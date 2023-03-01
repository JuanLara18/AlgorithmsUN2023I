#include <iostream>
#include <random>
#include <time.h>
#include <unistd.h> 

using namespace std;

const int rows = 100; // 100 // 600
const int cols = 100; // 100

double A [rows][cols]; // 600*100
double B [cols][rows]; // 100*600

double result[rows][rows];//600*600 //100*100

/*
double A[3][3] = {
            {3, 2, 1},
            {1, 1, 3},
            {0, 2, 1},
    };
double B[3][2] = {
            {2, 1},
            {1, 0},
            {3, 2},
    };
*/
bool C_AbyB(int n1, int m1, int n2, int m2){ //A[n1][m1] B[n2][m2]
    
    if(m1 != n2) return false;
    
    //Multiplicación de Matrices A * B
    for (int k = 0; k < n1; k++) {
        for (int i = 0; i < m2; i++) {
            double suma = 0.0;
            for (int j = 0; j < n2; j++) {
                
                suma += A[k][j] * B[j][i];
            }
            result[k][i] = suma;
        }
    }
    
    
    /* // Imprime la matriz resultado
    printf("\n");
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            printf("%.2f \t", result[i][j]);
        }
        printf("\n");
    }
    */
    
    return true;
}

void llenarM(){
    //Generar el numero aleatorio
    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<> distr(0, 1);

    //printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            A[i][j] = distr(eng);
            //printf("%.5f \t", A[i][j]);
        }
        //printf("\n");
    }
    
    //printf("\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            B[i][j] = distr(eng);
            //printf("%.5f \t", B[i][j]);
        }
        //printf("\n");
    }
}

double timeTotal(){
    llenarM();  
    //C_AbyB(3,3,3,2);
    
    clock_t begin = clock();
    
    C_AbyB(rows, cols, cols, rows);
    
    clock_t end = clock();
    return (double)(end - begin) / CLOCKS_PER_SEC;
}

int main()
{
    double time_spent = 0.0;
    for(int i=1; i<=10; i++){
        time_spent += timeTotal();
    }
    time_spent /= 10.0;
    printf("The average time is %f seconds", time_spent);
    
    return 0;
}
