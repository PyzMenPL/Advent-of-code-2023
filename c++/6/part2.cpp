// 35747 - too low

#include <iostream>
#include <vector>
#include <cctype>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stoi;
using std::isdigit;

/*vector<string> plik = {
    "Time:        45     97     72     95",
    "Distance:   305   1062   1110   1695"
};*/

int get_dist(int speed, int time_left) {
    return speed * time_left;
}

int main()
{
    //vector<int> times = {45977295};
    //vector<long> distances = {305106211101695};
    
    //vector<int> times = {71530};
    //vector<long> distances = {940200};
    
    /*for (int i = 0; i < plik.size(); i++) {
        string line = plik[i];
        string buffer;
        for (int j = 9; j < line.length(); j++) {
            if (isdigit(line[j])) {
                buffer.push_back(line[j]);
            } else if (buffer != "") {
                if (i) {
                    distances.push_back(stoi(buffer));
                } else {
                    times.push_back(stoi(buffer));
                }
                buffer = "";
            } 
        }
        
        if (i) {
            distances.push_back(stoi(buffer));
        } else {
            times.push_back(stoi(buffer));
        }
    }*/
    
    unsigned long long new_records = 0;
    for (int j = 14; j < 71517; j++) {
        unsigned long long result = get_dist(j, 45977295-j);
        
        if (result > 305106211101695) {
            new_records++;
        }
    }
   
    cout << new_records << endl;

    return 0;
}
