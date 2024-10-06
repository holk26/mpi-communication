#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(NULL, NULL);  // Inicializar el entorno MPI

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);  // Obtener número total de procesos

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);  // Obtener el rango del proceso actual

    printf("Hola mundo desde el procesador %d de %d procesadores\n", world_rank, world_size);

    MPI_Finalize();  // Finalizar el entorno MPI
    return 0;
}
