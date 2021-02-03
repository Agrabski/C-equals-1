grammar CMinusEqualsMinus1Revision0;

compilationUnit:
	languageStandardDeclaration declarationSequence EOF
	| declarationSequence;

languageStandardDeclaration:
	'standard' '=' IntegerLiteral SemiColon;

declarationSequence: declaration+;

declaration: functionDeclaration | typeDeclaration | namespaceDeclaration | importDeclaration | attributeDeclaration;

attributeDeclaration : (AccessSpecifier)? 'att' '<'attributeTarget+ '>' Identifier OpenBracket classContentSequence CloseBracket;

attributeTarget: ('type' | 'variable' | 'function');

importDeclaration : 'import' '{' Identifier+ '}' 'from' '{' qualifiedIdentifier '}';

typeDeclaration:
	(attributeSequence)? AccessSpecifier? classTypeSpecifier Identifier (':' implementedInterfacesSequence)? OpenBracket
		classContentSequence CloseBracket;

classTypeSpecifier: (Class| Interface | 'struct');

classContentSequence: (functionDeclaration | fieldDeclaration)*;

fieldDeclaration:
	attributeSequence? AccessSpecifier? Identifier ':' typeSpecifier SemiColon;

genericSpecifier: '<' Identifier (',' Identifier)* '>';

implementedInterfacesSequence:
	Identifier
	| (Identifier ',')+ Identifier;

namespaceDeclaration:
	'namespace' qualifiedIdentifier OpenBracket declarationSequence CloseBracket;

functionDeclaration:
	(attributeSequence)? AccessSpecifier? 'fn' Identifier genericSpecifier? ParamOpen parameterList ParamClose ('->'
		typeSpecifier)? functionBody;

parameterList: | parameter | (parameter ',')+ parameter;

parameter: attributeSequence? Identifier ':' typeSpecifier;

typeSpecifier: Identifier genericUsage? Ref? (Array)?;

genericUsage: '<' typeSpecifier (',' typeSpecifier)* '>';

functionBody: OpenBracket statement* CloseBracket;

compoundStatement:
	Unsafe? OpenBracket statement* CloseBracket
	| statement;

statement:
	expression SemiColon
	| ifStatement
	| loopStatement
	| assigmentStatement SemiColon
	| variableDeclarationStatement SemiColon
	| returnStatement SemiColon;

returnStatement: 'return' expression;

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
	Identifier genericUsage? ParamOpen (
		functionCallParameter (Comma functionCallParameter)*
	)? ParamClose;

functionCallParameter:
	expression
	| arithmeticExpression
	| logicalExpression;
attributeSequence: attribute+;

attribute: ATTROBITEOPEN functionCall ATTROBITECLOSE;

qualifiedIdentifier: Identifier (DoubleColon Identifier)*;

expression
    : STRING
	| functionCall
	| throwExpression
	| Identifier
	| ParamOpen expression ParamClose
	| lExpression
	| newExpression;

newExpression : 'new' functionCall;

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

AccessSpecifier: Public | Private | Internal;

Identifier: LETTER (LETTER | DIGIT)*;

OpenBracket: '{';
CloseBracket: '}';
DOUBLEQUOTE: '"';
SINGLEQUOTE: '\'';
ParamOpen: '(';
ParamClose: ')';
ATTROBITEOPEN: '[';
ATTROBITECLOSE: ']';
Array: '['']';

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

Unsafe: 'unsafe';

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
fragment ESC : '\\"' | '\\\\' ;
STRING: '"' ( ESC | ~[\\"\r\n] )* '"';
AnyCharacter:('\\"');
LETTER: [a-zA-Z_];
Whitespace: [ \t]+ -> skip;
Newline: ('\r' '\n'? | '\n') -> skip;
BlockComment: '/*' .*? '*/' -> skip;
LineComment: '//' ~ [\r\n]* -> skip;