#include <stdio.h>
#include <time.h>

#define ROUNDS 100000000
#define ARR_LEN 98444

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main() {
    int i;
    int arr[ARR_LEN];
    clock_t t;
    double time_taken; 
    for (i = 0; i < ARR_LEN; ++i) {
        arr[i] = i;
    } 

    t = clock();
        binsearch(10, arr, ARR_LEN);
    t = clock(); - t;
    
    // calculate the elapsed time
    time_taken = ((double)t)/CLOCKS_PER_SEC; 
    printf("Binsearch 1 time elapsed: %f\n", time_taken);

    t = clock();
        binsearch2(10, arr, ARR_LEN);
    t = clock(); - t;
    
    // calculate the elapsed time
    time_taken = ((double)t)/CLOCKS_PER_SEC; 
    printf("Binsearch 2 time elapsed: %f\n", time_taken);
}

int binsearch2(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n -1;

    mid = (low + high)/2;
    while ((low <= high) && (x != v[mid])) { //Expensive check each time
        if (x < v[mid]) {
            high = mid + 1;
        } else {
            low = mid + 1;
        }
        
        mid = (low + high)/2;
    }
    return x == v[mid] ? mid : -1;

}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n) {
    int low, high, mid;
   
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid + 1;
        else if (x > v[mid])
            low = mid + 1;
        else    /* found match */
            return mid;
    }
    return -1; /* no match */
}
