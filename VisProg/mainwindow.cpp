#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include <QPixmap>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

struct BaseStation {
    int posX;
    int posY;
};

class MainWindow : public QMainWindow {

public:
    MainWindow(QWidget *parent = nullptr);
private:
    float PL(float f, float d);
};

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    std::random_device rd;
    std::mt19937 gen(rd());
    QGraphicsScene* scene = new QGraphicsScene();
    int rand_lower = 1;
    int rand_upper = 1000;
    std::uniform_int_distribution<> distribution(rand_lower, rand_upper);
    int maxX = 1000;
    int maxY = 1000;
    int onePixDistance = 100; //[m]
    int TxPower = 23; // [dBm]
    int antGain = 12; // [dBi]
    float freq = 2.5; // [GHz]
    QPixmap map(maxX, maxY); // создаем карту для рисования
    QPainter p(&map);
    std::vector<BaseStation> baseStations;

    for (int i = 0; i < 10; i++) {
        BaseStation station;
        station.posX = distribution(gen);
        station.posY = distribution(gen);
        baseStations.push_back(station);
    }

    for (const auto& station : baseStations) {
        for (int i = 0; i < maxX; i++) {
            for (int j = 0; j < maxY; j++) {
                float distance = sqrt(pow(abs(station.posX - i), 2) + pow(abs(station.posY - j), 2)); // [pix]
                    if (distance <= 100) {
                        distance *= onePixDistance;
                        float sigPower = TxPower + antGain - PL(freq, distance);
                        // Проверяем, находится ли пиксель в пределах радиуса зоны базовой станции
                        if(sigPower < -44 && sigPower >= -54){
                            p.setPen(QColor(255, 0, 0, 255)); // Красный цвет
                        } else if (sigPower < -54 && sigPower >= -64) {
                            p.setPen(QColor(255, 69, 0, 255)); // Оранжевый цвет
                        } else if (sigPower < -64 && sigPower >= -74) {
                            p.setPen(QColor(255, 140, 0, 255)); // Темный оранжевый
                        } else if (sigPower < -74 && sigPower >= -84) {
                            p.setPen(QColor(255, 215, 0, 255)); // Желтый (Золотой)
                        } else if (sigPower < -84 && sigPower >= -94) {
                            p.setPen(QColor(255, 255, 0, 255)); // Желтый
                        } else if (sigPower < -94 && sigPower >= -104) {
                            p.setPen(QColor(173, 255, 47, 255)); // Желтозеленый
                        } else if (sigPower < -104 && sigPower >= -114) {
                            p.setPen(QColor(0, 255, 0, 255)); // Лаймовый
                        } else if (sigPower < -114 && sigPower >= -124) {
                            p.setPen(QColor(0, 255, 127, 255)); // Зеленосиний
                        } else if (sigPower < -124 && sigPower >= -134) {
                            p.setPen(QColor(0, 255, 255, 255)); // Циановый
                        } else if (sigPower < -134 && sigPower >= -144) {
                            p.setPen(QColor(0, 0, 255, 255)); // Голубой
                        }
                        p.drawPoint(i, j);
                    }
               }
         }
    }
    p.end();
    scene->addPixmap(map);
    QGraphicsView* view = new QGraphicsView(scene);
    setCentralWidget(view);
}

float MainWindow::PL(float f, float d) {
    return 28 + 22 * log10(f) + 20 * log10(d);
}
