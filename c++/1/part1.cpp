#include <iostream>
#include <fstream>
#include <cctype>

using std::string;
using std::cout;
using std::ifstream;
using std::cerr;
using std::getline;
using std::endl;
using std::isdigit;
using std::stoi;

char get_first_number(string text) {
	for (int i = 0; i < text.length(); i++) {
		if (isdigit(text[i])) {
			return text[i];
		}
	}

	return '0';
}

char get_last_number(string text) {
	for (int i = text.length()-1; i >= 0; i--) {
		if (isdigit(text[i])) {
			return text[i];
		}
	}

	return '0';
}

int main() {
	ifstream file("input.txt");	

	if (!file.is_open()) {
		cerr << "No file: input.txt\n";
		return 1;
	}

	string text;

	int sum = 0;

	while (getline(file, text)) {
		string line = string(1, get_first_number(text)) + string(1, get_last_number(text));
		
		sum += stoi(line);
	}

	cout << sum << endl;
	
	file.close();

	return 0;
}
