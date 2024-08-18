//
// Created by Mladen Puzić on 17.8.24..
//

#ifndef GAINDIVIDUAL_H
#define GAINDIVIDUAL_H

#include <vector>
#include <random>
#include <ctime>
#include "Graph.h"

class GAIndividual {
public:
    GAIndividual(Graph *g, int groups = 1, double mutationProbability = 0.05) {
        m_graph = g;
        m_groups = groups;
        m_split.resize(g->getNodeCount());
        m_mutationProb = mutationProbability;
        for (int i = 0; i < groups; i++) {
            m_split[i] = i;
        }
        m_rnd.seed(time(nullptr));
        m_chooseGroup = std::uniform_int_distribution<int>(0, groups-1);
        m_doesMutate = std::uniform_real_distribution<double>(0, 1);
        for (int i = groups; i < m_split.size(); i++) {
            m_split[i] = m_chooseGroup(m_rnd);
        }
        std::shuffle(m_split.begin(), m_split.end(), m_rnd);
        updateFitness();
    }
    static GAIndividual crossover(GAIndividual a, GAIndividual b, int position);
    void updateFitness();
    long long getFitness();
    void mutate();
private:
    long long calcFitness();
    long long m_fitness;
    int m_groups;
    double m_mutationProb;
    Graph *m_graph;
    std::vector<int> m_split;
    std::mt19937 m_rnd;
    std::uniform_int_distribution<int> m_chooseGroup;
    std::uniform_real_distribution<double> m_doesMutate;
};

#endif //GAINDIVIDUAL_H
