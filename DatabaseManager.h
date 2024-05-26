#ifndef PROJET_QT_DATABASEMANAGER_H
#define PROJET_QT_DATABASEMANAGER_H
#include <QObject>
#include <QSqlDatabase>
#include <QStringList>
#include <QMap>

class DatabaseManager : public QObject
{
Q_OBJECT

public:
    explicit DatabaseManager(QObject *parent = nullptr);
    ~DatabaseManager();

    bool addPlayer(const QString &username);
    QStringList getPlayers();
    QMap <QString, int> getPlayersAndScores() const;
    bool updateScore(const QString &username, int score);

private:
    QSqlDatabase db;
    bool initializeDatabase();
};

#endif //PROJET_QT_DATABASEMANAGER_H
