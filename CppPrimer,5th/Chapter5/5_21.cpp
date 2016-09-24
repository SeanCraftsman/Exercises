#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    string lastStr="";
    bool flag = false;
    while(cin >> str){
        if(str == lastStr && isupper(str[0])){
            flag = true;
            break;
        }
        lastStr = str;
    }
    if(flag){
        cout << str << endl;
    }
    else{
        cout << "There is no repeat word." << endl;
    }
}
