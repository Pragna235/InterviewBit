int Solution::isPalindrome(int A) {
    long long int sum=0,rem,y=A;
    while(A>0)
    {
        rem=A%10;
        A=A/10;
        sum=rem+(10*sum);
    }
    if(y==sum)
    return 1;
    else
    return 0;
    
}
