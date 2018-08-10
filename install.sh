#!/bin/bash

# Install script written by Andrew Monaghan
# Commented by Daniel Trahan
# Last updated: 8/10/2018

# Setup
cd /projects/$USER
mkdir demo-Install
cd demo-Install

# Download and extract dmtcp
wget https://sourceforge.net/projects/dmtcp/files/2.5.2/dmtcp-2.5.2.tar.gz
tar -xvzf dmtcp-2.5.2.tar.gz

# cd into directory, load gcc, and install
cd dmtcp-2.5.2
ml gcc
./configure --prefix /projects/$USER/demo-Install/dmtcp
make
make install
