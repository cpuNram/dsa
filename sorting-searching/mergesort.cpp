#include <iostream>

void
merge(int A[], int left, int mid, int right)
{
    int a1 = mid-left+1;
    int a2 = right-mid;
    int L[a1], R[a2];
    for (int x = 0; x < a1; x++) L[x] = A[left+x];
    for (int x = 0; x < a2; x++) R[x] = A[mid+1+x];
    
    int i = 0; // left array index
    int j = 0; // right array index
    int k = left; // original array index.
    while (i < a1 && j < a2) {
        if (L[i] <= R[j])  A[k] = L[i], i++;
        else A[k] = R[j], j++;
        k++;
    }
    while (i < a1) A[k] = L[i], i++, k++;
    while (j < a2) A[k] = R[j], j++, k++;
}

void
printA(int A[], int len)
{
    for (int i = 0; i < len; i++) printf("%d ", A[i]);
    printf("\n");
}
void
mergesort(int array[], int left, int right)
{
    if (left < right) { 
        int mid = (left+right)/2;
        mergesort(array, left, mid);
        mergesort(array, mid+1, right);
        merge(array, left, mid, right);
    }
}

int
main(void)
{
    int A[] = {8, 1, 6, 2, 4, 9, 2, 2, 10, 3, 50};
    int len = sizeof(A)/sizeof(A[0]);
    printA(A, len);
    mergesort(A, 0, len-1);
    printA(A, len);
    return 0;
}
