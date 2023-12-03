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
	ifstream file("input.txt");

	if (!file.is_open()) {
		// No file XD
		return 1;
	}

	int sum = 0;

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

	string line = "";
	

	while (getline(file, line)) {
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

		for (int i = 5; i < line.length(); i++) {
			if (skip) {
				skip = false;
				continue;
			}

			if (line[i] == ':') {
				skip = true;
				game_id = stoi(buffer);
				buffer = "";
			} else if (line[i] == ' ') {
				balls_num = stoi(buffer);
				buffer = "";
			} else if (line[i] == ',' || line[i] == ';') {
				skip = true;

				if (balls_num > game_vals[buffer]) {
					game_vals[buffer] = balls_num;
				}

				buffer = "";
			} else {
				buffer.push_back(line[i]);
			}
		}

		if (balls_num > game_vals[buffer]) {
			game_vals[buffer] = balls_num;
		}

		sum += game_vals["red"] * game_vals["green"] * game_vals["blue"];
	}

	cout << sum << endl;

	file.close();

	return 0;
}
