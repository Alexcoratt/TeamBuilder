#include <iostream>
#include <fstream>

#include "graph.h"

std::ostream &operator<<(std::ostream &, const Graph &);
int fillGraph(Graph &, std::istream &);

int main(int argc, char **argv) {
    std::istream *input = nullptr;

    if (argc == 1)
        input = &std::cin;
    else {
        input = new std::ifstream(argv[1]);
        if (!input->good()) {
            std::cerr << "Error: error occured while opening file \"" << argv[1] << "\"\n";
            delete input;
            return 1;
        }
    }

    Graph::grsize_t vertexCount = 0;
    *input >> vertexCount;

    if (vertexCount == 0) {
        std::cerr << "Error: no lines to read. Exiting\n";
        return 0;
    }

    Graph gr(vertexCount);
    fillGraph(gr, *input);
    
    if (input != &std::cin) delete input;

    std::cout << gr << std::endl;

    return 0;
}

std::ostream &operator<<(std::ostream &out, const Graph &gr) {
    auto vcount = gr.getVertexCount();
    for (decltype(vcount) i = 0; i < vcount; ++i) {
        for (decltype(vcount) j = 0; j < vcount; ++j)
            out << gr.getWeight(i, j) << ' ';
        out << '\n';
    }

    return out;
}

int fillGraph(Graph &gr, std::istream &input) {
    Graph::weight_t weight = 0;
    Graph::grsize_t firstVertex = 0, secondVertex = 0;
    char delimiter = '\0';

    while (!input.eof()) {
        if (input >> secondVertex && !gr.setWeight(firstVertex, --secondVertex, weight)) {
            std::cerr << "Error: given vertex " << std::max(firstVertex, secondVertex) << " is out of range " << gr.getVertexCount() << "\n";
            return 2;
        }

        if (!input.good()) input.clear();

        if (input >> delimiter) {
            switch (delimiter) {
                case ';':
                    ++weight;
                    break;
                case '|':
                    break;
                case '/':
                    ++firstVertex;
                    weight = 0;
                    break;
                default:
                    std::cerr << "Error: unknown delimiter \'" << delimiter << "\'\n";
                    return 3;
            }
        }
    }

    return 0;
}