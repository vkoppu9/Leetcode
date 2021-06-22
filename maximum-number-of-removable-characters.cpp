class Solution {
public:
    // checks if p is a substring of s
    bool check(string &s, string &p) {
        int i = 0, j = 0;
        while(i < s.size() && j < p.size()) {
            if(s[i] == p[j]) {
                i++; j ++;
            }else {
                i++;
            }
        }
        if(j == p.size()) {
            return true;
        } else {
            return false;
        }
    }
    
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l = 0, r = removable.size();
        while(l < r) {
            int mid = (l + r) / 2;
            string s1 = s;
            
            for(int i = 0; i < mid; i++) {
                s1[removable[i]] = '-';
            }
            if(check(s1, p)) {
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        string s1 = s;
        for(int i = 0; i < l; i++) {
            s1[removable[i]] = '-';
        }
        if(check(s1, p)) 
            return l;
        return l - 1;
    }
};