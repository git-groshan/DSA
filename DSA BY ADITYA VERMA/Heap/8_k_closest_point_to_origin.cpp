#include<bits/stdc++.h>
using namespace std;


// key = x^2 + y^2
// Since we need to know the k closest points i.e min Distance points 
// Hence maxHeap we will use because farthest point i.e whose distance are larger are of no use 


typedef pair<int , pair<int,int>> ppi;
vector<vector<int>> kClosestPointsToOrigin(vector<vector<int>>&points , int k){
    vector<vector<int>>k_closest_point_2_origin;
    priority_queue<ppi> maxHeap;
    int n = points.size();
    for(auto &point : points){
        int x = point[0] , y = point[1];
        int dist = x*x + y*y;
        maxHeap.push({dist , {x,y}});
        if(maxHeap.size()>k) maxHeap.pop();
    }
    while(maxHeap.size() > 0){
        int x = maxHeap.top().second.first;
        int y = maxHeap.top().second.second;
        k_closest_point_2_origin.push_back({x,y});
        maxHeap.pop();
    }
    return k_closest_point_2_origin;

}


// Leetcode solution  

/*
Closest point will be the min dist from origin 
since we need to return the min dist hence we will use maxHeap so that we can pop out all the max distance point 
only k min dist point to be stored in Heap 
O(nlogk)
*/

struct Pair{
    int x;
    int y;
    int dist;
};
int getDistanceFromOrigin(int x , int y){
    return x*x + y*y;
}
struct ComparePairs {
    bool operator()(const Pair& p1, const Pair& p2) {
        return p1.dist < p2.dist; // Change to '>' for max heap
    }
};
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Pair , vector<Pair> ,ComparePairs > maxHeap;
        vector<vector<int>> ans;
        for(auto point: points){
            Pair p;
            p.x = point[0];
            p.y = point[1];
            p.dist = getDistanceFromOrigin(p.x , p.y);

            maxHeap.push(p);
            if(maxHeap.size() > k) maxHeap.pop();
        }

        while(maxHeap.size() > 0){
            Pair p = maxHeap.top();
            int x = p.x;
            int y = p.y;
            ans.push_back({x,y});
            maxHeap.pop();
        }
        return ans;

    }


int main(){
    vector<vector<int>>points ={{1,3} , {-2,2} , {5,8} , {0,1}};
    int k = 2;

    vector<vector<int>>ans = kClosestPointsToOrigin(points , k);
    for(auto point:ans){
        cout<<point[0] <<" "<<point[1]<<endl;
    }
return 0;
}