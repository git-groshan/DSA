#include<bits/stdc++.h>
using namespace std;

/*
          0,1,2,3,4,5,6
arr[] :   6,2,5,4,5,1,6    -- heights of histogram 
NSR idx:  1,5,3,5,5,7,7     -- indices of next smaller element in right
NSL idx : -1,-1,1,1,3,-1,5
maxWidthofHistoGram = NSR[i] - NSL[i] -1
width :    1,5,1,3,1,7,1
maxArea = width*arr[i]
maxAraa :   6,10,5,12,5,7,6 -----> maxArea = 12 which is for 3rd idx in arr which has value 4
We have assumed that the 7th idx has building of height 0
We have assumed that the -1th idx has building of height 0

A building can only be expanded into other building only when their heights are greater than or equal to current building 


Approch - for every ith building  find the nearest smaller to it's left and right untill before that point it's expandable

*/
void printVector(vector<int>&v){
    for(int x:v)cout<<x<<" ";
    cout<<endl;
}
vector<int> nextSmalllerElementToLeft(vector<int>&arr){
    /*
    We have assumed that for ith building if there is not any building which is smaller to ith is present then we will consider the -1 th idx building is smaller one for ith building 
    */
    vector<int>NSE_left_indices;
    stack<pair<int,int>>st;
    int psudo_idx = -1;
    for(int i=0;i<arr.size();i++){
        // if(st.empty()) NSE_left_indices.push_back(-1); // -1 th idx is the NSE 
        if(st.empty()) NSE_left_indices.push_back(psudo_idx); // -1 th idx is the NSE 
        else if(!st.empty() && st.top().first < arr[i])NSE_left_indices.push_back(st.top().second);
        else if(!st.empty() && st.top().first >= arr[i]){
            while (!st.empty() && st.top().first >= arr[i])
            {
            st.pop();
            }
            
        // if(st.empty()) NSE_left_indices.push_back(-1); // -1 the idx is the NSE
        if(st.empty()) NSE_left_indices.push_back(psudo_idx); // -1 the idx is the NSE
        else if(st.top().first < arr[i])NSE_left_indices.push_back(st.top().second);
        }
        st.push({arr[i] , i});
    }

return NSE_left_indices;

}

vector<int> nextSmalllerElementToRight(vector<int>&arr){
    /*
    We have assumed if for ith building if there is not any building smaller than ith building then next to the last building i.e arr.size() index we will consider that as a smaller building 
    */

    vector<int>NSE_right_indices;
    stack<pair<int,int>>st;
    int pseudo_idx = arr.size();
    for(int i=arr.size()-1;i>=0;i--){
        // if(st.empty()) NSE_right_indices.push_back(-1);
        // if(st.empty()) NSE_right_indices.push_back(arr.size()); // arr.size() idx is the NSE
        if(st.empty()) NSE_right_indices.push_back(pseudo_idx); // arr.size() idx is the NSE
        else if(!st.empty() && st.top().first < arr[i])NSE_right_indices.push_back(st.top().second);
        else if(!st.empty() && st.top().first >= arr[i]){
            while (!st.empty() && st.top().first >= arr[i])
            {
            st.pop();
            }
            
        // if(st.empty()) NSE_right_indices.push_back(-1); // here it means no element in right are smaller 
        // if(st.empty()) NSE_right_indices.push_back(arr.size()); // arr.size() is the NSE
        if(st.empty()) NSE_right_indices.push_back(pseudo_idx); // arr.size() is the NSE
        else if(st.top().first < arr[i])NSE_right_indices.push_back(st.top().second);
        }
        st.push({arr[i] , i});
    }

    reverse(NSE_right_indices.begin() , NSE_right_indices.end());

return NSE_right_indices;    
}

long long int maxAreaOfHistogram(vector<int>&Histogram){

    vector<int>nse_left = nextSmalllerElementToLeft(Histogram);
    cout<<"NSE_left_vector is ";
    printVector(nse_left);
    vector<int>nse_right = nextSmalllerElementToRight(Histogram);
    cout<<"NSE_right_vector is ";
    printVector(nse_right);

    vector<int>width;
    for(int i=0;i<Histogram.size();i++){
        width.push_back(nse_right[i] - nse_left[i] -1);
    }
    cout<<"Width vector is ";
    printVector(width);
    vector<long long int>AreaOfHistograms;
    for(int i=0;i<Histogram.size();i++){
        int length = Histogram[i];
        int wide = width[i];
        AreaOfHistograms.push_back(wide*length);
    }
    long long int maxArea = INT_MIN;
    for(auto area:AreaOfHistograms) maxArea = max(maxArea,area);
    return maxArea;

}
int main(){
 /* we have assumed that for extrem*/
    vector<int>Histogram={6,2,5,4,5,1,6};
    cout<<"Max Area of Histogram is "<<maxAreaOfHistogram(Histogram)<<endl;
return 0;
}