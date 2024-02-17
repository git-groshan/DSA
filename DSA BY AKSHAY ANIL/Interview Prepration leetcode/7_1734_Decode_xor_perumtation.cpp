
#include<bits/stdc++.h>
using namespace std;




class Solution {
public:

    /*
        a^b = c 
        b^c = a
        a^c = b
    */
    vector<int> decode(vector<int>& encoded) {
        // xor of a0,a1,a2,a3,a4 perm array the output array we want 
        int n = encoded.size()+1;
        int perm_xor = 0;
        for(int i=1;i<=n;i++){
            perm_xor^=i; // here we have xor of all the element present in permutatiom 
        }
        int enc_xor = 0;
        for(int i=1;i<encoded.size();i+=2){
            enc_xor^=encoded[i]; // except the first element here we have xor of all the rest element 
        }

        int a0 = perm_xor^enc_xor; // here we have got out first elemnt of perm array 

        vector<int>ans(n,0);
        ans[0] = a0;
        for(int i=1;i<n;i++) ans[i] = ans[i-1]^encoded[i-1]; // if a^b=c ==> b=a^c and a = b^C

          return ans;
    }

  
};

int main(){

return 0;
}