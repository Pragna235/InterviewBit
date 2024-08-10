int Solution::maxProduct(const vector<int> &A) {
    int n = A.size();
    double pre=1,suf=1;
    double maxi = INT_MIN;
    for(int i=0;i<n;i++){
        if(pre==0) pre=1;
        if(suf==0) suf=1;
        
        pre*=A[i];
        suf*=A[n-i-1];
        maxi = max(maxi,max(pre,suf));
    }
    return maxi;
}
