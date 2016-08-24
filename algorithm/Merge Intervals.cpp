class Solution {
private:
    static const int MAXN=10000;
    int x[MAXN];
    int c1[MAXN],c2[MAXN];
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for (int i=0;i<intervals.size();i++)
        {
            x[2*i]=intervals[i].start;
            x[2*i+1]=intervals[i].end;
        }
        int n=2*intervals.size();
        sort(x,x+n);
        int m=unique(x,x+n)-x;
        vector<Interval> v;
        for (int i=0;i<intervals.size();i++)
        {
            int left=lower_bound(x,x+m,intervals[i].start)-x;
            int right=lower_bound(x,x+m,intervals[i].end)-x;
            c1[left]++;
            c2[right]++;
        }
        int start=-1;
        int sum=0;
        for (int i=0;i<m;i++)
        {
            sum+=c1[i];
            if (sum>0)
            {
                if (start<0) start=i;
            }
            sum-=c2[i];
            if (sum==0)
            {
                if (start>=0)
                {
                    v.push_back(Interval(x[start],x[i]));
                    start=-1;
                }
            }
        }
        if (start>=0)
        {
            v.push_back(Interval(x[start],x[m-1]));
        }
        return v;
    }
};