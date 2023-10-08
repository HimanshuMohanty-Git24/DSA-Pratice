#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

// Objective function: f(x) = -x^2 + 8x + 10
double objective_function(double x) {
    return -x*x + 8*x + 10;
}

int main() {
    // Seed the random number generator
    std::srand(std::time(nullptr));

    const int max_iterations = 3;
    double x = std::rand() / (RAND_MAX / 15.0) - 5.0; // Random initial solution in [-5, 10]

    std::cout << "Simple Hill Climbing\n";
    std::cout << "Iteration\tInitial Population\tFitness Value\tBest Solution\tBest Fitness\n";

    for (int iteration = 0; iteration < max_iterations; ++iteration) {
        double current_fitness = objective_function(x);
        double step_size = 0.1;
        double x_new = x + step_size;
        double new_fitness = objective_function(x_new);

        if (new_fitness > current_fitness) {
            x = x_new;
        }

        std::cout << iteration + 1 << "\t\t" << x << "\t\t" << current_fitness << "\t\t" << x << "\t\t" << new_fitness << "\n";
    }

    return 0;
}
