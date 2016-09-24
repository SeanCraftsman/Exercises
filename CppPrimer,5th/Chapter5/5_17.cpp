#include <iostream>
#include <vector>
using namespace std;

bool isPrefix(vector<int> a, vector<int> b){
    if(a.size() > b.size()){
        vector<int> temp;
        temp = a;
        a = b;
        b = temp;
    }
    for(int i=0; i < a.size(); i++){
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}

int main(){
    vector<int> vec1 = {0,1,1,2};
    vector<int> vec2 = {0,1,1,2,3,5,8};
    cout << isPrefix(vec1, vec2) << endl;
}
