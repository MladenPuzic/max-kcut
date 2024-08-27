#include <iostream>

#include "GeneticAlgorithm.h"
#include "BruteForce.h"
#include "Graph.h"
#include "Greedy.h"
#include "SimmulatedAnnealing.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;
    Graph g(n);
    for (int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        g.addEdge(x, y, w);
    }
    GeneticAlgorithm ga(k, &g);
    BruteForce bf(k, &g);
    Greedy gd(k, &g);
    SimmulatedAnnealing sa(k, &g);
    cout << ga.run(200, 100, 20, 10, 0.05) << '\n';
    cout << bf.run() << '\n';
    cout << gd.runBestImprovement(1000) << ' ' << gd.runFirstImprovement(1000) << '\n';
    cout << sa.run(10000);
    return 0;
}