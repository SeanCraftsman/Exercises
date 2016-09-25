#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> vec(nums.size());
        int num=1;
        for(int i=0; i < nums.size(); i++){
            vec[i] = num;
            num *= nums[i];
        }
        num = 1;
        for(int i=nums.size()-1; i >= 0; i--){
            vec[i] = vec[i] * num;
            num *= nums[i];
        }
        return vec;
    }
};

int main(){
    vector<int> vec = {1,2,3,4};
    Solution s;
    vector<int> ans = s.productExceptSelf(vec);
    for(auto num : ans){
        cout << num << " ";
    }
    return 0;
}
