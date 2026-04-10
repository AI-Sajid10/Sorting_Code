///Bismillahir Rahmanir Rahim
//merge sort implementation
#include <bits/stdc++.h>
using namespace std;
vector<int> generate(int size, int min_val = 0, int max_val = 100000)
{
    vector<int> dataset;
    dataset.reserve(size);
    for (int i = 0; i < size; ++i)
    {
        int range = max_val - min_val + 1;
        int num = min_val + (rand() % range);
        dataset.push_back(num);
    }
    return dataset;
}

void print(const vector<int> &data)
{
    cout << "Generated " << data.size() << " numbers:\n";
    for (size_t i = 0; i < data.size(); ++i)
    {
        cout << data[i];
        if (i != data.size() - 1)
            cout << " ";
    }
    cout << "\n";
    cout << "Student ID: C243014 \n"
         << "Student Name: Nafizur Rahman Seam\n";
}

void merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp;
    int i = start;
    int j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[idx + start] = temp[idx];
    }
}

void mergesort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    int size = 1000;
    vector<int> data = generate(size);

    auto start_time = chrono::high_resolution_clock::now();

    mergesort(data, 0, size - 1);

    auto end_time = chrono::high_resolution_clock::now();

    chrono::duration<double, std::milli> execution_time = end_time - start_time;

    print(data);
    cout << "Execution Time: " << execution_time.count() << " ms\n";
}