# Documentation for language C-=-1, version 0.1.X

This language has been designed as an experiment in metaprogramming mechanisms in low level programming languages.
The core principles behind C-=-1 are:

- Make all code executable at compile-time and move as mutch of the computation away from run-time as possible.
- Make the language as expressive and robust as possible
  - Support compile-time reflection.
  - Support self-modyfying code.
  - Make writing custom code analisys tools as easy as possible.


## Language versioning

C-=-1 language version numbering roughly follows [Semantic Versioning](https://semver.org/).
Language version is expressed as `Major.Minor.Patch` (ex: `1.2.3`), where `Patch` is reserved for reference compiler build number.
Third party compilers (should one ever be created for whatever reason) should list their language standard compilance as `Major.Minor.X` (ex: `1.2.X`).

## Language

[Basic concepts](Language/BasicConcepts.md)

[Compilation](Language/Compilation.md)

[Attributes](Language/Attributes)

## Semantic model

[Functions](Semantic-Model/Functions.md)

[Semantic model libraray](Semantic-Model/Library.md)

## Compiler backend

[Backend entry point](Compiler-Backend/BackendEntryPoint.d)
