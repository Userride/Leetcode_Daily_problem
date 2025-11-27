// Last updated: 11/27/2025, 5:18:03 PM
class Solution {
public:

    int solve(vector<int>& nums, int maxdiff, int p)
    {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n-1;i++)
        {
            if((nums[i+1]-nums[i])<=maxdiff)
            {
                cnt++;
                i++;
            }
        }
        return cnt;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        if(n==1) return 0;
        sort(nums.begin(), nums.end());

        int left=0, right=nums[n-1]-nums[0];
        int ans=right;

        while(left<=right)
        {
            int mid=left+(right-left)/2;

            //no. of pairs satisfyingthe the criteria: max diff between pair elements <= mid
            int paircnt=solve(nums,mid,p); 

            if(paircnt>=p)
            {
                right=mid-1;
                ans=min(ans,mid);
            }
            else
            left=mid+1;
        }

        return ans;
    }
};