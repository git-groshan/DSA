#include<bits/stdc++.h>
using namespace std;
/*
Given an array containing 0,1 and 2 . sort them 

Dutch National Flag Algorithms 

*/

void sortColors(vector<int>&v){
    int low = 0 ; // to handle zeros 
    int high = v.size() -1 ;// to handle two's
    int mid = 0 ; // to handle one's

    while( mid <=high){
        //cases 
        if(v[mid] == 0){ // swap it with low idx 
            int temp = v[mid];
            v[mid] = v[low];
            v[low] = temp;
            low++;
            mid++;
        }
        else if(v[mid] == 1){ // swap it with mid (as it points to itself no need to swap )
            mid++;

        }
        else{ // v[mid] == 2 ,hence swap it with high idx 
            int temp = v[mid];
            v[mid] = v[high];
            v[high] = temp;
            high--; // only high should be decrease beacuse we don't know what value earlier at v[high] which is currently at v[mid] i.e why we again need to check for v[mid] hence only high -- as we are confirm that at that place 2 is present now 
        }
    }
}
int main(){
        vector<int> v = {0,1,2,0,1,1,2};
        sortColors(v);
        for(int x:v)cout<<x<<" ";
return 0;
}