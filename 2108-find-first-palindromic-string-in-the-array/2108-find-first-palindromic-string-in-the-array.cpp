class Solution {
public:
    bool isPal(string &s){
        int sz = s.size();
        for(int i=0;i<sz/2;i++){
            if(s[i] != s[sz-i-1]){
                return false;
            }
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int ss=words.size();
        for(int i=0;i<ss;i++){
            if(isPal(words[i])){
                return words[i];
            }
        }
        return "";
    }
};