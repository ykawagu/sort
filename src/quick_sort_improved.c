#include <stdio.h>

//フェルマー素数
#define N ((1<<16)+1)

int A[N];

/*
A[0], A[1], ..., A[n-1] をソートして昇順に書き換える関数
*/
void quick_sort_improved(int A[], int n){
    int i, l, r,pivot;
    pivot = A[0];
    if (n == 1) return;
    else{
        for(i = l = 1, r = n-1; i <= r; i++){
            if(A[i] < pivot){
                int z = A[l];
                A[l] = A[i];
                A[i] = z;
                l++;
            }
            if(A[i] > pivot){
                int z = A[r];
                A[r] = A[i];
                A[i] = z;
                r--;
                i--;
            }
        }
        //{pivot未満}{pivot}{pivot以上}に並び替える
        int z = A[l-1];
        A[l-1] = A[0];
        A[0] = z;
        if (l >= 2) quick_sort_improved(A, l);
        if (r <= n-2) quick_sort_improved(A+r+1,n-r-1);
    }
}

int main(){
    int i;
    A[0] = 0;
    A[1] = 3; //原始元
    for(i=2;i<N;i++){
        A[i] = (long long int) A[i-1] * A[1] % N;
    }
    
    // すべての要素が同じ場合でも計算が早く終わるか確認する

  quick_sort_improved(A, N);
  for(i=0;i<N;i++){
    if(A[i] != i) printf("ERROR %dth element is %d\n", i, A[i]);
        }
}
