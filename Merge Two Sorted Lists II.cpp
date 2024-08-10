void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    //
    int n = A.size();
    int m = B.size();
    
    
    vector<int> ans(n+m,0);
    int left=n-1,right=0;
    
    while(left>=0 && right<m){
        if(A[left]>B[right]){
            swap(A[left],B[right]);
            left--,right++;
        }
        else{
            break;
        }
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    A.resize(m+n);
    
    /*for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    for(int i=0;i<m;i++){
        cout<<B[i]<<" ";
    }*/
    
    int j=m-1,k=(m+n-1);
    
    while(j>=0){
        A[k] = B[j];
        j--;
        k--;
    }
    
}
