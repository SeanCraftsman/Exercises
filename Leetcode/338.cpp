#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int num){
	vector<int> vec;
	vec.push_back(0);
	int cnt = 0;
	for(int i = 1; i <= num; i++){
		int temp = i;
		while(temp % 2 == 0){
			cnt--;
			temp /= 2;
		}
		cnt ++;
		vec.push_back(cnt);
	}
	return vec;
}

int main(){
	int num = 10;
	vector<int> vec;
	vec = countBits(num);
	for(auto it = vec.begin(); it != vec.end(); ++it){
		cout << *it << " " ;	
	}
	return 0;
}