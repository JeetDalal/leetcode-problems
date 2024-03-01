class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') count++;
        }
        for(int i=0;i<s.size();i++){
            if(count-1>0){
                s[i]='1';
            }else if(i==s.size()-1){
                s[i]='1';
            }
            else{
                s[i]='0';
            }
            count--;
        }
        return s;
    }
};