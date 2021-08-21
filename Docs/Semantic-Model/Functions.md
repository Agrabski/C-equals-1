# Functions

## Function categories

In C-=-1, functions and methods may fall into one of several overlapping categories.
Category membership affects overload resolution (see [Overload Resolution](Functions#Overload-resolution)).

### Compile-time executable

A compile-time executable function may be invoked in the interpreted context (see [execution context](../Language/BasicConcepts#Execution-context)). Function is within this category if:

- Has no arguments of compile-time excluded types.
- Was not marked as excluded from compile-time by the user.

A function is in an invalid state if:

- Claims to be compile-time executable
  - and contains a call to a function that has no applicable, compile-time executable overload.

### Run-time executable

A compile-time executable function may be invoked in the compiled context (see [execution context](../Language/BasicConcepts#Execution-context)). Function is within this category if:

- Has no arguments of run-time excluded types.
- Was not marked as excluded from run-time by the user.

A function is in an invalid state if:

- Claims to be run-time executable
  - and contains a call to a function that has no applicable, run-time executable overload.

### Abstract

Within C-=-1 only `interface` methods may be abstract and all `interface` methods are abstract.
Abstract methods canot have a body and must be implemented in classes that implement the interface.

### Virtual

## Overload resolution

Each function call instruction in C-=-1 may invoke two different functions, depending on the execution context (see [execution context](../Language/BasicConcepts#Execution-context)).
Therefore, the overload resolution process produces up to two function for a given call: one for the run-time context and one for the compile-time context.
These functions may or may not be the same.

Overload resolution process must always find __at most__ one overload for a given context.
Therefore the code:

```cm1

fn f(a: usize) {}

[excludeAtRuntime()]
fn f(a: usize) {}
```

Is invalid as the function `f` has two identical overloads in compile-time context.
Programs that contain a functions for which overload resolution is not unique are invalid.

__Compilers of this language revision are not required to detect this error__.
Compilation may not be interrupted and no diagnostic may be provided.

## Invalid state

A function may be in an invalid state, due to not strict enough restrictions beeing applied or any other difficult to imidieatly diagnose problem.

## Abstract method invocation

