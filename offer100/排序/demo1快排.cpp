#include <stdio.h>

int partition(int a[], int left, int right)
{
   int pivot = a[left];
   while (left < right)
   {
      while (left < right && a[right] >= pivot)
         right--;
      a[left] = a[right];
      while (left < right && a[left] <= pivot)
         left++;
      a[right] = a[left];
   }
   a[left] = pivot; 
   return left;
}

//a表示要排序的数组
//1eft 和 right 表示区间的左右端点
void quicksort(int a[], int left,int right)
{   
     //区间长度大于1才需要划分和递归
    if(left < right)
    { 
      // 返回枢轴位置
      int pivot = partition(a, left, right);
      quicksort(a, left, pivot-1);
      quicksort(a, pivot+1, right);
    }
}
int main()
{
   int a[10] = {16,20,23,27,45,56,89,54,76,82};
   quicksort(a, 0 ,9);
   for (int i = 0; i < 10; i++){
      printf("%d ", a[i]);
   }
   printf("\n");
   return 0;
}