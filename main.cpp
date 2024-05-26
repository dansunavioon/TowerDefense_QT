#include <QApplication>
#include <QtGui>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QObject>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMediaPlayer *player = new QMediaPlayer;
    QAudioOutput *audioOutput = new QAudioOutput;

    // Configurer QMediaPlayer avec QAudioOutput
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl("qrc:/sounds/music3.mp3"));

    audioOutput->setVolume(0.5); // Volume à 50%

    QObject::connect(player, &QMediaPlayer::mediaStatusChanged, [=](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::EndOfMedia) {
            player->play(); // Redémarrer la lecture
        }
    });

    // démarrer la lecture
    player->play();

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}

