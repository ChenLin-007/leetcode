class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 使用集合来统计先前子串的字符，在这道题是最适合的数据结构
        unordered_set<char> set;
        int n = s.length();
        int r =  0;
        int res = 0;
        for(int i = 0; i < n; i++) {
            if (i != 0){
                // 这里巧妙的使用-1 作为第一个索引，这样就可以让右指针先走，因为第一次遍历不会进入这个分支。
                set.erase(s[i -1 ]);
            }

            //  loop condition
            //  1. index < n.
            //  2. set don't have the element.
            while(r < n && ! set.count(s[r])){
                set.insert(s[r]);
                ++r;
            }
            res = max(r- i, res);

        }

        return res;;
    }
};