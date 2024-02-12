#include<bits/stdc++.h>
using namespace std;

void printAllUniquePermutationOfStringUsingRecursion(string ip , string op , vector<string>&v)
{
    if(ip.size() == 0){
        v.push_back(op);
        return;
    }
    unordered_set<char>us;
    for(int i=0;i<ip.size();i++){
        if(us.find(ip[i]) == us.end()){ // to check for duplicate recursive calls i.e controlled recursion  
            us.insert(ip[i]);
        string newInput = ip.substr(0,i) + ip.substr(i+1);
        string newOutput = op + ip[i];
        printAllUniquePermutationOfStringUsingRecursion(newInput , newOutput , v);// variables passed by value 
        }
    }

}
/*
In Backtracking approach , for each idx we will swap it with all other charcter to generate other permutation 
*/
void printAllUniquePermutationOfStringUsingBacktracking(int start,string &s , vector<string>&ans)
{
    if(start == s.size() -1 ){
        ans.push_back(s);
        return;
    }
    unordered_set<char>us;
    for(int i=start;i<s.size();i++){
        if(us.find(s[i])==us.end()){
            us.insert(s[i]);
        swap(s[start] , s[i]);
        printAllUniquePermutationOfStringUsingBacktracking(start+1, s , ans);
        swap(s[start] , s[i]);
        }
    }
}


/*
Time Complexicity of Recursive Tree
1. Time complexicity 1o1
- Time complexicity represents change/rate of time w.r.t input size 

2. Recrusive Tree TC
- use Recursive tree to derive TC of Recursion program 
- workDone = work done on Node x no of node 
- total no of node depends on height of Tree and nodes at each level  generally 2^n is no of nodes 

3. TC of last solution 
- In last solution i.e permutation of string 
- no of node  = n!
- work done at one node = O(nXn)
- T.C = O(n^2xn!) = O(n! )
4. Don't be too attached 
*/
int main(){
    // string s = "abc";//input
    string s = "abc";//input
    string cur = ""; // output
    vector<string>v;
   // printAllUniquePermutationOfStringUsingRecursion(s , cur , v);
   printAllUniquePermutationOfStringUsingBacktracking(0 , s, v);
    for(auto &str : v) cout<<str<<" ";

return 0;
}