#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

class Coordinates {
private:
    int x, y;

public:
    Coordinates() {
        x = 0;
        y = 0;
    }

    int getX() const {
        return x;
    }

    void setX(int xCoord) {
        x = xCoord;
    }

    int getY() const {
        return y;
    }

    void setY(int yCoord) {
        y = yCoord;
    }
};

class Object {
private:
    Coordinates coords;
    int c;

public:
    Object() {
        c = 0;
    }

    void calculatePath() {
        c = std::sqrt(std::pow(coords.getX(), 2) + std::pow(coords.getY(), 2));
        std::cout << "Полный путь: " << c << std::endl;
    }

    void simulateMovement(int n) {
        srand(time(NULL));
        int z, q;
        for (int i = 0; i < n; i++) {
            z = rand() % 10;
            q = rand() % 10;
            coords.setX(coords.getX() + z);
            coords.setY(coords.getY() + q);
            std::cout << "Значение X/Y: " << coords.getX() << "/" << coords.getY() << std::endl;
            calculatePath();
        }
    }
};

int main() {
    int n;
    std::cout << "Укажите размер: ";
    std::cin >> n;

    Object path;
    path.simulateMovement(n);

    return 0;
}