# Semantic model library

### IVariable

```
public interface IVariable
{
 public fn name() -> string;
 public fn type() -> typeDescriptor*;
 public fn attributes() -> IAttributeInstance*[];
}
```

## Expressions

### IExpression

```
public interface IExpression
{
 public fn pointerToSourceCode() -> pointerToSourceCode;
 public fn parentExpression() -> IStatement*;
 public fn type() -> typeDescriptor*;
}
```

## Statements

### IStatement

```
public interface IStatement
{
 public fn pointerToSourceCode() -> pointerToSourceCode;
 public fn parentStatement() -> IStatement*;
 public fn function() -> functionDescriptor*;
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
 public fn expression() -> IExpression*;
 public fn ifBranch() -> IStatement*[];
 public fn elseBranch() -> IStatement*[];
}
```

### IFunctionCall

```
public interface IFunctionCall : IStatement, IExpression
{
 public fn parameters() -> IExpression*[];
 public fn function() -> functionDescriptor*;
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
 public fn values() -> enumValueDescriptor*[];
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
 public fn returnType() -> typeDescriptor*;
 public fn parameters() -> parameterDescriptor[];
}
```

## typeDescriptor

```
public class typeDescriptor
{
 public fn classifier() -> typeClassifier ;
 public fn name() -> string;
 public fn implementedInterfaces() -> typeDescriptor*[];
 public fn fields() -> fieldDescriptor*[];
 public fn functions() -> functionDescriptor*[]
}
```

## typeClassifier

```
public enum typeClassifier {class, interface};
```