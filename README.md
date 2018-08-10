# DMTCP Test Programs and Scripts

## Installation
Installing DMTCP on Summit:
Automatic installation can be preformed using the included `install.sh` script.

Simply run ./install.sh to install dmtcp in your local projects directory.

### Manual installation instructions

1. Begin by downloading the stable release of DMTCP from their source forge:
        `wget https://sourceforge.net/projects/dmtcp/files/2.5.2/dmtcp-2.5.2.tar.gz`
2. In your projects directory, create a folder named "demo-Install":
        `mkdir demo-Install`
3. Move the dmtcp tarball into the directory:
        `mv dmtcp-2.5.2.tar.gz demo-Install`
4. CD into the demo-Install file:
        `cd demo-Install`
5. Unpack the tarball into the directory:
        `tar -xvzf dmtcp-2.5.2.tar.gz`
6. Load gcc:
        `ml gcc`
7. CD into the dmtcp-2.5.2's directory:
        `cd dmtcp-2.5.2`
8. Run the configure script as such:
        `./configure --prefix /projects/$USER/demo-Install/dmtcp`
9. Run the `make` command:
        `make`
10. Run the `make install` command:
        `make install`

## Running Test Scripts
To run the included scripts, ensure you have properly installed DMTCP locally.
1. Download the scripts.
2. Enter into the directory containing the script you would like to run.
3. If running a C program, run `make` to compile the C code.
4. Submit the job script with `sbatch <desired-test-script>`
5. Job will take approximately 1 minute and 30 seconds, results will be stored in a `results.<job-id>.out` file.

Notes:

MPI Test is currently not working because DMTCP does not support Omnipath connectors. Support for Omnipath is expected to come end of year.
