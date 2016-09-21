#include <iostream>
#include <string>
using namespace std;

string reverseString(string s){
	string t;
	for(auto it=s.rbegin(); it!=s.rend(); it++){
		t += *it;
	}
	return t;
}

int main(){
	string s = "hello";
	cout << reverseString(s) << endl;	
	return 0;
}