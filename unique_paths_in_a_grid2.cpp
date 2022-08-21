#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int solve(vector<vector<int>> &arr,int i,int j){
    if(i==0 && j==0 && arr[i][j]==0) return 1;
    else if(i<0 || j<0 ||arr[i][j]==1) return 0;
    else return solve(arr,i-1,j) + solve(arr,i,j-1);
}

int uniquePathsWithObstacles(vector<vector<int> > &A){
    return solve(A,A.size()-1,A[0].size()-1);
}
 
int uniquePathTopDown(vector<vector<int>> &arr){
    if(arr.size()==0) return 0;
    else if(arr[0].size()==0) return 0;
    vector<int> temp(arr[0].size());
    vector<vector<int>> dp(arr.size(),temp);
    int x = 1;
    for(int i = 0;i<dp.size();i++){
        if(arr[i][0]==1) x = 0;
        dp[i][0] = x;
    }
    x = 1;
    for(int i = 0;i<dp[0].size();i++){
        if(arr[0][i]==1) x = 0;
        dp[0][i] = x;
    }

    for(int i = 1;i<dp.size();i++){
        for(int j = 1;j<dp[0].size();j++){
          if(arr[i][j]==1){
            dp[i][j] = 0;
            continue;
          }
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    // for(auto i:dp){
    //   for(auto j:i) cout<<j<<" ";
    //   cout<<endl;
    // }
    return dp[arr.size()-1][arr[0].size()-1];

}

int main(){
    vector<vector<int>> arr = {
  {0, 0, 1, 0, 1, 1, 1, 1},
  {0, 1, 0, 1, 0, 0, 1, 1},
  {0, 0, 1, 0, 0, 0, 0, 1}
    };
    cout<<uniquePathTopDown(arr)<<endl;
    cout<<uniquePathsWithObstacles(arr)<<endl;
 
 
    return 0;
}