/*
Bir liste ve bir k sayısı verilmiş olsun. Eğer liste içindeki sayıların toplamı k değerini veriyorsa true çıktısı veren foksiyonu yazınız.

Örneğin, verilen [10, 15, 3, 7] ve k = 17, return true çünkü 10 + 7 = 17.

Bonus: Bunu listeyi tek defa döndürerek yapabilir misiniz?

*/
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <unordered_set>
#include <time.h>
#include <chrono>

using namespace std::chrono;
using namespace std;

void swap(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end) {

    int pivot = arr[end];
    int pIndex = start;

    for(int i=start; i < end; ++i) {
        if(arr[i] < pivot){
            swap(&arr[i], &arr[pIndex]);
            ++pIndex;
        }

    }
    swap(&arr[pIndex], &arr[end]);
    return pIndex;
}


void quicksort(int arr[], int start, int end) {
    int pIndex;
    if(start < end) {
        pIndex = partition(arr, start, end);
        quicksort(arr, start, pIndex-1);
        quicksort(arr, pIndex+1, end);
    }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
		cout << arr[i] << " ";
    }
    printf("\n");
}

/*
    artik arrayimiz sorted oldugu için sol ve sagdan baslayip toplama ulaşana kadar içe gideriz.
    toplamin verilen sayidan büyük olmasi durumunda listenin sagini yani büyük elemani geriye çekeriz.
    toplamin küçük olmasi durumunda ise solu yukari çekerek toplama ulasmaya çalisiriz.
    liste bossa ya da toplam bulunamazsa false döndürülür.
*/
bool doesAddUpLoop(int arr[], int k, int len){

    for(int i=0; i<=len; i++) {
        for(int j=i+1; j<=len; j++) {
            if((arr[i]+ arr[j]) == k)
                return true;
        }
    }
    return false;

}

bool doesAddUpSort(int arr[], int k, int len){
    quicksort(arr,0,len);
    int left = 0;
    int right = len;
    while(left<right){
        if(arr[left] + arr[right] == k)
            return true;
        else if(arr[left] + arr[right] > k)
            --right;
        else
            ++left;
    }
    return false;

}

/*
    eger arraydeki sayilarin tümleyenlerini bir hash set'e kaydedip dogrusal bir sekilde iterate ederken
    hashset içinde bu sayilarin tümleyenlerinden biriyle karsilasirsak hedef toplama ulasmisiz demektir.
*/
bool doesAddUpHash(int arr[], int k, int len){
    unordered_set <int> compSet;
    for(int i=0; i<= len; ++i) {
        //  end iteratorune eşit değilse bulunmuş demektir.
        if (compSet.find(arr[i]) != compSet.end())
            return true;
        else{
            compSet.insert(k-arr[i]);
        }
    }
    return false;
}

int main() {

    int arr[100000];
    for(int i=0; i<100000; i++) {
        arr[i] = rand() % 100;
    }
    int n = sizeof(arr) / sizeof(arr[0]);

    /*
        3 ALGORITMA'NIN ZAMAN PERFORMANSLARI
    */

    // iç içe loop
    auto start = high_resolution_clock::now();
    printf("Does Add Up(nested loops): %d\n",doesAddUpLoop(arr,63,n-1));
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // hash set ile
    auto start2 = high_resolution_clock::now();
    printf("Does Add Up(with hash set): %d\n",doesAddUpHash(arr,63,n-1));
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);

    // quick sort ile(sort sira degistigi için en son implement edildi)
    auto start1 = high_resolution_clock::now();
    printf("Does Add Up(with quick sort): %d\n",doesAddUpSort(arr,63,n-1));
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    cout << "Time taken by nested loop function: "
         << duration.count() << " microseconds" << endl;

    cout << "Time taken with quick sort function: "
         << duration1.count() << " microseconds" << endl;

    cout << "Time taken by hash set function: "
         << duration2.count() << " microseconds" << endl;


    return 0;

}
