#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void disp(vector<int> arr){
    for(int i:arr) cout<<i<<" ";
    cout<<endl;
}

void disp(vector<vector<int>> arr){
    for(auto i:arr){
        disp(i);
    }
}

int solve1(vector<vector<int>> &arr,int i,int j,vector<vector<int>> &dp){
    if(dp[i][j]!=-1) return dp[i][j];
    if((i==0 && j==0) || (j>i)) return 0;
    else if(i==1 && j==1) return arr[i-1][j-1];
    else if(j==1 && i>1) return dp[i][j] = arr[i-1][j-1] + solve1(arr,i-1,j,dp);
    else if(i==j) return dp[i][j] = arr[i-1][j-1] + solve1(arr,i-1,j-1,dp);
    else return dp[i][j] = arr[i-1][j-1] + min(solve1(arr,i-1,j,dp),solve1(arr,i-1,j-1,dp));
}

int minimumTotal(vector<vector<int> > &A) {
    int ans = INT_MAX;
    vector<vector<int>> dp;
    vector<int> temp(A.size()+1,-1);
    for(int i = 0;i<A.size()+1;i++) dp.push_back(temp);
    for(int i = 0;i<dp.size();i++) dp[0][i] = 1;
    for(int i = 0;i<dp.size();i++) dp[i][0] = 1;
    for(int i = 0;i<A.size();i++){
        ans = min(ans,solve1(A,A.size(),i+1,dp));
    }
    return ans;
}

int main(){
    vector<vector<int>> arr = {{8},{5,3},{7,6,8},{6,7,1,8},{4,9,7,3,1},{0,2,3,7,1,8},{9,3,7,4,8,0,4}};
    cout<<solve(arr);
 
    return 0;
}
// 7 8 5 3 7 6 8 6 7 1 8 4 9 7 3 1 0 2 3 7 1 8 9 3 7 4 8 0 4