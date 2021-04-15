#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using std::vector;


vector<string> string_split (const string &input, const char &separator) {
    vector<string> result;
    if (input.empty()) return result;
    string temp("");

    for (const auto &c : input) {
        if (c != separator) {
            temp += c;
            continue;
        }
        if (!temp.empty()) result.push_back(temp);
        temp = "";
    }
    if (!temp.empty()) result.push_back(temp);
    
    return result;
}


// return max - min;
int part1_calc_checksum (const string &line, const char &separator) {
    int max = 0;
    int min = 1000;
    auto data = string_split(line, separator);

    for (const auto value : data) {
        if (stoi(value) > max) { max = stoi(value); }
        if (stoi(value) < min) { min = stoi(value); }
    }
    return max - min;
}

// returns division if mod == 0
int part2_calc_division (const string &line, const char &separator) {
    auto data = string_split(line, separator);
    for (const auto a : data) {
        for (const auto b : data) {
            int val_a = stoi(a), val_b = stoi(b);
            if (val_a == val_b) continue;
            if (val_a % val_b == 0) return val_a/val_b;
            if (val_b % val_a == 0) return val_b/val_a;
        }
    }
}


int main() {
    string line;
    ifstream input ("2.txt");

    if (!input.is_open()) { cerr << "File not open." << endl; return 1; }

    int checksum = 0;
    int sum = 0;
    while (getline (input, line)) {
        checksum += part1_calc_checksum(line, '	');
        sum += part2_calc_division(line, '	');
    }

    cout << "Part 1: " << checksum << endl;
    cout << "Part 2: " << sum << endl;

    return 0;
} 