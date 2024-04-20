#include<bits/stdc++.h>
using namespace std;

/*
Given overlapping/non-overlapping intervals 
To check if the intervals are ovelapping or not , we need to fix one point either starting or ending
if we sort intervals on basis of start time 
then if next interval is overlapping with the prev intervale then it's start must be less than the end of prev interval
if it is more then end of prev interval then it is not overlapping.

//Merge Intervals

sort(intervals.begin() , intervals.end());// sorted on the basis of starttime

vector<vector<int>>ans;
for(auto interval : intervals){
    if(ans.size()==0 || interval[0] > ans.back()[1]){
        ans.push_back(interval);// push current interval if ans is empty of current interval start time is greater than prev interval end time i.e no overlapping in between them
    }
    else { // this is overlapping case 
        // grab out the prev elem which is stored in ans.back()
        vector<int> prevInterval = ans.back();
        ans.pop_back();
        ans.push_back({prevInterval[0] , max(prevInterval[1] , interval[1])});
    }
}
return ans;


*/

/*
56. Merge Intervals
Solved
Medium
Topics
Companies
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/
class Solution {
public:
    /*
    Approach - 1. sort the interval on the basis of start time so that we could check if 2 intervals are overlapping or not
               2. To check overlapping - prevInterval end must be greater than curInterval start
               3.Hence new Interval = {prevIntervalStart , max( nextIntervalEnd , prevIntervalEnd}
    */

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin() , intervals.end());

        for(auto interval : intervals){
            // if ans is empty or curIntervalstart is greater than prevIntervalEnd(which is simply ans.back) simply push this new Interval
            if(ans.size()==0  || interval[0] > ans.back()[1]){
                ans.push_back(interval);
            }
            else{ // there is an overlapping hence we need to calculate the new non-overlapping Interval
                auto prevInterval = ans.back();
                ans.pop_back();
                vector<int> newInterval = {prevInterval[0] , max(prevInterval[1] , interval[1])};
                ans.push_back(newInterval);


            }
            
        }
        return ans;
        
    }
};


/*####################################################################*/

/*
57. Insert Interval
Solved
Medium
Topics
Companies
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105
*/

int main(){

return 0;
}