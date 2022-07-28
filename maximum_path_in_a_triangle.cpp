#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int solve1(vector<vector<int>> &arr,int i,int j,vector<vector<int>> &dp){
    if(dp[i][j]!=-1) return dp[i][j];
    if((i==0 && j==0) || (j>i)) return 0;
    else if(i==1 && j==1) return arr[i-1][j-1];
    else if(j==1 && i>1) return dp[i][j] = arr[i-1][j-1] + solve1(arr,i-1,j,dp);
    else if(i==j) return dp[i][j] = arr[i-1][j-1] + solve1(arr,i-1,j-1,dp);
    else return dp[i][j] = arr[i-1][j-1] + max(solve1(arr,i-1,j,dp),solve1(arr,i-1,j-1,dp));
}

int solve(vector<vector<int> > &A) {
     int ans = INT_MIN;
    vector<vector<int>> tempDP;
    vector<int> temp(A.size()+1,-1);
    for(int i = 0;i<A.size()+1;i++) tempDP.push_back(temp);
    for(int i = 0;i<tempDP.size();i++) tempDP[0][i] = 1;
    for(int i = 0;i<tempDP.size();i++) tempDP[i][0] = 1;
    vector<vector<int>> dp = tempDP;
    for(int i = 0;i<A.size();i++){
        if(A[A.size()-1][i]==0) break;
        ans = max(ans,solve1(A,A.size(),i+1,dp));
    }
    return ans;
} 
 
void disp(vector<int> arr){
    for(int i:arr) cout<<i<<" ";
    cout<<endl;
}

void disp(vector<vector<int>> arr){
    for(auto i:arr){
        disp(i);
    }
}

int main(){
    vector<vector<int>> arr = {
         {3, 0, 0, 0}
        ,{7, 4, 0, 0}
        ,{2, 4, 6, 0}
        ,{8, 5, 9, 3}
    };
    // vector<int> arr = {1,2,3};
    // disp(arr);
    cout<<solve(arr)<<endl;
    
    return 0;
}