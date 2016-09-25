#include <iostream>
#include <vector>
using namespace std;

void fact(vector<int> vec, int size){
    if(size > 0){
        fact(vec, size - 1);
        cout << " " << vec[size];
    }
    else{
        cout << vec[size];
    }
}

int main(){
    vector<int> vec={1,2,3,4,5,6,7};
    fact(vec,vec.size()-1);
    return 0;
}


