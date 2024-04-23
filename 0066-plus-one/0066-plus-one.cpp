class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        bool carry=false;
        int n=v.size()-1;
        if(v[n]+1>9){
            v[n]=0;
            carry=true;
        }else{
            v[n]++;
            return v;
        }
        // n--;
        while(n--){
            if(carry){
                if(v[n]+1<=9){
                    v[n]++;
                    return v;
                }
                v[n]=0;
                carry=true;
            }
        }
        v.insert(v.begin(),1);
        return v;
    }
};