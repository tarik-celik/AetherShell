# AetherShell

A minimal unix-like shell
that is independent as possible.

# Features

* Clearing the screen (clear)
* Change directory (cd <dirname>)
* Remove a file (rm <filename>)
* Remove a directory (rmdir <dirname>)
* Create a file (touch <filename>)
* Create a directory (mkdir <dirname>)
* Execute external commands (exec <name>)

# Installation

> cd ~
> git clone github.com/tarik-celik/AetherShell
> cd AetherShell
> clang/gcc AetherShell.c -o aesh
> chmod +x aesh
> mv aesh /usr/bin/aesh
> aesh
