/**
  * Complexity - O(n^3)
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int H=matrix.size();
        if (H==0) return 0;
        int W=matrix[0].size();
        vector<int> h[2];
        int ans=0;
        for (int i=0;i<W;i++)
        {
            int v=(int)(matrix[0][i]-'0');
            if (v==1) ans=1;
            h[0].push_back(v);
            h[1].push_back(0);
        }
        for (int i=1;i<H;i++)
        {
            for (int j=0;j<W;j++)
            {
                int v=(int)(matrix[i][j]-'0');
                if (v==1)
                {
                    h[i%2][j]=h[(i-1)%2][j]+1;
                    int r=i%2;
                    int len=h[r][j];
                    for (int k=j;k>=0;k--)
                    {
                        if (h[r][k]==0) break;
                        len=min(len,h[r][k]);
                        int side=min(len,j-k+1);
                        ans=max(ans,side*side);
                    }
                }else{
                    h[i%2][j]=0;
                }
            }
        }
        return ans;
    }
};