//
// Created by damra on 25/05/2024.
//

#include "volume_setting.h"


volume_setting::volume_setting(QWidget *parent) : QDialog(parent) {
    QVBoxLayout *layout = new QVBoxLayout();

    volumeSlider = new QSlider(Qt::Horizontal);
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(50);
    volumeSlider->update();
    layout->addWidget(volumeSlider);

    setLayout(layout);
    setWindowTitle("Volume Settings");
}

volume_setting::~volume_setting() {

}
