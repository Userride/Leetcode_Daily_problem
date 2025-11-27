// Last updated: 11/27/2025, 5:16:47 PM
class Solution {
public:
    int encrypted(int n){
        int sum=0;
        int maxi=-1;
        int copy =n;
        while(copy!=0){
            maxi=max(maxi,copy%10);
            copy=copy/10;
        }
        while(n!=0){
            sum=sum*10;
            sum=sum+maxi;
            n=n/10;
        }
        return sum;
    }
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum=sum+encrypted(nums[i]);
        }
        return sum;
    }
};