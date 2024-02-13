class Solution {
public:
    bool isPal(string &s){
        for(int i=0;i<s.size()/2;i++){
            if(s[i] != s[s.size()-i-1]){
                return false;
            }
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(isPal(words[i])){
                return words[i];
            }
        }
        return "";
    }
};