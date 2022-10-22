#include<stdlib.h>
#include<stdio.h>
#include <time.h>
#include<math.h>
#include<locale.h>
void insertionSort(int insertion[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = insertion[i];
        j = i - 1;
        while (j >= 0 && insertion[j] > key) {
            insertion[j + 1] = insertion[j];
            j = j - 1;
        }
        insertion[j + 1] = key;
    }
}
    
   
void merge(int arr[], int l, int m, int r)
{
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;
int L[n1], R[n2];
for (i = 0; i < n1; i++)
L[i] = arr[l + i];
for (j = 0; j < n2; j++)
R[j] = arr[m + 1+ j];
i = 0;
j = 0;
k = l;
while (i < n1 && j < n2)
{
if (L[i] <= R[j])
{
arr[k] = L[i];
i++;
}
else
{
arr[k] = R[j];
j++;
}
k++;
}
while (i < n1)
{
arr[k] = L[i];
i++;
k++;
}
while (j < n2)
{
arr[k] = R[j];
j++;
k++;
}
}

void mergeSort(int arr[], int l, int r)
{
if (l < r)
{
int m = l+(r-l)/2;
mergeSort(arr, l, m);
mergeSort(arr, m+1, r);
merge(arr, l, m, r);
}
}

int main()
{   setlocale(LC_ALL,"Turkish");
    int i;
    clock_t start, end;
    double gecensure;
    
    int insertion10[10],insertion100[100],insertion1000[1000];
    int merge10[10],merge100[100],merge1000[1000];
    srand(time(NULL));
    for(i=0;i<10;i++){
    merge10[i]=rand()%10000+0;
    insertion10[i]=merge10[i];
    }
     for(i=0;i<100;i++){
    merge100[i]=rand()%10000+0;
    insertion100[i]=merge100[i];
    }
    for(i=0;i<1000;i++){
    merge1000[i]=rand()%10000+0;
    insertion1000[i]=merge1000[i];
    }
  printf("\n\n10 adet elemanlı dizilerde karşılaştırma...\n");
    
    start = clock();
    mergeSort(merge10, 0, 9);
    end = clock();
    gecensure = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nMERGE SORT kullanıldığında geçen süre= %f saniye = %.0f mikrosaniye\n",gecensure,gecensure*1000000);
    gecensure=0;
    start = clock();
    insertionSort(insertion10, 10);
    end =clock();
    gecensure = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("INSERTION SORT kullanıldığında geçen süre= %f saniye = %.0f mikrosaniye\n",gecensure,gecensure*1000000);
    gecensure=0;
    
    printf("\n\n100 adet elemanlı dizilerde karşılaştırma...\n");
    
     start = clock();
    mergeSort(merge100, 0, 99);
    end = clock();
    gecensure = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nMERGE SORT kullanıldığında geçen süre= %f saniye = %.0f mikrosaniye\n",gecensure,gecensure*1000000);
    gecensure=0;
    start = clock();
    insertionSort(insertion100, 100);
    end =clock();
    gecensure = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("INSERTION SORT kullanıldığında geçen süre= %f saniye = %.0f mikrosaniye\n",gecensure,gecensure*1000000);
    gecensure=0;
    
    
    
    printf("\n\n10000 adet elemanlı dizilerde karşılaştırma...\n");
    
    start = clock();
    mergeSort(merge1000, 0, 999);
    end = clock();
    gecensure = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nMERGE SORT kullanıldığında geçen süre= %f saniye = %.0f mikrosaniye\n",gecensure,gecensure*1000000);
    gecensure=0;
    start = clock();
    insertionSort(insertion1000, 1000);
    end =clock();
    gecensure = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("INSERTION SORT kullanıldığında geçen süre= %f saniye = %.0f mikrosaniye\n",gecensure,gecensure*1000000);
    gecensure=0;
    
    
    printf("\n\n\nÖrnek amaçlı 100 elemanlı dizilerin son durumlarını işlemin başarılı olduğuna emin olmak için ekrana yazalım...");
    printf("\n\n100 adet elemandan oluşan ve MERGE yapılan dizi...\n");
    for(i=0;i<100;i++){
        printf("%d  ",merge100[i]);
        if(i%20==0&&i!=0)printf("\n");
    }
    printf("\n");
printf("\n\n100 adet elemandan oluşan ve INSERTION yapılan dizi...\n");
    for(i=0;i<100;i++){
        printf("%d  ",insertion100[i]);
        if(i%20==0&&i!=0)printf("\n");
    }
    printf("\n\nGörüldüğü üzere iki dizi de aynı ve rastgele seçilen elemanlar barındırıyor...\nKod başarılı...");
    
    
    printf("\n\nBu kod Ömer CEVHER tarafından yazılmıştır...\n");
return 0;
}









