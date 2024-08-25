//
// Created by Mladen Puzić on 24.8.24..
//

#include "SimmulatedAnnealing.h"
#include "GAIndividual.h"

long long SimmulatedAnnealing::run(int iter) {
    m_split = GAIndividual::randomSplit(m_groups, m_graph->getNodeCount());
    m_score = GAIndividual::calcFitness(m_graph, m_split);
    long long bestScore = m_score;
    auto bestSplit = m_split;
    for (int idx = 1; idx <= iter; idx++) {
        auto new_split = GAIndividual::smallChange(m_split, m_groups, m_rnd);
        long long new_value = GAIndividual::calcFitness(m_graph, new_split);

        if (new_value > m_score) {
            m_score = new_value;
            m_split = new_split;
            if (new_value > bestScore) {
                bestScore = new_value;
                bestSplit = new_split;
            }
        } else {
            int rnd = std::uniform_int_distribution<int>(1, idx)(m_rnd);
            if (rnd == 1) {
                m_score = new_value;
                m_split = new_split;
            }
        }
    }
    return bestScore;
}