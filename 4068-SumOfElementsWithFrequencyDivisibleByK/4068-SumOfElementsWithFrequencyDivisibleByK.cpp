// Last updated: 11/28/2025, 12:48:27 PM
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int sum=0;
        for(auto & it:mp){
            if(it.second % k==0){
                sum=sum+it.first*it.second;
            }
        }
        return sum;
    }
};