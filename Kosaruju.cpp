// KosaRaju Algorithm - To find the number of Strongly connected components

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define V 8 // Number f vertices in this example

unordered_map<int, vector<int>> adj, rev;

void DFS1(int i, vector<bool> &visited, stack<int> &mystack)
{
    visited[i] = true;
    for(int j : adj[i])
    {
        if (!visited[j])
        {
            DFS1(j, visited, mystack);
        }
    }
    mystack.push(i);
}

void reverse()
{
    for (int i = 0; i < V; i++)
    {
        for(int j : adj[i])
        {
            rev[j].pb(i);
        }
    }
}

void DFS2(int i, vector<bool> &visited)
{
    cout <<i<<" ";
    visited[i] = true;
    for(int j : rev[i])
    {
        if (!visited[j])
        {
            DFS2(j, visited);
        }
    }
}

void findSCCs()
{
    stack<int> mystack;
    vector<bool>visited(V,false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            DFS1(i, visited, mystack);
        }
    }

    reverse();
    // :: Quick Fix
    // Please check it afterward
    // memset(visited, false, V); --> Only works for the -1, 0

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    
    cout <<"Strongly connected components are: \n";
    while (!mystack.empty())
    {
        int curr = mystack.top();
        mystack.pop();
        if (!visited[curr])
        {
            DFS2(curr, visited);
            cout <<"\n";
        }
    }
}

int main()
{
    adj[0].pb(1);
    adj[2].pb(0);
    adj[1].pb(2);
    adj[2].pb(3);
    adj[3].pb(4);
    adj[4].pb(5);
    adj[4].pb(7);
    adj[5].pb(6);
    adj[6].pb(7);
    adj[6].pb(4);

    findSCCs();
    return 0;
}
