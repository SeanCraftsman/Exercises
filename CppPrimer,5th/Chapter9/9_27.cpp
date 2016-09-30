#include <iostream>
#include <forward_list>
using namespace std;

void removeOdds(forward_list<int> &lst){
    auto prev = lst.before_begin();
    auto curr = lst.begin();
    while( curr != lst.end()){
        if(*curr % 2){
            curr = lst.erase_after(prev);
        }
        else{
            prev = curr;
            ++curr;
        }
    }
}

int main(){
    forward_list<int> lst = {0, 1, 2, 3, 4, 5};
    removeOdds(lst);
    for( auto item : lst){
        cout << item << " ";
    }
    return 0;
}
