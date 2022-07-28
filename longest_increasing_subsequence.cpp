#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int sub(vector<int> &arr,int i,int y,vector<int> &dp){
    if(i==0 && arr[i]>y) return 1;
    // if(dp[i]!=-1) return dp[i];
    if(i<=0){
        return 0;
    }
    if(arr[i] <y){
        return max(max((1+sub(arr,i-1,arr[i],dp)),sub(arr,i-1,y,dp)),sub(arr,i-1,arr[i],dp));
    }
    else return  max(sub(arr,i-1,y,dp),sub(arr,i-1,arr[i],dp));   
}

int lis(const vector<int> &A) {
    vector<int> dp(A.size()+5,-1);
    dp[0] = 1;
    vector<int> arr = A;
    int x = sub(arr,arr.size()-1,2001,dp);
    return x;
}

 
int main(){
    vector<int> arr = {1, 2, 1, 5,1};
    // vector<int> arr = {69, 54, 19, 51, 16, 54, 64, 89, 72, 40, 31, 43, 1, 11, 82, 65, 75, 67, 25, 98, 31, 77, 55, 88, 85, 76, 35, 101, 44, 74, 29, 94, 72, 39, 20, 24, 23, 66, 16, 95, 5, 17, 54, 89, 93, 10, 7, 88, 68, 10, 11, 22, 25, 50, 18, 59, 79, 87, 7, 49, 26, 96, 27, 19, 67, 35, 50, 10, 6, 48, 38, 28, 66, 94, 60, 27, 76, 4, 43, 66, 14, 8, 78, 72, 21, 56, 34, 90, 89 };
    cout<<lis(arr)<<endl;
 
    return 0;
}