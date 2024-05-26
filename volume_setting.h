//
// Created by damra on 25/05/2024.
//

#ifndef PROJET_QT_VOLUME_SETTING_H
#define PROJET_QT_VOLUME_SETTING_H

#include <QDialog>
#include <QSlider>
#include <QVBoxLayout>
#include <QMediaPlayer>


class volume_setting : public QDialog {
    Q_OBJECT

public:
    volume_setting(QWidget *parent = nullptr);
    virtual ~volume_setting();

private:
    QSlider *volumeSlider;
};


#endif //PROJET_QT_VOLUME_SETTING_H
