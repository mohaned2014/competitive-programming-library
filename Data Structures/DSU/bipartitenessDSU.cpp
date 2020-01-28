struct DSU
{
    vector<ii>parent;
    vector<int>GroupSize,bipartite;
    DSU(int sz)
    {
        parent.resize(sz);
        GroupSize.resize(sz);
        bipartite.resize(sz);
        for(int i = 0; i < sz; i++)
        {
            parent[i].first = i;
            parent[i].second=0;
            GroupSize[i] = 1;
            bipartite[i]=1;
        }
    }
    ii FindLeader(int i)
    {
        if(parent[i].first != i)
        {
            int parity = parent[i].second;
            parent[i] = FindLeader(parent[i].first);
            parent[i].second ^= parity;
        }
        return parent[i];
    }

    bool SameGroup(int x, int y)
    {
        ii leader1 = FindLeader(x);
        ii leader2 = FindLeader(y);

        return leader1.first == leader2.first;
    }

    void MergeGroups(int n1, int n2)
    {
        ii pa = FindLeader(n1);
        int a = pa.first;
        int x = pa.second;

        ii pb = FindLeader(n2);
        int b =pb.first;
        int y = pb.second;

        if(a==b)
        {
            if(x==y)
            {
                bipartite[a]=false;
            }
                return ;
        }
        else
        {
            if(GroupSize[a] < GroupSize[b])
                swap(a,b);
            //a is always bigger
            parent[b] =  {a,x^y^1};
            bipartite[a] &= bipartite[b];
            GroupSize[a] += GroupSize[b];
        }
    }

    int GetSize(int x)
    {
        ii leader = FindLeader(x);
        return GroupSize[leader.first];
    }

    bool IsBipartite(int v)
    {
        return bipartite[FindLeader(v).first];
    }
};