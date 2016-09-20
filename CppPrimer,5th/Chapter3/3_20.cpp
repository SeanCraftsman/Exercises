#include <iostream>
#include <vector>
using namespace std;

void sum1(vector<int> ivec){
	for(decltype(ivec.size()) i=0; i<ivec.size(); i+=2){
		if( i+1 < ivec.size()){
			cout << ivec[i]+ivec[i+1] << endl;
		}
		else{
			cout << ivec[i] << endl;
		}
	}
}

void sum2(vector<int> ivec){
	decltype(ivec.size()) j = ivec.size()-1;
	for(decltype(ivec.size()) i=0; i<=j; i++){
		if( i != j){
			cout << ivec[i]+ivec[j] << endl;
		}
		else{
			cout << ivec[i] << endl;
		}
		j--;
	}
}

int main(){
	vector<int> ivec;
	int temp;
	while(cin >> temp){
		ivec.push_back(temp);
	}
	sum1(ivec);
	sum2(ivec);
}
