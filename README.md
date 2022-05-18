# Pipesim

A simulator for a 5-stage (classical RISC) pipeline, with or without forwarding.  See lab1_printout.pdf for example execution.

First, build the project by calling `make` at the command line.
To run the script, ensure you have permissions to execute it, and type `./run.sh` at the command line.

For each test, instructions are printed, followed by a simulation of the pipeline stages, with bubbles shown with asterisks, as:

```
Starting...
Forwarding is <disabled/enabled with window size set to <window_size>>.
Loading application...<file name>
Printing Application:
<instructions>
Initializing pipeline...
Cycle      IF           ID          EXEC         MEM           WB
<pipeline states for each cycle>
Completed in <num_cycles_required> cycles.
```
