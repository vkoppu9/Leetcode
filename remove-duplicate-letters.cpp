class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> visited(26, 0); // True if character is in stack, else false
        vector<int>  count(26, 0);   // How many of this charaters are remaining
        stack<int>   st;             // Stack of unique charaters
        string       ans;            // result   
        
        for (auto c: s)
            count[c-'a']++;
        
        for (auto c : s) {
            int idx = c - 'a';
            count[idx]--;
            if (!visited[idx]) {
                visited[idx] = true;
                while(!st.empty() && count[st.top()] && st.top() > idx) {
                    visited[st.top()] = false;
                    st.pop();
                }
                st.push(idx);
            }
        }
        
        while(!st.empty()) {
            ans = string(1, 'a'+st.top()) + ans;
            st.pop();
        }
        return ans;
    }
};