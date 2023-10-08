#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cmath>

// Objective function: f(x) = -x^2 + 8x + 10
double objective_function(double x) {
    return -x*x + 8*x + 10;
}

int main() {
    // Seed the random number generator
    std::srand(std::time(nullptr));

    const int max_iterations = 3;
    const int beam_size = 2;
    std::vector<double> populations(beam_size);

    std::cout << "Local Beam Search\n";
    std::cout << "Iteration\tInitial Population\tFitness Value\tBest Solution\tBest Fitness\n";

    for (int iteration = 0; iteration < max_iterations; ++iteration) {
        for (int i = 0; i < beam_size; ++i) {
            populations[i] = std::rand() / (RAND_MAX / 15.0) - 5.0; // Random initial solutions in [-5, 10]
        }

        std::vector<double> new_populations(beam_size);

        for (int i = 0; i < beam_size; ++i) {
            double current_fitness = objective_function(populations[i]);
            double step_size = 0.1;
            double x_new = populations[i] + step_size;
            double new_fitness = objective_function(x_new);

            if (new_fitness > current_fitness) {
                populations[i] = x_new;
            }

            new_populations[i] = populations[i];
        }

        std::sort(new_populations.begin(), new_populations.end(), [](double a, double b) {
            return objective_function(a) > objective_function(b);
        });

        populations = std::vector<double>(new_populations.begin(), new_populations.begin() + beam_size);

        std::cout << iteration + 1 << "\t\t";
        for (int i = 0; i < beam_size; ++i) {
            std::cout << populations[i] << "\t\t";
        }
        std::cout << objective_function(populations[0]) << "\t\t" << populations[0] << "\t\t" << objective_function(populations[0]) << "\n";
    }

    return 0;
}
