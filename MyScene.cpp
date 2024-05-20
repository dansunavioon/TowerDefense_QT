#include "MyScene.h"

using namespace std;


// ------------------------------------------ MENU
Menu::Menu(QObject* parent) : QGraphicsScene(parent) {
    pseudo = "";

    playButton = new QPushButton("Play");
    connect(playButton, &QPushButton::clicked, this, &Menu::askPseudo);
    settingsButton = new QPushButton("Settings");
    classementButton = new QPushButton("Classement");

    QLabel *logo_TD = new QLabel();
    QPixmap pixmap(":/ressources/logo.png");
    logo_TD->setPixmap(pixmap);
    logo_TD->setAlignment(Qt::AlignCenter);

    qDebug() << logo_TD;
    QHBoxLayout *flayout = new QHBoxLayout();
    QVBoxLayout *layout = new QVBoxLayout();
    flayout->addWidget(playButton);
    flayout->addWidget(settingsButton);
    layout->addWidget(logo_TD);
    layout->addLayout(flayout);
    layout->addWidget(classementButton);

    QWidget *container = new QWidget();
    container->setLayout(layout);

    QGraphicsProxyWidget *proxyWidget = new QGraphicsProxyWidget();
    proxyWidget->setWidget(container);

    this->addItem(proxyWidget);
    this->setSceneRect(0, 0, 800, 600);

    QRectF sceneRect = this->sceneRect();
    QPointF centerPoint = sceneRect.center();
    QSizeF containerSize = container->sizeHint(); // Utiliser sizeHint pour obtenir une taille approximative
    QPointF containerTopLeft = centerPoint - QPointF(containerSize.width() / 2, containerSize.height() / 2);
    proxyWidget->setPos(containerTopLeft);
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
