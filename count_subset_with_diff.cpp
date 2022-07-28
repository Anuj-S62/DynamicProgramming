#include<bits/stdc++.h>
using namespace std;

void disp(vector<vector<int>> vec){
    for(int i = 0;i<vec.size();i++){
        for(int j = 0;j<vec[i].size();j++) cout<<vec[i][j]<<" ";
        cout<<endl;
    }
}

int subset(vector<int> &arr,int sum,int x,vector<vector<int>> &dp){
    if(sum==0) return 1;
    if(sum<0 || x==0) return 0;
    if(dp[x][sum]!=-1) return dp[x][sum];
    if(sum>=arr[x-1]) return dp[x][sum] = (subset(arr,sum,x-1,dp) + subset(arr,sum-arr[x-1],x-1,dp));
    else return dp[x][sum] = subset(arr,sum,x-1,dp);
}

int solve(vector<int> &A, int B) {
    int range = 0;
    for(int i:A) range+=i;
    int s1;
    if((range+B)%2==0) s1 = (range+B)/2;
    else return 0;
    vector<int> temp(s1+1,-1);
    vector<vector<int>> dp(A.size()+2,temp);
    for(int i = 0;i<dp.size();i++) dp[i][0] = 1; 
    for(int j = 1;j<dp[0].size();j++) dp[0][j] = 0;
    return subset(A,s1,A.size(),dp);
}


int main(){
    vector<int> arr = {1,1,2,3};
    int b = 1;
    cout<<solve(arr,b)<<endl;

    return 0;
}