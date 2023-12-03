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

	int suma = 0;

	while (getline(plik, tekst)) {
		string line = string(1, get_first_number(tekst)) + string(1, get_last_number(tekst));
		
		suma += stoi(line);
	}

	cout << suma << endl;
	
	plik.close();

	return 0;
}
