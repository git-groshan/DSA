/*
1. what is not Backtracking ?
- Backtracking is not done by us. It's a recursion phenomena , 
i.e whenever  a function return to from  where it is called is called backtracking .

2. Difference between BT , DP , Recursion?
- Recursion = choice + decision 
- Recursion is parent of DP , BT and DnC
- In Recursion we get answer at leaf node 
- Usually In DP we get our answer at root node
- Dp is Recursion + memoisation 

- BT = Recursion + control + pass by refernce 
- BT is generally all combination 
- In BT answer is generally is in the path of recursive tree


3. pass by value pass by reference.
- variable are passed by value means value is passed to function and that value is copied in memory and used for further calculation 
- variable passed by refernece means the pointer or refence of variable is passed to fucntion hence any changes in variable inside function would also be reflected in variable  


4. BT  =  controlled Recursion + pass by reference

**** Bactracking is reverting back the changes we do in tha variable before next function call 
when that function call overs we undo the changes done to the variables
*/


/**
 * Identification of BAcktracking 
 * 1. choices + decision 
 * 2. All combinations
 * 3. controlled Recursion 
 * 4. Number of choices (generally large or variable)
 * 5. size of constraints (2^N or N!)  1<=N<=20
 * 6. Don't  be greedy 
*/

/**
 * Generalization of Backrtracking 
 * Pseudo code 
 * void solve(args){
 *  // base case 
 *      if(isSolved(args) == True)
 * {
 *      save the ans
 *      return      
 *  }
 * // nof of choices are large hence for loop 
 * for(choice in all choices )
 * {
 * // controlled recursion 
 * if( choice is valid ){ // comtrolled recursion 
 *      solve(args); // need to change is args for recursive calls 
 * }
 * // Backtrack
 * // revert back the changes done on variables used in function call
 * }
 * 
 * 
 * }
*/

/*
void solve(&v){
    // base case 
    if(isSolved() == true){
        print/save the answer 
    }

    for(c in all choices ){ // iterating in all choices 
        if(isValid() == true){ //controlled recursion 
            change in v;
            solve(v);
            revert changes in v; // backtracking 
        }
    }
}
*/


/**
 * Backtracking Problems 
 * 1. Permutaion of a string 
 * 2. largest number in kth swap
 * 3. N digit number with digit in increasing order
 * 4. Rat in a maze 
 * 5. word Break
 * 6. Plaindrome partitioning
 * 7. combinational sum 
 * 8. sudoku 
 * 9. N Queen
 * 10. phone letter digits
 * 
*/
#include<bits/stdc++.h>
using namespace std;


int main(){

return 0;
}