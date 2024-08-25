#include <iostream>

#include "GeneticAlgorithm.h"
#include "BruteForce.h"
#include "Graph.h"
#include "Greedy.h"
#include "SimmulatedAnnealing.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

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
    cout << ga.run(200, 100, 20, 10, 0.05) << endl;
    cout << bf.run() << endl;
    cout << gd.runBestImprovement(1000) << ' ' << gd.runFirstImprovement(1000) << endl;
    cout << sa.run(1000);
    return 0;
}