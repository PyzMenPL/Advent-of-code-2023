// 35747 - too low
// 93 - too low

#include <iostream>
#include <vector>
#include <cctype>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stoi;
using std::isdigit;


int get_dist(int speed, int time_left) {
    return speed * time_left;
}

void test(unsigned long long czas = 71530, unsigned long long record = 940200) {
    unsigned long long new_records = 0;
    unsigned long long last_result = 0;
    for (int j = 14; j < 71517; j++) {
        unsigned long long result = get_dist(j, czas-j);
        
        if (result < last_result) {
            new_records *= 2;
            break;
        }
        
        if (result > record) {
            new_records++;
        }
        
        last_result = result;
    }
   
    cout << new_records-1 << endl;
}

int main()
{
    test();
    test(45977295, 305106211101695);

    return 0;
}
