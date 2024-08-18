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


void GAIndividual::updateFitness() {
    m_fitness = calcFitness();
}

long long GAIndividual::getFitness() {
    return m_fitness;
}

void GAIndividual::mutate() {
    for (int i = 0; i < m_split.size(); i++) {
        if (m_doesMutate(m_rnd) <= m_mutationProb) {
            m_split[i] = m_chooseGroup(m_rnd);
        }
    }
}

long long GAIndividual::calcFitness() {
    long long fitness = 0;
    std::vector<Graph::Edge> edges = m_graph->getEdges();
    for (auto edge : edges) {
        if (m_split[edge.src] != m_split[edge.dst]) {
            fitness += edge.w;
        }
    }
    return fitness;
}