#include <QApplication>
#include <QtGui>
#include <QGraphicsView>
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    MainWindow mainWindow;

    QGraphicsView view(&mainWindow);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    mainWindow.show();
    return application.exec();
}
