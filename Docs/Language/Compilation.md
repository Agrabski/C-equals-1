# Compilation process

Parse code -> Build IR for attributes -> Collect function and type definitions -> Attach attributes -> Build IR for functions and types -> Execute special attribute functions -> Remove reflection and metaprogramming operations -> Save assembly IR -> (optional) convert to LLVM IR and compile to machine code

# Intermediate representation

C-=-1 code is handled by the compiler and distributed as an intermediate representation. During the _Execute special attribute functions_ step, it is exposed to user code as a modifiable data structure.