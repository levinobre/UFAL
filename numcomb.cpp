#include <stdio.h>
int possible(int arr[], int n) {
 int i;
 for (i = n-1; i > 0; i--)
  if (arr[i] > arr[i-1])
  return 1;
 return 0;
}
void print(int arr[], int n) {
 int i;
 for (i = 0; i < n; i++)
  printf("%d",arr[i]);
  printf("\n");
}
void swap(int* a, int* b) {
 int t = *a;
 *a = *b;
 *b = t;
}
int partition (int arr[], int low, int high) {
 int pivot = arr[high];
 int i = (low - 1);
 int j;
 for ( j = low; j <= high- 1; j++) {
  if (arr[j] <= pivot) {
   i++;
   swap(&arr[i], &arr[j]);
  }
 }
 swap(&arr[i + 1], &arr[high]);
 return (i + 1);
}
void quickSort(int arr[], int low, int high) {
 if (low < high) {
  int pi = partition(arr, low, high);
  quickSort(arr, low, pi - 1);
  quickSort(arr, pi + 1, high);
 }
}
void nextNumber(int arr[], int n) {
 int i, j;
 int currentMin = 1000000;
 int index;
 int temp;
 for ( i = n-1; i > 0; i--) {
  if (arr[i] > arr[i-1]) {
   for ( j = i; j < n; j++) {
    if (arr[i-1] < arr[j] && currentMin > arr[j]) {
     currentMin = arr[j];
     index = j;
    }
   }
   temp = arr[i-1];
   arr[i-1] = arr[index];
   arr[index] = temp;
   quickSort(arr,i,n-1);
   break;
  }
 }
 return;
}
int main() {
 int num;
 int tmp;
 int len = 0;
 int i;
 scanf("%d",&num);
 tmp = num;
 while (tmp) {
  tmp /= 10;
  len++;
 }
 int arr[len];
 for (i = len-1; i >= 0; i--) {
  arr[i] = num%10;
  num /= 10;
 }
 quickSort(arr,0,len-1);
 while(1) {
  print(arr,len);
  if(possible(arr,len)) {
   nextNumber(arr,len);
  } else {
   printf("Sem mais possibilidades\n");
   break;
  }
 }
 return 0;
}
