///Bismillahir Rahmanir Rahim
//Quick sort implementation
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
    cout << "Student ID: C243042 \n"
         << "Student Name: Ahmed Ibrahim Sajid\n";
}
int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[end]);
    return i;
}

void quicksort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int p = partition(arr, start, end);
        quicksort(arr, start, p - 1);
        quicksort(arr, p + 1, end);
    }
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    int size = 1000;
    vector<int> data = generate(size);

    auto start_time = chrono::high_resolution_clock::now();

    quicksort(data, 0, size - 1);

    auto end_time = chrono::high_resolution_clock::now();

    chrono::duration<double, std::milli> execution_time = end_time - start_time;

    print(data);
    cout << "Execution Time: " << execution_time.count() << " ms\n";
}