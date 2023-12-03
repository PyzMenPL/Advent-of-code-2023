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
		{"red", 0},
		{"green", 0}, 
		{"blue", 0}
	};

	string linijka = "";
	

	while (getline(plik, linijka)) {
		game_id = 1;
		balls_num = 0;
		skip = false;
		aborted = false;
		buffer = "";
		game_vals = {
			{"red", 0},
			{"green", 0}, 
			{"blue", 0}
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
					game_vals[buffer] = balls_num;
				}

				buffer = "";
			} else {
				buffer.push_back(linijka[i]);
			}
		}

		if (balls_num > game_vals[buffer]) {
			game_vals[buffer] = balls_num;
		}

		suma += game_vals["red"] * game_vals["green"] * game_vals["blue"];
	}

	cout << suma << endl;

	plik.close();

	return 0;
}
