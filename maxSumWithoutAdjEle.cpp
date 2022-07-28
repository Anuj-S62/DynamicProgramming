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

int solve(vector<vector<int>> &arr,int i,int j,vector<vector<int>> &dp){
    if(j<=0) return 0;
    if(dp[j][i]!=-1) return dp[j][i];
    else return dp[j][i] = max((arr[i][j-1] + max(solve(arr,0,j-2,dp),solve(arr,1,j-2,dp))),max(solve(arr,0,j-1,dp),solve(arr,1,j-1,dp)));
}

int adjacent(vector<vector<int> > &A) {
    vector<vector<int>> dp;
    vector<int> temp(2,-1);
    for(int i = 0;i<A[0].size()+1;i++) dp.push_back(temp);
    dp[0][0] = 0; dp[0][1] = 0; dp[1][0] = A[0][0]; dp[1][1] = A[1][0];
    return max(solve(A,0,A[0].size(),dp),solve(A,1,A[0].size(),dp));
} 

int main(){
    // vector<vector<int>> arr = {{1, 2, 3, 4},
    //         {2, 3, 4, 5}};
    vector<vector<int>> arr = {
  {10, 17, 8, 7, 1, 2, 20, 17, 19, 17, 4, 19, 11, 16, 8, 17, 14, 14},
  {17, 7, 4, 10, 19, 4, 20, 7, 4, 5, 2, 6, 4, 16, 15, 11, 8, 16}
    };

    // cout<<solve(arr,1,arr[0].size())<<endl;
    // cout<<solve(arr,2,arr[0].size())<<endl;
    cout<<adjacent(arr);
 
    return 0;
}