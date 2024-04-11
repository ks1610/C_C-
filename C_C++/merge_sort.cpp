#include <iostream>

/*void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}*/

void merge(int arr[], int left, int right, int mid){

    int i, j , k, c[50];
    i = left;
    k = left;
    j = mid + 1;
    
    while(i <= mid && j <= right){
        if(arr[i] < arr[j]){
            c[k] = arr[i];
            k++;
            i++;
        }
        else{
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while(i <= mid){
        c[k] = arr[i];
        k++;
        i++;
    }
    while(j <= right){
        c[k] = arr[j];
        k++;
        j++;
    }

    for(int i = left; i < k; i++)
        arr[i] = c[i];
}

void merge_sort(int *arr, int low, int high){
    int mid;
    if(low < high){
        
        mid = (low+high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);

        merge(arr, low, high, mid);
    }
}

/*void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high){
        //divide the array at mid and sort independently using merge sort
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        //merge or conquer sorted arrays
        merge(arr,low,high,mid);
    }
}*/

int main(){
    int a[5] = {1, 9, 5, 4, 11};
    
    merge_sort(a, 0, 4);

    for(int i = 0; i < 5; i++)
        std::cout<<a[i]<<" ";

    return 0;
}