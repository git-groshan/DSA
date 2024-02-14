#include<bits/stdc++.h>
using namespace std;

/*
Given an array where each element is repeated thrice except one element which is only one time is present 
return that element.

Logic - Since the no is repeated thrice then it's bit will also repeated thrice 
So we will count the no of 1's at each bit position and take modular with 3
Here we won't consider no of 0's as they don't have any weightage and will not contribute in answe 
[2,2,3,2] --> 10 , 10, 11, 10 
0th bit place - no of 1's = 1 %3 = 1 hence it will contribute in answer 
1st bit place -> no of 1's = 4 % 3 = 1   '' '' 
*/
int main(){
    vector<int>nums = {2,2,3,2 , 5,5,5,6,6,6};
    int ans = 0;
    for(int i=0;i<32;i++){
        int countOf1bit = 0;
        for(int x:nums){
            if( (x & (1<<i) ) != 0) countOf1bit++;
        }
        if(countOf1bit % 3 != 0 ) ans|=(1<<i); // set that i'th bit to 1
        //if(countOf1bit % 3 != 0 ) ans += (1<<i); // adding (1<<i) value to the answer 
    }
    cout<<"Non repeating element is "<<ans;
return 0;
}