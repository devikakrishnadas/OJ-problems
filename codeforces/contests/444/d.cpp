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

//segTree[tp].ff -> mi ; segTree[tp].ss -> sum
void makeSegTree(vector<pair<int,int> > &bb,int l,int r,vector<pair<int,int> >&segTree,int tp)
{
    if(l==r)
    {
        segTree[tp].ff=segTree[tp].ss=bb[l].ss;
        return;
    }
    int mid=(l+r)/2;
    makeSegTree(bb,l,mid,segTree,2*tp+1);
    makeSegTree(bb,mid+1,r,segTree,2*tp+2);
    segTree[tp].ff=min(segTree[2*tp+1].ff,segTree[2*tp+2].ff);
    segTree[tp].ss=segTree[2*tp+1].ss+segTree[2*tp+2].ss;
}

void getMinSum(vector<pair<int,int> >&segTree,int l,int r,int ql,int qr,int tp,int &mi,int &sum)
{
    if(l>=ql && r <= qr)
    {
        mi=min(segTree[tp].ff,mi);
        sum+=segTree[tp].ss;
        return;
    }
    if(r<ql || l>qr) 
        return;
    int mid=(l+r)/2;
    getMinSum(segTree,l,mid,ql,qr,2*tp+1,mi,sum);
    getMinSum(segTree,mid+1,r,ql,qr,2*tp+2,mi,sum);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll n,a,b,c,d,start,len;
    cin>>n>>a>>b>>c>>d>>start>>len;
    vector<pair<int,int > >aa,bb;
    for(int i=0;i<n;i++)
    {
        int t,q;
        cin>>t>>q;
        if(q)
        {
            aa.pb(mp(t,a));
            bb.pb(mp(t,c));
        }
        else 
        {
            aa.pb(mp(t,-b));
            bb.pb(mp(t,-d));
        }
    }
    vi isNeg(n+1,0);
    //for(int i=1;i<aa.size();i++)
   // {
     //   aa[i].ss+=aa[i-1].ss;
   // }
    // find start + aa[n-1]-(aa[i+len]-aa[i])+sum(bb[i+1] to bb[i+len])
    // iff (start+aa[i])>min_element(bb[i+1] to bb[i+len])
    // for that make a segment tree for bb[]
    vector<pair<int,int> >segTree(5*n,mp(0,0));
    makeSegTree(bb,0,n-1,segTree,0);
   // int mi=INT_MAX,sum=0;
//    getMinSum(segTree,0,n-1,0,n-1,0,mi,sum);
//    cout<<mi<<" "<<sum<<endl;
    ll sumTillNow=start;
    for(int i=0;i<n;i++)
    {
        int mi=INT_MAX,sum=0;
        getMinSum(segTree,0,n-1,i,min(n-1,i+len),0,mi,sum);
        cout<<sum<<" "<<sumTillNow<<endl;
        if(mi+sumTillNow >= 0 && sum+sumTillNow >=0)
        {
            cout<<aa[i].ff<<endl;
            return 0;
        }
        /*else
        {
            if(mi+sumTillNow >= 0)
            {
                if(aa[i].ff-aa[i-1].ff>1)
                {
                    cout<<aa[i].ff-1<<endl;
                    return 0;
                }
            }
        }*/
        cout<<sumTillNow<<" += "<<aa[i].ss<<endl;
        sumTillNow+=aa[i].ss;
        
    }
    if(sumTillNow>0)
    {
        cout<<aa[n-1].ff+1<<endl;
        return 0;
    }
    cout<<-1<<endl;
   /* for(int i=0;i<n;i++)
    {
        cout<<bb[i].ss<<" ";
    }
    cout<<endl<<endl;
    for(int i=0;i<2*n;i++)
    {
        cout<<segTree[i].ff<<" "<<segTree[i].ss<<endl;
    }*/
	return 0;
}

