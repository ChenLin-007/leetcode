class Solution {
public:
    /*inline int getMinDistance(int pos, vector<int>& heaters) {
        if (pos <= heaters[0]) return abs(heaters[0] - pos);
        if (pos >= heaters[heaters.size() - 1]) return abs(heaters[heaters.size() - 1] - pos);
        int i = 0;
        while(pos > heaters[i] && heaters[i + 1] < pos){
            i++;
        }
        return min(abs(pos - heaters[i]), abs(pos - heaters[i + 1]));
    }*/

    // searching algorithm is important
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        // don't care the house position
        sort(heaters.begin(), heaters.end());
        int ans = INT_MIN;
        int index;
        for (auto pos: houses){
            // upper_bound use binary searching algorithm 
            // find the first element that greater than pos;
            index = upper_bound(heaters.begin(), heaters.end(), pos) - heaters.begin();
            int right = (index >= heaters.size())? INT_MAX: heaters[index] - pos;
            int left = (index <= 0)? INT_MAX: pos - heaters[index - 1];
            ans = max(ans, min(left, right));
        }
        return ans;
    }
};