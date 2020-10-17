#include<iostream>
using namespace std;

int profit(int wines[],int i,int j,int y,int dp[][100]){
	
	//Base case
	if(i>j){
		return 0;
	}
	//Return if dp[i][j] is known
	if(dp[i][j] != 0){
		return dp[i][j];
	}

	//Recursive Case
	int op1,op2,ans;
	op1 = op2 = ans = 0;

	op1 = wines[i]*y + profit(wines,i+1,j,y+1,dp);
	op2 = wines[j]*y + profit(wines,i,j-1,y+1,dp);

	ans = max(op1,op2);
	return dp[i][j] = ans;
}

int main(){	//Greedy - 49   ----> DP - 50

	int wines[] = {2,3,5,1,4};  //prices of wines
	int dp[100][100] = {0};

	int n = sizeof(wines)/sizeof(int);

	int i=0;
	int j=n-1;
	int y=1;
	cout << profit(wines,i,j,y,dp);

	return 0;
}
