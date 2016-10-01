#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> map;
        for(auto c: magazine){
            map[c] ++;
        }
        for(auto c: ransomNote){
            if(map.find(c) != map.end() && map[c] > 0){
                map[c] --;
            }
            else{
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    cout << s.canConstruct("a","b") << endl;
    cout << s.canConstruct("aa","ab") << endl;
    cout << s.canConstruct("aa","aab") << endl;
}
