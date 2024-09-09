class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
            return true;
        }
        
        return false;
    }
    string reverseVowels(string s) {
        int i=0,j=s.size()-1,n=s.size();
        while(i<=j && i<n && j>=0){
            while(!isVowel(s[i]) && i<n && i<=j){
                i++;
            }
            while(!isVowel(s[j]) && j>=0 && i<=j){
                j--;
            }
            if(isVowel(s[i]) && isVowel(s[j])){
                swap(s[i],s[j]);
            i++;
            j--;
            }
        }
         return s;
    }
   
};