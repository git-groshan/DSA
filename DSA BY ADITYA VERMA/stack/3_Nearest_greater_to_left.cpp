#include<bits/stdc++.h>
using namespace std;
/*
arr=[1,3,2,4]
output=[-1,-1,3,-1]
BruteForce : for(i=0;i<n;i++){
    for(j-i-1;;j>=0;j--) // j is dependent on i 
}
*/

vector<int> nextGreaterToLeft(vector<int>&arr){
    stack<int>st;
    vector<int>ans;

    // traverse from left to right 
    for(int i=0;i<arr.size();i++){ // THAT'S THE ONLY CHANGE FROM PREVIOUS CODE 
        // if stack is empty means no greater element in left
        if(st.empty()) ans.push_back(-1);
        // else if stack is not emmpty and st.top() > arr[i]
        else if(!st.empty() and st.top()>arr[i]){
            ans.push_back(st.top());
        } 
        // else if stack is not empty and st.top()<=arr[i]
        else if(!st.empty() and st.top()<=arr[i]){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }

            if(st.empty()) ans.push_back(-1);
            else if(st.top()>arr[i])ans.push_back(st.top());
        }
        st.push(arr[i]);
    }
    return ans;
}
int main(){

    vector<int>arr={1,3,2,4};
    vector<int>NGE_left = nextGreaterToLeft(arr);
    for(int x:NGE_left)cout<<x<<",";

return 0;
}