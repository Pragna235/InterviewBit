int Solution::uniquePaths(int A, int B) {
    int N = A + B -2;
    int r = A-1;
    double res = 1;
    for(int i=1;i<=r;i++){
        res = res * (N-r+i)/i;
    }
    return (int)res;
}
