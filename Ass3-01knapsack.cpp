// Here is the top-down approach of 
// dynamic programming 
#include <bits/stdc++.h> 
using namespace std; 

// Returns the value of maximum profit 
int knapSackRec(int W, int wt[], int val[], int index, int** dp) 
{ 
	// base condition 
	if (index < 0) 
		return 0; 
	if (dp[index][W] != -1) 
		return dp[index][W]; 

	if (wt[index] > W) { 

		// Store the value of function call 
		// stack in table before return 
		dp[index][W] = knapSackRec(W, wt, val, index - 1, dp); 
		return dp[index][W]; 
	} 
	else { 
		// Store value in a table before return
		dp[index][W] = max(val[index] 
						+ knapSackRec(W - wt[index], wt, val, 
										index - 1, dp), 
					knapSackRec(W, wt, val, index - 1, dp)); 

		// Return value of table after storing 
		return dp[index][W]; 
	} 
} 

int knapSack(int W, int wt[], int val[], int n) 
{ 
	// double pointer to declare the 
	// table dynamically 
	int** dp; 
	dp = new int*[n]; 

	// loop to create the table dynamically 
	for (int i = 0; i < n; i++) 
		dp[i] = new int[W + 1]; 

	// loop to initially filled the 
	// table with -1 
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < W + 1; j++) 
			dp[i][j] = -1; 
	return knapSackRec(W, wt, val, n - 1, dp); 
} 

// Driver Code 
int main() 
{ 
	int n, W;

    cout << "Enter the number of items: ";
    cin >> n;
    
    int profit[n];
    int weight[n];
    
    cout << "Enter the profits and weights for each item:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " - Profit: ";
        cin >> profit[i];
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> weight[i];
    }

    cout << "Enter the maximum weight capacity (W): ";
    cin >> W;

    cout << "Maximum profit: " << knapSack(W, weight, profit, n) << endl;
    
    return 0; 
}