/**
  Algorithm - Indexed Tree
*/

class NumArray {
private:
    vector<int> s,v;
    int N;
    int bit(int x)
    {
        return x&(-x);
    }
    int sum(int i)
    {
        int ans=0;
        i++;
        for (int k=i;k>0;k-=bit(k))
        {
            ans+=s[k];
        }
        return ans;
    }
public:
    NumArray(vector<int> &nums) {
        s.push_back(0);
        N=nums.size()+1;
        for (int i=0;i<nums.size();i++)
        {
            s.push_back(0);
            v.push_back(0);
        }
        for (int i=0;i<nums.size();i++)
        {
            update(i,nums[i]);
        }
    }

    void update(int i, int val) {
        int delta=val-v[i];
        v[i]=val;
        for (int k=i+1;k<N;k+=bit(k))
        {
            s[k]+=delta;
        }
    }

    int sumRange(int i, int j) {
        return sum(j)-sum(i-1);
    }
};