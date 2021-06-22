/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        // when only 1 row is present
        if(numRows == 1)
            return {{1}};
        
        // resultant array that contains answer for numRows <= 2 as we need atleast 2 rows to calculate furthur coming rows.
        // When looked carefully, its actually is an embodiment for DP problems. One can easily get the gist of DP from this simple problem.
        vector<vector<int> > res{{1},{1,1}};
        
        // starting from 3rd row (0-based indexing) to calculate ans for required number of rows
        for(int i = 2; i <numRows; i++)
        {
            // temp vector to store ans for current row, to be later on appended to res array
            vector<int>temp;
            for(int j = 0; j <= i; j++)
            {
                // from observation, we can see that first and last element of any row will be 1, here i is acting as last index of temp array
                if(j == 0 || j == i)
                    temp.push_back(1);
                // else elements between first and last elements can be calculated easily from index just above it and one before the latter( see animation in ques, you'll understand).
                else
                    temp.push_back(res[i-1][j] + res[i-1][j-1]);
            }
            // appending the new row that was just created to res array
            res.push_back(temp);
        }
        return res;
    }
};