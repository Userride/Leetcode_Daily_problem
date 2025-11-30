// Last updated: 11/30/2025, 11:00:04 PM
class Solution {
public:
    int possibleStringCount(string word) {
      int count=0;
      for(int i=0;i<word.size();i++){
        if(word[i]==word[i+1]){
          count++;
        }
      }
      return count +1;
        
    }
};