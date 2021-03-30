
// Generated from CMinusEqualsMinus1Revision0.g4 by ANTLR 4.7.2


#include "CMinusEqualsMinus1Revision0Listener.h"
#include "CMinusEqualsMinus1Revision0Visitor.h"

#include "CMinusEqualsMinus1Revision0Parser.h"


using namespace antlrcpp;
using namespace antlr4;

CMinusEqualsMinus1Revision0Parser::CMinusEqualsMinus1Revision0Parser(TokenStream *input) : Parser(input)
{
	setInterpreter(std::make_unique<atn::ParserATNSimulator>(this, _atn, _decisionToDFA, _sharedContextCache));
}

std::string CMinusEqualsMinus1Revision0Parser::getGrammarFileName() const
{
	return "CMinusEqualsMinus1Revision0.g4";
}

const std::vector<std::string_view>& CMinusEqualsMinus1Revision0Parser::getRuleNames() const
{
	return _ruleNames;
}

dfa::Vocabulary& CMinusEqualsMinus1Revision0Parser::getVocabulary() const
{
	return _vocabulary;
}


//----------------- CompilationUnitContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::CompilationUnitContext::CompilationUnitContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::LanguageStandardDeclarationContext* CMinusEqualsMinus1Revision0Parser::CompilationUnitContext::languageStandardDeclaration()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::LanguageStandardDeclarationContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::DeclarationSequenceContext* CMinusEqualsMinus1Revision0Parser::CompilationUnitContext::declarationSequence()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::DeclarationSequenceContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::CompilationUnitContext::EOF()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::EOF, 0);
}


size_t CMinusEqualsMinus1Revision0Parser::CompilationUnitContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleCompilationUnit;//688
}

void CMinusEqualsMinus1Revision0Parser::CompilationUnitContext::copyFrom(CompilationUnitContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::CompilationUnitContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<CompilationUnitContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::CompilationUnitContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::CompilationUnitContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::CompilationUnitContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitCompilationUnit(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::CompilationUnitContext* CMinusEqualsMinus1Revision0Parser::compilationUnit( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<CompilationUnitContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 0, CMinusEqualsMinus1Revision0Parser::RuleCompilationUnit);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		setState(107);//750
		_errHandler->sync(this, ctx);
		switch (_input->LA(1))
		{
			case CMinusEqualsMinus1Revision0Parser::T__0:
			{
				enterOuterAlt(ctx, 1);
				setState(102); //951
				languageStandardDeclaration(ctx);
				setState(103); //951
				declarationSequence(ctx);
				setState(104);//958
				match(CMinusEqualsMinus1Revision0Parser::EOF,ctx);
				break;
			}

			case CMinusEqualsMinus1Revision0Parser::T__1:
			case CMinusEqualsMinus1Revision0Parser::T__5:
			case CMinusEqualsMinus1Revision0Parser::T__8:
			case CMinusEqualsMinus1Revision0Parser::T__9:
			case CMinusEqualsMinus1Revision0Parser::T__10:
			case CMinusEqualsMinus1Revision0Parser::AccessSpecifier:
			case CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN:
			case CMinusEqualsMinus1Revision0Parser::Class:
			case CMinusEqualsMinus1Revision0Parser::Interface:
			{
				enterOuterAlt(ctx, 2);
				setState(106); //951
				declarationSequence(ctx);
				break;
			}

		default:
			throw NoViableAltException(this, ctx);
		}
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::CompilationUnitContext> CMinusEqualsMinus1Revision0Parser::parsecompilationUnit()
{
	compilationUnit();
	auto result = std::unique_ptr<CompilationUnitContext>(dynamic_cast<CompilationUnitContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- LanguageStandardDeclarationContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::LanguageStandardDeclarationContext::LanguageStandardDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::LanguageStandardDeclarationContext::Asssigment()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Asssigment, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::LanguageStandardDeclarationContext::IntegerLiteral()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::IntegerLiteral, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::LanguageStandardDeclarationContext::SemiColon()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::SemiColon, 0);
}


size_t CMinusEqualsMinus1Revision0Parser::LanguageStandardDeclarationContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleLanguageStandardDeclaration;//688
}

void CMinusEqualsMinus1Revision0Parser::LanguageStandardDeclarationContext::copyFrom(LanguageStandardDeclarationContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::LanguageStandardDeclarationContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<LanguageStandardDeclarationContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::LanguageStandardDeclarationContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::LanguageStandardDeclarationContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::LanguageStandardDeclarationContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitLanguageStandardDeclaration(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::LanguageStandardDeclarationContext* CMinusEqualsMinus1Revision0Parser::languageStandardDeclaration( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<LanguageStandardDeclarationContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 2, CMinusEqualsMinus1Revision0Parser::RuleLanguageStandardDeclaration);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(109);//958
		match(CMinusEqualsMinus1Revision0Parser::T__0,ctx);
		setState(110);//958
		match(CMinusEqualsMinus1Revision0Parser::Asssigment,ctx);
		setState(111);//958
		match(CMinusEqualsMinus1Revision0Parser::IntegerLiteral,ctx);
		setState(112);//958
		match(CMinusEqualsMinus1Revision0Parser::SemiColon,ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::LanguageStandardDeclarationContext> CMinusEqualsMinus1Revision0Parser::parselanguageStandardDeclaration()
{
	languageStandardDeclaration();
	auto result = std::unique_ptr<LanguageStandardDeclarationContext>(dynamic_cast<LanguageStandardDeclarationContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- DeclarationSequenceContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::DeclarationSequenceContext::DeclarationSequenceContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

std::vector<CMinusEqualsMinus1Revision0Parser::DeclarationContext *> CMinusEqualsMinus1Revision0Parser::DeclarationSequenceContext::declaration()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::DeclarationContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::DeclarationContext* CMinusEqualsMinus1Revision0Parser::DeclarationSequenceContext::declaration(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::DeclarationContext>(i);//1183
}


size_t CMinusEqualsMinus1Revision0Parser::DeclarationSequenceContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleDeclarationSequence;//688
}

void CMinusEqualsMinus1Revision0Parser::DeclarationSequenceContext::copyFrom(DeclarationSequenceContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::DeclarationSequenceContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<DeclarationSequenceContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::DeclarationSequenceContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::DeclarationSequenceContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::DeclarationSequenceContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitDeclarationSequence(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::DeclarationSequenceContext* CMinusEqualsMinus1Revision0Parser::declarationSequence( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<DeclarationSequenceContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 4, CMinusEqualsMinus1Revision0Parser::RuleDeclarationSequence);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(115); //814
		_errHandler->sync(this, ctx);
		_la = _input->LA(1);
		do
		{
			setState(114); //951
			declaration(ctx);
			setState(117); //820
			_errHandler->sync(this, ctx);
			_la = _input->LA(1);
		} while ((((_la & ~ 0x3fULL) == 0) &&
			((1ULL << _la) & ((1ULL << CMinusEqualsMinus1Revision0Parser::T__1)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__5)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__8)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__9)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__10)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::AccessSpecifier)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN))) != 0) || _la == CMinusEqualsMinus1Revision0Parser::Class

		|| _la == CMinusEqualsMinus1Revision0Parser::Interface);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::DeclarationSequenceContext> CMinusEqualsMinus1Revision0Parser::parsedeclarationSequence()
{
	declarationSequence();
	auto result = std::unique_ptr<DeclarationSequenceContext>(dynamic_cast<DeclarationSequenceContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- DeclarationContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::DeclarationContext::DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext* CMinusEqualsMinus1Revision0Parser::DeclarationContext::functionDeclaration()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext* CMinusEqualsMinus1Revision0Parser::DeclarationContext::typeDeclaration()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext* CMinusEqualsMinus1Revision0Parser::DeclarationContext::namespaceDeclaration()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext* CMinusEqualsMinus1Revision0Parser::DeclarationContext::importDeclaration()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext* CMinusEqualsMinus1Revision0Parser::DeclarationContext::attributeDeclaration()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext>(0);//1165
}


size_t CMinusEqualsMinus1Revision0Parser::DeclarationContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleDeclaration;//688
}

void CMinusEqualsMinus1Revision0Parser::DeclarationContext::copyFrom(DeclarationContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::DeclarationContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<DeclarationContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::DeclarationContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::DeclarationContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitDeclaration(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::DeclarationContext* CMinusEqualsMinus1Revision0Parser::declaration( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<DeclarationContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 6, CMinusEqualsMinus1Revision0Parser::RuleDeclaration);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		setState(124);//830
		_errHandler->sync(this, ctx);
		switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, ctx))
		{
		case 1:
		{
			enterOuterAlt(ctx, 1);
			setState(119); //951
			functionDeclaration(ctx);
			break;
		}

		case 2:
		{
			enterOuterAlt(ctx, 2);
			setState(120); //951
			typeDeclaration(ctx);
			break;
		}

		case 3:
		{
			enterOuterAlt(ctx, 3);
			setState(121); //951
			namespaceDeclaration(ctx);
			break;
		}

		case 4:
		{
			enterOuterAlt(ctx, 4);
			setState(122); //951
			importDeclaration(ctx);
			break;
		}

		case 5:
		{
			enterOuterAlt(ctx, 5);
			setState(123); //951
			attributeDeclaration(ctx);
			break;
		}

		}
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::DeclarationContext> CMinusEqualsMinus1Revision0Parser::parsedeclaration()
{
	declaration();
	auto result = std::unique_ptr<DeclarationContext>(dynamic_cast<DeclarationContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- AttributeDeclarationContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext::AttributeDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext::Less()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Less, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext::Greater()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Greater, 0);
}

CMinusEqualsMinus1Revision0Parser::IdentifierContext* CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext::identifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::IdentifierContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext::OpenBracket()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::OpenBracket, 0);
}

CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext* CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext::classContentSequence()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext::CloseBracket()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::CloseBracket, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext::AccessSpecifier()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::AccessSpecifier, 0);
}

std::vector<CMinusEqualsMinus1Revision0Parser::AttributeTargetContext *> CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext::attributeTarget()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::AttributeTargetContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::AttributeTargetContext* CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext::attributeTarget(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::AttributeTargetContext>(i);//1183
}


size_t CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleAttributeDeclaration;//688
}

void CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext::copyFrom(AttributeDeclarationContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<AttributeDeclarationContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitAttributeDeclaration(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext* CMinusEqualsMinus1Revision0Parser::attributeDeclaration( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<AttributeDeclarationContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 8, CMinusEqualsMinus1Revision0Parser::RuleAttributeDeclaration);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(127);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::AccessSpecifier)
		{
			setState(126);//958
			match(CMinusEqualsMinus1Revision0Parser::AccessSpecifier,ctx);
		}
		setState(129);//958
		match(CMinusEqualsMinus1Revision0Parser::T__1,ctx);
		setState(130);//958
		match(CMinusEqualsMinus1Revision0Parser::Less,ctx);
		setState(132); //814
		_errHandler->sync(this, ctx);
		_la = _input->LA(1);
		do
		{
			setState(131); //951
			attributeTarget(ctx);
			setState(134); //820
			_errHandler->sync(this, ctx);
			_la = _input->LA(1);
		} while ((((_la & ~ 0x3fULL) == 0) &&
			((1ULL << _la) & ((1ULL << CMinusEqualsMinus1Revision0Parser::T__2)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__3)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__4))) != 0));
		setState(136);//958
		match(CMinusEqualsMinus1Revision0Parser::Greater,ctx);
		setState(137); //951
		identifier(ctx);
		setState(138);//958
		match(CMinusEqualsMinus1Revision0Parser::OpenBracket,ctx);
		setState(139); //951
		classContentSequence(ctx);
		setState(140);//958
		match(CMinusEqualsMinus1Revision0Parser::CloseBracket,ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext> CMinusEqualsMinus1Revision0Parser::parseattributeDeclaration()
{
	attributeDeclaration();
	auto result = std::unique_ptr<AttributeDeclarationContext>(dynamic_cast<AttributeDeclarationContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- AttributeTargetContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::AttributeTargetContext::AttributeTargetContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}


size_t CMinusEqualsMinus1Revision0Parser::AttributeTargetContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleAttributeTarget;//688
}

void CMinusEqualsMinus1Revision0Parser::AttributeTargetContext::copyFrom(AttributeTargetContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::AttributeTargetContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<AttributeTargetContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::AttributeTargetContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::AttributeTargetContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::AttributeTargetContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitAttributeTarget(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::AttributeTargetContext* CMinusEqualsMinus1Revision0Parser::attributeTarget( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<AttributeTargetContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 10, CMinusEqualsMinus1Revision0Parser::RuleAttributeTarget);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(142);//970
		_la = _input->LA(1);
		if (!((((_la & ~ 0x3fULL) == 0) &&
			((1ULL << _la) & ((1ULL << CMinusEqualsMinus1Revision0Parser::T__2)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__3)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__4))) != 0)))
		{
		_errHandler->recoverInline(this, ctx);
		}
		else
		{
			_errHandler->reportMatch(this);
			consume(ctx);
		}
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::AttributeTargetContext> CMinusEqualsMinus1Revision0Parser::parseattributeTarget()
{
	attributeTarget();
	auto result = std::unique_ptr<AttributeTargetContext>(dynamic_cast<AttributeTargetContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- ImportDeclarationContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext::ImportDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

std::vector<tree::TerminalNode *> CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext::OpenBracket()
{
	return getTokens(CMinusEqualsMinus1Revision0Parser::OpenBracket);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext::OpenBracket(size_t i)
{
	return getToken(CMinusEqualsMinus1Revision0Parser::OpenBracket, i);
}

std::vector<tree::TerminalNode *> CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext::CloseBracket()
{
	return getTokens(CMinusEqualsMinus1Revision0Parser::CloseBracket);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext::CloseBracket(size_t i)
{
	return getToken(CMinusEqualsMinus1Revision0Parser::CloseBracket, i);
}

CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext* CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext::qualifiedIdentifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext>(0);//1165
}

std::vector<CMinusEqualsMinus1Revision0Parser::IdentifierContext *> CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext::identifier()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::IdentifierContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::IdentifierContext* CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext::identifier(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::IdentifierContext>(i);//1183
}


size_t CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleImportDeclaration;//688
}

void CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext::copyFrom(ImportDeclarationContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<ImportDeclarationContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitImportDeclaration(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext* CMinusEqualsMinus1Revision0Parser::importDeclaration( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<ImportDeclarationContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 12, CMinusEqualsMinus1Revision0Parser::RuleImportDeclaration);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(144);//958
		match(CMinusEqualsMinus1Revision0Parser::T__5,ctx);
		setState(145);//958
		match(CMinusEqualsMinus1Revision0Parser::OpenBracket,ctx);
		setState(147); //814
		_errHandler->sync(this, ctx);
		_la = _input->LA(1);
		do
		{
			setState(146); //951
			identifier(ctx);
			setState(149); //820
			_errHandler->sync(this, ctx);
			_la = _input->LA(1);
		} while (((((_la - 22) & ~ 0x3fULL) == 0) &&
			((1ULL << (_la - 22)) & ((1ULL << (CMinusEqualsMinus1Revision0Parser::T__21 - 22))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::T__22 - 22))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::T__23 - 22))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::T__24 - 22))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::T__25 - 22))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::T__26 - 22))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::SimpleIdentifier - 22)))) != 0));
		setState(151);//958
		match(CMinusEqualsMinus1Revision0Parser::CloseBracket,ctx);
		setState(152);//958
		match(CMinusEqualsMinus1Revision0Parser::T__6,ctx);
		setState(153);//958
		match(CMinusEqualsMinus1Revision0Parser::OpenBracket,ctx);
		setState(154); //951
		qualifiedIdentifier(ctx);
		setState(155);//958
		match(CMinusEqualsMinus1Revision0Parser::CloseBracket,ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext> CMinusEqualsMinus1Revision0Parser::parseimportDeclaration()
{
	importDeclaration();
	auto result = std::unique_ptr<ImportDeclarationContext>(dynamic_cast<ImportDeclarationContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- TypeDeclarationContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext::TypeDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::ClassTypeSpecifierContext* CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext::classTypeSpecifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ClassTypeSpecifierContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::IdentifierContext* CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext::identifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::IdentifierContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext::OpenBracket()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::OpenBracket, 0);
}

CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext* CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext::classContentSequence()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext::CloseBracket()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::CloseBracket, 0);
}

CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext* CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext::attributeSequence()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext::AccessSpecifier()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::AccessSpecifier, 0);
}

CMinusEqualsMinus1Revision0Parser::GenericSpecifierContext* CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext::genericSpecifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::GenericSpecifierContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::ImplementedInterfacesSequenceContext* CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext::implementedInterfacesSequence()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ImplementedInterfacesSequenceContext>(0);//1165
}


size_t CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleTypeDeclaration;//688
}

void CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext::copyFrom(TypeDeclarationContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<TypeDeclarationContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitTypeDeclaration(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext* CMinusEqualsMinus1Revision0Parser::typeDeclaration( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<TypeDeclarationContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 14, CMinusEqualsMinus1Revision0Parser::RuleTypeDeclaration);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(158);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN)
		{
			setState(157); //951
			attributeSequence(ctx);
		}
		setState(161);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::AccessSpecifier)
		{
			setState(160);//958
			match(CMinusEqualsMinus1Revision0Parser::AccessSpecifier,ctx);
		}
		setState(163); //951
		classTypeSpecifier(ctx);
		setState(164); //951
		identifier(ctx);
		setState(166);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::Less)
		{
			setState(165); //951
			genericSpecifier(ctx);
		}
		setState(170);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::T__7)
		{
			setState(168);//958
			match(CMinusEqualsMinus1Revision0Parser::T__7,ctx);
			setState(169); //951
			implementedInterfacesSequence(ctx);
		}
		setState(172);//958
		match(CMinusEqualsMinus1Revision0Parser::OpenBracket,ctx);
		setState(173); //951
		classContentSequence(ctx);
		setState(174);//958
		match(CMinusEqualsMinus1Revision0Parser::CloseBracket,ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext> CMinusEqualsMinus1Revision0Parser::parsetypeDeclaration()
{
	typeDeclaration();
	auto result = std::unique_ptr<TypeDeclarationContext>(dynamic_cast<TypeDeclarationContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- ClassTypeSpecifierContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::ClassTypeSpecifierContext::ClassTypeSpecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ClassTypeSpecifierContext::Class()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Class, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ClassTypeSpecifierContext::Interface()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Interface, 0);
}


size_t CMinusEqualsMinus1Revision0Parser::ClassTypeSpecifierContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleClassTypeSpecifier;//688
}

void CMinusEqualsMinus1Revision0Parser::ClassTypeSpecifierContext::copyFrom(ClassTypeSpecifierContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::ClassTypeSpecifierContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<ClassTypeSpecifierContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::ClassTypeSpecifierContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::ClassTypeSpecifierContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::ClassTypeSpecifierContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitClassTypeSpecifier(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::ClassTypeSpecifierContext* CMinusEqualsMinus1Revision0Parser::classTypeSpecifier( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<ClassTypeSpecifierContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 16, CMinusEqualsMinus1Revision0Parser::RuleClassTypeSpecifier);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(176);//970
		_la = _input->LA(1);
		if (!(((((_la - 9) & ~ 0x3fULL) == 0) &&
			((1ULL << (_la - 9)) & ((1ULL << (CMinusEqualsMinus1Revision0Parser::T__8 - 9))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::Class - 9))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::Interface - 9)))) != 0)))
		{
		_errHandler->recoverInline(this, ctx);
		}
		else
		{
			_errHandler->reportMatch(this);
			consume(ctx);
		}
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::ClassTypeSpecifierContext> CMinusEqualsMinus1Revision0Parser::parseclassTypeSpecifier()
{
	classTypeSpecifier();
	auto result = std::unique_ptr<ClassTypeSpecifierContext>(dynamic_cast<ClassTypeSpecifierContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- ClassContentSequenceContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext::ClassContentSequenceContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

std::vector<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext *> CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext::functionDeclaration()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext* CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext::functionDeclaration(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext>(i);//1183
}

std::vector<CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext *> CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext::fieldDeclaration()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext* CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext::fieldDeclaration(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext>(i);//1183
}


size_t CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleClassContentSequence;//688
}

void CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext::copyFrom(ClassContentSequenceContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<ClassContentSequenceContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitClassContentSequence(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext* CMinusEqualsMinus1Revision0Parser::classContentSequence( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<ClassContentSequenceContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 18, CMinusEqualsMinus1Revision0Parser::RuleClassContentSequence);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(182);//800
		_errHandler->sync(this, ctx);
		_la = _input->LA(1);
		while ((((_la & ~ 0x3fULL) == 0) &&
			((1ULL << _la) & ((1ULL << CMinusEqualsMinus1Revision0Parser::T__10)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__21)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__22)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__23)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__24)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__25)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__26)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::AccessSpecifier)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN))) != 0) || _la == CMinusEqualsMinus1Revision0Parser::SimpleIdentifier)
		{
			setState(180);//830
			_errHandler->sync(this, ctx);
			switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, ctx))
			{
			case 1:
			{
				setState(178); //951
				functionDeclaration(ctx);
				break;
			}

			case 2:
			{
				setState(179); //951
				fieldDeclaration(ctx);
				break;
			}

			}
			setState(184);//806
			_errHandler->sync(this, ctx);
			_la = _input->LA(1);
		}
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext> CMinusEqualsMinus1Revision0Parser::parseclassContentSequence()
{
	classContentSequence();
	auto result = std::unique_ptr<ClassContentSequenceContext>(dynamic_cast<ClassContentSequenceContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- FieldDeclarationContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext::FieldDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::IdentifierContext* CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext::identifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::IdentifierContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext* CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext::typeSpecifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext::SemiColon()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::SemiColon, 0);
}

CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext* CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext::attributeSequence()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext::AccessSpecifier()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::AccessSpecifier, 0);
}


size_t CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleFieldDeclaration;//688
}

void CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext::copyFrom(FieldDeclarationContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<FieldDeclarationContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitFieldDeclaration(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext* CMinusEqualsMinus1Revision0Parser::fieldDeclaration( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<FieldDeclarationContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 20, CMinusEqualsMinus1Revision0Parser::RuleFieldDeclaration);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(186);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN)
		{
			setState(185); //951
			attributeSequence(ctx);
		}
		setState(189);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::AccessSpecifier)
		{
			setState(188);//958
			match(CMinusEqualsMinus1Revision0Parser::AccessSpecifier,ctx);
		}
		setState(191); //951
		identifier(ctx);
		setState(192);//958
		match(CMinusEqualsMinus1Revision0Parser::T__7,ctx);
		setState(193); //951
		typeSpecifier(ctx);
		setState(194);//958
		match(CMinusEqualsMinus1Revision0Parser::SemiColon,ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext> CMinusEqualsMinus1Revision0Parser::parsefieldDeclaration()
{
	fieldDeclaration();
	auto result = std::unique_ptr<FieldDeclarationContext>(dynamic_cast<FieldDeclarationContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- GenericSpecifierContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::GenericSpecifierContext::GenericSpecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::GenericSpecifierContext::Less()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Less, 0);
}

std::vector<CMinusEqualsMinus1Revision0Parser::IdentifierContext *> CMinusEqualsMinus1Revision0Parser::GenericSpecifierContext::identifier()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::IdentifierContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::IdentifierContext* CMinusEqualsMinus1Revision0Parser::GenericSpecifierContext::identifier(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::IdentifierContext>(i);//1183
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::GenericSpecifierContext::Greater()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Greater, 0);
}

std::vector<tree::TerminalNode *> CMinusEqualsMinus1Revision0Parser::GenericSpecifierContext::Comma()
{
	return getTokens(CMinusEqualsMinus1Revision0Parser::Comma);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::GenericSpecifierContext::Comma(size_t i)
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Comma, i);
}


size_t CMinusEqualsMinus1Revision0Parser::GenericSpecifierContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleGenericSpecifier;//688
}

void CMinusEqualsMinus1Revision0Parser::GenericSpecifierContext::copyFrom(GenericSpecifierContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::GenericSpecifierContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<GenericSpecifierContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::GenericSpecifierContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::GenericSpecifierContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::GenericSpecifierContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitGenericSpecifier(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::GenericSpecifierContext* CMinusEqualsMinus1Revision0Parser::genericSpecifier( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<GenericSpecifierContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 22, CMinusEqualsMinus1Revision0Parser::RuleGenericSpecifier);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(196);//958
		match(CMinusEqualsMinus1Revision0Parser::Less,ctx);
		setState(197); //951
		identifier(ctx);
		setState(202);//800
		_errHandler->sync(this, ctx);
		_la = _input->LA(1);
		while (_la == CMinusEqualsMinus1Revision0Parser::Comma)
		{
			setState(198);//958
			match(CMinusEqualsMinus1Revision0Parser::Comma,ctx);
			setState(199); //951
			identifier(ctx);
			setState(204);//806
			_errHandler->sync(this, ctx);
			_la = _input->LA(1);
		}
		setState(205);//958
		match(CMinusEqualsMinus1Revision0Parser::Greater,ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::GenericSpecifierContext> CMinusEqualsMinus1Revision0Parser::parsegenericSpecifier()
{
	genericSpecifier();
	auto result = std::unique_ptr<GenericSpecifierContext>(dynamic_cast<GenericSpecifierContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- ImplementedInterfacesSequenceContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::ImplementedInterfacesSequenceContext::ImplementedInterfacesSequenceContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

std::vector<CMinusEqualsMinus1Revision0Parser::IdentifierContext *> CMinusEqualsMinus1Revision0Parser::ImplementedInterfacesSequenceContext::identifier()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::IdentifierContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::IdentifierContext* CMinusEqualsMinus1Revision0Parser::ImplementedInterfacesSequenceContext::identifier(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::IdentifierContext>(i);//1183
}

std::vector<tree::TerminalNode *> CMinusEqualsMinus1Revision0Parser::ImplementedInterfacesSequenceContext::Comma()
{
	return getTokens(CMinusEqualsMinus1Revision0Parser::Comma);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ImplementedInterfacesSequenceContext::Comma(size_t i)
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Comma, i);
}


size_t CMinusEqualsMinus1Revision0Parser::ImplementedInterfacesSequenceContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleImplementedInterfacesSequence;//688
}

void CMinusEqualsMinus1Revision0Parser::ImplementedInterfacesSequenceContext::copyFrom(ImplementedInterfacesSequenceContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::ImplementedInterfacesSequenceContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<ImplementedInterfacesSequenceContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::ImplementedInterfacesSequenceContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::ImplementedInterfacesSequenceContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::ImplementedInterfacesSequenceContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitImplementedInterfacesSequence(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::ImplementedInterfacesSequenceContext* CMinusEqualsMinus1Revision0Parser::implementedInterfacesSequence( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<ImplementedInterfacesSequenceContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 24, CMinusEqualsMinus1Revision0Parser::RuleImplementedInterfacesSequence);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		size_t alt;
		setState(217);//830
		_errHandler->sync(this, ctx);
		switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, ctx))
		{
		case 1:
		{
			enterOuterAlt(ctx, 1);
			setState(207); //951
			identifier(ctx);
			break;
		}

		case 2:
		{
			enterOuterAlt(ctx, 2);
			setState(211); //883
			_errHandler->sync(this, ctx);
			alt = 1;
			do
			{
				switch (alt)
			{
					case 1:
					{
								setState(208); //951
								identifier(ctx);
								setState(209);//958
								match(CMinusEqualsMinus1Revision0Parser::Comma,ctx);
								break;
							}

				default:
					throw NoViableAltException(this, ctx);
				}
				setState(213); //900
				_errHandler->sync(this, ctx);
				alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, ctx);
			} while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
			setState(215); //951
			identifier(ctx);
			break;
		}

		}
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::ImplementedInterfacesSequenceContext> CMinusEqualsMinus1Revision0Parser::parseimplementedInterfacesSequence()
{
	implementedInterfacesSequence();
	auto result = std::unique_ptr<ImplementedInterfacesSequenceContext>(dynamic_cast<ImplementedInterfacesSequenceContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- NamespaceDeclarationContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext::NamespaceDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext* CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext::qualifiedIdentifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext::OpenBracket()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::OpenBracket, 0);
}

CMinusEqualsMinus1Revision0Parser::DeclarationSequenceContext* CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext::declarationSequence()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::DeclarationSequenceContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext::CloseBracket()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::CloseBracket, 0);
}


size_t CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleNamespaceDeclaration;//688
}

void CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext::copyFrom(NamespaceDeclarationContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<NamespaceDeclarationContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitNamespaceDeclaration(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext* CMinusEqualsMinus1Revision0Parser::namespaceDeclaration( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<NamespaceDeclarationContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 26, CMinusEqualsMinus1Revision0Parser::RuleNamespaceDeclaration);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(219);//958
		match(CMinusEqualsMinus1Revision0Parser::T__9,ctx);
		setState(220); //951
		qualifiedIdentifier(ctx);
		setState(221);//958
		match(CMinusEqualsMinus1Revision0Parser::OpenBracket,ctx);
		setState(222); //951
		declarationSequence(ctx);
		setState(223);//958
		match(CMinusEqualsMinus1Revision0Parser::CloseBracket,ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext> CMinusEqualsMinus1Revision0Parser::parsenamespaceDeclaration()
{
	namespaceDeclaration();
	auto result = std::unique_ptr<NamespaceDeclarationContext>(dynamic_cast<NamespaceDeclarationContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- FunctionDeclarationContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext::FunctionDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::FunctionNameContext* CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext::functionName()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::FunctionNameContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext::ParamOpen()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ParamOpen, 0);
}

CMinusEqualsMinus1Revision0Parser::ParameterListContext* CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext::parameterList()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ParameterListContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext::ParamClose()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ParamClose, 0);
}

CMinusEqualsMinus1Revision0Parser::FunctionBodyContext* CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext::functionBody()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::FunctionBodyContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext* CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext::attributeSequence()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext::AccessSpecifier()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::AccessSpecifier, 0);
}

CMinusEqualsMinus1Revision0Parser::GenericSpecifierContext* CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext::genericSpecifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::GenericSpecifierContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext* CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext::typeSpecifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext>(0);//1165
}


size_t CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleFunctionDeclaration;//688
}

void CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext::copyFrom(FunctionDeclarationContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<FunctionDeclarationContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitFunctionDeclaration(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext* CMinusEqualsMinus1Revision0Parser::functionDeclaration( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<FunctionDeclarationContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 28, CMinusEqualsMinus1Revision0Parser::RuleFunctionDeclaration);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(226);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN)
		{
			setState(225); //951
			attributeSequence(ctx);
		}
		setState(229);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::AccessSpecifier)
		{
			setState(228);//958
			match(CMinusEqualsMinus1Revision0Parser::AccessSpecifier,ctx);
		}
		setState(231);//958
		match(CMinusEqualsMinus1Revision0Parser::T__10,ctx);
		setState(232); //951
		functionName(ctx);
		setState(234);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::Less)
		{
			setState(233); //951
			genericSpecifier(ctx);
		}
		setState(236);//958
		match(CMinusEqualsMinus1Revision0Parser::ParamOpen,ctx);
		setState(237); //951
		parameterList(ctx);
		setState(238);//958
		match(CMinusEqualsMinus1Revision0Parser::ParamClose,ctx);
		setState(241);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::T__11)
		{
			setState(239);//958
			match(CMinusEqualsMinus1Revision0Parser::T__11,ctx);
			setState(240); //951
			typeSpecifier(ctx);
		}
		setState(243); //951
		functionBody(ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext> CMinusEqualsMinus1Revision0Parser::parsefunctionDeclaration()
{
	functionDeclaration();
	auto result = std::unique_ptr<FunctionDeclarationContext>(dynamic_cast<FunctionDeclarationContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- ParameterListContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::ParameterListContext::ParameterListContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

std::vector<CMinusEqualsMinus1Revision0Parser::ParameterContext *> CMinusEqualsMinus1Revision0Parser::ParameterListContext::parameter()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::ParameterContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::ParameterContext* CMinusEqualsMinus1Revision0Parser::ParameterListContext::parameter(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ParameterContext>(i);//1183
}

std::vector<tree::TerminalNode *> CMinusEqualsMinus1Revision0Parser::ParameterListContext::Comma()
{
	return getTokens(CMinusEqualsMinus1Revision0Parser::Comma);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ParameterListContext::Comma(size_t i)
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Comma, i);
}


size_t CMinusEqualsMinus1Revision0Parser::ParameterListContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleParameterList;//688
}

void CMinusEqualsMinus1Revision0Parser::ParameterListContext::copyFrom(ParameterListContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::ParameterListContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<ParameterListContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::ParameterListContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::ParameterListContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitParameterList(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::ParameterListContext* CMinusEqualsMinus1Revision0Parser::parameterList( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<ParameterListContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 30, CMinusEqualsMinus1Revision0Parser::RuleParameterList);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		size_t alt;
		setState(256);//830
		_errHandler->sync(this, ctx);
		switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, ctx))
		{
		case 1:
		{
			enterOuterAlt(ctx, 1);

			break;
		}

		case 2:
		{
			enterOuterAlt(ctx, 2);
			setState(246); //951
			parameter(ctx);
			break;
		}

		case 3:
		{
			enterOuterAlt(ctx, 3);
			setState(250); //883
			_errHandler->sync(this, ctx);
			alt = 1;
			do
			{
				switch (alt)
			{
					case 1:
					{
								setState(247); //951
								parameter(ctx);
								setState(248);//958
								match(CMinusEqualsMinus1Revision0Parser::Comma,ctx);
								break;
							}

				default:
					throw NoViableAltException(this, ctx);
				}
				setState(252); //900
				_errHandler->sync(this, ctx);
				alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, ctx);
			} while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
			setState(254); //951
			parameter(ctx);
			break;
		}

		}
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::ParameterListContext> CMinusEqualsMinus1Revision0Parser::parseparameterList()
{
	parameterList();
	auto result = std::unique_ptr<ParameterListContext>(dynamic_cast<ParameterListContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- ParameterContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::ParameterContext::ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::IdentifierContext* CMinusEqualsMinus1Revision0Parser::ParameterContext::identifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::IdentifierContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext* CMinusEqualsMinus1Revision0Parser::ParameterContext::typeSpecifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext* CMinusEqualsMinus1Revision0Parser::ParameterContext::attributeSequence()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext>(0);//1165
}


size_t CMinusEqualsMinus1Revision0Parser::ParameterContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleParameter;//688
}

void CMinusEqualsMinus1Revision0Parser::ParameterContext::copyFrom(ParameterContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::ParameterContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<ParameterContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::ParameterContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::ParameterContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::ParameterContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitParameter(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::ParameterContext* CMinusEqualsMinus1Revision0Parser::parameter( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<ParameterContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 32, CMinusEqualsMinus1Revision0Parser::RuleParameter);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(259);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN)
		{
			setState(258); //951
			attributeSequence(ctx);
		}
		setState(261); //951
		identifier(ctx);
		setState(262);//958
		match(CMinusEqualsMinus1Revision0Parser::T__7,ctx);
		setState(263); //951
		typeSpecifier(ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::ParameterContext> CMinusEqualsMinus1Revision0Parser::parseparameter()
{
	parameter();
	auto result = std::unique_ptr<ParameterContext>(dynamic_cast<ParameterContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- TypeSpecifierContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext::TypeSpecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::IdentifierContext* CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext::identifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::IdentifierContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::GenericUsageContext* CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext::genericUsage()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::GenericUsageContext>(0);//1165
}

std::vector<CMinusEqualsMinus1Revision0Parser::RefContext *> CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext::ref()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::RefContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::RefContext* CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext::ref(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::RefContext>(i);//1183
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext::Array()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Array, 0);
}


size_t CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleTypeSpecifier;//688
}

void CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext::copyFrom(TypeSpecifierContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<TypeSpecifierContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitTypeSpecifier(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext* CMinusEqualsMinus1Revision0Parser::typeSpecifier( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<TypeSpecifierContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 34, CMinusEqualsMinus1Revision0Parser::RuleTypeSpecifier);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(265); //951
		identifier(ctx);
		setState(267);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::Less)
		{
			setState(266); //951
			genericUsage(ctx);
		}
		setState(272);//800
		_errHandler->sync(this, ctx);
		_la = _input->LA(1);
		while (_la == CMinusEqualsMinus1Revision0Parser::Star)
		{
			setState(269); //951
			ref(ctx);
			setState(274);//806
			_errHandler->sync(this, ctx);
			_la = _input->LA(1);
		}
		setState(276);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::Array)
		{
			setState(275);//958
			match(CMinusEqualsMinus1Revision0Parser::Array,ctx);
		}
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext> CMinusEqualsMinus1Revision0Parser::parsetypeSpecifier()
{
	typeSpecifier();
	auto result = std::unique_ptr<TypeSpecifierContext>(dynamic_cast<TypeSpecifierContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- GenericUsageContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::GenericUsageContext::GenericUsageContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::GenericUsageContext::Less()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Less, 0);
}

std::vector<CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext *> CMinusEqualsMinus1Revision0Parser::GenericUsageContext::typeSpecifier()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext* CMinusEqualsMinus1Revision0Parser::GenericUsageContext::typeSpecifier(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext>(i);//1183
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::GenericUsageContext::Greater()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Greater, 0);
}

std::vector<tree::TerminalNode *> CMinusEqualsMinus1Revision0Parser::GenericUsageContext::Comma()
{
	return getTokens(CMinusEqualsMinus1Revision0Parser::Comma);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::GenericUsageContext::Comma(size_t i)
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Comma, i);
}


size_t CMinusEqualsMinus1Revision0Parser::GenericUsageContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleGenericUsage;//688
}

void CMinusEqualsMinus1Revision0Parser::GenericUsageContext::copyFrom(GenericUsageContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::GenericUsageContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<GenericUsageContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::GenericUsageContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::GenericUsageContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::GenericUsageContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitGenericUsage(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::GenericUsageContext* CMinusEqualsMinus1Revision0Parser::genericUsage( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<GenericUsageContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 36, CMinusEqualsMinus1Revision0Parser::RuleGenericUsage);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(278);//958
		match(CMinusEqualsMinus1Revision0Parser::Less,ctx);
		setState(279); //951
		typeSpecifier(ctx);
		setState(284);//800
		_errHandler->sync(this, ctx);
		_la = _input->LA(1);
		while (_la == CMinusEqualsMinus1Revision0Parser::Comma)
		{
			setState(280);//958
			match(CMinusEqualsMinus1Revision0Parser::Comma,ctx);
			setState(281); //951
			typeSpecifier(ctx);
			setState(286);//806
			_errHandler->sync(this, ctx);
			_la = _input->LA(1);
		}
		setState(287);//958
		match(CMinusEqualsMinus1Revision0Parser::Greater,ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::GenericUsageContext> CMinusEqualsMinus1Revision0Parser::parsegenericUsage()
{
	genericUsage();
	auto result = std::unique_ptr<GenericUsageContext>(dynamic_cast<GenericUsageContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- FunctionBodyContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::FunctionBodyContext::FunctionBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::FunctionBodyContext::OpenBracket()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::OpenBracket, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::FunctionBodyContext::CloseBracket()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::CloseBracket, 0);
}

std::vector<CMinusEqualsMinus1Revision0Parser::StatementContext *> CMinusEqualsMinus1Revision0Parser::FunctionBodyContext::statement()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::StatementContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::StatementContext* CMinusEqualsMinus1Revision0Parser::FunctionBodyContext::statement(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::StatementContext>(i);//1183
}


size_t CMinusEqualsMinus1Revision0Parser::FunctionBodyContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleFunctionBody;//688
}

void CMinusEqualsMinus1Revision0Parser::FunctionBodyContext::copyFrom(FunctionBodyContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::FunctionBodyContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<FunctionBodyContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::FunctionBodyContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::FunctionBodyContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::FunctionBodyContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitFunctionBody(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::FunctionBodyContext* CMinusEqualsMinus1Revision0Parser::functionBody( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<FunctionBodyContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 38, CMinusEqualsMinus1Revision0Parser::RuleFunctionBody);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(289);//958
		match(CMinusEqualsMinus1Revision0Parser::OpenBracket,ctx);
		setState(293);//800
		_errHandler->sync(this, ctx);
		_la = _input->LA(1);
		while ((((_la & ~ 0x3fULL) == 0) &&
			((1ULL << _la) & ((1ULL << CMinusEqualsMinus1Revision0Parser::T__12)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__13)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__14)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__16)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__18)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__19)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__20)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__21)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__22)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__23)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__24)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__25)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__26)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::ParamOpen)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::LogicalUnaryOperator))) != 0) || ((((_la - 78) & ~ 0x3fULL) == 0) &&
			((1ULL << (_la - 78)) & ((1ULL << (CMinusEqualsMinus1Revision0Parser::Throw - 78))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::New - 78))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::SimpleIdentifier - 78))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::IntegerLiteral - 78))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::STRING - 78)))) != 0))
		{
			setState(290); //951
			statement(ctx);
			setState(295);//806
			_errHandler->sync(this, ctx);
			_la = _input->LA(1);
		}
		setState(296);//958
		match(CMinusEqualsMinus1Revision0Parser::CloseBracket,ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::FunctionBodyContext> CMinusEqualsMinus1Revision0Parser::parsefunctionBody()
{
	functionBody();
	auto result = std::unique_ptr<FunctionBodyContext>(dynamic_cast<FunctionBodyContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- FunctionNameContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::FunctionNameContext::FunctionNameContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::IdentifierContext* CMinusEqualsMinus1Revision0Parser::FunctionNameContext::identifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::IdentifierContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::SpecialFunctionIdentifierContext* CMinusEqualsMinus1Revision0Parser::FunctionNameContext::specialFunctionIdentifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::SpecialFunctionIdentifierContext>(0);//1165
}


size_t CMinusEqualsMinus1Revision0Parser::FunctionNameContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleFunctionName;//688
}

void CMinusEqualsMinus1Revision0Parser::FunctionNameContext::copyFrom(FunctionNameContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::FunctionNameContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<FunctionNameContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::FunctionNameContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::FunctionNameContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::FunctionNameContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitFunctionName(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::FunctionNameContext* CMinusEqualsMinus1Revision0Parser::functionName( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<FunctionNameContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 40, CMinusEqualsMinus1Revision0Parser::RuleFunctionName);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		setState(300);//750
		_errHandler->sync(this, ctx);
		switch (_input->LA(1))
		{
			case CMinusEqualsMinus1Revision0Parser::T__21:
			case CMinusEqualsMinus1Revision0Parser::T__22:
			case CMinusEqualsMinus1Revision0Parser::T__23:
			case CMinusEqualsMinus1Revision0Parser::T__24:
			case CMinusEqualsMinus1Revision0Parser::T__25:
			case CMinusEqualsMinus1Revision0Parser::T__26:
			case CMinusEqualsMinus1Revision0Parser::SimpleIdentifier:
			{
				enterOuterAlt(ctx, 1);
				setState(298); //951
				identifier(ctx);
				break;
			}

			case CMinusEqualsMinus1Revision0Parser::Operator:
			{
				enterOuterAlt(ctx, 2);
				setState(299); //951
				specialFunctionIdentifier(ctx);
				break;
			}

		default:
			throw NoViableAltException(this, ctx);
		}
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::FunctionNameContext> CMinusEqualsMinus1Revision0Parser::parsefunctionName()
{
	functionName();
	auto result = std::unique_ptr<FunctionNameContext>(dynamic_cast<FunctionNameContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- SpecialFunctionIdentifierContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::SpecialFunctionIdentifierContext::SpecialFunctionIdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::SpecialFunctionIdentifierContext::Operator()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Operator, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::SpecialFunctionIdentifierContext::New()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::New, 0);
}

CMinusEqualsMinus1Revision0Parser::BinaryOperatorContext* CMinusEqualsMinus1Revision0Parser::SpecialFunctionIdentifierContext::binaryOperator()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::BinaryOperatorContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::SpecialFunctionIdentifierContext::Unique()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Unique, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::SpecialFunctionIdentifierContext::Shared()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Shared, 0);
}


size_t CMinusEqualsMinus1Revision0Parser::SpecialFunctionIdentifierContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleSpecialFunctionIdentifier;//688
}

void CMinusEqualsMinus1Revision0Parser::SpecialFunctionIdentifierContext::copyFrom(SpecialFunctionIdentifierContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::SpecialFunctionIdentifierContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<SpecialFunctionIdentifierContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::SpecialFunctionIdentifierContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::SpecialFunctionIdentifierContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::SpecialFunctionIdentifierContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitSpecialFunctionIdentifier(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::SpecialFunctionIdentifierContext* CMinusEqualsMinus1Revision0Parser::specialFunctionIdentifier( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<SpecialFunctionIdentifierContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 42, CMinusEqualsMinus1Revision0Parser::RuleSpecialFunctionIdentifier);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(302);//958
		match(CMinusEqualsMinus1Revision0Parser::Operator,ctx);
		setState(306);//750
		_errHandler->sync(this, ctx);
		switch (_input->LA(1))
		{
			case CMinusEqualsMinus1Revision0Parser::New:
			{
				setState(303);//958
				match(CMinusEqualsMinus1Revision0Parser::New,ctx);
				setState(304);//970
				_la = _input->LA(1);
				if (!(_la == CMinusEqualsMinus1Revision0Parser::Shared

				|| _la == CMinusEqualsMinus1Revision0Parser::Unique))
				{
				_errHandler->recoverInline(this, ctx);
				}
				else
				{
					_errHandler->reportMatch(this);
					consume(ctx);
				}
				break;
			}

			case CMinusEqualsMinus1Revision0Parser::ParamOpen:
			case CMinusEqualsMinus1Revision0Parser::Equal:
			case CMinusEqualsMinus1Revision0Parser::NotEqual:
			case CMinusEqualsMinus1Revision0Parser::Plus:
			case CMinusEqualsMinus1Revision0Parser::Minus:
			case CMinusEqualsMinus1Revision0Parser::Star:
			case CMinusEqualsMinus1Revision0Parser::PlusEquals:
			case CMinusEqualsMinus1Revision0Parser::MinusEquals:
			case CMinusEqualsMinus1Revision0Parser::MultiplyEquals:
			case CMinusEqualsMinus1Revision0Parser::DivideEquals:
			case CMinusEqualsMinus1Revision0Parser::GreaterEqual:
			case CMinusEqualsMinus1Revision0Parser::Greater:
			case CMinusEqualsMinus1Revision0Parser::Less:
			case CMinusEqualsMinus1Revision0Parser::LessEqual:
			case CMinusEqualsMinus1Revision0Parser::Or:
			case CMinusEqualsMinus1Revision0Parser::And:
			case CMinusEqualsMinus1Revision0Parser::Xor:
			{
				setState(305); //951
				binaryOperator(ctx);
				break;
			}

		default:
			throw NoViableAltException(this, ctx);
		}
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::SpecialFunctionIdentifierContext> CMinusEqualsMinus1Revision0Parser::parsespecialFunctionIdentifier()
{
	specialFunctionIdentifier();
	auto result = std::unique_ptr<SpecialFunctionIdentifierContext>(dynamic_cast<SpecialFunctionIdentifierContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- CompoundStatementContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::CompoundStatementContext::CompoundStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::CompoundStatementContext::OpenBracket()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::OpenBracket, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::CompoundStatementContext::CloseBracket()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::CloseBracket, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::CompoundStatementContext::Unsafe()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Unsafe, 0);
}

std::vector<CMinusEqualsMinus1Revision0Parser::StatementContext *> CMinusEqualsMinus1Revision0Parser::CompoundStatementContext::statement()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::StatementContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::StatementContext* CMinusEqualsMinus1Revision0Parser::CompoundStatementContext::statement(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::StatementContext>(i);//1183
}


size_t CMinusEqualsMinus1Revision0Parser::CompoundStatementContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleCompoundStatement;//688
}

void CMinusEqualsMinus1Revision0Parser::CompoundStatementContext::copyFrom(CompoundStatementContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::CompoundStatementContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<CompoundStatementContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::CompoundStatementContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::CompoundStatementContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::CompoundStatementContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitCompoundStatement(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::CompoundStatementContext* CMinusEqualsMinus1Revision0Parser::compoundStatement( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<CompoundStatementContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 44, CMinusEqualsMinus1Revision0Parser::RuleCompoundStatement);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		setState(320);//750
		_errHandler->sync(this, ctx);
		switch (_input->LA(1))
		{
			case CMinusEqualsMinus1Revision0Parser::OpenBracket:
			case CMinusEqualsMinus1Revision0Parser::Unsafe:
			{
				enterOuterAlt(ctx, 1);
				setState(309);//788
				_errHandler->sync(this, ctx);

				_la = _input->LA(1);
				if (_la == CMinusEqualsMinus1Revision0Parser::Unsafe)
				{
					setState(308);//958
					match(CMinusEqualsMinus1Revision0Parser::Unsafe,ctx);
				}
				setState(311);//958
				match(CMinusEqualsMinus1Revision0Parser::OpenBracket,ctx);
				setState(315);//800
				_errHandler->sync(this, ctx);
				_la = _input->LA(1);
				while ((((_la & ~ 0x3fULL) == 0) &&
					((1ULL << _la) & ((1ULL << CMinusEqualsMinus1Revision0Parser::T__12)
					| (1ULL << CMinusEqualsMinus1Revision0Parser::T__13)
					| (1ULL << CMinusEqualsMinus1Revision0Parser::T__14)
					| (1ULL << CMinusEqualsMinus1Revision0Parser::T__16)
					| (1ULL << CMinusEqualsMinus1Revision0Parser::T__18)
					| (1ULL << CMinusEqualsMinus1Revision0Parser::T__19)
					| (1ULL << CMinusEqualsMinus1Revision0Parser::T__20)
					| (1ULL << CMinusEqualsMinus1Revision0Parser::T__21)
					| (1ULL << CMinusEqualsMinus1Revision0Parser::T__22)
					| (1ULL << CMinusEqualsMinus1Revision0Parser::T__23)
					| (1ULL << CMinusEqualsMinus1Revision0Parser::T__24)
					| (1ULL << CMinusEqualsMinus1Revision0Parser::T__25)
					| (1ULL << CMinusEqualsMinus1Revision0Parser::T__26)
					| (1ULL << CMinusEqualsMinus1Revision0Parser::ParamOpen)
					| (1ULL << CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN)
					| (1ULL << CMinusEqualsMinus1Revision0Parser::LogicalUnaryOperator))) != 0) || ((((_la - 78) & ~ 0x3fULL) == 0) &&
					((1ULL << (_la - 78)) & ((1ULL << (CMinusEqualsMinus1Revision0Parser::Throw - 78))
					| (1ULL << (CMinusEqualsMinus1Revision0Parser::New - 78))
					| (1ULL << (CMinusEqualsMinus1Revision0Parser::SimpleIdentifier - 78))
					| (1ULL << (CMinusEqualsMinus1Revision0Parser::IntegerLiteral - 78))
					| (1ULL << (CMinusEqualsMinus1Revision0Parser::STRING - 78)))) != 0))
				{
					setState(312); //951
					statement(ctx);
					setState(317);//806
					_errHandler->sync(this, ctx);
					_la = _input->LA(1);
				}
				setState(318);//958
				match(CMinusEqualsMinus1Revision0Parser::CloseBracket,ctx);
				break;
			}

			case CMinusEqualsMinus1Revision0Parser::T__12:
			case CMinusEqualsMinus1Revision0Parser::T__13:
			case CMinusEqualsMinus1Revision0Parser::T__14:
			case CMinusEqualsMinus1Revision0Parser::T__16:
			case CMinusEqualsMinus1Revision0Parser::T__18:
			case CMinusEqualsMinus1Revision0Parser::T__19:
			case CMinusEqualsMinus1Revision0Parser::T__20:
			case CMinusEqualsMinus1Revision0Parser::T__21:
			case CMinusEqualsMinus1Revision0Parser::T__22:
			case CMinusEqualsMinus1Revision0Parser::T__23:
			case CMinusEqualsMinus1Revision0Parser::T__24:
			case CMinusEqualsMinus1Revision0Parser::T__25:
			case CMinusEqualsMinus1Revision0Parser::T__26:
			case CMinusEqualsMinus1Revision0Parser::ParamOpen:
			case CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN:
			case CMinusEqualsMinus1Revision0Parser::LogicalUnaryOperator:
			case CMinusEqualsMinus1Revision0Parser::Throw:
			case CMinusEqualsMinus1Revision0Parser::New:
			case CMinusEqualsMinus1Revision0Parser::SimpleIdentifier:
			case CMinusEqualsMinus1Revision0Parser::IntegerLiteral:
			case CMinusEqualsMinus1Revision0Parser::STRING:
			{
				enterOuterAlt(ctx, 2);
				setState(319); //951
				statement(ctx);
				break;
			}

		default:
			throw NoViableAltException(this, ctx);
		}
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::CompoundStatementContext> CMinusEqualsMinus1Revision0Parser::parsecompoundStatement()
{
	compoundStatement();
	auto result = std::unique_ptr<CompoundStatementContext>(dynamic_cast<CompoundStatementContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- StatementContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::StatementContext::StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::IfStatementContext* CMinusEqualsMinus1Revision0Parser::StatementContext::ifStatement()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::IfStatementContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::LoopStatementContext* CMinusEqualsMinus1Revision0Parser::StatementContext::loopStatement()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::LoopStatementContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext* CMinusEqualsMinus1Revision0Parser::StatementContext::assigmentStatement()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::StatementContext::SemiColon()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::SemiColon, 0);
}

CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext* CMinusEqualsMinus1Revision0Parser::StatementContext::variableDeclarationStatement()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::ReturnStatementContext* CMinusEqualsMinus1Revision0Parser::StatementContext::returnStatement()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ReturnStatementContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::FunctionCallStatementContext* CMinusEqualsMinus1Revision0Parser::StatementContext::functionCallStatement()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::FunctionCallStatementContext>(0);//1165
}


size_t CMinusEqualsMinus1Revision0Parser::StatementContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleStatement;//688
}

void CMinusEqualsMinus1Revision0Parser::StatementContext::copyFrom(StatementContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::StatementContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<StatementContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::StatementContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::StatementContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::StatementContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitStatement(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::StatementContext* CMinusEqualsMinus1Revision0Parser::statement( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<StatementContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 46, CMinusEqualsMinus1Revision0Parser::RuleStatement);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		setState(336);//830
		_errHandler->sync(this, ctx);
		switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, ctx))
		{
		case 1:
		{
			enterOuterAlt(ctx, 1);
			setState(322); //951
			ifStatement(ctx);
			break;
		}

		case 2:
		{
			enterOuterAlt(ctx, 2);
			setState(323); //951
			loopStatement(ctx);
			break;
		}

		case 3:
		{
			enterOuterAlt(ctx, 3);
			setState(324); //951
			assigmentStatement(ctx);
			setState(325);//958
			match(CMinusEqualsMinus1Revision0Parser::SemiColon,ctx);
			break;
		}

		case 4:
		{
			enterOuterAlt(ctx, 4);
			setState(327); //951
			variableDeclarationStatement(ctx);
			setState(328);//958
			match(CMinusEqualsMinus1Revision0Parser::SemiColon,ctx);
			break;
		}

		case 5:
		{
			enterOuterAlt(ctx, 5);
			setState(330); //951
			returnStatement(ctx);
			setState(331);//958
			match(CMinusEqualsMinus1Revision0Parser::SemiColon,ctx);
			break;
		}

		case 6:
		{
			enterOuterAlt(ctx, 6);
			setState(333); //951
			functionCallStatement(ctx);
			setState(334);//958
			match(CMinusEqualsMinus1Revision0Parser::SemiColon,ctx);
			break;
		}

		}
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::StatementContext> CMinusEqualsMinus1Revision0Parser::parsestatement()
{
	statement();
	auto result = std::unique_ptr<StatementContext>(dynamic_cast<StatementContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- FunctionCallStatementContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::FunctionCallStatementContext::FunctionCallStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::FunctionCallContext* CMinusEqualsMinus1Revision0Parser::FunctionCallStatementContext::functionCall()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::FunctionCallContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::ExpressionContext* CMinusEqualsMinus1Revision0Parser::FunctionCallStatementContext::expression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ExpressionContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::FunctionCallStatementContext::Period()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Period, 0);
}


size_t CMinusEqualsMinus1Revision0Parser::FunctionCallStatementContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleFunctionCallStatement;//688
}

void CMinusEqualsMinus1Revision0Parser::FunctionCallStatementContext::copyFrom(FunctionCallStatementContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::FunctionCallStatementContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<FunctionCallStatementContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::FunctionCallStatementContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::FunctionCallStatementContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::FunctionCallStatementContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitFunctionCallStatement(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::FunctionCallStatementContext* CMinusEqualsMinus1Revision0Parser::functionCallStatement( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<FunctionCallStatementContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 48, CMinusEqualsMinus1Revision0Parser::RuleFunctionCallStatement);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		setState(343);//830
		_errHandler->sync(this, ctx);
		switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, ctx))
		{
		case 1:
		{
			enterOuterAlt(ctx, 1);
			setState(338); //951
			functionCall(ctx);
			break;
		}

		case 2:
		{
			enterOuterAlt(ctx, 2);
			setState(339); //951
			expression(0,ctx);
			setState(340);//958
			match(CMinusEqualsMinus1Revision0Parser::Period,ctx);
			setState(341); //951
			functionCall(ctx);
			break;
		}

		}
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::FunctionCallStatementContext> CMinusEqualsMinus1Revision0Parser::parsefunctionCallStatement()
{
	functionCallStatement();
	auto result = std::unique_ptr<FunctionCallStatementContext>(dynamic_cast<FunctionCallStatementContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- ReturnStatementContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::ReturnStatementContext::ReturnStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::ExpressionContext* CMinusEqualsMinus1Revision0Parser::ReturnStatementContext::expression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ExpressionContext>(0);//1165
}


size_t CMinusEqualsMinus1Revision0Parser::ReturnStatementContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleReturnStatement;//688
}

void CMinusEqualsMinus1Revision0Parser::ReturnStatementContext::copyFrom(ReturnStatementContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::ReturnStatementContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<ReturnStatementContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::ReturnStatementContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::ReturnStatementContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitReturnStatement(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::ReturnStatementContext* CMinusEqualsMinus1Revision0Parser::returnStatement( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<ReturnStatementContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 50, CMinusEqualsMinus1Revision0Parser::RuleReturnStatement);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(345);//958
		match(CMinusEqualsMinus1Revision0Parser::T__12,ctx);
		setState(346); //951
		expression(0,ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::ReturnStatementContext> CMinusEqualsMinus1Revision0Parser::parsereturnStatement()
{
	returnStatement();
	auto result = std::unique_ptr<ReturnStatementContext>(dynamic_cast<ReturnStatementContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- VariableDeclarationStatementContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext::VariableDeclarationStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::IdentifierContext* CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext::identifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::IdentifierContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext* CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext::attributeSequence()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext* CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext::typeSpecifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext::Asssigment()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Asssigment, 0);
}

CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext* CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext::functionCallParameter()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext>(0);//1165
}


size_t CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleVariableDeclarationStatement;//688
}

void CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext::copyFrom(VariableDeclarationStatementContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<VariableDeclarationStatementContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitVariableDeclarationStatement(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext* CMinusEqualsMinus1Revision0Parser::variableDeclarationStatement( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<VariableDeclarationStatementContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 52, CMinusEqualsMinus1Revision0Parser::RuleVariableDeclarationStatement);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(349);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN)
		{
			setState(348); //951
			attributeSequence(ctx);
		}
		setState(351);//958
		match(CMinusEqualsMinus1Revision0Parser::T__13,ctx);
		setState(352); //951
		identifier(ctx);
		setState(355);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::T__7)
		{
			setState(353);//958
			match(CMinusEqualsMinus1Revision0Parser::T__7,ctx);
			setState(354); //951
			typeSpecifier(ctx);
		}
		setState(359);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::Asssigment)
		{
			setState(357);//958
			match(CMinusEqualsMinus1Revision0Parser::Asssigment,ctx);
			setState(358); //951
			functionCallParameter(ctx);
		}
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext> CMinusEqualsMinus1Revision0Parser::parsevariableDeclarationStatement()
{
	variableDeclarationStatement();
	auto result = std::unique_ptr<VariableDeclarationStatementContext>(dynamic_cast<VariableDeclarationStatementContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- IfStatementContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::IfStatementContext::IfStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::IfStatementContext::ParamOpen()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ParamOpen, 0);
}

CMinusEqualsMinus1Revision0Parser::ExpressionContext* CMinusEqualsMinus1Revision0Parser::IfStatementContext::expression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ExpressionContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::IfStatementContext::ParamClose()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ParamClose, 0);
}

std::vector<CMinusEqualsMinus1Revision0Parser::CompoundStatementContext *> CMinusEqualsMinus1Revision0Parser::IfStatementContext::compoundStatement()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::CompoundStatementContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::CompoundStatementContext* CMinusEqualsMinus1Revision0Parser::IfStatementContext::compoundStatement(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::CompoundStatementContext>(i);//1183
}


size_t CMinusEqualsMinus1Revision0Parser::IfStatementContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleIfStatement;//688
}

void CMinusEqualsMinus1Revision0Parser::IfStatementContext::copyFrom(IfStatementContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::IfStatementContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<IfStatementContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::IfStatementContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::IfStatementContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitIfStatement(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::IfStatementContext* CMinusEqualsMinus1Revision0Parser::ifStatement( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<IfStatementContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 54, CMinusEqualsMinus1Revision0Parser::RuleIfStatement);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(361);//958
		match(CMinusEqualsMinus1Revision0Parser::T__14,ctx);
		setState(362);//958
		match(CMinusEqualsMinus1Revision0Parser::ParamOpen,ctx);
		setState(363); //951
		expression(0,ctx);
		setState(364);//958
		match(CMinusEqualsMinus1Revision0Parser::ParamClose,ctx);
		setState(365); //951
		compoundStatement(ctx);
		setState(368);//848
		_errHandler->sync(this, ctx);

		switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, ctx))
		{
		case 1:
		{
			setState(366);//958
			match(CMinusEqualsMinus1Revision0Parser::T__15,ctx);
			setState(367); //951
			compoundStatement(ctx);
			break;
		}

		}
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::IfStatementContext> CMinusEqualsMinus1Revision0Parser::parseifStatement()
{
	ifStatement();
	auto result = std::unique_ptr<IfStatementContext>(dynamic_cast<IfStatementContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- LoopStatementContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::LoopStatementContext::LoopStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::RangeForStatementContext* CMinusEqualsMinus1Revision0Parser::LoopStatementContext::rangeForStatement()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::RangeForStatementContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::ForStatementContext* CMinusEqualsMinus1Revision0Parser::LoopStatementContext::forStatement()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ForStatementContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::WhileStatementContext* CMinusEqualsMinus1Revision0Parser::LoopStatementContext::whileStatement()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::WhileStatementContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::DoWhileStatementContext* CMinusEqualsMinus1Revision0Parser::LoopStatementContext::doWhileStatement()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::DoWhileStatementContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::InfiniteLoopStatementContext* CMinusEqualsMinus1Revision0Parser::LoopStatementContext::infiniteLoopStatement()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::InfiniteLoopStatementContext>(0);//1165
}


size_t CMinusEqualsMinus1Revision0Parser::LoopStatementContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleLoopStatement;//688
}

void CMinusEqualsMinus1Revision0Parser::LoopStatementContext::copyFrom(LoopStatementContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::LoopStatementContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<LoopStatementContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::LoopStatementContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::LoopStatementContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::LoopStatementContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitLoopStatement(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::LoopStatementContext* CMinusEqualsMinus1Revision0Parser::loopStatement( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<LoopStatementContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 56, CMinusEqualsMinus1Revision0Parser::RuleLoopStatement);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		setState(375);//830
		_errHandler->sync(this, ctx);
		switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, ctx))
		{
		case 1:
		{
			enterOuterAlt(ctx, 1);
			setState(370); //951
			rangeForStatement(ctx);
			break;
		}

		case 2:
		{
			enterOuterAlt(ctx, 2);
			setState(371); //951
			forStatement(ctx);
			break;
		}

		case 3:
		{
			enterOuterAlt(ctx, 3);
			setState(372); //951
			whileStatement(ctx);
			break;
		}

		case 4:
		{
			enterOuterAlt(ctx, 4);
			setState(373); //951
			doWhileStatement(ctx);
			break;
		}

		case 5:
		{
			enterOuterAlt(ctx, 5);
			setState(374); //951
			infiniteLoopStatement(ctx);
			break;
		}

		}
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::LoopStatementContext> CMinusEqualsMinus1Revision0Parser::parseloopStatement()
{
	loopStatement();
	auto result = std::unique_ptr<LoopStatementContext>(dynamic_cast<LoopStatementContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- RangeForStatementContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::RangeForStatementContext::RangeForStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::RangeForStatementContext::ParamOpen()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ParamOpen, 0);
}

CMinusEqualsMinus1Revision0Parser::IdentifierContext* CMinusEqualsMinus1Revision0Parser::RangeForStatementContext::identifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::IdentifierContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::ExpressionContext* CMinusEqualsMinus1Revision0Parser::RangeForStatementContext::expression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ExpressionContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::RangeForStatementContext::ParamClose()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ParamClose, 0);
}

CMinusEqualsMinus1Revision0Parser::CompoundStatementContext* CMinusEqualsMinus1Revision0Parser::RangeForStatementContext::compoundStatement()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::CompoundStatementContext>(0);//1165
}


size_t CMinusEqualsMinus1Revision0Parser::RangeForStatementContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleRangeForStatement;//688
}

void CMinusEqualsMinus1Revision0Parser::RangeForStatementContext::copyFrom(RangeForStatementContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::RangeForStatementContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<RangeForStatementContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::RangeForStatementContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::RangeForStatementContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::RangeForStatementContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitRangeForStatement(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::RangeForStatementContext* CMinusEqualsMinus1Revision0Parser::rangeForStatement( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<RangeForStatementContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 58, CMinusEqualsMinus1Revision0Parser::RuleRangeForStatement);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(377);//958
		match(CMinusEqualsMinus1Revision0Parser::T__16,ctx);
		setState(378);//958
		match(CMinusEqualsMinus1Revision0Parser::ParamOpen,ctx);
		setState(379); //951
		identifier(ctx);
		setState(380);//958
		match(CMinusEqualsMinus1Revision0Parser::T__17,ctx);
		setState(381); //951
		expression(0,ctx);
		setState(382);//958
		match(CMinusEqualsMinus1Revision0Parser::ParamClose,ctx);
		setState(383); //951
		compoundStatement(ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::RangeForStatementContext> CMinusEqualsMinus1Revision0Parser::parserangeForStatement()
{
	rangeForStatement();
	auto result = std::unique_ptr<RangeForStatementContext>(dynamic_cast<RangeForStatementContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- ForStatementContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::ForStatementContext::ForStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ForStatementContext::ParamOpen()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ParamOpen, 0);
}

std::vector<CMinusEqualsMinus1Revision0Parser::ExpressionContext *> CMinusEqualsMinus1Revision0Parser::ForStatementContext::expression()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::ExpressionContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::ExpressionContext* CMinusEqualsMinus1Revision0Parser::ForStatementContext::expression(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ExpressionContext>(i);//1183
}

std::vector<tree::TerminalNode *> CMinusEqualsMinus1Revision0Parser::ForStatementContext::SemiColon()
{
	return getTokens(CMinusEqualsMinus1Revision0Parser::SemiColon);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ForStatementContext::SemiColon(size_t i)
{
	return getToken(CMinusEqualsMinus1Revision0Parser::SemiColon, i);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ForStatementContext::ParamClose()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ParamClose, 0);
}

CMinusEqualsMinus1Revision0Parser::CompoundStatementContext* CMinusEqualsMinus1Revision0Parser::ForStatementContext::compoundStatement()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::CompoundStatementContext>(0);//1165
}


size_t CMinusEqualsMinus1Revision0Parser::ForStatementContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleForStatement;//688
}

void CMinusEqualsMinus1Revision0Parser::ForStatementContext::copyFrom(ForStatementContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::ForStatementContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<ForStatementContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::ForStatementContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::ForStatementContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitForStatement(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::ForStatementContext* CMinusEqualsMinus1Revision0Parser::forStatement( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<ForStatementContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 60, CMinusEqualsMinus1Revision0Parser::RuleForStatement);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(385);//958
		match(CMinusEqualsMinus1Revision0Parser::T__16,ctx);
		setState(386);//958
		match(CMinusEqualsMinus1Revision0Parser::ParamOpen,ctx);
		setState(387); //951
		expression(0,ctx);
		setState(388);//958
		match(CMinusEqualsMinus1Revision0Parser::SemiColon,ctx);
		setState(389); //951
		expression(0,ctx);
		setState(390);//958
		match(CMinusEqualsMinus1Revision0Parser::SemiColon,ctx);
		setState(391); //951
		expression(0,ctx);
		setState(392);//958
		match(CMinusEqualsMinus1Revision0Parser::ParamClose,ctx);
		setState(393); //951
		compoundStatement(ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::ForStatementContext> CMinusEqualsMinus1Revision0Parser::parseforStatement()
{
	forStatement();
	auto result = std::unique_ptr<ForStatementContext>(dynamic_cast<ForStatementContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- WhileStatementContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::WhileStatementContext::WhileStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::WhileHeaderContext* CMinusEqualsMinus1Revision0Parser::WhileStatementContext::whileHeader()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::WhileHeaderContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::CompoundStatementContext* CMinusEqualsMinus1Revision0Parser::WhileStatementContext::compoundStatement()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::CompoundStatementContext>(0);//1165
}


size_t CMinusEqualsMinus1Revision0Parser::WhileStatementContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleWhileStatement;//688
}

void CMinusEqualsMinus1Revision0Parser::WhileStatementContext::copyFrom(WhileStatementContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::WhileStatementContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<WhileStatementContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::WhileStatementContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::WhileStatementContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitWhileStatement(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::WhileStatementContext* CMinusEqualsMinus1Revision0Parser::whileStatement( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<WhileStatementContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 62, CMinusEqualsMinus1Revision0Parser::RuleWhileStatement);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(395); //951
		whileHeader(ctx);
		setState(396); //951
		compoundStatement(ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::WhileStatementContext> CMinusEqualsMinus1Revision0Parser::parsewhileStatement()
{
	whileStatement();
	auto result = std::unique_ptr<WhileStatementContext>(dynamic_cast<WhileStatementContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- DoWhileStatementContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::DoWhileStatementContext::DoWhileStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::CompoundStatementContext* CMinusEqualsMinus1Revision0Parser::DoWhileStatementContext::compoundStatement()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::CompoundStatementContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::WhileHeaderContext* CMinusEqualsMinus1Revision0Parser::DoWhileStatementContext::whileHeader()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::WhileHeaderContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::DoWhileStatementContext::SemiColon()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::SemiColon, 0);
}


size_t CMinusEqualsMinus1Revision0Parser::DoWhileStatementContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleDoWhileStatement;//688
}

void CMinusEqualsMinus1Revision0Parser::DoWhileStatementContext::copyFrom(DoWhileStatementContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::DoWhileStatementContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<DoWhileStatementContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::DoWhileStatementContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::DoWhileStatementContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::DoWhileStatementContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitDoWhileStatement(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::DoWhileStatementContext* CMinusEqualsMinus1Revision0Parser::doWhileStatement( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<DoWhileStatementContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 64, CMinusEqualsMinus1Revision0Parser::RuleDoWhileStatement);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(398);//958
		match(CMinusEqualsMinus1Revision0Parser::T__18,ctx);
		setState(399); //951
		compoundStatement(ctx);
		setState(400); //951
		whileHeader(ctx);
		setState(401);//958
		match(CMinusEqualsMinus1Revision0Parser::SemiColon,ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::DoWhileStatementContext> CMinusEqualsMinus1Revision0Parser::parsedoWhileStatement()
{
	doWhileStatement();
	auto result = std::unique_ptr<DoWhileStatementContext>(dynamic_cast<DoWhileStatementContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- WhileHeaderContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::WhileHeaderContext::WhileHeaderContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::WhileHeaderContext::ParamOpen()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ParamOpen, 0);
}

CMinusEqualsMinus1Revision0Parser::ExpressionContext* CMinusEqualsMinus1Revision0Parser::WhileHeaderContext::expression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ExpressionContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::WhileHeaderContext::ParamClose()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ParamClose, 0);
}


size_t CMinusEqualsMinus1Revision0Parser::WhileHeaderContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleWhileHeader;//688
}

void CMinusEqualsMinus1Revision0Parser::WhileHeaderContext::copyFrom(WhileHeaderContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::WhileHeaderContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<WhileHeaderContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::WhileHeaderContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::WhileHeaderContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::WhileHeaderContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitWhileHeader(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::WhileHeaderContext* CMinusEqualsMinus1Revision0Parser::whileHeader( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<WhileHeaderContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 66, CMinusEqualsMinus1Revision0Parser::RuleWhileHeader);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(403);//958
		match(CMinusEqualsMinus1Revision0Parser::T__19,ctx);
		setState(404);//958
		match(CMinusEqualsMinus1Revision0Parser::ParamOpen,ctx);
		setState(405); //951
		expression(0,ctx);
		setState(406);//958
		match(CMinusEqualsMinus1Revision0Parser::ParamClose,ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::WhileHeaderContext> CMinusEqualsMinus1Revision0Parser::parsewhileHeader()
{
	whileHeader();
	auto result = std::unique_ptr<WhileHeaderContext>(dynamic_cast<WhileHeaderContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- InfiniteLoopStatementContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::InfiniteLoopStatementContext::InfiniteLoopStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::CompoundStatementContext* CMinusEqualsMinus1Revision0Parser::InfiniteLoopStatementContext::compoundStatement()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::CompoundStatementContext>(0);//1165
}


size_t CMinusEqualsMinus1Revision0Parser::InfiniteLoopStatementContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleInfiniteLoopStatement;//688
}

void CMinusEqualsMinus1Revision0Parser::InfiniteLoopStatementContext::copyFrom(InfiniteLoopStatementContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::InfiniteLoopStatementContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<InfiniteLoopStatementContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::InfiniteLoopStatementContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::InfiniteLoopStatementContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::InfiniteLoopStatementContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitInfiniteLoopStatement(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::InfiniteLoopStatementContext* CMinusEqualsMinus1Revision0Parser::infiniteLoopStatement( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<InfiniteLoopStatementContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 68, CMinusEqualsMinus1Revision0Parser::RuleInfiniteLoopStatement);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(408);//958
		match(CMinusEqualsMinus1Revision0Parser::T__20,ctx);
		setState(409); //951
		compoundStatement(ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::InfiniteLoopStatementContext> CMinusEqualsMinus1Revision0Parser::parseinfiniteLoopStatement()
{
	infiniteLoopStatement();
	auto result = std::unique_ptr<InfiniteLoopStatementContext>(dynamic_cast<InfiniteLoopStatementContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- FunctionCallContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::FunctionCallContext::FunctionCallContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::IdentifierContext* CMinusEqualsMinus1Revision0Parser::FunctionCallContext::identifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::IdentifierContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::FunctionCallContext::ParamOpen()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ParamOpen, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::FunctionCallContext::ParamClose()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ParamClose, 0);
}

CMinusEqualsMinus1Revision0Parser::GenericUsageContext* CMinusEqualsMinus1Revision0Parser::FunctionCallContext::genericUsage()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::GenericUsageContext>(0);//1165
}

std::vector<CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext *> CMinusEqualsMinus1Revision0Parser::FunctionCallContext::functionCallParameter()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext* CMinusEqualsMinus1Revision0Parser::FunctionCallContext::functionCallParameter(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext>(i);//1183
}

std::vector<tree::TerminalNode *> CMinusEqualsMinus1Revision0Parser::FunctionCallContext::Comma()
{
	return getTokens(CMinusEqualsMinus1Revision0Parser::Comma);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::FunctionCallContext::Comma(size_t i)
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Comma, i);
}


size_t CMinusEqualsMinus1Revision0Parser::FunctionCallContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleFunctionCall;//688
}

void CMinusEqualsMinus1Revision0Parser::FunctionCallContext::copyFrom(FunctionCallContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::FunctionCallContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<FunctionCallContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::FunctionCallContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::FunctionCallContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitFunctionCall(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::FunctionCallContext* CMinusEqualsMinus1Revision0Parser::functionCall( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<FunctionCallContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 70, CMinusEqualsMinus1Revision0Parser::RuleFunctionCall);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(411); //951
		identifier(ctx);
		setState(413);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::Less)
		{
			setState(412); //951
			genericUsage(ctx);
		}
		setState(415);//958
		match(CMinusEqualsMinus1Revision0Parser::ParamOpen,ctx);
		setState(424);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if ((((_la & ~ 0x3fULL) == 0) &&
			((1ULL << _la) & ((1ULL << CMinusEqualsMinus1Revision0Parser::T__21)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__22)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__23)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__24)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__25)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__26)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::ParamOpen)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::LogicalUnaryOperator))) != 0) || ((((_la - 78) & ~ 0x3fULL) == 0) &&
			((1ULL << (_la - 78)) & ((1ULL << (CMinusEqualsMinus1Revision0Parser::Throw - 78))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::New - 78))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::SimpleIdentifier - 78))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::IntegerLiteral - 78))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::STRING - 78)))) != 0))
		{
			setState(416); //951
			functionCallParameter(ctx);
			setState(421);//800
			_errHandler->sync(this, ctx);
			_la = _input->LA(1);
			while (_la == CMinusEqualsMinus1Revision0Parser::Comma)
			{
				setState(417);//958
				match(CMinusEqualsMinus1Revision0Parser::Comma,ctx);
				setState(418); //951
				functionCallParameter(ctx);
				setState(423);//806
				_errHandler->sync(this, ctx);
				_la = _input->LA(1);
			}
		}
		setState(426);//958
		match(CMinusEqualsMinus1Revision0Parser::ParamClose,ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::FunctionCallContext> CMinusEqualsMinus1Revision0Parser::parsefunctionCall()
{
	functionCall();
	auto result = std::unique_ptr<FunctionCallContext>(dynamic_cast<FunctionCallContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- FunctionCallParameterContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext::FunctionCallParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::ExpressionContext* CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext::expression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ExpressionContext>(0);//1165
}


size_t CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleFunctionCallParameter;//688
}

void CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext::copyFrom(FunctionCallParameterContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<FunctionCallParameterContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitFunctionCallParameter(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext* CMinusEqualsMinus1Revision0Parser::functionCallParameter( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<FunctionCallParameterContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 72, CMinusEqualsMinus1Revision0Parser::RuleFunctionCallParameter);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(428); //951
		expression(0,ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext> CMinusEqualsMinus1Revision0Parser::parsefunctionCallParameter()
{
	functionCallParameter();
	auto result = std::unique_ptr<FunctionCallParameterContext>(dynamic_cast<FunctionCallParameterContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- AttributeSequenceContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext::AttributeSequenceContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

std::vector<CMinusEqualsMinus1Revision0Parser::AttributeContext *> CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext::attribute()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::AttributeContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::AttributeContext* CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext::attribute(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::AttributeContext>(i);//1183
}


size_t CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleAttributeSequence;//688
}

void CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext::copyFrom(AttributeSequenceContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<AttributeSequenceContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitAttributeSequence(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext* CMinusEqualsMinus1Revision0Parser::attributeSequence( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<AttributeSequenceContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 74, CMinusEqualsMinus1Revision0Parser::RuleAttributeSequence);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(431); //814
		_errHandler->sync(this, ctx);
		_la = _input->LA(1);
		do
		{
			setState(430); //951
			attribute(ctx);
			setState(433); //820
			_errHandler->sync(this, ctx);
			_la = _input->LA(1);
		} while (_la == CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext> CMinusEqualsMinus1Revision0Parser::parseattributeSequence()
{
	attributeSequence();
	auto result = std::unique_ptr<AttributeSequenceContext>(dynamic_cast<AttributeSequenceContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- AttributeContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::AttributeContext::AttributeContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::AttributeContext::ATTROBITEOPEN()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN, 0);
}

CMinusEqualsMinus1Revision0Parser::FunctionCallContext* CMinusEqualsMinus1Revision0Parser::AttributeContext::functionCall()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::FunctionCallContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::AttributeContext::ATTROBITECLOSE()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ATTROBITECLOSE, 0);
}


size_t CMinusEqualsMinus1Revision0Parser::AttributeContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleAttribute;//688
}

void CMinusEqualsMinus1Revision0Parser::AttributeContext::copyFrom(AttributeContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::AttributeContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<AttributeContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::AttributeContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::AttributeContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::AttributeContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitAttribute(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::AttributeContext* CMinusEqualsMinus1Revision0Parser::attribute( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<AttributeContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 76, CMinusEqualsMinus1Revision0Parser::RuleAttribute);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(435);//958
		match(CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN,ctx);
		setState(436); //951
		functionCall(ctx);
		setState(437);//958
		match(CMinusEqualsMinus1Revision0Parser::ATTROBITECLOSE,ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::AttributeContext> CMinusEqualsMinus1Revision0Parser::parseattribute()
{
	attribute();
	auto result = std::unique_ptr<AttributeContext>(dynamic_cast<AttributeContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- QualifiedIdentifierContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext::QualifiedIdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

std::vector<CMinusEqualsMinus1Revision0Parser::IdentifierContext *> CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext::identifier()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::IdentifierContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::IdentifierContext* CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext::identifier(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::IdentifierContext>(i);//1183
}

std::vector<tree::TerminalNode *> CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext::DoubleColon()
{
	return getTokens(CMinusEqualsMinus1Revision0Parser::DoubleColon);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext::DoubleColon(size_t i)
{
	return getToken(CMinusEqualsMinus1Revision0Parser::DoubleColon, i);
}


size_t CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleQualifiedIdentifier;//688
}

void CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext::copyFrom(QualifiedIdentifierContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<QualifiedIdentifierContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitQualifiedIdentifier(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext* CMinusEqualsMinus1Revision0Parser::qualifiedIdentifier( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<QualifiedIdentifierContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 78, CMinusEqualsMinus1Revision0Parser::RuleQualifiedIdentifier);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(439); //951
		identifier(ctx);
		setState(444);//800
		_errHandler->sync(this, ctx);
		_la = _input->LA(1);
		while (_la == CMinusEqualsMinus1Revision0Parser::DoubleColon)
		{
			setState(440);//958
			match(CMinusEqualsMinus1Revision0Parser::DoubleColon,ctx);
			setState(441); //951
			identifier(ctx);
			setState(446);//806
			_errHandler->sync(this, ctx);
			_la = _input->LA(1);
		}
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext> CMinusEqualsMinus1Revision0Parser::parsequalifiedIdentifier()
{
	qualifiedIdentifier();
	auto result = std::unique_ptr<QualifiedIdentifierContext>(dynamic_cast<QualifiedIdentifierContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- ExpressionContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::ExpressionContext::ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ExpressionContext::STRING()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::STRING, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ExpressionContext::ParamOpen()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ParamOpen, 0);
}

std::vector<CMinusEqualsMinus1Revision0Parser::ExpressionContext *> CMinusEqualsMinus1Revision0Parser::ExpressionContext::expression()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::ExpressionContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::ExpressionContext* CMinusEqualsMinus1Revision0Parser::ExpressionContext::expression(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ExpressionContext>(i);//1183
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ExpressionContext::ParamClose()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ParamClose, 0);
}

CMinusEqualsMinus1Revision0Parser::FunctionCallContext* CMinusEqualsMinus1Revision0Parser::ExpressionContext::functionCall()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::FunctionCallContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext* CMinusEqualsMinus1Revision0Parser::ExpressionContext::throwExpression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::IdentifierContext* CMinusEqualsMinus1Revision0Parser::ExpressionContext::identifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::IdentifierContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ExpressionContext::IntegerLiteral()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::IntegerLiteral, 0);
}

CMinusEqualsMinus1Revision0Parser::NewExpressionContext* CMinusEqualsMinus1Revision0Parser::ExpressionContext::newExpression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::NewExpressionContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ExpressionContext::LogicalUnaryOperator()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::LogicalUnaryOperator, 0);
}

CMinusEqualsMinus1Revision0Parser::BinaryOperatorContext* CMinusEqualsMinus1Revision0Parser::ExpressionContext::binaryOperator()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::BinaryOperatorContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ExpressionContext::Period()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Period, 0);
}

CMinusEqualsMinus1Revision0Parser::IndexExpressionContext* CMinusEqualsMinus1Revision0Parser::ExpressionContext::indexExpression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::IndexExpressionContext>(0);//1165
}


size_t CMinusEqualsMinus1Revision0Parser::ExpressionContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleExpression;//688
}

void CMinusEqualsMinus1Revision0Parser::ExpressionContext::copyFrom(ExpressionContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::ExpressionContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<ExpressionContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::ExpressionContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::ExpressionContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitExpression(this);
	else
		return visitor->visitChildren(this);
}


CMinusEqualsMinus1Revision0Parser::ExpressionContext* CMinusEqualsMinus1Revision0Parser::expression()
{
	 return expression(0, nullptr);//600
}

CMinusEqualsMinus1Revision0Parser::ExpressionContext* CMinusEqualsMinus1Revision0Parser::expression(int precedence, antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	antlr4::ParserRuleContext *parentContext = parent;
	size_t parentState = getState();
	auto _localctx = std::make_unique<ExpressionContext>(parentContext, parentState);//610
	auto ctx = _localctx.get();//609
	size_t startState = 80;
	enterRecursionRule(ctx, 80, CMinusEqualsMinus1Revision0Parser::RuleExpression, precedence);

		

	auto onExit = finally([=,&_localctx]
{
		unrollRecursionContexts(parentContext, std::move(_localctx));
	});
	try
{
		size_t alt;
		enterOuterAlt(ctx, 1);
		setState(460);//830
		_errHandler->sync(this, ctx);
		switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, ctx))
		{
		case 1:
		{
			setState(448);//958
			match(CMinusEqualsMinus1Revision0Parser::STRING,ctx);
			break;
		}

		case 2:
		{
			setState(449);//958
			match(CMinusEqualsMinus1Revision0Parser::ParamOpen,ctx);
			setState(450); //951
			expression(0,ctx);
			setState(451);//958
			match(CMinusEqualsMinus1Revision0Parser::ParamClose,ctx);
			break;
		}

		case 3:
		{
			setState(453); //951
			functionCall(ctx);
			break;
		}

		case 4:
		{
			setState(454); //951
			throwExpression(ctx);
			break;
		}

		case 5:
		{
			setState(455); //951
			identifier(ctx);
			break;
		}

		case 6:
		{
			setState(456);//958
			match(CMinusEqualsMinus1Revision0Parser::IntegerLiteral,ctx);
			break;
		}

		case 7:
		{
			setState(457); //951
			newExpression(ctx);
			break;
		}

		case 8:
		{
			setState(458);//958
			match(CMinusEqualsMinus1Revision0Parser::LogicalUnaryOperator,ctx);
			setState(459); //951
			expression(2,ctx);
			break;
		}

		}
		ctx->stop = _input->LT(-1);
		setState(476);//865
		_errHandler->sync(this, ctx);
		alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, ctx);
		while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER)
		{
			if (alt == 1)
		{
				if (!_parseListeners.empty())
					triggerExitRuleEvent(ctx);

				setState(474);//830
				_errHandler->sync(this, ctx);
				switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, ctx))
				{
				case 1:
				{
					auto tmpContext = std::make_unique<ExpressionContext>(parentContext, parentState);
					pushNewRecursionContext(std::move(_localctx), tmpContext.get(), startState, RuleExpression);//1240
					_localctx = std::move(tmpContext);
					ctx = _localctx.get();
					setState(462);//1002

					if (!(precpred(nullptr, 3))) throw FailedPredicateException(this, "precpred(nullptr, 3)", ctx);
					setState(463); //951
					binaryOperator(ctx);
					setState(464); //951
					expression(4,ctx);
					break;
				}

				case 2:
				{
					auto tmpContext = std::make_unique<ExpressionContext>(parentContext, parentState);
					pushNewRecursionContext(std::move(_localctx), tmpContext.get(), startState, RuleExpression);//1240
					_localctx = std::move(tmpContext);
					ctx = _localctx.get();
					setState(466);//1002

					if (!(precpred(nullptr, 10))) throw FailedPredicateException(this, "precpred(nullptr, 10)", ctx);
					setState(467);//958
					match(CMinusEqualsMinus1Revision0Parser::Period,ctx);
					setState(468); //951
					identifier(ctx);
					break;
				}

				case 3:
				{
					auto tmpContext = std::make_unique<ExpressionContext>(parentContext, parentState);
					pushNewRecursionContext(std::move(_localctx), tmpContext.get(), startState, RuleExpression);//1240
					_localctx = std::move(tmpContext);
					ctx = _localctx.get();
					setState(469);//1002

					if (!(precpred(nullptr, 9))) throw FailedPredicateException(this, "precpred(nullptr, 9)", ctx);
					setState(470);//958
					match(CMinusEqualsMinus1Revision0Parser::Period,ctx);
					setState(471); //951
					functionCall(ctx);
					break;
				}

				case 4:
				{
					auto tmpContext = std::make_unique<ExpressionContext>(parentContext, parentState);
					pushNewRecursionContext(std::move(_localctx), tmpContext.get(), startState, RuleExpression);//1240
					_localctx = std::move(tmpContext);
					ctx = _localctx.get();
					setState(472);//1002

					if (!(precpred(nullptr, 1))) throw FailedPredicateException(this, "precpred(nullptr, 1)", ctx);
					setState(473); //951
					indexExpression(ctx);
					break;
				}

				} 
			}
			setState(478);//875
			_errHandler->sync(this, ctx);
			alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, ctx);
		}
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		_localctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}
	onExit();
	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::ExpressionContext> CMinusEqualsMinus1Revision0Parser::parseexpression()
{
	expression();
	auto result = std::unique_ptr<ExpressionContext>(dynamic_cast<ExpressionContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}

//----------------- IndexExpressionContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::IndexExpressionContext::IndexExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::IndexExpressionContext::ATTROBITEOPEN()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::IndexExpressionContext::ATTROBITECLOSE()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ATTROBITECLOSE, 0);
}

std::vector<CMinusEqualsMinus1Revision0Parser::ExpressionContext *> CMinusEqualsMinus1Revision0Parser::IndexExpressionContext::expression()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::ExpressionContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::ExpressionContext* CMinusEqualsMinus1Revision0Parser::IndexExpressionContext::expression(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ExpressionContext>(i);//1183
}


size_t CMinusEqualsMinus1Revision0Parser::IndexExpressionContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleIndexExpression;//688
}

void CMinusEqualsMinus1Revision0Parser::IndexExpressionContext::copyFrom(IndexExpressionContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::IndexExpressionContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<IndexExpressionContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::IndexExpressionContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::IndexExpressionContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::IndexExpressionContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitIndexExpression(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::IndexExpressionContext* CMinusEqualsMinus1Revision0Parser::indexExpression( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<IndexExpressionContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 82, CMinusEqualsMinus1Revision0Parser::RuleIndexExpression);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(479);//958
		match(CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN,ctx);
		setState(481); //814
		_errHandler->sync(this, ctx);
		_la = _input->LA(1);
		do
		{
			setState(480); //951
			expression(0,ctx);
			setState(483); //820
			_errHandler->sync(this, ctx);
			_la = _input->LA(1);
		} while ((((_la & ~ 0x3fULL) == 0) &&
			((1ULL << _la) & ((1ULL << CMinusEqualsMinus1Revision0Parser::T__21)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__22)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__23)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__24)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__25)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::T__26)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::ParamOpen)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::LogicalUnaryOperator))) != 0) || ((((_la - 78) & ~ 0x3fULL) == 0) &&
			((1ULL << (_la - 78)) & ((1ULL << (CMinusEqualsMinus1Revision0Parser::Throw - 78))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::New - 78))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::SimpleIdentifier - 78))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::IntegerLiteral - 78))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::STRING - 78)))) != 0));
		setState(485);//958
		match(CMinusEqualsMinus1Revision0Parser::ATTROBITECLOSE,ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::IndexExpressionContext> CMinusEqualsMinus1Revision0Parser::parseindexExpression()
{
	indexExpression();
	auto result = std::unique_ptr<IndexExpressionContext>(dynamic_cast<IndexExpressionContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- NewExpressionContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::NewExpressionContext::NewExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::NewExpressionContext::New()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::New, 0);
}

CMinusEqualsMinus1Revision0Parser::FunctionCallContext* CMinusEqualsMinus1Revision0Parser::NewExpressionContext::functionCall()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::FunctionCallContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::NewExpressionContext::Unique()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Unique, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::NewExpressionContext::Shared()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Shared, 0);
}


size_t CMinusEqualsMinus1Revision0Parser::NewExpressionContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleNewExpression;//688
}

void CMinusEqualsMinus1Revision0Parser::NewExpressionContext::copyFrom(NewExpressionContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::NewExpressionContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<NewExpressionContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::NewExpressionContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::NewExpressionContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::NewExpressionContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitNewExpression(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::NewExpressionContext* CMinusEqualsMinus1Revision0Parser::newExpression( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<NewExpressionContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 84, CMinusEqualsMinus1Revision0Parser::RuleNewExpression);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(487);//958
		match(CMinusEqualsMinus1Revision0Parser::New,ctx);
		setState(488);//970
		_la = _input->LA(1);
		if (!(_la == CMinusEqualsMinus1Revision0Parser::Shared

		|| _la == CMinusEqualsMinus1Revision0Parser::Unique))
		{
		_errHandler->recoverInline(this, ctx);
		}
		else
		{
			_errHandler->reportMatch(this);
			consume(ctx);
		}
		setState(489); //951
		functionCall(ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::NewExpressionContext> CMinusEqualsMinus1Revision0Parser::parsenewExpression()
{
	newExpression();
	auto result = std::unique_ptr<NewExpressionContext>(dynamic_cast<NewExpressionContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- AssigmentStatementContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext::AssigmentStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

std::vector<CMinusEqualsMinus1Revision0Parser::ExpressionContext *> CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext::expression()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::ExpressionContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::ExpressionContext* CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext::expression(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ExpressionContext>(i);//1183
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext::Asssigment()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Asssigment, 0);
}


size_t CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleAssigmentStatement;//688
}

void CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext::copyFrom(AssigmentStatementContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<AssigmentStatementContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitAssigmentStatement(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext* CMinusEqualsMinus1Revision0Parser::assigmentStatement( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<AssigmentStatementContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 86, CMinusEqualsMinus1Revision0Parser::RuleAssigmentStatement);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(491); //951
		expression(0,ctx);
		setState(492);//958
		match(CMinusEqualsMinus1Revision0Parser::Asssigment,ctx);
		setState(493); //951
		expression(0,ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext> CMinusEqualsMinus1Revision0Parser::parseassigmentStatement()
{
	assigmentStatement();
	auto result = std::unique_ptr<AssigmentStatementContext>(dynamic_cast<AssigmentStatementContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- ThrowExpressionContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext::ThrowExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext::Throw()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Throw, 0);
}

CMinusEqualsMinus1Revision0Parser::ExpressionContext* CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext::expression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ExpressionContext>(0);//1165
}


size_t CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleThrowExpression;//688
}

void CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext::copyFrom(ThrowExpressionContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<ThrowExpressionContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitThrowExpression(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext* CMinusEqualsMinus1Revision0Parser::throwExpression( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<ThrowExpressionContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 88, CMinusEqualsMinus1Revision0Parser::RuleThrowExpression);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(495);//958
		match(CMinusEqualsMinus1Revision0Parser::Throw,ctx);
		setState(496); //951
		expression(0,ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext> CMinusEqualsMinus1Revision0Parser::parsethrowExpression()
{
	throwExpression();
	auto result = std::unique_ptr<ThrowExpressionContext>(dynamic_cast<ThrowExpressionContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- ArithmeticBinaryOperatorContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::ArithmeticBinaryOperatorContext::ArithmeticBinaryOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ArithmeticBinaryOperatorContext::Plus()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Plus, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ArithmeticBinaryOperatorContext::Minus()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Minus, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ArithmeticBinaryOperatorContext::Star()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Star, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ArithmeticBinaryOperatorContext::PlusEquals()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::PlusEquals, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ArithmeticBinaryOperatorContext::MinusEquals()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::MinusEquals, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ArithmeticBinaryOperatorContext::MultiplyEquals()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::MultiplyEquals, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ArithmeticBinaryOperatorContext::DivideEquals()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::DivideEquals, 0);
}


size_t CMinusEqualsMinus1Revision0Parser::ArithmeticBinaryOperatorContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleArithmeticBinaryOperator;//688
}

void CMinusEqualsMinus1Revision0Parser::ArithmeticBinaryOperatorContext::copyFrom(ArithmeticBinaryOperatorContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::ArithmeticBinaryOperatorContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<ArithmeticBinaryOperatorContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::ArithmeticBinaryOperatorContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::ArithmeticBinaryOperatorContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::ArithmeticBinaryOperatorContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitArithmeticBinaryOperator(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::ArithmeticBinaryOperatorContext* CMinusEqualsMinus1Revision0Parser::arithmeticBinaryOperator( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<ArithmeticBinaryOperatorContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 90, CMinusEqualsMinus1Revision0Parser::RuleArithmeticBinaryOperator);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		setState(506);//750
		_errHandler->sync(this, ctx);
		switch (_input->LA(1))
		{
			case CMinusEqualsMinus1Revision0Parser::T__21:
			case CMinusEqualsMinus1Revision0Parser::T__22:
			case CMinusEqualsMinus1Revision0Parser::T__23:
			case CMinusEqualsMinus1Revision0Parser::T__24:
			case CMinusEqualsMinus1Revision0Parser::T__25:
			case CMinusEqualsMinus1Revision0Parser::T__26:
			case CMinusEqualsMinus1Revision0Parser::ParamOpen:
			case CMinusEqualsMinus1Revision0Parser::LogicalUnaryOperator:
			case CMinusEqualsMinus1Revision0Parser::Less:
			case CMinusEqualsMinus1Revision0Parser::Throw:
			case CMinusEqualsMinus1Revision0Parser::New:
			case CMinusEqualsMinus1Revision0Parser::SimpleIdentifier:
			case CMinusEqualsMinus1Revision0Parser::IntegerLiteral:
			case CMinusEqualsMinus1Revision0Parser::STRING:
			{
				enterOuterAlt(ctx, 1);

				break;
			}

			case CMinusEqualsMinus1Revision0Parser::Plus:
			{
				enterOuterAlt(ctx, 2);
				setState(499);//958
				match(CMinusEqualsMinus1Revision0Parser::Plus,ctx);
				break;
			}

			case CMinusEqualsMinus1Revision0Parser::Minus:
			{
				enterOuterAlt(ctx, 3);
				setState(500);//958
				match(CMinusEqualsMinus1Revision0Parser::Minus,ctx);
				break;
			}

			case CMinusEqualsMinus1Revision0Parser::Star:
			{
				enterOuterAlt(ctx, 4);
				setState(501);//958
				match(CMinusEqualsMinus1Revision0Parser::Star,ctx);
				break;
			}

			case CMinusEqualsMinus1Revision0Parser::PlusEquals:
			{
				enterOuterAlt(ctx, 5);
				setState(502);//958
				match(CMinusEqualsMinus1Revision0Parser::PlusEquals,ctx);
				break;
			}

			case CMinusEqualsMinus1Revision0Parser::MinusEquals:
			{
				enterOuterAlt(ctx, 6);
				setState(503);//958
				match(CMinusEqualsMinus1Revision0Parser::MinusEquals,ctx);
				break;
			}

			case CMinusEqualsMinus1Revision0Parser::MultiplyEquals:
			{
				enterOuterAlt(ctx, 7);
				setState(504);//958
				match(CMinusEqualsMinus1Revision0Parser::MultiplyEquals,ctx);
				break;
			}

			case CMinusEqualsMinus1Revision0Parser::DivideEquals:
			{
				enterOuterAlt(ctx, 8);
				setState(505);//958
				match(CMinusEqualsMinus1Revision0Parser::DivideEquals,ctx);
				break;
			}

		default:
			throw NoViableAltException(this, ctx);
		}
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::ArithmeticBinaryOperatorContext> CMinusEqualsMinus1Revision0Parser::parsearithmeticBinaryOperator()
{
	arithmeticBinaryOperator();
	auto result = std::unique_ptr<ArithmeticBinaryOperatorContext>(dynamic_cast<ArithmeticBinaryOperatorContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- ComparsionOperatorContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::ComparsionOperatorContext::ComparsionOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ComparsionOperatorContext::Greater()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Greater, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ComparsionOperatorContext::Less()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Less, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ComparsionOperatorContext::GreaterEqual()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::GreaterEqual, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ComparsionOperatorContext::LessEqual()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::LessEqual, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ComparsionOperatorContext::Equal()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Equal, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ComparsionOperatorContext::NotEqual()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::NotEqual, 0);
}


size_t CMinusEqualsMinus1Revision0Parser::ComparsionOperatorContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleComparsionOperator;//688
}

void CMinusEqualsMinus1Revision0Parser::ComparsionOperatorContext::copyFrom(ComparsionOperatorContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::ComparsionOperatorContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<ComparsionOperatorContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::ComparsionOperatorContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::ComparsionOperatorContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::ComparsionOperatorContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitComparsionOperator(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::ComparsionOperatorContext* CMinusEqualsMinus1Revision0Parser::comparsionOperator( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<ComparsionOperatorContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 92, CMinusEqualsMinus1Revision0Parser::RuleComparsionOperator);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(508);//970
		_la = _input->LA(1);
		if (!((((_la & ~ 0x3fULL) == 0) &&
			((1ULL << _la) & ((1ULL << CMinusEqualsMinus1Revision0Parser::Equal)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::NotEqual)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::GreaterEqual)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::Greater)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::Less)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::LessEqual))) != 0)))
		{
		_errHandler->recoverInline(this, ctx);
		}
		else
		{
			_errHandler->reportMatch(this);
			consume(ctx);
		}
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::ComparsionOperatorContext> CMinusEqualsMinus1Revision0Parser::parsecomparsionOperator()
{
	comparsionOperator();
	auto result = std::unique_ptr<ComparsionOperatorContext>(dynamic_cast<ComparsionOperatorContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- BinaryOperatorContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::BinaryOperatorContext::BinaryOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::LogicalBinaryOperatorContext* CMinusEqualsMinus1Revision0Parser::BinaryOperatorContext::logicalBinaryOperator()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::LogicalBinaryOperatorContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::ComparsionOperatorContext* CMinusEqualsMinus1Revision0Parser::BinaryOperatorContext::comparsionOperator()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ComparsionOperatorContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::ArithmeticBinaryOperatorContext* CMinusEqualsMinus1Revision0Parser::BinaryOperatorContext::arithmeticBinaryOperator()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ArithmeticBinaryOperatorContext>(0);//1165
}


size_t CMinusEqualsMinus1Revision0Parser::BinaryOperatorContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleBinaryOperator;//688
}

void CMinusEqualsMinus1Revision0Parser::BinaryOperatorContext::copyFrom(BinaryOperatorContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::BinaryOperatorContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<BinaryOperatorContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::BinaryOperatorContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::BinaryOperatorContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::BinaryOperatorContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitBinaryOperator(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::BinaryOperatorContext* CMinusEqualsMinus1Revision0Parser::binaryOperator( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<BinaryOperatorContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 94, CMinusEqualsMinus1Revision0Parser::RuleBinaryOperator);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		setState(513);//830
		_errHandler->sync(this, ctx);
		switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, ctx))
		{
		case 1:
		{
			enterOuterAlt(ctx, 1);
			setState(510); //951
			logicalBinaryOperator(ctx);
			break;
		}

		case 2:
		{
			enterOuterAlt(ctx, 2);
			setState(511); //951
			comparsionOperator(ctx);
			break;
		}

		case 3:
		{
			enterOuterAlt(ctx, 3);
			setState(512); //951
			arithmeticBinaryOperator(ctx);
			break;
		}

		}
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::BinaryOperatorContext> CMinusEqualsMinus1Revision0Parser::parsebinaryOperator()
{
	binaryOperator();
	auto result = std::unique_ptr<BinaryOperatorContext>(dynamic_cast<BinaryOperatorContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- LogicalBinaryOperatorContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::LogicalBinaryOperatorContext::LogicalBinaryOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::LogicalBinaryOperatorContext::Or()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Or, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::LogicalBinaryOperatorContext::And()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::And, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::LogicalBinaryOperatorContext::Xor()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Xor, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::LogicalBinaryOperatorContext::NotEqual()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::NotEqual, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::LogicalBinaryOperatorContext::Equal()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Equal, 0);
}


size_t CMinusEqualsMinus1Revision0Parser::LogicalBinaryOperatorContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleLogicalBinaryOperator;//688
}

void CMinusEqualsMinus1Revision0Parser::LogicalBinaryOperatorContext::copyFrom(LogicalBinaryOperatorContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::LogicalBinaryOperatorContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<LogicalBinaryOperatorContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::LogicalBinaryOperatorContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::LogicalBinaryOperatorContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::LogicalBinaryOperatorContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitLogicalBinaryOperator(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::LogicalBinaryOperatorContext* CMinusEqualsMinus1Revision0Parser::logicalBinaryOperator( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<LogicalBinaryOperatorContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 96, CMinusEqualsMinus1Revision0Parser::RuleLogicalBinaryOperator);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(515);//970
		_la = _input->LA(1);
		if (!((((_la & ~ 0x3fULL) == 0) &&
			((1ULL << _la) & ((1ULL << CMinusEqualsMinus1Revision0Parser::Equal)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::NotEqual)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::Or)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::And)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::Xor))) != 0)))
		{
		_errHandler->recoverInline(this, ctx);
		}
		else
		{
			_errHandler->reportMatch(this);
			consume(ctx);
		}
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::LogicalBinaryOperatorContext> CMinusEqualsMinus1Revision0Parser::parselogicalBinaryOperator()
{
	logicalBinaryOperator();
	auto result = std::unique_ptr<LogicalBinaryOperatorContext>(dynamic_cast<LogicalBinaryOperatorContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- RefContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::RefContext::RefContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::RefContext::Star()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Star, 0);
}


size_t CMinusEqualsMinus1Revision0Parser::RefContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleRef;//688
}

void CMinusEqualsMinus1Revision0Parser::RefContext::copyFrom(RefContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::RefContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<RefContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::RefContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::RefContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::RefContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitRef(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::RefContext* CMinusEqualsMinus1Revision0Parser::ref( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<RefContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 98, CMinusEqualsMinus1Revision0Parser::RuleRef);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(517);//958
		match(CMinusEqualsMinus1Revision0Parser::Star,ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::RefContext> CMinusEqualsMinus1Revision0Parser::parseref()
{
	ref();
	auto result = std::unique_ptr<RefContext>(dynamic_cast<RefContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- IdentifierContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::IdentifierContext::IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::IdentifierContext::SimpleIdentifier()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::SimpleIdentifier, 0);
}


size_t CMinusEqualsMinus1Revision0Parser::IdentifierContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleIdentifier;//688
}

void CMinusEqualsMinus1Revision0Parser::IdentifierContext::copyFrom(IdentifierContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::IdentifierContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<IdentifierContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::IdentifierContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::IdentifierContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::IdentifierContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitIdentifier(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::IdentifierContext* CMinusEqualsMinus1Revision0Parser::identifier( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<IdentifierContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 100, CMinusEqualsMinus1Revision0Parser::RuleIdentifier);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(519);//970
		_la = _input->LA(1);
		if (!(((((_la - 22) & ~ 0x3fULL) == 0) &&
			((1ULL << (_la - 22)) & ((1ULL << (CMinusEqualsMinus1Revision0Parser::T__21 - 22))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::T__22 - 22))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::T__23 - 22))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::T__24 - 22))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::T__25 - 22))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::T__26 - 22))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::SimpleIdentifier - 22)))) != 0)))
		{
		_errHandler->recoverInline(this, ctx);
		}
		else
		{
			_errHandler->reportMatch(this);
			consume(ctx);
		}
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::IdentifierContext> CMinusEqualsMinus1Revision0Parser::parseidentifier()
{
	identifier();
	auto result = std::unique_ptr<IdentifierContext>(dynamic_cast<IdentifierContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


bool CMinusEqualsMinus1Revision0Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex)
{
	switch (ruleIndex)
{
		case 40: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);//430

	default:
		break;
	}
	return true;
}

bool CMinusEqualsMinus1Revision0Parser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex)
{
	switch (predicateIndex)
{
		case 0: return precpred(nullptr, 3);
		case 1: return precpred(nullptr, 10);
		case 2: return precpred(nullptr, 9);
		case 3: return precpred(nullptr, 1);

	default:
		break;
	}
	return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> CMinusEqualsMinus1Revision0Parser::_decisionToDFA;
atn::PredictionContextCache CMinusEqualsMinus1Revision0Parser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CMinusEqualsMinus1Revision0Parser::_atn;
std::vector<uint16_t> CMinusEqualsMinus1Revision0Parser::_serializedATN;

std::vector<std::string_view> CMinusEqualsMinus1Revision0Parser::_ruleNames =
{
	"compilationUnit", "languageStandardDeclaration", "declarationSequence", 
	"declaration", "attributeDeclaration", "attributeTarget", "importDeclaration", 
	"typeDeclaration", "classTypeSpecifier", "classContentSequence", "fieldDeclaration", 
	"genericSpecifier", "implementedInterfacesSequence", "namespaceDeclaration", 
	"functionDeclaration", "parameterList", "parameter", "typeSpecifier", "genericUsage", 
	"functionBody", "functionName", "specialFunctionIdentifier", "compoundStatement", 
	"statement", "functionCallStatement", "returnStatement", "variableDeclarationStatement", 
	"ifStatement", "loopStatement", "rangeForStatement", "forStatement", "whileStatement", 
	"doWhileStatement", "whileHeader", "infiniteLoopStatement", "functionCall", 
	"functionCallParameter", "attributeSequence", "attribute", "qualifiedIdentifier", 
	"expression", "indexExpression", "newExpression", "assigmentStatement", 
	"throwExpression", "arithmeticBinaryOperator", "comparsionOperator", "binaryOperator", 
	"logicalBinaryOperator", "ref", "identifier"
};

std::vector<std::string_view> CMinusEqualsMinus1Revision0Parser::_literalNames =
{
	"", "'standard'", "'att'", "'type'", "'variable'", "'function'", "'import'", 
	"'from'", "':'", "'struct'", "'namespace'", "'fn'", "'->'", "'return'", 
	"'let'", "'if'", "'else'", "'for'", "'in'", "'do'", "'while'", "'loop'", 
	"'@new'", "'@unique'", "'@shared'", "'@throw'", "'@attribute'", "'@default'", 
	"", "'{'", "'}'", "'\"'", "'''", "'('", "')'", "'['", "']'", "", "'unsafe'", 
	"", "", "", "", "'::'", "';'", "','", "'.'", "", "'='", "", "'+'", "'-'", 
	"'*'", "'+='", "'-='", "'*='", "'/='", "'>='", "'>'", "'<'", "'<='", "'||'", 
	"'&&'", "'^^'", "", "'?'", "'^'", "'class'", "'interface'", "'public'", 
	"'private'", "'internal'", "'final'", "'virtual'", "'abstract'", "'override'", 
	"", "'attribute'", "'throw'", "'operator'", "'shared'", "'unique'", "'new'"
};

std::vector<std::string_view> CMinusEqualsMinus1Revision0Parser::_symbolicNames =
{
	"", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
	"", "", "", "", "", "", "", "", "", "", "AccessSpecifier", "OpenBracket", 
	"CloseBracket", "DOUBLEQUOTE", "SINGLEQUOTE", "ParamOpen", "ParamClose", 
	"ATTROBITEOPEN", "ATTROBITECLOSE", "Array", "Unsafe", "LogicalUnaryOperator", 
	"Equal", "NotEqual", "Not", "DoubleColon", "SemiColon", "Comma", "Period", 
	"Equals", "Asssigment", "NotEquals", "Plus", "Minus", "Star", "PlusEquals", 
	"MinusEquals", "MultiplyEquals", "DivideEquals", "GreaterEqual", "Greater", 
	"Less", "LessEqual", "Or", "And", "Xor", "Strong", "Nullable", "Mutable", 
	"Class", "Interface", "Public", "Private", "Internal", "Final", "Virtual", 
	"Abstract", "Override", "DefaultSpecification", "Attribute", "Throw", "Operator", 
	"Shared", "Unique", "New", "SimpleIdentifier", "IntegerLiteral", "DIGIT", 
	"STRING", "AnyCharacter", "LETTER", "Whitespace", "Newline", "BlockComment", 
	"LineComment"
};

dfa::Vocabulary CMinusEqualsMinus1Revision0Parser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string_view> CMinusEqualsMinus1Revision0Parser::_tokenNames;

CMinusEqualsMinus1Revision0Parser::Initializer::Initializer()
{
	for (size_t i = 0; i < _symbolicNames.size(); ++i)
{
		auto name = _vocabulary.getLiteralName(i);
		if (name.empty())
{
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty())
{
			_tokenNames.push_back("<INVALID>");
		} else
{
			_tokenNames.push_back(name);
		}
	}

	_serializedATN =
	{
		0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 0x3, 
		0x5e, 0x20c, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 0x4, 
		0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 0x8, 
		0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 0xb, 
		0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 0xf, 
		0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 0x9, 
		0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 
		0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 
		0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 
		0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 
		0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 
		0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x4, 
		0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 0x4, 0x29, 
		0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 0x2c, 0x9, 
		0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 0x9, 0x2f, 
		0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 0x32, 0x4, 
		0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
		0x2, 0x3, 0x2, 0x5, 0x2, 0x6e, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
		0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x6, 0x4, 0x76, 0xa, 0x4, 0xd, 0x4, 0xe, 
		0x4, 0x77, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 
		0x7f, 0xa, 0x5, 0x3, 0x6, 0x5, 0x6, 0x82, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 
		0x3, 0x6, 0x6, 0x6, 0x87, 0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x88, 0x3, 0x6, 
		0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 
		0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x6, 0x8, 0x96, 0xa, 0x8, 0xd, 0x8, 0xe, 
		0x8, 0x97, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
		0x3, 0x9, 0x5, 0x9, 0xa1, 0xa, 0x9, 0x3, 0x9, 0x5, 0x9, 0xa4, 0xa, 0x9, 
		0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xa9, 0xa, 0x9, 0x3, 0x9, 0x3, 
		0x9, 0x5, 0x9, 0xad, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
		0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xb7, 0xa, 0xb, 0xc, 
		0xb, 0xe, 0xb, 0xba, 0xb, 0xb, 0x3, 0xc, 0x5, 0xc, 0xbd, 0xa, 0xc, 0x3, 
		0xc, 0x5, 0xc, 0xc0, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
		0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xcb, 0xa, 
		0xd, 0xc, 0xd, 0xe, 0xd, 0xce, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 
		0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x6, 0xe, 0xd6, 0xa, 0xe, 0xd, 0xe, 0xe, 
		0xe, 0xd7, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xdc, 0xa, 0xe, 0x3, 0xf, 0x3, 
		0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x5, 0x10, 0xe5, 
		0xa, 0x10, 0x3, 0x10, 0x5, 0x10, 0xe8, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 
		0x3, 0x10, 0x5, 0x10, 0xed, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
		0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xf4, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 
		0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x6, 0x11, 0xfd, 
		0xa, 0x11, 0xd, 0x11, 0xe, 0x11, 0xfe, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 
		0x103, 0xa, 0x11, 0x3, 0x12, 0x5, 0x12, 0x106, 0xa, 0x12, 0x3, 0x12, 0x3, 
		0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x10e, 0xa, 
		0x13, 0x3, 0x13, 0x7, 0x13, 0x111, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x114, 
		0xb, 0x13, 0x3, 0x13, 0x5, 0x13, 0x117, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 
		0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x11d, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 
		0x120, 0xb, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 
		0x126, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x129, 0xb, 0x15, 0x3, 0x15, 0x3, 
		0x15, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x12f, 0xa, 0x16, 0x3, 0x17, 0x3, 
		0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x135, 0xa, 0x17, 0x3, 0x18, 0x5, 
		0x18, 0x138, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x13c, 0xa, 0x18, 
		0xc, 0x18, 0xe, 0x18, 0x13f, 0xb, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 
		0x143, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
		0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
		0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x153, 0xa, 0x19, 0x3, 0x1a, 0x3, 
		0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x15a, 0xa, 0x1a, 0x3, 
		0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x5, 0x1c, 0x160, 0xa, 0x1c, 0x3, 
		0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x166, 0xa, 0x1c, 0x3, 
		0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x16a, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 
		0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x173, 0xa, 
		0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 
		0x17a, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
		0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 
		0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
		0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
		0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
		0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x1a0, 
		0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x1a6, 
		0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x1a9, 0xb, 0x25, 0x5, 0x25, 0x1ab, 0xa, 
		0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x27, 0x6, 0x27, 
		0x1b2, 0xa, 0x27, 0xd, 0x27, 0xe, 0x27, 0x1b3, 0x3, 0x28, 0x3, 0x28, 0x3, 
		0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x7, 0x29, 0x1bd, 0xa, 
		0x29, 0xc, 0x29, 0xe, 0x29, 0x1c0, 0xb, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
		0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
		0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x1cf, 0xa, 0x2a, 
		0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
		0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x7, 0x2a, 
		0x1dd, 0xa, 0x2a, 0xc, 0x2a, 0xe, 0x2a, 0x1e0, 0xb, 0x2a, 0x3, 0x2b, 0x3, 
		0x2b, 0x6, 0x2b, 0x1e4, 0xa, 0x2b, 0xd, 0x2b, 0xe, 0x2b, 0x1e5, 0x3, 0x2b, 
		0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 
		0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 
		0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 
		0x2f, 0x5, 0x2f, 0x1fd, 0xa, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 
		0x31, 0x3, 0x31, 0x5, 0x31, 0x204, 0xa, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 
		0x33, 0x3, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x34, 0x2, 0x3, 0x52, 0x35, 
		0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
		0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 
		0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 
		0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 
		0x64, 0x66, 0x2, 0x8, 0x3, 0x2, 0x5, 0x7, 0x4, 0x2, 0xb, 0xb, 0x45, 0x46, 
		0x3, 0x2, 0x52, 0x53, 0x4, 0x2, 0x2a, 0x2b, 0x3b, 0x3e, 0x4, 0x2, 0x2a, 
		0x2b, 0x3f, 0x41, 0x4, 0x2, 0x18, 0x1d, 0x55, 0x55, 0x2, 0x226, 0x2, 0x6d, 
		0x3, 0x2, 0x2, 0x2, 0x4, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6, 0x75, 0x3, 0x2, 
		0x2, 0x2, 0x8, 0x7e, 0x3, 0x2, 0x2, 0x2, 0xa, 0x81, 0x3, 0x2, 0x2, 0x2, 
		0xc, 0x90, 0x3, 0x2, 0x2, 0x2, 0xe, 0x92, 0x3, 0x2, 0x2, 0x2, 0x10, 0xa0, 
		0x3, 0x2, 0x2, 0x2, 0x12, 0xb2, 0x3, 0x2, 0x2, 0x2, 0x14, 0xb8, 0x3, 0x2, 
		0x2, 0x2, 0x16, 0xbc, 0x3, 0x2, 0x2, 0x2, 0x18, 0xc6, 0x3, 0x2, 0x2, 0x2, 
		0x1a, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x1e, 
		0xe4, 0x3, 0x2, 0x2, 0x2, 0x20, 0x102, 0x3, 0x2, 0x2, 0x2, 0x22, 0x105, 
		0x3, 0x2, 0x2, 0x2, 0x24, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x26, 0x118, 0x3, 
		0x2, 0x2, 0x2, 0x28, 0x123, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x12e, 0x3, 0x2, 
		0x2, 0x2, 0x2c, 0x130, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x142, 0x3, 0x2, 0x2, 
		0x2, 0x30, 0x152, 0x3, 0x2, 0x2, 0x2, 0x32, 0x159, 0x3, 0x2, 0x2, 0x2, 
		0x34, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x36, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x38, 
		0x16b, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x179, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x17b, 
		0x3, 0x2, 0x2, 0x2, 0x3e, 0x183, 0x3, 0x2, 0x2, 0x2, 0x40, 0x18d, 0x3, 
		0x2, 0x2, 0x2, 0x42, 0x190, 0x3, 0x2, 0x2, 0x2, 0x44, 0x195, 0x3, 0x2, 
		0x2, 0x2, 0x46, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x48, 0x19d, 0x3, 0x2, 0x2, 
		0x2, 0x4a, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x1b1, 0x3, 0x2, 0x2, 0x2, 
		0x4e, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x50, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x52, 
		0x1ce, 0x3, 0x2, 0x2, 0x2, 0x54, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x56, 0x1e9, 
		0x3, 0x2, 0x2, 0x2, 0x58, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x1f1, 0x3, 
		0x2, 0x2, 0x2, 0x5c, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x1fe, 0x3, 0x2, 
		0x2, 0x2, 0x60, 0x203, 0x3, 0x2, 0x2, 0x2, 0x62, 0x205, 0x3, 0x2, 0x2, 
		0x2, 0x64, 0x207, 0x3, 0x2, 0x2, 0x2, 0x66, 0x209, 0x3, 0x2, 0x2, 0x2, 
		0x68, 0x69, 0x5, 0x4, 0x3, 0x2, 0x69, 0x6a, 0x5, 0x6, 0x4, 0x2, 0x6a, 
		0x6b, 0x7, 0x2, 0x2, 0x3, 0x6b, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6e, 
		0x5, 0x6, 0x4, 0x2, 0x6d, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6c, 0x3, 0x2, 
		0x2, 0x2, 0x6e, 0x3, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x7, 0x3, 0x2, 0x2, 
		0x70, 0x71, 0x7, 0x32, 0x2, 0x2, 0x71, 0x72, 0x7, 0x56, 0x2, 0x2, 0x72, 
		0x73, 0x7, 0x2e, 0x2, 0x2, 0x73, 0x5, 0x3, 0x2, 0x2, 0x2, 0x74, 0x76, 
		0x5, 0x8, 0x5, 0x2, 0x75, 0x74, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x3, 0x2, 
		0x2, 0x2, 0x77, 0x75, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x3, 0x2, 0x2, 0x2, 
		0x78, 0x7, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7f, 0x5, 0x1e, 0x10, 0x2, 0x7a, 
		0x7f, 0x5, 0x10, 0x9, 0x2, 0x7b, 0x7f, 0x5, 0x1c, 0xf, 0x2, 0x7c, 0x7f, 
		0x5, 0xe, 0x8, 0x2, 0x7d, 0x7f, 0x5, 0xa, 0x6, 0x2, 0x7e, 0x79, 0x3, 0x2, 
		0x2, 0x2, 0x7e, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7b, 0x3, 0x2, 0x2, 0x2, 
		0x7e, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7f, 
		0x9, 0x3, 0x2, 0x2, 0x2, 0x80, 0x82, 0x7, 0x1e, 0x2, 0x2, 0x81, 0x80, 
		0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x3, 0x2, 
		0x2, 0x2, 0x83, 0x84, 0x7, 0x4, 0x2, 0x2, 0x84, 0x86, 0x7, 0x3d, 0x2, 
		0x2, 0x85, 0x87, 0x5, 0xc, 0x7, 0x2, 0x86, 0x85, 0x3, 0x2, 0x2, 0x2, 0x87, 
		0x88, 0x3, 0x2, 0x2, 0x2, 0x88, 0x86, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 
		0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x7, 0x3c, 
		0x2, 0x2, 0x8b, 0x8c, 0x5, 0x66, 0x34, 0x2, 0x8c, 0x8d, 0x7, 0x1f, 0x2, 
		0x2, 0x8d, 0x8e, 0x5, 0x14, 0xb, 0x2, 0x8e, 0x8f, 0x7, 0x20, 0x2, 0x2, 
		0x8f, 0xb, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0x9, 0x2, 0x2, 0x2, 0x91, 0xd, 
		0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x7, 0x8, 0x2, 0x2, 0x93, 0x95, 0x7, 0x1f, 
		0x2, 0x2, 0x94, 0x96, 0x5, 0x66, 0x34, 0x2, 0x95, 0x94, 0x3, 0x2, 0x2, 
		0x2, 0x96, 0x97, 0x3, 0x2, 0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 0x97, 
		0x98, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 
		0x7, 0x20, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x9, 0x2, 0x2, 0x9b, 0x9c, 0x7, 
		0x1f, 0x2, 0x2, 0x9c, 0x9d, 0x5, 0x50, 0x29, 0x2, 0x9d, 0x9e, 0x7, 0x20, 
		0x2, 0x2, 0x9e, 0xf, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa1, 0x5, 0x4c, 0x27, 
		0x2, 0xa0, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa1, 
		0xa3, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa4, 0x7, 0x1e, 0x2, 0x2, 0xa3, 0xa2, 
		0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x3, 0x2, 
		0x2, 0x2, 0xa5, 0xa6, 0x5, 0x12, 0xa, 0x2, 0xa6, 0xa8, 0x5, 0x66, 0x34, 
		0x2, 0xa7, 0xa9, 0x5, 0x18, 0xd, 0x2, 0xa8, 0xa7, 0x3, 0x2, 0x2, 0x2, 
		0xa8, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xac, 0x3, 0x2, 0x2, 0x2, 0xaa, 
		0xab, 0x7, 0xa, 0x2, 0x2, 0xab, 0xad, 0x5, 0x1a, 0xe, 0x2, 0xac, 0xaa, 
		0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x3, 0x2, 
		0x2, 0x2, 0xae, 0xaf, 0x7, 0x1f, 0x2, 0x2, 0xaf, 0xb0, 0x5, 0x14, 0xb, 
		0x2, 0xb0, 0xb1, 0x7, 0x20, 0x2, 0x2, 0xb1, 0x11, 0x3, 0x2, 0x2, 0x2, 
		0xb2, 0xb3, 0x9, 0x3, 0x2, 0x2, 0xb3, 0x13, 0x3, 0x2, 0x2, 0x2, 0xb4, 
		0xb7, 0x5, 0x1e, 0x10, 0x2, 0xb5, 0xb7, 0x5, 0x16, 0xc, 0x2, 0xb6, 0xb4, 
		0x3, 0x2, 0x2, 0x2, 0xb6, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xba, 0x3, 0x2, 
		0x2, 0x2, 0xb8, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x3, 0x2, 0x2, 0x2, 
		0xb9, 0x15, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xbb, 
		0xbd, 0x5, 0x4c, 0x27, 0x2, 0xbc, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 
		0x3, 0x2, 0x2, 0x2, 0xbd, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc0, 0x7, 0x1e, 
		0x2, 0x2, 0xbf, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x3, 0x2, 0x2, 0x2, 
		0xc0, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x5, 0x66, 0x34, 0x2, 0xc2, 
		0xc3, 0x7, 0xa, 0x2, 0x2, 0xc3, 0xc4, 0x5, 0x24, 0x13, 0x2, 0xc4, 0xc5, 
		0x7, 0x2e, 0x2, 0x2, 0xc5, 0x17, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x7, 
		0x3d, 0x2, 0x2, 0xc7, 0xcc, 0x5, 0x66, 0x34, 0x2, 0xc8, 0xc9, 0x7, 0x2f, 
		0x2, 0x2, 0xc9, 0xcb, 0x5, 0x66, 0x34, 0x2, 0xca, 0xc8, 0x3, 0x2, 0x2, 
		0x2, 0xcb, 0xce, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcc, 
		0xcd, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcc, 
		0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x7, 0x3c, 0x2, 0x2, 0xd0, 0x19, 0x3, 
		0x2, 0x2, 0x2, 0xd1, 0xdc, 0x5, 0x66, 0x34, 0x2, 0xd2, 0xd3, 0x5, 0x66, 
		0x34, 0x2, 0xd3, 0xd4, 0x7, 0x2f, 0x2, 0x2, 0xd4, 0xd6, 0x3, 0x2, 0x2, 
		0x2, 0xd5, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd7, 
		0xd5, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 
		0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x5, 0x66, 0x34, 0x2, 0xda, 0xdc, 0x3, 
		0x2, 0x2, 0x2, 0xdb, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xd5, 0x3, 0x2, 0x2, 
		0x2, 0xdc, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x7, 0xc, 0x2, 0x2, 0xde, 
		0xdf, 0x5, 0x50, 0x29, 0x2, 0xdf, 0xe0, 0x7, 0x1f, 0x2, 0x2, 0xe0, 0xe1, 
		0x5, 0x6, 0x4, 0x2, 0xe1, 0xe2, 0x7, 0x20, 0x2, 0x2, 0xe2, 0x1d, 0x3, 
		0x2, 0x2, 0x2, 0xe3, 0xe5, 0x5, 0x4c, 0x27, 0x2, 0xe4, 0xe3, 0x3, 0x2, 
		0x2, 0x2, 0xe4, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe7, 0x3, 0x2, 0x2, 0x2, 
		0xe6, 0xe8, 0x7, 0x1e, 0x2, 0x2, 0xe7, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe7, 
		0xe8, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 
		0x7, 0xd, 0x2, 0x2, 0xea, 0xec, 0x5, 0x2a, 0x16, 0x2, 0xeb, 0xed, 0x5, 
		0x18, 0xd, 0x2, 0xec, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 0x2, 
		0x2, 0x2, 0xed, 0xee, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x7, 0x23, 0x2, 
		0x2, 0xef, 0xf0, 0x5, 0x20, 0x11, 0x2, 0xf0, 0xf3, 0x7, 0x24, 0x2, 0x2, 
		0xf1, 0xf2, 0x7, 0xe, 0x2, 0x2, 0xf2, 0xf4, 0x5, 0x24, 0x13, 0x2, 0xf3, 
		0xf1, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 
		0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x5, 0x28, 0x15, 0x2, 0xf6, 0x1f, 0x3, 
		0x2, 0x2, 0x2, 0xf7, 0x103, 0x3, 0x2, 0x2, 0x2, 0xf8, 0x103, 0x5, 0x22, 
		0x12, 0x2, 0xf9, 0xfa, 0x5, 0x22, 0x12, 0x2, 0xfa, 0xfb, 0x7, 0x2f, 0x2, 
		0x2, 0xfb, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xfd, 
		0xfe, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 
		0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0x5, 
		0x22, 0x12, 0x2, 0x101, 0x103, 0x3, 0x2, 0x2, 0x2, 0x102, 0xf7, 0x3, 0x2, 
		0x2, 0x2, 0x102, 0xf8, 0x3, 0x2, 0x2, 0x2, 0x102, 0xfc, 0x3, 0x2, 0x2, 
		0x2, 0x103, 0x21, 0x3, 0x2, 0x2, 0x2, 0x104, 0x106, 0x5, 0x4c, 0x27, 0x2, 
		0x105, 0x104, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x3, 0x2, 0x2, 0x2, 0x106, 
		0x107, 0x3, 0x2, 0x2, 0x2, 0x107, 0x108, 0x5, 0x66, 0x34, 0x2, 0x108, 
		0x109, 0x7, 0xa, 0x2, 0x2, 0x109, 0x10a, 0x5, 0x24, 0x13, 0x2, 0x10a, 
		0x23, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10d, 0x5, 0x66, 0x34, 0x2, 0x10c, 0x10e, 
		0x5, 0x26, 0x14, 0x2, 0x10d, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 
		0x3, 0x2, 0x2, 0x2, 0x10e, 0x112, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x111, 0x5, 
		0x64, 0x33, 0x2, 0x110, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x111, 0x114, 0x3, 
		0x2, 0x2, 0x2, 0x112, 0x110, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0x3, 0x2, 
		0x2, 0x2, 0x113, 0x116, 0x3, 0x2, 0x2, 0x2, 0x114, 0x112, 0x3, 0x2, 0x2, 
		0x2, 0x115, 0x117, 0x7, 0x27, 0x2, 0x2, 0x116, 0x115, 0x3, 0x2, 0x2, 0x2, 
		0x116, 0x117, 0x3, 0x2, 0x2, 0x2, 0x117, 0x25, 0x3, 0x2, 0x2, 0x2, 0x118, 
		0x119, 0x7, 0x3d, 0x2, 0x2, 0x119, 0x11e, 0x5, 0x24, 0x13, 0x2, 0x11a, 
		0x11b, 0x7, 0x2f, 0x2, 0x2, 0x11b, 0x11d, 0x5, 0x24, 0x13, 0x2, 0x11c, 
		0x11a, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x120, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11c, 
		0x3, 0x2, 0x2, 0x2, 0x11e, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x121, 0x3, 
		0x2, 0x2, 0x2, 0x120, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 0x7, 0x3c, 
		0x2, 0x2, 0x122, 0x27, 0x3, 0x2, 0x2, 0x2, 0x123, 0x127, 0x7, 0x1f, 0x2, 
		0x2, 0x124, 0x126, 0x5, 0x30, 0x19, 0x2, 0x125, 0x124, 0x3, 0x2, 0x2, 
		0x2, 0x126, 0x129, 0x3, 0x2, 0x2, 0x2, 0x127, 0x125, 0x3, 0x2, 0x2, 0x2, 
		0x127, 0x128, 0x3, 0x2, 0x2, 0x2, 0x128, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x129, 
		0x127, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 0x7, 0x20, 0x2, 0x2, 0x12b, 0x29, 
		0x3, 0x2, 0x2, 0x2, 0x12c, 0x12f, 0x5, 0x66, 0x34, 0x2, 0x12d, 0x12f, 
		0x5, 0x2c, 0x17, 0x2, 0x12e, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12d, 
		0x3, 0x2, 0x2, 0x2, 0x12f, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x130, 0x134, 0x7, 
		0x51, 0x2, 0x2, 0x131, 0x132, 0x7, 0x54, 0x2, 0x2, 0x132, 0x135, 0x9, 
		0x4, 0x2, 0x2, 0x133, 0x135, 0x5, 0x60, 0x31, 0x2, 0x134, 0x131, 0x3, 
		0x2, 0x2, 0x2, 0x134, 0x133, 0x3, 0x2, 0x2, 0x2, 0x135, 0x2d, 0x3, 0x2, 
		0x2, 0x2, 0x136, 0x138, 0x7, 0x28, 0x2, 0x2, 0x137, 0x136, 0x3, 0x2, 0x2, 
		0x2, 0x137, 0x138, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 0x3, 0x2, 0x2, 0x2, 
		0x139, 0x13d, 0x7, 0x1f, 0x2, 0x2, 0x13a, 0x13c, 0x5, 0x30, 0x19, 0x2, 
		0x13b, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x13d, 
		0x13b, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x140, 
		0x3, 0x2, 0x2, 0x2, 0x13f, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x140, 0x143, 0x7, 
		0x20, 0x2, 0x2, 0x141, 0x143, 0x5, 0x30, 0x19, 0x2, 0x142, 0x137, 0x3, 
		0x2, 0x2, 0x2, 0x142, 0x141, 0x3, 0x2, 0x2, 0x2, 0x143, 0x2f, 0x3, 0x2, 
		0x2, 0x2, 0x144, 0x153, 0x5, 0x38, 0x1d, 0x2, 0x145, 0x153, 0x5, 0x3a, 
		0x1e, 0x2, 0x146, 0x147, 0x5, 0x58, 0x2d, 0x2, 0x147, 0x148, 0x7, 0x2e, 
		0x2, 0x2, 0x148, 0x153, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 0x5, 0x36, 0x1c, 
		0x2, 0x14a, 0x14b, 0x7, 0x2e, 0x2, 0x2, 0x14b, 0x153, 0x3, 0x2, 0x2, 0x2, 
		0x14c, 0x14d, 0x5, 0x34, 0x1b, 0x2, 0x14d, 0x14e, 0x7, 0x2e, 0x2, 0x2, 
		0x14e, 0x153, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 0x5, 0x32, 0x1a, 0x2, 
		0x150, 0x151, 0x7, 0x2e, 0x2, 0x2, 0x151, 0x153, 0x3, 0x2, 0x2, 0x2, 0x152, 
		0x144, 0x3, 0x2, 0x2, 0x2, 0x152, 0x145, 0x3, 0x2, 0x2, 0x2, 0x152, 0x146, 
		0x3, 0x2, 0x2, 0x2, 0x152, 0x149, 0x3, 0x2, 0x2, 0x2, 0x152, 0x14c, 0x3, 
		0x2, 0x2, 0x2, 0x152, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x153, 0x31, 0x3, 0x2, 
		0x2, 0x2, 0x154, 0x15a, 0x5, 0x48, 0x25, 0x2, 0x155, 0x156, 0x5, 0x52, 
		0x2a, 0x2, 0x156, 0x157, 0x7, 0x30, 0x2, 0x2, 0x157, 0x158, 0x5, 0x48, 
		0x25, 0x2, 0x158, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x159, 0x154, 0x3, 0x2, 0x2, 
		0x2, 0x159, 0x155, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x33, 0x3, 0x2, 0x2, 0x2, 
		0x15b, 0x15c, 0x7, 0xf, 0x2, 0x2, 0x15c, 0x15d, 0x5, 0x52, 0x2a, 0x2, 
		0x15d, 0x35, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x160, 0x5, 0x4c, 0x27, 0x2, 0x15f, 
		0x15e, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x160, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 
		0x3, 0x2, 0x2, 0x2, 0x161, 0x162, 0x7, 0x10, 0x2, 0x2, 0x162, 0x165, 0x5, 
		0x66, 0x34, 0x2, 0x163, 0x164, 0x7, 0xa, 0x2, 0x2, 0x164, 0x166, 0x5, 
		0x24, 0x13, 0x2, 0x165, 0x163, 0x3, 0x2, 0x2, 0x2, 0x165, 0x166, 0x3, 
		0x2, 0x2, 0x2, 0x166, 0x169, 0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 0x7, 0x32, 
		0x2, 0x2, 0x168, 0x16a, 0x5, 0x4a, 0x26, 0x2, 0x169, 0x167, 0x3, 0x2, 
		0x2, 0x2, 0x169, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x37, 0x3, 0x2, 0x2, 
		0x2, 0x16b, 0x16c, 0x7, 0x11, 0x2, 0x2, 0x16c, 0x16d, 0x7, 0x23, 0x2, 
		0x2, 0x16d, 0x16e, 0x5, 0x52, 0x2a, 0x2, 0x16e, 0x16f, 0x7, 0x24, 0x2, 
		0x2, 0x16f, 0x172, 0x5, 0x2e, 0x18, 0x2, 0x170, 0x171, 0x7, 0x12, 0x2, 
		0x2, 0x171, 0x173, 0x5, 0x2e, 0x18, 0x2, 0x172, 0x170, 0x3, 0x2, 0x2, 
		0x2, 0x172, 0x173, 0x3, 0x2, 0x2, 0x2, 0x173, 0x39, 0x3, 0x2, 0x2, 0x2, 
		0x174, 0x17a, 0x5, 0x3c, 0x1f, 0x2, 0x175, 0x17a, 0x5, 0x3e, 0x20, 0x2, 
		0x176, 0x17a, 0x5, 0x40, 0x21, 0x2, 0x177, 0x17a, 0x5, 0x42, 0x22, 0x2, 
		0x178, 0x17a, 0x5, 0x46, 0x24, 0x2, 0x179, 0x174, 0x3, 0x2, 0x2, 0x2, 
		0x179, 0x175, 0x3, 0x2, 0x2, 0x2, 0x179, 0x176, 0x3, 0x2, 0x2, 0x2, 0x179, 
		0x177, 0x3, 0x2, 0x2, 0x2, 0x179, 0x178, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x3b, 
		0x3, 0x2, 0x2, 0x2, 0x17b, 0x17c, 0x7, 0x13, 0x2, 0x2, 0x17c, 0x17d, 0x7, 
		0x23, 0x2, 0x2, 0x17d, 0x17e, 0x5, 0x66, 0x34, 0x2, 0x17e, 0x17f, 0x7, 
		0x14, 0x2, 0x2, 0x17f, 0x180, 0x5, 0x52, 0x2a, 0x2, 0x180, 0x181, 0x7, 
		0x24, 0x2, 0x2, 0x181, 0x182, 0x5, 0x2e, 0x18, 0x2, 0x182, 0x3d, 0x3, 
		0x2, 0x2, 0x2, 0x183, 0x184, 0x7, 0x13, 0x2, 0x2, 0x184, 0x185, 0x7, 0x23, 
		0x2, 0x2, 0x185, 0x186, 0x5, 0x52, 0x2a, 0x2, 0x186, 0x187, 0x7, 0x2e, 
		0x2, 0x2, 0x187, 0x188, 0x5, 0x52, 0x2a, 0x2, 0x188, 0x189, 0x7, 0x2e, 
		0x2, 0x2, 0x189, 0x18a, 0x5, 0x52, 0x2a, 0x2, 0x18a, 0x18b, 0x7, 0x24, 
		0x2, 0x2, 0x18b, 0x18c, 0x5, 0x2e, 0x18, 0x2, 0x18c, 0x3f, 0x3, 0x2, 0x2, 
		0x2, 0x18d, 0x18e, 0x5, 0x44, 0x23, 0x2, 0x18e, 0x18f, 0x5, 0x2e, 0x18, 
		0x2, 0x18f, 0x41, 0x3, 0x2, 0x2, 0x2, 0x190, 0x191, 0x7, 0x15, 0x2, 0x2, 
		0x191, 0x192, 0x5, 0x2e, 0x18, 0x2, 0x192, 0x193, 0x5, 0x44, 0x23, 0x2, 
		0x193, 0x194, 0x7, 0x2e, 0x2, 0x2, 0x194, 0x43, 0x3, 0x2, 0x2, 0x2, 0x195, 
		0x196, 0x7, 0x16, 0x2, 0x2, 0x196, 0x197, 0x7, 0x23, 0x2, 0x2, 0x197, 
		0x198, 0x5, 0x52, 0x2a, 0x2, 0x198, 0x199, 0x7, 0x24, 0x2, 0x2, 0x199, 
		0x45, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x19b, 0x7, 0x17, 0x2, 0x2, 0x19b, 0x19c, 
		0x5, 0x2e, 0x18, 0x2, 0x19c, 0x47, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19f, 0x5, 
		0x66, 0x34, 0x2, 0x19e, 0x1a0, 0x5, 0x26, 0x14, 0x2, 0x19f, 0x19e, 0x3, 
		0x2, 0x2, 0x2, 0x19f, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a1, 0x3, 0x2, 
		0x2, 0x2, 0x1a1, 0x1aa, 0x7, 0x23, 0x2, 0x2, 0x1a2, 0x1a7, 0x5, 0x4a, 
		0x26, 0x2, 0x1a3, 0x1a4, 0x7, 0x2f, 0x2, 0x2, 0x1a4, 0x1a6, 0x5, 0x4a, 
		0x26, 0x2, 0x1a5, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a9, 0x3, 0x2, 0x2, 
		0x2, 0x1a7, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a8, 0x3, 0x2, 0x2, 0x2, 
		0x1a8, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1aa, 
		0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1ac, 
		0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ad, 0x7, 0x24, 0x2, 0x2, 0x1ad, 0x49, 0x3, 
		0x2, 0x2, 0x2, 0x1ae, 0x1af, 0x5, 0x52, 0x2a, 0x2, 0x1af, 0x4b, 0x3, 0x2, 
		0x2, 0x2, 0x1b0, 0x1b2, 0x5, 0x4e, 0x28, 0x2, 0x1b1, 0x1b0, 0x3, 0x2, 
		0x2, 0x2, 0x1b2, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b1, 0x3, 0x2, 0x2, 
		0x2, 0x1b3, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x4d, 0x3, 0x2, 0x2, 0x2, 
		0x1b5, 0x1b6, 0x7, 0x25, 0x2, 0x2, 0x1b6, 0x1b7, 0x5, 0x48, 0x25, 0x2, 
		0x1b7, 0x1b8, 0x7, 0x26, 0x2, 0x2, 0x1b8, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x1b9, 
		0x1be, 0x5, 0x66, 0x34, 0x2, 0x1ba, 0x1bb, 0x7, 0x2d, 0x2, 0x2, 0x1bb, 
		0x1bd, 0x5, 0x66, 0x34, 0x2, 0x1bc, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1bd, 
		0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1bf, 
		0x3, 0x2, 0x2, 0x2, 0x1bf, 0x51, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1be, 0x3, 
		0x2, 0x2, 0x2, 0x1c1, 0x1c2, 0x8, 0x2a, 0x1, 0x2, 0x1c2, 0x1cf, 0x7, 0x58, 
		0x2, 0x2, 0x1c3, 0x1c4, 0x7, 0x23, 0x2, 0x2, 0x1c4, 0x1c5, 0x5, 0x52, 
		0x2a, 0x2, 0x1c5, 0x1c6, 0x7, 0x24, 0x2, 0x2, 0x1c6, 0x1cf, 0x3, 0x2, 
		0x2, 0x2, 0x1c7, 0x1cf, 0x5, 0x48, 0x25, 0x2, 0x1c8, 0x1cf, 0x5, 0x5a, 
		0x2e, 0x2, 0x1c9, 0x1cf, 0x5, 0x66, 0x34, 0x2, 0x1ca, 0x1cf, 0x7, 0x56, 
		0x2, 0x2, 0x1cb, 0x1cf, 0x5, 0x56, 0x2c, 0x2, 0x1cc, 0x1cd, 0x7, 0x29, 
		0x2, 0x2, 0x1cd, 0x1cf, 0x5, 0x52, 0x2a, 0x4, 0x1ce, 0x1c1, 0x3, 0x2, 
		0x2, 0x2, 0x1ce, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1c7, 0x3, 0x2, 0x2, 
		0x2, 0x1ce, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1c9, 0x3, 0x2, 0x2, 0x2, 
		0x1ce, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1ce, 
		0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1d1, 
		0xc, 0x5, 0x2, 0x2, 0x1d1, 0x1d2, 0x5, 0x60, 0x31, 0x2, 0x1d2, 0x1d3, 
		0x5, 0x52, 0x2a, 0x6, 0x1d3, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1d4, 0x1d5, 
		0xc, 0xc, 0x2, 0x2, 0x1d5, 0x1d6, 0x7, 0x30, 0x2, 0x2, 0x1d6, 0x1dd, 0x5, 
		0x66, 0x34, 0x2, 0x1d7, 0x1d8, 0xc, 0xb, 0x2, 0x2, 0x1d8, 0x1d9, 0x7, 
		0x30, 0x2, 0x2, 0x1d9, 0x1dd, 0x5, 0x48, 0x25, 0x2, 0x1da, 0x1db, 0xc, 
		0x3, 0x2, 0x2, 0x1db, 0x1dd, 0x5, 0x54, 0x2b, 0x2, 0x1dc, 0x1d0, 0x3, 
		0x2, 0x2, 0x2, 0x1dc, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1d7, 0x3, 0x2, 
		0x2, 0x2, 0x1dc, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1e0, 0x3, 0x2, 0x2, 
		0x2, 0x1de, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1df, 0x3, 0x2, 0x2, 0x2, 
		0x1df, 0x53, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1e1, 
		0x1e3, 0x7, 0x25, 0x2, 0x2, 0x1e2, 0x1e4, 0x5, 0x52, 0x2a, 0x2, 0x1e3, 
		0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e3, 
		0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1e7, 0x3, 
		0x2, 0x2, 0x2, 0x1e7, 0x1e8, 0x7, 0x26, 0x2, 0x2, 0x1e8, 0x55, 0x3, 0x2, 
		0x2, 0x2, 0x1e9, 0x1ea, 0x7, 0x54, 0x2, 0x2, 0x1ea, 0x1eb, 0x9, 0x4, 0x2, 
		0x2, 0x1eb, 0x1ec, 0x5, 0x48, 0x25, 0x2, 0x1ec, 0x57, 0x3, 0x2, 0x2, 0x2, 
		0x1ed, 0x1ee, 0x5, 0x52, 0x2a, 0x2, 0x1ee, 0x1ef, 0x7, 0x32, 0x2, 0x2, 
		0x1ef, 0x1f0, 0x5, 0x52, 0x2a, 0x2, 0x1f0, 0x59, 0x3, 0x2, 0x2, 0x2, 0x1f1, 
		0x1f2, 0x7, 0x50, 0x2, 0x2, 0x1f2, 0x1f3, 0x5, 0x52, 0x2a, 0x2, 0x1f3, 
		0x5b, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1fd, 
		0x7, 0x34, 0x2, 0x2, 0x1f6, 0x1fd, 0x7, 0x35, 0x2, 0x2, 0x1f7, 0x1fd, 
		0x7, 0x36, 0x2, 0x2, 0x1f8, 0x1fd, 0x7, 0x37, 0x2, 0x2, 0x1f9, 0x1fd, 
		0x7, 0x38, 0x2, 0x2, 0x1fa, 0x1fd, 0x7, 0x39, 0x2, 0x2, 0x1fb, 0x1fd, 
		0x7, 0x3a, 0x2, 0x2, 0x1fc, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1f5, 0x3, 
		0x2, 0x2, 0x2, 0x1fc, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1f7, 0x3, 0x2, 
		0x2, 0x2, 0x1fc, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1f9, 0x3, 0x2, 0x2, 
		0x2, 0x1fc, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1fb, 0x3, 0x2, 0x2, 0x2, 
		0x1fd, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1ff, 0x9, 0x5, 0x2, 0x2, 0x1ff, 
		0x5f, 0x3, 0x2, 0x2, 0x2, 0x200, 0x204, 0x5, 0x62, 0x32, 0x2, 0x201, 0x204, 
		0x5, 0x5e, 0x30, 0x2, 0x202, 0x204, 0x5, 0x5c, 0x2f, 0x2, 0x203, 0x200, 
		0x3, 0x2, 0x2, 0x2, 0x203, 0x201, 0x3, 0x2, 0x2, 0x2, 0x203, 0x202, 0x3, 
		0x2, 0x2, 0x2, 0x204, 0x61, 0x3, 0x2, 0x2, 0x2, 0x205, 0x206, 0x9, 0x6, 
		0x2, 0x2, 0x206, 0x63, 0x3, 0x2, 0x2, 0x2, 0x207, 0x208, 0x7, 0x36, 0x2, 
		0x2, 0x208, 0x65, 0x3, 0x2, 0x2, 0x2, 0x209, 0x20a, 0x9, 0x7, 0x2, 0x2, 
		0x20a, 0x67, 0x3, 0x2, 0x2, 0x2, 0x36, 0x6d, 0x77, 0x7e, 0x81, 0x88, 0x97, 
		0xa0, 0xa3, 0xa8, 0xac, 0xb6, 0xb8, 0xbc, 0xbf, 0xcc, 0xd7, 0xdb, 0xe4, 
		0xe7, 0xec, 0xf3, 0xfe, 0x102, 0x105, 0x10d, 0x112, 0x116, 0x11e, 0x127, 
		0x12e, 0x134, 0x137, 0x13d, 0x142, 0x152, 0x159, 0x15f, 0x165, 0x169, 
		0x172, 0x179, 0x19f, 0x1a7, 0x1aa, 0x1b3, 0x1be, 0x1ce, 0x1dc, 0x1de, 
		0x1e5, 0x1fc, 0x203, 
	};

	atn::ATNDeserializer deserializer;
	_atn = deserializer.deserialize(_serializedATN);

	size_t count = _atn.getNumberOfDecisions();
	_decisionToDFA.reserve(count);
	for (size_t i = 0; i < count; i++)
	{ 
		_decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
	}
}

CMinusEqualsMinus1Revision0Parser::Initializer CMinusEqualsMinus1Revision0Parser::_init;
