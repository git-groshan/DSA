#include<bits/stdc++.h>
using namespace std;

// fixed size window general format 

/*
while(j<size){
    calcualtions 
    if(winSize < k) j++;
    else if(winSize == k){
        1.get answer by performing calculation according to ques
        2. Remove calculation done for i
        3. window size maintain and slide the window
    }
}
*/
 

// variable size general format

/*
while(j<size){
    calculations for each j 
    if(condition < k) j++;
    else if(condition == k){
        get ans doing calculations 
        j++;
    }
    else if( condition > k){
        while(condition > k){
            remove calculation for i 
            i++;
        }
        j++;
    }
}
*/

vector<int> longestSubstringWithKuniqueCharacters(string s , int k){
    int n = s.size();
    int i=0 , j=0 ;
    int ans = 0;
    unordered_map<char , int>um;
    int startIdx = 0 , endIdx = 0;// to store the indices of longestSubstring of unique k chars

    while(j<s.size()){
        char ch = s[j];
        um[ch]++;
        if(um.size()<k)j++;// size of map i.e count of unique charcters is less than k hence j++
        else if(um.size()==k){// one of the possible candidate
            // ans = max(ans , j-i+1);
            if(j-i+1 > ans){
                ans = j-i+1;
                startIdx = i ;
                endIdx = j;
            }
            j++;
        }
        else if(um.size()>k){
            while(um.size()>k){
                um[s[i]]--;
                if(um[s[i]]==0) um.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return {ans,startIdx,endIdx};
}

// GFG solution 
//https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int i=0 , j=0 , ans= INT_MIN;
    unordered_map<char , int>um; // to store the freq of each char in curr window 
    while(j<s.size()){
        char ch = s[j];
        um[ch]++;
        if(um.size()<k)j++; // if curr unique char count is less than k then expand the window 
        else if(um.size()==k){// one possible candidate for answer 
            ans = max(ans , j-i+1);
            j++;
        }
        else if(um.size()>k){ // window size is greater than k then start removing element from starting of window 
            while(um.size()>k){// remove element untill size is > k
                um[s[i]]--;
                if(um[s[i]]==0)um.erase(s[i]); // if count of char becomes zero , remove it from map also 
                i++;
            }
            j++;
        }
    }
    return ans==INT_MIN?-1:ans;
    
    }
};
// 2nd solution 
class Solution2{
  public:
   int longestKSubstr(string s, int k) {
        int freq[26]={0},ans=-1,i=0,j=0,n=s.length(),sum;
        freq[s[0]-'a']++;
        while(j<n){
            sum=0;
            for(int t=0; t<26; t++) if(freq[t]!=0) sum++;
            if(sum>k) freq[s[i++]-'a']--;
            else{
                if(sum==k) ans=max(ans,(j-i+1));
                freq[s[++j]-'a']++;
            }
        }
        return ans;
    }
};
int main(){

        string s = "aabacebebebe";
        int k = 3;
        vector<int> v = longestSubstringWithKuniqueCharacters(s ,k);
        cout<<"longestSubstringWithKuniqueCharacters "<<v[0]<<endl;
        cout<<"startIdx is "<<v[1]<<" "<<"endIdx is "<<v[2]<<endl;
        return 0;
}