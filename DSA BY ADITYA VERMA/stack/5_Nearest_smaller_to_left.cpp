#include<bits/stdc++.h>
using namespace std;

// Nearest smaller to left / Nearest Smaller element 

/*
arr:[4,5,2,10,8]
output:[-1,4,-1,2,2]
BruteForce : for(int i=0;i<n;i++){
    for(int j=i-1;j>=0;j--) // dependent loop 
}
*/
vector<int> nearestElementToleft(vector<int>arr){
    stack<int>st;
    vector<int>ans;
    for(int i=0;i<arr.size();i++){ // that' the only change we need to do 
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
    return ans;
}
int main(){

    vector<int>arr={4,5,2,10,8};
    vector<int>ans = nearestElementToleft(arr);
    for(int x:ans) cout<<x<<" ";

return 0;
}