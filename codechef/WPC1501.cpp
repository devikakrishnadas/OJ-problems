#include<bits/stdc++.h>
#define ll unsigned long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 1000000007
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

int val=1000000;
vi prime(val+1,0);

void sieve()
{
    for(int i=2;i<=1000000;i++)
    {
        if(!prime[i])
        {
            for(int j=2;i*j<=1000000;j++)
            {
//                cout<<i<<" "<<j<<endl;
                prime[i*j]=1;
            }
            
        }
    }
}

ll Phi (ll n) {
    ll result = n;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    if (n > 1)
        result -= result / n;
    return result;}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin>>t;
    //t=1000;
    sieve();
    while(t--)
    {
        ll n,phi;
        cin>>n>>phi;
        //n=t;
        //phi=Phi(n);
        ll phiR=1,valR=1;
        if(phi==n-1)
        {
            cout<<n<<endl;
            continue;
        }
        vll fac;
        ll ttn=n;
        // take the factors <= 1000000
        for(int i=2;i<=val;i++)
        {
            if(!prime[i])
            {
                if(n%i==0)
                {   
//                    cout<<"iphir: "<<i<<endl;
                    phiR*=(i-1);
                }
                while(n%i==0)
                {
                    n=n/i;
                    valR*=i;
                    fac.pb(i);
                }
            }
        }
  /*      if(n==1)
        {
            for(int i=0;i<fac.size();i++)
            {
                cout<<fac[i]<<" ";
            }
            cout<<endl;
            continue;
        }
    */    //phiR*=valR;
        ll tvalR=valR;
//        cout<<valR<<" "<<phiR<<endl;
        for(int i=2;i<=val;i++)
        {
            if(ttn%i==0 && !prime[i])
            {
                tvalR/=i;
            }
        }
        phiR=phiR*tvalR;
        ll tn=ttn/valR;// tn can be product of 2 numbers greater than 1000000
        //cout<<"ttn :"<<ttn<<endl;
        ll phin=phi/phiR;
//        cout<<"phitt "<<phitt<<endl; 
  //      cout<<"tn :"<< tn<<" phin :"<<phin<<endl; 
//        cout<<"valR "<<valR<<" phiR :"<<phiR<<endl;
        if(phin==tn-1)
        {
            fac.pb(tn);
        }
        else if(tn>1)
        {
  //          cout<<"r1"<<endl;
            long double b=(tn+1-phin);
            long double c=tn;
            long double ss=sqrt(b*b-4*c);
        //    cout<<tn+1-phin<<" "<<tn<<endl;
      //      cout<<b*b-4*c<<endl;
            ll p=tn-phin;
            if(p*p==n)
            {
                fac.pb(p);
                fac.pb(p);
                sort(all(fac));
        //        reverse(all(fac));
                for(int i=0;i<fac.size();i++)
                {
                    if(fac[i]>1)
                    cout<<fac[i]<<" ";
                //    ttn=ttn/fac[i];
                }
                cout<<endl;
                continue;
            }
    //        cout<<"SS :"<<ss<<endl;
            ll r1=b+sqrt(b*b-4.0*c);
            r1=r1/2;
            ll r2=b-sqrt(b*b-4.0*c);
            r2=r2/2;
  //          cout<<"b :"<<b<<" c: "<<c<<endl;
//            cout<<"r1 :"<<r1<<" r2 :"<<r2<<endl;
            bool enter=0;
            for(ll i=r1-100;i<=r1+100;i++)
            {
                for(ll j=r2-100;j<=r2+100;j++)
                {
                    if(i*j==tn)
                    {
                        r1=i;
                        r2=j;
                        enter=1;
                        //cout<<i<<" "<<j<<endl;
                        break;
                    }
                    //cout<<i<<" "<<j<<endl;
                }
                if(enter) break;
            }
            
            fac.pb(r1);
            fac.pb(r2);
//            cout<<"r4"<<endl;
        }
        sort(all(fac));
//        reverse(all(fac));
        for(int i=0;i<fac.size();i++)
        {
            if(fac[i]>1)
            cout<<fac[i]<<" ";
        //    ttn=ttn/fac[i];
        }
        cout<<endl;
    }
	return 0;
}

