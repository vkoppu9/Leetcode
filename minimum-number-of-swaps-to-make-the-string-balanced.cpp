/*
You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and n / 2 closing brackets ']'.

A string is called balanced if and only if:

It is the empty string, or
It can be written as AB, where both A and B are balanced strings, or
It can be written as [C], where C is a balanced string.
You may swap the brackets at any two indices any number of times.

Return the minimum number of swaps to make s balanced.

 

Example 1:

Input: s = "][]["
Output: 1
Explanation: You can make the string balanced by swapping index 0 with index 3.
The resulting string is "[[]]".
Example 2:

Input: s = "]]][[["
Output: 2
Explanation: You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][[]".
- Swap index 1 with index 5. s = "[[][]]".
The resulting string is "[[][]]".
Example 3:

Input: s = "[]"
Output: 0
Explanation: The string is already balanced.
 

Constraints:

n == s.length
2 <= n <= 106
n is even.
s[i] is either '[' or ']'.
The number of opening brackets '[' equals n / 2, and the number of closing brackets ']' equals n / 2.
*/

// Very elegant and simple solution 
// You have over thought it
/*
Solution 1. Two Pointers
Intuition: We keep looking for the first unmatched ] from left and the first unmatched [ from the right, and swap them.

Algorithm: Use two pointers L = 0, R = N - 1, and two counters left and right which are the number of unmatched [/] from left/right, respectively. For example, if we've seen [[] from the left, then left = 1 because there is one [ unmatched.

We keep incrementing L and decrementing R until left and right become -1. And we swap s[L] and s[R] and set left = right = 1.
*/
class Solution {
public:
    int minSwaps(string s) {
        int left = 0, right = 0, N = s.size(), L = 0, R = N - 1, ans = 0; 
        while (L < R) {
            
            for (; L < R; ++L) {
                left += s[L] == '[' ? 1 : -1;
                if (left == -1) 
                    break;
            }
            
            // this is important 
            if (L >= R) 
                break; // no more unmatched brackets, break
            
            for (; L < R; --R) {
                right += s[R] == ']' ? 1 : -1;
                if (right == -1) 
                    break;
            }
            
            left = right = 1; // after swapping `s[L]` and `s[R]`, `left` and `right` will become `1`.
            ++L, --R;
            ++ans;
        
        }
        return ans;
    }
};