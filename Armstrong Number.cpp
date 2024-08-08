int Solution::solve(int A) {
// calculating no. of digits in a number
    int dig_count = (int)log10(A)+1;
   
    long sum = 0;
    int A1=A;
    while(A1>0){
       long d = A1%10;
       sum+=pow(d,dig_count);
       A1=A1/10;
    }
    if(sum==A){
        return 1;
    }
    return 0;
}
