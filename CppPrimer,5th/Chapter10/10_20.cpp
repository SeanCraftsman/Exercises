#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<string> v{"alan","moophy","1234567","1234567","1234567","1234567"};
    cout << count_if(v.begin(),v.end(),[](string v){return v.size()>6;}) << endl;
    return 0;
}
