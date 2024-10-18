#include "graph.h"

GraphNode::GraphNode() {}

// editing
void GraphNode::pushNeighbour(weight_t weight, GraphNode *node) {
    _neighbours.insert({weight, node});
}

void GraphNode::popNeighbour(GraphNode *node) {
    _neighbours.
}