#include<bits/stdc++.h>
using namespace std;


/*
1004. Max Consecutive Ones III
Medium
Topics
Companies
Hint
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length

*/

/*
Return maxConesecutive ones , u r allowed to flip atmost k 0's

arr[] = [1,1,1,0,0,0,1,1,1,1,0]  k = 2

Brute Force - The Ques can be converted as LONGEST SUBARRAY WITH AT MOST K ZEROS
Generate all subarray and figure out the longest subaaray with at most  k 0



maxLen = 0
for(int i=0;i<arr.size();i++){
    int numZeros = 0;
    for(int j=i;j<n;j++){
        if(arr[j] == 0)numZeros++;
        if(numZeros < k) maxLen= max(maxLen , j-i+1);
        else break;
    }
}

T.C = O(N^2) , S.C = O(1);

*/


int maxConsecutiveOnes_striver(vector<int>&nums , int k)
{
    int maxLen = 0 , l = 0 , r= 0, zeros = 0;

    while( r < nums.size())
    {
        if(nums[r] == 0) zeros++;

        while(zeros > k){
            if(nums[l] == 0) zeros--;
            l++;
        }
        if(zeros <= k){
        maxLen = max(maxLen , r-l+1);
        }
        r++;
    }

}
/*
T.C = O(N) + O(N)
S.C = O(1)
*/

int maxConsecutiveOnes_striver_optimised(vector<int>&nums , int k)
{
    /*Earlier we were trimming the window untill we have zeros <= k which in worst case taking O(N)
    To counter this , what we will do  is , if we encounter zeros > k
    we will keep our window length as it is i.e move l to l+1 and r to r+1
    */
   int l = 0 , r=0 , n = nums.size();
   int maxLen = 0;
   int zeros = 0;

   while( r < n){
        if(nums[r] == 0) zeros++; // zeros += !nums[r]
        if(zeros > k)
        {
            if(nums[l] == 0) zeros--;
            l++;
        }
        if(zeros <= k)
        {
            maxLen = max(maxLen , r-l+1);
        }

        r++;

   }
   return maxLen;

}
/*
T.C = O(N)
S.C = O(1)
*/

class Solution {
public:


    /*
    If we think reverse of the question then we only need to find the maxLength subarray of with atmost K zeros.
    So , to find that we can use sliding window technique
    
    */
    int longestOnes_leetcode(vector<int>& nums, int k) {
        int i=0 , j=0 , n = nums.size();
        int zeros = 0;
        int maxLen = 0;

        while( j < n)
        {

            if(nums[j] == 0) zeros++;
            if(zeros <= k){
                maxLen = max(maxLen , j-i+1);
            }
            else if(zeros > k){
                while(zeros > k){
                    if(nums[i] == 0) zeros--;
                    i++;
                }
            }
            j++;
        }

        return maxLen;
        
    }
};

int maxConecutiveOnesIII(vector<int>&v , int k){

}
int main(){

return 0;
}