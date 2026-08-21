# Local Development for HPC Deployment

Supporting code for a tutorial on developing code locally and deploying it on the University of Delaware's DARWIN cluster.

The code is a simple root finder written in C. Compilation is handled through a Makefile and unit tests are included so that portable compilation and testing can be demonstrated as part of the tutorial.

There are two TODOs to implement in `root_finding_funcs.c` so that the driver code `root_finder.c` computes a meaningful result.

## Creating a repository based on this repository

This repository is a "template repository". This means you can create your own repository based on this one, with the freedom to choose a new name and whichever visibility you prefer (public or private). Refer to GitHub's documentation on [creating a repository from a template](https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-repository-from-a-template) for instructions on how to do this.

Once you have created your own repository based on this template, you should clone your repository on your local machine and on DARWIN.

## Software dependencies on your local machine

Your local machine will need to have a C compiler, GNU Make, and Git installed so that you can follow the tutorial. Guidance is provided below for installing these depenencies on some common operating systems, although this is not an exhaustive list.

### Ubuntu Linux or Windows Subsystem for Linux (WSL)

**Make sure you have administrator/root access to the machine where you want to install these dependencies. Otherwise, the command provided below will not work.**

Git should be available by default. You can install a C compiler and GNU Make by running:

```bash
sudo apt install build-essential
```

## macOS

All dependencies can be installed by running:

```zsh
xcode-select --install
```

## Compiling on your local machine

There are four Make targets:
  - `root_finder` compiles the driver code which finds the root of a given function.
  - `tests` compiles the unit tests.
  - `run_tests` compiles and runs the unit tests (or just runs them if they have already been compiled).
  - `clean` removes the executables for the driver code and tests.

For example, starting from a clean working directory, running

```sh
make run_tests
```

will compile and run the tests.

## Compiling on DARWIN

On DARWIN, you will need to load a recent GCC compiler before running any Make commands. For example:

```sh
vpkg_devrequire gcc/14.2
```

Once you have done so, compilation works the same as on your local machine.