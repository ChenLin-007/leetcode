class Solution {
public:
    string res;
    // center-expand algorithm is one of the easiest algorithm. and has not bad efficency.
    void check(string s, int l, int r){
        int n = s.length();
        while (l >= 0 && r < n && s[l] == s[r]){
            if (r - l + 1 > res.length()){
                res = s.substr(l, r - l + 1);
            }
            l--, r++;
        }
    }

    string longestPalindrome(string s) {
        int n = s.length();
        for (int i = 0; i < n; i++){
            check(s, i, i);
            check(s, i, i+1);
        }
        return res;
    }
};