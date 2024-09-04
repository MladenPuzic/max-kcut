//
// Created by Mladen Puzić on 17.8.24..
//

#include "Greedy.h"

#include <algorithm>

#include "Individual.h"

long long Greedy::runBestImprovement(int iter) {
    Individual cur = Individual(m_graph, m_groups, true);
    long long curFitness = cur.getFitness();
    bool improved = true;
    while (improved && iter--) {
        improved = false;
        int mx_idx = 0, mx_grp = cur.m_split[0];
        for (int idx = 0; idx < m_graph->getNodeCount(); idx++) {
            int st = cur.m_split[idx];
            for (int nw = 0; nw < m_groups; nw++) {
                if (st != nw) {
                    cur.m_split[idx] = nw;
                    long long nwFitness = cur.getFitness(true);
                    if (nwFitness > curFitness) {
                        curFitness = nwFitness;
                        mx_idx = idx;
                        mx_grp = nw;
                    }
                }
            }
            cur.m_split[idx] = st;
        }
        if (cur.m_split[mx_idx] != mx_grp) {
            cur.m_split[mx_idx] = mx_grp;
            improved = true;
        }
    }
    return cur.getFitness(true);
}

long long Greedy::runFirstImprovement(int iter) {
    Individual cur = Individual(m_graph, m_groups, true);
    long long curFitness = cur.getFitness();
    bool improved = true;
    while (improved && iter--) {
        improved = false;
        auto perm = std::vector<int>(m_graph->getNodeCount());
        for (int i = 0; i < perm.size(); i++) {
            perm[i] = i;
        }
        std::shuffle(perm.begin(), perm.end(), m_rnd);
        for (auto idx : perm) {
            int st = cur.m_split[idx];
            for (int nw = 0; nw < m_groups; nw++) {
                if (st != nw) {
                    cur.m_split[idx] = nw;
                    long long nwFitness = cur.getFitness(true);
                    if (nwFitness > curFitness) {
                        curFitness = nwFitness;
                        improved = true;
                        break;
                    }
                }
            }
            if (improved) {
                break;
            }
            cur.m_split[idx] = st;
        }
    }
    return cur.getFitness(true);
}
