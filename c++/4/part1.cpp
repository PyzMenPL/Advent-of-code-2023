#include <iostream>
#include <vector>
#include <cctype>
#include <set>
#include <algorithm>
#include <cmath>

using std::set;
using std::vector;
using std::cout;
using std::string;
using std::isdigit;
using std::stoi;
using std::endl;
using std::set_intersection;

vector<string> file = {"Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53",
"Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19",
"Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1",
"Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83",
"Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36",
"Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11"};

int get_value(int n) {
    if (n == 0) {
        return 0;
    }
    
    return pow(2, n-1);
}

int main() {
    int sum = 0;
    string buffer = "";
    set<string> left = {};
    set<string> right = {};
    
    for (string line : file) {
        
        left = {};
        right = {};
        buffer = "";
        int i = line.find(": ");
        
        if (i == string::npos) {
            // No such string
            return 1;
        } else {
            i++;
        }
        
        bool add_left = true;
        bool skip = false;
        
        for (; i < line.length(); i++) {
            
            if (skip) {
                skip = false;
                continue;
            } else if (isdigit(line[i])) {
                buffer.push_back(line[i]);
            } else if (line[i] == ' ' && buffer != "") {
                if (add_left) {
                    left.insert(buffer);
                } else {
                    right.insert(buffer);
                }
                
                buffer = "";
            } else if (line[i] == '|') {
                add_left = false;
            }
            
        }
        
        right.insert(buffer);
        
        vector<string> result;
        set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(result, result.begin()));
        
        sum += get_value(result.size());
    }
    
    cout << sum << endl;

    return 0;
}
