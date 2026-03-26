///Bismillahir Rahmanir Rahim
//Insertion sort algorithm implementation
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[100], n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    arr[0] = -100000;  //negative infinity
    for(int k = 2; k <= n; k++){
        int temp = arr[k];
        for(int i = k-1; i >= 0; i--){
            if(temp < arr[i]){
                arr[i+1] = arr[i];
            }
            else{
                arr[i+1] = temp;
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout<< arr[i]<< " ";
    }
    return 0;
}
