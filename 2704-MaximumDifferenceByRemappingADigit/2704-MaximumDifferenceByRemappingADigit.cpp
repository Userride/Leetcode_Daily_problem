// Last updated: 11/27/2025, 5:18:07 PM
class Solution {
public:
    int minMaxDifference(int num) {
      string s= to_string(num);
      int id=0;
      char c=s[0];
      for(int i=0;i<s.size();i++){
        if(s[i]!='9'){
          c=s[i];
          id=i;
          break;
        }
      }
      string s1="";
       for(int i=0;i<s.size();i++){
        if(s[i]==c){
          s1=s1+'9';
         
        }
        else{
          s1=s1+s[i];
        }
      }
      string s2="";
       for(int i=0;i<s.size();i++){
        if(s[i]==s[0]){
          s2=s2+'0';
         
        }
        else{
          s2=s2+s[i];
        }
      }
      int val1=stoi(s1);
      int val2=stoi(s2);
      return (val1-val2);
        
    }
};