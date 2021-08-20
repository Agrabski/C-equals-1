# Functions

## Function categories

In C-=-1, functions and metgods may fall into one of several overlapping categories.

### Compile-time executable

### Run-time executable

### Abstract

### Virtual

## Overload resolution

Each function call instruction in C-=-1 may invoke two different functions, depending on the execution context (see [execution context](../Language/BasicConcepts#Execution-context)).
Therefore, the overload resolution process produces up to two function for a given call: one for the run-time context and one for the compile-time context.
These functions may or may not be the same.