//
// Created by Mladen Puzić on 24.8.24..
//

#ifndef SIMMULATEDANNEALING_H
#define SIMMULATEDANNEALING_H

#include <random>
#include "Graph.h"

class SimmulatedAnnealing {
public:
    SimmulatedAnnealing(int k, Graph *g = nullptr) {
        m_groups = k;
        m_graph = g;
        m_rnd.seed(time(nullptr));
    }

    long long run(int iter);
private:
    int m_groups;
    long long m_score;
    std::mt19937 m_rnd;
    std::vector<int> m_split;
    Graph* m_graph;
};

#endif //SIMMULATEDANNEALING_H
