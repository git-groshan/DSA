#include<bits/stdc++.h>
using namespace std;
/*
arr[]: 7,10,4,3,20,15
k=3
Output : 20,15,10

sorted arr: 3,4,7,10,15,20

Heap - k largest ---> minHeap (smallest element at top)

we will maintain a min Heap of size k 
keep on pushing element in the min Heap and if size of minHeap >k keep pooping out element 
untill size becomes <=k
This will ensure that in the end minHeap will be having k largest element in it because we have keep popping 
out n-k smallest element from the heap


*/

vector<int> k_largest_element_in_array(vector<int>&v,int k){
    int i=0 , n = v.size();
    vector<int>kLargestElement;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    while(i<n){
        minHeap.push(v[i]);
        if(minHeap.size()>k)minHeap.pop();
        i++;
    }
    while(minHeap.size()>0){
        int val = minHeap.top();
        minHeap.pop();
        kLargestElement.push_back(val);
    }
    return kLargestElement;
}

int main(){
    vector<int>arr={7,10,4,3,20,15};
    int k =3;
    vector<int>ans = k_largest_element_in_array(arr,k);
    for(int x:ans)cout<<x<<" ";
return 0;
}