// Last updated: 11/30/2025, 11:00:09 PM
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
     vector<int> ans;
        
        for (int num : nums) {
            bool found = false;
            for (int x = 0; x <= num; x++) {
                if ((x | (x + 1)) == num) {
                    ans.push_back(x);
                    found = true;
                    break;
                }
            }
            if (!found) ans.push_back(-1);
        }
        
        return ans;
    }
};