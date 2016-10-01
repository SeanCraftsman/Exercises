class Solution {
public:
    string convertToTitle(int n) {
        string title="";
        while(n--){
            title.push_back(n%26+'A');
            n /= 26;
        }
        reverse(title.begin(),title.end());
        return title;
    }
};
