#include "MyScene.h"

using namespace std;


// ------------------------------------------ MENU
Menu::Menu(QObject* parent) : QGraphicsScene(parent) {
    pseudo = "";

    playButton = new QPushButton("Play");
    connect(playButton, &QPushButton::clicked, this, &Menu::askPseudo);
    settingsButton = new QPushButton("Settings");
    classementButton = new QPushButton("Classement");
    connect(classementButton, &QPushButton::clicked, this, &Menu::afficherClassement);

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
    DatabaseManager dbManager;
    bool ok;
    QString text = QInputDialog::getText(nullptr, tr("Entez votre Pseudo"), tr("Pseudo :"), QLineEdit::Normal, "", &ok, Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    if (ok && !text.isEmpty()) {
        pseudo = text;
        qDebug() << "Pseudo entered:" << pseudo;
        if (dbManager.addPlayer(text)) {
            qDebug() << "Pseudo entered and added to the database:" << text;
        } else {
            qDebug() << "Failed to add pseudo to the database:" << text;
        }
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
        //mainView->scale(pow(1.0015, etape), pow(1.0015, etape));
    }
    event->accept();
}

void Menu::deplacement_fleche(QKeyEvent *event) {
    int step = 25;

    switch (event->key()) {
        case Qt::Key_Left:
          //  mainView->horizontalScrollBar()->setValue(mainView->horizontalScrollBar()->value() - step);
            break;
        case Qt::Key_Right:
          //  mainView->horizontalScrollBar()->setValue(mainView->horizontalScrollBar()->value() + step);
            break;
        case Qt::Key_Up:
          //  mainView->verticalScrollBar()->setValue(mainView->verticalScrollBar()->value() - step);
            break;
        case Qt::Key_Down:
          //  mainView->verticalScrollBar()->setValue(mainView->verticalScrollBar()->value() + step);
            break;
        default:
            break;
    }
}


// ------------------------------------------ GAME
Game::Game(QObject *parent) : QGraphicsScene(parent) {
    new map_bloc(this);
}

void showPlayersList() {
    DatabaseManager dbManager; // Créer une instance de DatabaseManager
    QStringList players = dbManager.getPlayers();

    // Afficher chaque joueur dans la console
    qDebug() << "List of players:";
    for (const QString &player : players) {
        qDebug() << player;
    }
}

void printPandS(){
    DatabaseManager dbManager;
    QMap<QString, int> playersAndScores = dbManager.getPlayersAndScores();
    qDebug() << "Current players and scores:";
    for (auto it = playersAndScores.begin(); it != playersAndScores.end(); ++it) {
        qDebug() << "Username:" << it.key() << ", Score:" << it.value();
    }
}


void Menu::afficherClassement() {
    DatabaseManager dbManager;
    classement = dbManager.getPlayersAndScores();
    QWidget *window = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(window);

    // Créer le bouton "Retour"
    QPushButton *boutonRetour = new QPushButton("Retour", window);
    layout->addWidget(boutonRetour);

    // Créer le tableau
    QTableWidget *table = new QTableWidget(classement.size(), 2, window);
    table->setHorizontalHeaderLabels(QStringList() << "Nom" << "Score");

    int row = 0;
    for (auto it = classement.begin(); it != classement.end(); ++it) {
        QTableWidgetItem *nameItem = new QTableWidgetItem(it.key());
        QTableWidgetItem *scoreItem = new QTableWidgetItem(QString::number(it.value()));

        table->setItem(row, 0, nameItem);
        table->setItem(row, 1, scoreItem);
        ++row;
    }

    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    layout->addWidget(table);

    window->setLayout(layout);
    window->setWindowTitle("Tableau de Classement");
    window->resize(400, 300);
    window->show();

    QObject::connect(boutonRetour, &QPushButton::clicked, window, &QWidget::close);
}
