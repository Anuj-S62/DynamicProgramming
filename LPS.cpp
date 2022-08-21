#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int lcsTopDown(string a,string b){
    // initialization of matrix
    vector<int> temp(b.length()+1);
    vector<vector<int>> dp(a.length()+1,temp);
    for(int i = 0;i<a.length()+1;i++) dp[i][0] = 0;
    for(int i = 0;i<b.length()+1;i++) dp[0][i] = 0;

    // choice diagram
    for(int i = 1;i<dp.size();i++){
        for(int j = 1;j<dp[0].size();j++){
            if(a[i-1]==b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[a.length()][b.length()];
} 

int lps(string a){
    string b = a;
    reverse(b.begin(),b.end());
    return lcsTopDown(a,b);
}
 
int main(){
    string a = "agbcba";
    cout<<lps(a)<<endl;
 
    return 0;
}