#include<bits/stdc++.h>
using namespace std;

/*
Given a Number N , find xor of all from 1 to N

pattern 
N      xor            value

1    1^1                1
2    1^2                3
3    1^2^3              0
4    1^2^3^4            4

5    1^2^3^4^5          1
6   1^2^3^4^5^6         7
7    1^2^3^4^5^6^7      0
8   1^2^3^4^5^6^7^8     8

9   1^2^3^4^5^6^7^8^9         1
10  1^2^3^4^5^6^7^8^9^10      11
12  1^2^3^4^5^6^7^8^9^10^11    0
12  1^2^3^4^5^6^7^8^9^10^11^12  12

pattern is 
if N%4 == 1 then return 1
if(N%4==2) return N+1
if(N%4 == 3) return 0
if(N%4 == 0) return N




*/

int rangeXor(int n){
    if(n%4==1) return 1;
    else if(n%4 == 2) return n+1;
    else if(n%4 == 3) return 0;
    else if(n%4 == 0) return n;
}

int xorRangeFromL2R(int L , int R){
    int xorFrom1toL = rangeXor(L-1);
    int xorFrom1toR = rangeXor(R);

    return xorFrom1toL^xorFrom1toR;
}

int main(){


return 0;
}