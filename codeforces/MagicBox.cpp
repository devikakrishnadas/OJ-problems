#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

struct point
{
	int x,y,z;	
};


int dotp(point a,point b)
{
	return (a.x*b.x + a.y*b.y + a.z*b.z);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	point P,P1;
	cin>>P1.x>>P1.y>>P1.z>>P.x>>P.y>>P.z;
	P.x=2*P.x;
	P.y=2*P.y;
	P.z=2*P.z;
	P1.x=2*P1.x;
	P1.y=2*P1.y;
	P1.z=2*P1.z;
	vi a(6);
	for(int i=0;i<6;i++)
	{
		cin>>a[i];
	}
	point v[6],p[6];
	v[1].x=0;	p[0].x=P1.x-(P.x/2);
	v[1].y=1;	p[0].y=P1.y;
	v[1].z=0;	p[0].z=P1.z-(P.z/2);
	
	v[0].x=0;	p[1].x=P1.x-(P.x/2);
        v[0].y=-1;	p[1].y=P1.y-P.y;
        v[0].z=0;	p[1].z=P1.z-(P.z/2);
	
	v[3].x=0;	p[2].x=P1.x-(P.x/2);
        v[3].y=0;	p[2].y=P1.y-(P.y/2);
        v[3].z=1;	p[2].z=P1.z;

	v[2].x=0;	p[3].x=P1.x-(P.x/2);
        v[2].y=0;	p[3].y=P1.y-(P.y/2);
        v[2].z=-1;	p[3].z=P1.z-P.z;

	v[5].x=1;	p[4].x=P1.x;
        v[5].y=0;	p[4].y=P1.y-(P.y/2);
        v[5].z=0;	p[4].z=P1.z-(P.z/2);
	
	v[4].x=-1;	p[5].x=P1.x-P.x;
        v[4].y=0;	p[5].y=P1.y-(P.y/2);
        v[4].z=0;	p[5].z=P1.z-(P.z/2);


	int ans=0;


	for(int i=0;i<6;i++)
	{
		int aa=dotp(v[i],p[i]);
		if(aa>0)
		{
			//cout<<a[i]<<endl;
			//cout<<p[i].x<<" "<<p[i].y<<" "<<p[i].z<<endl;
			ans=ans+a[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}

