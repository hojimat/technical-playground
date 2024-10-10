#include <iostream>
#include <array>


class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        int m = s1.size();
        int n = s2.size();
        if (m > n) {
            return false;
        }
        std::array<int, 26> s1Letters = countLetters(s1);
        for(auto& let : s1Letters) {
            std::cout << let << ", "; 
        }
        std::cout << "////\n";
        std::array<int, 26> s2Letters = countLetters(s2.substr(0,m));

        int l = 0;
        int r = m-1;
        while(r < n-1){
            for(auto& let : s2Letters) {
                std::cout << let << ", "; 
            }
            std::cout << std::endl;
            

            if (s1Letters==s2Letters) {
                return true;
            }

            s2Letters[s2[l]-'a']--;
            l++;
            r++;
            s2Letters[s2[r]-'a']++;
        }

        if (s1Letters==s2Letters) {
            return true;
        }

        return false;
    }

private:
    std::array<int, 26> countLetters(std::string s) {
        std::array<int, 26> counts {0};

        for(const char& c : s) {
            counts[c-'a']++;
        }

        return counts;
    }
};


int main() {
    std::string s1 = "adc";
    std::string s2 = "dcda";

    bool ret = Solution().checkInclusion(s1, s2);
    std::cout << "Answer is: " << ret << std::endl;

    return 0;
}
