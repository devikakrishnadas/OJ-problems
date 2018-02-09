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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    vi fib(100000,0);
    fib[0]=0;
    fib[1]=1;
    vc str(100000,'o');
    str[1]='O';
    for(int i=2;i<20;i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
        if(fib[i] <= n)
        str[fib[i]] = 'O';
        else break;
    }
    for(int i=1;i<=n;i++)
    {   
        cout<<str[i];
    }
    cout<<endl;
	return 0;
}

