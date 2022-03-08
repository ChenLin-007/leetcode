class Solution {
public:
    vector<string> res;
    string ans;
    void back_track(vector<bool> &vis, string s, int l, int n) {
        if (l == n)
            res.push_back(ans);
        else {
            for (int i = 0; i < n; i++) {
                // if visited, continue
                // slove reapted char problem with sorted arrays, that make the releative position of the same number is fixed. 
                if (vis[i] || (i > 0 && !vis[i - 1] &&s[i] == s[i - 1]))
                    continue;
                vis[i] = true;
                ans.push_back(s[i]);
                back_track(vis, s, l + 1, n);
                vis[i] = false;
                ans.pop_back();
            }
        }
    }

    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        int n = s.size();
        vector<bool> vis(n, 0);
        back_track(vis, s, 0, n);
        return res;
    }
};