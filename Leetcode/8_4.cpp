#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void readFileToVec(string fileName, vector<string>& vec){
    ifstream in(fileName);
    string buf;
    while(getline(in, buf)){
        vec.push_back(buf);
    }
}

int main(){
    vector<string> vec;
    readFileToVec("..\\message\\test.txt",vec);
    for(auto str: vec){
        cout << str << endl;
    }
    return 0;
}
