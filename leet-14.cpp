class Solution {
public:
    // this issue is quite easy,but how to reduce excute time and memory usage is the main question.
    // I try to use less loop to reduce time, and finally not bad.
    // but memory use is not good.
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0)
            return "";
        if (n == 1)
            return strs[0];
        string res;
        bool over = false;
        for (int idx = 0; ; idx++) {
            for(int i = 1; i < n; i++) {
                if(idx < strs[i].length() && strs[i][idx] == strs[i-1][idx]){
                    continue;
                }else{
                    over = 1;
                    break;
                }
                
            }
            if (over){
                break;
            }
            res.push_back(strs[0][idx]);
        }
        return res;
    }
};