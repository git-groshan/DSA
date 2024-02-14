#include<bits/stdc++.h>
using namespace std;

/*
Given an array where each element is occure twice except for one element
return that element 
1. Brute force -- > O(n^2)
2. Hash Map --> T.C =  O(n) S.C = O(n)
3. Bitwise implementation - > O(n) O(1)
*/
int main(){
    vector<int>nums = {1,2,2,3,1};
    int ans = 0; // 0^1 = 1 0^0 = 0  --> means zor with 0^num = num
    // 1^1 = 0 , 0^0 = 0 --> same element zor is equal to 0 
    for(int x:nums)ans^=x;
    cout<<"Non repeating element is "<<ans;
return 0;
}