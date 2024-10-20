#include <iomanip>
#include "iograph.hpp"

std::ostream &operator<<(std::ostream &out, const Graph &gr) {
    auto vcount = gr.getVertexCount();
    using size_type = decltype(vcount);

    const int width = 6;

    out << std::fixed << std::setprecision(1) << std::setw(width + 1) << std::left;

    for (size_type i = 0; i < vcount; ++i) 
        out << ' ' << std::setw(width) << i;
    out << '\n';

    for (size_type i = 0; i < vcount; ++i) {
        out << std::right << std::setw(width) << i;
        for (size_type j = 0; j < vcount; ++j)
            out << '|' << std::left << std::setw(width) << gr.getWeight(i, j);
        out << "|\n";
    }

    return out;
}

int fill(Graph &gr, std::istream &input) {
    Graph::weight_t weight = 1;
    Graph::grsize_t firstVertex = 0, secondVertex = 0;
    char delimiter = '\0';

    while (!input.eof()) {
        if (input >> secondVertex && !gr.setWeight(firstVertex, --secondVertex, 100 / weight)) {
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
                    weight = 1;
                    break;
                default:
                    std::cerr << "Error: unknown delimiter \'" << delimiter << "\'\n";
                    return 3;
            }
        }
    }

    return 0;
}