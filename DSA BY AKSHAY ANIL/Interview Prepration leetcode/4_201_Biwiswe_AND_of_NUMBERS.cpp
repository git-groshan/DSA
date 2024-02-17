#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

/*
Brute force will be give TLE 
Logic-   5 --> 1 0 1
         6 --> 1 1 0
         7---> 1 1 1
         -------------
                0  1  1   

    starting from 0th bit we will continue to traverse to the bit idx where all bits are same 
    this will be final destination

*/
    int rangeBitwiseAnd(int left, int right) {
        // 1&0 = 0 , 1&1 = 1 --> 1&num = num;
        // 0^0 = 0 , 0^1 = 0 ==> 0^num = 0;
        int ct=0;
        while(left != right){
            left >>=1;
            right>>=1;
            ct++;
        }

        return left<<ct; // right<<c;
        
    }
};
int main(){

return 0;
}