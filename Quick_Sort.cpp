///Bismillahir Rahmanir Rahim
//Quick sort implementation
#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int r)
{
    int i = l, j = r - 1, pivot = a[r];
    while(i < j){
        if(a[i] > pivot){
            swap(a[i], a[j]);
            j--;
        }
        else{
            i++;
        }
    }
    if(a[i] > pivot){
        swap(a[i], a[r]);
        return i;
    }
    else{
        swap(a[i+1], a[r]);
        return i+1;
    }
}

void QuickSort(int a[], int l, int r)
{
    if(l >= r) return;
    int m = partition(a, l, r);
    QuickSort(a, l, m-1);
    QuickSort(a, m+1, r);
}

int main()
{
    int n, arr[100];
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    QuickSort(arr, 1, n);

    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
