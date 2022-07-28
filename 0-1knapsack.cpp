// #include<bits/stdc++.h>
// using namespace std;

// int knapsack(vector<int> &val,vector<int> &wt,int weight,int x){
//     if(weight==0 || x==0) return 0;
//     if(weight>=wt[x-1]) return max(knapsack(val,wt,weight,x-1),(val[x-1]+knapsack(val,wt,weight-wt[x-1],x-1)));
//     else return knapsack(val,wt,weight,x-1);
// }
#include <bits/stdc++.h>
using namespace std;


int knapsack(vector<int> weight,vector<int> value,int n,int w){
    if(n==0 || w==0)return 0;
    if(weight[n-1]<=w){
        return max((value[n-1]+knapsack(weight,value,n-1,w-weight[n-1])),(knapsack(weight,value,n-1,w)));
    }
    else{
        return knapsack(weight,value,n-1,w);
    }
}
int knapsack_mem(vector<int> weight,vector<int> value,int n,int w,vector<vector<int>>dp){
    if(n==0 || w==0)return 0;
    if(dp[n][w]!=-1)return dp[n][w];
    if(weight[n-1]<=w){
        return dp[n][w]=max((value[n-1]+knapsack_mem(weight,value,n-1,w-weight[n-1],dp)),(knapsack_mem(weight,value,n-1,w,dp)));
    }
    else{
        return dp[n][w]=knapsack_mem(weight,value,n-1,w,dp);
    }
}
int knapsack_dp(vector<int> weight,vector<int> value,int w, vector<vector<int>> dp){
    int n=weight.size();
    // initialization
    for (int i = 0; i <n+1; i++){
        for (int j = 0; j < w+1; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    // answer
    for (int i = 1; i < n+1; i++){
        for (int j = 1; j < w+1; j++){
            //  now i is the size of array and j is the weight ( sub problem)
            if(weight[i-1]<=j){
                // whether we take the last value of the array or not
                dp[i][j]=max((value[i-1]+dp[i-1][j-weight[i-1]]),(dp[i-1][j]));
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        } 
    }
    return dp[n][w];
}

void disp(vector<int> vec){
    for(int a:vec){
        cout<<a<<" ";
    }
    cout<<endl;
}
void disp(vector<vector<int>> vec){
    for(vector<int> a:vec){
        disp(a);
    }
}

void init_dp(vector<vector<int>>&dp,int n,int w,int val){
    for (int i = 0; i <n+1; i++){
       vector<int> node(w+1,val);
       dp.push_back(node); 
    }
}

int main(){

    vector<int> weight={1,9,7,6,4,3,85,74,12,96,74};
    vector<int> value={10,14,100,45,90,20,85,74,12,96,74};
    int w=31;
    int n=weight.size();
    vector<int> val = { 468, 335, 501, 170, 725, 479, 359, 963, 465, 706, 146, 282, 828, 962, 492, 996, 943, 828, 437, 392, 605, 903, 154, 293, 383, 422, 717, 719, 896, 448, 727, 772, 539, 870, 913, 668, 300, 36, 895, 704, 812, 323};
    vector<int> wt = {4, 4, 5, 2, 2, 4, 9, 8, 5, 3, 8, 8, 10, 4, 2, 10, 9, 7, 6, 1, 3, 9, 7, 1, 3, 5, 9, 7, 6, 1, 10, 1, 1, 7, 2, 4, 9, 10, 4, 5, 5, 7};
    int c = 841;
    n = wt.size();

    // 5057
    // vector<int> val = {60,100,120};
    // vector<int> wt = {10,20,30};
    // int c = 50;
    // cout<<solve(val,wt,c)<<endl;
    // cout<<knapsack(wt,val,wt.size(),c)<<endl;
    vector<vector<int>>stor;
    init_dp(stor,n,c,-1);
    // cout<<knapsack(weight,value,n,w)<<endl;
    cout<<knapsack_mem(wt,val,n,c,stor)<<endl;


    vector<vector<int>>dp;
    init_dp(dp,n,c,0);

    cout<<knapsack_dp(wt,val,c,dp);
    return 0;
}