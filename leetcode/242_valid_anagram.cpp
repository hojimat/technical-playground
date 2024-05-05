#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
      if (s.length() != t.length()) {
        return false;
      }

      std::unordered_map<char, int> sLetters {};
      for(int i=0; i<s.length(); i++) {
        if(sLetters.find(s[i])==sLetters.end()) {
          sLetters[s[i]] = 1;
        } else {
          sLetters[s[i]] += 1;
        }
      }

      std::unordered_map<char, int> tLetters {};
      for(int i=0; i<t.length(); i++) {
        if(tLetters.find(t[i])==tLetters.end()) {
          tLetters[t[i]] = 1;
        } else {
          tLetters[t[i]] += 1;
        }
      }

      return sLetters==tLetters;
    }
};


int main() {
  Solution mySol;
  std::string myS = "contemporaryart";
  std::string myT = "anymoreprotract";

  bool result = mySol.isAnagram(myS, myT);
  std::cout << result;
  return 0;
}