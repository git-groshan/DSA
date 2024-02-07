#include<bits/stdc++.h>
using namespace std;

/*

arr[]: 3,0,0,2,0,4   represents heights of  buildings of 1 unit width 
calculate the max Area trapped by rain

total water trapped = summation of water trapped in each building
for a particlular building , the height of water = minimum(maxHeightBuildingToLeft,maxHeightBuildingToRight) - height[i];

*/

  int trap(vector<int>& height) {
        int n = height.size();
        if(n<3) return 0;
        vector<int>left(n,0) , right(n,0);
        left[0]= height[0];
        right[n-1]= height[n-1];
        // int cur_max=height[0]
        for(int i=1;i<n;i++){
            left[i]= max(left[i-1] , height[i]);
            right[n-i-1] = max(right[n-i] , height[n-i-1]);
        }
        int water =0;
        for(int i=0;i<n;i++){
            water += min(left[i] , right[i]) - height[i];
        }
        return water;
    }
int Rain_water_trapping(vector<int>&heights){
    int n = heights.size();
    vector<int>leftMaxHeights(heights.size() , 0);
    vector<int>RightMaxHeights(heights.size() , 0);
    leftMaxHeights[0] = heights[0];
    RightMaxHeights[n-1] = heights[n-1];
    for(int i=1;i<heights.size();i++){
        leftMaxHeights[i] = max(leftMaxHeights[i-1] , heights[i]);
        RightMaxHeights[n-i-1] = max(RightMaxHeights[n-i] , heights[n-i-1]);
    }
    int water = 0;
    for(int i=1;i<n;i++){
        water+=min(leftMaxHeights[i] , RightMaxHeights[i]) - heights[i];
    }
    return water;
}

int Rain_water_trappingByAV(vector<int>&heights){
    int n = heights.size();
    vector<int>leftMaxHeights(heights.size() , 0);
    vector<int>RightMaxHeights(heights.size() , 0);
    leftMaxHeights[0] = heights[0];
    RightMaxHeights[n-1] = heights[n-1];
    for(int i=1;i<heights.size();i++){
        leftMaxHeights[i] = max(leftMaxHeights[i-1] , heights[i]);
        RightMaxHeights[n-i-1] = max(RightMaxHeights[n-i] , heights[n-i-1]);
    }
    int total_water = 0;
    vector<int>water;
    for(int i=0;i<n;i++){
        water.push_back(min(leftMaxHeights[i] , RightMaxHeights[i]) - heights[i]);
        total_water+=water[i];
    }
    
    return total_water;
}
int main(){
    vector<int>heights={3,0,0,2,0,4};
    cout<<"from trap fun "<<trap(heights)<<endl;
    cout<<"from Rain_water_trapped "<<Rain_water_trapping(heights)<<endl;
    cout<<"from Rain_water_trapped by AV "<<Rain_water_trappingByAV(heights)<<endl;
return 0;
}