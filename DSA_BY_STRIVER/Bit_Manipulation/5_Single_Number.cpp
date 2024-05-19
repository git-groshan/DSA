#include<bits/stdc++.h>
using namespace std;



int singleNumber(vector<int>&v){
    int ans = 0; // as xor of anything with 0 remains same 
    for(int x:v)ans^=x;

    return ans;

}
int main(){
    vector<int>v={1,2,3,4,1,2,3};
    cout<<"Single Number is "<<singleNumber(v);
return 0;
}