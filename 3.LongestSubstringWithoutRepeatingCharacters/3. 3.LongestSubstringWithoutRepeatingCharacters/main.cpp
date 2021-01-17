#include <iostream>
#include <exception>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
        map<char, int> dataBase = {{'\0', -1}};
        
        int currentMax = 0;
        int buffer = -1;
        
        for(int i = 0; i < s.size(); ++i) {
            try {
                int lastAppearance = dataBase.at(s[i]);
                dataBase[s[i]] = i;
                buffer = max(buffer, lastAppearance);
                currentMax = max(currentMax, i - buffer);
            } catch (std::out_of_range& ex) {
                dataBase[s[i]] = i;
                currentMax = max(currentMax, i - buffer);
            }
        }
        return currentMax;
    }

int main() {
    string a = "abca";
    string b = "bbb";
    string c = "drdr";
    
    cout << lengthOfLongestSubstring(a) << endl;
    cout << lengthOfLongestSubstring(b) << endl;
    cout << lengthOfLongestSubstring(c) << endl;
    
    return 0;
}
