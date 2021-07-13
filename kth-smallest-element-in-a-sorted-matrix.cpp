/*
Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
 

Constraints:

n == matrix.length
n == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n2
*/

//priority queue
/* 
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        priority_queue<int>pq;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pq.push(matrix[i][j]);
                if (pq.size() > k)
                    pq.pop();
            }
        }
        
        return pq.top();
    }
};
*/
//binary search
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int i, j, cnt=0, low, high, mid, m = matrix.size();
        if(k > m * m || m == 0)
            return 0;
        low = matrix[0][0];
        high = matrix[m-1][m-1];
        while(low < high) {
            mid = low + (high - low) / 2;
            cnt = 0;
            j = m - 1;
            for(i = 0; i < m; i++){
                while(j >= 0 && matrix[i][j] > mid)
                    j--;
                cnt += j + 1;
            }
            if(cnt < k)
                low = mid + 1;
            else
                high = mid;
        }
        return high;
    }
};