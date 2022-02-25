#include <iostream>

using namespace std;

const int BUCKET_SIZE = 10;

void countingSort(int* data, int n, int exp) {

    int count[BUCKET_SIZE] = { 0 };
    int output[n];

    for (int i=0;i<n;i++) {
        count[(data[i]/exp)%BUCKET_SIZE]++;
    }

    for(int i=1;i<BUCKET_SIZE;i++) {
        count[i] += count[i-1];
    }

    for(int i=n-1;i>=0;i--) {
        count[(data[i]/exp)%BUCKET_SIZE]--;
        output[count[(data[i]/exp)%BUCKET_SIZE]] = data[i];
    }

    for(int i=0;i<n;i++) {
        data[i] = output[i];
    }
}

int getMax(int data[], int n) {

    int max = data[0];
	
    for (int i = 1; i < n; i++)
        if (data[i] > max)
            max = data[i];    

    return max;
}

void radixSort(int data[], int n) {

    int maximum = getMax(data, n);

    for (int exp = 1; maximum/exp > 0; exp *= 10) {
        countingSort(data, n, exp);
    }
}

void show(int *data, int n) {
    for ( int i = 0; i < n; i++ ) {
        cout << data[i] << " ";
    }
}

int main(int argc, const char * argv[]) {

    int data[] = {1201,1452,8643,3743,1032,3456,3718,1938};
    int n = sizeof(data)/sizeof(data[0]);
   
    radixSort(data, n);
    show(data, n);

    return 0;
}