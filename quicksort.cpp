#include <iostream>
#include <time.h>
#include <random>

//-------------------------------------------------------------

void quicksort(int *array, int left, int right)
{
    int v=array[(left+right)/2];     //ustalanie osi tablicy "v"
    int i,j,x;
    i=left;
    j=right;
    
    do
    {
        while(array[i]<v) i++;       // < sortuje rosnąco; > sortuje malejąco;
        while(array[j]>v) j--;       // > sortuje rosnąco; < sortuje malejąco;
        if(i<=j)
        {
            x=array[i];
            array[i]=array[j];
            array[j]=x;
            i++;
            j--;
        }
    }
    while(i<=j);
    
    if(j>left) quicksort(array, left, j);
    if(i<right) quicksort(array, i, right);
}

//-------------------------------------------------------------

int main(int argc, const char * argv[]) {
    
    std::cout << "Implementation Quicksort v.1\n";
    
    std::cout << "\nHow many numbers in array?: ";
    int howMany;
    std::cin >> howMany;
    
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
    
    std::cout<< "\n\nQuicksort algorithm in progress. Please wait!\n";
    start=clock();
    quicksort(array2, 0, howMany-1);  // left=0 ->indeks początku tablicy; right=howMany-1 ->indeks końca tablicy;
    stop=clock();
    time=(double)(stop-start)/CLOCKS_PER_SEC;

    //liczby po posortowaniu
    std::cout<< "\nAfter sort: \n";
    for(int i=0; i<howMany; i++)
    {
        std::cout<<array2[i]<<" ";
    }
    
    std::cout<<"\nQuicksort time: "<<time<< " s \n\n";
    
    delete [] array;

    return 0;
}
