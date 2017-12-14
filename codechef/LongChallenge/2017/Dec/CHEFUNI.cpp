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
        int a,b,c;
        vi v(3);
        cin>>v[0]>>v[1]>>v[2]>>a>>b>>c;
        sort(all(v));
        int x=v[0],y=v[1],z=v[2];
        int t1=(x+y+z)*a;
        int t2 = min(x+y,z)*b + abs(x + y - z)*a;
        int t3 = x*b + (y + z - x)*a;
        int t4 = y*b + (x + z - y)*a;
        int t5 = x*c + b*(y-x) + a*(z-y);
        int t6 = x*c + (y + z - 2*x)*a;
        int ans = min(t1,min(t2,min(t3,min(t4,min(t5,t6)))));
        if(z-y <= x)
        {
            int t8 = b*(z-y) + (y + ((x-(z-y))/2))*b + ((x-(z-y))%2)*a;
            if((x-(z-y))%2)
            {
                t8 = min(b*(z-y) + (y - 1 + ((x-(z-y))/2))*b + c,t8);
            }
            ans=min(ans,t8);
        }
        
        if(x + y > z)
        {
            int tt = x + y - z;
            int t7 = z*b + (tt/2)*b + (tt - 2*(tt/2))*a;
            t7 = min(t7,z*b + tt*a);
            t7 = min(t7, c*tt + 2*a*(z-tt));
            t7 = min(t7, 3*a*tt + b*(z-tt));
            ans = min(min(ans,t7),c*tt + b*(z-tt));
        }
        cout<<ans<<endl;
    }
	return 0;
}

