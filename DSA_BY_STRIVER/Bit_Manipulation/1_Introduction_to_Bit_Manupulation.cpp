#include<bits/stdc++.h>
using namespace std;

/*
 7 -> 111
 13-> 1101

*/

string to_binary(int n)
{
    string res="";

    while(n != 1){
        if(n%2 == 1) res += '1';
        else res+='0';
        n/=2;
    }
    reverse(res.begin() , res.end());
    return res;
}

int to_decimal(string binary){
    int len = binary.size();
    int decimal_value = 0;
    int base = 1;
    for(int i=len-1;i>=0;i--)
    {
        if(binary[i] == '1')
            decimal_value+=(1*base);
        base*=2;
    }
    return decimal_value;
}

// 1's compliment is simply reverse the bits from the last set bit 
// 13 -> 1101 ->1's compl = 0010

/*
2's compliment - 
step 1. take 1 compliment 
step 2. add 1 to it to get 2's compliment 
*/

/*
Binary Operators -
1. AND/& - all true then only output  true , if any 1 false then output false
2. OR/| - any 1 true then all true
3.xor/^ - if no of 1 is odd then 1 otherwise 0 
4. right shift / >> - shift binary to right 
eg- 13>>2 => (1101>>2) the last 2 bits will be removed and in place of them 00 will be added in the right most bits 
hence it would become 0011 == 3
n>>k = n/2^k    13>>2 = 13/2^2 = 13/4 = 3

# since int has 32 bit , in which the 31st index bit(starting from 0) is reserved for sign \
if 31st bit 0 then +ve number , 1 means -ve 

x = -13 
negative numbers are stored in form of 2's compliment 
13 => (0000 0000 0000 1101) -->1's compliment = 1111 1111 1111 0010
-13 = 2's compliment of 0000 0000 0000 1101 = 1111 1111 1111 0010 + 1 =  1111 1111 1111 0011

max 32 bit +ve number = 0111 1111 1111 1111 = 2^30 + 2^29 + 2^28 + .... + 2^0 = 2^31 - 1 = INT_MAX  simple G.P
min 32 Bit -ve number  = 1000 0000 0000 0000 = -2^31 = INT_MIN
2^31 = 0111 1111 1111 ... 1111  -> 1's compliment = 1000 0000 ... 0000  = -2^31

5. left shift <<

13 << 1 
0000 ... 1101 << 1 ==> 0000 ... 11010 ==> 13*2^1 = 26

(2^31 - 1) << 1  --> It will overflow

6. Not Operator ~ It flips the bits
x = ~(5)
first flip the bits and then check if it's a negative number then stores it's 2's complement else stop 

~(0000 ... 0101 ) --> (1111 ...1010) it's a negative number then store it in 2's complement forms
1's complement of (1111 ... 1010) -> (1000 ... 0101)
2's complemetnt of (1000 ... 0101) + 1 -> (1000 ... 0110) = -6

x = ~(-6)
6 = 0000 .... 0110 
1's complement of 6 = 1111 ... 1001
2's complement is = 1111 ... 1001 + 1 = 1111 .... 1010

for ~(-6) 1st step flip the bits 2. if number is neg then stores in 2's complement otherwise stop.

1. after filliping  1111 .... 1010 = 0000 .... 0101 = 5  which is a pos number hence stops here  




*/

int main(){

return 0;
}