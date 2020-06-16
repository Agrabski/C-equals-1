grammar CMinusEqualsMinus1Revision0;

compilationUnit:
	languageStandardDeclaration declarationSequence EOF
	| declarationSequence;

languageStandardDeclaration:
	'standard' '=' IntegerLiteral SemiColon;

declarationSequence: declaration+;

declaration: functionDeclaration | classDeclaration | interfaceDeclaration | structDeclaration | namespaceDeclaration | importDeclaration | attributeDeclaration;

attributeDeclaration : (AccessSpecifier)? 'att' '<'('type' | Interface | 'function')+ '>' Identifier OpenBracket attributeContentSequence CloseBracket;

attributeContentSequence:functionDeclaration*;

importDeclaration : 'import' '{' Identifier+ '}' 'from' '{' qualifiedIdentifier '}';

classDeclaration:
	(attributeSequence)? AccessSpecifier? Class Identifier ':' implementedInterfacesSequence OpenBracket
		classContentSequence CloseBracket;
interfaceDeclaration: attributeSequence? AccessSpecifier? Interface Identifier ':' implementedInterfacesSequence OpenBracket interfaceContentSequence CloseBracket;

interfaceContentSequence:functionDeclaration*;

structDeclaration : (attributeSequence)? (AccessSpecifier)? 'struct' Identifier OpenBracket structContentSequence CloseBracket;

structContentSequence : fieldDeclaration*;

classContentSequence: (functionDeclaration | fieldDeclaration)*;

fieldDeclaration:
	attributeSequence? AccessSpecifier? Identifier ':' Identifier;

implementedInterfacesSequence:
	Identifier
	| (Identifier ',')+ Identifier;

namespaceDeclaration:
	'namespace' qualifiedIdentifier OpenBracket declarationSequence CloseBracket;

functionDeclaration:
	(attributeSequence)? AccessSpecifier? 'fn' Identifier ParamOpen parameterList ParamClose ('->'
		Identifier)? functionBody;

parameterList: | parameter | (parameter ',')+ parameter;

parameter: attributeSequence? Identifier ':' Identifier;

functionBody: OpenBracket statement* CloseBracket;

compoundStatement:
	OpenBracket statement* CloseBracket
	| statement;

statement:
	expression SemiColon
	| ifStatement
	| loopStatement
	| assigmentStatement SemiColon
	| variableDeclarationStatement SemiColon;

variableDeclarationStatement: attributeSequence? 'let' Identifier (':' Identifier)? ('=' functionCallParameter)?;

ifStatement:
	'if' ParamOpen logicalExpression ParamClose compoundStatement ('else' compoundStatement)?;

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

functionCall:
	Identifier ParamOpen (
		functionCallParameter (Comma functionCallParameter)*
	)? ParamClose;

functionCallParameter:
	expression
	| arithmeticExpression
	| logicalExpression;
attributeSequence: attribute+;

attribute: ATTROBITEOPEN functionCall ATTROBITECLOSE;

qualifiedIdentifier: Identifier (DoubleColon Identifier)*;

expression:
	functionCall
	| throwExpression
	| Identifier
	| ParamOpen expression ParamClose;

arithmeticExpression:
	arithmeticExpression ArithmeticBinaryOperator arithmeticExpression
	| functionCall
	| Identifier
	| ArithmeticUnaryOperator arithmeticExpression
	| IntegerLiteral
	| expression;

logicalExpression:
	logicalExpression LogicalBinaryOperator logicalExpression
	| functionCall
	| Identifier
	| LogicalUnaryOperator logicalExpression
	| comparisonExpression
	| expression;

comparisonExpression:
	arithmeticExpression ComparsionOperator arithmeticExpression;

assigmentStatement:
	lExpression Asssigment (
		expression
		| arithmeticExpression
		| logicalExpression
	);

lExpression: Identifier | Identifier ('.' Identifier)+;

throwExpression: Throw expression;

AccessSpecifier: Public | Private | Protected;

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
	'>'
	| '<'
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