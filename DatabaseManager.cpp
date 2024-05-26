//
// Created by damra on 21/05/2024.
//

#include "DatabaseManager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("players.db");

    if (!db.open()) {
        qWarning() << "Error: connection with database failed";
    } else {
        qDebug() << "Database: connection ok";
    }

    if (!initializeDatabase()) {
        qWarning() << "Error: failed to initialize database";
    }
}

DatabaseManager::~DatabaseManager()
{
    if (db.isOpen()) {
        db.close();
    }
}

bool DatabaseManager::initializeDatabase()
{
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS players (id INTEGER PRIMARY KEY, username TEXT UNIQUE, score INTEGER)")) {
        qWarning() << "Failed to create table:" << query.lastError();
        return false;
    }
    return true;
}

bool DatabaseManager::addPlayer(const QString &username)
{
    // Vérifier si le pseudo existe déjà
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM players WHERE username = :username");
    checkQuery.bindValue(":username", username);
    if (!checkQuery.exec()) {
        qWarning() << "Failed to check if username exists:" << checkQuery.lastError();
        return false;
    }

    checkQuery.next();
    if (checkQuery.value(0).toInt() > 0) {
        qDebug() << "Username already exists:" << username;
        return false;
    }

    // Ajouter le joueur si le pseudo n'existe pas
    QSqlQuery query;
    query.prepare("INSERT INTO players (username, score) VALUES (:username, :score)");
    query.bindValue(":username", username);
    query.bindValue(":score", 0);
    if (!query.exec()) {
        qWarning() << "Failed to add player:" << query.lastError();
        return false;
    }
    return true;
}

QStringList DatabaseManager::getPlayers()
{
    QSqlQuery query("SELECT username FROM players");
    QStringList players;
    while (query.next()) {
        players << query.value(0).toString();
    }
    return players;
}

QMap<QString, int> DatabaseManager::getPlayersAndScores() const
{
    QMap<QString, int> playersAndScores;
    QSqlQuery query("SELECT username, score FROM players ORDER BY score DESC");

    if (!query.exec()) {
        qWarning() << "Failed to execute query:" << query.lastError().text();
        return playersAndScores; // Retourne une map vide en cas d'erreur
    }

    while (query.next()) {
        QString username = query.value(0).toString();
        int score = query.value(1).toInt();
        playersAndScores[username] = score;
    }

    return playersAndScores;
}

bool DatabaseManager::updateScore(const QString &username, int score)
{
    QSqlQuery query;
    query.prepare("UPDATE players SET score = :score WHERE username = :username");
    query.bindValue(":score", score);
    query.bindValue(":username", username);

    if (!query.exec()) {
        qWarning() << "Failed to update score:" << query.lastError();
        return false;
    }
    return true;
}
