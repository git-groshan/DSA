#include<bits/stdc++.h>
using namespace std;

// Next largest element aka nearest greater to right

/*
arr[] = {1,3,2,4}
output: [3,4,4,-1] // 4 doesn't have element to it's right
arr[] = {1,3,0,0,1,2,4}
output: [3,4,1,1,2,4,-1]
Brute force 
for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){ // dependent loop 
        if(arr[j]>arr[i]) 
            ans[i] = arr[j];
            break;
        
    }
}

Approach : since we know , we can use stack which is LIFO in nature
for every arr[i] , we have to get just next greater element . so in stack it should be present at top 
so , for that we will traverse from end of array for every i so that we could ensure , next greater element must be at top
**** TO GET OUT ANS FIRST OUT , IT SHOULD BE INSERTED AT LAST ****
*/
/*
1. start traversing for right , if stack is empty then no greater element exist for that element
2. for an instance we will have  necessary right araay store in stack for arr[i]
3. 

stack.empty() ===> v.push_back(-1)
stack.top() > arr[i] ==> v.push(s.top())
stack.top() <= arr[i] ==> pop element while stack is not empty or stack.top() > arr[i]
*/

int main(){

    int arr[] = {1,3,2,4};
    int n = 4;
    vector<int>v; // to store the ans
    stack<int>st;

    // traverse from right to left 
    for(int i=n-1;i>=0;i--){
        // if stack is empty means no greater element in right side 
        if(st.empty()) v.push_back(-1);

        // if stack is not empty and it's top is greter than arr[i] , means we have found NGE in right of it 
        else if(!st.empty() and st.top()>arr[i]) v.push_back(st.top());

        // if stack is not empty and stack top is less than arr[i] then pop out it from stack 
        // repeate untill stack becomes eempty or we found stack top is greter than arr[i]
        else if(!st.empty() and st.top() <= arr[i]){
            while (!st.empty() and st.top()<=arr[i])
            {
                st.pop();// pop out means it can never contribut for NGE for rest of element because arr[i] is itself greter than these pooped element hence arr[i] can be MGE for furthers arr[i]
            }
            if(st.empty()) v.push_back(-1);
            else v.push_back(st.top());
        }

        st.push(arr[i]);// push elment in stack bcz if might be NGE for remianing element 
    }

    reverse(v.begin() , v.end());
    for(auto val:v) cout<<val<<" ";

return 0;
}