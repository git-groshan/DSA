#include<bits/stdc++.h>
using namespace std;

/*

//https://leetcode.com/problems/count-number-of-nice-subarrays/description/

1248. Count Number of Nice Subarrays
Solved
Medium
Topics
Companies
Hint
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 

Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length
*/

/*
If we carefully look at the problem , it is the similar problem like count no of subarray with sum == goal in a binary array
if we consider odd numbers as 1 and even numbers as 0 
then this problem becomes similar to the problem we solved earlier.
*/


int numberOfSubarraywithSumLessThanGoal(vector<int>&nums , int goal){
    int l=0 , r=0 , sum=0 , cnt=0;
    if(goal < 0) return 0;
    while(r<nums.size())
    {
        sum+=(nums[r]%2);

        while(sum > goal)
        {
            sum -= (nums[l]%2);
            l++;
        }

        // total subarray = length of window
        cnt += (r-l+1);
        r = r+1;
    }
    /*
    T.C = O(N + N)
    S.C = O(1)
    */
}



// ############# LEETCODE SOLUTION #########

class Solution {
public:


     int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0 , prefSum = 0;
        unordered_map<int,int>freq; // to track no of freq of reuired subarray
        freq[0] = 1; // Empty subarray 
        for(auto ele : nums){
            prefSum += ele; // calculating prefSum = ps[j]
            // required ps[i-1] = prefSum - goal
            if(freq.find(prefSum - goal) != freq.end()){
                ans+=freq[prefSum - goal];
            }
            freq[prefSum]++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {

        for(int i=0;i<nums.size();i++){
            if(nums[i] & 1) nums[i] = 1;
            else nums[i] = 0;
        }

        return numSubarraysWithSum(nums , k);
        
    }
};



int main(){

return 0;
}