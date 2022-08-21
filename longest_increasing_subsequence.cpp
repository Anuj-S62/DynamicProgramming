#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 

void disp(vector<int> arr){
    for(int i:arr) cout<<i<<" ";
    cout<<endl;
}

void disp(vector<vector<int> >arr){
    for(auto i:arr) disp(i);
}


// memoization

int solve(vector<int> &arr,int i,int j,vector<vector<int>> &dp){
    if(i==0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(arr[i-1]<arr[j-1]){
        return dp[i][j] = max((1+solve(arr,i-1,i,dp)),solve(arr,i-1,j,dp));
    }
    return dp[i][j] = solve(arr,i-1,j,dp);
}
int lengthOfLIS(vector<int>& nums) {
    nums.push_back(10002);
    vector<int> temp(nums.size()+5,-1);
    vector<vector<int>> dp(nums.size()+5,temp);
    return solve(nums,nums.size()-1,nums.size(),dp);
}

// Top down 

int lis(vector<int> &arr){
    vector<int> temp(arr.size()+1);
    vector<vector<int>> dp(arr.size()+1,temp);
    for(int i = 0;i<dp.size();i++){
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for(int i =1;i<dp.size();i++){
        for(int j = 1;j<dp.size();j++){
            if(arr[i-1]<arr[j-1]){
                dp[i][j] = max((1 + dp[i-1][i]),dp[i-1][j]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[dp.size()-1][dp.size()-1];
}
// method 3
int lis2(vector<int> arr){
    vector<int> dp(arr.size()+1,1);
    for(int i = 1;i<arr.size();i++){
        for(int j = 0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i] = max((1 + dp[j]),dp[i]);
            }
        }
    }
    int ans = INT_MIN;
    for(auto i:dp){
        ans  = max(i,ans);
    }
    return ans;
}


int main(){
    vector<int> arr = {1, 2, 1, 5,1};
    // cout<<solve(arr,arr.size()-1,arr.size())<<endl;
    // cout<<lengthOfLIS(arr)<<endl;
    cout<<lis2(arr)<<endl;
    // vector<int> arr = {69, 54, 19, 51, 16, 54, 64, 89, 72, 40, 31, 43, 1, 11, 82, 65, 75, 67, 25, 98, 31, 77, 55, 88, 85, 76, 35, 101, 44, 74, 29, 94, 72, 39, 20, 24, 23, 66, 16, 95, 5, 17, 54, 89, 93, 10, 7, 88, 68, 10, 11, 22, 25, 50, 18, 59, 79, 87, 7, 49, 26, 96, 27, 19, 67, 35, 50, 10, 6, 48, 38, 28, 66, 94, 60, 27, 76, 4, 43, 66, 14, 8, 78, 72, 21, 56, 34, 90, 89 };
    // cout<<lengthOfLIS(arr)<<endl;
    // cout<<lis(arr)<<endl;
 
    return 0;
}