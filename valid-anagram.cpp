/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) 
            return false;
        unordered_map<char,int> hash;
        for(int i = 0; i < s.size(); i++){
            hash[s[i]]++;
            hash[t[i]]--;
        }
        for(auto &i : hash){
            if(i.second != 0) 
                return false;
        }
        return true;
    }
};