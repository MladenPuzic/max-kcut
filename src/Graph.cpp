//
// Created by Mladen Puzić on 20.7.24..
//

#include "Graph.h"

void Graph::addEdge(int x, int y, int w) {
    if (x < 0 || x >= m_nodeCount) {
        return;
    }
    if (y < 0 || y >= m_nodeCount) {
        return;
    }
    m_adj[x][y] += w;
    m_adj[y][x] += w;
    if (x > y) {
        std::swap(x, y);
    }
    m_edges.push_back({x, y, w});
}

int Graph::getNodeCount() { return m_nodeCount; }

const std::vector<Graph::Edge>& Graph::getEdges() { return m_edges; }
