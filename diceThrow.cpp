#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 

void show(vector<long long int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<i<<" : "<<arr[i]<<endl;
    }
}

int dp[1001][1001];

int solve(int sum,int dice,int face){
    if(sum<dice) return 0;
    if(sum==0 && dice==0) return 1;
    else if(sum<=0) return 0;
    if(dp[dice][sum]!=-1) return dp[dice][sum];
    long long int ans = 0;
    for(int i = 1;i<=face;i++){
        ans += solve(sum-i,dice-1,face);
        ans = ans%1000000007;
    }
    return dp[dice][sum] = ans%1000000007;
}

int findDiceSum(int A, int B, int C) {
    if(C<A) return 0;
    memset(dp,-1,sizeof(dp));
    for(int i = 0;i<1001;i++) dp[0][i] = 0,dp[i][0] = 0;
    return solve(C,A,B);
}

 
int main(){
    memset(dp,-1,sizeof(dp));
    for(int i = 0;i<1001;i++) dp[0][i] = 0,dp[i][0] = 0;
    cout<<findDiceSum(2,4,5)<<endl;
 
    return 0;
}