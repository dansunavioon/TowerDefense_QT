#ifndef CPP_QT_TPMINIPROJET_MYSCENE_H
#define CPP_QT_TPMINIPROJET_MYSCENE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>

class MyScene : public QGraphicsScene {
    Q_OBJECT

public:
    MyScene(QObject* parent = nullptr);
    virtual ~MyScene();

public slots:
    void update();

private:
    QTimer* timer;
    QGraphicsRectItem* qgri;
    QGraphicsTextItem* qgti;

};


#endif //CPP_QT_TPMINIPROJET_MYSCENE_H
