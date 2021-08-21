# Backend entry point

To translate the semantic model into machine code, the compiler invokes the backend-interface library.
User may specify a package to be used as the interface with the ``compiler-interface`` CLI option.
Otherwise the default backend-interface will be used.

## `compilerEntryPoint` Attribute

To create a backend-interface package, the user must mark one of the free functions within that package with `compilerEntryPoint` attribute.

- If no such function exists, the compiler will raise an error.
- If more than one function has such markings, the behaviour is undefined.
- Methods marked with `compilerEntryPoint` are ignored.
- If the function marked with `compilerEntryPoint` is not public the compiler will raise an error.
- If the function marked with `compilerEntryPoint` has incorrect signature, the behaviour is undefined.
- If the function marked with `compilerEntryPoint` is not compile-time executable, the compiler will rise an error.

Entry point function must have the following signature:

```cm1

import {compilerEntryPoint packageDescriptor } from {cm1mLang::compiler}
import {compilationResult} from {cm1mLang::compiler::backend}

[compilerEntryPoint()]
public fn <function name> (
  packages: packageDescriptor[],
  result: compilationResult
) { <function body> }

```

- `packages` argument contains a collection of packages to be compiled into llvm-ir. The packages are passed in an unspecified order.
- `result` argument contains the `compilationResult` associated with the current compilation (see [`compilationResult` type](BackendEntryPoint#compilationresult-type))

## `compilationResult` type

The `compilationResult` type allows the user to interact with LLVM compiler backend.
This object allows the user to  manipulate LLVM data structures and gaining access to built-in types.
`compilationResult` may also be used to set linker and compiler flags and specifying external linkage.

The goal of a backend-interface package is to populate `compilationResult` with LLVM data structures and to set the appropriate linker flags.
