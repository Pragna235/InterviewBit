int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int row=A.size();
    int col=A[0].size();
    int low=0;
    int high=(row*col)-1;
    if(!row) return 0;
    while(low<=high){
        int mid = (low+(high-low)/2);
        if(A[mid/col][mid%col]==B)
        return 1;
        if(A[mid/col][mid%col]<B)
        low=mid+1;
        else
        high=mid-1;
    }
    return 0;
}
