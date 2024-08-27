//
// Created by Mladen Puzić on 17.8.24..
//

#include "BruteForce.h"

void BruteForce::checkAllOptions(int idx) {
    if (idx == m_graph->getNodeCount()) {
        long long curScore = m_cur.getFitness(true);
        if (curScore > m_opt.getFitness()) {
            m_opt = m_cur;
        }
        return;
    }
    for (int opt = 0; opt < m_groups; opt++) {
        m_cur.m_split[idx] = opt;
        checkAllOptions(idx + 1);
    }
}

long long BruteForce::run() {
    m_cur = Individual(m_graph, m_groups, false);
    m_opt = m_cur;
    checkAllOptions(0);
    return m_opt.getFitness();
}