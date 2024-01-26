#include<bits/stdc++.h>
using namespace std;

int countNoOfAnagram(string str , string pattern){
    int count = 0;
    vector<int>pat(26,0);
    for(char ch : pattern) pat[ch - 'a']++;
    vector<int>cur(26,0);
    int k = pattern.size();
    int i=0 , j = 0;

    while(j<str.size()){
        char ch = str[j];
        cur[ch - 'a']++;

        if(j -i + 1 < k) j++;
        else if( j- i + 1 == k){
            if(cur == pat) count++;
            cur[str[i] - 'a']--;
            i++;
            j++;

        }

    }
    return count;

}

int countNoOfAnagram_BY_AV(string str , string pat){
    int i=0 , j=0 , k = pat.size();
    int ans = 0;
    unordered_map<char,int>um;
    for(char ch:pat) um[ch]++;
    int count = um.size(); // stores the count of no of distinct char in pattern
    /*
    logic is to traverse the whole string and keep on decreasing the freq of char if they are present in map
    if any one's freq is 0 then do count-- 
    if size of window is k then check if count is 0(means all the distict char are presnt in map are also in our window with same freq) then ans++ 
    when slide the window revert back the calculation done for ith char 
    */

    while(j<str.size()){
        // performing calculation of every j 
        char ch = str[j];

        if(um.find(ch) != um.end()){
            um[ch]--; // decreas the freq of element 
            if(um[ch]==0){ // means one element is present in our window with same freq 
                count--; // decrease the no of count of element requried in window 
            }
        }

        if(j-i+1<k)j++; // if window size is less increase the window 
        else if( j-i+1 == k){
            if(count == 0) ans++;
            if(um.find(str[i]) != um.end()){ // since we are removing ith element from window hence reverting back the calculation performed for the element 
                um[str[i]]++; // increasing it's frequency 
                if(um[str[i]] == 1) count++;
            }
            i++;
            j++;
        }

    }
    return ans;

}

int main(){

/*
    string str = "forxxorfxdofr";
    string pattern = "for";
aabaabaa
aaba
    kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
kkkkk
*/
  string str = "kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk";
    string pattern = "kkkkk";


    cout<<"No of anagrams By My logic "<<countNoOfAnagram(str , pattern)<<endl;
    cout<<"No of anagrams BY AV logic "<<countNoOfAnagram_BY_AV(str , pattern)<<endl;
    

return 0;
}