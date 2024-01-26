#include<bits/stdc++.h>
using namespace std;


vector<int> firstNegativeInEveryWindowOFSizeK(vector<int>&nums , int k){
    queue<int>q; // to store the negative numbers 
    vector<int>ans;
    int i = 0 , j = 0 , n = nums.size();
    while(j<n){
        // some calculation to be performed for every j
        // if nums[j]<0 push that into queue

        if(nums[j]<0) q.push(nums[j]);

        if(j - i + 1 < k) j++;

        else if(j - i + 1 == k){
            if(!q.empty()) ans.push_back(q.front()); // if q is not empty then window must have an negative element 
            else ans.push_back(0); // q is empty means cur window has no -ve element 
            
            if(nums[i] == q.front()) q.pop(); // check if starting window element is our negative number in queue then remove it from queue
            i++;
            j++;
        }
    }
    return ans;
}

vector<int> firstNegativeInEveryWindowOFSizeK_AV(vector<int>&nums , int k){
    queue<int>q; // to store the negative numbers 
    vector<int>ans;
    int i = 0 , j = 0 , n = nums.size();
    while(j<n){
        // some calculation to be performed for every j
        // if nums[j]<0 push that into queue

        if(nums[j]<0) q.push(nums[j]);

        if(j - i + 1 < k) j++;

        else if(j - i + 1 == k){
            if(q.empty()) ans.push_back(0);
            else{
                ans.push_back(q.front());
                if(nums[i]==q.front()) q.pop();
                   
            }
            i++;
            j++;
        }
    }
    return ans;
}

// gfg question link https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int k) {
                                                 
        vector<long long > ans;
        queue<long long> q;
        
        for(int i=0;i<k;i++){
            if(A[i]<0)q.push(A[i]);
        }
        
        if(!q.empty()) ans.push_back(q.front());// storing first negative element in ans from window of size k
        else ans.push_back(0);
        
        int start = 0;
        for(int i=k;i<N;i++){
            // remove starting element from the window 
            if(!q.empty() && A[start] == q.front()) q.pop();
            // add the next element of window in queue if it is negative 
            if(A[i]<0)q.push(A[i]);
            
            if(!q.empty()) ans.push_back(q.front());
            else ans.push_back(0);
            
            start++;
            
            
        }
        
        return ans;
                                                 
 }

// method 2

vector<long long> printFirstNegativeIntegerM1(long long int A[],
                                             long long int N, long long int K) {
                                                 
        int i=0 , j = 0 ;
        vector<long long> ans;
        queue<long long>q;
        while(j<N){
            // storing the number in queue if it is negative 
            if(A[j]<0) q.push(A[j]);
            
            if( j - i + 1 < K) j++;
            else if(j - i + 1 == K){
                // check if q is not empty then cur win must have neg number 
                if(!q.empty()) ans.push_back(q.front());
                else ans.push_back(0);
                // slide the window 
                if(A[i] == q.front()) q.pop();
                i++;
                j++;
            }
            
        }
        return ans;
                                                 
 }
int main(){
    vector<int> nums = {12 , -1 , -7 , 8 , -15 , 30 , 13 , 28};
    int n = nums.size();
    int k = 3; 
    // if no negative number in the window of size k then print 0
    // total no of windows possible = n - k + 1 

    vector<int>ans = firstNegativeInEveryWindowOFSizeK(nums , k);
    for(auto &neg: ans) cout<<neg<<" ";
    cout<<endl;

return 0;
}