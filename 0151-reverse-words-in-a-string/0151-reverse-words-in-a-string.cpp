class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        vector<string> v;
        
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                string x="";
                while(s[i] != ' ' && i<s.size()){
                    x+=s[i];
                    i++;
                }
                v.push_back(x);
            }
        }
        
        for(int i=0;i<v.size();i++){
            ans+=v[v.size()-i-1];
            if(i!=v.size()-1){
                ans+=' ';
            }
        }
        
        
        return ans;
    }
};