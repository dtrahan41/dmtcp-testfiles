#!/bin/bash

#SBATCH --nodes=1
#SBATCH --ntasks=2
#SBATCH --partition=shas
#SBATCH --qos=debug
#SBATCH --job-name=ckptDemo
#SBATCH --time=00:03:00
#SBATCH --output=results.%j.out

# Reset and load modules

ml purge

ml gcc
ml python

# -------------------------------------------------------------------------
# Setup
# -------------------------------------------------------------------------

echo "=== Setting Up Tester Files ==="

export OMP_NUM_THREADS=2

touch key.out
touch integrity.out

./openmpCkptJob.exe key.out &

# -------------------------------------------------------------------------
# Checkpoint Test
# -------------------------------------------------------------------------

echo "=== Starting DMTCP Daemon ==="

/projects/$USER/demo-Install/dmtcp/bin/dmtcp_coordinator --daemon --exit-after-ckpt

echo "=== Running Python Script ==="
/projects/$USER/demo-Install/dmtcp/bin/dmtcp_launch ./openmpCkptJob.exe integrity.out &

echo "    Sleeping for 35 Seconds..."
sleep 35

echo "=== Checkpoint and Kill ==="
echo "    Creating Checkpoint..."
/projects/$USER/demo-Install/dmtcp/bin/dmtcp_command --checkpoint

echo "    Process Killed. Sleeping for 15 Seconds..."
sleep 15

echo "=== Restart ==="
echo "    Restarting..."
./dmtcp_restart_script.sh  

# -------------------------------------------------------------------------
# Validating Test
# -------------------------------------------------------------------------

echo "=== Validating ==="
echo "    Checking Diff..."

diff -s key.out integrity.out

echo "=== Clean Up ==="

rm *.dmtcp
rm dmtcp*
