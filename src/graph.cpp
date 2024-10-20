#include "graph.hpp"

// constructors
    Graph::Graph(grsize_t vertexCount) : _vertexCount(vertexCount), _weights(vertexCount * vertexCount) {}

    Graph::Graph(const Graph &other) : _vertexCount(other._vertexCount), _weights(other._weights) {}
    Graph::Graph(Graph &&other) : _vertexCount(other._vertexCount), _weights(std::move(other._weights)) {}

// assignment
    Graph &Graph::operator=(const Graph &other) {
        _vertexCount = other._vertexCount;
        _weights = other._weights;
        return *this;
    }

    Graph &Graph::operator=(Graph &&other) {
        _vertexCount = other._vertexCount;
        _weights = std::move(other._weights);
        return *this;
    }

// editing
    #define MX_INDEX(ROW, COL, WIDTH) (WIDTH) * (ROW) + (COL)

    bool Graph::setWeight(grsize_t first, grsize_t second, weight_t weight) {
        if (first >= _vertexCount || second >= _vertexCount)
            return false;

        _weights[MX_INDEX(first, second, _vertexCount)] = weight;
        return true;
    }

// getting
    Graph::grsize_t Graph::getVertexCount() const { return _vertexCount; }

    Graph::weight_t Graph::getWeight(grsize_t first, grsize_t second) const {
        if (first >= _vertexCount || second >= _vertexCount)
            return ERR_WEIGHT;
        
        return _weights[MX_INDEX(first, second, _vertexCount)];
    }