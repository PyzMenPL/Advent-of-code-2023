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

string get_numbers_from(string tekst, bool rev=false) {
	for (int i = 0; i < tekst.length(); i++) {
		for (pair<string, string> para : numbers) {
			if (i + para.first.length() < tekst.length()) {
				pair<string, string> tmp = para;
				if (rev) {
					reverse(tmp.first.begin(), tmp.first.end());
				}
				
				if (tekst.substr(i, tmp.first.length()) == tmp.first) {
					tekst.replace(i, tmp.first.length(), tmp.second);
				}
			}
		}
	}

	if (rev) {
		reverse(tekst.begin(), tekst.end());
	}

	return tekst;
}

char get_first_number(string tekst) {
	for (int i = 0; i < tekst.length(); i++) {
		if (isdigit(tekst[i])) {
			return tekst[i];
		}
	}

	return '0';
}

char get_last_number(string tekst) {
	for (int i = tekst.length()-1; i >= 0; i--) {
		if (isdigit(tekst[i])) {
			return tekst[i];
		}
	}

	return '0';
}

int main() {
	ifstream plik("input.txt");	

	if (!plik.is_open()) {
		cerr << "Nie można otworzyć pliku: input.txt\n";
		return 1;
	}

	string tekst;
	string rev_tekst;

	int suma = 0;

	while (plik >> tekst/*getline(plik, tekst)*/) {
		rev_tekst = tekst;
		reverse(rev_tekst.begin(), rev_tekst.end());

		string line = string(1, get_first_number(get_numbers_from(tekst))) + string(1, get_last_number(get_numbers_from(rev_tekst, true)));

		suma += stoi(line);
	}

	cout << suma << endl;
	
	plik.close();

	return 0;
}
