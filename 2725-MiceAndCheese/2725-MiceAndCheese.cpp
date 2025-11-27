// Last updated: 11/27/2025, 5:18:02 PM
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<pair<int, int>> cheese;
        for(int i = 0; i < n; i++) {
            cheese.push_back({reward1[i] - reward2[i], i});
        }
        sort(cheese.rbegin(), cheese.rend());
        
        int total = 0;
        vector<bool> firstMouse(n, false);
        for(int i = 0; i < k; ++i) {
            int idx = cheese[i].second;
            total += reward1[idx];
            firstMouse[idx] = true;
        }
  
        for(int i = 0; i < n; ++i) {
            if(!firstMouse[i]) total += reward2[i];
        }
        return total;
    }
};
