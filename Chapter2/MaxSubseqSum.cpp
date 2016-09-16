#include <iostream>

int MaxSubseqSum1(const int A[], int N){
	int maxSum = 0;
	for(int i=0; i < N; i++){
		int thisSum = 0;
		for(int j=i; j < N; j++){
			thisSum += A[j];
			if(thisSum > maxSum){
				maxSum = thisSum;
			}
		}
	}
	return maxSum;
}

int max3(int a, int b, int c){
	return a > b ? (a > c? a : c) : (b > c? b : c);
}

int maxSubseqSum(const int A[], int left, int right){
	if(left == right){
		if(A[left] > 0){
			return A[left];
		}
		else{
			return 0;
		}
	}
	int center = (left+right)/2;
	int maxLeftSum = maxSubseqSum(A,left,center);
	int maxRightSum = maxSubseqSum(A,center+1,right);

	int maxLeftBorderSum = 0;
	int thisLeftBorderSum = 0;
	for(int i=center; i >= left; i--){
		thisLeftBorderSum += A[i];
		if(thisLeftBorderSum > maxLeftBorderSum){
			maxLeftBorderSum = thisLeftBorderSum;
		}
	}

	int maxRightBorderSum = 0;
	int thisRightBorderSum = 0;
	for(int i=center+1; i <= right; i++){
		thisRightBorderSum += A[i];
		if(thisRightBorderSum > maxRightBorderSum){
			maxRightBorderSum = thisRightBorderSum;
		}
	}

	return max3(maxLeftSum,maxRightSum,(maxLeftBorderSum+maxRightBorderSum));
}

int MaxSubseqSum2(const int A[], int N){
	return maxSubseqSum(A, 0, N-1);
}

int MaxSubseqSum3(const int A[], int N){
	int maxSum = 0;
	int thisSum = 0;
	for(int i=0; i < N; i++){
		thisSum += A[i];
		if(thisSum > maxSum){
			maxSum = thisSum;
		}
		else if(thisSum < 0){
			thisSum = 0;
		}
	}
	return maxSum;
}