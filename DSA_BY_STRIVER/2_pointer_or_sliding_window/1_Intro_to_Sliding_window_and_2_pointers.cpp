#include<bits/stdc++.h>
using namespace std;

/*
Types of Problems 
1. Constant window (window length is constant) / Fixed length window 
l=0 , r=0;
for(;r<k;r++) sum+=arr[r];
while(r < n-1){
    sum = sum - arr[l];
    l++;
    r++;
    sum = sum + arr[r];
    maxSum = max(maxSum , sum);
}

2. Longest Subarray / Substring where <condition>
- Variable size window 

Longest Subarray with sum <= k
arr = [2,3,1,7,10] k = 14
- Expands the windows till the conditions are met 
- Shrink the windows if conditions are not met

int l=0 , r=0 , sum = 0, maxLen = 0;
while(r < n){
    sum+=arr[r];
    while(sum > k && i <= j){
            sum-=arr[l];
            l++;
        }
    if(sum <= k) maxLen = max(maxLen , r-l+1);

    r++;
}
T.C = O( N + N)
S.C = O(1)


// Most Optimised (This will only work when we only need to find the length of Subarray )
int l=0 , r=0 , sum = 0, maxLen = 0;
while(r < n){
    sum+=arr[r];
    if(sum > k && i <= j){ // Since we have gotten our maxLen so no need to shrink the window less than maxLen hence we decreasing it by only one not untill the conditions are met 
            sum-=arr[l];
            l++;
        }
    if(sum <= k) maxLen = max(maxLen , r-l+1);

    r++;
}
T.C = O(N)
S.C = O(1)

3. No of Subarray where <condition>  - Solved using pattern 2 
Eg- No of Subarray with sum equal to K 
- Tough to understand whether to expand / shrink 
- No of Subarray with Sum equal to k = (No of Subarray with sum <= k) - (No of SUbarray where Sum <= K-1)

4. Shortest/Minimum Window where <condition> 

*/



int main(){

return 0;
}