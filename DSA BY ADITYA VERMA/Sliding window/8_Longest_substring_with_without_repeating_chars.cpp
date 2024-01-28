#include<bits/stdc++.h>
using namespace std;


// No repeating characters means All unique characters 
// in prev problem we need to find longest substring with k unique charc but here in this K is not given.
// to check if in current window all chars are unique  the count of each chars must be 1 i.e the length of window must be equal to size of map 
// possible candidate will occure only when map.size() == j -i + 1 == length of window 
int longestSUbstringWithNoRepeatingCharacters(string s){
    int i=0,j=0;
    int ans = 1;
    unordered_map<char,int>um; // to store the unique char map 
    while(j<s.size()){
        char ch = s[j];
        um[ch]++;

        if(um.size() == j-i+1){
            ans = max(ans , j-i+1);
            j++;
        }
        else if(um.size()<j-i+1){
            while(um.size()<j-i+1){
                um[s[i]]--;
                if(um[s[i]]==0)um.erase(s[i]);
                i++;
            }
            j++;
        }

    }
    return ans;

}
// leetcode question solution
//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0 ,j=0 ,window_len=0 , max_window_len =0;
        int start_of_window_of_max_len =-1;
        unordered_map<char,int>m;
        while(j<s.size()){
            char ch = s[j];
            if(m.count(ch) && m[ch]>=i){
                i= m[ch]+1;
                window_len = j-i;
            }
            m[ch] =j;
            window_len++;
            j++;
            if(window_len > max_window_len){
                max_window_len = window_len;
                start_of_window_of_max_len = i;
            }
        }
        return max_window_len;
    }
};

int main(){
        // string s = "pwwkew";
        string s = "abcabcbb";
        cout<<longestSUbstringWithNoRepeatingCharacters(s);
return 0;
}