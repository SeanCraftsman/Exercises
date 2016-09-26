#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string toHex(unsigned int num) {
        if(!num) return "0";
        string ans;
        while(num){
            int ms = num & 15;
            if( ms < 10 )
                ans.push_back('0'+ms);
            else{
                ans.push_back('a'+ms-10);
            }
            num = num >> 4;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.toHex(-1) << endl;
    return 0;
}
