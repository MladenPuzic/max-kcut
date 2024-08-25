//
// Created by Mladen Puzić on 17.8.24..
//

#ifndef GAINDIVIDUAL_H
#define GAINDIVIDUAL_H

#include <vector>
#include <random>
#include <ctime>
#include "Graph.h"
#include "Individual.h"

class GAIndividual: public Individual {
public:
    GAIndividual(Graph *g, int groups, double mutationProbability = 0.05) : Individual(g, groups, true ){
        m_mutationProb = mutationProbability;
        m_doesMutate = std::uniform_real_distribution<double>(0, 1);
    }
    static GAIndividual crossover(GAIndividual a, GAIndividual b, int position);
    void mutate();
private:
    double m_mutationProb;
    std::uniform_real_distribution<double> m_doesMutate;
};

#endif //GAINDIVIDUAL_H
