/* A Naive recursive implementation of
 0-1 Knapsack problem */
#include <bits/stdc++.h>
using namespace std;
 
// A utility function that returns
// maximum of two integers
// int max(int a, int b) { return (a > b) ? a : b; }
 
// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapsack(int wt[],int val[],int w,int n){

    if(n==0||w==0){
        
        return 0;
    }

    if(wt[n-1] > w){
        return knapsack(wt,val,w,n-1); 
}else
     return max(val[n-1] + knapsack(wt,val,w-wt[n-1],n-1), knapsack(wt,val,w,n-1));
          
}
// Driver code
int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsack(wt,val,W,n);
    return 0;
}