//
// Created by Mladen Puzić on 17.8.24..
//

#include "GeneticAlgorithm.h"
#include <algorithm>

bool GeneticAlgorithm::fitnessCmp(GAIndividual a, GAIndividual b) {
    return a.getFitness() > b.getFitness();
}

GAIndividual GeneticAlgorithm::selection(std::vector<GAIndividual> &population, int tournamentSize, GAIndividual *excl) {
    std::shuffle(population.begin(), population.end(), m_rnd);
    GAIndividual max_individual = population[0];
    long long max_fitness = -1;
    for (int el = 0; el < tournamentSize; el++) {
        if (&population[el] != excl && population[el].getFitness() > max_fitness) {
            max_fitness = population[el].getFitness();
            max_individual = population[el];
        }
    }
    return max_individual;
}

long long GeneticAlgorithm::run(int populationSize, int numGenerations, int elitismSize, int tournamentSize, double mutationProb) {
    std::vector<GAIndividual> population(populationSize, GAIndividual(m_graph, m_groups, mutationProb));
    std::vector<GAIndividual> new_population = population;

    for (int gen = 0; gen < numGenerations; gen++) {
        std::sort(population.begin(), population.end(), fitnessCmp);
        for (int el = 0; el < elitismSize; el++) {
            new_population[el] = population[el];
        }
        for (int j = elitismSize; j < populationSize; j += 2) {
            GAIndividual parent1 = selection(population, tournamentSize);
            GAIndividual parent2 = selection(population, tournamentSize, &parent1);

            int randomPos = std::uniform_int_distribution<int>(0, m_graph->getNodeCount())(m_rnd);
            new_population[j] = GAIndividual::crossover(parent1, parent2, randomPos);
            new_population[j+1] = GAIndividual::crossover(parent2, parent1, randomPos);

            new_population[j].mutate();
            new_population[j+1].mutate();
        }
        population = new_population;
    }
    long long max_fitness = 0;
    for (auto ind : population) {
        max_fitness = std::max(max_fitness, ind.getFitness());
    }
    return max_fitness;
}