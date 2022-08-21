#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int dp[101][101];

// memoization
int ans(int i,int j){
    // BASE CONDITION
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==0 && j==0) return 1;
    else if(i<0 || j<0) return 0;
    //  CHOICE DIAGRAM
    else return dp[i][j] = (ans(i-1,j) + ans(i,j-1));
}
    
int uniquePathsMemo(int m, int n) {
    // INITIALIZATION
    memset(dp,-1,sizeof(dp));
    for(int i = 0;i<101;i++){
        dp[i][0] = 1;
        dp[0][i] = 1;
    }
    return ans(m-1,n-1);
} 
 
// TOP DOWN  
int uniquePathTopDown(int m,int n){
    vector<int> temp(n+1,0);
    vector<vector<int>> t(m+1,temp);
    // INITIALIZATION
    for(int i = 0;i<t.size();i++) t[i][1] = 1;
    for(int i = 0;i<t[0].size();i++) t[1][i] = 1;

    // filling the matrix / Choice Diagram
    for(int i =2;i<t.size();i++){
        for(int j = 2;j<t[0].size();j++){
            t[i][j] = t[i-1][j] + t[i][j-1];
        }
    }
    return t[m][n];
}

int main(){
    cout<<uniquePathTopDown(3,2)<<endl;   
 
    return 0;
}