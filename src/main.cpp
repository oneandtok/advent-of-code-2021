#include "solver.hpp"

int main(int argc, char** argv) {
    Solver solver;
    auto success = solver.loadOptions(argc, argv);
    if (!success) {
        solver.printUsage();

        return 0;
    }

    solver.run();

    return 0;
}
