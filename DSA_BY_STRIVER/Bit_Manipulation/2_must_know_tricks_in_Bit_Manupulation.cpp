#include<bits/stdc++.h>
using namespace std;


void swapUsingXor(int a , int b){
    // xor of same number will be zero as every bit will have even no of ones
    a=a^b;
    b=b^a;// b^a = b^(a^b) = a
    a=a^b;// a^b = (a^b)^a = b
}
bool isIthBitSet(int a , int i){
    return ((a & (1<<i)) != 0); // using left shift operator 
    // return ((a>>i) & 1) != 0); // using right shift operator 
}
int  setIthBit(int a , int i){
     return (a | (1<<i));
}

int clearIthBit(int a  , int i){
    // mask should be like 0th bit should be zero and other bits shoudl be 1
    return (a & ~(1<<i));
}

int toggleIthBit(int a  , int i){
    // 0^1 = 1 , 1^1 = 0  --> hence xor with 1 
    // 0^1 = 1 , 0^0 = 0 -->xor with 0 don't changes the number 
    return (a ^ (1<<i));
}

int removeLastSetBit(int a){

    return (a & (a-1));
}

bool checkIfNumberIsPowerOf2(int a){
    // there will be only one set bit 

    return ((a & (a-1)) == 0);
}

int countSetBits(int a){
    /*
// Method 1

int count = 0;
while(a>1){
if(a%2==1) count++; // if(a&1)
a/=2; // a>>1
}
if(a==1) count++;
return count;
*/


    int ct = 0;

    while(a!=0){
        ct++;
        a = (a & (a-1));
    }
    return ct;

}

int main(){
    int a = 13;
    cout<<clearIthBit(a,0)<<endl;
    cout<<countSetBits(13)<<endl;
return 0;
}