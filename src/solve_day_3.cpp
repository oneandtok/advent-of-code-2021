#include "solver.hpp"

#include <cmath>
#include <vector>

int64_t convertBinaryToDecimal(int64_t& binary) {
    int64_t decimal { 0 };
    int64_t base { 1 };
    while (0 < binary) {
        decimal += binary % 10 * base;
        binary /= 10;
        base *= 2;
    }

    return decimal;
}

int Solver::solveDay3First(std::ifstream& ifs) {
    std::string read_line;
    std::getline(ifs, read_line);

    auto digits = static_cast<int>(read_line.size());
    std::vector<int> count_zeros;
    count_zeros.resize(digits);
    auto countZeros = [&]() {
        for (int i = 0; i < digits; i++) {
            if (read_line[i] - '0' == 0) {
                count_zeros[i]++;
            }
        }
    };

    countZeros();

    int binary_number_count { 1 };
    while (std::getline(ifs, read_line)) {
        countZeros();
        binary_number_count++;
    }

    int64_t binary_gamma { 0 };
    int64_t binary_max { 0 };
    for (int i = 0; i < digits; i++) {
        auto power = digits - i - 1;
        binary_max += std::pow(10, power);

        if (count_zeros[i] < binary_number_count / 2) {
            binary_gamma += std::pow(10, power);
        }
    }

    std::cout << "binary_gamma: [" << binary_gamma << "]\n";
    std::cout << "binary_max: [" << binary_max << "]\n";

    const auto decimal_gamma = convertBinaryToDecimal(binary_gamma);
    const auto decimal_max = convertBinaryToDecimal(binary_max);

    std::cout << "decimal_gamma: [" << decimal_gamma << "]\n";
    std::cout << "decimal_max: [" << decimal_max << "]\n";

    return (decimal_max - decimal_gamma) * decimal_gamma;
}

int Solver::solveDay3Second(std::ifstream& ifs) {
    std::string read_line;
    std::getline(ifs, read_line);
    auto digits = static_cast<int>(read_line.size());

    std::vector<std::string> original_list;
    while (std::getline(ifs, read_line)) {
        original_list.emplace_back(read_line);
    }

    auto getRating = [&](const bool should_get_oxy) -> std::string {
        std::vector<std::string> all_list = original_list;
        std::vector<std::string> zero_list;
        std::vector<std::string> one_list;
        for (int i = 0; i < digits; i++) {
            for (const auto& binary : all_list) {
                if (binary[i] - '0' == 0) {
                    zero_list.emplace_back(binary);
                } else {
                    one_list.emplace_back(binary);
                }
            }

            if (should_get_oxy) {
                all_list.swap(zero_list.size() <= one_list.size() ? one_list : zero_list);
            } else {
                all_list.swap(zero_list.size() <= one_list.size() ? zero_list : one_list);
            }

            zero_list.clear();
            one_list.clear();
        }

        return all_list[0];
    };

    const auto oxy_rate = getRating(true);
    const auto co2_rate = getRating(false);

    int64_t binary_oxy_rate;
    int64_t binary_co2_rate;
    try {
        binary_oxy_rate = std::stoll(oxy_rate);
        binary_co2_rate = std::stoll(co2_rate);
    } catch (...) {
        std::cout << "Failed to stoll. oxy_rate: [" << oxy_rate << "]. co2_rate: [" << co2_rate << "]\n";

        return 0;
    }
    std::cout << "binary_oxy_rate: [" << binary_oxy_rate << "]\n";
    std::cout << "binary_co2_rate: [" << binary_co2_rate << "]\n";

    const auto decimal_oxy_rate = convertBinaryToDecimal(binary_oxy_rate);
    const auto decimal_co2_rate = convertBinaryToDecimal(binary_co2_rate);
    std::cout << "decimal_oxy_rate: [" << decimal_oxy_rate << "]\n";
    std::cout << "decimal_co2_rate: [" << decimal_co2_rate << "]\n";

    return decimal_oxy_rate * decimal_co2_rate;
}
