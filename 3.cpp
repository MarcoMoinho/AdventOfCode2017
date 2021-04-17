#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
using std::vector;


int calc_manhantan_dist (const int target) {
    if (target == 1) return 0;

    // calculate the bottom right corner to find the correct "ring"
    int ring {1};
    int ring_max {0};
    do {
        ring_max = ring * 2 + 1;         // calc the ring width
        ring_max = ring_max * ring_max;  // calc the max of the ring
        ++ring;
    }
    while (target > ring_max);
    ring -= 1;

    if (target == ring_max) { return ring*2; }

    // navigate backwards to the position
    for (int i = 0; i != 5; ++i) {
        if (target < (ring_max - ring * 2 * i)) continue;
        // return the offset from the new corner
        ring_max = (ring_max - ring * 2 * i);
        return std::abs(target - ring_max - ring) + ring;
    }
    return -99; // error
}

int main() {
    
    cout << calc_manhantan_dist(1) << endl;
    cout << calc_manhantan_dist(12) << endl;
    cout << calc_manhantan_dist(23) << endl;
    cout << calc_manhantan_dist(1024) << endl;
    cout << "Part 1: " << calc_manhantan_dist(265149) << endl;

    return 0;
}
