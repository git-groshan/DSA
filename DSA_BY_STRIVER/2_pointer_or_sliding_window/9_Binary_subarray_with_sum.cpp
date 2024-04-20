#include<bits/stdc++.h>
using namespace std;

/*
930. Binary Subarrays With Sum
Solved
Medium
Topics
Companies
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 

Constraints:

1 <= nums.length <= 3 * 104
nums[i] is either 0 or 1.
0 <= goal <= nums.length

*/


/*
Logic - If we try to implement the sliding window here then we will be in delima situation whether to shrink or how much to shrink the window
So for that what we are doing here is 
total no subarray with sum K = total subarray with sum less than or equal to k  - total subarray with sum less than k 

we will write a function which will count subarray with sum less than k 
- To count subarrays with sum less than k we will pass k value as k-1

*/

int numberOfSubarraywithSumLessThanGoal(vector<int>&nums , int goal){
    int l=0 , r=0 , sum=0 , cnt=0;
    if(goal < 0) return 0;
    while(r<nums.size())
    {
        sum+=nums[r];

        while(sum > goal)
        {
            sum -= nums[l];
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

int numOfBinarySubarrayWithgoal(vector<int>&v , int k){

    return numberOfSubarraywithSumLessThanGoal(v , k) - numberOfSubarraywithSumLessThanGoal(v , k-1);
}


// ########## LEETCODE SOLUTION ###############

class Solution {
public:
/*
Since we need to find the subarray sum which boils down the problem into Find Range sum which can be done using 1. Prefix Sum 2. Spare sum 3.Fenwick Tree /Segment tree
Our requirement ps[j] - ps[i-1] = K => ps[i-1] = ps[j] - K = constant .Here ps is prefixSum array 
i.e Sum of  window of subarray from i to j should be K
To find the no of Subarray we just need to find the no of subarray whose value is ps[j] - K which is a constant value 
*/
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
};




int main(){

return 0;
}