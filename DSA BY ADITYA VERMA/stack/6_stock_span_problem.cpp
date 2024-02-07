#include<bits/stdc++.h>
using namespace std;
/*

arr: 100 ,80,60,70,60,75,85
output: -1 , 1, 1, 2, 1, 4,6   ---> consecutive smaller or equal before it

Given an array of size n which represent stock price at ith day
return the no stock price which is consecutively smaller or equal to current price at ith day 

********THIS PROBLEM IS ACTUALLY AN VARIATION OF NEAREST GREATER TO IT'S LEFT PROBLEM #####################
to get the length we need to find the index of nearest greater to it's left subtract that index with i to get the length 

*/

vector<int> stockSpan(vector<int>&stockPrice){
    vector<int>ans;
    vector<int>nge_left_indices;
    stack<pair<int,int>>st;// to store NGE and it's index 
    for(int i=0;i<stockPrice.size();i++){
        if(st.empty()) ans.push_back(1);
        else if(!st.empty() && st.top().first > stockPrice[i]) ans.push_back(i - st.top().second);
        else if(!st.empty() && st.top().first<=stockPrice[i]){
            while(!st.empty() && st.top().first<=stockPrice[i]){
                st.pop();
            }
            if(st.empty()) ans.push_back(-1);
            else if(st.top().first > stockPrice[i]) ans.push_back(i - st.top().second);
        }
        st.push({stockPrice[i] , i});
    }
    return ans;
}
vector<int> stockSpanAV(vector<int>&stockPrice){
    vector<int>ans;
    vector<int>nge_left_indices;
    stack<pair<int,int>>st;// to store NGE and it's index 
    for(int i=0;i<stockPrice.size();i++){
        if(st.empty()) nge_left_indices.push_back(-1);
        else if(!st.empty() && st.top().first > stockPrice[i]) nge_left_indices.push_back(st.top().second);
        else if(!st.empty() && st.top().first<=stockPrice[i]){
            while(!st.empty() && st.top().first<=stockPrice[i]){
                st.pop();
            }
            if(st.empty()) nge_left_indices.push_back(-1);
            else if(st.top().first > stockPrice[i]) nge_left_indices.push_back(st.top().second);
        }
        st.push({stockPrice[i] , i});
    }

    for(int i=0;i<stockPrice.size();i++) ans.push_back(i-nge_left_indices[i]);
    return ans;
}


int main(){
    vector<int> v= { 100 ,80,60,70,60,75,85};
    // vector<int>ans = stockSpan(v);
    vector<int>ans = stockSpanAV(v);
    for(int x:ans) cout<<x<<" ";

return 0;
}