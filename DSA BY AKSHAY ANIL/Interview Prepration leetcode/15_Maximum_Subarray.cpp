#include<bits/stdc++.h>
using namespace std;

int maximumSubarraySum(vector<int>&v){
    int maxi = INT_MIN;
    int sum = 0;

    for(int x: v){
        sum+=x;
        maxi = max(sum , maxi);
        if(sum<0){
            sum = 0;
        }
    }
    return maxi;
}

int main(){
    // vector<int>v={-2,1,-3,4,-1,2,1,-5,4};
    vector<int>v={5,4,-1,7,6};
    cout<<"Maximum Subarray sum is "<<maximumSubarraySum(v)<<endl;
return 0;
}