#include <iostream>

#include "GeneticAlgorithm.h"
#include "BruteForce.h"
#include "Graph.h"

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
    cout << ga.run(100, 10, 7, 10, 0.05) << endl;
    cout << bf.run();
    return 0;
}