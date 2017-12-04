#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll A[100001],B[100001];

int f(ll& n){
  int ct=0;
  while(n%41==0){
    ++ct;
    n/=41;    
  }
  return ct;
}

ll pow_(ll a, ll b, ll mod){
  ll ans=1;
  while(b){
    if(b&1) ans = ans*a%mod;
    b=b>>1;
    a=a*a%mod;
  }
  return ans;
}

void pre(){   // find modulo 41*41
  A[1]=2;
  ll pow_41=0,num,den,temp=2;
  for(int i=2;i<=100000;++i){
    num=2*(2*i-1),den=i;
    pow_41 += f(num)-f(den);
    temp = temp*num%1681;
    temp = temp*pow_(den,1639,1681)%1681;   // phi(41*41=1681) = 1640
    A[i]=temp*pow_(41,pow_41,1681)%1681;
  }
}
void pre1(){  //find modulo 148721
  B[1]=2;
  ll num,den;
  for(int i=2;i<=100000;++i){
    num=2*(2*i-1),den=i;
    B[i] = B[i-1]*num%148721;
    B[i] = B[i]*pow_(den,148719,148721)%148721;
  }
}
void use_crt(){
  ll n1=2,n2=1681,n3=148721,m2,m3,c2,c3;
  m2 = n1*n3, m3 = n1*n2;
  c2 = m2*pow_(m2,1639,n2);
  c3 = m3*pow_(m3,n3-2,n3);
  for(int i=1;i<=100000;i++){
    A[i] = (A[i]*c2%500000002 + B[i]*c3%500000002)%500000002;
    //  if(i==94012) cout << A[i] <<" " << B[i] <<endl;
  }
  A[0]=1; // 0 chose 0 is 1
}
ll crt_again(ll n1, ll n2, ll a, ll b){
  ll m1=n2,m2=n1;
  m1 = m1*pow_(m1,n1-2,n1)%1000000006;
  m2 = m2*pow_(m2,n2-2,n2)%1000000006;
  return (m1*a%1000000006 + m2*b%1000000006)%1000000006;
}
int main()
{
  pre();
  pre1();
  use_crt();
  int t; 
  ll a,b,n;
    ifstream fin;
    fin.open("testfile.txt");
  //scanf("%d",&t);
    fin>>t;
    ofstream fout;
    fout.open("output2.txt");
  while(t--){
    //scanf("%lld%lld%lld",&a,&b,&n);
    fin>>a>>b>>n;
    ll ans = A[n];
    ans = pow_(b,ans,500000003);
    ans = crt_again(2,500000003,b%2,ans);
    if(b==0) ans = 0;
    ans = pow_(a,ans,1000000007);
    //printf("%lld\n",ans);
    fout<<ans<<endl;
  }
  return 0;
}
