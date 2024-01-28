#include<bits/stdc++.h>
using namespace std;

/*
Given a string where each char represents one type of toy.
you have to choose max 2 type of toys with max quantity and toys should be placed consecutively i.e in continuous manner i.e substring

In a nutshell - longest substring with 2 unique charcters 
*/

int pickToys(string s){
    int i=0 , j=0;
    int ans = 0;
    unordered_map<char,int>um;
    while(j<s.size()){
        um[s[j]]++;
        if(um.size()<2)j++;
        else if(um.size() == 2){
            int curToys = 0;
            // for(auto &pr : um)curToys+=pr.second;
            // the above statement can be changes to 
            curToys = j - i + 1;// length of window = no of curToys 
            ans = max(ans, curToys);
            j++;
        }
        else if(um.size()>2){
            while(um.size()>2){
            um[s[i]]--;
            if(um[s[i]]==0)um.erase(s[i]);
            i++;
            }
            j++;
        }
    }
    return ans;
}
int main(){
        string s = "abaccab";
        cout<<"Max Toys "<<pickToys(s);
return 0;
}