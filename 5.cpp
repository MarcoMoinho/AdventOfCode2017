#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int navigate_part1(vector<int> input) {
    int steps {0}, pos {0};
    do {
        ++steps;
        pos += input[pos]++;
        if (pos >= input.size()) { break; }
    } while (true);
    return steps;
}

int navigate_part2(vector<int> input) {
    int steps {0}, pos {0}, offset {1};
    do {
        ++steps;
        if (input[pos] >= 3) { offset = -1; } else { offset = 1; }
        input[pos] += offset;
        pos += input[pos] - offset;
        if (pos >= input.size()) { break; }
    } while (true);
    return steps;
}

int main() {
    ifstream file ("5.txt");
    string line;
    vector<int> input;    
    while (getline(file, line)) {
        input.push_back(stoi(line));
    }

    cout << "Part 1: " << navigate_part1(input) << endl;
    cout << "Part 2: " << navigate_part2(input) << endl;

    return 0;
}
