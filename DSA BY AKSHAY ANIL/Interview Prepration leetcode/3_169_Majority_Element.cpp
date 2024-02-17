#include<bits/stdc++.h>
using namespace std;

/*
Majority Element is the element which appears more than n/2 times in array 
Logic :  for each bit position check the count of 1's if it is greater than n/2 then that bit will contribute in answer 
*/

int main(){

vector<int>nums = {1,2,3,3,4,4,4,4,4};
int ans = 0;
for(int i=0;i<32;i++){
    int count = 0;
    for(int x:nums){
        if((x & (1<<i)) != 0) count++;
    }
    if(count > nums.size()/2) ans|=(1<<i);

}
cout<<"Majority element is "<<ans<<endl;

return 0;
}