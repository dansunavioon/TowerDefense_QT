#ifndef CPP_QT_TPMINIPROJET_MAINWINDOW_H
#define CPP_QT_TPMINIPROJET_MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>
#include <QWheelEvent>



#include "MyScene.h"

class MainWindow : public QMainWindow {
Q_OBJECT

private :
    Menu* mainScene;
    map_bloc* secondeScene;
    QGraphicsView* mainView;


public:
    MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

public slots:
    void retournerAuMenu();

private slots:
    void start_game(const QString &pseudo);


protected:
    bool eventFilter(QObject *obj, QEvent *event);
};



#endif //CPP_QT_TPMINIPROJET_MAINWINDOW_H
