#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin,V.end

using namespace std;

int main()
{
	int n;
	cin>>n;
	string a,b,c,d;
	vector<pair<string,string > >A;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		a= a.substr(0,3);
		b= a.substr(0,2) + b[0];
		A.pb(mp(a,b));
	}
	bool no=0;
	map<pair<string,string>,int>G;//To keep track of whether this word is done or no !
	map<string,int>B; //To keep count of how many unique type 2 names exist for a particular type 1 name
	map<string,vector<pair<string,int> > >C;// To keep track of type 2 names for each type 1 name in order
	map<string, set<string> >D;//To note if there are any repititions in type 2 names for a particular type 1 name;
	map<string,int>E;//To keep track of which category the string falls into- 1:type1, 2:type2, 3:type1 of they type2 chosen;
	for(int i=0;i<n;i++)
	{
		a=A[i].first;
		b=A[i].second;
		B[a]++;
		C[a].pb(mp(b,i));
		D[a].insert(b);
	}
	for(int i=0;i<n;i++)
	{
		a=A[i].first;
		b=A[i].second;
		if(B[a]>1 && B[a]!=D[a].size())
		{
			no=1;
			break;
		}
	}
	if(no)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	
	vector<pair<int,string> >ans;
	map<string,set<string> >::iterator i1;//To access elements stored in D;
	for(i1=D.begin();i1!=D.end();++i1)
	{
		a=i1->first;
		sort((C[i1->first]).begin(),(C[i1->first]).end());
		
		int ptr=0;
		set<string>::iterator i12;// To access the strings stored in i1->second;
		
		if((i1->second).size()>1)
		{
			E[a]=3;
			for(i12=(i1->second).begin();i12!=(i1->second).end();++i12,++ptr)
			{
				b=(*i12);
				if(G.find(mp(a,b))!=G.end())
					continue;
				//b=(*i12);
				E[b]=2;
				G[mp(a,b)]=1;
//				if(b=="ABO") cout<<"YYYY"<<endl;
				ans.pb(mp(C[a][ptr].second,b));
				
			}
		}
	}
	bool enter=1;
	int count=0;
	while(enter)
	{
		enter=0;
		for(i1=D.begin();i1!=D.end();++i1)
		{
			a=i1->first;
			b=*((i1->second).begin());
//			cout<<a<<" "<<b<<endl;
//			cout<<b<<" "<<E[b]<<endl;
			if((i1->second).size()==1)
			{
//				cout<<G[mp("ABD","ABO")]<<endl;
//				cout<<"***"<<(i1->second).size()<<endl;
				if(G.find(mp(a,b))!=G.end())
					continue;
				map<string,int>::iterator i2,i3;
				i2=E.find(a);
				i3=E.find(b);
				if(i2==E.end() && ((i3->second)==2 or (i3->second)==1))
				{
					
					enter=1;
					E[a]=1;
					ans.pb(mp(C[a][0].second,a));
					//G[mp(a,b)]=1;
				}
				else if((i3==E.end() or i3->second==3) and i2!=E.end())
				{
					enter=1;
//					if(b=="ABO")
//					{
//						cout<<a<<" "<<b<<endl;
//					}
					E[b]=2;
					G[mp(a,b)]=1;
					ans.pb(mp(C[a][0].second,b));
				}
				else if(i2!=E.end() and (i3->second==1 or i3->second==2))
				{
			//		cout<<a<<"-"<<E[a]<<endl<<b<<"-"<<E[b]<<endl;
			//		cout<<G[mp(a,b)]<<endl;
					no=1;
					break;
				}
			}
			
		}
		if(no)
			break;
	}
	if(no)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	for(i1=D.begin();i1!=D.end();++i1)
	{
		if((i1->second).size()==1)
		{
		//	cout<<"r11"<<endl;
			map<string,int>::iterator i2,i3;
			a=i1->first;
			b=*((i1->second).begin());
			if(G.find(mp(a,b))!=G.end())
				continue;
			i2=E.find(a);
			i3=E.find(b);
		//	if(i2==E.end()) cout<<"2 end ";
		//	else cout<<i2->second<<" ";
		//	if(i3==E.end()) cout<<"3 End ";
		//	else cout<<i3->second<<" ";
		//	cout<<endl;
			if(i2==E.end())
			{
				E[a]=1;
				ans.pb(mp(C[a][0].second,a));
		//		cout<<"r1"<<endl;
			}
		}
	}
	sort(ans.begin(),ans.end());
	cout<<"YES"<<endl;
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i].second<<endl;
	}
	return 0;
}

