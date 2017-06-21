SCHEDULING SIMULATOR
====================
Scheduling simulator is a Advanced Operating System assignment which requires to implement a simulator of different 
scheduling algorithm. 

Current supported scheduler:
 - Short job first.
 - Round Robin.
 - Rate monotonic.
 - Earliest deadline first.
 - Lottery scheduling.

## How to build it?
### Dependencies
#### For developers
- Autotools suite.
- Python2.7 with yaml module (For integration tests).

#### For users
- UNIX plataform.
- C++ compiler with c++14 support.

### Building it
The project uses Autotools. Thus, the building steps are the common three steps to build:
```
#Download the tar ball from Github.
wget https://github.com/vicentebolea/scheduling-simulator/archive/v0.0.2.tar.gz

#untar
tar xf scheduling-simulator-0.0.2.tar.gz

# configure the project
cd scheduler..
./configure --prefix `pwd`/build

# Optional, check the unit tests
make check

# Compile and install it
make install

```
## How to run it?
The binary called `scheduler_sim` will be installed in the `prefix/bin` folder.
Here are the different options that `scheduler_sim` supports:

```
simulator_sim -s SCHEDULER [OPS] -i FILE
    -s SCHEDULER: SJF,RR,RM,EDF,LT
    -i FILE:      If file is -, it will read the input from stdin
    [OPS]: 
      -q #:         Quantum (For RR and LT).
      -e #:         Ending time (For RM and EDF).
      -f:           For LT to use most probable proccess.
```

## CONTRIBUTION
- [License](LICENSE)
- [Authors](AUTHORS.md)
- [Contribute](CONTRIBUTING.md)
