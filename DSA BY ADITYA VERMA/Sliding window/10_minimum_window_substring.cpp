#include<bits/stdc++.h>
using namespace std;

/**
 * Given 2 string  s and t .you need to find min window substring in s
 * where  that  sub-string contains an anagram of t  i.e same chars of same quantity .
 * 
 * return the size of min window substring
 * 
*/

/*
Logic : first store the char and it's freq of string t in a map and also take it count = map.size();
now traverse the whole string s
1. check if s[j] is present in map if yes then decrease it's freq if it's become zero then count--;
2. if s[j] not in present continue i.e j++;
3. even if freq of s[j] in map is 0 even then decrease it's count . negative freq means window has extra t  

*/

vector<int> minimumWindowSubstring(string s , string t)
{
    if(t.size()>s.size()) return {-1,-1,-1};
    int ans = INT_MAX;
    unordered_map<char,int>um;
    int count = 0;
    for(char &ch : t)um[ch]++;
    count = um.size();
    int startIdx = 0 , endIdx = 0;
    int i=0 , j=0;
    while(j<s.size()){
        char ch = s[j];
        if(um.find(ch)!=um.end()){
            um[ch]--;
            if(um[ch]==0)count--;// if freq of char becomes 0 then decrease the count varibale 
        }
        while(count == 0){
            if(ans > j-i+1){
                ans = j-i+1;
                startIdx = i;
                endIdx = j;
            }
            if(um.find(s[i])!= um.end()){// check if ith char is in the map or not if yes then increase the count of s[i]
                um[s[i]]++;
                if(um[s[i]]>0) count++; // if freq of s[i] becomes greter than 0 then increase the count variable
                
            }
            i++;
        }
        j++; // slide the window 
    }
    return {ans , startIdx , endIdx}; 

}
int main(){

    string s = "totmtaptat";
    string t = "tta";

    vector<int> v = minimumWindowSubstring(s , t);
    cout<<"length of minWindow is "<<v[0]<<" start idx is "<<v[1]<<" end idx is "<<v[2]<<endl;
    cout<<"minWindow substring is ";
    for(int idx =v[1];idx<=v[2];idx++)cout<<s[idx];
return 0;
}

