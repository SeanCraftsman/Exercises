#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
    ifstream in("../message/test.txt");
    vector<string> file;
    string str;
    while(getline(in, str)){
        file.push_back(str);
    }
    for(auto l: file){
        istringstream line(l);
        string word;
        while(line >> word){
            cout << word << endl;
        }
    }
    return 0;
}
