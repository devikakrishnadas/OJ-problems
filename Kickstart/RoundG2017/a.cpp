#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first

#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

long long int ModE(long long int A,long long int M,long long int P)
{
    long long int res = 1;     
  
    while (P > 0)
    {
       
        if (P & 1)
            res = (res*A)%M;
  
        
        P = P>>1; 
        A = (A*A)%M ;  
    }
    return res;
    
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ifstream fin;
    ofstream fout;
    fin.open("A-large-practice.txt");
    fout.open("op.txt");
    
    int t;
    fin>>t;
    int cntr=0; 
    ll a,n,p;
    while(t--)
    {
        cntr++;
        fout<<"Case #"<<cntr<<": ";
        fin>>a>>n>>p;
        ll ans=a%p;
        for(ll i=2;i<=n;i++)
        {
            ans=ModE(ans,p,i);
        }
        ans=ans%p;
        fout<<ans<<endl;
        
    }
	return 0;
}

