#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int find(int x,int next,int B,vector<vector<int>> &dp){
    if(B==0) return 1;
    else if(x<=0) return 0;
    // if(dp[B][x]!=-1) return dp[B][x];
    if(x<=(next/2)){
        return dp[B][x] = find(x-1,x,B-1,dp) ;
    }
    return dp[B][x] = find(x-1,next,B,dp);
}

int solve(int A, int B) {
    vector<int> temp(A+1,-1);
    vector<vector<int>> dp(B+1,temp);
    for(int i = 1;i<dp[0].size();i++) dp[1][i] = i;
    for(int i = 2;i<dp.size();i++) dp[i][1] = 0;
    int ans = 0;
    for(int i = 1;i<=A;i++){
        ans += find(i,INT_MAX,B,dp);
    }
    return ans;
}

void disp(vector<vector<int>> &dp){
    for(auto i:dp){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
}

// int find(int x,int next,int B,vector<vector<int>> &dp){
//     if(dp[B][x]!=-1 && B==1 && next!=INT_MAX){
//         if(x<=(next/2)){
//             return find(x-1,x,B-1,dp) + find(x-1,next,B,dp);
//         }
//         return find(x-1,next,B,dp);
//     }
//     if(x==0) return 0;
//     if(B==0 && x>0) return 1;
//     else if(x<=0) return 0;
//     if(dp[B][x]!=-1) return dp[B][x];
//     if(x<=(next/2)){
//         return dp[B][x] = find(x-1,x,B-1,dp) + find(x-1,next,B,dp);
//     }
//     return dp[B][x] = find(x-1,next,B,dp);
// }

// int solve(int A, int B) {
//     vector<int> temp(A+1,-1);
//     vector<vector<int>> dp(B+1,temp);
//     for(int i = 0;i<dp[0].size();i++) dp[1][i] = i;
//     dp[1][0] = -1;
//     for(int i = 2;i<dp.size();i++){
//         dp[i][1] = 0;
//     }
//     disp(dp);
//     cout<<"-----"<<endl;
//     int ans = find(A,INT_MAX,B,dp);
//     disp(dp);
//     return ans;
// }

// const int mod =1e9+7;
// int solve(int A, int B) {
//     int dp[A+1][B+1];
//     memset(dp, 0, sizeof(dp));
//     for(int i=1;i<=A;i++){
//         for(int j=1;j<=B;j++){
//             if(j==1){
//                 dp[i][j]=i;
//             }
//             else{
//                 dp[i][j]=dp[i-1][j]+dp[i/2][j-1];
//             }
//             dp[i][j]%=mod;
//         }
//     }
//     return dp[A][B];
// }
 
int main(){
    cout<<solve(4,2)<<endl;
 
    return 0;
}