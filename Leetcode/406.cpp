#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
using std::list;
using std::vector;
using std::pair;


class Solution {
public:
    static bool comp(const pair<int,int> &a, const pair<int,int>&b){
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(),people.end(), Solution::comp);
        vector<pair<int, int>> vec;
        int temp;
        for(auto &item : people){
            auto it = vec.begin();
            temp = item.second;
            while(temp--){
                ++it;
            }
            vec.insert(it, item);
        }
        return vec;
    }
};


int main(){
    Solution s;
    vector<pair<int, int>> people={{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    vector<pair<int, int>> ans;
    ans = s.reconstructQueue(people);
    for(auto i: ans){
        std::cout << i.first << " " << i.second << std::endl;
    }
    return 0;
}
