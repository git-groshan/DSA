#include<bits/stdc++.h>
using namespace std;
/**
 * Longest Subarray of sum K
 * array size : 7 
 * array: [4,1,1,1,2,3,5]
 * K : 5
 * subarray of sum 5 are [4,1] [5] , [2,3] [1,1,1,2]
 * Output : 4 (longest subaraay of sum 5 is [1,1,1,2])
*/

// Below code will only work for array having positive elements only
int largestSubArrayOfSumK(vector<int>&v , int k){
    int i = 0 , j = 0;
    long long int curSum = 0;
    int lengthOfMaxSubaary= INT_MIN;

    while(j<v.size()){
        curSum+=v[j]; // adding current element into current sum
        if(curSum<k)j++; // increasing window size if current sum is less than requires sum i.e K
        else if(curSum == k) {
        lengthOfMaxSubaary = max(lengthOfMaxSubaary , j-i+1); // j-i+1 = length of window = length of subarray 
        j++;// now add next element in the window 
        }
        else if(curSum > k){
            while(curSum > k){ // removing element while our current sum comes in range <= K
                curSum -= v[i];
                i++;
            }
            j++; // now add the next element in window 
        }


    }
    return lengthOfMaxSubaary;
}

int main(){
    vector<int>v = {4,1,1,1,2,3,5};
    int k = 5;
    int n = v.size();
    cout<<largestSubArrayOfSumK(v , k)<<endl;
    vector<int>v1 = {-5,8,-14,2,4,12}; int k1 = -5;
    cout<<largestSubArrayOfSumK(v1 , k1); 
return 0;
}