#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

void countingSort(int array[], int size) {
  int max = array[0];
  int i;
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }
  printf("\nDizinin en büyük değeri büyüklüğünde bir dizi oluşturuldu...\n\n");
  int output[max+1];

  int count[max+1];
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }
  printf("\n\nYeni oluşturulan dizinin tüm elemanları 0 a eşitlendi...\n");
  for(i=0;i<max+1;i++)printf("%d ",count[i]);

  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }
  printf("\n\nDizideki her değerin yeni oluşturulan dizideki karşılığı bir artırıldı...\n");
  for(i=0;i<max+1;i++)printf("%d ",count[i]);

  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }
  printf("\n\nYeni oluşturulan dizi icremental olarak eklenerek değerlerin konumları belirlendi...\n");
  for(i=0;i<max+1;i++)printf("%d ",count[i]);
    for(i=0;i<size;i++)output[i]=0;
int k;
  printf("\n\nAna dizimizden son değerden başlayarak ilk değere doğru seçilen her değer tek tek incremente dizi konumuna göre output dizisine yerleştiririldi..\n");
  for (int i = size - 1; i >= 0; i--) {

    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
    for(k=0;k<size;k++)printf("%d ",output[k]);
    printf("\n");
  }

    printf("\nSon olarak ana dizimizdeki konumları output dizisindeki konumlara göre ayarladık...\n\n");
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
    int n,i;

  printf("Kaç elemanlı olacak:");
  scanf("%d",&n);
  int array[n];
  printf("\nDeğerleri giriniz:\n");
  for(i=0;i<n;i++)
  {
  scanf("%d",&array[i]);
  if(array[i]<0){printf("\nCounting sortta 0 dan küçük sayı girilemez...\nTekrar giriniz:");scanf("%d",&array[i]);}
  }
  countingSort(array, n);
  printArray(array, n);
printf("Ve işlem tamamlandı...\nCREATOR: Ömer CEVHER - 21110131002");
}
