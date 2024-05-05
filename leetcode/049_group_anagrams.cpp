#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>


class Solution {
public:
  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    /*Pass through each string;
    for each string sort it by chars
    and use this as a key to an unordered_map,
    where the value is a vector,
    and push the value to it;
    then return only the values of the map*/
    std::unordered_map<std::string, std::vector<std::string>> mapOfAnagrams {};
    for(auto& str : strs) {
      std::string word = str;
      std::sort(word.begin(), word.end());
      mapOfAnagrams[word].push_back(str);
    }

    std::vector<std::vector<std::string>> result {};
    for (auto const& [key, val] : mapOfAnagrams) {
      result.push_back(val);
    }

    return result;
  }
};


int main() {
  Solution mySol;
  std::vector<std::string> myStrs {"eat","tea","tan","ate","nat","bat"};
  std::vector<std::vector<std::string>> result = mySol.groupAnagrams(myStrs);
  for (auto& xs : result) {
    for (auto& x : xs) {
      std::cout << x << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}