class Solution {
public:
    vector<string> ans;
    string path;

    void solve(string &digits, int i, vector<string> &mp) {
        if (i == digits.size()) {
            ans.push_back(path);
            return;
        }

        for (char c : mp[digits[i] - '2']) {
            path += c;
            solve(digits, i + 1, mp);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        vector<string> mp = {
            "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        solve(digits, 0, mp);
        return ans;
    }
};