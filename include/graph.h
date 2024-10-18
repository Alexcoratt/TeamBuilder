#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_set> // TODO: replace with unordered_map
#include <utility>
#include <functional>

class GraphNode {
public:
    using weight_t = float;

private:
    using noderef_t = std::pair<weight_t, GraphNode *>;
    
    class NodeRefHash { std::size_t operator()(const noderef_t &); };

public:
    using traverse_func = std::function<void(weight_t, GraphNode *)>;
    using const_traverse_func = std::function<void(weight_t, const GraphNode *)>;

    // constructor
    GraphNode();

    // each GraphNode is an essential part of a graph,
    // so it can neither be copied nor moved 
    GraphNode(const GraphNode &) = delete;
    GraphNode(GraphNode &&) = delete;

    GraphNode &operator=(const GraphNode &) = delete;
    GraphNode &operator=(GraphNode &&) = delete;

    // editing
    void pushNeighbour(weight_t, GraphNode *);
    void popNeighbour(GraphNode *);

    void setNeighbourWeight(const GraphNode *);

    // getting
    weight_t getNeighbourWeight(const GraphNode *) const;

    // auxillary
    void traverse(traverse_func);
    void traverseConst(const_traverse_func);

private:
    std::unordered_set<noderef_t, NodeRefHash> _neighbours;
};

#endif