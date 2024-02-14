#include<bits/stdc++.h>
using namespace std;

/**
 Given an array , return sum of  elements between k1th and k2th smallest number in array 
 arr[]: 1,3,12,5,15,11
 k1 = 3
 k2 = 6

 sorted Arr: 1,3,5,11,12,25
 3rd smallest is 5 and 6th smallest is 15 
 Sum of element in between them = 11 + 12
 Approach : get those 2 number in nlogk
 traverse the array and check if(num>k1Smallest and num<k2Smallest) ans+=num
*/

int kthSmallestElement(vector<int>&v , int k){
    priority_queue<int>maxHeap;
    int i=0;
    while(i<v.size()){
        maxHeap.push(v[i]);
        if(maxHeap.size() > k)maxHeap.pop();
        i++;
    }
    return maxHeap.top();
}


int main(){

    vector<int>v={1,3,12,5,15,11};
    int k1 = 3 , k2 = 6;
    int k1thSmallest = kthSmallestElement(v , k1);
    int k2thSmallest = kthSmallestElement(v , k2);
    int sum = 0;
    for(int i=0;i<v.size();i++){
        if(v[i]>k1thSmallest and v[i]<k2thSmallest) sum+=v[i];
    }
    cout<<"Sum of elements in between is "<<sum<<endl;

return 0;
}