#include "MyScene.h"

using namespace std;


// ------------------------------------------ MENU
Menu::Menu(QObject* parent) : QGraphicsScene(parent) {

    pseudo = "";

    playButton = new QPushButton("Play");
    connect(playButton, &QPushButton::clicked, this, &Menu::askPseudo);
    settingsButton = new QPushButton("Settings");
    classementButton = new QPushButton("Classement");

    QHBoxLayout *flayout = new QHBoxLayout();
    QVBoxLayout *layout = new QVBoxLayout();
    flayout->addWidget(playButton);

    flayout->addWidget(settingsButton);
    layout->addLayout(flayout);
    layout->addWidget(classementButton);

    // Créer un widget pour contenir le layout
    QWidget *container = new QWidget();
    container->setLayout(layout);



    // Créer un proxy widget pour contenir le widget
    QGraphicsProxyWidget *proxyWidget = new QGraphicsProxyWidget();
    proxyWidget->setWidget(container);

    // Ajouter le proxy widget à la scène
    this->addItem(proxyWidget);


    // Positionner le proxy widget
    //proxyWidget->setPos(0, 0);
}
Menu::~Menu() {

}

void Menu::askPseudo() {
    bool ok;
    QString text = QInputDialog::getText(nullptr, tr("Enter Pseudo"),tr("Pseudo:"), QLineEdit::Normal,"", &ok);
    if (ok && !text.isEmpty()) {
        pseudo = text;
        qDebug() << "Pseudo entered:" << pseudo;
    }
}

Game::Game(QObject *parent) : QGraphicsScene(parent) {
    // à compléter
}
