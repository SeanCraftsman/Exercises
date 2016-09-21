#include <iostream>
using namespace std;

int getSum(int a, int b){
	int sum = a ^ b;
	int c = a & b;
	c = c << 1;
	while(c != 0){
		a = sum;
		b = c;
		sum = a ^ b;
		c = a & b;
		c = c << 1;
	}
	return sum;
}



int main(){
	cout << getSum(-45,8) << endl;
	return 0;
}