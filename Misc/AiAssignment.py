import numpy as np
import matplotlib.pyplot as plt

# Objective function: f(x) = -x^2 + 8x + 10
def objective_function(x):
    return -x**2 + 8*x + 10

# Simple Hill Climbing
def simple_hill_climbing(x, max_iterations):
    history = []
    for _ in range(max_iterations):
        current_fitness = objective_function(x)
        step_size = 0.1
        x_new = x + step_size
        new_fitness = objective_function(x_new)

        if new_fitness > current_fitness:
            x = x_new

        history.append(x)

    return history

# Local Beam Search
def local_beam_search(beam_size, max_iterations):
    populations = [np.random.uniform(-5, 10) for _ in range(beam_size)]
    history = []

    for iteration in range(max_iterations):
        new_populations = []

        for x in populations:
            current_fitness = objective_function(x)
            step_size = 0.1
            x_new = x + step_size
            new_fitness = objective_function(x_new)

            if new_fitness > current_fitness:
                x = x_new

            new_populations.append(x)

        populations = sorted(new_populations, key=lambda x: -objective_function(x))[:beam_size]
        history.extend(populations)

    return history

# Genetic Algorithm
def genetic_algorithm(population_size, max_iterations):
    populations = np.random.uniform(-5, 10, size=population_size)
    history = []

    for iteration in range(max_iterations):
        fitness_values = [objective_function(x) for x in populations]

        parents_indices = np.argsort(fitness_values)[-2:]
        parent1, parent2 = populations[parents_indices[0]], populations[parents_indices[1]]  # Corrected this line

        offspring = [parent1 + np.random.uniform(-1, 1), parent2 + np.random.uniform(-1, 1)]
        populations = np.concatenate([populations, offspring])

        populations = sorted(populations, key=lambda x: -objective_function(x))[:population_size]
        history.extend(populations)

    return history

# Main function
def main():
    max_iterations = 3

    # Simple Hill Climbing
    x_initial = np.random.uniform(-5, 10)
    simple_hill_climbing_history = simple_hill_climbing(x_initial, max_iterations)

    # Local Beam Search
    local_beam_search_history = local_beam_search(2, max_iterations)

    # Genetic Algorithm
    genetic_algorithm_history = genetic_algorithm(4, max_iterations)

    # Plot the results
    plt.figure(figsize=(12, 6))
    plt.plot(range(len(simple_hill_climbing_history)), [objective_function(x) for x in simple_hill_climbing_history], label="Simple Hill Climbing")
    plt.plot(range(len(local_beam_search_history)), [objective_function(x) for x in local_beam_search_history], label="Local Beam Search")
    plt.plot(range(len(genetic_algorithm_history)), [objective_function(x) for x in genetic_algorithm_history], label="Genetic Algorithm")
    plt.xlabel("Iteration")
    plt.ylabel("f(x)")
    plt.legend()
    plt.savefig("Algorithm_itteration_graph.png")
    plt.show()

if __name__ == "__main__":
    main()
