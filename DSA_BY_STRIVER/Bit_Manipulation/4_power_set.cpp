#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> powerSet(vector<int>&v){
    int n = v.size();
    vector<vector<int>> ans;
    for(int i=0; i<(1<<n);i++){
        vector<int>subset;
        for(int j=0;j<32;j++){ // we can go j from 0 to n-1
            if(i & (1<<j)){
                subset.push_back(v[j]);
            }
        }
        ans.push_back(subset);
    }
    return ans;
}

// T.C = 2^n x 32


int main(){

    vector<int> v = {1,2,3};
    vector<vector<int>> powerset = powerSet(v);
    cout<<"Total subsets are "<<powerset.size();
    for(auto v : powerset){
        for(int x:v) cout<<x<<" ";
        cout<<endl;
    }

return 0;
}