#include <stdio.h>

#define ENDE 99999999
#define MAX 100

void polyprint(double * arr) {
    // MAX array size
    int i;
    for(i = 0; i < MAX || arr[i] != ENDE; ++i) {
        printf("%.1lf\t", arr[i]);
    }
    puts("");
    // printf("\n");
}



void polyadd(double* target, double* sum1, double* sum2) {
    int i, j, k;
    i = j = k = 0;

    while((i < MAX && j < MAX) || (sum1[i] != ENDE && sum2[j] != ENDE)){
        if(sum1[i] == ENDE) 
            target[k++] = sum2[j++];
        else if (sum2[j] == ENDE) {
            target[k] = sum1[i];
            k++;
            ++i;
        }
        else
            target[k++] = sum1[i++] + sum2[j++];
    }

    return;
}

double f(double* arr, int x) {
    double res = 0.0;
    int i;
    
    for(i = 0, arr[i] != ENDE && i < MAX, ++i) {
        
        int j, p = 1;
        for(j = 0; j < i; ++j)
            p = x * p;

        res = p * arr[i] + res;

    }

    return res;
}






