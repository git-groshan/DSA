#include<bits/stdc++.h>
using namespace std;
// Heap uses self balancing tree 
int KthLargestElementInArray(vector<int>&v , int k){
    priority_queue<int , vector<int> , greater<int>>minHeap;
    int i=0;
    int n = v.size();
    while(i<n){
        minHeap.push(v[i]);
        if(minHeap.size()>k)minHeap.pop();
        i++;
    }
    return minHeap.top();
}

/*
kth largest by akshay anil 

*/
int findKthLargestElement(vector<int>&nums , int k){
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<k;i++){
        pq.push(nums[i]);
    }
    for(int i=k;i<nums.size();i++){
        if(pq.top() < nums[i]){
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}
int main(){
    vector<int>v = {3,2,1,5,6,4};
    int k=3;
    cout<<k<<"th largest by AV appraoch "<<KthLargestElementInArray(v ,k)<<endl;
    cout<<k<<"th largest by AA appraoch "<<findKthLargestElement(v ,k)<<endl;
return 0;
}