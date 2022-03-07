class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int m = num1.size();
        int n = num2.size();
        vector<int> res(m + n + 1, 0);
        for(int i = m-1; i>=0; i--) {
            int x = num1[i] - '0';
            for(int j = n-1; j>=0; j--){
                int y = num2[j] - '0';
                res[i + j + 1] += x * y;
            }
        }

        for (int i = m + n - 1; i>0; i--){
            res[i-1] += res[i]/10;
            res[i] %= 10;
        }

        string ans;
        int i = 0;
        while(res[i] == 0){
            i++;
        }
        if (res[i] > 9) ans.push_back(res[i]/10 - '0');
        res[i] %= 10;
        for(; i<m + n; i++) {
            ans.push_back(res[i] + '0');
        }
        return ans;
    }
};