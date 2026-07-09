#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// --- Day 1: Report Repair ---

void part1(std::ifstream& file) {
    std::string entry;
    std::vector<int> entries;

    while (getline(file, entry)) {
        entries.push_back(std::stoi(entry));
    }

    for (int i = 0; i < entries.size(); i++) {
        for (int j = i + 1; j < entries.size() - 1; j++) { // starts at i + 1 to avoid checking same pair
            if (entries[i] + entries[j] == 2020) {
                std::cout << entries[i] * entries[j] << "\n";
            }
        }
    }
}

void part2(std::ifstream& file) {
    std::string entry;
    std::vector<int> entries;

    while (getline(file, entry)) {
        entries.push_back(std::stoi(entry));
    }

    for (int i = 0; i < entries.size(); i++) {
        for (int j = i + 1; j < entries.size() - 1; j++) { // starts at i + 1 to avoid checking same pair
            for (int k = j + 1; k < entries.size() - 2; k++) {
                if (entries[i] + entries[j] + entries[k] == 2020) {
                    std::cout << entries[i] * entries[j] * entries[k] << "\n";
                }
            }
        }
    }
}


int main() {
    std::ifstream file("aoc.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
    }
    part1(file);
    part2(file);
}
