#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include <string>

void genSmallGraph(int tc, std::mt19937 rnd); // k^n <= 10^10
void genBigSparseGraph(int tc, std::mt19937 rnd); // n <= 200, m <= 200, k <= 20
void genBigGraphSmallK(int tc, std::mt19937 rnd); // n <= 200, k <= 5
void genBigGraphBigK(int tc, std::mt19937 rnd); //   n <= 200, k <= 20

int main()
{
    std::mt19937 rnd(time(nullptr));
    for (int tc = 1; tc <= 10; tc++) {
        genSmallGraph(tc, rnd);
    }
    for (int tc = 11; tc <= 20; tc++) {
        genBigSparseGraph(tc, rnd);
    }
    for (int tc = 21; tc <= 30; tc++) {
        genBigGraphSmallK(tc, rnd);
    }
    for (int tc = 31; tc <= 40; tc++) {
        genBigGraphBigK(tc, rnd);
    }
    return 0;
}

void genSmallGraph(int tc, std::mt19937 rnd) {
    // k = 5, n = 14 x 4
    // k = 4, n = 16 x 2
    // k = 3, n = 20 x 2
    // k = 2, n = 33 x 2
    std::ofstream out;
    out.open(std::to_string(tc) + ".in");
    int n, m, k;
    if (tc <= 2) {
        k = 2;
        n = 33;
    } else if (tc <= 4) {
        k = 3;
        n = 20;
    } else if (tc <= 6) {
        k = 4;
        n = 16;
    } else {
        k = 5;
        n = 14;
    }
    m = std::uniform_int_distribution<int>(4*n, n*(n-1)/2)(rnd);
    auto rnd_node = std::uniform_int_distribution<int>(0, n-1);
    auto rnd_weight = std::uniform_int_distribution<int>(1, 100);
    out << n << ' ' << m << ' ' << k << std::endl;
    std::vector<std::vector<int> > cst(n, std::vector<int>(n));
    for (int i = 1; i <= m; i++) {
        int x, y;
        do {
            x = rnd_node(rnd);
            y = rnd_node(rnd);
        } while (x == y || cst[x][y] != 0);
        cst[x][y] = cst[y][x] = rnd_weight(rnd);
        out << x << ' ' << y << ' ' << cst[x][y] << std::endl;
    }
    out.close();
}

void genBigSparseGraph(int tc, std::mt19937 rnd) {
    std::ofstream out;
    out.open(std::to_string(tc) + ".in");
    int n, m, k;
    n = std::uniform_int_distribution<int>(120, 130)(rnd);
    m = std::uniform_int_distribution<int>(190, 200)(rnd);
    k = std::uniform_int_distribution<int>(2, 20)(rnd);

    auto rnd_node = std::uniform_int_distribution<int>(0, n-1);
    auto rnd_weight = std::uniform_int_distribution<int>(1, 10000);
    out << n << ' ' << m << ' ' << k << std::endl;
    std::vector<std::vector<int> > cst(n, std::vector<int>(n));
    for (int i = 1; i <= m; i++) {
        int x, y;
        do {
            x = rnd_node(rnd);
            y = rnd_node(rnd);
        } while (x == y || cst[x][y] != 0);
        cst[x][y] = cst[y][x] = rnd_weight(rnd);
        out << x << ' ' << y << ' ' << cst[x][y] << std::endl;
    }
    out.close();
}

void genBigGraphSmallK(int tc, std::mt19937 rnd) {
    std::ofstream out;
    out.open(std::to_string(tc) + ".in");
    int n, m, k;
    n = std::uniform_int_distribution<int>(190, 200)(rnd);
    m = std::uniform_int_distribution<int>(n*(n-1)/4, n*(n-1)/2)(rnd);
    k = std::uniform_int_distribution<int>(2, 5)(rnd);

    auto rnd_node = std::uniform_int_distribution<int>(0, n-1);
    auto rnd_weight = std::uniform_int_distribution<int>(1, 10000);
    out << n << ' ' << m << ' ' << k << std::endl;
    std::vector<std::vector<int> > cst(n, std::vector<int>(n));
    for (int i = 1; i <= m; i++) {
        int x, y;
        do {
            x = rnd_node(rnd);
            y = rnd_node(rnd);
        } while (x == y || cst[x][y] != 0);
        cst[x][y] = cst[y][x] = rnd_weight(rnd);
        out << x << ' ' << y << ' ' << cst[x][y] << std::endl;
    }
    out.close();
}

void genBigGraphBigK(int tc, std::mt19937 rnd) {
    std::ofstream out;
    out.open(std::to_string(tc) + ".in");
    int n, m, k;
    n = std::uniform_int_distribution<int>(190, 200)(rnd);
    m = std::uniform_int_distribution<int>(n*(n-1)/4, n*(n-1)/2)(rnd);
    k = std::uniform_int_distribution<int>(6, 20)(rnd);

    auto rnd_node = std::uniform_int_distribution<int>(0, n-1);
    auto rnd_weight = std::uniform_int_distribution<int>(1, 10000);
    out << n << ' ' << m << ' ' << k << std::endl;
    std::vector<std::vector<int> > cst(n, std::vector<int>(n));
    for (int i = 1; i <= m; i++) {
        int x, y;
        do {
            x = rnd_node(rnd);
            y = rnd_node(rnd);
        } while (x == y || cst[x][y] != 0);
        cst[x][y] = cst[y][x] = rnd_weight(rnd);
        out << x << ' ' << y << ' ' << cst[x][y] << std::endl;
    }
    out.close();
}