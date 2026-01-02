# Logbook CLI (C)


A simple command-line logbook written in C.

This project is a learning exercise focused on:
- basic C syntax
- structures
- file I/O
- user input handling
- simple program architecture (menu, functions)

## Features

- Add log entries from the terminal
- Each entry contains:
  - an auto-incremented ID
  - a title
  - a content text
- Entries are saved persistently in a text file
- Display all saved entries
- Simple interactive menu

## File format

Entries are stored in a plain text file (`logbook.txt`) using the following format: `ID|Title|Content`

Example :

`1|First test|My first log entry|`
`2|Second test|My second log entry|`

## Build

Compile with `gcc`:

```sh
gcc -Wall -Wextra -std=c11 main.c -o logbook
```
## Run

```sh
./logbook
```

## Notes

This project intentionally uses basic C standard library functions
(`scanf`, `fgets`, `sscanf`, `FILE*`) to better understand low-level behavior.

Input buffer handling is done manually to avoid common pitfalls with scanf.

## Possible improvements

* Parse and display entries in a formatted way

* Add dates to entries

* Edit or delete entries

* Improve input validation

* Split the project into multiple source files
