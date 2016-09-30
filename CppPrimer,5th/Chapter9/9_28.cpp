#include <iostream>
#include <string>
#include <forward_list>
using namespace std;

void findAndInsert(forward_list<string> &flst, string toFind, string toAdd){
    auto prev = flst.before_begin();
    for(auto curr = flst.begin(); curr != flst.end(); prev = curr++){
        if(*curr == toFind){
            flst.insert_after(curr, toAdd);
            return;
        }
    }
    flst.insert_after(prev, toAdd);
}

int main(){
    forward_list<string> flst = {"hello","this is","a string","how"};
    string str = "hello";
    findAndInsert(flst, str, "world");
    for(auto item: flst){
        cout << item << endl;
    }
    return 0;
}
