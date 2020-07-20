/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*/
class Solution {
public:
        string addBinary(string a, string b) {
            string ret = "";
            int carry = 0;
            for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--) {
                int m = (i >= 0 && a[i] == '1');
                int n = (j >= 0 && b[j] == '1');
                ret = to_string((m + n + carry) & 1) + ret;
                carry = (m + n + carry) >> 1;
           }
            return carry ? '1' + ret : ret;
        }
};