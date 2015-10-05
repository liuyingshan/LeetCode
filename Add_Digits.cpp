/*
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
*/

class Solution {
public:
	/*
	Proof:
	Assume num = abcde % 9
	           = (10000a + 1000b + 100c + 10d + e) % 9
	           = [(a + b + c + d + e) + (9999a + 999b + 99c + 9d)] % 9
	           = (a + b + c + d + e) % 9 , a+b+c+d+e=xyz
	           = [(x + y + z) + (99x + 9y)] % 9
	           = (x + y + z) % 9 , x+y+z=p
	           ......
	           = p % 9
	*/ 
    int addDigits(int num) {
        return num ? (num - 1) % 9 + 1 : 0;
    }
};
