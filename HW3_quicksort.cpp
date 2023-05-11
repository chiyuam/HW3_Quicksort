#include <iostream>
using namespace std;
/*先寫一個分割函數，用來得知pivot的在陣列的相對位置*/
int partition(int arr[], int start, int end){
    int pivot = arr[start];//把pivot設為陣列的起始
    int count = 0;//宣告一個整數，用來得知pivot到底該被往右移動幾格
    //依序檢查該陣列裡面的數值，如果pivot比該數值大，就算移動一格
    for(int i = start + 1; i <= end; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }
    int pivot_index = start + count;//得知pivot在該陣列的索引值
    swap(arr[start], arr[pivot_index]);//交換pivot以及原本位於pivot索引值得數值
    int i = start, j = end;
    //此時已經把陣列分為兩部份了，所以依序把左邊以及右邊的陣列做排序
    while(i < pivot_index && j > pivot_index){
        while(arr[i] < pivot){
            i++;
        }//從pivot的起始點開始檢查，如果比pivot小就繼續找
        while(arr[j] >= pivot){
            j--;
        }//從陣列的最末端開始找，如果比pivot大就繼續找
        if(i < pivot_index && j > pivot_index){
        /*一定要加這行判斷式，因為假設遇到上述兩行while有一行已經排到排序結束了，
        如果不加這行會打亂原本就排好的陣列*/
            swap(arr[i++], arr[j--]);//交換好值後在往下一個去找
        }
    }
    return pivot_index;//回傳pivot的索引，供下面的遞迴函式使用
}//開始寫遞迴函式
void Quicksort(int arr[], int start, int end){
    if(start >= end){
        return;//遞迴停止點
    }
    int p = partition(arr, start, end);
    //把陣列分兩部分做排序
    Quicksort(arr, start, p-1);
    Quicksort(arr, p+1, end);
}
int main(){
    int arr[] = {33, 67, 8, 13, 54, 119, 3, 84, 25, 41};
    Quicksort(arr, 0, 9);
    for(int i= 0; i < 10; i++){
        cout << arr[i] << " " ;
    }
    return 0;
}