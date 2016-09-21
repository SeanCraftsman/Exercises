#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target){
    vector<int> vec;
    for(auto it=numbers.begin(); it != numbers.end(); ++it ){
        if(binary_search(it,numbers.end(),target-*it)){
            vec.push_back(it-numbers.begin()+1);
            vec.push_back(lower_bound(it,numbers.end(),target-*it)-numbers.begin()+1);
            return vec;
        }
    }
    return vec;
}

int main(){
    vector<int> num = {2, 3, 4};
    vector<int> answer;
    int target = 6;
    answer = twoSum(num, target);
    cout << answer[0] << " " << answer[1]<< endl;
    return 0;
}
