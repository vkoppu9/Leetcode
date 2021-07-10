/*
You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.

 

Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: 
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: 
The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
*/

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        //check
        if(words.empty() || chars.empty()) {
            return 0;
        }
        
        vector<int> m(128, 0);
        //initialize the dictionary
        for(int i : chars) {
            m[i]++;
        }
        
        int length_sum = 0;
        for(int i = 0; i < words.size(); ++i) {
            vector<int> vec(128);
            bool flag = true;
            for(int j = 0; j < words[i].size(); ++j) {
                vec[words[i][j]]++;
                if(vec[words[i][j]] > m[words[i][j]]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                length_sum += words[i].size();
            }
        }
        return length_sum;
    }
};