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
void printAllUniquePermutationOfStringUsingBacktracking()
{

}


/*
Time Complexicity of Recursive Tree
1. Time complexicity 1o1
- Time complexicity represents change/rate of time w.r.t input size 

2. Recrusive Tree TC
- use Recursive tree to derive TC of Recursion program 
- 
4. TC of last solution 
4. Don't be too attached 
*/
int main(){
    // string s = "abc";//input
    string s = "aab";//input
    string cur = ""; // output
    vector<string>v;
    printAllUniquePermutationOfStringUsingRecursion(s , cur , v);
    for(auto &str : v) cout<<str<<" ";

return 0;
}