#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[],int val[],int w,int n);
int  t[100][100];     // Global dp array
// memset(t, 0, sizeof(t));

int knapsack(int wt[],int val[],int w,int n){

    if(n==0||w==0){
        
        return 0;
    }
    // cout<<endl<<"||||"<<endl;
    if(t[n][w] != -1){
        return t[n][w];
    }

   else
    if(wt[n-1] <= w){
        return t[n][w] = max(val[n-1] + knapsack(wt,val,w-wt[n-1],n-1), knapsack(wt,val,w,n-1));
}else
        return t[n][w] = knapsack(wt,val,w,n-1); 
          
}



int main(){
    
    int val[] = {60,100,120};
    int wt[] = {10,20,30};
    int we = 50;
    int n = sizeof(val) / sizeof(val[0]);

    for (int i = 0; i <= n; i++)
		for (int j = 0; j <= we; j++)
			t[i][j] = -1; // initialize matrix with -1


    cout<<n<<endl;
    cout<<knapsack(wt,val,we,n)<<endl;


}