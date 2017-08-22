#include <iostream>

using namespace std;

class Solution {
private:
    bool isPalindrome(string s) {
        int len = s.size();
        for (int i = 0, j = len - 1; i <= j; i++, j--) {
            if(s[i] != s[j])
                return false;
        }
        return true;
    }

    int expandAroundCenter(string s, int left, int right) {
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s.at(L) == s.at(R)) {
            L--;
            R++;
        }
        return R - L - 1;
    }

public:
    string longestPalindrome(string s) {
        int ht[128] = {0};
        int len = s.size();
        string res;
        for(int i = 0; i < len; i++) {
            if(ht[s[i]] != 0) {

            }
        }
        return res;
    }

    /**
     * TLE 时间复杂度O(n^3)
     * @param s
     * @return
     */
    string longestPalindrome_tle(string s) {
        int len = s.size();
        string res;
        if(len <= 0) return res;
        int max = 0;
        for(int i = 0; i < len; i++) {
            for(int j = len - 1; j >= i; j--) {
                string sub = s.substr(i, j - i + 1);
                //cout<<s<<", substring is "<<sub<<endl;
                if(isPalindrome(sub)) {
                    int max_tmp = sub.length();
                    if(max_tmp > max) {
                        res = sub;
                        max = max_tmp;
                    }
                }
            }
        }
        return res;
    }

    //other peoples' solution
public:
    /**
     * Expand Around Center
     * 思想：以每个点或者临近的两个点开始搜索最长点子串，最差情况下O(n^2)
     * @param s
     * @return
     */
    string longestPalindrome_expandAroundCenter(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end + 1);
    }

    //@todo to be complete
    string longestPalindrome_dp(string s) {
        int len = s.length();
        string res;
        if(len <= 0) return res;
        bool dp[len][len] = {false};
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < len; j++) {
                if(i == j) {
                    dp[i][j] = true;
                }
            }
        }
    }
};

int main() {
    cout<<"test case:"<<endl;
    Solution s;
    cout<<s.longestPalindrome("babad")<<endl;
    cout<<s.longestPalindrome("cbbd")<<endl;
    return 0;
}