#include<bits/stdc++.h>
using namespace std;

/*
Given a matrix of MxN , return no of paths from top left to bottom right
you can either mov to right or down

Input only M and N are given 
M [0 , 10^9]
N[0 ,10^9]

since we can only move right or down 
for eg. for 3x3 matrix 
possible combinations are 
RRDD , RDRD , RDDR , DRRD , DRDR , DDRR
this is just a possible comibination of 2 D and 2 R on 4 places 

4Cr 


fermet theorm is used here 
*/


long numberOfPaths(int m , int n ){
    long ans = 1;
    long mod = 1e9 +7;
    for(long i=n;i<=(n+m-2);i++){
        ans = (ans*i)%mod;
        long invert =modInv(i-n+1 , mod);
        ans = (ans*invert)%mod;
    }
    return ans;
}

long pow(long x , long y , long mod){
    long res = 1;
    while(y>0){
        if(y%2!=0) res = (res*x)%mod;

        y=y/2;
        x = (x*x)%mod;
    }
    return res;
}

long modInv(long n , long mod){
    return pow(n , static_cast<int>(mod -2) , mod);
}
int main(){

return 0;
}