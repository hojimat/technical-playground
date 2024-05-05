#include <iostream>
#include <vector>
#include <array>
#include <map>
#define print(x) std::cout << x << std::endl;


int main() {
    std::map<std::string, int> areaCodes;
    areaCodes["Russia"] = 7;
    areaCodes["Germany"] = 49;
    areaCodes["Austria"] = 43;
    areaCodes["Turkey"] = 90;

    for(auto it=areaCodes.begin(); it!=areaCodes.end(); it++) {
        print(it->first << ": " << it->second);
    }

    print("\nc++17");
    
    for(const auto& [k,v] : areaCodes) {
        print(k << ": " << v);
    }

}



/*
int main() {
    std::vector<int> numbers = {10,20,30,40,50,60,70};
    
    print("classic for loop")

    for(int i=0; i<numbers.size(); i++) {
        print(numbers[i]);
    }

    print("\nfor with iterator");

    for(auto it = numbers.begin(); it != numbers.end(); it++){
        print(*it);
    }

    print("\npython-style for");

    for(const auto &number : numbers) {
        print(number);
    }

    return 0;
}
*/
