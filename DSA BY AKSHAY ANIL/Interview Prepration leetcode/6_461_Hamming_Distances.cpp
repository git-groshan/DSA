#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int hammingDistance(int x, int y) {

        int ct=0;
        while(x>0 || y>0){
            if((y&1) != (x&1)) ct++;
            x>>=1;
            y>>=1;
        }
        return ct;
        
    }
};
int main(){

return 0;
}