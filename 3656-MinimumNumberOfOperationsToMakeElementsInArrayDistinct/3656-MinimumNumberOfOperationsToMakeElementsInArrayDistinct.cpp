// Last updated: 12/1/2025, 12:51:58 PM
class Solution {
public:
    int minimumOperations(vector<int>& a) {

        int n=a.size(),ans=0;

        for(int i=0;i<n;i+=3){
            unordered_set<int> s(a.begin()+i,a.end());
            if(s.size()==n-i) return ans;
            else ans++;
        }
        return ans;
    }
};