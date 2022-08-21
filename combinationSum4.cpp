#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int dp[1001]; 

 int solve(vector<int> &arr,int sum){
    if(dp[sum]!=-1) return dp[sum];
    if(sum==0) return 1;
    else if(sum<=0) return 0;
    int ans = 0;
    for(int x = 0;x<arr.size();x++){
        if(arr[x]>sum) break;
        ans += solve(arr,sum-arr[x]);
    }
    return dp[sum] = ans;
 }
 
int combinationSum4(vector<int>& nums, int target) {
    memset(dp,-1,sizeof(dp));
    dp[0] = 1;
    return solve(nums,target);
}

int main(){
    vector<int> arr = {1,2,3};
    cout<<combinationSum4(arr,32)<<endl;
 
    return 0;
}