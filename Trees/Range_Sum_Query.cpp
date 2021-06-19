#include <bits/stdc++.h>
using namespace std;

void build(int *tree, int *a, int index, int s, int e)
{
    if (s == e)
    {
        tree[index] = a[s];
    }
    else
    {
        int mid = (s + e) / 2;
        build(tree, a, 2 * index, s, mid);
        build(tree, a, 2 * index + 1, mid + 1, e);
        tree[index] = tree[2 * index] + tree[2 * index + 1];
    }
}

int sum(int *tree, int index, int s, int e, int qs, int qe)
{
    if (qs <= s && e <= qe)
    {
        return tree[index];
    }
    if (qs > e || qe < s)
        return 0;
    int mid = (s + e) / 2;
    return sum(tree, 2 * index, s, mid, qs, qe) + sum(tree, 2 * index + 1, mid + 1, e, qs, qe);
}

void update(int *tree, int index, int s, int e, int pos, int val)
{
    if (pos < s || pos > e)
        return;
    if (s == e)
    {
        tree[index] = val;
        return;
    }
    int mid = (s + e) / 2;
    update(tree, 2 * index, s, mid, pos, val);
    update(tree, 2 * index + 1, mid + 1, e, pos, val);
    tree[index] = tree[2 * index] + tree[2 * index + 1];
    return;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    int *tree = new int[4 * n + 1];
    int index = 1;

    int s = 0, e = n - 1;
    build(tree, arr, index, s, e);

    cout << sum(tree, index, s, e, 1, 3) << endl;
    update(tree, index, s, e, 1, 43);
    cout << sum(tree, index, s, e, 1, 3) << endl;
}
