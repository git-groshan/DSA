#include<bits/stdc++.h>
using namespace std;

/*
76. Minimum Window Substring
Solved
Hard
Topics
Companies
Hint
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?
*/
// Brute force - generate all subarrays
string bruteForceMinWindowSubstring(string s , string t)
{
   int minLength = INT_MAX;
   int startIdx = -1;
   for(int i=0;i<s.size();i++)
   {
        unordered_map<char,int>hash;
        int cnt = 0;
        for(int j=0;j<t.size();j++){
            hash[t[j]]++;
        }
        for(int j=i;j<s.size();j++)
        {
            if(hash[s[j]] > 0) cnt++;
            hash[s[j]]--;
        if(cnt == t.size())
        {
            if(j-i+1 < minLength){
                minLength = j-i+1;
                startIdx = i;
                break;
            }
        }
        }
        if(startIdx == -1) return "";
        return s.substr(startIdx , t.size());
   } 
}




// ########### leetcode solution ##########

class Solution {
public:
    /*
    Logic - we will store the freq of each char of t in a map and a count to
    store the no of char in map i.e map.size() == count and while traversing
    string s  we will keep on decreasing the freq of char from map and if anyone
    char freq becomes zero we will decrease count variable. if count == 0 then
    we have our one possible candidate answer then we start decreasing the
    window from starting to get minimun window
    */

    string minWindow(string s, string t) {
        unordered_map<char, int> um;
        for (char c : t) um[c]++;
        int i = 0, j = 0, count = um.size(), startIdx = -1, endIdx = -1;
        int length = INT_MAX; // length of minWindow substring
        while (j < s.size()) {
            char ch = s[j];

            // if ch is present in map decrease it's count
            if (um.find(ch) != um.end()) {
                um[ch]--;
                // if freq of char becomes zero in map decrease the count
                if (um[ch] == 0)
                    count--;
            }

            // now if count becomes zero

            while (count == 0) {
                // one possible candidate of answer is
                if (length > j - i + 1) {
                    length = j - i + 1;
                    startIdx = i;
                    endIdx = j;
                }
                // decrease the window size by increasing i pointer
                if (um.find(s[i]) != um.end()) {
                    um[s[i]]++; // increase freq of char if it is present in map
                    if (um[s[i]] > 0)
                        count++; // increase count varibale if freq becomes > 0
                }
                i++; // slide the window
            }
            j++; // slide the window
        }

        if (startIdx == -1)
            return "";

        return s.substr(startIdx, endIdx - startIdx + 1);
    }
};
 
int main(){

return 0;
}