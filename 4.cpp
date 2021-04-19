#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<string> string_split (const string &input, const char separator, const bool sort = false) {
    vector<string> result;
    if (input.empty()) return result;
    string temp;

    for (const auto c : input) {
        if (c != separator) {
            temp += c;
            continue;
        }
        if (!temp.empty()) {
            if (sort) { std::sort(temp.begin(), temp.end()); }
            result.push_back(temp);
        }
        temp.clear();
    }
    if (!temp.empty()) {
        if (sort) { std::sort(temp.begin(), temp.end()); }
        result.push_back(temp);
    }
    result.shrink_to_fit();
    return std::move(result);
}


// check if there are duplicate words in the phrase
bool contains_duplicates(const string &input, const char separator, const bool sort) {
    const auto items = string_split(input, separator, sort);
    for (auto i = items.begin(); i != items.end(); ++i) {
       if (std::count(items.begin(), items.end(), *i) > 1) { return true; }
    }
    return false;
}


int main() {
    int p1_valid {0}, p2_valid {0};
    ifstream input ("4.txt");
    string line;
    while (getline(input, line)) {
        if (!contains_duplicates(line,' ',false)) ++p1_valid;
        // if we sort the component we don't need to check for anagrams
        if (!contains_duplicates(line,' ',true))  ++p2_valid;
    }
    cout << "Part 1: " << p1_valid << endl;
    cout << "Part 2: " << p2_valid << endl;

    return 0;
}
