int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size();
    long long maxi = LONG_MIN;
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=A[i];
        if(sum>maxi){
            maxi=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maxi;
}
