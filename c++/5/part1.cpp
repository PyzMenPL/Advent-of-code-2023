#include <iostream>
#include <vector>
#include <cctype>

using std::cout;
using std::vector;
using std::string;
using std::getline;
using std::isdigit;

vector<string> plik = {
    "seeds: 79 14 55 13",
    "",
    "seed-to-soil map:",
    "50 98 2",
    "52 50 48",
    "",
    "soil-to-fertilizer map:",
    "0 15 37",
    "37 52 2",
    "39 0 15",
    "",
    "fertilizer-to-water map:",
    "49 53 8",
    "0 11 42",
    "42 0 7",
    "57 7 4",
    "",
    "water-to-light map:",
    "88 18 7",
    "18 25 70",
    "",
    "light-to-temperature map:",
    "45 77 23",
    "81 45 19",
    "68 64 13",
    "",
    "temperature-to-humidity map:",
    "0 69 1",
    "1 0 69",
    "",
    "humidity-to-location map:",
    "60 56 37",
    "56 93 4"
};


int main()
{
    vector<int> seeds;
    
    string buffer;
    
    for (int i = 0; i < plik.size(); i++) {
        for (int j = 0; j < plik[i].length(); j++) {
            if ()
            buffer.push_back(plik[i]);
            if (i == 0) {
                
            }
        }
    }

    return 0;
}
