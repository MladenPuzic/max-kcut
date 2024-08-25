//
// Created by Mladen Puzić on 17.8.24..
//

#include "Greedy.h"

#include "GAIndividual.h"

long long Greedy::runBestImprovement(int iter) {
    m_split = GAIndividual::randomSplit(m_groups, m_graph->getNodeCount());
    m_score = GAIndividual::calcFitness(m_graph, m_split);

    bool improved = true;
    while (improved && iter--) {
        improved = false;
        int mx_idx = 0, mx_grp = m_split[0];
        for (int idx = 0; idx < m_split.size(); idx++) {
            int st = m_split[idx];
            for (int nw = 0; nw < m_groups; nw++) {
                if (st != nw) {
                    m_split[idx] = nw;
                    long long nw_value = GAIndividual::calcFitness(m_graph, m_split);
                    if (nw_value > m_score) {
                        m_score = nw_value;
                        mx_idx = idx;
                        mx_grp = nw;
                    }
                }
            }
            m_split[idx] = st;
        }
        if (m_split[mx_idx] != mx_grp) {
            m_split[mx_idx] = mx_grp;
            improved = true;
        }
    }
    return m_score;
}

long long Greedy::runFirstImprovement(int iter) {
    m_split = GAIndividual::randomSplit(m_groups, m_graph->getNodeCount());
    m_score = GAIndividual::calcFitness(m_graph, m_split);

    bool improved = true;
    while (improved && iter--) {
        improved = false;
        auto perm = std::vector<int>(m_split.size());
        for (int i = 0; i < perm.size(); i++) {
            perm[i] = i;
        }
        shuffle(perm.begin(), perm.end(), m_rnd);
        for (auto idx : perm) {
            int st = m_split[idx];
            for (int nw = 0; nw < m_groups; nw++) {
                if (st != nw) {
                    m_split[idx] = nw;
                    long long nw_value = GAIndividual::calcFitness(m_graph, m_split);
                    if (nw_value > m_score) {
                        m_score = nw_value;
                        improved = true;
                        break;
                    }
                }
            }
            if (improved) {
                break;
            }
            m_split[idx] = st;
        }
    }
    return m_score;
}

