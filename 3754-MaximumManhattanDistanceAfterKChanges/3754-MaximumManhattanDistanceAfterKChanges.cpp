// Last updated: 11/29/2025, 4:15:35 PM
class Solution {
public:
    int maxDistance(string s, int k) {
        int N=0,S=0,E=0,W=0;
        int maxi=0;
        for(auto c:s){
            if(c=='N')
            N+=1;
            else if(c=='S')
            S+=1;
            else if(c=='E')
            E+=1;
            else
            W+=1;
          int miniY=min(N,S);
          int miniX=min(E,W);
           int ans=abs(E-W)+abs(S-N);
        ans+=min(k,miniX+miniY)*2;
        maxi=max(maxi,ans);
        }
       
        return maxi;
        
    }
};