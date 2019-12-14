grammar CMinusEqualsMinus1Revision0;

compilationUnit
    : languageStandardDeclaration declarationSequence EOF
    | declarationSequence
    ;


OpenBracket : '{';
CloseBracket : '}';
RAWSTRING : '"' .*? '(' .*? ')' .*? '"';
DOUBLEQUOTE : '"';
SINGLEQUOTE : '\'';
ParamOpen : '(';
PARAMCLOSE : ')';
ATTROBITEOPEN : '[';
ATTROBITECLOSE : ']';

declarationSequence
    : declaration declarationSequence
    | declaration
    ;

declaration
    : classOrInterfaceDeclaration
    | functionDeclaration
    ;

classOrInterfaceDeclaration
    : attributeSequence Class identifier classBody
    | attributeSequence Interface identifier classBody
    | Class identifier
    ;

classBody
    : OpenBracket memberDeclarationSequence CloseBracket
    ;

memberDeclarationSequence
    : memberDeclaration memberDeclarationSequence?
    |
    ;

memberDeclaration
    : functionDeclaration
    | memberVariableDeclaration
    ;

memberVariableDeclaration
    : accessibility? qualifiedTypeName reference? identifier semiColon
    | accessibility? qualifiedTypeName reference? identifier asssigment expression semiColon
    ;

expression
    : identifier
    | literal
    | expression binaryOperator expression
    //| unaryOperator expression		TODO
    ;

functionDeclaration
    : attributeSequence accessibility virtuality? qualifiedTypeName identifier ParamOpen argumentSequence PARAMCLOSE semiColon
    | attributeSequence accessibility virtuality? qualifiedTypeName identifier ParamOpen argumentSequence PARAMCLOSE functionBody
    ;

functionBody
    : statementBlock
    | defaultSpecification
    ;


attributeSequence
    : 
    | attributeUse attributeSequence
    | attributeUse
    ;

qualifiedTypeName 
    : identifier doubleColon qualifiedTypeName
    | identifier
    ;

attributeUse
    : ATTROBITEOPEN identifier ATTROBITECLOSE;

languageStandardDeclaration
    : 'language standard' asssigment standardNumber semiColon;

standardNumber : integerLiteral;

identifier : LETTER (DIGIT|LETTER)*;

invocation : identifier ParamOpen argumentUseSequence PARAMCLOSE;

argumentSequence 
    : qualifiedTypeName identifier comma argumentSequence 
    | qualifiedTypeName comma argumentSequence
    | qualifiedTypeName
    | qualifiedTypeName identifier
    ;

argumentUseSequence
    : identifierOrLiteral comma argumentSequence
    | identifierOrLiteral
    ;

identifierOrLiteral
    : identifier
    | literal
    ;

literal
    : numericLiteral
    | stringLiteral
    //| classLiteral		TODO
    //| characterLiteral	TODO
    ;

numericLiteral
    : integerLiteral
    | floatingPointLiteral
    ;

accessibility
    : Public
    | Private
    | Protected
    | Internal;

virtuality
    : Virtual
    | Final
    | Abstract
    | Override
    ;
    

stringLiteral : DOUBLEQUOTE RAWSTRING DOUBLEQUOTE;

floatingPointLiteral : integerLiteral comma integerLiteral;

statementBlock : OpenBracket statementSequence CloseBracket;

statementSequence : statement statementSequence?;

statement 
	: statementBlock
	| invocation
	| variableDeclaration
	;

variableDeclaration : qualifiedTypeName reference? identifier asssigment expression;


binaryOperator
    : plus
    | minus
    | star
    | or
    | and
    | xor
    ;

reference
    : nullable? strong? mutable? ref;

doubleColon : '::';
semiColon : ';';
comma : ',';
period : '.';
equals : '==';
asssigment : '=';
notEquals : '!=';
plus : '+';
minus : '-';
star : '*';
or : '||';
and : '&&';
xor : '^^';
strong : '!';
nullable : '?';
mutable : '?';
ref : '&';
Class : 'class';
Interface : 'interface';
Public : 'public';
Private : 'private';
Protected : 'protected';
Internal : 'internal';
Final : 'final';
Virtual : 'virtual';
Abstract : 'abstract';
Override : 'override';
defaultSpecification : '=' 'default';


integerLiteral : (DIGIT)*;

DIGIT
   : [0-9]
   ;

LETTER : [a-zA-Z];