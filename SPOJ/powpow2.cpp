#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 1000000007
#define phiM 1000000006
#define phiphiM 500000002
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;


ll maxval=100000;


ll ModE(ll A,ll M_,ll P)
{
    ll res = 1;     
  
    while (P > 0)
    {
       
        if (P & 1)
            res = (res*A)%M_;
  
        
        P = P>>1; 
        A = (A*A)%M_ ;  
    }
    return res;
    
}

ll E_GCD(ll a,ll b,ll &x,ll &y)
{
    if(a==0)
    {
        x=0;
        y=1;
        
        return b;
        
    }
    ll X1,Y1;
    ll gcd = E_GCD(b%a,a,X1,Y1);
    x=Y1-(b/a)*X1;
    y=X1;
    
    
    return gcd;
    
}

ll inv(ll n, ll mod)
{
    ll x,y;
    E_GCD(n,mod,x,y);
    while(x<0) x=x+mod;
    return x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    vll pow2(3*maxval,0);
    vll pow41(3*maxval,0);
    vll fact(3*maxval,1);
    for(ll i=2;i<=2*maxval+1;i++)
    {
        ll t=i;
        while(t%2==0)
        {
            t=t/2;
            pow2[i]++;
            //pow2[i]+=pow2[t];
        }
        while(t%41==0)
        {
            t=t/41;
            pow41[i]++;
            //pow41[i]+=pow41[t];
        }
        fact[i]=(fact[i-1]*t)%phiphiM;
    }
    for(int i=2;i<=2*maxval+1;i++)
    {
        pow2[i]+=pow2[i-1];
        pow41[i]+=pow41[i-1];
    }
    int tt;
    cin>>tt;
    while(tt--)
    {
        ll a,b,n;
        cin>>a>>b>>n;
        if(b==0)
        {
            cout<<1<<endl;
            continue;
        }
        ll fact2n=fact[2*n];
        ll pow22n=pow2[2*n];
        ll pow412n=pow41[2*n];
        ll factn=fact[n];
        ll pow2n=pow2[n];
        ll pow41n=pow41[n];
        //cout<<"fact2n"<<fact[2*n]<<" factn"<<fact[n]<<endl;
        //cout<<"pow22n"<<pow22n<<" pow2n"<<pow2n<<endl;
        
        pow412n-=(2*pow41n);
        pow22n-=(2*pow2n);
        //cout<<"pow412"<<pow412n<<" pow22"<<pow22n<<endl;
        //cout<<fact2n<<endl;
        fact2n=(fact2n*ModE((ll)41,phiphiM,pow412n))%phiphiM;
        //cout<<fact2n<<endl;
        fact2n=(fact2n*ModE((ll)2,phiphiM,pow22n))%phiphiM;
        //cout<<fact2n<<endl;
        ll ttt=inv(factn,phiphiM);
        //cout<<"inv"<<ttt<<endl;
        ll choose=(((fact2n*ttt)%phiphiM)*ttt)%phiphiM;
        //cout<<"choose"<<choose<<endl;
        //cout<<b<<" "<<a<<endl;
        ll ob=b;
        //b=ModE(b,phiM,choose);
        if(ob%2==0 && ob!=0)
        {
            b=ModE(b,phiphiM+1,choose);
            b=(b*2*inv(2,phiphiM+1))%phiM;
        }
        else
        {
            b=ModE(b,phiM,choose);
            
        }
        ll ans=ModE(a,M,b);
        cout<<ans<<endl;
    }
	return 0;
}

