#include <stdio.h>


int partition(int a[], int left, int right)
{
   int pivot = a[left];

   while (left < right)
   {
      while(left < right && a[right] >= pivot)
         right--;
      a[left] = a[right];

      while (left < right && a[left] <= pivot)
         left++;
      a[right] = a[left];
   }

   a[left] = pivot;
   return left;
}

void quickSort(int a[], int left, int right)
{
   if(left < right)
   {
      int pivot = partition(a, left, right);
      quickSort(a, left, pivot - 1);
      quickSort(a, pivot + 1, right);
   }
}


int main()
{
   int a[10] = {16,20,23,27,45,56,89,54,76,82};
   quickSort(a, 0 ,9);
   for (int i = 0; i < 10; i++){
      printf("%d ", a[i]);
   }
   printf("\n");
   return 0;
}