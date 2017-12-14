import math
ans = dict()


def ModE(a,b) :
    res = 1
    m = 1000000007
    while b>0 :
        #print " %d %d %d " %(res,a,b)
        if b & 1 :
            res = (res * a)%m;
        b = b >> 1
        a = (a*a)%m;
        #print "%d %d %d" % (a , a%m, m) ;
        res = res%m
    return res


def func(a) :
    
    m = 1000000007
    if a in ans :
        return ans[a]
    ans[a] = ModE(2,a-1)-1;
#    print "2 ^ %d = %d" %(a-1,ModE(2,a-1))
#    if a==4 :
#        print "* %d " % ans[a]
    #print "sqrt val %d %d" % (int(math.sqrt(a)), ans[a])
    for i in range(2,int(math.sqrt(a))+1) :
        if a%i==0 :
            ans[a] = ans[a] - func(a/i);                               
            if i != (a/i) : 
                ans[a] = ans[a] - func(i)

#    print "ans[ %d ] is %d" %(a,ans[a])
    ans[a] = ans[a]%m
    return ans[a]

n,m = raw_input().split()
n = int(n)
m = int(m)

if m==n :
    print 1
elif m%n != 0 :
    print 0
else :
    a = m/n
    print func(a)
