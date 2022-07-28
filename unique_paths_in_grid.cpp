#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
void disp(vector<vector<int>> vec){
    for(int i = 0;i<vec.size();i++){
        for(int j = 0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}

int solve(vector<vector<int>> &arr,int i,int j,vector<vector<int>> &dp){
    if(dp[i][j]!=-1) return dp[i][j];
    // if(i==0 && j==0 && arr[i][j]==0) return 1;
    // else if(i<0 || j<0 ||arr[i][j]==1) return 0;
    else return dp[i][j] = solve(arr,i-1,j,dp) + solve(arr,i,j-1,dp);
}

int uniquePathsWithObstacles(vector<vector<int> > &A){
    vector<vector<int>> dp;
    for(int i =0;i<A.size()+10;i++){
        vector<int> temp;
        for(int j = 0;j<A[0].size()+10;j++){
            temp.push_back(-1);
        }
        dp.push_back(temp);
    }
    bool flag = true;
    for(int i = 0;i<A[0].size();i++){
        if(A[0][i]==0 && flag) dp[0][i] = 1;
        else{
            dp[0][i]==0;
            flag = false;
        }
    }
    flag = true;
    for(int i = 0;i<A.size();i++){
        if(A[i][0]==0 && flag) dp[i][0] = 1;
        else{
            dp[0][i]==0;
            flag = false;
        }
    }
    for(int i = 0;i<dp.size();i++) if(dp[i][0]==-1) dp[i][0] = 0;
    for(int i = 0;i<dp[0].size();i++) if(dp[0][i]==-1) dp[0][i] = 0;
    // disp(dp);
    return solve(A,A.size()-1,A[0].size()-1,dp);
}

int main(){
//     vector<vector<int>> arr = {
//   {0, 0},
//   {0, 0},
//   {0, 0},
//   {1, 0},
//   {0, 0}
//     };

    vector<vector<int>> arr = {
  {0, 0, 1, 0, 1, 1, 1, 1},
  {0, 1, 0, 1, 0, 0, 1, 1},
  {0, 0, 1, 0, 0, 0, 0, 1}
};
    cout<<uniquePathsWithObstacles(arr)<<endl;
 
    return 0;
}

// [
//   [0, 0, 1, 0, 1, 1, 1, 1]
//   [0, 1, 0, 1, 0, 0, 1, 1]
//   [0, 0, 1, 0, 0, 0, 0, 1]
// ]