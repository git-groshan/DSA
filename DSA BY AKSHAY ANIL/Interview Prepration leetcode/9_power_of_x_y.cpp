#include<bits/stdc++.h>
using namespace std;


long long int  binaryExponentiation(int x , int y){
    if( y==0) return 1;

    if(y%2==0) return binaryExponentiation(x,y/2)*binaryExponentiation(x,y/2);
    else return x*binaryExponentiation(x , y/2)*binaryExponentiation(x , y/2);

}

const int mod = 1e9 + 7;
long long power(int a , int b)
{
    if(a==0) return 0;
    if(b==0) return 1;
    long long int ans = 0;
    if(b & 1){ // odd
        ans = a%mod;
        ans = (a*power(a , b-1)%mod)%mod;
    }
    else{
        ans  = power(a , b/2);
        ans = (ans%mod*ans%mod)%mod;;
    }
    return ans%mod;
}


int main(){
int a = 2 , b = 3;
cout<<a<<"to the power "<<b<<" is "<<binaryExponentiation(a,b)<<endl;
cout<<a<<"to the power "<<b<<" is "<<power(a,b)<<endl;

return 0;
}