#include <random>
#include <chrono>

class Random {
public:
    static Random& instance();        // Синглтон
    void seed(unsigned int s = 0);    // Инициализация
    int nextInt(int min, int max);    // Случайное целое
    float nextFloat();                // Случайное дробное [0,1)
    bool nextBool(float p = 0.5f);    // Случайный булев с вероятностью p
private:
    Random();                         // Приватный конструктор
    std::mt19937 rng_;                // Генератор
};
