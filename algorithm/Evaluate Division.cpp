#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution {
private:
    const static int MAXN=1000;
    vector<pair<int,double> > adj[MAXN];
    int N;
    map<string,int> index;
    int getIndex(string s)
    {
        if (index.find(s)!=index.end())
        {
            return index[s];
        }else{
            index[s]=N++;
            return N-1;
        }
    }
    double search(int start,int end)
    {
        list<int> queue;
        bool used[MAXN];
        double w[MAXN];
        for (int i=0;i<N;i++) w[i]=-1;
        memset(used,0,sizeof(used));
        used[start]=true;
        w[start]=1;
        queue.push_back(start);
        while (!queue.empty() && !used[end])
        {
            int u=queue.front();
            queue.pop_front();
            for (int i=0;i<adj[u].size();i++)
            {
                int v=adj[u][i].first;
                if (used[v]) continue;
                used[v]=true;
                w[v]=w[u]*adj[u][i].second;
                queue.push_back(v);
            }
        }
        return w[end];
    }
public:
    Solution(){
        N=0;
        for (int i=0;i<MAXN;i++){
            adj[i].clear();
        }
        index.clear();
    }
    vector<double> calcEquation(vector<pair<string, string> > equations, vector<double>& values, vector<pair<string, string> > queries) {
        for (int i=0;i<values.size();i++)
        {
            string s1=equations[i].first;
            string s2=equations[i].second;
            int u=getIndex(s1);
            int v=getIndex(s2);
            double w=values[i];
            adj[u].push_back(pair<int,double>(v,w));
            adj[v].push_back(pair<int,double>(u,1/w));
        }
        vector<double> ans;
        for (int i=0;i<queries.size();i++)
        {
            string s1=queries[i].first;
            string s2=queries[i].second;
            if (index.find(s1)==index.end() || index.find(s2)==index.end())
            {
                ans.push_back(-1.0); continue;
            }
            int u=getIndex(s1);
            int v=getIndex(s2);
            ans.push_back(search(u,v));
        }
        return ans;
    }
};
