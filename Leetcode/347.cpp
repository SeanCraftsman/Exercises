#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


bool comp(const pair<int, int> &a, const pair<int, int> &b){
    return a.second > b.second;
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> imap;
        for( auto num: nums){
            imap[num]++;
        }
        vector<pair<int, int>> temp;
        for(auto p:imap){
            temp.push_back(p);
        }
        sort(temp.begin(),temp.end(),comp);
        vector<int> ans;
        for(auto it=temp.begin(); it != temp.end() && it!= temp.begin()+k; ++it){
            ans.push_back(it->first);
        }
        return ans;
    }
};

int main(){
    vector<int> ivec = {1,1,1,2,2,3};
    Solution s;
    vector<int> ans = s.topKFrequent(ivec,2);
    for(auto i:ans){
        cout << i << " " ;
    }
    return 0;
}
