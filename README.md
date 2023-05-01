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

The code bases are numbered `01-05` and
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
  - xclip
And the following python package:
  - pyclip

For distros with an apt package manager (i.e. Debian Ubuntu etc.):
```
sudo apt update && sudo apt upgrade
sudo apt install file zlib1g-dev xxhash libzip-dev xclip
pip install pyclip
```

Okay so unfortunately apt doesn't support `radare2` which has too many
advantages to pass up, so we will need to execute:
```
cd ~/Documents/
git clone https://github.com/radareorg/radare2
cd radare2/
./sys/install.sh
```
This may take a while, but it is downloading and compiling `radare2`.

Note here that there is a `nix/` directory, this is a `nix-shell` script that
will install the `xxHash`, `file`, `zlib`, and `libzip` dependencies in the
current shell session for NixOS users.

Now that we have all of the dependencies, we can finally get to working with the
decompiled functions:
```
r2 some_binary
```
(Where some_binary is any binary, it just needs one as a command line arg or it
will not start) This should bring you to a command prompt where you can:
```
r2pm -ci r2ghidra
```
This step will take a while as `radare2` is downloading and compiling the C++
code for `ghidra` and integrating it into the `radare2` environment. This is
essential for being able to automate the process.

# :running: Using Scripts to Generate Report (15 mins / analysis)
For this section, I think that it will be best for me to walk through the first
example.

First we go to the project we wish to analyze (I will walk through
`01_heaps_algorithm`) and then make the project. So:
```
cd 01_heaps_algorithm
make
```
This will make the binary that we will analyze (please note that if you are
building java projects you will need to replace this binary `ordering` with the
main `.class` file and if you are compiling python projects you will need to
replace this binary with the main `.pyc` file). Next we need to get the input
to the `radare2` function. There is a neat script that we have that automates
much of this process.

The most sensible way to do this is to make a file with the names of functions
that we would like to analyze separated by a newline. Hence, in this example I
made a file called `interesting_funcs.txt`:
```
main
swap
printarr
fact
```
Note that this is all of the functions in this project, but for larger programs
we might not want to analyze _all_ of the functions. So now our script will
translate these functions to the proper input to `radare2`:
```
python ../scripts/r2inputs.py -f interesting_funcs.txt
```
This will produce a file called `interesting_funcs.out`. Next we have a script
to feed these inputs to `radare2`:
```
../scripts/feedr2.sh ordering interesting_funcs.out
```
This will open up r2 and analyze all interesting functions which you have
specified. Next:
```
[some_hex_number]> q
```
Now we will open up a text file (in this example called
`func_code.txt` and copy the functions which were output from r2. I did this and
you can verify it in `01_heaps_algorithm/func_code.txt`.

And now for the final step! Execute this script:
```
python ../scripts/to_tex.py -f func_code.txt
```
And this will put a latex formatted version of the code onto you clipboard. From
here edit the report by pasting your code and writing about your results.

# :scroll: Note on Commiting
Do not commit any binaries (i.e. compiled C programs, `.class` files, or `.pyc`
files).

# :page_facing_up: References
Thanks to all of the FOSS developers, as you can see from the dependencies, we
are using lots of packages.

The following git code repositories were used in the analysis of this project:
  - [Luke Shankin's "Projects"](https://github.com/lukeshankin/Projects)
  - [Matthew Lindeman's "Erdos Renyi Graph Visualiztion"](https://github.com/millipedes/Erdos-Renyi-Visualization)
  - [Matthew Lindeman's "C Netpbm Graph Generator (With Context Free Grammar)"](https://github.com/millipedes/C-Netpbm-Function-Grapher)

The following scripts were used from git repos:
  - [Matthew Lindeman's "Code to Latex Format"](https://github.com/millipedes/Code-to-Latex)
