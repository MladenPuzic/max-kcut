//
// Created by Mladen Puzić on 17.8.24..
//

#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include "Graph.h"
#include "Individual.h"

class BruteForce {
public:
    BruteForce(int k = 1, Graph *g = nullptr) {
        m_groups = k;
        m_graph = g;
    }

    long long run();
private:
    void checkAllOptions(int idx);
    int m_groups;
    Individual m_cur;
    Individual m_opt;
    Graph* m_graph;
};

#endif //BRUTEFORCE_H