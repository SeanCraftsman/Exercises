#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool comp(const string &str){
    return str.size() >= 5;
}

int main(){
    vector<string> vec {"fox", "jump", "quick", "over","slow", "red", "turtle", "the", "red", "the"};
    auto iter = partition(vec.begin(), vec.end(), comp);
    for(auto it = vec.begin(); it != iter; ++it){
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
