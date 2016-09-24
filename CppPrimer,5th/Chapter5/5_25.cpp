#include <iostream>
#include <stdexcept>
using namespace std;
int main(){
    int a, b;
    while(cin >> a >> b){
        try{
            if(b == 0){
                throw runtime_error("Divisor must not be zero!");
            }
            else{
                cout << a/b << endl;
                break;
            }
        } catch (runtime_error err){
            cout << err.what()
                 << "\nTry Again? Enter y or n"<< endl;
            char c;
            cin >> c;
            if(!cin || c == 'n'){
                break;
            }
        }
    }
    return 0;
}
