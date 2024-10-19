#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <limits.h>

class Graph {
public:
    using grsize_t = std::size_t;
    using weight_t = unsigned int;

    constexpr static weight_t WEIGHT_T_MIN = 0;
    constexpr static weight_t WEIGHT_T_MAX = UINT_MAX;

    constexpr static weight_t ERR_WEIGHT = WEIGHT_T_MAX;

    // constructors
        Graph(grsize_t vertexCount = 0);

        Graph(const Graph &);
        Graph(Graph &&);

    // assignment
        Graph &operator=(const Graph &);
        Graph &operator=(Graph &&);

    // editing
        // returns false if any of vertices is out of the range
        bool setWeight(grsize_t firstVertex, grsize_t secondVertex, weight_t);

    // getting
        grsize_t getVertexCount() const;

        // returns ERR_WEIGHT if any of vertices is out of the range
        weight_t getWeight(grsize_t firstVertex, grsize_t secondVertex) const;

private:
    grsize_t _vertexCount;
    std::vector<weight_t> _weights;
};

#endif