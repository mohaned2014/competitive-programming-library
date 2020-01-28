struct BIT
{
    vector<ll> tree;

    BIT(int n)
    {
        tree.resize(n+1);
    }

    BIT(vector<ll>& arr)
    {
        tree.resize(arr.size()+1);
        for(int i=1; i<(int)tree.size(); i++)
        {
            tree[i]+=arr[i-1];
            int parent = i+LSB(i);
            if(parent<(int)tree.size())
                tree[parent]+=tree[i];
        }
    }

    void add(int i,ll v)
    {
        while(i<(int)tree.size())
        {
            tree[i] += v;
            i += LSB(i);
        }
    }

    ll PrefixSum(int i)
    {
        ll sum =0;
        while(i>0)
        {
            sum+=tree[i];
            i-=LSB(i);
        }
        return sum;
    }

    void UpdateRange(int left,int right,ll v)
    {
        add(left,+v);
        add(right+1,-v);
    }

    ll SumRange(int left,int right)
    {
        return PrefixSum(right)-PrefixSum(left-1);
    }

    int LSB(int i)
    {
        return i&-i;
    }

    void SetPoint(int i,ll v)
    {
        add(i, v- SumRange(i,i));
    }
};