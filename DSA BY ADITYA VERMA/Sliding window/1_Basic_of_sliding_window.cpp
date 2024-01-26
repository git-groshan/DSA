#include<bits/stdc++.h>
using namespace std;
/*
Problem: given an array and a number k 
return max sum subarray of size k
*/

/**
 * Identification of sliding problem 
 * 
 *  1. array /string with Subarray/Substring 
 *  2. largest/smallest 
 *  3. K= window size 
 * 
**/
/*
Types of sliding window 
1. fixed size window  - window size is fixed
2. variable size window - largest window / smallest window with sum condition 
*/

int maxSumSubarrayOfSizeK(vector<int>&nums , int k){
    int maxSum = INT_MIN;
    // i is start of window  and j is end of window
    int i = 0 , j = 0 , n = nums.size();
    int curSum = 0;
    while(j<n){
        // doing calculation which is need to be performed for every j 
        curSum += nums[j];
        // cur window size = j - i + 1
        if(j-i+1 < k) j++; // if window size is less than k simply increase 

        else if(j - i + 1 == k){ // size is equal to window size 
            maxSum = max(maxSum , curSum); // caluclate maxSum
            curSum -= nums[i]; // remove starting element 
            i++; // start of window shifted to next position 
            j++; // check for next element
        }
    }

    return maxSum;

}

// Approach 2 

long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        long curSum = 0 , maxSum = INT_MIN;
        for(int i=0;i<K;i++) curSum += Arr[i]; // storing sum of starting k element 
        maxSum =  max(maxSum , curSum); // storing maxSum 
        int startOfWindow = 0;
        for(int endOfwindow = K; endOfwindow<N; endOfwindow++){
            curSum-=Arr[startOfWindow];// removing starting element from current sum 
            curSum+=Arr[endOfwindow]; // adding next element in curSum
            maxSum = max(maxSum , curSum); // calculating max of window 
            startOfWindow++; // starting index moved to next element
        }
        return maxSum;
    }

int main(){

    vector<int>nums = {1,2,4,5,6,71,2};
    int k = 3;

    cout<<"Max sum subarray of size approach 1 "<<k<<" is "<<maxSumSubarrayOfSizeK(nums , k)<<endl;
    cout<<"Max sum subarray of size "<<k<<" is "<<maximumSumSubarray(k , nums, nums.size());

return 0;
} 