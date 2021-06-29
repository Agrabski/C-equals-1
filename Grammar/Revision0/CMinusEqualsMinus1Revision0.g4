grammar CMinusEqualsMinus1Revision0;

compilationUnit:
	languageStandardDeclaration declarationSequence EOF
	| declarationSequence;

languageStandardDeclaration:
	'standard' '=' IntegerLiteral SemiColon;

declarationSequence: declaration+;

declaration: functionDeclaration | typeDeclaration | namespaceDeclaration | importDeclaration | attributeDeclaration;

attributeDeclaration : (AccessSpecifier)? 'att' Less attributeTarget+ Greater identifier OpenBracket classContentSequence CloseBracket;

attributeTarget: ('type' | 'variable' | 'function');

importDeclaration : 'import' '{' importAliasDeclaration+ '}' 'from' '{' qualifiedIdentifier '}';

importAliasDeclaration: identifier (':'identifier)?;

typeDeclaration:
	(attributeSequence)? AccessSpecifier? classTypeSpecifier identifier genericSpecifier? (':' implementedInterfacesSequence)? OpenBracket
		classContentSequence CloseBracket;

classTypeSpecifier: (Class| Interface | 'struct');

classContentSequence: (functionDeclaration | fieldDeclaration)*;

fieldDeclaration:
	attributeSequence? AccessSpecifier? identifier ':' typeSpecifier SemiColon;

genericSpecifier: Less identifier (',' identifier)* Greater;

implementedInterfacesSequence:
	typeReference
	| (typeReference ',')+ identifier;

typeReference: identifier genericUsage?;

namespaceDeclaration:
	'namespace' qualifiedIdentifier OpenBracket declarationSequence CloseBracket;

functionDeclaration:
	(attributeSequence)? AccessSpecifier? 'fn' functionName genericSpecifier? ParamOpen parameterList ParamClose ('->'
		typeSpecifier)? functionBody;

parameterList: | parameter | (parameter ',')+ parameter;

parameter: attributeSequence? identifier ':' typeSpecifier;

typeSpecifier: typeReference modifier;

modifier:  arraySpecifier? ref*;

arraySpecifier: '[' modifier']';

genericUsage: Less typeSpecifier (',' typeSpecifier)* Greater;

functionBody: OpenBracket statement* CloseBracket;

functionName: identifier | specialFunctionIdentifier;
specialFunctionIdentifier: Operator (New (Unique | Shared) | binaryOperator ); // todo: more operators

compoundStatement:
	Unsafe? OpenBracket statement* CloseBracket
	| statement;

statement:
	  ifStatement
	| loopStatement
	| assigmentStatement SemiColon
	| variableDeclarationStatement SemiColon
	| returnStatement SemiColon
    | functionCallStatement SemiColon;

functionCallStatement: functionCall | expression Period functionCall;

returnStatement: 'return' expression;

variableDeclarationStatement: attributeSequence? 'let' identifier (':' typeSpecifier)? ('=' functionCallParameter)?;

ifStatement:
	'if' ParamOpen expression ParamClose compoundStatement ('else' compoundStatement)?;

loopStatement:
	rangeForStatement
	| forStatement
	| whileStatement
	| doWhileStatement
	| infiniteLoopStatement;

rangeForStatement:
	'for' ParamOpen identifier 'in' expression ParamClose compoundStatement;

forStatement:
	'for' ParamOpen expression SemiColon expression SemiColon expression ParamClose
		compoundStatement;

whileStatement: whileHeader compoundStatement;
doWhileStatement: 'do' compoundStatement whileHeader SemiColon;
whileHeader: 'while' ParamOpen expression ParamClose;

infiniteLoopStatement: 'loop' compoundStatement;

functionCall:
	identifier genericUsage? ParamOpen (
		functionCallParameter (Comma functionCallParameter)*
	)? ParamClose;

functionCallParameter: expression;
attributeSequence: attribute+;

attribute: ATTROBITEOPEN functionCall ATTROBITECLOSE;

qualifiedIdentifier: identifier (DoubleColon identifier)*;

expression
    : STRING
    | arrayLiteral
    | ParamOpen expression ParamClose
    | expression Period identifier
    | expression Period functionCall
    | functionCall
    | throwExpression
    | identifier
    | IntegerLiteral
	| newExpression
	| expression binaryOperator expression
    | LogicalUnaryOperator expression
    | expression indexExpression
    ;

arrayLiteral: typeReference '[' ((expression ',')* expression)? ']';

indexExpression: '[' expression+']';

newExpression : New (Unique | Shared) functionCall;

assigmentStatement:
	expression Asssigment expression;

throwExpression: Throw expression;

AccessSpecifier: Public | Private | Internal;



OpenBracket: '{';
CloseBracket: '}';
DOUBLEQUOTE: '"';
SINGLEQUOTE: '\'';
ParamOpen: '(';
ParamClose: ')';
ATTROBITEOPEN: '[';
ATTROBITECLOSE: ']';

arithmeticBinaryOperator
    : Plus
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

logicalBinaryOperator: Or | And | Xor | NotEqual | Equal;

Unsafe: 'unsafe';

LogicalUnaryOperator: Not;

Equal: '==';
NotEqual: '!=';
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
Operator: 'operator';
Shared: 'shared';
Unique: 'unique';
New: 'new';

identifier: SimpleIdentifier | '@new' | '@unique' | '@shared' | '@throw' | '@attribute' | '@default';

SimpleIdentifier: LETTER (LETTER | DIGIT)*;


IntegerLiteral: (DIGIT)+;
DIGIT: [0-9];
fragment ESC : '\\"' | '\\\\' | '\\\n' ;
STRING: '"' ( ESC | ~[\\"\r\n] )* '"';
AnyCharacter:('\\"');
LETTER: [a-zA-Z_];
Whitespace: [ \t]+ -> skip;
Newline: ('\r' '\n'? | '\n') -> skip;
BlockComment: '/*' .*? '*/' -> skip;
LineComment: '//' ~ [\r\n]* -> skip;