int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int xr=0;
    map<int,int> mpp;
    mpp[xr]++;
    int count=0;
    
    for(int i=0;i<n;i++){
        xr^=A[i];
        int rem = xr^B;
        count+=mpp[rem];
        mpp[xr]++;
    }
    return count;
}
