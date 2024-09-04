#include <iostream>

#include "BruteForce.h"
#include "GeneticAlgorithm.h"
#include "Graph.h"
#include "Greedy.h"
#include "SimmulatedAnnealing.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    Graph g(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g.addEdge(x, y, w);
    }
    GeneticAlgorithm ga(k, &g);
    BruteForce bf(k, &g);
    Greedy gd(k, &g);
    SimmulatedAnnealing sa(k, &g);
    cout << ga.run(200, 100, 20, 10, 0.1) << ", ";
    cout.flush();
    if (n <= 20) {
        cout << bf.run() << ", ";
    } else {
        cout << "DNF" << ", ";
    }

    cout.flush();
    cout << gd.runBestImprovement(10000) << ", " << gd.runFirstImprovement(10000) << ", ";
    cout.flush();
    cout << sa.run(10000) << '\n';
    return 0;
}
/*
./max_kcut < ../tests/1.in >> ../tests/results.csv
./max_kcut < ../tests/2.in >> ../tests/results.csv
./max_kcut < ../tests/3.in >> ../tests/results.csv
./max_kcut < ../tests/4.in >> ../tests/results.csv
./max_kcut < ../tests/5.in >> ../tests/results.csv
./max_kcut < ../tests/6.in >> ../tests/results.csv
./max_kcut < ../tests/7.in >> ../tests/results.csv
./max_kcut < ../tests/8.in >> ../tests/results.csv
./max_kcut < ../tests/9.in >> ../tests/results.csv
./max_kcut < ../tests/10.in >> ../tests/results.csv
./max_kcut < ../tests/11.in >> ../tests/results.csv
./max_kcut < ../tests/12.in >> ../tests/results.csv
./max_kcut < ../tests/13.in >> ../tests/results.csv
./max_kcut < ../tests/14.in >> ../tests/results.csv
./max_kcut < ../tests/15.in >> ../tests/results.csv
./max_kcut < ../tests/16.in >> ../tests/results.csv
./max_kcut < ../tests/17.in >> ../tests/results.csv
./max_kcut < ../tests/18.in >> ../tests/results.csv
./max_kcut < ../tests/19.in >> ../tests/results.csv
./max_kcut < ../tests/20.in >> ../tests/results.csv
*/