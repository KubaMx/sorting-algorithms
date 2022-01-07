//  Created by Kuba Makowiecki on 21/10/2021.
//

#include <stdio.h>
#include <iostream>
#include <time.h>
#include <random>

//------------------------------------------------------

int *addArr; //tablica pomocnicza, potrzebna przy scalaniu

//scalenie posortowanych podtablic
void merge(int arr[], int left, int middle, int right)
{
  int i, j;
  
  //zapisujemy lewą częsć podtablicy w tablicy pomocniczej
  for(i = middle + 1; i>left; i--)
    addArr[i-1] = arr[i-1];
 
  //zapisujemy prawą częsć podtablicy w tablicy pomocniczej
  for(j = middle; j<right; j++)
    addArr[right+middle-j] = arr[j+1];
 
  //scalenie dwóch podtablic pomocniczych i zapisanie ich
  //we własciwej tablicy
  for(int k=left;k<=right;k++)
    if(addArr[j]<addArr[i])
      arr[k] = addArr[j--];
    else
      arr[k] = addArr[i++];
}

void mergesort(int arr[],int left, int right)
{
    //gdy mamy jeden element, to jest on już posortowany
    if(right<=left) return;
    
    //znajdujemy srodek podtablicy
    int middle = (right+left)/2;
    
    //dzielimy tablice na częsć lewą i prawa
    mergesort(arr, left, middle);
    mergesort(arr, middle+1, right);
    
    //scalamy dwie już posortowane tablice
    merge(arr, left, middle, right);
}
//------------------------------------------------------

void quicksort(int *array2, int left, int right)
{
    int v=array2[(left+right)/2];     //ustalanie osi tablicy "v"
    int i,j,x;
    i=left;
    j=right;
    
    do
    {
        while(array2[i]<v) i++;       // < sortuje rosnąco; > sortuje malejąco;
        while(array2[j]>v) j--;       // > sortuje rosnąco; < sortuje malejąco;
        if(i<=j)
        {
            x=array2[i];
            array2[i]=array2[j];
            array2[j]=x;
            i++;
            j--;
        }
    }
    while(i<=j);
    
    if(j>left) quicksort(array2, left, j);
    if(i<right) quicksort(array2, i, right);
}

//------------------------------------------------------

int main(int argc, const char * argv[]) {
    
    std::cout<<"Comparison of Mergesort and Quicksort sort times v.1\n";
    std::cout<<"\nType how many numbers to sort?: ";
    int howMany;
    std::cin>>howMany;
    
    //dynamiczne alokowanie pamięci w tablicy
    int *arr;
    arr= new int [howMany];
    addArr= new int[howMany];
    int *array2;
    array2= new int [howMany];
    
    //uruchomienie algorytmu losowania
    srandom((unsigned int)time(NULL));
    
    //przypisanie wylosowanych liczb do tablicy
    for(int i=0; i<howMany; i++)
    {
    arr[i]=random()%100000+1;
    }
    
    //przepisywanie tablicy
    for(int i=0; i<howMany; i++)
    {
    array2[i]=arr[i];
    }
    
    clock_t start, stop;
    double time;
    
    start=clock();
    mergesort(arr, 0, howMany-1);
    stop=clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;
    
     std::cout<< "\nAfter Mergesort: \n";
     for(int i=0; i<howMany; i++)
     {
         std::cout<<arr[i]<<" ";
     }
    
    std::cout<<"\nMergesort time: "<<time<<"s \n";
    
    start=clock();
    quicksort(array2, 0, howMany-1);
    stop=clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;
    
    std::cout<< "\nAfter Quicksort: \n";
    for(int i=0; i<howMany; i++)
    {
        std::cout<<array2[i]<<" ";
    }
  
    std::cout<<"\nQuicksort time: "<<time<<"s \n\n";
    
    delete [] arr;
    delete [] addArr;
    delete [] array2;
    
        return 0;
}
