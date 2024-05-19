#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    this->mainScene = new Menu;

    this->mainView = new QGraphicsView;
    this->mainView->setScene(mainScene);

    this->setCentralWidget(mainView);
    this->setWindowTitle("Tower Defense by StudioXY");
    this->resize(800, 600); // Game : 1600px/1100px

/*
    helpMenu = menuBar()->addMenu(tr("&Help"));
    QAction* actionHelp = new QAction(tr("&About"), this);
    connect(actionHelp, SIGNAL(triggered()), this, SLOT(slot_aboutMenu()));
    helpMenu->addAction(actionHelp);
*/

}

MainWindow::~MainWindow(){

}

/*
void MainWindow::slot_aboutMenu(){
    QMessageBox msgBox;
    msgBox.setText("A small QT/C++ projet...");
    msgBox.setModal(true); // on souhaite que la fenetre soit modale i.e qu'on ne puisse plus cliquer ailleurs
    msgBox.exec();
}
*/