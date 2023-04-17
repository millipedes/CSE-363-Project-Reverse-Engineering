# :collision: CSE 363 Reverse Engineering Tools Project
This is the official repository for the CSE 363 project made by:
  - Matthew Lindeman
  - Luke Shankin
  - Nikki Sparacino
  - Cameron Savage

Which relates to reverse engineering and analysis of binaries in the following
languages:
  - C (Family)
  - Java
  - Python

The code bases are numbered `01-PUT_NUMBER_HERE_LATER_ME_OR_SOMEONE_ELSE` and
can be found in their respective sub directories in this project.

The scripts used to automate this analysis can be found under the `scripts`
directory.

Finally, the report can be found in the `report` directory.

# :hammer: Building (15-30mins)
You will require the following packages:
  - radare2
  - pkg-config
  - xxHash
  - file
  - zlib
  - libzip
And the following python package:
  - pyclip

For distros with an apt package manager (i.e. Debian Ubuntu etc.):
```
sudo apt update && sudo apt upgrade
sudo apt install file zlib1g-dev xxhash libzip-dev
sudo snap install radare2 --classic
pip install pyclip
```
Now that we have all of the dependencies, we can finally get to working with the
decompiled functions:
```
r2
```
This should bring you to a command prompt where you can:
```
r2pm -ci r2ghidra
```
This step will take a while as `radare2` is downloading and compiling the C++
code for `ghidra` and integrating it into the `radare2` environment. This is
essential for being able to automate the process.

# :running: Using Scripts to Generate Report

# :page_facing_up: References
The following git code repositories were used in the analysis of this project:
  - [Luke Shankin's "Projects"](https://github.com/lukeshankin/Projects)
  - [Matthew Lindeman's "Erdos Renyi Graph Visualiztion"](https://github.com/millipedes/Erdos-Renyi-Visualization)
  - [Matthew Lindeman's "C Netpbm Graph Generator (With Context Free Grammar)"](https://github.com/millipedes/C-Netpbm-Function-Grapher)
