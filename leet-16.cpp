class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res; 
        int diff = INT_MAX;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // use lambda expression
        auto update = [&](int value) {
            int cur = abs(value - target);
            if (cur < diff) {
                res = value;
                diff = cur;
            }
        };

        for(int first = 0; first < n; first++){
            if (first > 0 && nums[first] == nums[first - 1])
                continue;
            int second = first + 1;
            int third = n - 1;
            
            int cur = abs(nums[first]);
            // nums[first] + nums[second] + nums[third] - target < diff
            while (second < third) {
                // 
                int temp = nums[first] + nums[second] + nums[third];
                update(temp);

                if (temp == target) return target;

                if (temp > target) {
                    // third number shift left
                    int k = third - 1;
                    while(k > second && nums[k] == nums[third]) {
                        k--;
                    }
                    third = k;
                } else {
                    // second nums shift right, skip the same number
                    int j = second + 1;
                    while (j < third && nums[j] == nums[second])
                        j++;
                    second = j;
                }
            }
        }
        return res;
    }
};