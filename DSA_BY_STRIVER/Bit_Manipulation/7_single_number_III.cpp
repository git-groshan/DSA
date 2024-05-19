#include<bits/stdc++.h>
using namespace std;

/*
Every number appears twice except two numbers which appears only once 
[2,4,2,6,3,7,7,3]

since 2 nos are distinct hence atleas 1 bit will be different in both


mask = (num & (num-1)) ^ num;
*/

vector<int> singleNumberIII(vector<int>&v){

    int firstbucket = 0 , secondbucket = 0;
    int totalXor = 0;
    for(int x:v)totalXor^=x;

    int mask = (totalXor & (totalXor-1))^totalXor; // this will create a mask for first set Bit like if in total xor 3rd bit is set then mask would be like 0000....1000
    // here we need to take care as totalXor -1 may over flow
    //[1,1,0,-2^31] , totalXor = -2^31 , totalXor - 1 = -2^31 -1 will overflow
    for(int x:v){
        if(x & mask) firstbucket^=x; // stores xor of element which has rightmost bit is set as same of mask 
        else secondbucket^=x;
    }
    return {firstbucket , secondbucket};
}

int main(){

vector<int>v = {2,4,2,6,3,7,7,3};
vector<int>ans = singleNumberIII(v);
cout<<ans[0]<<" "<<ans[1]<<endl;

return 0;
}