///Bismillahir Rahmanir Rahim
//merge sort implementation
#include<bits/stdc++.h>
using namespace std;

void Merge(int c[], int l, int m, int r)
{
    vector<int> a, b;
    for(int k = l; k <= m; k++)
        a.push_back(c[k]);
    for(int k = m+1; k <= r; k++)
        b.push_back(c[k]);

    int i = 0, j = 0;
    for(int k = l; k <= r; k++)
    {
        if(i < a.size() && (j >= b.size() || a[i] <= b[j]))
            c[k] = a[i++];
        else
            c[k] = b[j++];
    }
}

void MergeSort(int c[], int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;
        MergeSort(c, l, m);
        MergeSort(c, m + 1, r);
        Merge(c, l, m, r);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int c[n];
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++)
        cin >> c[i];

    MergeSort(c, 0, n - 1);

    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++)
        cout << c[i] << " ";
    cout << endl;

    return 0;
}


