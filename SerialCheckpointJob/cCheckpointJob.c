/*
Program created by Daniel Trahan
Last Updated 31 July 2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>

int main(int argc, char* argv[]){

	//Initialize variables
	FILE* sampleFile;
	char string_buff [20];

	//Open file
	sampleFile = fopen(argv[1], "w+");

	//Count from 1 to 60, wait 1 second every increment
	for(int i = 1; i <= 60; i++){

		//Write to a string buffer and put the buffer into the opened file
		snprintf(string_buff, 20, "Counting: %d\n", i);
		fputs(string_buff, sampleFile);

		sleep(1);
	}

	//Close file
	fclose(sampleFile);

	return 0;

}
