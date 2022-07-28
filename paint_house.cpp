#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void disp(vector<int> arr){
    for(int i:arr) cout<<i<<" ";
    cout<<endl;
}

void disp(vector<vector<int>> arr){
    for(auto i:arr){
        disp(i);
    }
}

int paint(vector<vector<int>> &arr,int x,int y,vector<vector<int>> &dp){
    if(dp[y][x]!=-1) return dp[y][x];
    if(y==0) return 0;
    int ans = INT_MAX;
    if(x==2) return dp[y][x] = arr[y-1][x] + min(paint(arr,0,y-1,dp),paint(arr,1,y-1,dp));
    else if(x==1) return dp[y][x] = arr[y-1][x] + min(paint(arr,0,y-1,dp),paint(arr,2,y-1,dp));
    else if(x==0) return dp[y][x] = arr[y-1][x] + min(paint(arr,1,y-1,dp),paint(arr,2,y-1,dp));
    return ans;
}

int solve(vector<vector<int> > &A) {
    vector<vector<int>> dp;
    vector<int> temp(4,-1);
    for(int i = 0;i<A.size()+1;i++) dp.push_back(temp);
    for(int i = 0;i<4;i++) {
        dp[0][i] = 0;
        dp[1][i] = A[0][i];
    }
    int ans = INT_MAX;
    for(int i = 0;i<3;i++){
        ans = min(ans,paint(A,i,A.size(),dp));
    }
    return ans;
}


int main(){
    vector<vector<int>> arr = {
  {468, 335, 501}
  ,{170, 725, 479}
  ,{359, 963, 465}
  ,{706, 146, 282}
  ,{828, 962, 492}
  ,{996, 943, 828}
  ,{437, 392, 605}
  ,{903, 154, 293}
  ,{383, 422, 717}
  ,{719, 896, 448}
  ,{727, 772, 539}
  ,{870, 913, 668}
  ,{300, 36, 895}
  ,{704, 812, 323}
  ,{334, 674, 665}
  ,{142, 712, 254}
  ,{869, 548, 645}
  ,{663, 758, 38}
  ,{860, 724, 742}
  ,{530, 779, 317}
  ,{36, 191, 843}
  ,{289, 107, 41}
  ,{943, 265, 649}
  ,{447, 806, 891}
  ,{730, 371, 351}
  ,{7, 102, 394}
  ,{549, 630, 624}
  ,{85, 955, 757}
  ,{841, 967, 377}
  ,{932, 309, 945}
  ,{440, 627, 324}
  ,{538, 539, 119}
  ,{83, 930, 542}
  ,{834, 116, 640}
  ,{659, 705, 931}
  ,{978, 307, 674}
  ,{387, 22, 746}
  ,{925, 73, 271}
  ,{830, 778, 574}
  ,{98, 513, 987}
  ,{291, 162, 637}
  ,{356, 768, 656}
  ,{575, 32, 53}
  ,{351, 151, 942}
  ,{725, 967, 431}
  ,{108, 192, 8}
  ,{338, 458, 288}
  ,{754, 384, 946}
  ,{910, 210, 759}
  ,{222, 589, 423}
  ,{947, 507, 31}
};

    // vector<vector<int>> arr = {{1, 2, 3},
    //     {10, 11, 12}
    // };
    cout<<solve(arr);
 
    return 0;
}