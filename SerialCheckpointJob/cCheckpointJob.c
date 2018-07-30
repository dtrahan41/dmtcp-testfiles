#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>

int main(int argc, char* argv[]){

	FILE* sampleFile;
	char string_buff [20];

	sampleFile = fopen(argv[1], "w+");

	for(int i = 1; i <= 60; i++){

		snprintf(string_buff, 20, "Counting: %d\n", i);
		fputs(string_buff, sampleFile);

		sleep(1);
	}

	fclose(sampleFile);

	return 0;

}
