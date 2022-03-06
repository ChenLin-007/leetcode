class Solution {
public:
    // much more variables will need more memory, use local variables is better
    // sorted arrays
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 3) return res;
        // use sort method
        sort(nums.begin(), nums.end());

        for (int idx1 = 0; idx1 < n; idx1++){
            // first round don't enter into this while loop.
            if (idx1 > 0 && nums[idx1] == nums[idx1 - 1]){
                continue;
            }
            int idx3 = n - 1;
            int target = -nums[idx1];
            for(int idx2 = idx1 + 1; idx2 < n; idx2++) {
                // same with first element, first round don't judge.
                if (idx2 > idx1 + 1 && nums[idx2] == nums[idx2 - 1])
                    continue;
    
                while (idx3 > idx2 && nums[idx2] + nums[idx3] > target) {
                    idx3--;
                }
                // if they meet at the same positon, break;
                if (idx2 == idx3)
                    break;
                
                if (nums[idx2] + nums[idx3] == target)
                    res.push_back({nums[idx1], nums[idx2], nums[idx3]});

            }
        }
        return res;

    }
};