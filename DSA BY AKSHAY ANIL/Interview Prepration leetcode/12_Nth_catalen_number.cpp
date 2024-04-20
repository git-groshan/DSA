#include<bits/stdc++.h>
using namespace std;
/*
Catalen sequence is 

The first few catalan number for N=0,1,2,3,... are 1,1,2,5,14,42,132,429,1430,4862
0 -> 1
1-> 1
2->2 == 2C0 * 2C2  + 2C1*2C2
3->5 ==  C0*C2 + C1*C1 + C2*C0 = 2+1+2
 

*/

long findCatelan(int n ){
     const int mod  = 1e9 +7;
    
    long dp[n+1];
    memset(dp , 0 , sizeof(dp));
    dp[0]= 1 ; dp[1] = 1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i] = ((dp[i] + dp[j]*dp[i-j-1])%mod)%mod;
        }
    }
    return dp[n];
}
int main(){
   int n = 6;
   cout<<n<<"th catalean number is "<<findCatelan(n)<<endl;

return 0;
}