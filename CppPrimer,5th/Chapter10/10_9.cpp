#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
std::ostream& printVec(std::ostream &output,vector<string> &svec){
    for(auto str: svec){
        output << str << " ";
    }
    return output;
}

void elimDups(vector<string> &svec){
    sort(svec.begin(), svec.end());
    printVec(cout, svec)<<endl;
    auto end_unique = unique(svec.begin(),svec.end());
    printVec(cout, svec)<<endl;
    svec.erase(end_unique, svec.end());
}


int main(){
    vector<string> svec{"fox", "jump", "quick", "over","slow", "red", "turtle", "the", "red", "the" };
    printVec(cout,svec) << endl;
    elimDups(svec);
    printVec(cout,svec) << endl;
}
