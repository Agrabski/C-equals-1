grammar CMinusEqualsMinus1Revision0;

compilationUnit
    : EOF
    | languageStandardDeclaration declarationSequence
    | declarationSequence
    ;

declarationSequence
    : declaration declarationSequence
    | declaration
    ;

declaration
    : classOrInterfaceDeclaration
    | functionDeclaration
    ;

classOrInterfaceDeclaration
    : attributeSequence (class | interface) identifier classBody
    ;

functionDeclaration
    : attributeSequence accessibility virtuality? qualifiedTypeName identifier PARAMOPEN argumentSequence PARAMCLOSE semiColon
    | attributeSequence accessibility virtuality? qualifiedTypeName identifier PARAMOPEN argumentSequence PARAMCLOSE functionBody
    ;

functionBody
    : expressionBlock
    | defaultSpecification
    ;


attributeSequence
    : attributeUse attributeSequence
    | attributeUse
    |
    ;

qualifiedTypeName 
    : identifier doubleColon qualifiedTypeName
    | identifier
    ;

attributeUse
    : ATTROBITEOPEN identifier ATTROBITECLOSE;

languageStandardDeclaration
    : 'language standard' equals standardNumber semiColon;

standardNumber : integerLiteral;

identifier : LETTER (DIGIT|LETTER)*;

invocation : identifier PARAMOPEN argumentUseSequence PARAMCLOSE;

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
    | classLiteral
    | characterLiteral
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
    : virtual
    | final
    | abstract
    | override
    ;
    

stringLiteral : DOUBLEQUOTE RAWSTRING DOUBLEQUOTE;

floatingPointLiteral : numericLiteral comma numericLiteral;

expressionBlock : OPENBRACKET expressionSequence CLOSEBRACKET;


doubleColon : '::';
semiColon : ';';
comma : ',';
period : '.';
equals : '==';
asssigment : '=';
notEquals : '!=';
class : 'class';
interface : 'interface';
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

fragment OPENBRACKET : '{';
fragment CLOSEBRACKET : '}';
fragment RAWSTRING : '"' .*? '(' .*? ')' .*? '"';
fragment DOUBLEQUOTE : '"';
fragment SINGLEQUOTE : '\'';
fragment PARAMOPEN : '(';
fragment PARAMCLOSE : ')';
fragment DIGIT : [0-9];
fragment LETTER : [a-zA-Z];
fragment ATTROBITEOPEN : '[';
fragment ATTROBITECLOSE : ']';
