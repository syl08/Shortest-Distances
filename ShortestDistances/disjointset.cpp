
#include "disjointset.h"

using namespace std;

DisjointSet::DisjointSet(int N)
{
    this->N = N;
    id = new int[N];
    for(int i = 0; i < N; i++)
    {
        id[i] = i;
    }
}

DisjointSet::~DisjointSet()
{
    delete[] id;
}

int DisjointSet::find(int i)
{
    while (i != id[i])
    {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

void DisjointSet::join(int p, int q)
{
    int i = find(p);
    int j = find(q);
    if (i == j) return;
    if (i > j)
    {
        id[i] = j;
        j += i;
    }
    else
    {
        id[j] = i;
        i += j;
    }

}

bool DisjointSet::sameComponent(int p, int q)
{
    return find(p) == find(q);
}
