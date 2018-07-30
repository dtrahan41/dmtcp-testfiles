# DMTCP Test Programs and Scripts

## Installation
Installing DMTCP on Summit:

1. Begin by downloading the stable release of DMTCP from their source forge: https://sourceforge.net/projects/dmtcp/files/2.5.2/dmtcp-2.5.2.tar.gz/download
2. In your projects directory, create a folder named “demo-Install”: `mkdir demo-Install`
3. Move the dmtcp tarball into the directory with Globus or SCP/SFTP
4. CD into the demo-Install file: `cd demo-Install`
5. Unpack the tarball into the directory: `tar -xvzf dmtcp-2.5.2.tar.gz`
6. Load gcc: `ml gcc`
7. CD into the dmtcp-2.5.2’s directory: `cd dmtcp-2.5.2`
8. Run the configure script as such: 
```./configure --prefix /projects/$USER/demo-Install/dmtcp```
9. Run the `make` command: make
10. Run the `make install` command: make install

## Running Test Scripts
To run the included scripts, ensure you have properly installed DMTCP locally.
- Download the scripts.
- Enter into the directory comtaining the script you would like to run.
- If running a C program, run `make` to compile the C code.
- Submit the job script with `sbatch <desired-test-script>`
- Job will take approximately 1 minute and 30 seconds, results will be stored in a `results.<job-id>.out` file.

Notes: 
