#include<bits/stdc++.h>
using namespace std;

int minElement;
stack<int>st;
void push(int a)
{
    if(st.size() == 0){
        st.push(a);
        minElement = a;
    }
    else{
        if(a>=minElement) st.push(a);
        else if(a<minElement){
            st.push(2*a - minElement);
            minElement = a;
        }
    }
}

void pop()
{
    if(st.size()==0) {
    cout<<"stack is empty";
    return;
    }
    else{
        if(st.top() >= minElement)st.pop();
        else if(st.top()<minElement){ // ambiguity
            minElement = 2*minElement - st.top();
            st.pop();
        }
    }
}

int top(){
    if(st.size()==0) return -1;
    else{
        if(st.top()>=minElement) return st.top();
        else if(st.top()<minElement) return minElement;
    }
}

int getMin(){
    if(st.size() == 0) return -1;
    return minElement;
}
int main(){

return 0;
}