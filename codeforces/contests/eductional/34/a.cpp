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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n%7==0||n%3==0)
        {
            cout<<"YES"<<endl;
            continue;
        }
        bool no=1;
        while(n>0)
        {
            n=n-3;
            if(n%7==0)
            {
                no=0;
                cout<<"YES"<<endl;
                break;
            }
        }
        if(no)
        {
            cout<<"NO"<<endl;
        }
    }
	return 0;
}

