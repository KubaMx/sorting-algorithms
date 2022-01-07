//  Created by Kuba Makowiecki on 28/10/2021.
//

#include<iostream>
#include<random>
using namespace std;

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

int main()
{
    int *arr, n; //liczba elementów tablicy
    
    cout<<"Implementation of Mergesort v.1.0\n\n";
    cout<<"Type how many numbers to sort: ";
    cin>>n;
    arr = new int[n]; //przydzielenie pamięci na tablicę liczb
    addArr = new int[n]; //przydzielenie pamięci na tablicę pomocniczą
    
    
    //inicjowanie generatora liczb losowych
    srandom((unsigned int)time(NULL));
    
    //wczytanie pseudolosowych elementów tablicy
    for(int i=0;i<n;i++)
        arr[i]=random()%100000+1;
    
    //sortowanie wczytanej tablicy
    mergesort(arr,0,n-1);
    
    //wypisanie wyników
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    cout<<endl<<endl;
    
    return 0;
}
