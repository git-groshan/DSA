#include<bits/stdc++.h>
using namespace std;

/**
 560 Subarray sym Equal k 
 560. Subarray Sum Equals K
Medium
Topics
Companies
Hint
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
  
*/
/*
Approach 1 - Brute Force Find all subarray then find the sum of subarray O(N^2 * N)
Approach 2 - Simulatneoulsy find sum of subarray O(N^2)

Approach 3 - Sub Array Sum --> Find Range Sum 
Range Sum can be solved by 
1. Prefix Sum 2. Sparse Table 3. Fenwick Tree or Segment Tree 

nums = [1,2,3]
prefixSum = [1,3,6]  ps[i] = ps[i-1] + nums[i]

ps[j] - ps[i-1] = goal(i.e subarray of window i to j )
I'm at j right now  , find how many such  ps[i-1] are available which produces the goal.
We need to know how many ps[i-1] are available for cur j which produces are goal value.
ps[i-1] = ps[j] -  goal = constant 

nums = [0, 1, 0, 1, 0, 1]
ps = 0 [0, 1, 1, 2, 2, 3]
k = 2;
for j = 3 
psRequired = 2 - 2 = 0;


Eg- 
*/
class Solution {
public:
/*
Since we need to find the subarray sum which boils down the problem into Find Range sum which can be done using 1. Prefix Sum 2. Spare sum 3.Fenwick Tree /Segment tree
Our requirement ps[j] - ps[i-1] = K => ps[i-1] = ps[j] - K = constant .Here ps is prefixSum array 
i.e Sum of  window of subarray from i to j should be K
To find the no of Subarray we just need to find the no of subarray whose value is ps[j] - K which is a constant value 
*/
    int subarraySum(vector<int>& nums, int goal) {
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


// ####################################################

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


If we use 2 Pointer here 

By shrinking newSum <= Sum 
By Expanding newSum >= Sum 

Since no negative number are present in this array , there is a bit certainity 


No of Subarray with sum equal to goal = No of subarray wiht sum less than goal - No of subarrays with sum less than goal 


*/

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

/*
In case of negative number , It was confusing either we shrink/expand our Subarray , the sum will either increase/decrease .
Hence there were no certainity in case of negative element.
But Here in this , Having Binary Numbers ,
 In case of shrink our newSum <= sum
 In case of expand our newSum >= Sum

 Hence to find no of Subarray with sum==k
 No of Subarray with sum equal to k(goal) = No of Subarray with sum less than or equal to goal - No of Subarray with sum less than goal i,e <= goal -1


*/

int atMost(vector<int>&nums , int goal){
    int i=0 , j=0 , ans = 0, sum =0 , n = nums.size();

    while(j<n){
        sum+=nums[j];
        // if sum > goal shrink the window
        while(sum > goal && i<=j){
            sum-=nums[i];
            i++;// shrink the window
        }
        // total subarray on current window = j-i+1 hence add it in ans 
        ans+=(j-i+1);
        j++;// expand the window 
    }
    return ans;
}

int numSubarraysWithSum(vector<int>& nums, int goal){
    return atMost(nums , goal) - atMost(nums , goal - 1);
}



/*
Sliding window Vs 2 Pointer 
- 2 Pointer is Applicable When movement is directional i.e jis chiz pr focus krna h ques me woh monotonic function ho 
- Expand j at every step , compress i when sum becomes more than required.
- while(j<n){
    
    while(cond. > goal) i++;
    
    j++;

}

*/

int main(){

return 0;
}