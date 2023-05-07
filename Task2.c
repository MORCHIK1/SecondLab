#include <stdio.h>
#include <malloc.h>
#include <math.h>

float rec_fract(int);
float L(int, int, float);
float suma(float*, int, int, float);

float main() {
    int n, k, i;
    float x;
    float* Y;

    printf("Введіть n");
    scanf("%d", &n);

    Y=(float*)malloc(n*sizeof(float));

    printf("Введіть х");
    scanf("%f", &x);

    printf("Введіть масив Y");
    for(i=0; i<n; i++)scanf("%f", &Y[i]);

    float sum = 0;
    k=n;
    sum = suma(Y, k, n ,x);

    printf("%f", sum);
    return 0;
}

float suma(float* Y, int k, int n, float x){
    if(k==-1)return 0;
    return suma(Y,k-1,n,x) + pow(Y[k]*(-1),k) * L(n,k,x);
}

float L(int n, int k, float x) {
    if (k == 0)return 1;
    if (k == 1)return x; 
    return x*L(n,k-1,x)-rec_fract(k)*L(n,k-2,x);
}

float rec_fract(int k){
    return (k-1.0)/((4.0*k)-2.0);
}
