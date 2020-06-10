/*
class Solution {
public:
    int lcs(string str1,string str2,int a,int b){
        int dp[a+1][b+1];
        for(int i = 0; i <= a; i++){
            dp[i][0] = 0;
        }
        for(int j = 1; j <= b; j++){
            dp[0][j] = 0;
        }
        for(int i = 1; i <= a; i++){
            for(int j = 1; j <= b; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[a][b];
    }
    bool isSubsequence(string s, string t) {
        int ans = lcs(t,s,t.length(),s.length());
        return ans == s.length();
    }
};
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0) return true;
        if(t.size() == 0) return false;
        if(s.at(0) == t.at(0))
            return isSubsequence(s.substr(1), t.substr(1));
        return isSubsequence(s, t.substr(1));
    }
};