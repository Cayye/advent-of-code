#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_set>

// Day 4: Passport Porcessing

void part1(std::ifstream& file) {
    std::vector<std::string> fields = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid", "cid"};

    std::vector<std::string> data;
    std::string line;

    while (getline(file, line)) {
        data.push_back(line);
    }

    int valid_passports = 0;
    int i = 0;
    while (i <= data.size()) {
        
        std::basic_istringstream<char> stream(data[i]);
        std::string field;

        std::vector<std::string> fields_present;
        while (stream >> field) {
            size_t end_pos = field.find(":");
            if (end_pos != std::string::npos) {
                fields_present.push_back(field.substr(0, end_pos));
            }
        }

        // See if the required fields exist
        std::unordered_set<std::string> set(fields_present.begin(), fields_present.end());
        std::vector<std::string> missing;
        for (std::string& field: fields) {
            if (set.find(field) == set.end() && field != "cid") { // cid is a valid field
                missing.push_back(field);
            }
        } 

        if (missing.empty()) {
            valid_passports++; // no missing fields!
        }
        i++;
    }

    std::cout << valid_passports << "\n";
}   

int main() {
    std::ifstream file("aoc.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << "\n";
        return 1;
    }

    part1(file);
    return 0;
}
