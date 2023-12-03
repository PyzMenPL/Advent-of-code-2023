#include <iostream>
#include <fstream>
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::stoi;
using std::getline;
using std::ifstream;
using std::unordered_map;

int main() {
	ifstream plik("input.txt");

	if (!plik.is_open()) {
		// Nie ma pliku XD
		return 1;
	}

	int suma = 0;

	int game_id = 1;
	int balls_num = 0;
	bool skip = false;
	bool aborted = false;
	string buffer = "";
	unordered_map<string, int> game_vals = {
		{"red", 12},
		{"green", 13}, 
		{"blue", 14}
	};

	string linijka = "";
	

	while (getline(plik, linijka)) {
		game_id = 1;
		balls_num = 0;
		skip = false;
		aborted = false;
		buffer = "";
		game_vals = {
			{"red", 12},
			{"green", 13}, 
			{"blue", 14}
		};

		for (int i = 5; i < linijka.length(); i++) {
			if (skip) {
				skip = false;
				continue;
			}

			if (linijka[i] == ':') {
				skip = true;
				game_id = stoi(buffer);
				buffer = "";
			} else if (linijka[i] == ' ') {
				balls_num = stoi(buffer);
				buffer = "";
			} else if (linijka[i] == ',' || linijka[i] == ';') {
				skip = true;

				if (balls_num > game_vals[buffer]) {
					aborted = true;
					break;
				}
				buffer = "";
			} else {
				buffer.push_back(linijka[i]);
			}
		}

		if (balls_num > game_vals[buffer]) {
			aborted = true;
		}
		
		if (!aborted) {
			suma += game_id;
		}
	}

	cout << suma << endl;

	plik.close();

	return 0;
}
