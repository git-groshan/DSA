#include<bits/stdc++.h>
using namespace std;
/*
// we have to find the nearest smaller in the right 
arr: [1,3,2,4]
Output: [2,2,-1,-1]
Similar to the nearest greater element to the right , we have to find the nearest smaller to the right
steps: 1. traverse from right to left 
        2. if stack is empty --> ans.push_back(-1);
        else if st.top() <arr[i] --> ans.push_back(st.top())
        else if st.top() >= arr[i] --> while(!st.empty() && st.top()>=arr[i]) st.pop()
            if(st.empty()) ans.push_back(-1)
            else if(st.top() <arr[i]) ans.push_back(st.top());
*/

vector<int> nearestSmallerElementToRight(vector<int>arr){
    stack<int>st;
    vector<int>ans;
    for(int i=arr.size()-1;i>=0;i--){
        if(st.empty()) ans.push_back(-1);
        else if(!st.empty() and st.top() < arr[i])ans.push_back(st.top());
        else if(!st.empty() and st.top()>=arr[i]){
            while(!st.empty() and st.top()>=arr[i]){
                st.pop();
            }
            if(st.empty())ans.push_back(-1);
            else if(st.top()<arr[i])ans.push_back(st.top());
        }
        st.push(arr[i]);
    }
    reverse(ans.begin() , ans.end());
    return ans;
}
int main(){

    // vector<int>arr={1,3,2,4};
    vector<int>arr={4,5,2,10,8};
    vector<int>ans=nearestSmallerElementToRight(arr);
    for(int x:ans)cout<<x<<" ";
return 0;
}