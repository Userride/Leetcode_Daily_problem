// Last updated: 11/27/2025, 5:18:09 PM
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefixSum(words.size() + 1, 0);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        // Calculate the prefix sum array
        for (int i = 0; i < words.size(); ++i) {
            if (vowels.count(words[i].front()) && vowels.count(words[i].back())) {
                prefixSum[i + 1] = prefixSum[i] + 1;
            } else {
                prefixSum[i + 1] = prefixSum[i];
            }
        }
        
        vector<int> ans;
        for (const auto& query : queries) {
            int li = query[0], ri = query[1];
            ans.push_back(prefixSum[ri + 1] - prefixSum[li]);
        }
        
        return ans;
    }
};
