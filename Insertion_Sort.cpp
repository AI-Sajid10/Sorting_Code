///Bismillahir Rahmanir Rahim
//Insertion sort algorithm implementation
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
void insertionsort(vector<int> &arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    int size = 1000;
    vector<int> data = generate(size);

    auto start_time = chrono::high_resolution_clock::now();

    insertionsort(data, size);

    auto end_time = chrono::high_resolution_clock::now();

    chrono::duration<double, std::milli> execution_time = end_time - start_time;

    print(data);
    cout << "Execution Time: " << execution_time.count() << " ms\n";
}