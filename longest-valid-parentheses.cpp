/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/

class Solution {
public:
/*
    int longestValidParentheses(string s) {
        stack<int> st;
        int maxI = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                st.push(i);
            } else {
                if(!st.empty() && s[st.top()] == '(')
                    st.pop(); // you can compute the answer here itself the next method
                else 
                    st.push(i);
            }
        }
        if(st.empty())
            return s.length();
        else {
            int a = s.length(), b = 0;
            while(!st.empty()) {
                b = st.top(); st.pop();
                maxI = max(maxI, a - b - 1);
                a = b;
            }
            maxI = max(maxI, a); // handle this case "())"
        }
        return maxI;
    }
};
*/
  int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    ans = max(ans, i - stk.top());
                }
            }
        }
        return ans;
    }
};