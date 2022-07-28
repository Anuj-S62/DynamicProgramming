#include<bits/stdc++.h>
using namespace std;

void show(vector<long long int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<i<<" : "<<arr[i]<<endl;
    }
}

int calc(int sum,long long int count,vector<long long int> &dp){
    if(dp[sum]!=-1 && sum>0){
        count = count + dp[sum];
        return count%(1000000007);
    }
    if(sum<=0){
        if(sum==0){
            count++;
            count = count % (1000000007);
            return count;
        }
        return 0;
    }
    long long int y = 1000000007;
    dp[sum] = (calc(sum-1,count,dp)%y+calc(sum-2,count,dp)%y+calc(sum-3,count,dp)%y+calc(sum-4,count,dp)%y+calc(sum-5,count,dp)%y+calc(sum-6,count,dp)%y)%y;
    return dp[sum];
}

int solve(int A) {
    long long int count = 0;
    vector<long long int> dp(A+10,-1);
    dp[1] = 1;
    calc(A,count,dp);
    // return dp[A];
    return dp[A]%(1000000007);
}


int main(){
    cout<<solve(2);

    return 0;
}
// 1 1 1 1
// 1 1 2
// 1 2 1
// 1 3
// 2 1 1
// 2 2
// 3 1
// 4