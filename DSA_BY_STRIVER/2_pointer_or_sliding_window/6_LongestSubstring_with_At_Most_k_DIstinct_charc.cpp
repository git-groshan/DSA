#include<bits/stdc++.h>
using namespace std;

/*
// https://www.naukri.com/code360/problems/longest-substring-with-at-most-k-distinct-characters_2221410?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

Problem statement
You are given a string 'str' and an integer ‘K’. Your task is to find the length of the largest substring with at most ‘K’ distinct characters.

For example:
You are given ‘str’ = ‘abbbbbbc’ and ‘K’ = 2, then the substrings that can be formed are [‘abbbbbb’, ‘bbbbbbc’]. Hence the answer is 7.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= K <= 26
1 <= |str| <= 10^6

The string str will contain only lowercase alphabets.    

Time Limit: 1 sec
Note:
You do not need to print anything. It has already been taken care of. Just implement the function.
Sample Input 1:
2
2
abbbbbbc
3
abcddefg
Sample Output 1:
7
4
Explanation:
For the first test case, ‘str’ = ‘abbbbbbc’ and ‘K’ = 2, then the substrings that can be formed are [‘abbbbbb’, ‘bbbbbbc’]. Hence the answer is 7.

For the second test case, ‘str’ = ‘abcddefg’ and ‘K’ = 3, then the substrings that can be formed is [‘cdde’, ‘ddef’]. Hence the answer is 4.
Sample Input 2:
2
3
aaaaaaaa
1
abcefg
Sample Output 2:
8   
1   


Hints:
1. Try to think of a brute force approach.
2. Try to think of a two-pointer solution.

*/

int kDistinctChars(int k, string &str)
{
    // Write your code here
    int maxLen = 0 , i=0 , j=0;
    unordered_map<char,int>um;
    while(j < str.size()){
        char ch = str[j];
        um[ch]++;
        if(um.size() <= k){
            maxLen = max(maxLen , j-i+1);
        }
        else if(um.size() > k){
            while(um.size() > k){
                um[str[i]]--;
                if(um[str[i]] == 0) um.erase(str[i]);
                i++;
            }
        }
        j++;

    }
    return maxLen;
}

int kDistinctChars_striver(int k, string &str)
{
    // Write your code here
    int maxLen = 0 , i=0 , j=0;
    unordered_map<char,int>um;
    while(j < str.size()){
        char ch = str[j];
        um[ch]++;
        while(um.size() > k)  // while loop working as an if condition 
        {
            um[str[i]]--;
            if(um[str[i]] == 0) um.erase(str[i]);
            i++;
        }
        if(um.size() <= k){
            maxLen = max(maxLen , j-i+1);
        }
        
        j++;

    }
    return maxLen;
}

int kDistinctChars_optimised(string &s , int k ){
    int l=0 , r=0 , n = s.size();
    int maxLen = 0;
    unordered_map<char,int>um;
    while(r < n){
        um[s[r]]++;

        if(um.size() > k){// only while is replaced by if here 
            um[s[l]]--;
            if(um[s[l]] == 0) um.erase(s[l]);
            l++;
        }
        if(um.size() <= k){
            maxLen = max(maxLen , r-l+1);
        }
        r++;
    }
    return maxLen;
}

int main(){

    string s = "abbbbbbc";
    int k =2;
    cout<<"Max Len from mycode is "<<kDistinctChars(k , s)<<endl;
    cout<<"Max Len from striver code  is "<<kDistinctChars_striver(k , s)<<endl;
    cout<<"Max Len from optimsed code  is "<<kDistinctChars_optimised(s,k)<<endl;
    
return 0;
}