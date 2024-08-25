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
    m_fitness = calcFitness(m_graph, m_split);
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

long long GAIndividual::calcFitness(Graph* g, std::vector<int> split) {
    long long fitness = 0;
    std::vector<Graph::Edge> edges = g->getEdges();
    for (auto edge : edges) {
        if (split[edge.src] != split[edge.dst]) {
            fitness += edge.w;
        }
    }
    return fitness;
}

std::vector<int> GAIndividual::randomSplit(int groups, int len) {
    std::vector<int> split(len);
    for (int i = 0; i < groups; i++) {
        split[i] = i;
    }
    std::mt19937 rnd(time(nullptr));
    for (int i = groups; i < len; i++) {
        split[i] = std::uniform_int_distribution<int>(0, groups-1)(rnd);
    }
    std::shuffle(split.begin(), split.end(), rnd);
    return split;
}

std::vector<int> GAIndividual::smallChange(std::vector<int> split, int groups, std::mt19937 rnd) {
    int rnd_idx = std::uniform_int_distribution<int>(0, split.size()-1)(rnd);
    int rnd_grp = std::uniform_int_distribution<int>(0, groups-1)(rnd);

    split[rnd_idx] = rnd_grp;
    return split;
}