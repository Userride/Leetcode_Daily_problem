// Last updated: 11/27/2025, 5:15:29 PM
class Solution {
public:
    
    struct compare {
        bool  operator() (pair<int,int>p1, pair<int,int>p2) {
            if(p1.first == p2.first) return p1.second < p2.second;
            return p1.first < p2.first;
        }
    };

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

        vector<int>ans;

        for(int i=0; i<n-k+1; i++) {
            unordered_map<int,int>mp;
            int sum = 0;
            for(int j=i; j<i+k; j++) {
                sum += nums[j];
                mp[nums[j]]++;
            }

            if(mp.size() <= x) {
                ans.push_back(sum);
                continue;
            } 
            
            priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;

            for(auto i : mp) {
                pq.push({i.second,i.first});
            }

            int y = x;
            sum = 0;

            while(y--) {
                pair<int,int>p = pq.top();
                pq.pop();
                sum += (p.first*p.second);
            }

            ans.push_back(sum);

        }

        return ans;
    }
};