#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>


#define N 700


int main(){

    // Block of code Generates 2 random matrix
    srand(time(NULL)); int currentSize = 50;
    static double a[N][N];
    static double b[N][N];
    static double c[N][N];
    int row=0, col=0;
    for( row=0; row<N; row++ ){
        for( col=0; col<N; col++ ){
            a[row][col] = rand();
            b[row][col] = rand();
        }
    }
    // Clock Vars
    LARGE_INTEGER start, finish; int elapsed=0;

    FILE *ijk = fopen("ijk.csv", "w");
    FILE *jik = fopen("jik.csv", "w");
    FILE *kij = fopen("kij.csv", "w");
    FILE *ikj = fopen("ikj.csv", "w");
    FILE *jki = fopen("jki.csv", "w");
    FILE *kji = fopen("kji.csv", "w");
    FILE *ctr = fopen("nCtr.csv", "w");

    printf("ijk\t\tjik\t\tkij\t\tikj\t\tjki\t\tkji\n");

    // Goes through and changes the size of the array all at all points
    for ( currentSize=50; currentSize<N; currentSize+=50 ){
        int i,j,k; double sum, r; static double c[N][N];
        if(currentSize == N-50) fprintf(ctr, "%d,",currentSize); else fprintf(ctr, "%d",currentSize);


        // IJK
        QueryPerformanceCounter(&start);
        for (i=0; i<currentSize; i++) {
            for (j=0; j<currentSize; j++) {
                sum = 0.0;
                for (k=0; k<currentSize; k++)
                    sum += a[i][k] * b[k][j];
                c[i][j] = sum;
            }
        }
        QueryPerformanceCounter(&finish);
        elapsed = (int) (finish.QuadPart - start.QuadPart);
        printf("N(%d): %d\t",currentSize,elapsed);
        if(currentSize == N-50) fprintf(ijk, "%d,", elapsed); else fprintf(ijk, "%d",currentSize);
        // JIK
        QueryPerformanceCounter(&start);
        for (j=0; j<currentSize; j++) {
            for (i=0; i<currentSize; i++) {
                sum = 0.0;
                for (k=0; k<currentSize; k++)
                    sum += a[i][k] * b[k][j];
                c[i][j] = sum;
            }
        }
        QueryPerformanceCounter(&finish);
        elapsed = (int) (finish.QuadPart - start.QuadPart);
        printf("N(%d): %d\t",currentSize,elapsed);
        if(currentSize == N-50) fprintf(jik, "%d,", elapsed); else fprintf(jik, "%d",currentSize);


        // KIJ
        QueryPerformanceCounter(&start);
        for (k=0; k<currentSize; k++) {
            for (i=0; i<currentSize; i++) {
                r = a[i][k];
                for (j=0; j<currentSize; j++)
                    c[i][j] += r * b[k][j];
            }
        }
        QueryPerformanceCounter(&finish);
        elapsed = (int) (finish.QuadPart - start.QuadPart);
        printf("N(%d): %d\t",currentSize,elapsed);
        if(currentSize == N-50) fprintf(kij, "%d,", elapsed); else fprintf(kij, "%d",currentSize);
        // IKJ
        QueryPerformanceCounter(&start);
        for (i=0; i<currentSize; i++) {
            for (k=0; k<currentSize; k++) {
                r = a[i][k];
                for (j=0; j<currentSize; j++)
                    c[i][j] += r * b[k][j];
            }
        }
        QueryPerformanceCounter(&finish);
        elapsed = (int) (finish.QuadPart - start.QuadPart);
        printf("N(%d): %d\t",currentSize,elapsed);
        if(currentSize == N-50) fprintf(ikj, "%d,", elapsed); else fprintf(ikj, "%d",currentSize);

        // JKI
        QueryPerformanceCounter(&start);
        for (j=0; j<currentSize; j++) {
            for (k=0; k<currentSize; k++) {
                r = b[k][j];
                for (i=0; i<currentSize; i++)
                    c[i][j] += a[i][k] * r;
            }
        }
        QueryPerformanceCounter(&finish);
        elapsed = (int) (finish.QuadPart - start.QuadPart);
        printf("N(%d): %d\t",currentSize,elapsed);
        if(currentSize == N-50) fprintf(jki, "%d,", elapsed); else fprintf(jki, "%d",currentSize);
        // KJI
        QueryPerformanceCounter(&start);
        for (k=0; k<currentSize; k++) {
            for (j=0; j<currentSize; j++) {
                r = b[k][j];
                for (i=0; i<currentSize; i++)
                    c[i][j] += a[i][k] * r;
            }
        }
        QueryPerformanceCounter(&finish);
        elapsed = (int) (finish.QuadPart - start.QuadPart);
        printf("N(%d): %d\n",currentSize,elapsed);
        if(currentSize == N-50) fprintf(kji, "%d,", elapsed); else fprintf(kji, "%d",currentSize);

    }

    fclose(ijk);
    fclose(jik);
    fclose(kij);
    fclose(ikj);
    fclose(jki);
    fclose(kji);
    fclose(ctr);

    return 0;
}
