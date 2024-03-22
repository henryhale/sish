# Simple Shell (sish)

## Overview

This is a basic implementation of a shell in C.
The shell allows users to execute commands and interact with the system.

## Why?

There exists several powerful shells (like [bash](https://www.gnu.org/software/bash/manual/), [fish](https://fishshell.com/), [zsh](https://github.com/ohmyzsh/ohmyzsh/wiki)) whose underlying
implementation details are somewhat complex. This tends to implement a basic
shell that is simple and easy to understand so as to provide a starting point
on learning how shells actually work.

## Usage

To getting started with `sish` make sure you have the  following installed on your system;

- `git`
- `gcc` - GNU Compiler Collection
- `make` - GNU Make utility

1. **Compilation**: Build from source

   To compile the program, run the following

   ```sh
   mkdir simple_shell
   cd simple_shell
   git clone https://github.com/henryhale/sish.git
   make
   ```

2. **(Optional) Global Installation**

   Make `sish` available on the system globally

   ```sh
   sudo cp ./build/sish /usr/local/bin
   ```

   Uninstall using:

   ```sh
   sudo rm /usr/local/bin/sish
   ```

3. **Execution**: Run the compiled executable

   If you installed the executable globally, run

   ```sh
   sish
   ```

   Otherwise, manually run the shell using

   ```sh
   cd build
   ./sish
   ```

   Now you should see the `sish` prompt like `[shell-1234] $ `. The number after the hyphen (-) corresponds to the process ID.

4. **Enjoy `sish`** 🚀

   Type out some commands. Use `exit` to exit the shell.

## Contributing
Contributions are welcome!
If you find any issues or have improvements, please [open an issue](https://github.com/henryhale/sish/issues) or create a pull request. 

## References
- [C Reference Manual](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html)
- [GNU Compiler Collection](https://gcc.gnu.org)
- [GNU Make utility](https://gnu.org/software/make/manual/html_node/index.html)

## License
This project is licensed under the [MIT License](./LICENSE.md)

Copyright &copy; 2024-present, [Henry Hale](https://github.com/henryhale)