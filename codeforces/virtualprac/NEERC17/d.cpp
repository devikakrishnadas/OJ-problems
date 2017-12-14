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
    if(c>=a && c>=b && c<=a*b)
    {
        for(int i=0;i<a;i++)
        {
            cout<<0<<" "<<i<<" "<<0<<endl;
        }
        c-=a;
        b--;
        int tb=b;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<tb;j++)
            {
                cout<<0<<" "<<i<<" "<<j<<endl;
                c--;
                b--;
                if(c==0)
                break;
            }
            if(c==0)
                break;
        }
        if(b)
        {
            for(int i=1;i<b;i++)
            {
                cout<<i<<" "<<0<<" "<<0<<endl;
            }
        }
    }
    else if(b>=a && b>=c && b<=a*c)
    {
        for(int i=0;i<a;i++)
        {
            cout<<i<<" "<<0<<" "<<0<<endl;
        }
        b-=a;
        c--;
        int tc=c;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<tc;j++)
            {
                cout<<i<<" "<<0<<" "<<j<<endl;
                b--;
                c--;
                if(b==0)
                    break;
            }
            if(b==0) break;
        }
        if(c)
        {
            for(int i=1;i<c;i++)
            {
                cout<<0<<" "<<i<<" "<<0<<endl;
            }
        }
    }
    else if(a>=b && a>=c && a<=b*c)
    {
        for(int i=0;i<b;i++)
        {
            cout<<i<<" "<<0<<" "<<0<<endl;
        }
        a-=b;
        c--;
    }
	return 0;
}

