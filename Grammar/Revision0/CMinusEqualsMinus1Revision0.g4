grammar CMinusEqualsMinus1Revision0;

compilationUnit:
	languageStandardDeclaration declarationSequence EOF
	| declarationSequence;

languageStandardDeclaration:
	'standard' '=' IntegerLiteral SemiColon;

declarationSequence: declaration*;

declaration: functionDeclaration;
//| classDeclaration | interfaceDeclaration | structDeclaration | namespaceDeclaration;

namespaceDeclaration : 'namespace' qualifiedIdentifier OpenBracket declarationSequence CloseBracket;

functionDeclaration:
	attributeSequence? 'fn' Identifier ParamOpen parameterList ParamClose '->' qualifiedIdentifier
		functionBody;

parameterList:
	| qualifiedIdentifier Identifier
	| (qualifiedIdentifier Identifier ',')+ qualifiedIdentifier Identifier;

functionBody: OpenBracket statement* CloseBracket;

compoundStatement:
	OpenBracket statement* CloseBracket
	| statement;

statement:
	expression SemiColon
	| ifStatement
	| loopStatement
	| assigmentStatement SemiColon;

ifStatement:
	'if' ParamOpen logicalExpression ParamClose compoundStatement;

loopStatement:
	rangeForStatement
	| forStatement
	| whileStatement
	| doWhileStatement
	| infiniteLoopStatement;

rangeForStatement:
	'for' ParamOpen Identifier 'in' expression ParamClose compoundStatement;

forStatement:
	'for' ParamOpen expression SemiColon logicalExpression SemiColon expression ParamClose
		compoundStatement;

whileStatement: whileHeader compoundStatement;
doWhileStatement: 'do' compoundStatement whileHeader SemiColon;
whileHeader: 'while' ParamOpen logicalExpression ParamClose;

infiniteLoopStatement: 'loop' compoundStatement;

//todo
functionCall:
	qualifiedIdentifier ParamOpen (
		functionCallParameter (Comma functionCallParameter)*
	)? ParamClose;
functionCallParameter: expression | arithmeticExpression | logicalExpression;
attributeSequence: attribute+;

attribute: ATTROBITEOPEN functionCall ATTROBITECLOSE;

qualifiedIdentifier: Identifier (DoubleColon Identifier)*;

expression
    :functionCall
	| throwExpression
	| qualifiedIdentifier
	| ParamOpen expression ParamClose;

arithmeticExpression:
	arithmeticExpression ArithmeticBinaryOperator arithmeticExpression
	| functionCall
	| qualifiedIdentifier
	| ArithmeticUnaryOperator arithmeticExpression
	| IntegerLiteral
	| expression;

logicalExpression:
	logicalExpression LogicalBinaryOperator logicalExpression
	| functionCall
	| qualifiedIdentifier
	| LogicalUnaryOperator logicalExpression
	| comparisonExpression
	| expression;

comparisonExpression: arithmeticExpression ComparsionOperator arithmeticExpression;

assigmentStatement:
	lExpression Asssigment (
		expression
		| arithmeticExpression
		| logicalExpression
	);

lExpression: qualifiedIdentifier;

throwExpression: Throw expression;

Identifier: LETTER (LETTER | DIGIT)*;

OpenBracket: '{';
CloseBracket: '}';
RAWSTRING: '"' .*? '(' .*? ')' .*? '"';
DOUBLEQUOTE: '"';
SINGLEQUOTE: '\'';
ParamOpen: '(';
ParamClose: ')';
ATTROBITEOPEN: '[';
ATTROBITECLOSE: ']';

ArithmeticBinaryOperator:
	| Plus
	| Minus
	| Star
	| PlusEquals
	| MinusEquals
	| MultiplyEquals
	| DivideEquals;
ArithmeticUnaryOperator: Plus | Minus;

ComparsionOperator:
	GreaterThan
	| LessThan
	| GreaterEqual
	| LessEqual
	| Equal
	| NotEqual;

LogicalBinaryOperator: Or | And | Xor;

LogicalUnaryOperator: Not;

Not: '!';
DoubleColon: '::';
SemiColon: ';';
Comma: ',';
Period: '.';
Equals: '==';
Asssigment: '=';
NotEquals: '!=';
Plus: '+';
Minus: '-';
Star: '*';
PlusEquals: '+=';
MinusEquals: '-=';
MultiplyEquals: '*=';
DivideEquals: '/=';
GreaterThan: '>';
LessThan: '<';
GreaterEqual: '>=';
LessEqual: '<=';
Equal: '==';
NotEqual: '!=';
Or: '||';
And: '&&';
Xor: '^^';
Strong: '!';
Nullable: '?';
Mutable: '^';
Ref: '&';
Class: 'class';
Interface: 'interface';
Public: 'public';
Private: 'private';
Protected: 'protected';
Internal: 'internal';
Final: 'final';
Virtual: 'virtual';
Abstract: 'abstract';
Override: 'override';
DefaultSpecification: '=' 'default';
Attribute: 'attribute';
Throw: 'throw';

IntegerLiteral: (DIGIT)+;

DIGIT: [0-9];

LETTER: [a-zA-Z];

Whitespace: [ \t]+ -> skip;
Newline: ('\r' '\n'? | '\n') -> skip;
BlockComment: '/*' .*? '*/' -> skip;
LineComment: '//' ~ [\r\n]* -> skip;