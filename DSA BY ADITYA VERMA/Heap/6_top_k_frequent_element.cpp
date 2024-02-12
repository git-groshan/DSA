#include<bits/stdc++.h>
using namespace std;

/*
arr[] = [1,1,1,3,2,2,4]
mapping = {[1,3] ,[3,1][2,2],[4,1] } // number vs freq 
we need to store the max freq element in heap and pooped out minfreq element hence we use minHeap
as we have to pop out min element

*/
typedef pair<int,int> Pair;
vector<int> topKFrequentElement(vector<int>&v , int k){
    vector<int>ans;
    unordered_map<int,int>um;
    priority_queue<Pair,vector<Pair>,greater<Pair>>minHeap;
    for(int x:v)um[x]++;
    int i=0;
    for(auto &pr : um){
        int val = pr.first;
        int freq = pr.second;
        minHeap.push({freq,val});
        if(minHeap.size() > k)minHeap.pop();
    }

    while ((minHeap.size()>0))
    {
        /* code */
        Pair pr = minHeap.top();
        int freq = pr.first;
        int val = pr.second;
        ans.push_back(val);
        minHeap.pop();
    }

    return ans;
    
}
int main(){
        vector<int>v={1,1,1,3,2,2,4};
        int k = 2;
        vector<int> kfreqEle = topKFrequentElement(v,k);
        for(int x:kfreqEle) cout<<x<<" ";
return 0;
}