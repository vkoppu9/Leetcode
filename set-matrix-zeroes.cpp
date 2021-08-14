/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

You must do it in place.
*/

// using the first row and first col to save if 0
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row = false, col = false;  // to see if the first row or col has 0 is real
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                if(matrix[i][j] == 0) {
                    if(i == 0) row = true;
                    if(j == 0) col = true;
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        // except the first row and col
        for(int i = 1; i < matrix.size(); ++i) {
            for(int j = 1; j < matrix[0].size(); ++j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)  // check with the first row || col 
                    matrix[i][j] = 0;
            }
        }
        if(col) {
            for(int i = 0; i < matrix.size(); ++i) 
            matrix[i][0] = 0;
        }
        if(row) {
            for(int j = 0; j < matrix[0].size(); ++j) 
            matrix[0][j] = 0;
        }
    }
};