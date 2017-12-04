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
    int val0=0,val1=1,val0p=-1,val1p=-1;
    //vector<char,int>a;
    int andd=0,orr=0,xorr=0;
    vi a(11,3);   
    while(n--)
    {
        char c; int d;
        cin>>c>>d;
        int ptr=0;
        if(c=='|')
        {
            while(ptr<10)
            {
                if(d%2)
                {
                    a[ptr]=1;
                }
                ptr++;
                d=d/2;
            }
        }
        else if(c=='&')
        {
            while(ptr<10)
            {
                if(!(d%2))
                {
                    a[ptr]=0;
                }
                ptr++;
                d=d/2;
            }
        }
        else
        {
            while(ptr<10)
            {
                if(d%2)
                {
                    if(a[ptr]==1) a[ptr]=0;
                    else if(a[ptr]==0) a[ptr]=1;
                    else if(a[ptr]==3) a[ptr]=-3;
                    else if(a[ptr]==-3) a[ptr]=3;
                }
                ptr++;
                d=d/2;
            }
        }
    }
    int pow2=1;
    for(int i=0;i<10;i++)
    {
        if(a[i]==1)
        {
            orr+=pow2;
            
        }
        else if(a[i]==-3)
        {
            xorr+=pow2;
            
        }
        if(a[i])
        {
            andd+=pow2;
        }
        pow2*=2;
    }
    int cnt=0;
    if(andd!=1023)
    {
        cnt++;
    }
    if(orr) cnt++;
    if(xorr) cnt++;
    cout<<cnt<<endl;
    if(andd!=1023)
    {
        cout<<"& "<<andd<<endl;
    }
    if(orr)
    {
        cout<<"| "<<orr<<endl;
    }
    if(xorr)
    {
        cout<<"^ "<<xorr<<endl;
    }
	return 0;
}

