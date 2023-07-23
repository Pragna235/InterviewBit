int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    int c1=0,c2=0,e1,e2;
    for(int i=0;i<n;i++){
        if(c1==0 && A[i]!=e2){
            c1=1;
            e1=A[i];
        }
        else if(c2==0 && A[i]!=e1){
            c2=1;
            e2=A[i];
        }
        else if(A[i]==e1)c1++;
        else if(A[i]==e2)c2++;
        else{
            c1--;
            c2--;
        }
    }
    c1=0,c2=0;
    for(int i=0;i<n;i++){
        if(A[i]==e1)c1++;
        if(A[i]==e2)c2++;
    }
    int mini=int(n/3)+1;
    if(c1>=mini) return e1;
    if(c2>=mini)return e2;
    return -1;
}
