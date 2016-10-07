#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size()<2) return s.size();
        map<char,int> imap;
        for(auto i:s){
            imap[i]++;
        }
        int cnt = 0;
        for(auto it = imap.begin(); it != imap.end(); ++it){
            if(it->second >=2){
                cnt += it->second % 2 ? it->second-1: it->second;
            }
        }
        if(cnt < s.size())
            cnt += 1;
        return cnt;
    }
};


int main(){
    Solution s;
    cout << s.longestPalindrome("abccccdd") << endl;
}
