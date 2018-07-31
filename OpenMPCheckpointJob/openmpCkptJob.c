/*
Program created by Daniel Trahan
Last Updated 31 July 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

int main(int argc, char* argv[]){

	//Variable Declaration
	int i, thread_id, thread_count;
	char string_buff [30];

	//Open file
	FILE* outputFile;
	outputFile = fopen(argv[1], "w+");

	//Parallel Region
	#pragma omp parallel private(string_buff, thread_id)
	{

		//Obtain Thread Information
		thread_id = omp_get_thread_num();
		thread_count = omp_get_num_threads();

		//Count from 1 to 60, wait 1 second every increment
		for(int i = 1; i <= 60; i++){
			for(int j = 0; j <= thread_count; j++){
				if(j == thread_id){

					//Write to a string buffer and put the buffer for each thread into the opened file
					snprintf(string_buff, 30, "Counting: %d from process %d\n", i, thread_id);
					fputs(string_buff, outputFile);
				}

				//Barrier to keep threads in order
				#pragma omp barrier
			}
			sleep(1);
		}
	}

	//Close file, end program
	fclose(outputFile);
	return 0;
}
