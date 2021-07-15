#include "ExceptionHandling.hpp"
#include <iostream>
#include "../DataStructures/RuntimeException.hpp"
#include "../DataStructures/InvalidTypeException.hpp"
#include "../DataStructures/printStackTrace.hpp"

void cMCompiler::compiler::runWithHandling(std::function<void()> const& f)
{
	try 
	{
		f();
		return;
	}
	catch (cMCompiler::dataStructures::InvalidTypeException const& e)
	{
		std::cerr << "exception occured: " << e.what() << std::endl;
		std::cerr << "expected type: " << e.expected << std::endl;
		std::cerr << "saw: " << e.recieved << std::endl;
		dataStructures::printStackTrace(e.trace(), std::cerr);
	}
	catch (cMCompiler::dataStructures::RuntimeException const& e)
	{
		std::cerr << "exception occured: " << e.what() << std::endl;
		dataStructures::printStackTrace(e.trace(), std::cerr);
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what();
	}
		exit(-1);
}
