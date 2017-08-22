#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    template <class T>
    void printVec(vector<T> &v) {
        for(auto i : v) {
            cout<<i;
        }
        cout<<endl;
    }

    vector<char> findLongestSubstring(string& s) {
        vector<char> res;
        int max = 0;
        for(int i = 0; i < s.size(); i++) {
            int counter = 0;
            int e[128] = {0};
            vector<char> tmp_res;
            int tmp_max = 0;
            for(int j = i; j < s.size(); j++) {
                if(e[s[j]] != 0)
                    break;
                else {
                    e[s[j]]++;
                    tmp_max++;
                    tmp_res.push_back(s[j]);
                }
            }
            //printVec(tmp_res);
            if(tmp_max > max) {
                res = tmp_res;
                max = tmp_max;
            }
        }
        //printVec(res);
        return res;
    }

    int lengthOfLongestSubstring(string s) {
        vector<char> res;
        res = findLongestSubstring(s);
        //printVec(res);
        return res.size();
    }

    //other peoples' solution
    //O(n)
    /**
     * 思路: 记录每个字符上次出现的位置，当又遇到这个字符时，计算此时位置到上次位置之间的距离，
     * 并更新位置信息
     * 如果大于目前最大的子串，则更新最大子串长度
     * @param s
     * @return
     */
    int lengthOfLongestSubstring_others1(string s) {
        int size = s.size();
        if(!size) return 0;

        int index[256] = {0};
        int ans = 0;
        for(int i = 0, j = 0; j < size; ++j) {
            i = max(index[s[j]], i);
            ans = max(ans, j-i+1);
            index[s[j]] = j+1;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout<<s.lengthOfLongestSubstring("abcabcbb")<<endl;
    cout<<s.lengthOfLongestSubstring("bbbbbb")<<endl;
    cout<<s.lengthOfLongestSubstring("pwwkew")<<endl;
    return 0;
}