struct DSU
{
    vector<int>parent,GroupSize;
    DSU(int sz)
    {
        parent.resize(sz);
        GroupSize.resize(sz);
        for(int i = 0; i < sz; i++)
        {
            parent[i] = i;
            GroupSize[i] = 1;
        }
    }
    int FindLeader(int i)
    {
        if(parent[i] == i)
            return i;

        return parent[i] = FindLeader(parent[i]);
    }

    bool SameGroup(int x, int y)
    {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);

        return leader1 == leader2;
    }

    void MergeGroups(int x, int y)
    {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);

        if(leader1 == leader2)
            return;

        if(GroupSize[leader1] < GroupSize[leader2])
            swap(leader1,leader2);

        //leader1 is always bigger
        parent[leader2] =  leader1;
        GroupSize[leader1] += GroupSize[leader2];

    }

    int GetSize(int x)
    {
        int leader = FindLeader(x);
        return GroupSize[leader];
    }
};
