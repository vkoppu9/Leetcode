/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:

Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
Example 2:

Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
*/
class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        int result = 0;
        for(int i = 0; i < points.size(); i++) {
            int samePoint = 1;
            unordered_map<long double, int> map;
            for(int j = i + 1; j < points.size(); j++) {
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1]) { // same point
                    samePoint++;
                }
                else if(points[i][0] == points[j][0]) { // x co-ordinates matching so infinite slope 
                    map[INT_MAX]++;
                }
                else { // slope matching 
                    long double slope = (long double)(points[i][1] - points[j][1]) / (long double)(points[i][0] - points[j][0]);
                    map[slope]++;
                }
            }
            int localMax = 0;
            for(auto it = map.begin(); it != map.end(); it++) {
                localMax = max(localMax, it->second);
            }
            localMax += samePoint;
            result = max(result, localMax);
        }
        return result;
    }
};