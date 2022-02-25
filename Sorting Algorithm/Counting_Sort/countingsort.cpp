#include <iostream>

using namespace std;

const int BUCKET_SIZE = 100;

void sort(int* data, int n) {

    int count[BUCKET_SIZE] = { 0 };
    int output[n];

    for (int i=0;i<n;i++) {
        count[data[i]]++;
    }

    for(int i=1;i<BUCKET_SIZE;i++) {
        count[i] += count[i-1];
    }

    for(int i=n-1;i>=0;i--) {
        count[data[i]]--;
        output[count[data[i]]] = data[i];
    }

    for(int i=0;i<n;i++) {
        data[i] = output[i];
    }
}

void show(int *data, int n) {
    for ( int i = 0; i < n; i++ ) {
        cout << data[i] << " ";
    }
}


int main(int argc, const char * argv[]) {

    int data[] = {22, 61, 99, 66, 72, 92, 52};
    int n = sizeof(data)/sizeof(data[0]);

    sort(data, n);
    show(data, n);

	return 0;
}