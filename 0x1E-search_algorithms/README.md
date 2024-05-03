# Search Algorithms Project

This repository contains the implementation of various search algorithms in C as part of a learning project. The goal is to demonstrate the usage and efficiency of different search techniques on arrays of integers.

## General Information

- All code files are compiled on Ubuntu 20.04 LTS using `gcc` with the options `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- Only the `printf` function is allowed for output.
- Each function's prototype is declared in the header file `search_algos.h`.
- The code adheres to the Betty coding style.

## Installation

To run the programs in this project, clone this repo and compile the source files using `gcc`. For example:

```bash
git clone https://github.com/amandamadlingozi/search-algorithms.git
cd search-algorithms
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 <file-names>.c -o <executable-name>
```

Replace `<file-names>` with the names of the files you want to compile, and `<executable-name>` with the name you want to give to the resulting executable.

## Usage

Each executable file corresponds to a different search algorithm. To run any of these executables, use:

```bash
./<executable-name>
```

### Included Algorithms

1. **Linear Search:**
   - File: `0-linear.c`
   - Function: `int linear_search(int *array, size_t size, int value);`
   - Description: Searches for a value in an array of integers using the linear search algorithm. Outputs each checked value and returns the first index where the value is found or `-1` if the value is not found.

## Contributions

This project is part of a larger course program and is not open for public contributions. However, feedback and suggestions are welcome via the issue tracker.

## Authors

- **Amanda Madlingozi** - _Initial work_ - [amandamadlingozi](https://github.com/amandamadlingozi)

```

