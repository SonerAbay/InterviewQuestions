/*
Tamsayılardan oluşmuş bir liste verilsin. Yeni bir liste oluştuturn öyle ki i indexli elemanın yeni indexi i elemanın indexi dışındaki elemanların index çarpımı olsun.
Örnek: Input: [1, 2, 3, 4, 5] OutPut: [120, 60, 40, 30, 24]
*/

#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <unordered_set>
#include <time.h>
#include <chrono>

using namespace std::chrono;
using namespace std;


int *carpimListLoop(int arr[]){
    int k[10000];
    int carpim = 1;
    for(int i=0; i<10000; i++) {
        carpim = 1;
        for(int j = 0; j<10000; j++) {
            if(arr[j] != arr[i]) {
                carpim *= arr[j];
            }
        }
        k[i] = carpim;
    }
    return k;
}

int *carpimListBol(int arr[]){
    int carpim = 1;
    for(int i=0 ; i<10000; i++) {
        carpim *= arr[i];
    }
    int k[10000];
    for(int i = 0; i<10000; i++) {
        k[i] = carpim / arr[i];
    }
    return k;
}

int main() {
    int a[10000];
    for(int i=0; i<=10000; i++) {
        a[i] = i+1;
    }
    int n = sizeof(a) / sizeof(a[0]);

    
    auto start = high_resolution_clock::now();
    int *j = carpimListLoop(a);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    auto start2 = high_resolution_clock::now();
    int* k = carpimListBol(a);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);

    cout << "Time taken by nested loop function: "
        << duration.count() << " microseconds" << endl;

    cout << "Time taken BOL function: "
        << duration2.count() << " microseconds" << endl;
    
}
