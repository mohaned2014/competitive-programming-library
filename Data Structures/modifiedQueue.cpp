struct modifedQueue
{
    stack<pair<ll,ll>> s1,s2;

    void push(ll x)
    {
        ll newMin = s1.empty() ? x:max(x,s1.top().second);
        s1.push({x,newMin});
    }
    ll findMax()
    {
        ll mx;
        if (s1.empty() || s2.empty())
            mx = s1.empty() ? s2.top().second : s1.top().second;
        else
            mx = max(s1.top().second, s2.top().second);
        return mx;
    }
    void pop()
    {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                pair<ll,ll> p=s1.top();
                s1.pop();
                ll newMin = s2.empty() ? p.first:max(s2.top().second,p.first);
                s2.push({p.first,newMin});
            }
        }
        s2.pop();
    }

    bool isEmpty()
    {
        return (s1.empty()&&s2.empty());
    }
    int size()
    {
        return (s1.size()+s2.size());
    }
};
