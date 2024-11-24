class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int negativeCount=0,smallest=INT_MAX;
        long long sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0){
                    negativeCount++;
                }
                smallest=min(smallest,abs(matrix[i][j]));
                sum+=abs(matrix[i][j]);
            }
        }
        cout<<negativeCount<<"  "<<sum<<endl;
        if(negativeCount%2==0) return sum;
        return (sum - 2*smallest);
    }
};