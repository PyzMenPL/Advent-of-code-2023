#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::getline;
using std::vector;
using std::unordered_map;

int main() {
	string directions = "";
	ifstream file("input.txt");
	string line;
	unordered_map<string, vector<string>> nodes;

	while (getline(file, line)) {
		if (directions == "") {
			directions = line;
		} else if (line != "") {
			string buffer = "";
			bool skip = false;
			string name = "";
			string left = "";
			for (int i = 0; i < line.length(); i++) {

				if (skip) {
					skip = false;
					continue;
				}

				if (line[i] == ' ' || line[i] == ',' || line[i] == ')') {
					skip = true;

					if (name == "") {
						name = buffer;
					} else if (left == "") {
						left = buffer;
					} else {
						nodes[name] = vector<string>{left, buffer};
					}

					buffer = "";
					continue;
				}

				buffer.push_back(line[i]);
			}
		}
	}

	string current_node = "AAA";
	int sum = 0;

	while (current_node != "ZZZ") {
		for (int i = 0; i < directions.length(); i++) {
			sum++;

			if (directions[i] == 'R') {
				current_node = nodes[current_node][1];
			} else {
				current_node = nodes[current_node][0];
			}
		}
	}

	cout << sum << endl;

	return 0;
}
