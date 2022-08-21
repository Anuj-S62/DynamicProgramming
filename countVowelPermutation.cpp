#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
// int countVowelPermutation(int n) {
//     vector<int> temp(n+1);
//     vector<vector<int>> dp(5,temp);
//     for(int i = 0;i<dp.size();i++) dp[i][1] = 1;
//     for(int i = 2;i<=n;i++){
//         dp[0][i] = dp[1][i-1];
//         dp[1][i] = dp[0][i-1] + dp[2][i-1];
//         dp[2][i] = dp[0][i-1] + dp[1][i-1] + dp[3][i-1] + dp[4][i-1];
//         dp[3][i] = dp[2][i-1] + dp[4][i-1];
//         dp[4][i] = dp[0][i-1];
//     }
//     int ans =0 ;
//     for(int i = 0;i<5;i++){
//         ans += dp[i][n];
//     }
//     return ans;
// } 
 
        int countVowelPermutation(int n) {
            int mod = 1000000007;
    vector<long long int> temp(n+1);
    vector<vector<long long int>> dp(5,temp);
    for(int i = 0;i<dp.size();i++) dp[i][1] = 1;
    for(int i = 2;i<=n;i++){
        dp[0][i] = (dp[1][i-1])%mod;
        dp[1][i] = (dp[0][i-1] + dp[2][i-1])%mod;
        dp[2][i] = (dp[0][i-1] + dp[1][i-1] + dp[3][i-1] + dp[4][i-1])%mod;
        dp[3][i] = (dp[2][i-1] + dp[4][i-1])%mod;
        dp[4][i] = (dp[0][i-1])%mod;
    }
    long long int ans =0 ;
    for(int i = 0;i<5;i++){
        ans += dp[i][n];
        ans = ans%mod;
    }
    return (int)ans;
} 

int main(){
    cout<<countVowelPermutation(144)<<endl;
 
    return 0;
}