// 35747 - too low
// 93 - too low
// 18446744073709551615 -> unsigned long long
// 305106211101695

#include <iostream>
#include <vector>
#include <cctype>
#include <unordered_set>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stoi;
using std::isdigit;
using std::unordered_set;

int get_dist(int speed, int time_left) {
    return speed * time_left;
}

void test(/*unsigned*/ long long czas = 71530, /*unsigned*/ long long record = 940200) {
    //unordered_set<long long> known_outputs;
    long long lowest = 0;

    /*unsigned*/ long long new_records = 1;
    for (int j = 14; j < czas; j++) {
        //unsigned long long result = get_dist(j, czas-j);
       
	long long before = lowest;//known_outputs.size();

	

	for (int i = 1; i < czas-j; i++) {
		cout << record - (j * i) << endl;
		if (record - (j * i) < 0) {

		    cout << record << " - (" << j << " * (" << czas << " - " << j << ")) = " << record - (j * (czas-j)) << endl;

        	    new_records++;
		    if (record - (j * i) < lowest) {
			lowest = record - (j * i);
		    }
		    //known_outputs.insert(record - (j * i));
		    break;
	        }
	}

	if (before == lowest/*known_outputs.size() && before > 0*/) {
		new_records *= 2;
		break;
	}
    }
   
    cout << new_records-1 << endl;
}

int main()
{
    test();
    //test(45977295, 305106211101695);

    return 0;
}
