.PHONY: clean

parallelCkptJob.exe: parallelCkptJob.c
	@echo "Compiling parallelCkptJob.exe"
	mpic++ parallelCkptJob.c -o parallelCkptJob.exe

clean:
	rm -f *.o
	rm -f parallelCkptJob.exe
	rm -f *.out
