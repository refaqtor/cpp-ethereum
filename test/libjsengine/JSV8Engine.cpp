//
// Created by Marek Kotewicz on 27/04/15.
//

#include <boost/test/unit_test.hpp>
#include <libjsengine/JSV8Engine.h>
#include <libjsengine/JSV8Printer.h>

using namespace std;
using namespace dev;
using namespace dev::eth;

BOOST_AUTO_TEST_SUITE(jsv8engine)

BOOST_AUTO_TEST_CASE(evalInteger)
{
	JSV8Engine engine;
	JSV8Printer printer(engine);
	auto value = engine.eval("1 + 1");
	string result = printer.print(value);
	BOOST_CHECK_EQUAL(result, "2");
}

BOOST_AUTO_TEST_CASE(evalString)
{
	JSV8Engine engine;
	JSV8Printer printer(engine);
	auto value = engine.eval("'hello ' + 'world'");
	string result = printer.print(value);
	BOOST_CHECK_EQUAL(result, "hello world");
}

BOOST_AUTO_TEST_CASE(evalEmpty)
{
	JSV8Engine engine;
	JSV8Printer printer(engine);
	auto value = engine.eval("");
	string result = printer.print(value);
	BOOST_CHECK_EQUAL(result, "undefined");
}

BOOST_AUTO_TEST_SUITE_END()
