//
// Created by Mladen Puzić on 24.8.24..
//

#include "SimmulatedAnnealing.h"

#include "Individual.h"

long long SimmulatedAnnealing::run(int iter) {
    Individual cur = Individual(m_graph, m_groups, true);
    Individual opt = cur;

    for (int idx = 1; idx <= iter; idx++) {
        Individual nw = cur;
        nw.smallChange();
        if (nw.getFitness() > cur.getFitness()) {
            cur = nw;
            if (nw.getFitness() > opt.getFitness()) {
                opt = nw;
            }
        } else {
            int rnd = std::uniform_int_distribution<int>(1, idx)(m_rnd);
            if (rnd == 1) {
                cur = nw;
            }
        }
    }
    return opt.getFitness();
}
