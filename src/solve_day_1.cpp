#include "solver.hpp"

#include <list>
#include <numeric>

int Solver::solveDay1First(std::ifstream& ifs) {
    int previous_depth { -1 };
    int depth_increasing_count { 0 };
    std::string read_line;
    while (std::getline(ifs, read_line)) {
        try {
            if (previous_depth < 0) {
                previous_depth = std::stoi(read_line);

                continue;
            }

            auto now_depth = std::stoi(read_line);
            if (previous_depth < now_depth) {
                depth_increasing_count++;
            }

            previous_depth = now_depth;
        } catch (...) {
            std::cout << "Failed to stoi. read_line: [" << read_line << "]\n";

            continue;
        }
    }

    return depth_increasing_count;
}

int Solver::solveDay1Second(std::ifstream& ifs) {
    int previous_depth { -1 };
    int depth_increasing_count { 0 };
    std::list<int> depth_window;
    std::string read_line;
    while (std::getline(ifs, read_line)) {
        try {
            auto depth = std::stoi(read_line);
            if (3 <= depth_window.size()) {
                depth_window.pop_front();
            }

            depth_window.emplace_back(depth);

            if (depth_window.size() < 3) {
                continue;
            }

            auto now_depth = std::accumulate(depth_window.begin(), depth_window.end(), 0);

            if (previous_depth != -1 && previous_depth < now_depth) {
                depth_increasing_count++;                
            }

            previous_depth = now_depth;
        } catch (...) {
            std::cout << "Failed to stoi. read_line: [" << read_line << "]\n";

            continue;
        }
    }

    return depth_increasing_count;
}
