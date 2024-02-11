#include<bits/stdc++.h>
using namespace std;
/*
arr[]: 7,10,4,3,20,15
k=3
sorted arr[]: 3,4,7,10,15,20  --> O(nlog(n))

Identification :  K and smallest is given in question hence heap question 

In maxHeap we will keep on pushing element while size <=k if size >k keep poping out the element 
at the end of array traversal maxHeap will store the k smallest element where the kth smallest will be at top.

*/

int getKthSmallestElement(vector<int>&v , int k){
    int n = v.size();
    priority_queue<int>maxHeap;
    int i=0;

    while(i<n){
        maxHeap.push(v[i]);
        if(maxHeap.size() > k) maxHeap.pop();
        i++;
    }
    return maxHeap.top();
}

int main(){
    vector<int>arr = {7,10,4,3,20,15};
    int k = 1;
    cout<<"Kth Smallest Element is "<<getKthSmallestElement(arr,k);
return 0;
}