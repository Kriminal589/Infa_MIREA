
#include<iostream>
using namespace std;
  
// Служебная функция для обмена значениями, указанными
// двумя указателями
void swapValue(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
    return;
}
  
/* Функция сортировки массива с использованием сортировки вставкой*/
void InsertionSort(int arr[], int *begin, int *end)
{
    // Получить левый и правый индекс подмассива
    // для сортировки
    long left = begin - arr;
    long right = end - arr;
  
    for (long i = left+1; i <= right; i++)
    {
        int key = arr[i];
        long j = i-1;
  
       /* Переместите элементы arr [0..i-1], которые
        больше ключа, на одну позицию впереди
        их текущего положения */
        while (j >= left && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
   }
  
   return;
}
  
// Функция для разделения массива и возврата
// точки раздела
int* Partition(int arr[], int low, int high)
{
    int pivot = arr[high];    // поворот
    int i = (low - 1);  //Индекс меньшего элемента
  
    for (int j = low; j <= high- 1; j++)
    {
        //Если текущий элемент меньше или
                // равен оси поворота
        if (arr[j] <= pivot)
        {
            // индекс приращения меньшего элемента
            i++;
  
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (arr + i + 1);
}
  
  
// Функция, которая находит середину
// значений, указанные указателями a, b, c
// и возвращает этот указатель
int *MedianOfThree(int * a, int * b, int * c)
{
    if (*a < *b && *b < *c)
        return (b);
  
    if (*a < *c && *c <= *b)
        return (c);
  
    if (*b <= *a && *a < *c)
        return (a);
  
    if (*b < *c && *c <= *a)
        return (c);
  
    if (*c <= *a && *a < *b)
        return (a);
  
    if (*c <= *b && *b <= *a)
        return (b);
    return 0;
}
  
// Служебная функция для выполнения начальной сортировки
void IntrosortUtil(int arr[], int * begin,
                  int * end, int depthLimit)
{
    // Подсчитайте количество элементов
    long size = end - begin;
  
      //Если размер раздела мал, выполните сортировку вставкой
    if (size < 16)
    {
        InsertionSort(arr, begin, end);
        return;
    }
  
    //Если глубина равна нулю, используйте heapsort
    if (depthLimit == 0)
    {
        make_heap(begin, end+1);
        sort_heap(begin, end+1);
        return;
    }
  
    // В противном случае используйте концепцию медианы трех, чтобы
    // находим хороший поворот
    int * pivot = MedianOfThree(begin, begin+size/2, end);
  
    // Поменяйте местами значения, указанные двумя указателями
    swapValue(pivot, end);
  
   // Выполнить быструю сортировку
    int * partitionPoint = Partition(arr, begin-arr, end-arr);
    IntrosortUtil(arr, begin, partitionPoint-1, depthLimit - 1);
    IntrosortUtil(arr, partitionPoint + 1, end, depthLimit - 1);
  
    return;
}
  
/* Реализация интросорта */
void Introsort(int arr[], int *begin, int *end)
{
    int depthLimit = 2 * log(end-begin);
  
    //Выполните рекурсивную интросорт
    IntrosortUtil(arr, begin, end, depthLimit);
  
      return;
}
  
//Служебная функция для печати массива размера n
void printArray(int arr[], int n)
{
   for (int i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}
  
// Программа-драйвер для тестирования Introsort
int main()
{
    int arr[] = {25, 15, 8, 27, 77, 53, 109, 404, 228};
    int n = sizeof(arr) / sizeof(arr[0]);
  
    // Передайте массив, указатель на первый элемент и
    // указатель на последний элемент
    Introsort(arr, arr, arr+n-1);
    printArray(arr, n);
  
    return(0);
}
