class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> imap;
        for(auto c:s){
            imap[c]++;
        }
        for(int i=0; i < s.size(); i++){
            if(imap[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};
