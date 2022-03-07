class Solution {
public:
    // quite easy, just use the feature of sorted arrays.
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<vector<int>> ans;
         sort(intervals.begin(), intervals.end());
         int n = intervals.size();
         int left = intervals[0][0];
         int right = intervals[0][1];
         for (int i = 0; i < n; i++) {
             if (intervals[i][0] <= right) {
                 // update right and skip this loop
                 right = max(right, intervals[i][1]);
                 continue;
             } else {
                 ans.push_back({left, right});
                 // set next left, right
                 left = intervals[i][0];
                 right = intervals[i][1];
             }
         }
         ans.push_back({left, right});
         return ans;
    }
};