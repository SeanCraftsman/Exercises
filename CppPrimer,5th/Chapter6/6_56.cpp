#include <iostream>
#include <vector>
using namespace std;

typedef int (*FuncP)(int,int);
typedef int Func(int, int);

int add(int a, int b){
    return a+b;
}
int substract(int a, int b){
    return a-b;
}
int multiply(int a, int b){
    return a*b;
}
int divide(int a, int b){
    return a/b;
}
int main(){
    vector<int (*)(int, int)> vec = {add, substract, multiply, divide};
    vector<FuncP> vec2;
    int a = 3, b = 4;
    for(auto fun: vec){
        cout << fun(a,b) << endl;
    }
    return 0;
}
