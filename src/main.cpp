#include <iostream>
#include <fstream>

#include "graph.hpp"
#include "iograph.hpp"

typedef Graph::grsize_t grsize_t;
typedef Graph::weight_t weight_t;

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

    grsize_t minTeamSize = 0, maxTeamSize = 0, memberCount = 0;
    *input >> minTeamSize >> maxTeamSize >> memberCount;

    if (memberCount == 0) {
        std::cerr << "Error: no lines to read. Exiting\n";
        return 0;
    }

    Graph gr(memberCount);
    int res = fill(gr, *input);
    if (input != &std::cin) delete input;
    if (res != 0) return res;

    std::cout << gr << std::endl;
    std::cout << "min team size: " << minTeamSize << "\nmax team size: " << maxTeamSize << std::endl;

    return 0;
}