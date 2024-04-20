#include<bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

3. Longest Substring Without Repeating Characters
Solved
Medium
Topics
Companies
Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/

/*
Longest Substring(consecutive part) without repeating character

s = cadbzabcd

*/


    /*
    This is an extension problem of longest substring with K unique chartes
    Logic - we will take a map to store the unique charcters
    any moment if map.size()==j-i+1(window length) means we have all unique
    characters
    */

    /*
    Only 2 conditions are possible
    1. window size == map.size()
    2. window size > map.size() ---> In this case remove extra element
    */


    int longestSubstringWithoutRepeatingCharacter(string s){
    int i=0 , j= 0;
    unordered_map<char,int>um;
    int ans = 0;

    while(j < s.size()){
        char ch = s[j];
        um[ch]++;
        if(um.size() == j-i+1) // possible case 1
        {
            ans = max(ans, j-i+1);
        }
        else if (um.size() < j-i+1){ // [pssible case 2]
           
            while(um.size() <  j-i+1){
            um[s[i]]--;
            if(um[s[i]] == 0) um.erase(s[i]);
            i++;
            }
        }
        j++;
    }
    return ans;


}

int longestSubstringWithoutRepeatingCharacter_striver(string s){
    vector<int>hash(256,-1); // to store the index of char 

    int l=0 , r = 0;
    int maxLen = 0;
    while(r < s.size())
    {
        // check if current char is present in map or not 
        // if present then check it's index lies in between current window i.e l to r 
        // if it is within window then simply move l index to the next of that index (becasue till now our window will have repeating char so that will not count in answer)

        if(hash[s[r]] != -1) // it means it's already in map
        {  
            if(hash[s[r]] >= l)
            {
                l = hash[s[r]] + 1;
            }
        }
        maxLen = max(maxLen  , r-l+1);
        hash[s[r]] = r;
        r++;
        
    }
    return maxLen;
}


int main(){
    // string s = "cadbzabcd";
    // string s = "abcabcbb";
    string s = "bbbbb";
    cout<<longestSubstringWithoutRepeatingCharacter(s)<<endl;
    cout<<longestSubstringWithoutRepeatingCharacter_striver(s);
return 0;
}