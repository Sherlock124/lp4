#include <bits/stdc++.h> 
using namespace std; 

int max(int a, int b) { return (a > b) ? a : b; } 

int knapSack(int index, int capacity, int wt[], int val[], vector<vector<int>> dp) { 

	// Base Case 
	if (index < 0 || capacity == 0) 
		return 0; 
	
	if(dp[index][capacity] != -1){
		return dp[index][capacity];
	}

	if (wt[index] > capacity) 
		return dp[index][capacity] = knapSack(index-1, capacity, wt, val, dp);

	else
		return dp[index][capacity] = max( val[index] + knapSack(index-1, capacity - wt[index], wt, val, dp), knapSack(index-1, capacity, wt, val, dp)); 
} 

int main(){ 
	int profit[] = { 60, 100, 120 }; 
	int weight[] = { 10, 20, 30 }; 
	int capacity = 50; 
	int n = sizeof(profit) / sizeof(profit[0]); 

	vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
	
	cout << knapSack(n-1, capacity, weight, profit, dp); 
	return 0; 
} 
