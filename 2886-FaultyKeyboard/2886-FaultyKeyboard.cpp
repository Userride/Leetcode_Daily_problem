// Last updated: 11/27/2025, 5:17:45 PM
class Solution {
public:
    string finalString(string s) {
        string result="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='i'){
                reverse(result.begin(),result.end());
            }else{
                result=result+s[i];
            }
        }
        return result;
    }
};