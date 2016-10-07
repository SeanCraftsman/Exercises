#include <iostream>
#include <vector>
using namespace std;

vector<int>* makeAVector(){
    return new vector<int>;
}

istream& input(istream &is,vector<int>* pvi){
    for(int temp; is >> temp; pvi->push_back(temp));
    return  is;
}

ostream& output(ostream &os,vector<int>* pvi){
    for(auto i: *pvi){
        os << i << " ";
    }
    return os;
}

int main(){
    vector<int> *pvi = makeAVector();
    input(cin, pvi);
    output(cout, pvi) << endl;
    delete pvi;
    return 0;
}
