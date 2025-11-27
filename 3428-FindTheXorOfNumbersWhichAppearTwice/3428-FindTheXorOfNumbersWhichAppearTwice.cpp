// Last updated: 11/27/2025, 5:16:38 PM
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int>mp;
        int n=nums.size();
        for (int i=0;i<n;i++ ) {
            mp[nums[i]]++;
        }

        int result = 0;
        for (auto& it:mp) {
            if (it.second== 2) {
                result ^= it.first;
            }
        }
        return result;
    }
};
