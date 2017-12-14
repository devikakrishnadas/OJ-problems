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
    int a,b,c;
    cin>>a>>b>>c;
    int t=1000000;
    int i=0;
    
    int q;
    while(a<b && t--)
    {
        i++;
        a=a*10;
        q=a/b;
        a=a%b;
        if(q==c)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
	return 0;
}

