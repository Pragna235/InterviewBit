int Solution::solve(int A) {
int cnt=0,num=1;
long long mod=1e9+7;
A++;
for(int i=0;i<30;i++){
int x;
x=A/num;x=x/2;x=x*num;
if((A>>i) & 1) x=x+A%num;
cnt=(cnt+x)%(mod);num=num*2;
}
return cnt;
}
