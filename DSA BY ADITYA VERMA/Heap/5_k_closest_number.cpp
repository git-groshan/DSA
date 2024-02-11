#include<bits/stdc++.h>
using namespace std;

/*
arr[]: 5,6,7,8,9
k=3
x=7;
find k number which are closer to x
Approach :
AbsdiffArray = 2,1,0,1,2  --> diffArray[i] = abs(arr[i] - k)
sorting on the basis of diff array 
0,1,1,2,2
7,6,8,5,9 --> ans = [7,6,8]

In Heap we always pop the useless , and store the kaam ka chiz in Heap from where we can get our answer 
Since we have to store the minDiff element and pop out maxDIff element hence we will store it in minHeap

*/

vector<int> kClosestNumber(vector<int>&v , int k , int x ){
    priority_queue<pair<int,int>>maxHeap;// {abs(v[i]-x) , v[i]}
    int i=0;
    vector<int>ans;
    while(i<v.size()){
        maxHeap.push({abs(v[i]-x) , v[i]});
        if(maxHeap.size() > k) maxHeap.pop();
        i++;
    }
    while(maxHeap.size()>0){
        auto pr = maxHeap.top();
        ans.push_back(pr.second);
        maxHeap.pop();
    }
    return ans;
}

int main(){
    vector<int>v={5,6,7,8,9};
    int k=3 , x = 7;
    vector<int>ans = kClosestNumber(v,k,x);
    for(int x:ans) cout<<x<<" ";
return 0;
}