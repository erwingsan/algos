// Example program
#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s);

int mainlp() {

//get strings

	string str;

	cout << "Enter string: ";
	getline(cin, str);

	cout << longestPalindrome(str);

	return 0;
}

string longestPalindrome(string s) {

	int len = 0;
	string wpal;

	for (int i = 0; i < s.size(); ++i) {
		for (int j = i; j < s.size(); ++j) {
			int st = i;
			int fin = j;
			while (s[st] == s[fin] && fin >= st) {
				st++;
				--fin;
			}
			if (fin <= st && len <= j - i + 1) { // found
				len = len <= j - i + 1 ? j - i + 1 : len;
				wpal = len <= j - i + 1 ? s.substr(i, j - i + 1) : wpal;

				cout << len << " " << i << " " << j << " " << wpal << endl;
			}
		}
	}

	return wpal;

}
