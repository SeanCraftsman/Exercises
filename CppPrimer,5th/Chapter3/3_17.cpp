#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	vector<string> vec;
	string s;
	while(cin >> s){
		vec.push_back(s);
	}
	auto it = vec.begin();
	auto c = it->begin();
	for(auto s : vec){
		for(auto &c : s ){
			c = toupper(c);
		}
		cout << s << endl;
	}
	return 0;
}
