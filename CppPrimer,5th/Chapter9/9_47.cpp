#include <iostream>
#include <string>

using namespace std;

int main(){
    string numbers("0123456789");
    string alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    string str("ab2c3d7R4E6");

    cout << "numberic charaters: ";
    for(int pos = 0;(pos = str.find_first_of(numbers, pos) )!= string::npos; ++pos){
        cout << str[pos] << " ";
    }
    cout << "\nalphabetic charaters: ";
    for(int pos = 0;(pos = str.find_first_not_of(numbers, pos)) != string::npos; ++pos){
        cout << str[pos] << " ";
    }
    return 0;
}
