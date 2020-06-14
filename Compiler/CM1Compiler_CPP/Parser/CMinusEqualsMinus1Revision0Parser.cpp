
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
		setState(75);//750
		_errHandler->sync(this, ctx);
		switch (_input->LA(1))
		{
			case CMinusEqualsMinus1Revision0Parser::T__0:
			{
				enterOuterAlt(ctx, 1);
				setState(70); //951
				languageStandardDeclaration(ctx);
				setState(71); //951
				declarationSequence(ctx);
				setState(72);//958
				match(CMinusEqualsMinus1Revision0Parser::EOF,ctx);
				break;
			}

			case CMinusEqualsMinus1Revision0Parser::T__3:
			case CMinusEqualsMinus1Revision0Parser::AccessSpecifier:
			case CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN:
			{
				enterOuterAlt(ctx, 2);
				setState(74); //951
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
		setState(77);//958
		match(CMinusEqualsMinus1Revision0Parser::T__0,ctx);
		setState(78);//958
		match(CMinusEqualsMinus1Revision0Parser::Asssigment,ctx);
		setState(79);//958
		match(CMinusEqualsMinus1Revision0Parser::IntegerLiteral,ctx);
		setState(80);//958
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
		setState(83); //814
		_errHandler->sync(this, ctx);
		_la = _input->LA(1);
		do
		{
			setState(82); //951
			declaration(ctx);
			setState(85); //820
			_errHandler->sync(this, ctx);
			_la = _input->LA(1);
		} while ((((_la & ~ 0x3fULL) == 0) &&
			((1ULL << _la) & ((1ULL << CMinusEqualsMinus1Revision0Parser::T__3)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::AccessSpecifier)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN))) != 0));
	 
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
		enterOuterAlt(ctx, 1);
		setState(87); //951
		functionDeclaration(ctx);
	 
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


//----------------- ClassDeclarationContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::ClassDeclarationContext::ClassDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ClassDeclarationContext::Class()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Class, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ClassDeclarationContext::Identifier()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Identifier, 0);
}

CMinusEqualsMinus1Revision0Parser::ImplementedInterfacesSequenceContext* CMinusEqualsMinus1Revision0Parser::ClassDeclarationContext::implementedInterfacesSequence()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ImplementedInterfacesSequenceContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ClassDeclarationContext::OpenBracket()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::OpenBracket, 0);
}

CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext* CMinusEqualsMinus1Revision0Parser::ClassDeclarationContext::classContentSequence()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ClassDeclarationContext::CloseBracket()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::CloseBracket, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ClassDeclarationContext::AccessSpecifier()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::AccessSpecifier, 0);
}


size_t CMinusEqualsMinus1Revision0Parser::ClassDeclarationContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleClassDeclaration;//688
}

void CMinusEqualsMinus1Revision0Parser::ClassDeclarationContext::copyFrom(ClassDeclarationContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::ClassDeclarationContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<ClassDeclarationContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::ClassDeclarationContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::ClassDeclarationContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::ClassDeclarationContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitClassDeclaration(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::ClassDeclarationContext* CMinusEqualsMinus1Revision0Parser::classDeclaration( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<ClassDeclarationContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 8, CMinusEqualsMinus1Revision0Parser::RuleClassDeclaration);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(90);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::AccessSpecifier)
		{
			setState(89);//958
			match(CMinusEqualsMinus1Revision0Parser::AccessSpecifier,ctx);
		}
		setState(92);//958
		match(CMinusEqualsMinus1Revision0Parser::Class,ctx);
		setState(93);//958
		match(CMinusEqualsMinus1Revision0Parser::Identifier,ctx);
		setState(94);//958
		match(CMinusEqualsMinus1Revision0Parser::T__1,ctx);
		setState(95); //951
		implementedInterfacesSequence(ctx);
		setState(96);//958
		match(CMinusEqualsMinus1Revision0Parser::OpenBracket,ctx);
		setState(97); //951
		classContentSequence(ctx);
		setState(98);//958
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

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::ClassDeclarationContext> CMinusEqualsMinus1Revision0Parser::parseclassDeclaration()
{
	classDeclaration();
	auto result = std::unique_ptr<ClassDeclarationContext>(dynamic_cast<ClassDeclarationContext*>(_root.release()));
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
	enterRule(std::move(_localctx), 10, CMinusEqualsMinus1Revision0Parser::RuleClassContentSequence);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(102); //814
		_errHandler->sync(this, ctx);
		_la = _input->LA(1);
		do
		{
			setState(102);//830
			_errHandler->sync(this, ctx);
			switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, ctx))
			{
			case 1:
			{
				setState(100); //951
				functionDeclaration(ctx);
				break;
			}

			case 2:
			{
				setState(101); //951
				fieldDeclaration(ctx);
				break;
			}

			}
			setState(104); //820
			_errHandler->sync(this, ctx);
			_la = _input->LA(1);
		} while ((((_la & ~ 0x3fULL) == 0) &&
			((1ULL << _la) & ((1ULL << CMinusEqualsMinus1Revision0Parser::T__3)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::AccessSpecifier)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::Identifier)
			| (1ULL << CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN))) != 0));
	 
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

CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext* CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext::qualifiedIdentifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext::Identifier()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Identifier, 0);
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
	enterRule(std::move(_localctx), 12, CMinusEqualsMinus1Revision0Parser::RuleFieldDeclaration);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(107);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN)
		{
			setState(106); //951
			attributeSequence(ctx);
		}
		setState(110);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::AccessSpecifier)
		{
			setState(109);//958
			match(CMinusEqualsMinus1Revision0Parser::AccessSpecifier,ctx);
		}
		setState(112); //951
		qualifiedIdentifier(ctx);
		setState(113);//958
		match(CMinusEqualsMinus1Revision0Parser::Identifier,ctx);
	 
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


//----------------- ImplementedInterfacesSequenceContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::ImplementedInterfacesSequenceContext::ImplementedInterfacesSequenceContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

std::vector<CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext *> CMinusEqualsMinus1Revision0Parser::ImplementedInterfacesSequenceContext::qualifiedIdentifier()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext* CMinusEqualsMinus1Revision0Parser::ImplementedInterfacesSequenceContext::qualifiedIdentifier(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext>(i);//1183
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
	enterRule(std::move(_localctx), 14, CMinusEqualsMinus1Revision0Parser::RuleImplementedInterfacesSequence);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		size_t alt;
		setState(125);//830
		_errHandler->sync(this, ctx);
		switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, ctx))
		{
		case 1:
		{
			enterOuterAlt(ctx, 1);
			setState(115); //951
			qualifiedIdentifier(ctx);
			break;
		}

		case 2:
		{
			enterOuterAlt(ctx, 2);
			setState(119); //883
			_errHandler->sync(this, ctx);
			alt = 1;
			do
			{
				switch (alt)
			{
					case 1:
					{
								setState(116); //951
								qualifiedIdentifier(ctx);
								setState(117);//958
								match(CMinusEqualsMinus1Revision0Parser::Comma,ctx);
								break;
							}

				default:
					throw NoViableAltException(this, ctx);
				}
				setState(121); //900
				_errHandler->sync(this, ctx);
				alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, ctx);
			} while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
			setState(123); //951
			qualifiedIdentifier(ctx);
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
	enterRule(std::move(_localctx), 16, CMinusEqualsMinus1Revision0Parser::RuleNamespaceDeclaration);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(127);//958
		match(CMinusEqualsMinus1Revision0Parser::T__2,ctx);
		setState(128); //951
		qualifiedIdentifier(ctx);
		setState(129);//958
		match(CMinusEqualsMinus1Revision0Parser::OpenBracket,ctx);
		setState(130); //951
		declarationSequence(ctx);
		setState(131);//958
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

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext::Identifier()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Identifier, 0);
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

CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext* CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext::qualifiedIdentifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext>(0);//1165
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
	enterRule(std::move(_localctx), 18, CMinusEqualsMinus1Revision0Parser::RuleFunctionDeclaration);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(134);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN)
		{
			setState(133); //951
			attributeSequence(ctx);
		}
		setState(137);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::AccessSpecifier)
		{
			setState(136);//958
			match(CMinusEqualsMinus1Revision0Parser::AccessSpecifier,ctx);
		}
		setState(139);//958
		match(CMinusEqualsMinus1Revision0Parser::T__3,ctx);
		setState(140);//958
		match(CMinusEqualsMinus1Revision0Parser::Identifier,ctx);
		setState(141);//958
		match(CMinusEqualsMinus1Revision0Parser::ParamOpen,ctx);
		setState(142); //951
		parameterList(ctx);
		setState(143);//958
		match(CMinusEqualsMinus1Revision0Parser::ParamClose,ctx);
		setState(144);//958
		match(CMinusEqualsMinus1Revision0Parser::T__4,ctx);
		setState(145); //951
		qualifiedIdentifier(ctx);
		setState(146); //951
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
	enterRule(std::move(_localctx), 20, CMinusEqualsMinus1Revision0Parser::RuleParameterList);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		size_t alt;
		setState(159);//830
		_errHandler->sync(this, ctx);
		switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, ctx))
		{
		case 1:
		{
			enterOuterAlt(ctx, 1);

			break;
		}

		case 2:
		{
			enterOuterAlt(ctx, 2);
			setState(149); //951
			parameter(ctx);
			break;
		}

		case 3:
		{
			enterOuterAlt(ctx, 3);
			setState(153); //883
			_errHandler->sync(this, ctx);
			alt = 1;
			do
			{
				switch (alt)
			{
					case 1:
					{
								setState(150); //951
								parameter(ctx);
								setState(151);//958
								match(CMinusEqualsMinus1Revision0Parser::Comma,ctx);
								break;
							}

				default:
					throw NoViableAltException(this, ctx);
				}
				setState(155); //900
				_errHandler->sync(this, ctx);
				alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, ctx);
			} while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
			setState(157); //951
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

CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext* CMinusEqualsMinus1Revision0Parser::ParameterContext::qualifiedIdentifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ParameterContext::Identifier()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Identifier, 0);
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
	enterRule(std::move(_localctx), 22, CMinusEqualsMinus1Revision0Parser::RuleParameter);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(162);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (_la == CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN)
		{
			setState(161); //951
			attributeSequence(ctx);
		}
		setState(164); //951
		qualifiedIdentifier(ctx);
		setState(165);//958
		match(CMinusEqualsMinus1Revision0Parser::Identifier,ctx);
	 
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
	enterRule(std::move(_localctx), 24, CMinusEqualsMinus1Revision0Parser::RuleFunctionBody);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(167);//958
		match(CMinusEqualsMinus1Revision0Parser::OpenBracket,ctx);
		setState(171);//800
		_errHandler->sync(this, ctx);
		_la = _input->LA(1);
		while (((((_la - 6) & ~ 0x3fULL) == 0) &&
			((1ULL << (_la - 6)) & ((1ULL << (CMinusEqualsMinus1Revision0Parser::T__5 - 6))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::T__6 - 6))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::T__8 - 6))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::T__9 - 6))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::T__10 - 6))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::Identifier - 6))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::ParamOpen - 6))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::Throw - 6)))) != 0))
		{
			setState(168); //951
			statement(ctx);
			setState(173);//806
			_errHandler->sync(this, ctx);
			_la = _input->LA(1);
		}
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

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::FunctionBodyContext> CMinusEqualsMinus1Revision0Parser::parsefunctionBody()
{
	functionBody();
	auto result = std::unique_ptr<FunctionBodyContext>(dynamic_cast<FunctionBodyContext*>(_root.release()));
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
	enterRule(std::move(_localctx), 26, CMinusEqualsMinus1Revision0Parser::RuleCompoundStatement);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		setState(185);//750
		_errHandler->sync(this, ctx);
		switch (_input->LA(1))
		{
			case CMinusEqualsMinus1Revision0Parser::OpenBracket:
			{
				enterOuterAlt(ctx, 1);
				setState(176);//958
				match(CMinusEqualsMinus1Revision0Parser::OpenBracket,ctx);
				setState(180);//800
				_errHandler->sync(this, ctx);
				_la = _input->LA(1);
				while (((((_la - 6) & ~ 0x3fULL) == 0) &&
					((1ULL << (_la - 6)) & ((1ULL << (CMinusEqualsMinus1Revision0Parser::T__5 - 6))
					| (1ULL << (CMinusEqualsMinus1Revision0Parser::T__6 - 6))
					| (1ULL << (CMinusEqualsMinus1Revision0Parser::T__8 - 6))
					| (1ULL << (CMinusEqualsMinus1Revision0Parser::T__9 - 6))
					| (1ULL << (CMinusEqualsMinus1Revision0Parser::T__10 - 6))
					| (1ULL << (CMinusEqualsMinus1Revision0Parser::Identifier - 6))
					| (1ULL << (CMinusEqualsMinus1Revision0Parser::ParamOpen - 6))
					| (1ULL << (CMinusEqualsMinus1Revision0Parser::Throw - 6)))) != 0))
				{
					setState(177); //951
					statement(ctx);
					setState(182);//806
					_errHandler->sync(this, ctx);
					_la = _input->LA(1);
				}
				setState(183);//958
				match(CMinusEqualsMinus1Revision0Parser::CloseBracket,ctx);
				break;
			}

			case CMinusEqualsMinus1Revision0Parser::T__5:
			case CMinusEqualsMinus1Revision0Parser::T__6:
			case CMinusEqualsMinus1Revision0Parser::T__8:
			case CMinusEqualsMinus1Revision0Parser::T__9:
			case CMinusEqualsMinus1Revision0Parser::T__10:
			case CMinusEqualsMinus1Revision0Parser::Identifier:
			case CMinusEqualsMinus1Revision0Parser::ParamOpen:
			case CMinusEqualsMinus1Revision0Parser::Throw:
			{
				enterOuterAlt(ctx, 2);
				setState(184); //951
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

CMinusEqualsMinus1Revision0Parser::ExpressionContext* CMinusEqualsMinus1Revision0Parser::StatementContext::expression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ExpressionContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::StatementContext::SemiColon()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::SemiColon, 0);
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
	enterRule(std::move(_localctx), 28, CMinusEqualsMinus1Revision0Parser::RuleStatement);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		setState(195);//830
		_errHandler->sync(this, ctx);
		switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, ctx))
		{
		case 1:
		{
			enterOuterAlt(ctx, 1);
			setState(187); //951
			expression(ctx);
			setState(188);//958
			match(CMinusEqualsMinus1Revision0Parser::SemiColon,ctx);
			break;
		}

		case 2:
		{
			enterOuterAlt(ctx, 2);
			setState(190); //951
			ifStatement(ctx);
			break;
		}

		case 3:
		{
			enterOuterAlt(ctx, 3);
			setState(191); //951
			loopStatement(ctx);
			break;
		}

		case 4:
		{
			enterOuterAlt(ctx, 4);
			setState(192); //951
			assigmentStatement(ctx);
			setState(193);//958
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


//----------------- IfStatementContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::IfStatementContext::IfStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::IfStatementContext::ParamOpen()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ParamOpen, 0);
}

CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext* CMinusEqualsMinus1Revision0Parser::IfStatementContext::logicalExpression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::IfStatementContext::ParamClose()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ParamClose, 0);
}

CMinusEqualsMinus1Revision0Parser::CompoundStatementContext* CMinusEqualsMinus1Revision0Parser::IfStatementContext::compoundStatement()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::CompoundStatementContext>(0);//1165
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
	enterRule(std::move(_localctx), 30, CMinusEqualsMinus1Revision0Parser::RuleIfStatement);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(197);//958
		match(CMinusEqualsMinus1Revision0Parser::T__5,ctx);
		setState(198);//958
		match(CMinusEqualsMinus1Revision0Parser::ParamOpen,ctx);
		setState(199); //951
		logicalExpression(0,ctx);
		setState(200);//958
		match(CMinusEqualsMinus1Revision0Parser::ParamClose,ctx);
		setState(201); //951
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
	enterRule(std::move(_localctx), 32, CMinusEqualsMinus1Revision0Parser::RuleLoopStatement);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		setState(208);//830
		_errHandler->sync(this, ctx);
		switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, ctx))
		{
		case 1:
		{
			enterOuterAlt(ctx, 1);
			setState(203); //951
			rangeForStatement(ctx);
			break;
		}

		case 2:
		{
			enterOuterAlt(ctx, 2);
			setState(204); //951
			forStatement(ctx);
			break;
		}

		case 3:
		{
			enterOuterAlt(ctx, 3);
			setState(205); //951
			whileStatement(ctx);
			break;
		}

		case 4:
		{
			enterOuterAlt(ctx, 4);
			setState(206); //951
			doWhileStatement(ctx);
			break;
		}

		case 5:
		{
			enterOuterAlt(ctx, 5);
			setState(207); //951
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

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::RangeForStatementContext::Identifier()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Identifier, 0);
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
	enterRule(std::move(_localctx), 34, CMinusEqualsMinus1Revision0Parser::RuleRangeForStatement);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(210);//958
		match(CMinusEqualsMinus1Revision0Parser::T__6,ctx);
		setState(211);//958
		match(CMinusEqualsMinus1Revision0Parser::ParamOpen,ctx);
		setState(212);//958
		match(CMinusEqualsMinus1Revision0Parser::Identifier,ctx);
		setState(213);//958
		match(CMinusEqualsMinus1Revision0Parser::T__7,ctx);
		setState(214); //951
		expression(ctx);
		setState(215);//958
		match(CMinusEqualsMinus1Revision0Parser::ParamClose,ctx);
		setState(216); //951
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

CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext* CMinusEqualsMinus1Revision0Parser::ForStatementContext::logicalExpression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext>(0);//1165
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
	enterRule(std::move(_localctx), 36, CMinusEqualsMinus1Revision0Parser::RuleForStatement);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(218);//958
		match(CMinusEqualsMinus1Revision0Parser::T__6,ctx);
		setState(219);//958
		match(CMinusEqualsMinus1Revision0Parser::ParamOpen,ctx);
		setState(220); //951
		expression(ctx);
		setState(221);//958
		match(CMinusEqualsMinus1Revision0Parser::SemiColon,ctx);
		setState(222); //951
		logicalExpression(0,ctx);
		setState(223);//958
		match(CMinusEqualsMinus1Revision0Parser::SemiColon,ctx);
		setState(224); //951
		expression(ctx);
		setState(225);//958
		match(CMinusEqualsMinus1Revision0Parser::ParamClose,ctx);
		setState(226); //951
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
	enterRule(std::move(_localctx), 38, CMinusEqualsMinus1Revision0Parser::RuleWhileStatement);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(228); //951
		whileHeader(ctx);
		setState(229); //951
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
	enterRule(std::move(_localctx), 40, CMinusEqualsMinus1Revision0Parser::RuleDoWhileStatement);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(231);//958
		match(CMinusEqualsMinus1Revision0Parser::T__8,ctx);
		setState(232); //951
		compoundStatement(ctx);
		setState(233); //951
		whileHeader(ctx);
		setState(234);//958
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

CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext* CMinusEqualsMinus1Revision0Parser::WhileHeaderContext::logicalExpression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext>(0);//1165
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
	enterRule(std::move(_localctx), 42, CMinusEqualsMinus1Revision0Parser::RuleWhileHeader);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(236);//958
		match(CMinusEqualsMinus1Revision0Parser::T__9,ctx);
		setState(237);//958
		match(CMinusEqualsMinus1Revision0Parser::ParamOpen,ctx);
		setState(238); //951
		logicalExpression(0,ctx);
		setState(239);//958
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
	enterRule(std::move(_localctx), 44, CMinusEqualsMinus1Revision0Parser::RuleInfiniteLoopStatement);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(241);//958
		match(CMinusEqualsMinus1Revision0Parser::T__10,ctx);
		setState(242); //951
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

CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext* CMinusEqualsMinus1Revision0Parser::FunctionCallContext::qualifiedIdentifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::FunctionCallContext::ParamOpen()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ParamOpen, 0);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::FunctionCallContext::ParamClose()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ParamClose, 0);
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
	enterRule(std::move(_localctx), 46, CMinusEqualsMinus1Revision0Parser::RuleFunctionCall);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(244); //951
		qualifiedIdentifier(ctx);
		setState(245);//958
		match(CMinusEqualsMinus1Revision0Parser::ParamOpen,ctx);
		setState(254);//788
		_errHandler->sync(this, ctx);

		_la = _input->LA(1);
		if (((((_la - 13) & ~ 0x3fULL) == 0) &&
			((1ULL << (_la - 13)) & ((1ULL << (CMinusEqualsMinus1Revision0Parser::Identifier - 13))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::ParamOpen - 13))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::ArithmeticUnaryOperator - 13))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::LogicalUnaryOperator - 13))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::Throw - 13))
			| (1ULL << (CMinusEqualsMinus1Revision0Parser::IntegerLiteral - 13)))) != 0))
		{
			setState(246); //951
			functionCallParameter(ctx);
			setState(251);//800
			_errHandler->sync(this, ctx);
			_la = _input->LA(1);
			while (_la == CMinusEqualsMinus1Revision0Parser::Comma)
			{
				setState(247);//958
				match(CMinusEqualsMinus1Revision0Parser::Comma,ctx);
				setState(248); //951
				functionCallParameter(ctx);
				setState(253);//806
				_errHandler->sync(this, ctx);
				_la = _input->LA(1);
			}
		}
		setState(256);//958
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

CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext* CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext::arithmeticExpression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext* CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext::logicalExpression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext>(0);//1165
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
	enterRule(std::move(_localctx), 48, CMinusEqualsMinus1Revision0Parser::RuleFunctionCallParameter);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		setState(261);//830
		_errHandler->sync(this, ctx);
		switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, ctx))
		{
		case 1:
		{
			enterOuterAlt(ctx, 1);
			setState(258); //951
			expression(ctx);
			break;
		}

		case 2:
		{
			enterOuterAlt(ctx, 2);
			setState(259); //951
			arithmeticExpression(0,ctx);
			break;
		}

		case 3:
		{
			enterOuterAlt(ctx, 3);
			setState(260); //951
			logicalExpression(0,ctx);
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
	enterRule(std::move(_localctx), 50, CMinusEqualsMinus1Revision0Parser::RuleAttributeSequence);
	size_t _la = 0;

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(264); //814
		_errHandler->sync(this, ctx);
		_la = _input->LA(1);
		do
		{
			setState(263); //951
			attribute(ctx);
			setState(266); //820
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
	enterRule(std::move(_localctx), 52, CMinusEqualsMinus1Revision0Parser::RuleAttribute);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(268);//958
		match(CMinusEqualsMinus1Revision0Parser::ATTROBITEOPEN,ctx);
		setState(269); //951
		functionCall(ctx);
		setState(270);//958
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

std::vector<tree::TerminalNode *> CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext::Identifier()
{
	return getTokens(CMinusEqualsMinus1Revision0Parser::Identifier);
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext::Identifier(size_t i)
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Identifier, i);
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
	enterRule(std::move(_localctx), 54, CMinusEqualsMinus1Revision0Parser::RuleQualifiedIdentifier);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		size_t alt;
		enterOuterAlt(ctx, 1);
		setState(272);//958
		match(CMinusEqualsMinus1Revision0Parser::Identifier,ctx);
		setState(277);//865
		_errHandler->sync(this, ctx);
		alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, ctx);
		while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER)
		{
			if (alt == 1)
		{
				setState(273);//958
				match(CMinusEqualsMinus1Revision0Parser::DoubleColon,ctx);
				setState(274);//958
				match(CMinusEqualsMinus1Revision0Parser::Identifier,ctx); 
			}
			setState(279);//875
			_errHandler->sync(this, ctx);
			alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, ctx);
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

CMinusEqualsMinus1Revision0Parser::FunctionCallContext* CMinusEqualsMinus1Revision0Parser::ExpressionContext::functionCall()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::FunctionCallContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext* CMinusEqualsMinus1Revision0Parser::ExpressionContext::throwExpression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext* CMinusEqualsMinus1Revision0Parser::ExpressionContext::qualifiedIdentifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ExpressionContext::ParamOpen()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ParamOpen, 0);
}

CMinusEqualsMinus1Revision0Parser::ExpressionContext* CMinusEqualsMinus1Revision0Parser::ExpressionContext::expression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ExpressionContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ExpressionContext::ParamClose()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ParamClose, 0);
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

CMinusEqualsMinus1Revision0Parser::ExpressionContext* CMinusEqualsMinus1Revision0Parser::expression( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<ExpressionContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 56, CMinusEqualsMinus1Revision0Parser::RuleExpression);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		setState(287);//830
		_errHandler->sync(this, ctx);
		switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, ctx))
		{
		case 1:
		{
			enterOuterAlt(ctx, 1);
			setState(280); //951
			functionCall(ctx);
			break;
		}

		case 2:
		{
			enterOuterAlt(ctx, 2);
			setState(281); //951
			throwExpression(ctx);
			break;
		}

		case 3:
		{
			enterOuterAlt(ctx, 3);
			setState(282); //951
			qualifiedIdentifier(ctx);
			break;
		}

		case 4:
		{
			enterOuterAlt(ctx, 4);
			setState(283);//958
			match(CMinusEqualsMinus1Revision0Parser::ParamOpen,ctx);
			setState(284); //951
			expression(ctx);
			setState(285);//958
			match(CMinusEqualsMinus1Revision0Parser::ParamClose,ctx);
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

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::ExpressionContext> CMinusEqualsMinus1Revision0Parser::parseexpression()
{
	expression();
	auto result = std::unique_ptr<ExpressionContext>(dynamic_cast<ExpressionContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- ArithmeticExpressionContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext::ArithmeticExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::FunctionCallContext* CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext::functionCall()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::FunctionCallContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext* CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext::qualifiedIdentifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext::ArithmeticUnaryOperator()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ArithmeticUnaryOperator, 0);
}

std::vector<CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext *> CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext::arithmeticExpression()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext* CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext::arithmeticExpression(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext>(i);//1183
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext::IntegerLiteral()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::IntegerLiteral, 0);
}

CMinusEqualsMinus1Revision0Parser::ExpressionContext* CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext::expression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ExpressionContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext::ArithmeticBinaryOperator()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ArithmeticBinaryOperator, 0);
}


size_t CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleArithmeticExpression;//688
}

void CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext::copyFrom(ArithmeticExpressionContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<ArithmeticExpressionContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitArithmeticExpression(this);
	else
		return visitor->visitChildren(this);
}


CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext* CMinusEqualsMinus1Revision0Parser::arithmeticExpression()
{
	 return arithmeticExpression(0, nullptr);//600
}

CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext* CMinusEqualsMinus1Revision0Parser::arithmeticExpression(int precedence, antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	antlr4::ParserRuleContext *parentContext = parent;
	size_t parentState = getState();
	auto _localctx = std::make_unique<ArithmeticExpressionContext>(parentContext, parentState);//610
	auto ctx = _localctx.get();//609
	size_t startState = 58;
	enterRecursionRule(ctx, 58, CMinusEqualsMinus1Revision0Parser::RuleArithmeticExpression, precedence);

		

	auto onExit = finally([=,&_localctx]
{
		unrollRecursionContexts(parentContext, std::move(_localctx));
	});
	try
{
		size_t alt;
		enterOuterAlt(ctx, 1);
		setState(296);//830
		_errHandler->sync(this, ctx);
		switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, ctx))
		{
		case 1:
		{
			setState(290); //951
			functionCall(ctx);
			break;
		}

		case 2:
		{
			setState(291); //951
			qualifiedIdentifier(ctx);
			break;
		}

		case 3:
		{
			setState(292);//958
			match(CMinusEqualsMinus1Revision0Parser::ArithmeticUnaryOperator,ctx);
			setState(293); //951
			arithmeticExpression(3,ctx);
			break;
		}

		case 4:
		{
			setState(294);//958
			match(CMinusEqualsMinus1Revision0Parser::IntegerLiteral,ctx);
			break;
		}

		case 5:
		{
			setState(295); //951
			expression(ctx);
			break;
		}

		}
		ctx->stop = _input->LT(-1);
		setState(303);//865
		_errHandler->sync(this, ctx);
		alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, ctx);
		while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER)
		{
			if (alt == 1)
		{
				if (!_parseListeners.empty())
					triggerExitRuleEvent(ctx);

				auto tmpContext = std::make_unique<ArithmeticExpressionContext>(parentContext, parentState);
				pushNewRecursionContext(std::move(_localctx), tmpContext.get(), startState, RuleArithmeticExpression);//1240
				_localctx = std::move(tmpContext);
				ctx = _localctx.get();
				setState(298);//1002

				if (!(precpred(nullptr, 6))) throw FailedPredicateException(this, "precpred(nullptr, 6)", ctx);
				setState(299);//958
				match(CMinusEqualsMinus1Revision0Parser::ArithmeticBinaryOperator,ctx);
				setState(300); //951
				arithmeticExpression(7,ctx); 
			}
			setState(305);//875
			_errHandler->sync(this, ctx);
			alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, ctx);
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

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext> CMinusEqualsMinus1Revision0Parser::parsearithmeticExpression()
{
	arithmeticExpression();
	auto result = std::unique_ptr<ArithmeticExpressionContext>(dynamic_cast<ArithmeticExpressionContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}

//----------------- LogicalExpressionContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext::LogicalExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::FunctionCallContext* CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext::functionCall()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::FunctionCallContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext* CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext::qualifiedIdentifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext::LogicalUnaryOperator()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::LogicalUnaryOperator, 0);
}

std::vector<CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext *> CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext::logicalExpression()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext* CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext::logicalExpression(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext>(i);//1183
}

CMinusEqualsMinus1Revision0Parser::ComparisonExpressionContext* CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext::comparisonExpression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ComparisonExpressionContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::ExpressionContext* CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext::expression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ExpressionContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext::LogicalBinaryOperator()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::LogicalBinaryOperator, 0);
}


size_t CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleLogicalExpression;//688
}

void CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext::copyFrom(LogicalExpressionContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<LogicalExpressionContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitLogicalExpression(this);
	else
		return visitor->visitChildren(this);
}


CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext* CMinusEqualsMinus1Revision0Parser::logicalExpression()
{
	 return logicalExpression(0, nullptr);//600
}

CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext* CMinusEqualsMinus1Revision0Parser::logicalExpression(int precedence, antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	antlr4::ParserRuleContext *parentContext = parent;
	size_t parentState = getState();
	auto _localctx = std::make_unique<LogicalExpressionContext>(parentContext, parentState);//610
	auto ctx = _localctx.get();//609
	size_t startState = 60;
	enterRecursionRule(ctx, 60, CMinusEqualsMinus1Revision0Parser::RuleLogicalExpression, precedence);

		

	auto onExit = finally([=,&_localctx]
{
		unrollRecursionContexts(parentContext, std::move(_localctx));
	});
	try
{
		size_t alt;
		enterOuterAlt(ctx, 1);
		setState(313);//830
		_errHandler->sync(this, ctx);
		switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, ctx))
		{
		case 1:
		{
			setState(307); //951
			functionCall(ctx);
			break;
		}

		case 2:
		{
			setState(308); //951
			qualifiedIdentifier(ctx);
			break;
		}

		case 3:
		{
			setState(309);//958
			match(CMinusEqualsMinus1Revision0Parser::LogicalUnaryOperator,ctx);
			setState(310); //951
			logicalExpression(3,ctx);
			break;
		}

		case 4:
		{
			setState(311); //951
			comparisonExpression(ctx);
			break;
		}

		case 5:
		{
			setState(312); //951
			expression(ctx);
			break;
		}

		}
		ctx->stop = _input->LT(-1);
		setState(320);//865
		_errHandler->sync(this, ctx);
		alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, ctx);
		while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER)
		{
			if (alt == 1)
		{
				if (!_parseListeners.empty())
					triggerExitRuleEvent(ctx);

				auto tmpContext = std::make_unique<LogicalExpressionContext>(parentContext, parentState);
				pushNewRecursionContext(std::move(_localctx), tmpContext.get(), startState, RuleLogicalExpression);//1240
				_localctx = std::move(tmpContext);
				ctx = _localctx.get();
				setState(315);//1002

				if (!(precpred(nullptr, 6))) throw FailedPredicateException(this, "precpred(nullptr, 6)", ctx);
				setState(316);//958
				match(CMinusEqualsMinus1Revision0Parser::LogicalBinaryOperator,ctx);
				setState(317); //951
				logicalExpression(7,ctx); 
			}
			setState(322);//875
			_errHandler->sync(this, ctx);
			alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, ctx);
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

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext> CMinusEqualsMinus1Revision0Parser::parselogicalExpression()
{
	logicalExpression();
	auto result = std::unique_ptr<LogicalExpressionContext>(dynamic_cast<LogicalExpressionContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}

//----------------- ComparisonExpressionContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::ComparisonExpressionContext::ComparisonExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

std::vector<CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext *> CMinusEqualsMinus1Revision0Parser::ComparisonExpressionContext::arithmeticExpression()
{
	return getRuleContexts<CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext>();//1174
}

CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext* CMinusEqualsMinus1Revision0Parser::ComparisonExpressionContext::arithmeticExpression(size_t i)
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext>(i);//1183
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::ComparisonExpressionContext::ComparsionOperator()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::ComparsionOperator, 0);
}


size_t CMinusEqualsMinus1Revision0Parser::ComparisonExpressionContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleComparisonExpression;//688
}

void CMinusEqualsMinus1Revision0Parser::ComparisonExpressionContext::copyFrom(ComparisonExpressionContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::ComparisonExpressionContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<ComparisonExpressionContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::ComparisonExpressionContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::ComparisonExpressionContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::ComparisonExpressionContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitComparisonExpression(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::ComparisonExpressionContext* CMinusEqualsMinus1Revision0Parser::comparisonExpression( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<ComparisonExpressionContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 62, CMinusEqualsMinus1Revision0Parser::RuleComparisonExpression);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(323); //951
		arithmeticExpression(0,ctx);
		setState(324);//958
		match(CMinusEqualsMinus1Revision0Parser::ComparsionOperator,ctx);
		setState(325); //951
		arithmeticExpression(0,ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::ComparisonExpressionContext> CMinusEqualsMinus1Revision0Parser::parsecomparisonExpression()
{
	comparisonExpression();
	auto result = std::unique_ptr<ComparisonExpressionContext>(dynamic_cast<ComparisonExpressionContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- AssigmentStatementContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext::AssigmentStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::LExpressionContext* CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext::lExpression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::LExpressionContext>(0);//1165
}

tree::TerminalNode* CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext::Asssigment()
{
	return getToken(CMinusEqualsMinus1Revision0Parser::Asssigment, 0);
}

CMinusEqualsMinus1Revision0Parser::ExpressionContext* CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext::expression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ExpressionContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext* CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext::arithmeticExpression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext>(0);//1165
}

CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext* CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext::logicalExpression()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext>(0);//1165
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
	enterRule(std::move(_localctx), 64, CMinusEqualsMinus1Revision0Parser::RuleAssigmentStatement);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(327); //951
		lExpression(ctx);
		setState(328);//958
		match(CMinusEqualsMinus1Revision0Parser::Asssigment,ctx);
		setState(332);//830
		_errHandler->sync(this, ctx);
		switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, ctx))
		{
		case 1:
		{
			setState(329); //951
			expression(ctx);
			break;
		}

		case 2:
		{
			setState(330); //951
			arithmeticExpression(0,ctx);
			break;
		}

		case 3:
		{
			setState(331); //951
			logicalExpression(0,ctx);
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

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext> CMinusEqualsMinus1Revision0Parser::parseassigmentStatement()
{
	assigmentStatement();
	auto result = std::unique_ptr<AssigmentStatementContext>(dynamic_cast<AssigmentStatementContext*>(_root.release()));
	assert(result != nullptr);
	return result;
}


//----------------- LExpressionContext ------------------------------------------------------------------

CMinusEqualsMinus1Revision0Parser::LExpressionContext::LExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState)
	: antlr4::ParserRuleContext(parent, invokingState)
{
}

CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext* CMinusEqualsMinus1Revision0Parser::LExpressionContext::qualifiedIdentifier()
{
	return getRuleContext<CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext>(0);//1165
}


size_t CMinusEqualsMinus1Revision0Parser::LExpressionContext::getRuleIndex() const
{
	return CMinusEqualsMinus1Revision0Parser::RuleLExpression;//688
}

void CMinusEqualsMinus1Revision0Parser::LExpressionContext::copyFrom(LExpressionContext *ctx)
{
	antlr4::ParserRuleContext::copyFrom(ctx);
}

std::unique_ptr<antlr4::tree::ParseTree> CMinusEqualsMinus1Revision0Parser::LExpressionContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<LExpressionContext>();
	result->copyFrom(this);
	result->parent = parent;
	return result;
}
void CMinusEqualsMinus1Revision0Parser::LExpressionContext::enterRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->enter(this);
}

void CMinusEqualsMinus1Revision0Parser::LExpressionContext::exitRule(not_null<tree::ParseTreeListener*> listener)
{
	auto parserListener = dynamic_cast<CMinusEqualsMinus1Revision0Listener *>(listener.get());//1212
	if (parserListener != nullptr)
		parserListener->exit(this);
}


antlrcpp::Any CMinusEqualsMinus1Revision0Parser::LExpressionContext::accept(tree::ParseTreeVisitor *visitor)
{
	if (auto parserVisitor = dynamic_cast<CMinusEqualsMinus1Revision0Visitor*>(visitor))//1226
		return parserVisitor->visitLExpression(this);
	else
		return visitor->visitChildren(this);
}

CMinusEqualsMinus1Revision0Parser::LExpressionContext* CMinusEqualsMinus1Revision0Parser::lExpression( antlr4::ParserRuleContext *parent)
{
#ifdef PARSER_DEBUG
	if(parent != nullptr)
		std::cout<<parent->getText()<<std::endl;
#endif
	auto _localctx = std::make_unique<LExpressionContext>(parent, getState());//549
	auto ctx = _localctx.get();//549
	enterRule(std::move(_localctx), 66, CMinusEqualsMinus1Revision0Parser::RuleLExpression);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(334); //951
		qualifiedIdentifier(ctx);
	 
	}
	catch (RecognitionException &e)
{
		_errHandler->reportError(this, e, ctx);
		ctx->exception = std::current_exception();
		_errHandler->recover(this, ctx->exception, ctx);
	}

	return ctx;
}

std::unique_ptr< CMinusEqualsMinus1Revision0Parser::LExpressionContext> CMinusEqualsMinus1Revision0Parser::parselExpression()
{
	lExpression();
	auto result = std::unique_ptr<LExpressionContext>(dynamic_cast<LExpressionContext*>(_root.release()));
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
	enterRule(std::move(_localctx), 68, CMinusEqualsMinus1Revision0Parser::RuleThrowExpression);

	auto onExit = finally([=]
{
		exitRule(ctx);
	});
	try
{
		enterOuterAlt(ctx, 1);
		setState(336);//958
		match(CMinusEqualsMinus1Revision0Parser::Throw,ctx);
		setState(337); //951
		expression(ctx);
	 
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


bool CMinusEqualsMinus1Revision0Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex)
{
	switch (ruleIndex)
{
		case 29: return arithmeticExpressionSempred(dynamic_cast<ArithmeticExpressionContext *>(context), predicateIndex);

		case 30: return logicalExpressionSempred(dynamic_cast<LogicalExpressionContext *>(context), predicateIndex);//430

	default:
		break;
	}
	return true;
}

bool CMinusEqualsMinus1Revision0Parser::arithmeticExpressionSempred(ArithmeticExpressionContext *_localctx, size_t predicateIndex)
{
	switch (predicateIndex)
{
		case 0: return precpred(nullptr, 6);

	default:
		break;
	}
	return true;
}

bool CMinusEqualsMinus1Revision0Parser::logicalExpressionSempred(LogicalExpressionContext *_localctx, size_t predicateIndex)
{
	switch (predicateIndex)
{
		case 1: return precpred(nullptr, 6);

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
	"declaration", "classDeclaration", "classContentSequence", "fieldDeclaration", 
	"implementedInterfacesSequence", "namespaceDeclaration", "functionDeclaration", 
	"parameterList", "parameter", "functionBody", "compoundStatement", "statement", 
	"ifStatement", "loopStatement", "rangeForStatement", "forStatement", "whileStatement", 
	"doWhileStatement", "whileHeader", "infiniteLoopStatement", "functionCall", 
	"functionCallParameter", "attributeSequence", "attribute", "qualifiedIdentifier", 
	"expression", "arithmeticExpression", "logicalExpression", "comparisonExpression", 
	"assigmentStatement", "lExpression", "throwExpression"
};

std::vector<std::string_view> CMinusEqualsMinus1Revision0Parser::_literalNames =
{
	"", "'standard'", "':'", "'namespace'", "'fn'", "'->'", "'if'", "'for'", 
	"'in'", "'do'", "'while'", "'loop'", "", "", "'{'", "'}'", "", "'\"'", 
	"'''", "'('", "')'", "'['", "']'", "", "", "", "", "", "", "'::'", "';'", 
	"','", "'.'", "", "'='", "", "'+'", "'-'", "'*'", "'+='", "'-='", "'*='", 
	"'/='", "'>'", "'<'", "'>='", "'<='", "", "", "'||'", "'&&'", "'^^'", "", 
	"'?'", "'^'", "'&'", "'class'", "'interface'", "'public'", "'private'", 
	"'protected'", "'internal'", "'final'", "'virtual'", "'abstract'", "'override'", 
	"", "'attribute'", "'throw'"
};

std::vector<std::string_view> CMinusEqualsMinus1Revision0Parser::_symbolicNames =
{
	"", "", "", "", "", "", "", "", "", "", "", "", "AccessSpecifier", "Identifier", 
	"OpenBracket", "CloseBracket", "RAWSTRING", "DOUBLEQUOTE", "SINGLEQUOTE", 
	"ParamOpen", "ParamClose", "ATTROBITEOPEN", "ATTROBITECLOSE", "ArithmeticBinaryOperator", 
	"ArithmeticUnaryOperator", "ComparsionOperator", "LogicalBinaryOperator", 
	"LogicalUnaryOperator", "Not", "DoubleColon", "SemiColon", "Comma", "Period", 
	"Equals", "Asssigment", "NotEquals", "Plus", "Minus", "Star", "PlusEquals", 
	"MinusEquals", "MultiplyEquals", "DivideEquals", "GreaterThan", "LessThan", 
	"GreaterEqual", "LessEqual", "Equal", "NotEqual", "Or", "And", "Xor", "Strong", 
	"Nullable", "Mutable", "Ref", "Class", "Interface", "Public", "Private", 
	"Protected", "Internal", "Final", "Virtual", "Abstract", "Override", "DefaultSpecification", 
	"Attribute", "Throw", "IntegerLiteral", "DIGIT", "LETTER", "Whitespace", 
	"Newline", "BlockComment", "LineComment"
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
		0x4d, 0x156, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 0x4, 
		0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 0x8, 
		0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 0xb, 
		0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 0xf, 
		0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 0x9, 
		0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 
		0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 
		0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 
		0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 
		0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 
		0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
		0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x4e, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
		0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x6, 0x4, 0x56, 0xa, 0x4, 0xd, 0x4, 
		0xe, 0x4, 0x57, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x5, 0x6, 0x5d, 0xa, 0x6, 
		0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
		0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x6, 0x7, 0x69, 0xa, 0x7, 0xd, 0x7, 0xe, 
		0x7, 0x6a, 0x3, 0x8, 0x5, 0x8, 0x6e, 0xa, 0x8, 0x3, 0x8, 0x5, 0x8, 0x71, 
		0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
		0x3, 0x9, 0x6, 0x9, 0x7a, 0xa, 0x9, 0xd, 0x9, 0xe, 0x9, 0x7b, 0x3, 0x9, 
		0x3, 0x9, 0x5, 0x9, 0x80, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
		0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x5, 0xb, 0x89, 0xa, 0xb, 0x3, 0xb, 
		0x5, 0xb, 0x8c, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
		0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
		0xc, 0x3, 0xc, 0x3, 0xc, 0x6, 0xc, 0x9c, 0xa, 0xc, 0xd, 0xc, 0xe, 0xc, 
		0x9d, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xa2, 0xa, 0xc, 0x3, 0xd, 0x5, 0xd, 
		0xa5, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x7, 
		0xe, 0xac, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xaf, 0xb, 0xe, 0x3, 0xe, 0x3, 
		0xe, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xb5, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 
		0xb8, 0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xbc, 0xa, 0xf, 0x3, 0x10, 
		0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
		0x10, 0x5, 0x10, 0xc6, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
		0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
		0x3, 0x12, 0x5, 0x12, 0xd3, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
		0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 
		0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
		0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 
		0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
		0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 
		0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0xfc, 0xa, 0x19, 0xc, 
		0x19, 0xe, 0x19, 0xff, 0xb, 0x19, 0x5, 0x19, 0x101, 0xa, 0x19, 0x3, 0x19, 
		0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x108, 0xa, 0x1a, 
		0x3, 0x1b, 0x6, 0x1b, 0x10b, 0xa, 0x1b, 0xd, 0x1b, 0xe, 0x1b, 0x10c, 0x3, 
		0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
		0x7, 0x1d, 0x116, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x119, 0xb, 0x1d, 0x3, 
		0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 
		0x5, 0x1e, 0x122, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
		0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x12b, 0xa, 0x1f, 0x3, 0x1f, 
		0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 0x130, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 
		0x133, 0xb, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
		0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x13c, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 
		0x3, 0x20, 0x7, 0x20, 0x141, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x144, 0xb, 
		0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 
		0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x14f, 0xa, 0x22, 0x3, 0x23, 
		0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x2, 0x4, 0x3c, 
		0x3e, 0x25, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
		0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 
		0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 
		0x2, 0x2, 0x2, 0x160, 0x2, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4, 0x4f, 0x3, 0x2, 
		0x2, 0x2, 0x6, 0x55, 0x3, 0x2, 0x2, 0x2, 0x8, 0x59, 0x3, 0x2, 0x2, 0x2, 
		0xa, 0x5c, 0x3, 0x2, 0x2, 0x2, 0xc, 0x68, 0x3, 0x2, 0x2, 0x2, 0xe, 0x6d, 
		0x3, 0x2, 0x2, 0x2, 0x10, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x12, 0x81, 0x3, 0x2, 
		0x2, 0x2, 0x14, 0x88, 0x3, 0x2, 0x2, 0x2, 0x16, 0xa1, 0x3, 0x2, 0x2, 0x2, 
		0x18, 0xa4, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x1c, 
		0xbb, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xc5, 0x3, 0x2, 0x2, 0x2, 0x20, 0xc7, 
		0x3, 0x2, 0x2, 0x2, 0x22, 0xd2, 0x3, 0x2, 0x2, 0x2, 0x24, 0xd4, 0x3, 0x2, 
		0x2, 0x2, 0x26, 0xdc, 0x3, 0x2, 0x2, 0x2, 0x28, 0xe6, 0x3, 0x2, 0x2, 0x2, 
		0x2a, 0xe9, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xee, 0x3, 0x2, 0x2, 0x2, 0x2e, 
		0xf3, 0x3, 0x2, 0x2, 0x2, 0x30, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x32, 0x107, 
		0x3, 0x2, 0x2, 0x2, 0x34, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x36, 0x10e, 0x3, 
		0x2, 0x2, 0x2, 0x38, 0x112, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x121, 0x3, 0x2, 
		0x2, 0x2, 0x3c, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x13b, 0x3, 0x2, 0x2, 
		0x2, 0x40, 0x145, 0x3, 0x2, 0x2, 0x2, 0x42, 0x149, 0x3, 0x2, 0x2, 0x2, 
		0x44, 0x150, 0x3, 0x2, 0x2, 0x2, 0x46, 0x152, 0x3, 0x2, 0x2, 0x2, 0x48, 
		0x49, 0x5, 0x4, 0x3, 0x2, 0x49, 0x4a, 0x5, 0x6, 0x4, 0x2, 0x4a, 0x4b, 
		0x7, 0x2, 0x2, 0x3, 0x4b, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4e, 0x5, 0x6, 
		0x4, 0x2, 0x4d, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4c, 0x3, 0x2, 0x2, 0x2, 
		0x4e, 0x3, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x3, 0x2, 0x2, 0x50, 0x51, 
		0x7, 0x24, 0x2, 0x2, 0x51, 0x52, 0x7, 0x47, 0x2, 0x2, 0x52, 0x53, 0x7, 
		0x20, 0x2, 0x2, 0x53, 0x5, 0x3, 0x2, 0x2, 0x2, 0x54, 0x56, 0x5, 0x8, 0x5, 
		0x2, 0x55, 0x54, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x3, 0x2, 0x2, 0x2, 0x57, 
		0x55, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0x7, 0x3, 
		0x2, 0x2, 0x2, 0x59, 0x5a, 0x5, 0x14, 0xb, 0x2, 0x5a, 0x9, 0x3, 0x2, 0x2, 
		0x2, 0x5b, 0x5d, 0x7, 0xe, 0x2, 0x2, 0x5c, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5c, 
		0x5d, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 
		0x7, 0x3a, 0x2, 0x2, 0x5f, 0x60, 0x7, 0xf, 0x2, 0x2, 0x60, 0x61, 0x7, 
		0x4, 0x2, 0x2, 0x61, 0x62, 0x5, 0x10, 0x9, 0x2, 0x62, 0x63, 0x7, 0x10, 
		0x2, 0x2, 0x63, 0x64, 0x5, 0xc, 0x7, 0x2, 0x64, 0x65, 0x7, 0x11, 0x2, 
		0x2, 0x65, 0xb, 0x3, 0x2, 0x2, 0x2, 0x66, 0x69, 0x5, 0x14, 0xb, 0x2, 0x67, 
		0x69, 0x5, 0xe, 0x8, 0x2, 0x68, 0x66, 0x3, 0x2, 0x2, 0x2, 0x68, 0x67, 
		0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x68, 0x3, 0x2, 
		0x2, 0x2, 0x6a, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6b, 0xd, 0x3, 0x2, 0x2, 0x2, 
		0x6c, 0x6e, 0x5, 0x34, 0x1b, 0x2, 0x6d, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6d, 
		0x6e, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x70, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x71, 
		0x7, 0xe, 0x2, 0x2, 0x70, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 
		0x2, 0x2, 0x71, 0x72, 0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x5, 0x38, 0x1d, 
		0x2, 0x73, 0x74, 0x7, 0xf, 0x2, 0x2, 0x74, 0xf, 0x3, 0x2, 0x2, 0x2, 0x75, 
		0x80, 0x5, 0x38, 0x1d, 0x2, 0x76, 0x77, 0x5, 0x38, 0x1d, 0x2, 0x77, 0x78, 
		0x7, 0x21, 0x2, 0x2, 0x78, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x79, 0x76, 0x3, 
		0x2, 0x2, 0x2, 0x7a, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x79, 0x3, 0x2, 0x2, 
		0x2, 0x7b, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7d, 
		0x7e, 0x5, 0x38, 0x1d, 0x2, 0x7e, 0x80, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x75, 
		0x3, 0x2, 0x2, 0x2, 0x7f, 0x79, 0x3, 0x2, 0x2, 0x2, 0x80, 0x11, 0x3, 0x2, 
		0x2, 0x2, 0x81, 0x82, 0x7, 0x5, 0x2, 0x2, 0x82, 0x83, 0x5, 0x38, 0x1d, 
		0x2, 0x83, 0x84, 0x7, 0x10, 0x2, 0x2, 0x84, 0x85, 0x5, 0x6, 0x4, 0x2, 
		0x85, 0x86, 0x7, 0x11, 0x2, 0x2, 0x86, 0x13, 0x3, 0x2, 0x2, 0x2, 0x87, 
		0x89, 0x5, 0x34, 0x1b, 0x2, 0x88, 0x87, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 
		0x3, 0x2, 0x2, 0x2, 0x89, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8c, 0x7, 0xe, 
		0x2, 0x2, 0x8b, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x3, 0x2, 0x2, 0x2, 
		0x8c, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x6, 0x2, 0x2, 0x8e, 
		0x8f, 0x7, 0xf, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x15, 0x2, 0x2, 0x90, 0x91, 
		0x5, 0x16, 0xc, 0x2, 0x91, 0x92, 0x7, 0x16, 0x2, 0x2, 0x92, 0x93, 0x7, 
		0x7, 0x2, 0x2, 0x93, 0x94, 0x5, 0x38, 0x1d, 0x2, 0x94, 0x95, 0x5, 0x1a, 
		0xe, 0x2, 0x95, 0x15, 0x3, 0x2, 0x2, 0x2, 0x96, 0xa2, 0x3, 0x2, 0x2, 0x2, 
		0x97, 0xa2, 0x5, 0x18, 0xd, 0x2, 0x98, 0x99, 0x5, 0x18, 0xd, 0x2, 0x99, 
		0x9a, 0x7, 0x21, 0x2, 0x2, 0x9a, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x98, 
		0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9b, 0x3, 0x2, 
		0x2, 0x2, 0x9d, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 0x2, 0x2, 
		0x9f, 0xa0, 0x5, 0x18, 0xd, 0x2, 0xa0, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa1, 
		0x96, 0x3, 0x2, 0x2, 0x2, 0xa1, 0x97, 0x3, 0x2, 0x2, 0x2, 0xa1, 0x9b, 
		0x3, 0x2, 0x2, 0x2, 0xa2, 0x17, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa5, 0x5, 0x34, 
		0x1b, 0x2, 0xa4, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x3, 0x2, 0x2, 
		0x2, 0xa5, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x5, 0x38, 0x1d, 0x2, 
		0xa7, 0xa8, 0x7, 0xf, 0x2, 0x2, 0xa8, 0x19, 0x3, 0x2, 0x2, 0x2, 0xa9, 
		0xad, 0x7, 0x10, 0x2, 0x2, 0xaa, 0xac, 0x5, 0x1e, 0x10, 0x2, 0xab, 0xaa, 
		0x3, 0x2, 0x2, 0x2, 0xac, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xad, 0xab, 0x3, 0x2, 
		0x2, 0x2, 0xad, 0xae, 0x3, 0x2, 0x2, 0x2, 0xae, 0xb0, 0x3, 0x2, 0x2, 0x2, 
		0xaf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x7, 0x11, 0x2, 0x2, 0xb1, 
		0x1b, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb6, 0x7, 0x10, 0x2, 0x2, 0xb3, 0xb5, 
		0x5, 0x1e, 0x10, 0x2, 0xb4, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb8, 0x3, 
		0x2, 0x2, 0x2, 0xb6, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x3, 0x2, 0x2, 
		0x2, 0xb7, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb9, 
		0xbc, 0x7, 0x11, 0x2, 0x2, 0xba, 0xbc, 0x5, 0x1e, 0x10, 0x2, 0xbb, 0xb2, 
		0x3, 0x2, 0x2, 0x2, 0xbb, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x1d, 0x3, 0x2, 
		0x2, 0x2, 0xbd, 0xbe, 0x5, 0x3a, 0x1e, 0x2, 0xbe, 0xbf, 0x7, 0x20, 0x2, 
		0x2, 0xbf, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc6, 0x5, 0x20, 0x11, 0x2, 
		0xc1, 0xc6, 0x5, 0x22, 0x12, 0x2, 0xc2, 0xc3, 0x5, 0x42, 0x22, 0x2, 0xc3, 
		0xc4, 0x7, 0x20, 0x2, 0x2, 0xc4, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xbd, 
		0x3, 0x2, 0x2, 0x2, 0xc5, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc1, 0x3, 0x2, 
		0x2, 0x2, 0xc5, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc6, 0x1f, 0x3, 0x2, 0x2, 0x2, 
		0xc7, 0xc8, 0x7, 0x8, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x15, 0x2, 0x2, 0xc9, 
		0xca, 0x5, 0x3e, 0x20, 0x2, 0xca, 0xcb, 0x7, 0x16, 0x2, 0x2, 0xcb, 0xcc, 
		0x5, 0x1c, 0xf, 0x2, 0xcc, 0x21, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xd3, 0x5, 
		0x24, 0x13, 0x2, 0xce, 0xd3, 0x5, 0x26, 0x14, 0x2, 0xcf, 0xd3, 0x5, 0x28, 
		0x15, 0x2, 0xd0, 0xd3, 0x5, 0x2a, 0x16, 0x2, 0xd1, 0xd3, 0x5, 0x2e, 0x18, 
		0x2, 0xd2, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd2, 
		0xcf, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd1, 
		0x3, 0x2, 0x2, 0x2, 0xd3, 0x23, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x7, 0x9, 
		0x2, 0x2, 0xd5, 0xd6, 0x7, 0x15, 0x2, 0x2, 0xd6, 0xd7, 0x7, 0xf, 0x2, 
		0x2, 0xd7, 0xd8, 0x7, 0xa, 0x2, 0x2, 0xd8, 0xd9, 0x5, 0x3a, 0x1e, 0x2, 
		0xd9, 0xda, 0x7, 0x16, 0x2, 0x2, 0xda, 0xdb, 0x5, 0x1c, 0xf, 0x2, 0xdb, 
		0x25, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x9, 0x2, 0x2, 0xdd, 0xde, 
		0x7, 0x15, 0x2, 0x2, 0xde, 0xdf, 0x5, 0x3a, 0x1e, 0x2, 0xdf, 0xe0, 0x7, 
		0x20, 0x2, 0x2, 0xe0, 0xe1, 0x5, 0x3e, 0x20, 0x2, 0xe1, 0xe2, 0x7, 0x20, 
		0x2, 0x2, 0xe2, 0xe3, 0x5, 0x3a, 0x1e, 0x2, 0xe3, 0xe4, 0x7, 0x16, 0x2, 
		0x2, 0xe4, 0xe5, 0x5, 0x1c, 0xf, 0x2, 0xe5, 0x27, 0x3, 0x2, 0x2, 0x2, 
		0xe6, 0xe7, 0x5, 0x2c, 0x17, 0x2, 0xe7, 0xe8, 0x5, 0x1c, 0xf, 0x2, 0xe8, 
		0x29, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x7, 0xb, 0x2, 0x2, 0xea, 0xeb, 
		0x5, 0x1c, 0xf, 0x2, 0xeb, 0xec, 0x5, 0x2c, 0x17, 0x2, 0xec, 0xed, 0x7, 
		0x20, 0x2, 0x2, 0xed, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x7, 0xc, 
		0x2, 0x2, 0xef, 0xf0, 0x7, 0x15, 0x2, 0x2, 0xf0, 0xf1, 0x5, 0x3e, 0x20, 
		0x2, 0xf1, 0xf2, 0x7, 0x16, 0x2, 0x2, 0xf2, 0x2d, 0x3, 0x2, 0x2, 0x2, 
		0xf3, 0xf4, 0x7, 0xd, 0x2, 0x2, 0xf4, 0xf5, 0x5, 0x1c, 0xf, 0x2, 0xf5, 
		0x2f, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x5, 0x38, 0x1d, 0x2, 0xf7, 0x100, 
		0x7, 0x15, 0x2, 0x2, 0xf8, 0xfd, 0x5, 0x32, 0x1a, 0x2, 0xf9, 0xfa, 0x7, 
		0x21, 0x2, 0x2, 0xfa, 0xfc, 0x5, 0x32, 0x1a, 0x2, 0xfb, 0xf9, 0x3, 0x2, 
		0x2, 0x2, 0xfc, 0xff, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfb, 0x3, 0x2, 0x2, 0x2, 
		0xfd, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfe, 0x101, 0x3, 0x2, 0x2, 0x2, 0xff, 
		0xfd, 0x3, 0x2, 0x2, 0x2, 0x100, 0xf8, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 
		0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x7, 
		0x16, 0x2, 0x2, 0x103, 0x31, 0x3, 0x2, 0x2, 0x2, 0x104, 0x108, 0x5, 0x3a, 
		0x1e, 0x2, 0x105, 0x108, 0x5, 0x3c, 0x1f, 0x2, 0x106, 0x108, 0x5, 0x3e, 
		0x20, 0x2, 0x107, 0x104, 0x3, 0x2, 0x2, 0x2, 0x107, 0x105, 0x3, 0x2, 0x2, 
		0x2, 0x107, 0x106, 0x3, 0x2, 0x2, 0x2, 0x108, 0x33, 0x3, 0x2, 0x2, 0x2, 
		0x109, 0x10b, 0x5, 0x36, 0x1c, 0x2, 0x10a, 0x109, 0x3, 0x2, 0x2, 0x2, 
		0x10b, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10c, 
		0x10d, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x35, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 
		0x7, 0x17, 0x2, 0x2, 0x10f, 0x110, 0x5, 0x30, 0x19, 0x2, 0x110, 0x111, 
		0x7, 0x18, 0x2, 0x2, 0x111, 0x37, 0x3, 0x2, 0x2, 0x2, 0x112, 0x117, 0x7, 
		0xf, 0x2, 0x2, 0x113, 0x114, 0x7, 0x1f, 0x2, 0x2, 0x114, 0x116, 0x7, 0xf, 
		0x2, 0x2, 0x115, 0x113, 0x3, 0x2, 0x2, 0x2, 0x116, 0x119, 0x3, 0x2, 0x2, 
		0x2, 0x117, 0x115, 0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x3, 0x2, 0x2, 0x2, 
		0x118, 0x39, 0x3, 0x2, 0x2, 0x2, 0x119, 0x117, 0x3, 0x2, 0x2, 0x2, 0x11a, 
		0x122, 0x5, 0x30, 0x19, 0x2, 0x11b, 0x122, 0x5, 0x46, 0x24, 0x2, 0x11c, 
		0x122, 0x5, 0x38, 0x1d, 0x2, 0x11d, 0x11e, 0x7, 0x15, 0x2, 0x2, 0x11e, 
		0x11f, 0x5, 0x3a, 0x1e, 0x2, 0x11f, 0x120, 0x7, 0x16, 0x2, 0x2, 0x120, 
		0x122, 0x3, 0x2, 0x2, 0x2, 0x121, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x121, 0x11b, 
		0x3, 0x2, 0x2, 0x2, 0x121, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x121, 0x11d, 0x3, 
		0x2, 0x2, 0x2, 0x122, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 0x8, 0x1f, 
		0x1, 0x2, 0x124, 0x12b, 0x5, 0x30, 0x19, 0x2, 0x125, 0x12b, 0x5, 0x38, 
		0x1d, 0x2, 0x126, 0x127, 0x7, 0x1a, 0x2, 0x2, 0x127, 0x12b, 0x5, 0x3c, 
		0x1f, 0x5, 0x128, 0x12b, 0x7, 0x47, 0x2, 0x2, 0x129, 0x12b, 0x5, 0x3a, 
		0x1e, 0x2, 0x12a, 0x123, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x125, 0x3, 0x2, 0x2, 
		0x2, 0x12a, 0x126, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x128, 0x3, 0x2, 0x2, 0x2, 
		0x12a, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x131, 0x3, 0x2, 0x2, 0x2, 0x12c, 
		0x12d, 0xc, 0x8, 0x2, 0x2, 0x12d, 0x12e, 0x7, 0x19, 0x2, 0x2, 0x12e, 0x130, 
		0x5, 0x3c, 0x1f, 0x9, 0x12f, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x130, 0x133, 
		0x3, 0x2, 0x2, 0x2, 0x131, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x3, 
		0x2, 0x2, 0x2, 0x132, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x133, 0x131, 0x3, 0x2, 
		0x2, 0x2, 0x134, 0x135, 0x8, 0x20, 0x1, 0x2, 0x135, 0x13c, 0x5, 0x30, 
		0x19, 0x2, 0x136, 0x13c, 0x5, 0x38, 0x1d, 0x2, 0x137, 0x138, 0x7, 0x1d, 
		0x2, 0x2, 0x138, 0x13c, 0x5, 0x3e, 0x20, 0x5, 0x139, 0x13c, 0x5, 0x40, 
		0x21, 0x2, 0x13a, 0x13c, 0x5, 0x3a, 0x1e, 0x2, 0x13b, 0x134, 0x3, 0x2, 
		0x2, 0x2, 0x13b, 0x136, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x137, 0x3, 0x2, 0x2, 
		0x2, 0x13b, 0x139, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13a, 0x3, 0x2, 0x2, 0x2, 
		0x13c, 0x142, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 0xc, 0x8, 0x2, 0x2, 0x13e, 
		0x13f, 0x7, 0x1c, 0x2, 0x2, 0x13f, 0x141, 0x5, 0x3e, 0x20, 0x9, 0x140, 
		0x13d, 0x3, 0x2, 0x2, 0x2, 0x141, 0x144, 0x3, 0x2, 0x2, 0x2, 0x142, 0x140, 
		0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 0x3, 0x2, 0x2, 0x2, 0x143, 0x3f, 0x3, 
		0x2, 0x2, 0x2, 0x144, 0x142, 0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 0x5, 0x3c, 
		0x1f, 0x2, 0x146, 0x147, 0x7, 0x1b, 0x2, 0x2, 0x147, 0x148, 0x5, 0x3c, 
		0x1f, 0x2, 0x148, 0x41, 0x3, 0x2, 0x2, 0x2, 0x149, 0x14a, 0x5, 0x44, 0x23, 
		0x2, 0x14a, 0x14e, 0x7, 0x24, 0x2, 0x2, 0x14b, 0x14f, 0x5, 0x3a, 0x1e, 
		0x2, 0x14c, 0x14f, 0x5, 0x3c, 0x1f, 0x2, 0x14d, 0x14f, 0x5, 0x3e, 0x20, 
		0x2, 0x14e, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14c, 0x3, 0x2, 0x2, 0x2, 
		0x14e, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x43, 0x3, 0x2, 0x2, 0x2, 0x150, 
		0x151, 0x5, 0x38, 0x1d, 0x2, 0x151, 0x45, 0x3, 0x2, 0x2, 0x2, 0x152, 0x153, 
		0x7, 0x46, 0x2, 0x2, 0x153, 0x154, 0x5, 0x3a, 0x1e, 0x2, 0x154, 0x47, 
		0x3, 0x2, 0x2, 0x2, 0x20, 0x4d, 0x57, 0x5c, 0x68, 0x6a, 0x6d, 0x70, 0x7b, 
		0x7f, 0x88, 0x8b, 0x9d, 0xa1, 0xa4, 0xad, 0xb6, 0xbb, 0xc5, 0xd2, 0xfd, 
		0x100, 0x107, 0x10c, 0x117, 0x121, 0x12a, 0x131, 0x13b, 0x142, 0x14e, 
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
