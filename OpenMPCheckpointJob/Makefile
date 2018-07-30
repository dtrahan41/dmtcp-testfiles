.PHONY: clean

openmpCkptJob.exe: openmpCkptJob.c
	@echo "Compiling openmpCkptJob.exe"
	g++ openmpCkptJob.c -o openmpCkptJob.exe -fopenmp

clean:
	rm -f *.o
	rm -f *.out
	rm -f openmpCkptJob.exe
