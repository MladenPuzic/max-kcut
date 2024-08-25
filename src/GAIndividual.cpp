//
// Created by Mladen Puzić on 17.8.24..
//

#include "GAIndividual.h"

GAIndividual GAIndividual::crossover(GAIndividual a, GAIndividual b, int position) {
    GAIndividual child = a;
    for (int i = position; i < child.m_split.size(); i++) {
        child.m_split[i] = b.m_split[i];
    }
    child.updateFitness();
    return child;
}

void GAIndividual::mutate() {
    std::random_device rd;
    std::mt19937 rnd(rd());
    for (int i = 0; i < m_split.size(); i++) {
        if (m_doesMutate(rnd) <= m_mutationProb) {
            m_split[i] = m_chooseGroup(rnd);
        }
    }
    updateFitness();
}
