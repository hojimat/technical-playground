#include <iostream>
#include <vector>
#include <map>
#include <string>


int main() {
    std::vector<int> values = {1,2,3,4,5,6,7};

    for(int i=0; i<values.size(); i++) {
        std::cout << values[i] << " ";
    }


    for(int value : values) {
        std::cout << value << " ";
    }


    for(std::vector<int>::iterator it = values.begin(); it != values.end(); it++) {
        std::cout << *it << " ";
    }


    std::cout << "\n\n\n\n";



    std::map<std::string, int> codes;
    codes["Russia"] = 7;
    codes["Germany"] = 49;
    codes["Austria"] = 43;
    codes["USA"] = 1;


    for( std::map<std::string, int>::iterator it = codes.begin(); it != codes.end(); it++ ) {
        std::string mKey = it->first;
        int mVal = it->second;

        std::cout << mKey << ": " << mVal << "\n";
    }


    std::cout << "\n\n\n\n\n\n";

    for (auto [mKey,mVal] : codes) {
        std::cout << mKey << ": " << mVal << "\n";
    }


    return 0;
}
