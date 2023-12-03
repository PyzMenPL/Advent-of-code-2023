#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cctype>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::isdigit;

class Solve {
private:
	int sum = 0;
	vector<string> file;
	
	void main() {
		for (int i = 0; i < file.size(); i++) {
			for (int j = 0; j < file[i].length(); j++) {
				if (file[i][j] == '*') {
					find_numbers_around(i, j);
				}
			}
		}
	}

	void find_numbers_around(int i, int j) {
		std::set<int> digits_found;

		for (int height = -1; height < 2; height++) {
			if (i <= 0 || i + height >= file.size()) {
				continue;
			}

			int shift = j-1;

			if (j == 0) {
				shift++;
			}

			for (; shift < j+2; shift++) {
				if (isdigit(file[i+height][shift])) {
					digits_found.insert(get_number_from(i+height, shift));
				}
			}

		}

		if (digits_found.size() == 2) {
			int m = 1;
			for (int digit : digits_found) {
				m *= digit;
			}
			sum += m;	
		}
	}

	int get_number_from(int i, int j) {
		string number = "";
		number.push_back(file[i][j]);

		for (int go_left = 0; go_left < 2; go_left++) {
			int shift = 1;

			if (go_left) {
				shift = -1;
			}

			if (j + shift < 0 || j + shift >= file[i].length()) {
				continue;
			}

			while (isdigit(file[i][j+shift])) {
				if (go_left) {
					number = file[i][j+shift] + number;
				} else {
					number.push_back(file[i][j+shift]);
				}

				if (go_left) {
					shift--;
				} else {
					shift++;
				}

				if (j + shift < 0 || j + shift >= file[i].length()) {
					break;
				}
			}

		}

		return std::stoi(number);
	}

public:
	Solve() {
		std::ifstream input("input.txt");
		string line;

		while (std::getline(input, line)) {
			file.push_back(line);
		}

		input.close();
		main();
		cout << sum << endl;	
	}	
};

int main() {
	Solve();

	return 0;
}
