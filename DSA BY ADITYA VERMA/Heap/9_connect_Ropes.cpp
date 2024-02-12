#include<bits/stdc++.h>
using namespace std;

/*
Given an array of size n  which represent length of ropes
Minimise to cost to connect the ropes 
cost of connection two ropes = sum of length of those 2 ropes  

The mini cost would come only when we connect the ropes with min length
Hence we will use minHeap here 
*/

long long int minCostConnectingRopes(vector<int>&ropes){
    priority_queue<int,vector<int>,greater<int>>minHeap;
    long long int cost =0;
    for(int x :ropes) minHeap.push(x);
    while(minHeap.size() != 1){
        int firstMin = minHeap.top();
        minHeap.pop();
        int SecondMin = minHeap.top();
        minHeap.pop();
        int newLength = firstMin + SecondMin;

        cost+=(firstMin + SecondMin);
        minHeap.push(newLength);

    }
    cout<<"Length of rope "<<minHeap.top()<<endl;
    return cost;
}

int main(){
        vector<int>ropes = {1,2,3,4,5};
        cout<<"Min cost of joining all ropes "<<minCostConnectingRopes(ropes);

return 0;
}