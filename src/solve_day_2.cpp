#include "solver.hpp"

namespace {

constexpr std::string_view FORWARD { "forward " };
constexpr std::string_view UP { "up " };
constexpr std::string_view DOWN { "down " };

}  // namespace

int Solver::solveDay2First(std::ifstream& ifs) {
    int horizontal_pos { 0 };
    int depth { 0 };
    std::string read_line;
    while (std::getline(ifs, read_line)) {
        try {
            if (read_line.find(FORWARD) != std::string::npos) {
                horizontal_pos += std::stoi(read_line.substr(FORWARD.size(), read_line.size() - FORWARD.size()));

                continue;
            } else if (read_line.find(UP) != std::string::npos) {
                depth -= std::stoi(read_line.substr(UP.size(), read_line.size() - UP.size()));

                continue;
            } else if (read_line.find(DOWN) != std::string::npos) {
                depth += std::stoi(read_line.substr(DOWN.size(), read_line.size() - DOWN.size()));

                continue;
            } else {
                std::cout << "Found unknown index: [" << read_line << "]\n";

                continue;
            }
        } catch (...) {
            std::cout << "Failed to stoi. read_line: [" << read_line << "]\n";

            continue;
        }
    }

    return horizontal_pos * depth;
}

int Solver::solveDay2Second(std::ifstream& ifs) {
    int aim { 0 };
    int horizontal_pos { 0 };
    int depth { 0 };
    std::string read_line;
    while (std::getline(ifs, read_line)) {
        try {
            if (read_line.find(FORWARD) != std::string::npos) {
                auto i = std::stoi(read_line.substr(FORWARD.size(), read_line.size() - FORWARD.size()));
                horizontal_pos += i;
                depth += i * aim;

                continue;
            } else if (read_line.find(UP) != std::string::npos) {
                aim -= std::stoi(read_line.substr(UP.size(), read_line.size() - UP.size()));

                continue;
            } else if (read_line.find(DOWN) != std::string::npos) {
                aim += std::stoi(read_line.substr(DOWN.size(), read_line.size() - DOWN.size()));

                continue;
            } else {
                std::cout << "Found unknown index: [" << read_line << "]\n";

                continue;
            }
        } catch (...) {
            std::cout << "Failed to stoi. read_line: [" << read_line << "]\n";

            continue;
        }
    }

    return horizontal_pos * depth;
}
