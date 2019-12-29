#include <stdio.h>

/*
Merhaba bu haftanın sorusu (Stripe) sınavından: Tamsayılardan oluşmuş bir dizi verilsin, fonksiyonunuz dizide görülmeyen en küçük pozitif sayıyı çıktı olarak versin.
Mesela:
Input: [3, 4, -1, 1] —> Output: 2
Input: [1, 2, 0] —>Output: 3.
*/

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



int enKucukPoz(int arr[], int len) {
    quicksort(arr,0,len-1);
    int i = 0;
    while(arr[i] <= 0)
        i++;
    for(int j=1;i<len;i++) {
        if(i+1 < len) {
            if(j!=arr[i] && arr[i+1]>arr[i]){
             return j;
        }
        }else {

            if(j!=arr[i])
                return j;

            /* son sefere gelmişsek ve j == arr[i] eşitliği söz konusuysa array 1'den len'e
                kadar bosluksuz elemana sahip demektir. bu yuzden son j'ye 1 ekleriz.
            */
            else{
                return j+1;
            }
        }
        // j'yi sadece tekrarlayan eleman yoksa artırır
        if(arr[i+1]>arr[i])
            j++;
    }
    return -1;

}

int main() {

    int arr[] = {3, 4, -1, 1,2};
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("En kucuk pos: %d\n",enKucukPoz(arr,len));


}