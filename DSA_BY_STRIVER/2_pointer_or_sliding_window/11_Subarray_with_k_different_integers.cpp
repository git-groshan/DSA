#include<bits/stdc++.h>
using namespace std;

/*
992. Subarrays with K Different Integers
Solved
Hard
Topics
Companies
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length

*/

/*
In the problems where we have to find the length of max/min subarray with sum =k or <k or >k 
We can directly apply sliding window accroding 
But when the problem is to find the number of subarray 
then we are delima when to shrink the array. 
So what we do is , we try to find all the possible subrray with holds condition like 
sum <=k then to get the sum == k we subtract the all possible array which has sum < k to get the exact no of subarray with sum == k

*/

int numsubarrayWhereNumIntegersLessThanK(vector<int>&nums , int k){
    int l=0 , r=0 , ans = 0;

    unordered_map<int,int>um;

    while(r < nums.size()){
        um[nums[r]]++;

        while(um.size() > k){
            um[nums[l]]--;
            if(um[nums[l]] == 0) um.erase(nums[l]);
            l++;
        }
        // got our valid subarray 
        // total possible subarray with goal <= k => length of subarray 
        ans+=(r-l+1);
        r++;
    }
    return ans;
}

// ####### LEETCODE SOLUTION  #######
 class Solution {
public:
    
    int countSubarraysWithAtMostKDistinct(vector<int>& nums, int k){
        int n=nums.size();
        
        unordered_map<int, int> mp;
        
        int i=0, j=0;
        
        int c=0;
        
        while(j<n){
            mp[nums[j]]++;
            
            while(i<=j && mp.size()>k){
                if(--mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            
            c += (j-i+1);
            
            j++;
        }
        
        return c;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countSubarraysWithAtMostKDistinct(nums,k)-countSubarraysWithAtMostKDistinct(nums,k-1);
    }
};


int main(){

return 0;
}