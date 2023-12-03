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
	int suma = 0;
	vector<string> plik;
	
	void main() {
		for (int i = 0; i < plik.size(); i++) {
			for (int j = 0; j < plik[i].length(); j++) {
				if (!isdigit(plik[i][j]) && plik[i][j] != '.') {
					find_numbers_around(i, j);
				}
			}
		}
	}

	void find_numbers_around(int i, int j) {
		for (int height = -1; height < 2; height++) {
			if (i <= 0 || i + height >= plik.size()) {
				continue;
			}

			std::set<int> digits_found;

			int shift = j-1;

			if (j == 0) {
				shift++;
			}

			for (; shift < j+2; shift++) {
				if (isdigit(plik[i+height][shift])) {
					digits_found.insert(get_number_from(i+height, shift));
				}
			}

			for (int digit : digits_found) {
				suma += digit;
			}

		}	
	}

	int get_number_from(int i, int j) {
		string number = "";
		number.push_back(plik[i][j]);

		for (int go_left = 0; go_left < 2; go_left++) {
			int shift = 1;

			if (go_left) {
				shift = -1;
			}

			if (j + shift < 0 || j + shift >= plik[i].length()) {
				continue;
			}

			while (isdigit(plik[i][j+shift])) {
				if (go_left) {
					number = plik[i][j+shift] + number;
				} else {
					number.push_back(plik[i][j+shift]);
				}

				if (go_left) {
					shift--;
				} else {
					shift++;
				}

				if (j + shift < 0 || j + shift >= plik[i].length()) {
					break;
				}
			}

		}

		return std::stoi(number);
	}

public:
	Solve() {
		std::ifstream input("input.txt");
		string linijka;

		while (std::getline(input, linijka)) {
			plik.push_back(linijka);
		}

		input.close();
		main();
		cout << suma << endl;	
	}	
};

int main() {
	Solve();

	return 0;
}
