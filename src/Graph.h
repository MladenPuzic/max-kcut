//
// Created by Mladen Puzić on 20.7.24..
//

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
public:
    Graph(int nodeCount = 0) {
        m_nodeCount = nodeCount;
        m_adj = std::vector<std::vector<int>>(m_nodeCount, std::vector<int>(m_nodeCount));
    }
    struct Edge {
        int src, dst, w;
    };
    void addEdge(int x, int y, int w);
    int getNodeCount();
    const std::vector<Edge>& getEdges();
private:
    int m_nodeCount;
    std::vector<std::vector<int> > m_adj;
    std::vector<Edge> m_edges;
};

#endif //GRAPH_H
