#include <iostream>
#include <deque>
#include <list>
using namespace std;

int main(){
    list<int> lst{1, 2, 3, 4, 5, 6};
    deque<int> odd,even;
    for(auto item: lst){
        (item % 2 ? odd:even).push_back(item);
    }
    for(auto item: odd) cout<<item<<" ";
    cout << endl;
    for(auto item: even) cout<<item<<" ";
    cout << endl;
    return 0;
}
