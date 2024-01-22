#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::getline;
using std::vector;
using std::pair;
using std::min;
using std::max;
using std::abs;

int main() {
    // Downloading data from a file
    ifstream file("input.txt");

    vector<int> rows;
    vector<int> cols;
    vector<pair<int, int>> galaxies;

    string line;
    int i = -1;

    while (getline(file, line)) {
        // cols varizble initialization
        if (cols.empty()) {
            for (int j = 0; j < line.size(); j++) {
                cols.push_back(j);
            }
        }

        i++;

        int old_size = galaxies.size();

        for (int j = 0; j < line.size(); j++) {
            // Galaxy found
            if (line[j] == '#') {
                galaxies.push_back(pair<int, int>(i,j));

                // Remove adequate collumn
                for (int k = 0; k < cols.size(); k++) {
                    if (cols[k] == j) {
                        cols.erase(cols.begin()+k);
                        break;
                    }
                }
            }
        }

        // If there were no galaxies in line
        if (old_size == galaxies.size()) {
            rows.push_back(i);
        }
    }

    file.close();

    // Calculating output
    int sum = 0;

    for (int i = 0; i < galaxies.size(); i++) {
        for (int j = i+1; j < galaxies.size(); j++) {
            int g1_y = galaxies[i].first;
            int g1_x = galaxies[i].second;
            int g2_y = galaxies[j].first;
            int g2_x = galaxies[j].second;

            // Adding vertical distance
            int add_ver = 0;
            for (int k = 0; k < rows.size(); k++) {
                if (min(g1_y, g2_y) < rows[k] && rows[k] < max(g1_y, g2_y)) {
                    add_ver++;
                }
            }

            // Adding horizontal distance
            int add_hor = 0;
            for (int k = 0; k < cols.size(); k++) {
                if (min(g1_x, g2_x) < cols[k] && cols[k] < max(g1_x, g2_x)) {
                    add_hor++;
                }
            }

            sum += abs(g1_y - g2_y) + add_ver + abs(g1_x - g2_x) + add_hor;
        }
    }

    cout << sum << endl;

    return 0;
}
