//
// Created by Mladen Puzić on 17.8.24..
//

#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include "Graph.h"

class BruteForce {
public:
    BruteForce(int k, Graph *g = nullptr) {
        m_groups = k;
        m_graph = g;
    }

    long long run();
private:
    void checkAllOptions(int idx);
    int m_groups;
    int m_score;
    std::vector<int> m_split;
    std::vector<int> m_optimal;
    Graph* m_graph;
};



#endif //BRUTEFORCE_H
