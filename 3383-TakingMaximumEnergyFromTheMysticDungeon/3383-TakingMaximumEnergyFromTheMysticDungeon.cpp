// Last updated: 11/27/2025, 5:16:44 PM
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) 
    {
        int ans = INT_MIN;
        for(int i = energy.size()-1;i>=0;i--)
        {
            if(i+k < energy.size())
                energy[i]+=energy[i+k];
            ans = max(energy[i],ans);
        }
        return ans;
    }
};