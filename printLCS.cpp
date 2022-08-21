#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
string printLCS(string a,string b){
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

    int i = a.length(),j = b.length();
    string str;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            str.push_back(a[i-1]);
            i--,j--;
        }
        else{
            if(dp[i][j-1] > dp[i-1][j]) j--;
            else i--;
        }
    }
    reverse(str.begin(),str.end());
    return str;
    
} 

 
int main(){
    string a = "acbcf";
    string b = "abcdaf";
    cout<<printLCS(a,b)<<endl;
 
    return 0;
}