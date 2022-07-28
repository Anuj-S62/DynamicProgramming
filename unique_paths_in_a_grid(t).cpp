#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int solve(vector<vector<int>> &arr,int i,int j){
    if(i==0 && j==0 && arr[i][j]==0) return 1;
    else if(i<0 || j<0 ||arr[i][j]==1) return 0;
    else return solve(arr,i-1,j) + solve(arr,i,j-1);
}

int uniquePathsWithObstacles(vector<vector<int> > &A){
    return solve(A,A.size()-1,A[0].size()-1);
}

 
int main(){
    vector<vector<int>> arr = {
  {0, 0},
  {0, 0},
  {0, 0},
  {1, 0},
  {0, 0}
    };
    cout<<uniquePathsWithObstacles(arr)<<endl;
 
 
    return 0;
}