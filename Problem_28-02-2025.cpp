class Solution {
    public:
        vector<vector<int>> dp;
    
        string shortestCommonSupersequence(string str1, string str2) {
            int n = str1.length();
            int m = str2.length();
            dp.resize(n + 1, vector<int>(m + 1, 0));
    
            
    
            // Fill the DP table
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (str1[i - 1] == str2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
    
            // Backtrack to construct the shortest common supersequence
            int i = n, j = m;
            string ans;
            while (i > 0 && j > 0) {
                if (str1[i - 1] == str2[j - 1]) {
                    ans += str1[i - 1];
                    i--;
                    j--;
                } else if (dp[i - 1][j] > dp[i][j - 1]) {
                    ans += str1[i - 1];
                    i--;
                } else {
                    ans += str2[j - 1];
                    j--;
                }
            }
    
            // Add any remaining characters from str1 or str2
            while (i > 0) {
                ans += str1[i - 1];
                i--;
            }
            while (j > 0) {
                ans += str2[j - 1];
                j--;
            }
    
            // Reverse the answer to get the correct order
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };
    