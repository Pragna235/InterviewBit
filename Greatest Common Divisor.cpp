int Solution::gcd(int A, int B) {
    while(A>0 && B>0){
        if(A>B) A%=B;
        else B%=A;
    }
    if(A==0) return B;
    return A;
}
