#include<bits/stdc++.h>
using namespace std;

/*
Given an array sort the array based on frequency 
arr[]: 1,1,1,3,2,2,4
output: 1,1,1,2,2,3,4
*/
static bool comp(pair<int,int>&a , pair<int,int>&b){
    int fr1 = a.first , fr2 = b.first;
    int val1 = a.second , val2 = b.second;
    if(val1 != val2) return fr1 > fr2;

    return val1>val2;
}
vector<int> frequencySort(vector<int>&v){
    unordered_map<int,int>um;
    vector<int>ans;

    for(int x:v)um[x]++;
    vector<pair<int,int>>vp;
    for(auto &pr : um)vp.push_back(pr);
    sort(vp.begin() , vp.end(),comp);
    for(auto &pr :vp){
        int val = pr.second , freq = pr.first;
        for(int i=0;i<freq;i++){
            ans.push_back(val);
        }
    }
    return ans;

}

vector<int> frequencySortUsingHeap(vector<int>&v){
    unordered_map<int,int>um;
    vector<int>ans;
    for(int x:v)um[x]++;
    // since we need to store the maxFreq element first , hence we will use maxHeap to store maxFreqEle at top
    priority_queue<pair<int,int>>maxHeap;
    for(auto &pr :um){
        int val = pr.first;
        int freq = pr.second;
        maxHeap.push({freq,val});
    }
    while (!maxHeap.empty())
    {
        auto pr = maxHeap.top();
        int freq = pr.first , ele = pr.second;
        for(int i=0;i<freq;i++)ans.push_back(ele);
        maxHeap.pop();
    }
    return ans;


}
int main(){
    vector<int>v={1,1,1,3,2,2,4};
    // vector<int> ans = frequencySort(v); // need to be modify as giving wrong answer 
    vector<int> ans = frequencySortUsingHeap(v);
    for(int x:ans) cout<<x<<" ";
return 0;
}