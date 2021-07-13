# Basic concepts

In C-=-1 every element of the language except for namespaces is subject to access control, meaning they can be marked as public, private or internal. Public elements are visible everywhere, private are visible only within context of the parent element and internal elements are only visible within the assembly.

## Assembly

## Namespace

## Type

### Class

Classes in C-=-1 are directly analogous to C++. A class may have fields of any type, methods with any accessibility modifiers and constructors. Methods 

### Interface

Interfaces are Types that only contain function headers (with no bodies). Classes may implement an interface, which means that it must implement every method declared in the interface. Interfaces are declared with the `interface` keyword.
Interfaces can only be accessed via references and cannot be directly created. A reference to object of type that implements an interface is implicitly convertible to a reference to the interface.

## Variable

## Function

## Attribute

`attributeDeclaration : (AccessSpecifier)? 'att' '<'attributeTarget+ '>' Identifier OpenBracket classContentSequence CloseBracket;`

`attributeTarget: ('type' | 'variable' | 'function' | 'enum');`

Attributes are similar to types in their definition, they may contain fields and methods. Attributes are marked with the `att` keyword, followed by a list of targets in triangle brackets (`<>`), separated by spaces. If a attribute targets an element, it can be attached to that element. For example:

```
att<function> functionOnly {}

[functionOnly()]
fn function(){} // correct

[functionOnly()]
class Type{} // error! invalid target
```

Attributes are constructed the same way as types (`construct` special method). They also have several special methods used during compilation. These methods are discussed in [Attribute special functions](Attributes#attribute-special-functions).
