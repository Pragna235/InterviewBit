int Solution::solve(vector<int> &A) {
    int n = A.size();
    if(n==1) return A[0];
    if(A[0]>=A[1]) return A[0];
    if(A[n-1]>=A[n-2]) return A[n-1];
    
    int low=1,high=n-2;
    while(low<=high){
        int mid = (low+high)/2;
        if(A[mid]>=A[mid-1] && A[mid]>=A[mid+1]) return A[mid];
        if(A[mid]>=A[mid-1]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
