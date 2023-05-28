#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

class MovementSimulator {
private:
    int x, y, c;

public:
    MovementSimulator() {
        x = 0;
        y = 0;
        c = 0;
    }

    void calculatePath() {
        c = std::sqrt(std::pow(x, 2) + std::pow(y, 2));
        std::cout << "Полный путь: " << c << std::endl;
    }

    void simulateMovement(int n) {
        srand(time(NULL));
        int z, q;
        for (int i = 0; i < n; i++) {
            z = rand() % 10;
            q = rand() % 10;
            x += z;
            y += q;
            std::cout << "Значение X/Y: " << x << "/" << y << std::endl;
            calculatePath();
        }
    }
};

int main() {
    int n;
    std::cout << "Укажите размер: ";
    std::cin >> n;

    MovementSimulator simulator;
    simulator.simulateMovement(n);

    return 0;
}
