#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// sums two digits if the digit at n == n+offset
int sum_if_match (const string &line, const int offset) {
    int sum = 0;
    int next = 0;

    for (auto i = 0; i < line.size(); i++) {
        next = i+offset;
        if (next>=line.size())     { next -= line.size();  } // wrap around
        if (line[i] == line[next]) { sum += line[i] - '0'; }
    }

    return sum;
}

int main() {

    string line;
    ifstream input ("1.txt");

    if (!input.is_open()) { cerr << "File not open." << endl; }

    while (getline (input, line)) { } // get only last line

    cout << "Part1: " << sum_if_match(line, 1) << endl;
    cout << "Part2: " << sum_if_match(line, line.size()/2) << endl;

    return 0;
}