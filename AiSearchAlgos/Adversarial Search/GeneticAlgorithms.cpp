/*
Genetic Algorithms(GAs) are adaptive heuristic search algorithms that belong to the larger part of evolutionary algorithms.
Genetic algorithms are based on the ideas of natural selection and genetics. These are intelligent exploitation of random searches
provided with historical data to direct the search into the region of better performance in solution space. They are commonly used
to generate high-quality solutions for optimization problems and search problems.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to generate random numbers in a given range
int random_num(int start, int end)
{
    int range = (end - start) + 1;
    int random_int = start + (rand() % range);
    return random_int;
}

// Function to generate chromosome
string generate_chromosome(int n)
{
    string chromosome = "";
    for (int i = 0; i < n; i++)
    {
        int num = random_num(0, 1);
        chromosome += to_string(num);
    }
    return chromosome;
}

// Function to generate initial population
vector<string> generate_population(int population_size, int chromosome_size)
{
    vector<string> population;
    for (int i = 0; i < population_size; i++)
    {
        string chromosome = generate_chromosome(chromosome_size);
        population.push_back(chromosome);
    }
    return population;
}

// Function to calculate fitness score
int calculate_fitness(string chromosome, string target)
{
    int n = chromosome.size();
    int fitness = 0;
    for (int i = 0; i < n; i++)
    {
        if (chromosome[i] == target[i])
            fitness++;
    }
    return fitness;
}

// Function to perform crossover
string crossover(string parent1, string parent2)
{
    int n = parent1.size();
    int crossover_point = random_num(0, n - 1);
    string child = parent1.substr(0, crossover_point) + parent2.substr(crossover_point, n - crossover_point);
    return child;
}

// Function to perform mutation
void mutate(string &chromosome)
{
    int n = chromosome.size();
    int mutation_point = random_num(0, n - 1);
    chromosome[mutation_point] = (chromosome[mutation_point] == '0') ? '1' : '0';
}

// Function to perform genetic algorithm
string genetic_algorithm(string target, int population_size, int chromosome_size, int generations)
{
    vector<string> population = generate_population(population_size, chromosome_size);
    int n = population[0].size();
    for (int generation = 0; generation < generations; generation++)
    {
        vector<pair<int, string>> fitness_scores;
        for (int i = 0; i < population_size; i++)
        {
            int fitness = calculate_fitness(population[i], target);
            fitness_scores.push_back({fitness, population[i]});
        }
        sort(fitness_scores.begin(), fitness_scores.end(), greater<pair<int, string>>());
        if (fitness_scores[0].first == n)
            return fitness_scores[0].second;
        vector<string> new_population;
        for (int i = 0; i < population_size; i += 2)
        {
            string parent1 = fitness_scores[i].second;
            string parent2 = fitness_scores[i + 1].second;
            string child = crossover(parent1, parent2);
            if (random_num(0, 100) < 10)
                mutate(child);
            new_population.push_back(child);
        }
        population = new_population;
    }
    return "";
}

// Function to convert binary to decimal
int binary_to_decimal(string binary)
{
    int decimal = 0;
    int n = binary.size();
    for (int i = n - 1; i >= 0; i--)
    {
        decimal += (binary[i] - '0') * pow(2, n - i - 1);
    }
    return decimal;
}

int main()
{
    string target = "1101";
    int population_size = 10;
    int chromosome_size = target.size();
    int generations = 1000;
    string result = genetic_algorithm(target, population_size, chromosome_size, generations);
    if (result != "")
    {
        cout << "Target achieved: " << result << endl;
        cout << "Decimal equivalent: " << binary_to_decimal(result) << endl;
    }
    else
    {
        cout << "Target not achieved" << endl;
    }
    return 0;
}