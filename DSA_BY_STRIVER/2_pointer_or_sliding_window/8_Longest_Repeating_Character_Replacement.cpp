#include<bits/stdc++.h>
using namespace std;

/*

// https://leetcode.com/problems/longest-repeating-character-replacement/description/

424. Longest Repeating Character Replacement
Medium
Topics
Companies
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
*/
/*
Brute Force - Generate all substring 

for(int i=0;i<n;i++){
    int hash[26] = {0};
    int maxFreq = 0;
    for(int j=i;j<n;j++){
        hash[s[j] - 'A']++;
        maxFreq = max(maxFreq , hash[s[j] - 'A']);
        int changesRequired = (j-i+1) - maxFreq; // j-i+1 = len of substring 
        if(changesRequired <= k){
            maxLen = max(maxLen , j-i+1);
        }
        else break;

    }
    return maxLen;
}
T.C = O(N^2)
S.C = O(26)

*/

class Solution {
public:
/*
for any substring of len L , min no of changes required to make all substring char equal is lenOfSubstring - maxFreq
Here maxFreq = freq of char which is occuring max time in current substring 

*/
    int LongestSubstringWithAtMostKCharacters(string s , int k){
        int i=0 ,j=0 , n = s.size();
        int maxFreq = 0; // stores the max Freq value in current substring
        int ans = 0;
        unordered_map<char,int>um;
        while(j<n){
            um[s[j]]++;
            maxFreq = max(maxFreq , um[s[j]]);
            if(( (j-i+1) - maxFreq ) <= k){
                ans = max(ans , j-i+1);
            }
            else if(( (j-i+1) - maxFreq ) > k){
                while(( (j-i+1) - maxFreq ) > k){
                    um[s[i]]--;
                    maxFreq = max(maxFreq , um[s[i]]);
                    if(um[s[i]] == 0) um.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
    int characterReplacement(string s, int k) {
        return LongestSubstringWithAtMostKCharacters(s,k);
    }
 };

 int LongestSubstringWithAtMostKCharacters_striver_optimised(string s , int k){
        int i=0 ,j=0 , n = s.size();
        int maxFreq = 0; // stores the max Freq value in current substring
        int ans = 0;
        unordered_map<char,int>um;
        while(j<n){
            um[s[j]]++;
            maxFreq = max(maxFreq , um[s[j]]);
            if(( (j-i+1) - maxFreq ) <= k){
                ans = max(ans , j-i+1);
            }
            else if(( (j-i+1) - maxFreq ) > k){
               // while(( (j-i+1) - maxFreq ) > k){
                    um[s[i]]--;
                    maxFreq = max(maxFreq , um[s[i]]);
                    if(um[s[i]] == 0) um.erase(s[i]);
                    i++;
                //}
            }
            j++;
        }
        return ans;
    }

   int LongestSubstringWithAtMostKCharacters_striver(string s , int k){
    int l=0 , r=0 , n = s.size();
    vector<int>hash(26,0);
    int maxFreq = 0;
    int maxLen = 0;
    while (r < s.size())
    {
        char ch = s[r];
        hash[ch - 'A']++;
        maxFreq = max(maxFreq , hash[ch -'A']);

        while((r-l+1) - maxFreq > k){
            hash[s[l]]--;
            maxFreq = 0;
            // calculating new maxfreq
            for(int i=0;i<26;i++) maxFreq = max(maxFreq , hash[i]);
            l++;
        }
        if((r-l+1) - maxFreq <= k){ // this if condition is redundant but still it makes code readable
            maxLen = max(maxLen , r-l+1);
        }
        r++;
    }
    /**
     * T.C = O(N + N)*26
     * S.C = O(26) 
    */
   }
    int LongestSubstringWithAtMostKCharacters_striver_mostOptimized(string s , int k){
    int l=0 , r=0 , n = s.size();
    vector<int>hash(26,0);
    int maxFreq = 0;
    int maxLen = 0;
    while (r < s.size())
    {
        char ch = s[r];
        hash[ch - 'A']++;
        maxFreq = max(maxFreq , hash[ch -'A']);

        //while((r-l+1) - maxFreq > k){
        if((r-l+1) - maxFreq > k){
            hash[s[l]]--;
            maxFreq = 0;
            // calculating new maxfreq
            //for(int i=0;i<26;i++) maxFreq = max(maxFreq , hash[i]);
            l++;
        }
        if((r-l+1) - maxFreq <= k){ // this if condition is redundant but still it makes code readable
            maxLen = max(maxLen , r-l+1);
        }
        r++;
    }
    /**
     * T.C = O(N + N)*26
     * S.C = O(26) 
    */
   }
int main(){

return 0;
}