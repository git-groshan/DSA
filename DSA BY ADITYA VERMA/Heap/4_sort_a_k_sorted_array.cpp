#include<bits/stdc++.h>
using namespace std;
/*
arr[]: 6,5,3,2,8,10,9
k=3
output : 2,3,5,6,8,9,10
sorted array is rotated by k or nearly sorted array 
*/

void SortAkSortedArray(vector<int>&v,int k){
    int n = v.size();
    priority_queue<int,vector<int>,greater<int>>minHeap;
    int i=0;
    int startIdx = 0;
    while(i<n){
        minHeap.push(v[i]);
        if(minHeap.size() > k){
            v[startIdx] = minHeap.top();
            minHeap.pop();
            startIdx++;
        }
        i++;
    }
    while(minHeap.size() > 0){
        v[startIdx] = minHeap.top();
        startIdx++;
        minHeap.pop();
    }
    
}
int main(){

    vector<int>v = {6,5,3,2,8,10,9};
    int k = 3;
    SortAkSortedArray(v,3);
    for(int x:v)cout<<x<<" ";
    
return 0;
}