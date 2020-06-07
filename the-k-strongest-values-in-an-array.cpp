class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> res;
        sort(arr.begin(), arr.end());
        int m = arr[(n-1)/2];
        auto comp = [&](const int& p1, const int& p2)
                        { return abs(p1-m) > abs(p2-m) || abs(p1-m) == abs(p2-m) && (p1 > p2); };
        sort(arr.begin(), arr.end(), comp);
        for(int i = 0; i < arr.size() && k--; i++)
            res.push_back(arr[i]);
        return res;
    }
};