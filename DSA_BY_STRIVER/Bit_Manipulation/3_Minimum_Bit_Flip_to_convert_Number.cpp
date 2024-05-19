#include<bits/stdc++.h>
using namespace std;
/*
start = 10 positive integer goal =  7 
How many bit filp in start to get goal 

10 = 1010 
7 =  0111
total 3 bits required 

// 1^1 = 0 , 0^0 = 0 , 1^0 = 1 
10^7 = (1010) ^ (0111) = 1101 Here no of set bits in it will tell the no of flips required 
*/


int countSetBits(int a){
    int ct = 0;
    while(a!=0){
        ct++;
        a=a^(a-1); // clear last set bit 
    }
    return ct;
}
int countBitToBeFlipped(int start , int goal){
    int ans = start^goal;

    return countSetBits(ans);
}

int main(){

return 0;
}