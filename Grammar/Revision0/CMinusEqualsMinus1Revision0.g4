grammar CMinusEqualsMinus1Revision0;

compilationUnit:
	languageStandardDeclaration declarationSequence EOF
	| declarationSequence;

languageStandardDeclaration:
	'standard' '=' IntegerLiteral SemiColon;

declarationSequence: declaration+;

declaration: functionDeclaration | typeDeclaration | namespaceDeclaration | importDeclaration | attributeDeclaration;

attributeDeclaration : (AccessSpecifier)? 'att' Less attributeTarget+ Greater Identifier OpenBracket classContentSequence CloseBracket;

attributeTarget: ('type' | 'variable' | 'function');

importDeclaration : 'import' '{' Identifier+ '}' 'from' '{' qualifiedIdentifier '}';

typeDeclaration:
	(attributeSequence)? AccessSpecifier? classTypeSpecifier Identifier (':' implementedInterfacesSequence)? OpenBracket
		classContentSequence CloseBracket;

classTypeSpecifier: (Class| Interface | 'struct');

classContentSequence: (functionDeclaration | fieldDeclaration)*;

fieldDeclaration:
	attributeSequence? AccessSpecifier? Identifier ':' typeSpecifier SemiColon;

genericSpecifier: Less Identifier (',' Identifier)* Greater;

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

typeSpecifier: Identifier genericUsage? ref* (Array)?;

genericUsage: Less typeSpecifier (',' typeSpecifier)* Greater;

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

variableDeclarationStatement: attributeSequence? 'let' Identifier (':' typeSpecifier)? ('=' functionCallParameter)?;

ifStatement:
	'if' ParamOpen expression ParamClose compoundStatement ('else' compoundStatement)?;

loopStatement:
	rangeForStatement
	| forStatement
	| whileStatement
	| doWhileStatement
	| infiniteLoopStatement;

rangeForStatement:
	'for' ParamOpen Identifier 'in' expression ParamClose compoundStatement;

forStatement:
	'for' ParamOpen expression SemiColon expression SemiColon expression ParamClose
		compoundStatement;

whileStatement: whileHeader compoundStatement;
doWhileStatement: 'do' compoundStatement whileHeader SemiColon;
whileHeader: 'while' ParamOpen expression ParamClose;

infiniteLoopStatement: 'loop' compoundStatement;

functionCall:
	Identifier genericUsage? ParamOpen (
		functionCallParameter (Comma functionCallParameter)*
	)? ParamClose;

functionCallParameter: expression;
attributeSequence: attribute+;

attribute: ATTROBITEOPEN functionCall ATTROBITECLOSE;

qualifiedIdentifier: Identifier (DoubleColon Identifier)*;

expression
    : STRING
    | functionCall
    | throwExpression
    | Identifier
    | IntegerLiteral
	| ParamOpen expression ParamClose
	| newExpression
	| expression arithmeticBinaryOperator expression
	| expression comparsionOperator expression
	| expression logicalBinaryOperator expression
    | LogicalUnaryOperator expression
    | expression Period Identifier
    | expression Period functionCall
    ;

newExpression : 'new' functionCall;

assigmentStatement:
	expression Asssigment expression;

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

arithmeticBinaryOperator:
	| Plus
	| Minus
	| Star
	| PlusEquals
	| MinusEquals
	| MultiplyEquals
	| DivideEquals;

comparsionOperator
    : Greater
	| Less
	| GreaterEqual
	| LessEqual
	| Equal
	| NotEqual;

binaryOperator: logicalBinaryOperator | comparsionOperator | arithmeticBinaryOperator;

logicalBinaryOperator: Or | And | Xor;

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
Greater: '>';
Less: '<';
LessEqual: '<=';
Equal: '==';
NotEqual: '!=';
Or: '||';
And: '&&';
Xor: '^^';
Strong: '!';
Nullable: '?';
Mutable: '^';
ref: Star;
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