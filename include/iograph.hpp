#ifndef PRINT_GRAPH_HPP
#define PRINT_GRAPH_HPP

#include <iostream>
#include "graph.hpp"

int fill(Graph &, std::istream &);
std::ostream &operator<<(std::ostream &, const Graph &);

#endif