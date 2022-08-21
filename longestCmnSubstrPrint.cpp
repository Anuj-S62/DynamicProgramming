#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
void disp(vector<vector<int>> dp){
    for(auto i:dp){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
}

string lcstrTopDown(string a,string b){
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
    string arr;
    int idx = 0;
    for(int i = 0;i<dp.size();i++){
        for(int j = 0;j<dp[0].size();j++){
            if(dp[i][j]==ans){
                idx = i;
                break;
            }
        }
        if(idx) break;
    }
    for(int i = 0;i<ans;i++) arr.push_back(a[idx-1-i]);
    reverse(arr.begin(),arr.end());
    return arr;   
}
    string longestcommonsubstr(string a,string b) {
        return lcstrTopDown(a,b);
    } 
 
int main(){
    string a = "aacabdkacaa";
    string b = "aacabdkacagsjdaa";
    cout<<longestcommonsubstr(a,b)<<endl;
 
    return 0;
}