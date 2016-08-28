#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN=20000;
const int INF=1000000000;
class Segment
{
public:
    int l, r, y;
    bool isBottom;
    bool operator < (const Segment &rhs) const
    {
        return y < rhs.y;
    }
};

class Solution {
private:
    int minx,maxx,miny,maxy;
    Segment s[2*MAXN];
    int x[2*MAXN];
    int c[2*MAXN];
    int compress(int *a,int len)
    {
        sort(a,a+len);
        int index=1;
        for (int i=1;i<len;i++)
        {
            if (a[i]!=a[i-1])
            {
                a[index++]=a[i];
            }
        }
        return index;
    }
public:
    bool isRectangleCover(vector<vector<int> >& rec) {
        if (rec.size()<=1) return true;
        maxx=maxy=-INF;
        minx=miny=INF;
        //area is the sum of areas of rectangles
        int area=0;
        int nx=0;
        for (int i=0;i<rec.size();i++)
        {
            area+=(rec[i][2]-rec[i][0])*(rec[i][3]-rec[i][1]);
            minx=min(minx,rec[i][0]);
            miny=min(miny,rec[i][1]);
            maxx=max(maxx,rec[i][2]);
            maxy=max(maxy,rec[i][3]);
            x[nx++]=rec[i][0]; 
            x[nx++]=rec[i][2];
            int j=2*i;
            s[j].l=rec[i][0]; s[j].r=rec[i][2]; s[j].y=rec[i][1]; s[j].isBottom=true;
            s[j+1].l=rec[i][0]; s[j+1].r=rec[i][2]; s[j+1].y=rec[i][3]; s[j+1].isBottom=false;
        }
        if (area!=(maxx-minx)*(maxy-miny)) return false;
        int N=2*rec.size();
        sort(s,s+N);
        nx=compress(x,nx);
        //ny=compress(y,ny);
        memset(c,0,sizeof(c));
        //area of union
        area=0;
        for (int i=0;i<N-1;i++)
        {
            int left=lower_bound(x,x+nx,s[i].l)-x;
            int right=lower_bound(x,x+nx,s[i].r)-x;
            if (s[i].isBottom)
            {
                c[left]++; c[right]--;
            }else{
                c[left]--; c[right]++;
            }
            if (s[i+1].y!=s[i].y)
            {
                int cover=0;
                int h=s[i+1].y-s[i].y;
                for (int j=0;j<nx-1;j++)
                {
                    cover+=c[j];
                    if (cover>0) area+=h*(x[j+1]-x[j]);
                }
            }
        }
        if (area!=(maxx-minx)*(maxy-miny)) return false;
        return true;
    }
};

int main()
{
    vector<vector<int> > v;
    int r1[4]={0,0,1,1};
    int r2[4]={1,0,2,1};
    int r3[4]={2,0,3,1};
    int r4[4]={3,0,4,1};
    vector<int> v1(r1,r1+4);
    vector<int> v2(r2,r2+4);
    vector<int> v3(r3,r3+4);
    vector<int> v4(r4,r4+4);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    Solution s;
    if (s.isRectangleCover(v)) printf("true\n");
    else printf("false\n");
    int n;
    scanf("%d",&n);
    return 0;
}
