#include <iostream>
#include <fstream>
#include <cctype>
#include <map>
#include <algorithm>

using std::string;
using std::cout;
using std::ifstream;
using std::cerr;
using std::getline;
using std::endl;
using std::isdigit;
using std::stoi;
using std::map;
using std::pair;
using std::reverse;

const map<string, string> numbers = {
	{"one", "1"}, 
	{"two", "2"},
	{"three", "3"},
	{"four", "4"},
	{"five", "5"},
	{"six", "6"},
	{"seven", "7"},
	{"eight", "8"},
	{"nine", "9"}
};

string get_numbers_from(string text, bool rev=false) {
	for (int i = 0; i < text.length(); i++) {
		for (pair<string, string> p : numbers) {
			if (i + p.first.length() < text.length()) {
				pair<string, string> tmp = p;
				if (rev) {
					reverse(tmp.first.begin(), tmp.first.end());
				}
				
				if (text.substr(i, tmp.first.length()) == tmp.first) {
					text.replace(i, tmp.first.length(), tmp.second);
				}
			}
		}
	}

	if (rev) {
		reverse(text.begin(), text.end());
	}

	return text;
}

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
	string rev_text;

	int sum = 0;

	while (file >> text) {
		rev_text = text;
		reverse(rev_text.begin(), rev_text.end());

		string line = string(1, get_first_number(get_numbers_from(text))) + string(1, get_last_number(get_numbers_from(rev_text, true)));

		sum += stoi(line);
	}

	cout << sum << endl;
	
	file.close();

	return 0;
}
