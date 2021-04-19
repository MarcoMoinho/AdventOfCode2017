#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// same as Day 02
vector<string> string_split (const string &input, const char separator) {
    vector<string> result;
    if (input.empty()) return result;
    string temp;

    for (const auto c : input) {
        if (c != separator) {
            temp += c;
            continue;
        }
        if (!temp.empty()) result.push_back(temp);
        temp.clear();
    }
    if (!temp.empty()) result.push_back(temp);
    
    result.shrink_to_fit();
    return std::move(result);
}


// check if there are duplicate words in the phrase
bool contains_duplicates(const string &input, const char separator) {
    auto items = string_split(input, separator);
    for (auto i = items.begin(); i != items.end(); ++i) {
       if (std::count(items.begin(), items.end(), *i) > 1) { return true; }
    }
    return false;
}


int main() {

    int valid {0};
    ifstream input ("4.txt");
    string line;
    while (getline(input, line)) {
        if (!contains_duplicates(line,' ')) ++valid;
    }

    cout << "Part 1: " << valid << endl;

    return 0;
}