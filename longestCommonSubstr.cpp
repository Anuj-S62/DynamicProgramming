#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
void disp(vector<vector<int>> dp){
    for(auto i:dp){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
}


// RECURSIVE
int LCS(string str1, string str2, int n, int m, int count)
{
    if (n==0 || m==0)
        return count;
    if (str1[n-1] == str2[m-1])
        return LCS(str1, str2, n-1, m-1, count+1);
    return max(count, max(LCS(str1, str2, n-1, m, 0), LCS(str1, str2, n, m-1, 0)));
}

int solve(string A, string B) {
    vector<int> temp(B.length()+1,-1);
    vector<vector<int>> dp(A.length()+1,temp);
    for(int i = 0;i<dp.size();i++) dp[i][0] = 0;
    for(int i = 0;i<dp[0].size();i++) dp[0][i] = 0;
    return LCS(A,B,A.length(),B.length(),0);

}


// TOP DOWN METHOD
int lcstrTopDown(string a,string b){
    // initialization of matrix
    vector<int> temp(b.length()+1);
    vector<vector<int>> dp(a.length()+1,temp);
    for(int i = 0;i<a.length()+1;i++) dp[i][0] = 0;
    for(int i = 0;i<b.length()+1;i++) dp[0][i] = 0;

    // choice diagram
    int ans = INT_MIN;
    for(int i = 1;i<dp.size();i++){
        for(int j = 1;j<dp[0].size();j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(dp[i][j],ans);
            }
            else dp[i][j] = 0;
        }
    }
    return ans;
} 


int main(){
    string a = "abdecj";
    string b = "abtdj";
    cout<<solve(a,b)<<endl;
    cout<<lcstrTopDown(a,b)<<endl;
 
    return 0;
}