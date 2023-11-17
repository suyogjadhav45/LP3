#include <bits/stdc++.h>
using namespace std;


// int fun(int ind,int w,vector<int>&wt,vector<int>&val,vector<vector<int>>&dp){
//     if(ind==wt.size() || w<=0){
//         return 0;
//     }
//     if(dp[ind][w]!=-1) return dp[ind][w];
//     int nottake=0+fun(ind+1,w,wt,val,dp);
//     int take=0;
//     if(wt[ind]<=w) take=val[ind]+fun(ind+1,w-wt[ind],wt,val,dp);
//     return dp[ind][w]=max(nottake,take);
// }





























int solve(int idx, int w, vector<vector<int>> &dp, vector<int> &val, vector<int> &wt)
{
    if (idx == wt.size() || w <= 0)
    {
        return 0;
    }
    if (dp[idx][w] != -1)
    {
        return dp[idx][w];
    }
    int nottake = 0 + solve(idx + 1, w, dp, val, wt);
    int take = 0;
    if (wt[idx] <= w)
    {
        take = val[idx] + solve(idx + 1, w - wt[idx], dp, val, wt);
    }
    dp[idx][w]=max(take, nottake);
    return dp[idx][w];
}



int main()
{

    int n, W;
    cout<<"Enter the number of items and the capacity of the knapsack"<<endl;
    cin >> n >> W;
    vector<int> wt(n);
    vector<int> val(n);

    cout<<"Enter the weights of the items"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    cout<<"Enter the values of the items"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    int a = solve(0, W, dp, val, wt);
    cout <<"answer ---> "<< a << endl;

    return 0;
}


// n=3 w=4
// wt  = 4 5 1
// val = 1 2 3
// ans = 3



// time complexity is O(n * W), where n is the number of items and W is the knapsack capacity.

// The table has dimensions (n + 1) x (W + 1), where n is the number of items and W is the knapsack capacity.
// Therefore, the space complexity is O(n * W).