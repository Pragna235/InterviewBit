int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int left_sum=0;
    int max_sum=0;
    for(int i=0;i<B;i++){
        left_sum+=A[i];
    }
    max_sum = left_sum;
    
    int right_sum=0;
    for(int i=n-1,j=B-1;j>=0;i--,j--){
        right_sum+=A[i];
        left_sum-=A[j];
        max_sum = max(max_sum, left_sum + right_sum);
    }
    return max_sum;
}
