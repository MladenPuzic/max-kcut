//
// Created by Mladen Puzić on 25.8.24..
//

#include "Individual.h"
#include <algorithm>

long long Individual::getFitness(bool recalc) {
    if (recalc) {
        updateFitness();
    }
    return m_fitness;
}

void Individual::updateFitness() {
    m_fitness = 0;
    std::vector<Graph::Edge> edges = m_graph->getEdges();
    for (auto edge : edges) {
        if (m_split[edge.src] != m_split[edge.dst]) {
            m_fitness += edge.w;
        }
    }
}

void Individual::generateSplit() {
    std::random_device rd;
    std::mt19937 rnd(rd());
    int len = m_graph->getNodeCount();
    m_split.resize(len);
    for (int i = 0; i < m_groups; i++) {
        m_split[i] = i;
    }
    for (int i = m_groups; i < len; i++) {
        m_split[i] = m_chooseGroup(rnd);
    }
    std::shuffle(m_split.begin(), m_split.end(), rnd);
    updateFitness();
}

void Individual::smallChange() {
    std::random_device rd;
    std::mt19937 rnd(rd());
    int rnd_idx = std::uniform_int_distribution<int>(0, m_split.size()-1)(rnd);
    m_split[rnd_idx] = m_chooseGroup(rnd);
    updateFitness();
}