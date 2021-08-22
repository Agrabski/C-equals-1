
# Attribute special functions

Attribute special functions are invoked during the compilation process to validate and generate extra code. They may only use types and functions from assemblies listed as dependencies and the order in which functions are invoked when multiple attributes are attached to an element is undefined. These functions operate on intermediate representation after metaprogramming operations have been inlined.

## `attach`

Applicable targets: function, type, variable, enum.

```
fn attach(t: typeDescriptor*);
fn attach(f: functionDescriptor*);
fn attach(v: variableDescriptor*);
fn attach(e: enumDescriptor*);
```

This function is executed after all type and function definitions have been collected and before their intermediate representations have been built.
Any object metadata manipulation that affects overload resolution must be done within this function.

## `onCall`

Applicable targets: function

```
fn onCall(f: functionDescriptor*, call: IFunctionCall*);
```

Called whenever a function that the attribute is attached to is invoked in the source code.
Example:

```
public att<function> noDiscard
{
 public fn onCall(f: functionDescriptor*, call: IFunctionCall*)
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
