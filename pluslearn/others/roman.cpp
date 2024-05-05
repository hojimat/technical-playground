#include <iostream>
#include <string>
using std::cout, std::endl, std::string;


class Solution {
public:
    int romanToInt(string s) {
        int decimal = 0;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == 'I') {
                decimal += 1;
            }else if(s[i]=='V') {
                decimal += 5;
            }else if(s[i]=='X') {
                decimal += 10;
            }else if(s[i]=='L') {
                decimal += 50;
            }else if(s[i]=='C') {
                decimal += 100;
            }else if(s[i]=='D') {
                decimal += 500;
            }else if(s[i]=='M') {
                decimal += 1000;
            }

        }
        cout << decimal << endl;
        return decimal;
        }
};

int main(){
    cout << "Calling the Solution..." << endl;
    Solution mysol; // create an instance
    mysol.romanToInt("XLVI"); // call the function
    cout << "Ending the program..." << endl << "Done.";
    
    return 0;
}
