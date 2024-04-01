class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.size()-1;
        if(s[i] == ' '){
            while(s[i] == ' '){
                i--;
            }
        }
        for(int j=i;j>=0;j--){
            if(s[j]== ' ') return(i-j); 
        }
        return i+1;
    }
};