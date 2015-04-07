// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string multiply(string num1, string num2);

int mainM() {

//get strings

	string num1;
	string num2;

	cout << "Enter 1st string: ";
	cin >> num1;

	cout << "Enter 2nd string: ";
	cin >> num2;

	string res = multiply(num1, num2);

	cout << "Res: " << res;


}


string multiply(string num1, string num2) {
        string result;

        //init
        for(int i=0; i<num1.size()+num2.size(); ++i)
            result = result + '0';

        int carry = 0;

        // mult
        int lim1 = num1.size()-1;
        int lim2 = num2.size()-1;
        for(int i=lim1; i>=0; --i){
            for(int j=lim2; j>=0; --j) {
            	//cout << " ij" << i << j << "ni"<<num1[i]<< "nj"<<num2[j];
                int pos = result.size()-1 - (lim1-i + lim2-j);
                //cout <<  result.size()-1 << " " << lim1-i << " " << lim2-j;
                int partres = (num1[i] - '0')*(num2[j] - '0') + carry + (result[pos] - '0');
                cout << " pos"<< pos << "pr"<< partres;
                carry = partres/10;
                partres = partres%10;
                cout << "c" << carry << "pm" << partres;
                result[pos] = partres + '0';
           }
           if(carry){
        	   int cpos = result.size() - lim2 - lim1 +i -2;
               result[cpos] = carry + '0';
               //cout << " lastcarrypos " << cpos << " Value " << carry;
               carry = 0;
           }

        }

        //remove 0's
        while(result[0] == '0' && result.size() > 1)
        	result.erase(0,1);

        return result;
}
