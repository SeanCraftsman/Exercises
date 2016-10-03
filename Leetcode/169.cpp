class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> imap;
        for(auto n : nums){
            imap[n] ++;
        }
        int major;
        for(auto it = imap.begin(); it != imap.end(); ++it){
            if(it->second*2 >= nums.size()){
                major = it->first;
                break;
            }
        }
        return major;
    }
};
