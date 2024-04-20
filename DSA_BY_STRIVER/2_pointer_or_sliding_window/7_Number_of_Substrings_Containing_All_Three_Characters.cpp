#include<bits/stdc++.h>
using namespace std;


/*
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
1358. Number of Substrings Containing All Three Characters
Medium
Topics
Companies
Hint
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
*/


int bruteForce(string &s){
    int ct = 0;
    for(int i=0;i<s.size();i++)
    {
        vector<int>hash(3 , 0);
        for(int j=i;j<s.size();j++)
        {
            hash[s[j] - 'a'] = 1;
            if(hash[0] + hash[1] + hash[2] == 3) ct++;
        }
    } 
    return ct;   
}

int bruteForce_optimised(string &s){
    int ct = 0;
    int n = s.size();
    for(int i=0;i<s.size();i++)
    {
        vector<int>hash(3 , 0);
        for(int j=i;j<s.size();j++)
        {
            hash[s[j] - 'a'] = 1;
            if(hash[0] + hash[1] + hash[2] == 3){
                ct = ct + (n - j); // since we have found our valid substring , hence further adding char won't impact hence we have simply added those extra substring count which is (n-j);
                break;
            }
        }
    } 
    return ct;   
}
/*
T.C = O(N^2) 
S.C = O(1)
*/
/*
Approach -
With every characters , there is a substring that ends
for eg - 
string s = "bbacba"
for a at index 2 there are 3 substring that ends at a which are "bba" , "ba" , "a"


while iterating in the string we will keep track of last seen indices of a , b & c so that we could find the minumun length window which has all the 3 character 
from that we will count the no of substring that ends at index j which has all the three characters.


*/
// ########### LEETCODE SOLUTION  #######
class Solution {
public:


/*
Approach -
With every characters , there is a substring that ends
for eg - 
string s = "bbacba"
for a at index 2 there are 3 substring that ends at a which are "bba" , "ba" , "a"


while iterating in the string we will keep track of last seen indices of a , b & c so that we could find the minumun length window which has all the 3 character 
from that we will count the no of substring that ends at index j which has all the three characters.


*/
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char ,int>um; // last Seen Index 
        um['a'] = -1 , um['b'] = -1 , um['c'] = -1;
        int i=0;
        int ans = 0; // total valid substring 
        while( i < s.size()){
            char ch = s[i];
            um[ch] = i;
            if(um['a'] !=-1 && um['b']!=-1 && um['c']!=-1){
                int minIdx = min(um['a'] , min(um['b'] , um['c']));

                ans += (minIdx+1);
            }
            i++;
        }
        return ans;
    }
};

int numberOfSubstrings_striver(string s)
{
    int n = s.size();
    int totalNoOfSubstring = 0;
    vector<int>lastSeenIdx(3,-1);
    for(int i=0;i<n;i++){
        lastSeenIdx[s[i] - 'a'] = i;
        if(lastSeenIdx[0]!=-1 && lastSeenIdx[1]!=-1 && lastSeenIdx[2]!=-1){
            totalNoOfSubstring = totalNoOfSubstring + min(lastSeenIdx[0] , min(lastSeenIdx[1] , lastSeenIdx[2])) + 1;
        }
    }
    return totalNoOfSubstring;
}



int main(){
    string s =  "abcabc";
    cout<<" numberOfSubstrings_striver "<<numberOfSubstrings_striver(s)<<endl;
return 0;
}