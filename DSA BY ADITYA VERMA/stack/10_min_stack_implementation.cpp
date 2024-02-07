#include<bits/stdc++.h>
using namespace std;

/*
Stack gives us basic operation like push pop top
We have to implement the min operation which return min element in stack 

Appraoch : We will be using 2 stack for it . 1. stack 2. supporting stack 

while pushing element in the stack , we will  store the min element in supporing stack 
if any element which is smaller than supporting stack top element then push it also in the supporting stack 
if while popping element if it's value is same as supporting stack top then remove it also from the supporting stack
*/


stack<int>st; // stack  
stack<int>sst; // supporting stack 

void push(int a){
    st.push(a);
    if(sst.size() == 0 || a<=sst.top()) sst.push(a);
}

int pop(){
    if(st.size() == 0) return -1;
    int poppedElement = st.top();
    st.pop();
    if(poppedElement == sst.top()) sst.pop();
}
int getMin(){
    if(sst.size() == 0) return -1;
    return sst.top();
}
int main(){

return 0;
}