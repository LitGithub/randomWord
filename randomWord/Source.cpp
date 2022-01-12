#include <sstream>
#include <iostream>
#include <random>
using namespace std;

int main() {
	string start[] = { "Dr", "Dw", "L", "M", "Qu", "Thr", "Tr", "Tw", "Scr", "Sl", "Sm", "Sp", "Spl", "Squ", "Wh", "Y", "B", "F", "G", "P" };
	string middle[] = { "l", "w", "r", "" };
	string vowels[] = { "a", "e", "i", "o", "u", "ee", "aa"};
	string secondLast[] = {"bb", "ck", "dd", "mf", "mp", "mpf", "ng", "nk", "pp", "rf", "rk", "rp", "zz"};
	string last[] = {"aldo", "et", "et", "le", "le", "le", "a", "ok"};
	string shortLast[] = { "b", "d", "f", "m", "mp", "ng", "nk", "p", "rf", "rk", "rp", "x", "zz" };
	stringstream SS;

	srand(time(NULL));
	int shortCounter = 0;
	int shortString = rand() % 1;
	for (int i = 0; i < 100; i++) {
		if (shortString == 0) {
			
			int startrand = rand() % sizeof(start) / sizeof(start[0]);
			int middlerand = rand() % sizeof(middle) / sizeof(middle[0]);
			int vowelrand = rand() % sizeof(vowels) / sizeof(vowels[0]);
			int seclastrand = rand() % sizeof(secondLast) / sizeof(secondLast[0]);
			int lastrand = rand() % sizeof(last) / sizeof(last[0]);
			string startString = start[startrand];
			string middleString = middle[middlerand];
			string vowelString = vowels[vowelrand];
			string sLString = secondLast[seclastrand];
			string lastString = last[lastrand];
			char startEndLetter = start[startrand][sizeof(start[startrand]) / sizeof(start[startrand])];
			char endStartLetter = lastString[0];
			if (startEndLetter == endStartLetter)
				lastString.erase(0, 1);
			if (startEndLetter == 'u' && middleString == "" && vowelString[0] == 'u')
				vowelString.erase(0, 1);
			SS << startString << middleString << vowelString << sLString << lastString;
			shortCounter = 0;
		}
		else {
			//SS.str("");

			int startrand = rand() % sizeof(start) / sizeof(start[0]);
			int vowelrand = rand() % sizeof(vowels) / sizeof(vowels[0]);
			int shortlast = rand() % sizeof(shortLast) / sizeof(shortLast[0]);
			string startString = start[startrand];
			string vowelString = vowels[vowelrand];
			string shortStringlast = shortLast[shortlast];
			if (shortCounter == 0) {
				SS << startString << vowelString << shortStringlast << "-";
				shortCounter++;
			}
			else {
				SS << startString << vowelString << shortStringlast;
				shortCounter = 0;
			}
		}

		cout << SS.str();
		if(shortCounter == 0) 
		cout << endl;
		SS.str("");
		if (shortCounter != 2)
		shortString = rand() % 2;
	}
}