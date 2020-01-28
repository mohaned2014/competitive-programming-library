//timus 1470 3d fenwick tree

//from (x0, y0, z0) to (x, y, z)
// value1 = sum(x,y,z)- sum(x0-1,y,z)  - sum(x,y0-1,z) + sum(x0-1,y0-1,z)
// value2 = sum(x,y,z0-1) - sum(x0-1,y,z0-1) - sum(x,y0-1,z0-1)  + sum(x0-1,y0-1,z0-1)
// final answer = value1 - value2
// Time complexity of code is 8 (logn)^3

// 1> assume it as a cube.
// 2> value 1 gives answer for upper square layer of cube, but it include sum upto 0 in z-axis. 
// You only want upto z0, so you have subtract that extra part(from z0 to 0, and that is value2).
#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>

using namespace std;

const int N=130;
ll tree[N][N][N];
void add(int x,int y,int z,ll value)
{
    while(x<N)
    {
        int y1 = y;
        while(y1<N)
        {
            int z1 = z;
            while(z1<N)
            {
                tree[x][y1][z1]+=value;
                z1+= (z1&-z1);
            }
            y1+= (y1&-y1);

        }
        x+= (x&-x);
    }
}
ll sum(int x,int y,int z)
{
    ll ret =0;
    while(x)
    {
        int y1 = y;
        while(y1)
        {
            int z1 = z;
            while(z1)
            {
                ret+=tree[x][y1][z1];
                z1-= (z1&-z1);
            }
            y1-= (y1&-y1);

        }
        x-= (x&-x);
    }
    return ret;
}


ll query(int x1,int y1,int z1,int x2,int y2,int z2)
{
    // from z = 0 to z2  (z1<=z2)
    ll value1 = sum(x2,y2,z2)-sum(x2,y1-1,z2)-sum(x1-1,y2,z2) + sum(x1-1,y1-1,z2);
    // from z = 0 to z1-1
    ll value2 = sum(x2,y2,z1-1)-sum(x2,y1-1,z1-1)-sum(x1-1,y2,z1-1) + sum(x1-1,y1-1,z1-1);
    return value1 - value2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int m;
    while(cin>>m&&m!=3)
    {
        if(m==1)
        {
            int x,y,z,v;
            cin>>x>>y>>z>>v;
            add(x+1,y+1,z+1,v);
        }
        else
        {
            int x1,y1,z1,x2,y2,z2;
            cin>>x1>>y1>>z1>>x2>>y2>>z2;
            cout<<query(x1+1,y1+1,z1+1,x2+1,y2+1,z2+1)<<endl;
        }
    }
}
