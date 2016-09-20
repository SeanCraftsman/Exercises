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
	for(auto it = vec.begin(); it != vec.end(); ++it){
		for(auto c = it->begin(); c != it->end(); ++c ){
			*c = toupper(*c);
		}
		cout << *it << endl;
	}
	return 0;
}