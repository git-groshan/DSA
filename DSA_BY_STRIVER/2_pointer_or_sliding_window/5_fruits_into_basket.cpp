#include<bits/stdc++.h>
using namespace std;
/*
Fruite into basket 

Given 2 basket , There are n tree which represented by index , 
which produces fruit type arr[i] , you need to collect fruits in basket Given that 
basket can contain only one type of fruits 

Brute Force -
- generate all subarrays

for(int i=0;i<n;i++){
    set<int>st;
    for(int j=i;j<n;j++){
        st.insert(arr[i]);
        if(st.size() <=2 ){
            ans = max(ans , j-i+1);
        }
        else{
            break;
        }
    }
}
T.C = O(N^2)
S.C = 

*/
/*
In short we have to find the max window having k=2 , unique numbers 
*/

int findMaxFruits_myCode(vector<int> &arr, int n) {
    // Write your code here.
    unordered_map<int,int>um;
    int i=0 , j= 0 ;
    int ans = 0;
    while(j<n){
        um[arr[j]]++;
        if(um.size() <= 2){
            ans = max(ans , j-i+1);
        }
        else if(um.size() > 2){
            while(um.size() > 2){
                um[arr[i]]--;
                if(um[arr[i]] == 0) um.erase(arr[i]);
                i++;
            }
        }
        j++;
    }
    return ans;
}

int findMaxFruits_striver(vector<int>&nums , int k){
    int l=0 , r= 0 , maxLen = 0;
    unordered_map<int,int>um;
    while(r < nums.size()){
        um[nums[r]]++;
        if(um.size() > k){
            while(um.size() > k){
            um[nums[l]]--;
            if(um[nums[l]] == 0) um.erase(nums[l]);
            l++;
            }
        }
        if(um.size() <= k){
            maxLen = max(maxLen , r-l+1);
        }
        r++;

    }
    return maxLen;
}
/*
T.C = O(N + N)  3,3,3,1,2
S.C = O(3)
*/

// Lets' optimised it 
/*
At every instance of window we will check if it is a possible candidate for answer or not 
if yes then simply move r for other possible candiate 
if not then we will keep our window fixed by moving l++ and r++
*/

int maxFruitBasket_optimised(vector<int>&nums , int k){
    int l=0 , r=0 , maxLen = 0;
    unordered_map<int,int>um;
    while(r < nums.size()){
        um[nums[r]]++;

        if(um.size() > k){
            um[nums[l]]--;
            if(um[nums[l]] == 0) um.erase(nums[l]);
            l++;
        }
        if(um.size() <= k){
            maxLen = max(maxLen , r-l+1);
        }
        r++;
    }
    return maxLen;
}

int maxFruitBasket_optimised_2(vector<int>&nums , int k){
    int l=0 , r=0 , maxLen = 0;
    unordered_map<int,int>um;
    while(r < nums.size()){
        um[nums[r]]++;
        // if condition sequence is changed but it won't affect still we will get our right answer
        if(um.size() <= k){
            maxLen = max(maxLen , r-l+1);
        }
        if(um.size() > k){
            um[nums[l]]--;
            if(um[nums[l]] == 0) um.erase(nums[l]);
            l++;
        }
        r++;
    }
    return maxLen;
}


int main(){

return 0;
}