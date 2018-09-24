#pragma once

//#include <boost/function.hpp>
////#include <boost/function_equal.hpp>

//#include <boost/bind.hpp>

#include "computer.hxx"

//#include "array.txx"
//#include "var.cxx"	// "noware::var" is templated: do not include the implementation.
//#include "nr.cxx"
//#include "container/list/sqlite.cxx"
#include "db/sqlite.cxx"

#include ".computer/.cxx"


noware::computer::query_sql_initial =
	#include ".computer/query.sql.initial.hxx"
;

const std::string noware::computer::database_default = "computer.db";


noware::computer::computer (void)
{
	//initialize (database_default);
}

noware::computer::~computer (void)
{
	finalize ();
}

const bool noware::computer::initialize (const std::string & database)
{
	if (!science.connect (database))
		return false;
	
	if (!science.query (query_sql_initial))
		return false;
	
	return true;
}

const bool noware::computer::finalize (const std::string & database)
{
	if (!science.disconnect ())
		return false;
	
	return true;
}

const noware::var noware::computer::evaluate (const noware::var & expression)
{
	return "";
}
