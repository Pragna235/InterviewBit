int Solution::sqrt(int A) {
    long long int low=1,high=A;
    while(low<=high){
        long long mid = (low+high)/2;
        long long val = mid* mid;
        if(val<=A) low=mid+1;
        else high=mid-1;
    }
    return high;
}
