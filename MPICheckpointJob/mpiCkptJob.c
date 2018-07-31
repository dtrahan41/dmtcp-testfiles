/*
===========================================================================
========== DOES NOT WORK ON SUMMIT, OMNIPATH SUPPORT UNAVAILABLE ==========
===========================================================================

Program created by Daniel Trahan
Last Updated 31 July 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mpi.h>

int main(int argc, char* argv[]){

  //====================Initialization========================

  //Declare Variables
  MPI_File outputFile;
  int process_Rank, size_Of_Cluster;

  //Initialize MPI communicator
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &size_Of_Cluster);
  MPI_Comm_rank(MPI_COMM_WORLD, &process_Rank);

  //Open the MPI file
  MPI_File_open(MPI_COMM_WORLD, argv[1], MPI_MODE_WRONLY | MPI_MODE_CREATE, MPI_INFO_NULL, &outputFile);

  //Initialize Nonshared Variables
  char string_buff [30];

  //=======================File Write=========================

  //Write 1 to 60 to a file from every thread
  for(int i = 1; i <= 60; i++){

    //Create sting and write it to a nonshared buffer
    snprintf(string_buff, 30, "Counting: %d from process %d\n", i, process_Rank);

    //Collect all threads and distribute the buffer to the file in order.
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_File_write_ordered(outputFile, string_buff, strlen(string_buff), MPI_CHAR, MPI_STATUS_IGNORE);

    sleep(1);
  }

  //======================Clean Up============================
  //Close the MPI file and close the MPI communicator
  MPI_File_close(&outputFile);
  MPI_Finalize();

  return 0;

}
