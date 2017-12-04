
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

long long int modE(long long int A,long long int M,long long int P)
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
vll a(1000001,-1);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll p;
    cin>>p;

   for(int i=0;i<p;i++)
    {
        ll temp=modE(i,p,2);
//        cout<<i<<endl;
        temp=temp%p;
        a[temp]=i;
    }
    for(int i=0;i<p;i++)
        cout<<a[i]<<" ";
    cout<<endl;
	return 0;
}

