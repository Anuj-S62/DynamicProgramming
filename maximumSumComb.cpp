#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
void disp(vector<int> arr){
    for(int i:arr) cout<<i<<" ";
    cout<<endl;
}

vector<int> solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    priority_queue<pair<int ,pair<int,int>>> pq;
    set<pair<int,int>> s;
    vector<int> ans;
    int n = A.size()-1;
    pq.push(make_pair(A[n] + B[n],make_pair(n,n)));
    s.insert(make_pair(n,n));
    while(ans.size()<C){
        auto p = pq.top();
        pq.pop();
        ans.push_back(p.first);
        int i = p.second.first;
        int j = p.second.second;
        if(i>0 && j>0 && s.find(make_pair(i-1,j))==s.end()){
            pq.push(make_pair(A[i-1] + B[j],make_pair(i-1,j)));
            s.insert(make_pair(i-1,j));
        }
        if(i>0 && j>0 && s.find(make_pair(i,j-1))==s.end()){
            pq.push(make_pair(A[i] + B[j-1],make_pair(i,j-1)));
            s.insert(make_pair(i,j-1));
        }
    }
    return ans;  
}
 
 
int main(){
    vector<int> a = { 59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83 };
    vector<int> b = {59, 63, 65, 6, 46, 82, 28, 62, 92, 96, 43, 28, 37, 92, 5, 3, 54, 93, 83 };
    vector<int> ans = solve(a,b,10);
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
 
    return 0;
}