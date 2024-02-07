#include<bits/stdc++.h>
using namespace std;
/*
GIven a Binary Matrix 
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
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



long long int maxAreaBinaryMatrix(vector<vector<int>>&v){
    long long int maxAreaRectangle = INT_MIN;
    vector<int>historgram(v.size() , 0);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j] == 0) historgram[j] = 0;
            else historgram[j]+=v[i][j];
        }
        cout<<"Printing Histogram "<<endl;
        printVector(historgram);
        long long int curArea  =  maxAreaOfHistogram(historgram);
        // maxAreaOfBinaryMatrix = max(maxAreaBinaryMatrix , curArea);
        cout<<"Current Histogram area is "<<curArea<<endl;
        if(curArea > maxAreaRectangle) maxAreaRectangle = curArea;
    }
    return maxAreaRectangle;
}

int main(){

vector<vector<int>>matrix ={{0,1,1,0},
                            {1,1,1,1},
                            {1,1,1,1},
                            {1,1,0,0}};

cout<<"Max Area Rectangle is "<<maxAreaBinaryMatrix(matrix);
    

return 0;
}