/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        vector<int> mp1 (256, -1);
        vector<int> mp2 (256, -1);
        
        for(int i = 0; i < s.size(); i++) {
            if(mp1[s[i]] != mp2[t[i]])
                return false;
            
            mp1[s[i]] = mp2[t[i]] = i; // saving index 
        }
        
        return true;
    }
};