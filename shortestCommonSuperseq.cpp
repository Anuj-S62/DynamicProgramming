#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
void disp(vector<vector<int>> dp){
    for(auto i:dp){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
}


// MEMOIZATION
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


// TOP DOWN METHOD
int lcsTopDown(string a,string b){
    // initialization of matrix
    vector<int> temp(b.length()+1);
    vector<vector<int>> dp(a.length()+1,temp);
    for(int i = 0;i<a.length()+1;i++) dp[i][0] = 0;
    for(int i = 0;i<b.length()+1;i++) dp[0][i] = 0;

    // choice diagram
    for(int i = 1;i<dp.size();i++){
        for(int j = 1;j<dp[0].size();j++){
            if(a[i-1]==b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[a.length()][b.length()];
} 


int shortestCommonSupersequence(string a,string b){
    int common = lcsTopDown(a,b);
    return a.length() + b.length() - common;
}


int main(){
    string a = "aggtab";
    string b = "gxtxayb";
    cout<<shortestCommonSupersequence(a,b)<<endl;
    
    return 0;
}