class Solution {
public:
    bool isVowel(char x){
        if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='A' || x=='E' || x=='I' || x=='O' || x=='U'){
            return true;
        }else{
            return false;
        }
    }
    bool halvesAreAlike(string s) {
        int count =0;
        for(int i=0;i<s.size();i++){
            if(i<s.size()/2){
                if(isVowel(s[i])){
                    count++;
                }
            }else{
                if(isVowel(s[i])){
                    count--;
                }
            }
        }
        if(count ==0){
            return true;
        }else{
            return false;
        }
    }
};