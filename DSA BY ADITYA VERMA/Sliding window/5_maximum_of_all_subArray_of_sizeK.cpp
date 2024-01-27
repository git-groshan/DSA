#include<bits/stdc++.h>
using namespace std;

// this is giving TLE 
vector<int> maximumOfAllSubarrayOfSizeK(int n , int arr[] , int k){
        int i=0 , j=0;
        vector<int>ans;
        multiset<int,greater<int>>multiSet; // to store k element in sorted order
        while(j<n){
            multiSet.insert(arr[j]);
            if(j-i+1<k) j++;
            else if( j-i+1==k){
                ans.push_back(*multiSet.begin());
                multiSet.erase(arr[i]);
                i++;
                j++;
            }

        }
        return ans;

}

/*
logic - we will store the max element in deque(a list which is opened from both end)
for a particular j , we will remove all the element which are smaller than a[j] and in left of j i.e for all i < j
bcz they will never contribute in max element 

*/
vector<int> max_of_subarrays(vector<int> a, int n, int k) {
        
        vector<int>ans;
        deque<int>q;
          if(k>a.size())
    {
        ans.push_back(*max_element(a.begin(),a.end()));
        return ans;
    }
        int i=0, j=0;
        while(j<a.size())
        {
            // removing all the element stored in queue which are less that cur arr[j];
            while(q.size() && q.back()<a[j])
            { 
            q.pop_back();
            }

            q.push_back(a[j]);
            if(j-i+1<k) j++; // increasing the window size 
            else
            {
                ans.push_back(q.front());
                if(q.front()==a[i]) // checking if the front element is the maximum element 
                q.pop_front();
                i++; 
                j++;
            }
        }
        return ans;
    
    }
    // instead of deque we can use vector
vector<int> max_of_subarrays_using_list(vector<int> a, int n, int k) {
        vector<int>ans;
         if(k>a.size())
    {
        ans.push_back(*max_element(a.begin(),a.end()));
        return ans;
    }
        list<int>q;
        int i=0, j=0;
        while(j<a.size())
        {
            // removing all the element stored in queue which are less that cur arr[j];
            while(q.size() && q.back()<a[j])
            { 
            q.pop_back();
            }

            q.push_back(a[j]); // calculation for every j 
            if(j-i+1<k) j++; // increasing the window size 
            else
            {
                ans.push_back(q.front());
                if(q.front()==a[i]) // checking if the front element is the maximum element 
                q.pop_front();
                i++; 
                j++;
            }
        }
        return ans;
    
    }

int main(){
    /*
    int n = 8;
    int arr[n] = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    */


    /**\
     * we have to take an ans vector and keep on pushing max element of  all subarray of size of k
     * for above ans would be [3,3,5,5,6,7]
    */
/*
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 
*/
int n = 9 , k = 3;
int arr[9] = {1,2,3,1,4,5,2,3,6};
   vector<int> v = maximumOfAllSubarrayOfSizeK(n ,arr , k);
   for(int &x : v) cout<<x<<",";
   cout<<endl;

   vector<int>a={1,2,3,1,4,5,2,3,6};
   vector<int>ans = max_of_subarrays_using_list(a,9,3);
   vector<int>ans2 = max_of_subarrays(a,9,3);
   for(int &x:ans) cout<<x<<" "; 
   cout<<endl;
    for(int &x:ans2) cout<<x<<" "; 
return 0;
}