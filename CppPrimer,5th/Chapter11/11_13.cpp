#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;
int main(){
    vector<pair<string, int>> vec;
    string str;
    int i;
    while(cin >> str >> i){ // four ways to make a pair
        vec.push_back(pair<string,int>(str,i));
        vec.push_back(make_pair(str, i));
        vec.push_back({str, i});
        vec.emplace_back(str, i);
    }
    for(auto &p : vec){
        cout << p.first <<" " << p.second << endl;
    }
    return 0;
}
