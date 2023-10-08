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
    const int population_size = 4;
    std::vector<double> populations(population_size);

    std::cout << "Genetic Algorithm\n";
    std::cout << "Iteration\tInitial Population\tFitness Value\tBest Solution\tBest Fitness\n";

    for (int iteration = 0; iteration < max_iterations; ++iteration) {
        for (int i = 0; i < population_size; ++i) {
            populations[i] = std::rand() / (RAND_MAX / 15.0) - 5.0; // Random initial solutions in [-5, 10]
        }

        std::vector<double> fitness_values(population_size);

        for (int i = 0; i < population_size; ++i) {
            fitness_values[i] = objective_function(populations[i]);
        }

        std::vector<int> parents_indices(population_size);
        for (int i = 0; i < population_size; ++i) {
            parents_indices[i] = i;
        }

        std::partial_sort(parents_indices.begin(), parents_indices.begin() + 2, parents_indices.end(),
            [&fitness_values](int a, int b) {
                return fitness_values[a] > fitness_values[b];
            });

        int parent1_index = parents_indices[0];
        int parent2_index = parents_indices[1];
        double parent1 = populations[parent1_index];
        double parent2 = populations[parent2_index];

        double offspring1 = parent1 + (std::rand() / (RAND_MAX / 2.0) - 1.0);
        double offspring2 = parent2 + (std::rand() / (RAND_MAX / 2.0) - 1.0);

        populations[parent1_index] = offspring1;
        populations[parent2_index] = offspring2;

        std::cout << iteration + 1 << "\t\t";
        for (int i = 0; i < population_size; ++i) {
            std::cout << populations[i] << "\t\t";
        }
        std::cout << fitness_values[parent1_index] << "\t\t" << populations[parent1_index] << "\t\t" << fitness_values[parent1_index] << "\n";
    }

    return 0;
}
