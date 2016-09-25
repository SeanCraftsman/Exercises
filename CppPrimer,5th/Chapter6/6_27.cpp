#include <iostream>
using namespace std;
int sum(initializer_list<int> lst){
    int sum = 0;
    for(auto it = lst.begin(); it != lst.end(); ++it){
        sum += *it;
    }
    return sum;
}

int main(){
    cout << sum({1,2,3,4,5,6}) << endl;
    return 0;
}
