#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    string lastStr = "";
    string ans;
    int maxCnt = 0;
    int cnt = 0;
    while(cin >> str){
        if(str == lastStr){
            cnt ++;
            if(cnt > maxCnt){
                maxCnt = cnt;
                ans = str;
            }
        }
        lastStr = str;
    }
    if(maxCnt == 0){
        cout << "There is no repeat word." << endl;
    }
    else{
        cout << ans << " " << maxCnt << endl;
    }
    return 0;
}
