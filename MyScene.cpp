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

    /*
    connect(mainView, &QGraphicsView::wheelEvent, this, &Menu::zoom);
    connect(mainView, &QGraphicsView::keyPressEvent, this, &Menu::deplacement_fleche);
    */
}

Menu::~Menu() {

}

void Menu::askPseudo() {
    bool ok;
    QString text = QInputDialog::getText(nullptr, tr("Entez votre Pseudo"), tr("Pseudo :"), QLineEdit::Normal, "", &ok, Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    if (ok && !text.isEmpty()) {
        pseudo = text;
        qDebug() << "Pseudo entered:" << pseudo;

        emit start_game_signal(pseudo);
    }
}


// ------------------------------------------ DEPLACEMENT
void Menu::zoom(QWheelEvent *event) {
    QPoint deg = event->angleDelta() / 8;
    int etape = deg.y() / 15;

    if (!etape) {
        etape = deg.x() / 15;
    }

    if (event->angleDelta().y() != 0) {
        mainView->scale(pow(1.0015, etape), pow(1.0015, etape));
    }
    event->accept();
}

void Menu::deplacement_fleche(QKeyEvent *event) {
    int step = 25;

    switch (event->key()) {
        case Qt::Key_Left:
            mainView->horizontalScrollBar()->setValue(mainView->horizontalScrollBar()->value() - step);
            break;
        case Qt::Key_Right:
            mainView->horizontalScrollBar()->setValue(mainView->horizontalScrollBar()->value() + step);
            break;
        case Qt::Key_Up:
            mainView->verticalScrollBar()->setValue(mainView->verticalScrollBar()->value() - step);
            break;
        case Qt::Key_Down:
            mainView->verticalScrollBar()->setValue(mainView->verticalScrollBar()->value() + step);
            break;
        default:
            break;
    }
}


// ------------------------------------------ GAME
Game::Game(QObject *parent) : QGraphicsScene(parent) {
    new map_bloc(this);
}
