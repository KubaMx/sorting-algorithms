//  Created by Kuba Makowiecki on 19/10/2021.
//

#include <iostream>
#include <time.h>
#include <random>

//-------------------------------------------------------------

void bubblesort(int *arr, int n)
{
    for(int i=1; i<n; i++)
    {
        for(int j=n-1; j>=1; j--)
        {
            if(arr[j]<arr[j-1])
            {
                int buffer;
                buffer=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=buffer;
            }
        }
    }
}

//-------------------------------------------------------------

int main(int argc, const char * argv[]) {
    
    std::cout<<"Implementation of Bubblesort v.1\n";
    std::cout<<"\nType how many numbers to sort?: ";
    int howMany;
    std::cin>>howMany;
    
    //dynamiczna alokacja tablicy
    int *array;
    array = new int [howMany];
    
    //inicjowanie generatora liczb losowych
    srandom ((unsigned int)time(NULL));
    
    //wczytywanie losowych liczb do tablicy
    for(int i=0; i<howMany; i++)
    {
        array[i]=random()%100000+1;
    }
    
    //liczby przed posortowaniem
    std::cout<< "\nBefore sort: \n";
    for(int i=0; i<howMany; i++)
    {
        std::cout<<array[i]<<" ";
    }
    
    clock_t start, stop;
    double time;
    
    std::cout<< "\n\nBubblesort in progress. Please wait!\n";
    start=clock();
    bubblesort(array, howMany);
    stop=clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;
    std::cout<<"\nBubblesort time: "<<time<< " s \n";
    
    //liczby po posortowaniu
    std::cout<< "\nAfter sort: \n";
    for(int i=0; i<howMany; i++)
    {
        std::cout<<array[i]<<" ";
    }
    
    delete [] array;
    
        return 0;
}
