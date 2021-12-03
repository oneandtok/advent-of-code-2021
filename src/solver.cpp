#include "solver.hpp"

#include <chrono>
#include <optional>

void Solver::run() {
    auto start = std::chrono::system_clock::now();

    std::ifstream ifs(m_input_file);
    if (!ifs) {
        std::cout << "Failed to open input file [" << m_input_file << "]\n";
        printUsage();

        return;
    }

    std::optional<int> answer { std::nullopt };

    if (m_target_day == 1) {
        if (m_target_puzzle_number == 1) {
            answer = solveDay1First(ifs);
        } else if (m_target_puzzle_number == 2) {
            answer = solveDay1Second(ifs);
        }
    } else if (m_target_day == 2) {
        if (m_target_puzzle_number == 1) {
            answer = solveDay2First(ifs);
        } else if (m_target_puzzle_number == 2) {
            answer = solveDay2Second(ifs);
        }
    } else if (m_target_day == 3) {
        if (m_target_puzzle_number == 1) {
            answer = solveDay3First(ifs);
        } else if (m_target_puzzle_number == 2) {
            answer = solveDay3Second(ifs);
        }
    }

    if (answer.has_value()) {
        auto end = std::chrono::system_clock::now();
        auto run_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        std::cout << "The answer is [" << answer.value() << "] / run_time: [" << run_time << "]us\n";

        return;
    }

    std::cout << "The target day or the puzzle number is NOT available now\n";
    printUsage();
}

bool Solver::loadOptions(const int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "-d" || std::string(argv[i]) == "--day") {
            i++;

            try {
                m_target_day = atoi(argv[i]);
            } catch (...) {
                std::cout << "Failed to recognize the day to solve\n";
                printUsage();

                return false;
            }

            continue;
        }

        if (std::string(argv[i]) == "-p" || std::string(argv[i]) == "--puzzle") {
            i++;

            try {
                m_target_puzzle_number = atoi(argv[i]);
            } catch (...) {
                std::cout << "Failed to recognize the puzzle number to solve\n";
                printUsage();

                return false;
            }

            continue;
        }

        if (std::string(argv[i]) == "-i" || std::string(argv[i]) == "--input") {
            i++;

            m_input_file = std::string(argv[i]);

            continue;
        }
    }

    return true;
}

void Solver::printUsage() {
    std::cout << "Usage: $ advent-of-code-2021 [-d|--day] DAY [-p|--puzzle] NUMBER_OF_PUZZLE [-i|--input] INPUT_FILE_PATH\n";
}
