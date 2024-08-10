vector<int> Solution::solve(vector<int> &A) {
    //vector<int> ans;
    int pos=0,neg=0;
    int n = A.size();
    for(int i=0;i<n;i++){
        if(A[i]>0){
            pos++;
        }
        else if(A[i]<0) neg++;
    }
    return {pos,neg};
}
