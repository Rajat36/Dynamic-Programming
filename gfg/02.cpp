#include <bits/stdc++.h>
using namespace std;

const int D = 100; // DP - matrix dimension

int t[D][D]; // DP matrix

int Knapsack(int wt[], int val[], int W, int n) {
	// base case
	if (n == 0 || W == 0)
		return 0;

	// if already calculated
  
  
	if (t[n][W] != -1)
		return t[n][W];
  
	// else calculate
	else {
		if (wt[n - 1] <= W)
			return t[n][W] = max(val[n - 1] + Knapsack(wt, val, W - wt[n - 1], n - 1),Knapsack(wt, val, W, n - 1));
		else 
			return t[n][W] = Knapsack(wt, val, W, n - 1);

		
	}
}

int main() {
	// int n; cin >> n; // number of items
	// int val[n], wt[n]; // values and wts array
	// for (int i = 0; i < n; i++)
	// 	cin >> wt[i];
	// for (int i = 0; i < n; i++)
	// 	cin >> val[i];
	// int W; cin >> W; // capacity


// My Code


int val[] = {60,100,120};
    int wt[] = {10,20,30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);


// My Code

	// matrix initialization
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= W; j++)
			t[i][j] = -1; // initialize matrix with -1

    

	cout << Knapsack(wt, val, W, n) << endl;
	return 0;
}