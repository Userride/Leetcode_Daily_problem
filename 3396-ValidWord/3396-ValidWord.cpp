// Last updated: 11/27/2025, 5:16:41 PM
class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3){
            return false;
        }
        bool hasvowel=false;
        bool hasconsant=false;
        for(char ch:word){
            if(isalpha(ch)){
                ch=tolower(ch);
                if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                    hasvowel=true;
                }
                else{
                    hasconsant=true;
                }
            }
            else if(! isdigit(ch)){
                return false;
            }
        }
        return hasvowel && hasconsant;
        
    }
};