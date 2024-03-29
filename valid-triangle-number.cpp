class Solution {
public:
    int triangleNumber(vector<int>& a) {
        int res = 0;
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());    // a is decreasing
        for (int i = 0; i + 2 < a.size(); i++) {
            for (int j = i + 1, k = a.size() - 1; j < k; j++) {
                while (a[j] + a[k] <= a[i]) {
                    k--;
                }
                res += k - j;
            }
        }
        return res;
    }
};