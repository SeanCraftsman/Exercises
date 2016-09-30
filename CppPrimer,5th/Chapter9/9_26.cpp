#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main(){
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> ivec(ia,end(ia));
    list<int> ilst(ia,end(ia));
    for(auto it = ilst.begin(); it != ilst.end(); ){
        if(*it % 2)
            it = ilst.erase(it);
        else
            ++it;
    }
    for(auto it = ivec.begin(); it != ivec.end(); ){
        if(*it % 2 == 0)
            it = ivec.erase(it);
        else
            ++it;
    }

    cout << "list : ";
    for(auto i : ilst)   cout << i << " ";
    cout << "\nvector : ";
    for(auto i : ivec)   cout << i << " ";
    cout << std::endl;
}
