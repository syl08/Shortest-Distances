#ifndef DISJOINTSET_H_INCLUDED
#define DISJOINTSET_H_INCLUDED

class DisjointSet
{
public:

    DisjointSet(int);

    ~DisjointSet();

    int find(int);

    void join(int, int);

    bool sameComponent(int, int);

private:

    int* id;
    int N;

};

#endif // DISJOINTSET_H_INCLUDED
