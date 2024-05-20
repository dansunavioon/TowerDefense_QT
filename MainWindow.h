#ifndef CPP_QT_TPMINIPROJET_MAINWINDOW_H
#define CPP_QT_TPMINIPROJET_MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>



#include "MyScene.h"

class MainWindow : public QMainWindow {
Q_OBJECT

private :
    Menu* mainScene;
    Game* secondeScene;
    QGraphicsView* mainView;


public:
    MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

private slots:
    void start_game(QString pseudo);
};



#endif //CPP_QT_TPMINIPROJET_MAINWINDOW_H
