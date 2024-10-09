#include <stdio.h>
#include <mpi.h>
#include <math.h>
#include <time.h>

int main(int argc, char* argv[]) {
    int rank, size, i;
    long long n = 9000000000;  
    double pi = 0.0, sum = 0.0, local_sum = 0.0;
    double start_time, end_time;

    // Inicializar MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Tiempo de inicio
    if (rank == 0) {
        start_time = MPI_Wtime();
    }

    // Método de Leibniz para PI: pi = 4 * (1 - 1/3 + 1/5 - 1/7 + ...)
    for (i = rank; i < n; i += size) {
        local_sum += pow(-1, i) / (2 * i + 1);
    }

    MPI_Reduce(&local_sum, &sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    // Calcular el valor de pi
    if (rank == 0) {
        pi = 4 * sum;
        end_time = MPI_Wtime();
        printf("El valor aproximado de PI es: %.15f\n", pi);
        printf("Tiempo de ejecución: %.5f segundos\n", end_time - start_time);
    }

    // Finalizar MPI
    MPI_Finalize();
    return 0;
}
