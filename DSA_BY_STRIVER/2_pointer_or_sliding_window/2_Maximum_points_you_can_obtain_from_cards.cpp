#include<bits/stdc++.h>
using namespace std;

/*
Problem statement
Given an array 'arr' of size 'N' representing the points associated with each card,
and an integer 'K' representing the number of cards to be taken.
We need to return the maximum score that can be obtained.



In each step, we can choose to take one card from either the beginning or the end of the row.
 We must take exactly ‘K’ cards. The score is calculated as the sum of the points of the cards chosen.



For Example:
Input:
7 4
9 7 5 3 2 1 8

Output: 
29

Explanation:
Line 1: Contains ‘N’=7 and ‘K’=4
Line 2: Contains an array ‘arr’ of size 7.

arr=[9,7,5,3,2,1,8]

First step (K=1): we select 9 from the beginning so sum=9.

Second step (K=2): we select 8 from the end so sum= 9+8.

Third step (K=3): we select 7 from the beginning so sum=9+8+7.

Fourth step (K=4): we select 5 from the beginning so sum=9+8+7+5= 29.
*/

int maxPoint(vector<int>&arr , int k){

    /*
    int i=0 , j = arr.size() - 1;
    int maxScore = 0;
    while(i<j && k>0){
        if(arr[i] > arr[j]){
            maxScore += arr[i];
            i++;
        }
        else{
            maxScore+=arr[j];
            j--;
        }
        k--;
    }
    return maxScore;
    // The above code is wrong 
    */

   int leftSum = 0 , rightSum = 0;
   int maxSum = INT_MIN;
   for(int i=0;i<k;i++) leftSum+=arr[i];
   maxSum = max(maxSum , leftSum + rightSum);
   int i=k-1 , j=arr.size() - 1;
   while(i >= 0){
    leftSum -= arr[i];
    rightSum += arr[j];
    i--;
    j--;
    maxSum = max(maxSum , leftSum + rightSum);
   } 
   return maxSum;

}
// The above logic is totally wrong 
// What if all the k element in left or in right forms a maxScore ? 


int main(){

return 0;
}