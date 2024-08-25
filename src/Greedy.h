//
// Created by Mladen Puzić on 17.8.24..
//

#ifndef GREEDY_H
#define GREEDY_H

#include <random>

#include "Graph.h"

class Greedy {
public:
    Greedy(int k, Graph *g = nullptr) {
        m_groups = k;
        m_graph = g;
        m_rnd.seed(time(nullptr));
    }

    long long runFirstImprovement(int iter);
    long long runBestImprovement(int iter);
private:
    int m_groups;
    long long m_score;
    std::mt19937 m_rnd;
    std::vector<int> m_split;
    Graph* m_graph;
};



#endif //GREEDY_H
