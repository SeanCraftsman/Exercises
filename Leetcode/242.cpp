class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char, int> imap;
        for(auto c:s){
            imap[c] ++;
        }
        for(auto c:t){
            if(imap.find(c) != imap.end() && imap[c] > 0){
                imap[c] --;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
