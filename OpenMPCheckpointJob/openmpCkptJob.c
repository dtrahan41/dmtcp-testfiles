#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
#include <omp.h>

int main(int argc, char* argv[]){

	int i, thread_id, thread_count;
	char string_buff [30];

	FILE* outputFile;
	outputFile = fopen(argv[1], "w+");

	#pragma omp parallel private(string_buff, thread_id)
	{
		thread_id = omp_get_thread_num();
		thread_count = omp_get_num_threads();

		for(int i = 1; i <= 60; i++){
			for(int j = 0; j <= thread_count; j++){
				if(j == thread_id){
					snprintf(string_buff, 30, "Counting: %d from process %d\n", i, thread_id);

					fputs(string_buff, outputFile);
				}
				#pragma omp barrier
			}

			sleep(1);
		}
	}

	fclose(outputFile);

	return 0;

}
