#ifndef ADVENT_OF_CODE_2021_INCLUDE_SOLVER_HPP_
#define ADVENT_OF_CODE_2021_INCLUDE_SOLVER_HPP_

#include <iostream>
#include <fstream>

class Solver {
public:
    bool loadOptions(const int, char**);
    void printUsage();
    void run();

    int solveDay1First(std::ifstream&);
    int solveDay1Second(std::ifstream&);

private:
    int m_target_day;
    int m_target_puzzle_number;
    std::string m_input_file;
};

#endif  // ADVENT_OF_CODE_2021_INCLUDE_SOLVER_HPP_
