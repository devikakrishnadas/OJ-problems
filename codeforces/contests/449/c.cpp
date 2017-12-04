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
vector<unsigned long long int> a(100023,0);
string zero="What are you doing at the end of the world? Are you busy? Will you save us?";
string first ="What are you doing while sending \"";
string second ="\"? Are you busy? Will you send \"";
string third ="\"?";


char func(ll n,ll k)
{
    cerr<<n<<" "<<k<<endl;
     if(n==0)
    {
        if(k>a[n])
            return '.';
        cerr<<"r2"<<endl;
        return zero[k-1];
    }

    if(k<=34)
    {
        cerr<<"r3"<<endl;
            return first[k-1];
    }
    if(k>a[n])
    {
        cerr<<"r1"<<endl;
        return '.';
    }
       
    else if(k>34+a[n-1] && k<=34+a[n-1]+32)
    {
        cerr<<"r4"<<endl;
            return second[k-34-a[n-1]-1];
    }
    else if(k>34+a[n-1]+32+a[n-1])
    {
        cerr<<"r5"<<endl;
        if(k-34-a[n-1]-32-a[n-1] > 2)
        {
            return '.';
        }
        else
        {
                return third[k-34-a[n-1]-32-a[n-1]-1];
        }
    }
    else if(k>34 && k<=34 + a[n-1])
    {
        cerr<<"r6"<<endl;
        return func(n-1,k-34);
    }
    else
    {
        cerr<<"r7"<<endl;
        return func(n-1,k-34-a[n-1]-32);
    }
}

int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//    cout.tie(0);
    ll n,k;
    a[0]=zero.length();
    //string first ="What are you doing while sending \"";
    //string second ="\"? Are you busy? Will you send \"";
    //string third ="\"?";
    ll s;
    for(int i=1;i<=55;i++)
    {
        a[i]=34 + a[i-1] + 32 + a[i-1] + 2;
    }
    int q;
    cin>>q;
    vc ans;
    s=55;
//    cout<<a[s]<<endl;
    while(q--)
    {
        cin>>n>>k;
        bool enter=0;
        if(n>55)
        {
    //        k=k-(n-s)*34;
            for(int i=0;i<n-s;i++)
            {
                if(k<34)
                {
                    ans.pb(first[k-1]);
                    enter=1;
                    break;
                }
                if(k>34)
                k=k-34;
            }
            if(enter)
            {
                continue;
            }
            n=s;
        }
        char c=func(n,k);
        cerr<<c<<endl;
        ans.pb(c);
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i];
    }
    cout<<endl;
	return 0;
}
