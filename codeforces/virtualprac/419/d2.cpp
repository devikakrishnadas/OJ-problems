#include<bits/stdc++.h>
#define ll long long
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

long long int E_GCD(long long int a,long long int b,long long  int&x,long long int &y)
{
    if(a==0)
    {
        x=0;
        y=1;
        
        return b;
        
    }
    long long int X1,Y1;
    long long int gcd = E_GCD(b%a,a,X1,Y1);
    x=Y1-(b/a)*X1;
    y=X1;
    
    
    return gcd;
    
}
ll inv(ll a)
{
	ll x,y;
	E_GCD(a,M,x,y);
	/*while(x<0)
	{
		x=(x+M)%M;
		//cout<<x<<endl;
	}*/
	return x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	vll v(n);
	queue<ll>q;
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		q.push(v[i]);
	}
	if(n%4!=1)
	q.push(LLONG_MIN);
        ll i=0;
        ll s,a;
	//cout<<n<<endl;
        while(n%4!=1)
        {
		//cout<<"ENTER"<<endl;
                i++;
                s=q.front();
                //cout<<s<<endl;
                q.pop();
                a=q.front();
                if(a!=LLONG_MIN)
                {
                        if(i%2)
                                q.push(s+a);
                        else    
                                q.push(s-a);
                }               
                else
                {
                        i--;
                        q.pop();
			n--;
                        if(q.size()<=0)
                                break;
			
                        q.push(LLONG_MIN);
                }
        }
	if(q.size()==0)
		cout<<s<<endl;
	else
	{
		if(q.front()==LLONG_MIN)
			q.pop();
		//cout<<q.size()<<endl;
		//return 0;
		v.clear();
		//cout<<"r1"<<endl;
		while(q.front()!=LLONG_MIN && !q.empty())
		{
			v.pb(q.front());
			q.pop();
		}
		
		ll tn=n/2 ;
		ll ans=v[0];
		ll factorial[200023]={0};
		factorial[0]=factorial[1]=1;
		
		for(int i=2;i<=tn;i++)
		{
			factorial[i]=(i*factorial[i-1])%M;
		}
		//cout<<factorial[tn]<<endl;
		ll inv_factorial[200023]={0};
		inv_factorial[1]=1;	
		inv_factorial[0]=1;
		for(int i=2;i<=tn;i++)
		{
			inv_factorial[i]=(inv_factorial[i-1]*inv(i))%M;
		}	
	//	cout<<v[4]<<endl;
		for(int i=1,j=2;i<=tn;i++,j+=2)
		{
			ll f=((factorial[tn]*inv_factorial[i])%M)*inv_factorial[tn-i];
			f=f%M;
			
			ans=ans+(v[j]*f)%M;
			ans=(ans+M)%M;
		}
		while(ans<0)
			ans=(ans+M)%M;
		cout<<(ans+M)%M<<endl;
	}
	return 0;
}

