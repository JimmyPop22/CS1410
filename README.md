# A C++ project with a dev container

This repository is a C++ workspace supported by a cross-platform Docker-based dev container. The header (`.h`) files should be placed under the `include/` folder, while the implementation (`.cpp`) files should be placed under the `src/` folder.

## Requirements

This repository requires the following one-time setup:

- Install the [Docker desktop application](https://www.docker.com/products/docker-desktop/). You don't need to do anything with Docker other than installing it on your operating system.
- Install [Visual Studio Code](https://code.visualstudio.com).
- Open Visual Studio Code and install the Dev Containers extension.

Having done that, download or clone this repository into your local machine and open its folder in Visual Studio Code. If you see a popup with an option to "Reopen in Container," click that. Otherwise, click on the Dev Containers icon at the bottom left corner and select "Reopen in Container." You can also type F1 to launch VSCode's Command Palette and search for and select "Dev Containers: Reopen in Container." This will reopen this repository in the dev container where all development environment tools (compiler, linker, debugger, etc.) are available.

## Building the project
Inside the dev container, go to the build folder:

```
cd build
```

And if this is your first time running this repository, run the command to set up the project:

```
cmake ..
```

## Compiling and running the program
Using the terminal, make sure you are inside the `build/` folder. Adjust and run the command:


```
cd build
```

if you need to. Then, run the following command to compile the program(s) of this repository:

```
make 
```

To run a compiled program, use its name. For example, if you have a program named `main`, you can run it like this:

```
./main
```

## Debugging programs
To debug a program, open its source code in Visual Studio Code, set breakpoints at appropriate locations, and use Visual Studio Code's Run and Debug interface to initiate debugging.