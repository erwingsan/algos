// Example program
#include <iostream>
#include <string>

using namespace std;

void reverseWords(string &s);

int mainR() {

//get strings

	string str;

	cout << "Enter string: ";
	getline(cin, str);
	cout << str << endl;

	reverseWords(str);

	cout << "Res: " << str;
    
    return 0;

}

void reverseWords(string &s) {

	string res;
	int len=0;

	for(int i=s.size()-1; i>=0; --i){
		if(s[i] == ' ' || i==0){
			int st = i==0? i:i+1;
			len = i==0? len+1:len;
			string add = s.substr(st,len);
			add = i==0? add:add+' ';
			res += add;;
			len=0;
		}
		else{
			len++;
		}
	}

	s = res;

}
