vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int> ans;
    int row=A.size();
    int col=A[0].size();
    int top=0,left=0,bottom=row-1,right=col-1;
    
    while(left<=right && top<=bottom){
        for(int i=left;i<=right;i++){
            ans.push_back(A[top][i]);
        }
        top++;
        
        for(int i=top;i<=bottom;i++){
            ans.push_back(A[i][right]);
        }
        right--;
        
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(A[bottom][i]);
            }
            bottom--;
        }
        
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(A[i][left]);
            }
            left++;
        }
    }
    return ans;
}
