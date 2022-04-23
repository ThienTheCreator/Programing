/* 1323. Maximum 69 Number

You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

Example 1:

Input: num = 9669
Output: 9969
Explanation: 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.

Example 2:

Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.
Example 3:

Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.

*/

class Solution {
public:
    int maximum69Number (int num) {
        string temp = to_string(num);
        for(int i = 0; i < 4; i++){
            if(temp[i] == '6'){
                temp[i] = '9';
                break;
            }
        }
        return stoi(temp);
    }
};

/* Note

I converted the int to a string and loop through until I saw the first '6' and change to '9' then
broke from the loop finally returning the converted string to a int. I saw a solution in python
where lee215 which was
return int(str(num).replace('6', '9', 1))

Need to look into replace for C++

*/