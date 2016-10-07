#include <iostream>
#include <vector>
#include <memory>
using namespace std;

shared_ptr<vector<int>> makeAVector(){
    return  make_shared<vector<int>>();
}

istream& input(istream &is,shared_ptr<vector<int>> pvi){
    for(int temp; is >> temp; pvi->push_back(temp));
    return  is;
}

ostream& output(ostream &os,shared_ptr<vector<int>> pvi){
    for(auto i: *pvi){
        os << i << " ";
    }
    return os;
}

int main(){
    shared_ptr<vector<int>> pvi = makeAVector();
    input(cin, pvi);
    output(cout, pvi) << endl;
    return 0;
}

