#include<bits/stdc++.h>
using namespace std;

 long long int largestPrimeFactor(int N){
        // code here
        int n = 2;
        while(n*n<=N){
            if(N%n==0)N/=n;
            else n++;
        }
        return N;
    }
int main(){
    cout<<largestPrimeFactor(7)<<endl;
return 0;
}