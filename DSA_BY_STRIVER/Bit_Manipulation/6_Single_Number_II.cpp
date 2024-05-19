#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        /*
        0^0=0 , 0^1=1 , 1^1=0;
        */
        int x = 0;
        for(int c:nums)x^=c;
        // get first set bit index in x cuz 0^1=1
        /*
        int i=0;
        for(;i<32;i++){
            if(x&(1<<i)==1) break;
        }
        */
        
        // we can also get set bit by num & ~(num - 1)
        x = x & ~(x - 1);
        // now partiton these array in 2 group where in one group ith bit is set bit and in another ith bit is unset
        int setBits = 0 , unsetBit=0;
        for(int val:nums){
            if(val & x) setBits^=val;
            else unsetBit^=val;
        }
        if(setBits>unsetBit) return {unsetBit , setBits};
        return {setBits,unsetBit};
    }
};


// all number 3 times and one is only once return that element

int SingleNumber_3(vector<int>&v)
{
    int ans = 0;
    for(int i=0;i<32;i++)
    {
        int setBitCount = 0;
        for(int x:v){
            if( x & (1<<i)) setBitCount++;
        }
        if(setBitCount % 3 == 1) ans |= (1<<i);
    }
    return ans;
}
/*
T.C = Nx32
S.C = O(1)
*/

int SingleNumber_3_sol2(vector<int>&v)
{
    int ans = 0;
    sort(v.begin() , v.end());

    for(int i=1;i<v.size();i+=3){
        if(v[i]!=v[i-1]) return v[i-1];
    }
    return v[v.size() - 1];
}
/*
T.C = NxlogN + N/3  --> which is better than previous 
S.C = O(1)
*/
// concept of  bucket 

int SingleNumber_3_sol3(vector<int>&v)
{
    int ones = 0 , twos = 0;
    for(int x:v){
        ones = (ones^x) & ~(twos);
        twos = (twos^x) & ~(ones);
    }
    return ones;
}
/*
T.C = NxlogN + N/3  --> which is better than previous 
S.C = O(1)
*/

int main(){

return 0;
}