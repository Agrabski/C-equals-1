[basic concepts](Language\BasicConcepts.md)

# Compilation process

Parse code -> Build IR for attributes -> Collect function and type definitions -> Attach attributes -> Build IR for functions and types -> Execute special attribute functions -> Remove reflection and metaprogramming operations -> Save assembly IR -> (optional) convert to LLVM IR and compile to machine code

# Intermediate representation

C-=-1 code is handled by the compiler and distributed as an intermediate representation. During the _Execute special attribute functions_ step, it is exposed to user code as a modifiable data structure.

### IVariable

```
public interface IVariable
{
 public fn name() -> string;
 public fn type() -> typeDescriptor&;
 public fn attributes() -> IAttributeInstance&[];
}
```

## Expressions

### IExpression

```
public interface IExpression
{
 public fn pointerToSourceCode() -> pointerToSourceCode;
 public fn parentExpression() -> IStatement&;
 public fn type() -> typeDescriptor&;
}
```

## Statements

### IStatement

```
public interface IStatement
{
 public fn pointerToSourceCode() -> pointerToSourceCode;
 public fn parentStatement() -> IStatement&;
 public fn function() -> functionDescriptor&;
}
```

Base interface for all statements.

### IVariableDeclarationStatement

```
public interface IVariableDeclarationStatement : IStatement
{
 public fn variable() -> IVariable;
 public fn initialValue() -> IExpression;
}
```

### IIfStatement

```
public interface IIfStatement : IStatement
{
 public fn expression() -> IExpression&;
 public fn ifBranch() -> IStatement&[];
 public fn elseBranch() -> IStatement&[];
}
```

### IFunctionCall

```
public interface IFunctionCall : IStatement, IExpression
{
 public fn parameters() -> IExpression&[];
 public fn function() -> functionDescriptor&;
 public fn isInExpressionContext() -> bool;
 public fn isDynamicDispatch() -> bool
}
```

# Metatypes

## enumDescriptor

```
public class enumDescriptor
{
 public fn name() -> string;
 public fn values() -> enumValueDescriptor&[];
}
```

## enumValueDescriptor

```
public class enumValueDescriptor
{
 public name: string;
 public value: usize;
}
```

## functionDescriptor

```
public class functionDescriptor
{
 public fn name() -> string;
 public fn returnType() -> typeDescriptor&;
 public fn parameters() -> parameterDescriptor[];
}
```

## typeDescriptor

```
public class typeDescriptor
{
 public fn classifier() -> typeClassifier ;
 public fn name() -> string;
 public fn implementedInterfaces() -> typeDescriptor&[];
 public fn fields() -> fieldDescriptor&[];
 public fn functions() -> functionDescriptor&[]
}
```

## typeClassifier

```
public enum typeClassifier {class, interface};
```

# Attribute special functions

Attribute special functions are invoked during the compilation process to validate and generate extra code. They may only use types and functions from assemblies listed as dependencies and the order in which functions are invoked when multiple attributes are attached to an element is undefined. These functions operate on intermediate representation before metaprogramming operations have been inlined.

## attach

Applicable targets: function, type, variable, enum.

```
fn attach(t: typeDescriptor&);
fn attach(f: functionDescriptor&);
fn attach(v: variableDescriptor&);
fn attach(e: enumDescriptor&);
```

This function is executed after all type and function definitions have been collected and before their intermediate representations have been built. Parameters of object the attribute is attached to, that influence function overloading, can only be changed during ``attach`` function execution

## onCall

Applicable targets: function

```
fn onCall(f: functionDescriptor&, call: IFunctionCall&);
```

Called whenever a function that the attribute is attached to is invoked in the source code.
Example:

```
public att<function> noDiscard
{
 public fn onCall(f: functionDescriptor&, call: IFunctionCall&)
 {
  if (!call.isInExpressionContext())
   raiseError(call.pointerToSource(), "Value of function marked no discard is not used", 32540);
 }
}

fn someFunction() -> usize{}
[noDiscard()]
fn someNoDiscardFunction -> usize{}

public fn main()
{
 someFunction(); // ok
 let x = someFunction(); // ok
 someNoDiscardFunction(); // error! message: 'Value of function marked no discard is not used" error code: 32540
 let y = someNoDiscardFunction(); // ok
 let z = 1 + someNoDiscardFunction(); // ok
}
```
