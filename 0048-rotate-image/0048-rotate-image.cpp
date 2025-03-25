class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        swap(matrix[i][j],matrix[j][i]);
       for(int i=0;i<n;i++){
        int st=0,ed=n-1;
        while(st<ed){
         swap(matrix[i][st],matrix[i][ed]);
         st++,ed--;
        }
    }
     
    }
};