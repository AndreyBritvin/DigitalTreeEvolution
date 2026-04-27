#include "Random.hpp"
#include <random>
#include <chrono>

Random& Random::instance() {
    static Random instance;
    return instance;
}

Random::Random() {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    rng_.seed(static_cast<std::mt19937::result_type>(seed));
}

void Random::seed(unsigned int s) {
    if (s == 0) {
        std::random_device rd;
        s = rd();
    }
    rng_.seed(s);
}

int Random::nextInt(int min, int max) {
    if (min > max) {
        // throw std::invalid_argument("min cannot be greater than max");
    }
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng_);
}

float Random::nextFloat() {
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);
    return dist(rng_);
}

bool Random::nextBool(float probability) {
    if (probability < 0.0f || probability > 1.0f) {
        // throw std::invalid_argument("probability must be between 0.0 and 1.0");
    }
    return nextFloat() < probability;
}
