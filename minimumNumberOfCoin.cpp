#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
    int solve(vector<int> &arr,int sum,int i,vector<vector<int>> &dp){
        if(dp[i][sum]!=-1) return dp[i][sum];
    if(i<=0 && sum!=0) return INT_MAX-3;
    if(sum==0) return 0;
    else if(arr[i-1]<=sum){
        return dp[i][sum] = min((1 + solve(arr,sum-arr[i-1],i,dp)),solve(arr,sum,i-1,dp));
    }
    return dp[i][sum] = solve(arr,sum,i-1,dp);
}

int coin(vector<int> &arr,int s){
    sort(arr.begin(),arr.end());
    int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(s + 7, -1));
        
        for(int am = 0; am <= s; am++) {
            if(am % arr[0] == 0) dp[0][am] = am/arr[0];
            else dp[0][am] = INT_MAX-3;
        }
    int x = solve(arr,s,arr.size(),dp);
    if(x==2147483644) return -1;
    return x;

} 
    int coinChange(vector<int>& coins, int amount) {
        return coin(coins,amount);
    }
 
int main(){
    vector<int> arr = {1,2,5};
    cout<<coin(arr,11)<<endl;
 
    return 0;
}