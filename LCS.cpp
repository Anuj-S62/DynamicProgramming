#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int lcs(string x,string y,int i,int j,vector<vector<int>> &dp){
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==0 || j==0) return 0;
    if(x[i-1]==y[j-1]) return dp[i][j] = 1 + lcs(x,y,i-1,j-1,dp);
    return dp[i][j] = max(lcs(x,y,i-1,j,dp) , lcs(x,y,i,j-1,dp));
}

int solve(string A, string B) {
    vector<int> temp(B.length()+1,-1);
    vector<vector<int>> dp(A.length()+1,temp);
    for(int i = 0;i<dp.size();i++) dp[i][0] = 0;
    for(int i = 0;i<dp[0].size();i++) dp[0][i] = 0;
    return lcs(A,B,A.length(),B.length(),dp);
}

 
int main(){
    
 
    return 0;
}