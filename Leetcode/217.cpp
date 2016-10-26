class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> iset;
        for(auto i: nums){
            if(iset.find(i) == iset.end()){
                iset.insert(i);
            }
            else{
                return true;
            }
        }
        return false;
    }
};
