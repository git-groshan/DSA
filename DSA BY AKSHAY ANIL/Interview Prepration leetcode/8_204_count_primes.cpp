#include<bits/stdc++.h>
using namespace std;


int  sieveAlgo(int n ){
    vector<bool> isPrime(n+1 , true);
    isPrime[0] = isPrime[1] = false;

    for(int i=2;i<=n;i++){
        if(isPrime[i]==true){
        for(int j=2*i; j<=n; j+=i){
            isPrime[j] = false;
        }
    }

    }
    int primeCount =0;
        // we have to count prime numbers strictly less than n
        for(int i=0;i<n;i++){
            if(isPrime[i]) primeCount++;
        }
        return primeCount;
}

int  sieveAlgoOptimised(int n ){
    vector<bool> isPrime(n+1 , true);
    isPrime[0] = isPrime[1] = false;

    for(int i=2;i*i<=n;i++){
        if(isPrime[i]==true){
        for(int j=i*i; j<=n; j+=i){
            isPrime[j] = false;
        }
    }

    }
    int primeCount =0;
        // we have to count prime numbers strictly less than n
        for(int i=0;i<n;i++){
            if(isPrime[i]) primeCount++;
        }
        return primeCount;
}

 
int main(){

    int n = 10;
    cout<<"No of prime in between 1 to "<<n<<" is "<<sieveAlgo(n)<<endl;
    cout<<"Optimised No of prime in between 1 to "<<n<<" is "<<sieveAlgoOptimised(n);

return 0;
}