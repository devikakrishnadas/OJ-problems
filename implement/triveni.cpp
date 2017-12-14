/******
USER: TRIVENI MAHATHA (triveni)
DATE: 30/11/2013
ALGO: BIT + Maps 
******/
 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <ctime>
#include <cctype>
#include <cassert>
 
#define 	IOS						std::iostream::sync_with_stdio(false)
#define		vi						std::vector<int>
#define 	slen(s) 				strlen(s)
#define 	pb(i) 					push_back(i)
#define 	pf(i) 					push_front(i)
#define 	FOR(i,start,times) 		for(int i=start;i<start+times;i++)
#define 	scan(n)					scanf("%d",&n)
#define 	scan2(a,b)				scanf("%d%d",&a,&b)
#define		scan3(a,b,c)			scanf("%d%d%d",&a,&b,&c)
#define 	scan_array(Ar,n)		for(i,0,n) scan(Ar[i])
#define 	Scan(n)					scanf("%intd",&n)
#define 	Scan2(a,b)				scanf("%intd%intd",&a,&b)
#define		Scan3(a,b,c)			scanf("%intd%intd%intd",&a,&b,&c)
#define 	Scan_array(Ar,n)		for(i,0,n) scan(Ar[i])
#define 	sort					std::sort
#define 	max_					std::max
#define 	min_ 					std::min
/* Editable MACROS */
#define 	inf 					2147483647
#define 	INF 					(2147483647int*2147483647int)
#define 	SIZE 					131172
#define 	MAXN 					0
#define 	MINN 					0
#define 	MOD 					1000000007
/* Add other Macros here */
 
/************************/
 
using namespace std;
 
typedef long long ll;
typedef double D;
typedef float F;
 
/******************************* main code starts here ************************************************/
int BIT[222222];
 
struct Query{
  char ch;
  int x;
};
void update(int n, int idx, int val)
{
  while(idx<=n)
    {
      BIT[idx]+=val;
      idx+=(idx&-idx);
    }
}
int query(int n, int idx)
{
  int ans=0;
  while(idx>0)
    {
      ans+=BIT[idx];
      idx-=(idx&-idx);
    }
  return ans;
}
 
/*********************** Main Function is Here ***********************/
 
int main()
{
  //IOS;
  int q;
  vi A;
  char s[2];
  Query Q[222223];
 
  //cin>>q;
  scan(q);
  FOR(i,0,q)
    {
      //cin>>s>>Q[i].x;
      scanf("%s%d",s,&Q[i].x);
      Q[i].ch = s[0];
      if(s[0]=='I' || s[0] == 'D') A.pb(Q[i].x);
    }
  sort(A.begin(),A.end());
 
  std::map<int,int>map, map1;
  bool count[222223];
  
  int sz = A.size();
 
  FOR(i,0,sz+1) count[i] = BIT[i]=0;
 
  int j=1;
  FOR(i,0,sz)
    {
      if(i==0) map1[j] = A[i], map[A[i]]=j++;
      else if(A[i]!=A[i-1]) map1[j] = A[i], map[A[i]] = j++;
    }
  //A.clear();
  sz = map.size();
  
  FOR(i,0,q)
    {
 
      if(Q[i].ch == 'I'){
        int idd = map[Q[i].x] ;
  	     if(!count[idd]) 
  	         update(sz,idd,1),
  	         count[idd]=1;
        }
      else if(Q[i].ch == 'D'){
        int idd = map[Q[i].x] ;
      	if(count[idd])
      	  update(sz,idd,-1),
    	    count[idd]=0;
        }
      else if(Q[i].ch == 'K'){
	       if(Q[i].x> query(sz,sz)) puts("invalid");//cout << "invalid" << endl;
	       else{
        	  int l = 1, r = sz , m=(l+r)>>1;
        	  while(r-l>1)
        	    {
        	      m = (l+r)>>1;
        	      int qq = query(sz,m);
        	      if(qq<Q[i].x) l=m;
        	      else r=m;
        	    }
	         if(query(sz,l)==Q[i].x)printf("%d\n",map1[l]); //cout << map1[l]<<endl;
	         else if(query(sz,r)==Q[i].x) printf("%d\n",map1[r]); //cout << map1[r] << endl;
         }
      }
      else if(Q[i].ch == 'C'){
        int tt = (--map.end())->first;
        if(Q[i].x > tt) printf("%d\n",query(sz,sz)); //cout << query(sz,sz) <<endl ;
        else {
          int x =query(sz,map.lower_bound(Q[i].x)->second-1);
        	//cout << x << endl;
          printf("%d\n",x);
          }
      }
  }
  //map1.clear();
  return 0;
}
