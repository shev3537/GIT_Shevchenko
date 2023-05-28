#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

void path(int c, int x, int y)
{
    c = std::sqrt(std::pow(x, 2) + std::pow(y, 2));
    std::cout << "Полный путь: " << c << std::endl;
}

void simulateMovement(int n)
{
    srand(time(NULL));
    int x = 0, y = 0, c = 0, z, q;
    for (int i = 0; i < n; i++)
    {
        z = rand() % 10;
        q = rand() % 10;
        x += z;
        y += q;
        std::cout << "Значение X/Y: " << x << "/" << y << std::endl;
        path(c, x, y);
    }
}

int main()
{
    int n;
    std::cout << "Укажите размер: ";
    std::cin >> n;
    simulateMovement(n);
    return 0;
}
