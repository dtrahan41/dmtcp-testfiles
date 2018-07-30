#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
#include <string.h>
#include <mpi.h>

int main(int argc, char* argv[]){

  MPI_File outputFile;
  int process_Rank, size_Of_Cluster;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size_Of_Cluster);
  MPI_Comm_rank(MPI_COMM_WORLD, &process_Rank);

  MPI_File_open(MPI_COMM_WORLD, argv[1], MPI_MODE_WRONLY | MPI_MODE_CREATE, MPI_INFO_NULL, &outputFile);
 
  char string_buff [30];

  for(int i = 1; i <= 60; i++){
    snprintf(string_buff, 30, "Counting: %d from process %d\n", i, process_Rank);
    
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_File_write_ordered(outputFile, string_buff, strlen(string_buff), MPI_CHAR, MPI_STATUS_IGNORE);

    printf("%s", string_buff);
      
    sleep(1);
  }

  MPI_File_close(&outputFile);

  MPI_Finalize();

  return 0;

}
