#include <iostream>
using namespace std;

void swapTwoInt(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
    int a=1,b=3;
    swapTwoInt(a,b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}

