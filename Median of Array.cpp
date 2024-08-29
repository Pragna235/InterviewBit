double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n1 = A.size();
    int n2 = B.size();
    if(n1>n2) return findMedianSortedArrays(B,A);
    
    int low=0,high=n1;
    int left=(n1+n2+1)/2;
    int n = n1+n2;
    
    while(low<=high){
        int mid1 = (low+high)/2;
        int mid2 = left-mid1;
        
        int l1=INT_MIN, l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;
        
        if(mid1<n1) r1=A[mid1];
        if(mid2<n2) r2=B[mid2];
        if(mid1-1>=0) l1=A[mid1-1];
        if(mid2-1>=0) l2=B[mid2-1];
        
        if(l1<=r2 && l2<=r1){
            if(n%2==1) return max(l1,l2);
            return ((double)(max(l1,l2) + min(r1,r2))) / (2.0);
        }
        else if(l1>r2){
            high=mid1-1;
        }
        else{
            low=mid1+1;
        }
    }
    return 0;
    
}
