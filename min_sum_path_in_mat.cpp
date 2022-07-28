#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 

int solve(vector<vector<int>> &arr,int i,int j,vector<vector<int>> &dp){
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==0 && j==0) return 0;
    else if(i==1 && j==1) return dp[i][j] = arr[i-1][j-1];
    if(i==1 && j>1) return dp[i][j] = arr[i-1][j-1] + solve(arr,i,j-1,dp);
    else if(j==1 && i>1) return dp[i][j] = arr[i-1][j-1] + solve(arr,i-1,j,dp);
    else return dp[i][j] = arr[i-1][j-1] + min(solve(arr,i-1,j,dp),solve(arr,i,j-1,dp));
}

int minPathSum(vector<vector<int> > &A) {
    vector<vector<int>> dp;
    vector<int> temp(A[0].size()+2,-1);
    for(int i = 0;i<A.size()+2;i++) dp.push_back(temp);
    for(int i = 0;i<dp[0].size();i++) dp[0][i] = 0;
    for(int i = 0;i<dp.size();i++) dp[i][0] = 0;
    return solve(A,A.size(),A[0].size(),dp);
}
 

int main(){
    vector<vector<int>> arr = {{1,3,2},{4,3,1},{5,6,1}};
    cout<<minPathSum(arr)<<endl;
 
    return 0;
}