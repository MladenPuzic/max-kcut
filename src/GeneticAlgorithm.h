//
// Created by Mladen Puzić on 17.8.24..
//

#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

#include "GAIndividual.h"
#include "Graph.h"

class GeneticAlgorithm {
   public:
    GeneticAlgorithm(int k, Graph *g = nullptr) {
        m_groups = k;
        m_graph = g;
        m_rnd.seed(time(nullptr));
    }

    long long run(int populationSize, int numGenerations, int elitismSize,
                  int tournamentSize, double mutationProb);
    GAIndividual selection(std::vector<GAIndividual> &population,
                           int tournamentSize, GAIndividual *excl = nullptr);

   private:
    static bool fitnessCmp(GAIndividual a, GAIndividual b);
    Graph *m_graph;
    int m_groups;
    std::mt19937 m_rnd;
};

#endif  // GENETICALGORITHM_H
