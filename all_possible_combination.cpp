#include<bits/stdc++.h>
using namespace std;

void show(vector<string> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swap(vector<int> &arr,int l,int i){
    int temp=arr[i];
    arr[i]=arr[l];
    arr[l]=temp;
}

void permutation(vector<int> &arr,int l,int r,vector<vector<int>> &res){
    if(l==r){
        res.push_back(arr);
        return;
    }
    for(int i=l;i<arr.size();i++){
        swap(arr,l,i);
        permutation(arr,l+1,r,res);
        swap(arr,l,i);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> res;
    permutation(A,0,A.size()-1,res);
    return res;
}


int main(){
    vector<string> arr={"ab","cd"};
    specialStrings(arr);

    return 0;
}