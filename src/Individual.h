//
// Created by Mladen Puzić on 25.8.24..
//

#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <vector>
#include <random>
#include <ctime>
#include "Graph.h"

class Individual {
public:
    Individual() {}
    Individual(Graph *g, int groups, bool rnd) {
        m_graph = g;
        m_groups = groups;
        m_fitness = 0;

        m_chooseGroup = std::uniform_int_distribution<int>(0, groups-1);
        if (rnd) {
            generateSplit();
        } else {
            m_split = std::vector<int>(m_graph->getNodeCount());
        }
    }

    void smallChange();
    long long getFitness(bool recalc = false);
    std::vector<int> m_split;
protected:
    void generateSplit();
    void updateFitness();

    long long m_fitness;
    int m_groups;
    Graph *m_graph;
    std::uniform_int_distribution<int> m_chooseGroup;
};



#endif //INDIVIDUAL_H
