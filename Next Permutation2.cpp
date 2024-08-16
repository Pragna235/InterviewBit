vector<int> Solution::nextPermutation(vector<int> &A) {
    int ind=-1;
    int n = A.size();
    for(int i=n-2;i>=0;i--){
        if(A[i]<A[i+1]){
            ind=i;
            break;
        }
    }
    if(ind==-1){
        reverse(A.begin(),A.end());
        return A;
    }
    for(int i=n-1;i>=0;i--){
        if(A[i]>A[ind]){
            swap(A[i],A[ind]);
            break;
        }
    }
    reverse(A.begin()+ind+1,A.end());
    return A;
}
