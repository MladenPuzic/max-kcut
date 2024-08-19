//
// Created by Mladen Puzić on 17.8.24..
//

#include "BruteForce.h"

#include "GAIndividual.h"

void BruteForce::checkAllOptions(int idx) {
    if (idx == m_split.size()) {
        int curScore = GAIndividual::calcFitness(m_graph, m_split);
        if (curScore > m_score) {
            m_score = curScore;
            m_optimal = m_split;
        }
        return;// obrisi za bug
    }
    for (int opt = 0; opt < m_groups; opt++) {
        m_split[idx] = opt;
        checkAllOptions(idx+1);
    }
}

long long BruteForce::run() {
    m_split = std::vector<int>(m_graph->getNodeCount(), 0);
    m_optimal = m_split;
    m_score = 0;
    checkAllOptions(0);
    return m_score;
}