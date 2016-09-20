#include <iostream>
#include <string>
using namespace std;

void comp(string a, string b){
	if(a != b){
		cout << (a > b? a : b) << endl;
	}
}

void compSize(string a, string b){
	if(a.size() != b.size()){
		cout << (a.size() > b.size()? a : b);
	}
}

int main(){
	string a,b;
	cin >> a >> b;

	comp(a,b);
	compSize(a,b);

	return 0;
}