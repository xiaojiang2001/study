#include <bits/stdc++.h>

using namespace std;


// // 向下调整某个节点
// /*
// a: 数组
// idx: 节点下标
// len: 长度 判断是否到了叶节点
// */
// void downAdjust(int a[], int idx, int n)
// {
//     int i = idx;    // 待调整的节点
//     int j = 2 * i;  // 左孩子
//     while (j <= n)    // 左孩子不存在 -> 是否为叶节点
//     {
//         // 找到左右孩子较大者
//         if(j + 1 <= n && a[j+1] > a[j])
//             j++;
//         // 交换
//         if(a[i] < a[j]) {
//             swap(a[i], a[j]);
//             i = j;
//             j = i * 2;
//         }
//         else
//             break;
//     }
// }

// // 堆排序
// void heapSort(int a[], int n)
// {
//     //建堆(最后一个非叶结点开始依次向下调整)
//     for (int  i = n / 2; i >= 1; i--) {
//         downAdjust(a, i, n);
//     }

//     // 排序
//     for (int i = n; i >= 2; i--) {
//         swap(a[i], a[1]);
//         downAdjust(a, 1, i-1);
//     }
// }

// int main()
// {
//     int a[] = {1,4,7,9,10,5,8};
//     heapSort(a, 7);
//     for (int i = 0; i < 7;i++) {
//         printf("%d ", a[i]);
//     }
//     return 0;
// }


// 调节下标为idx的节点
// 数组长度为n， 下标从0开始
void adjustToDown(int a[], int idx, int n)
{
    int i = idx;        // 当前节点
    int j = idx * 2 + 1;    // 左节点 保存较大的子节点
    while (j <= n)
    {
        if(j + 1 <= n && a[j] < a[j+1])
            j++;
        if(a[i] < a[j]) {
            swap(a[i], a[j]);
            i = j;
            j = i * 2 + 1;
        }
        else
            break;
    }
}

// n是长度
void heapSort(int a[], int n)
{
    // 建堆
    for (int i = (n-1) / 2; i >= 0; i--) {
        adjustToDown(a, i, n-1);
    }
    for (int i = n - 1; i >= 1; i--) {
        swap(a[0], a[i]);
        adjustToDown(a, 0, i-1);
    }
}
int main()
{
    int n = 10;
    // int *a = (int *)malloc(n * sizeof(int));
    int *a = new int[n];

    srand(time(NULL));
    cout << "原始数组为: " << endl;
    for (int i = 0; i < n; i++) {
       a[i] = rand() % 100;
       cout << a[i] << " ";
    }
    cout << endl;

    heapSort(a, n);

    cout << "排序数组为: " << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    delete a;
    return 0;
}