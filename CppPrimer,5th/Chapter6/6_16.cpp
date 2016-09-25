#include <iostream>
#include <string>
using namespace std;

bool hasUppercaseChar(string s){
    for(auto c:s){
        if(isupper(c)){
            return true;
        }
    }
    return false;
}

string toUppercase(string &s){
    for(auto &c:s){
        c = toupper(c);
    }
    return s;
}

int main(){
    string s1 = "abcde";
    string s2 = "ssAdc";
    cout << hasUppercaseChar(s1) << endl;
    cout << hasUppercaseChar(s2) << endl;
    toUppercase(s1);
    cout << s1 << endl;
    cout << toUppercase(s2) << endl;
    return 0;
}
