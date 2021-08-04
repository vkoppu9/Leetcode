/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

class Solution {

    void subUtil(vector<int>& nums, int l, vector<int>& v, vector<vector<int>>& ans) {
        
        if (find(ans.begin(), ans.end(), v) == ans.end())
            ans.push_back(v);
        
        if (l >= nums.size())
            return;
        
        for (int i = l; i < nums.size(); i++) {
            v.push_back(nums[i]);
            subUtil(nums, i+1, v, ans);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>v;
        vector<vector<int>>ans;
        
        sort(nums.begin(), nums.end());
        subUtil(nums, 0, v, ans);
        return ans;
    }
};