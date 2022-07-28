#include<bits/stdc++.h>
using namespace std;

void disp(vector<vector<int>> vec){
    for(int i = 0;i<vec.size();i++){
        for(int j = 0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool subset(vector<int> &arr,int sum,int x,vector<vector<int>> &dp){
    // cout<<sum<<" "<<x<<endl;
    if(sum==0) return true;
    if(sum<0 || x==0) return false;
    if(dp[x][sum]!=-1) return dp[x][sum];
    if(sum>=arr[x-1]){
        return dp[x][sum] = (subset(arr,sum,x-1,dp) || subset(arr,sum-arr[x-1],x-1,dp));
    }
    else return dp[x][sum] = subset(arr,sum,x-1,dp);
}

int solve(vector<int> &A) {
    int range = 0;
    for(int i : A) range+=i;
    int x = range;
    range = range/2;
    
    vector<int> temp(range+1,-1);
    vector<vector<int>> dp(A.size()+2,temp);
    for(int i = 0;i<dp.size();i++){
        dp[i][0] = 1; 
    }
    for(int j = 1;j<dp[0].size();j++) dp[0][j] = 0;
    for(int i = range;i>=0;i--){
        if(subset(A,i,A.size(),dp)) return x - 2*i;
    }
    return 0;
    
}


int main(){
    // vector<int> arr = {68, 35, 1, 70, 25, 79, 59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83, 22, 17, 19, 96, 48, 27, 72, 39, 70, 13, 68, 100, 36, 95, 4, 12, 23, 34, 74, 65, 42, 12, 54, 69, 48, 45, 63, 58, 38, 60, 24, 42, 30, 79, 17, 36 };
    vector<int> arr = {1,7,11,5,1};
    cout<<solve(arr)<<endl;

    return 0;
}