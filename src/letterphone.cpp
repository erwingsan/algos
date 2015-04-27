#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {

//        char letters[][] = {{'0', '0', '0', '0'},
//                            {'0', '0', '0', '0'},
//                            {'a', 'b', 'c', '0'},
//                            {'d', 'e', 'f', '0'},
//                            {'g', 'h', 'i'. '0'},
//                            {'j', 'k', 'l', '0'},
//                            {'m', 'n', 'o', '0'},
//                            {'p', 'q', 'r', 's'},
//                            {'t', 'u', 'v', '0'},
//                            {'w', 'x', 'y', 'z'}};


//        vector<string> total;
//        total.push_back("");
//
//        for(int i = 0; i < digits.size(); ++i){
//
//            vector<string> copy1(total);
//            vector<string> copy2(total);
//            vector<string> copy3;
//
//            int current_digit = digits[i] - '0';
//            if(current_digit == 7 || current_digit == 9){
//                copy(copy3.end(), total.begin(), total.end());
//            }
//
//            for(int j = 0; j < total.size(); ++j){
//                total[j] += letter[current_digit-'0'][0];
//                copy1[j] += letter[current_digit-'0'][1];
//                copy2[j] += letter[current_digit-'0'][2];
//                if(current_digit == 7 || current_digit == 9){
//                copy3[j] += letter[current_digit-'0'][3];
//                }
//            }
//
//            total.insert(total.end(), copy1.begin(), copy1.end());
//            total.insert(total.end(), copy2.begin(), copy2.end());
//            if(current_digit == 7 || current_digit == 9){
//                total.insert(total.end(), copy3.begin(), copy3.end());
//            }
//        }
//
//        return total;
//

    }
};
