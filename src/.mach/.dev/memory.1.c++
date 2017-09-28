//#include <iostream>
#include "memory.h++"
//#include "../../network/ip.h++"
//#include <boost/mem_fn.hpp>
//#include <boost/ref.hpp>

//const std::string LIB::machine::device::memory::default_database_name = ":memory:";
//const LIB::machine::device::memory::key LIB::machine::device::memory::default_group = "";
////const LIB::machine::device::memory::value LIB::machine::device::memory::default_name;
//const LIB::machine::device::memory::value LIB::machine::device::memory::default_value = "";

// Memory: Iterator:
/*
LIB::machine::device::memory::iterator::iterator (void)
{
	//set = false;
}

LIB::machine::device::memory::iterator::iterator (const LIB::machine::device::memory::iterator & other)
{
	operator = (other);
}
*/
/*
LIB::machine::device::memory::iterator::~iterator (void)
{
}
*/
/*
const LIB::machine::device::memory::iterator & LIB::machine::device::memory::iterator::operator = (const LIB::machine::device::memory::iterator & other)
{
	iter = other.iter;
	
	return *this;
}

const bool LIB::machine::device::memory::iterator::operator == (const iterator & other) const
{
	return iter == other.iter;
	//return false;
}

const bool LIB::machine::device::memory::iterator::operator != (const iterator & other) const
{
	return ! (operator == (other));
}

const LIB::machine::device::memory::iterator & LIB::machine::device::memory::iterator::operator ++ (void)
{
	++ iter;
	
	return * this;
}

const LIB::machine::device::memory::iterator & LIB::machine::device::memory::iterator::operator -- (void)
{
	-- iter;
	
	return * this;
}

const LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V>::package & LIB::machine::device::memory::iterator::operator * (void) const
{
	//return * (iter -> v);
	//return iter -> v;
	return *iter;
}
*/

// Memory:

//static const std::string LIB::machine::device::memory::default_database_name;
//static const std::string LIB::machine::device::memory::default_group;
////static const std::string LIB::machine::device::memory::default_name;
//static const std::string LIB::machine::device::memory::default_value;
//
//const bool LIB::machine::device::memory::initialize (const LIB::database::sqlite *& _db, const LIB::machine::device::memory::key & grp, const LIB::machine::device::memory::key & previous_grp, const LIB::machine::device::memory::key & nm, const std::string & __database_name)
//{
//}

const bool LIB::machine::device::memory::initialize (const std::string & __database_name)
{
	//std::cout << std::endl << default_database_name << std::endl;
	//_database_name = __database_name;
	
	try
	{
		container = new LIB::container::memory (__database_name);
		
		return true;
	}
	catch (...)
	{
		return false;
	}
}
/*
LIB::machine::device::memory::memory (const std::string & __database_name)
{
//	db = other.db;
//	group = other.group;
//	previous_group = other.previous_group;
//	previous_name = other.previous_name;
	
	initialize (__database_name);
	//_database_name = __database_name;
}
*/
/*
LIB::machine::device::memory::memory (const memory & other, const std::string & __database_name)
{
//	db = other.db;
//	group = other.group;
//	previous_group = other.previous_group;
//	previous_name = other.previous_name;
	
	initialize (__database_name);
	
	operator = (other);
}
*/
/*
LIB::machine::device::memory::~memory (void)
{
	//if (db != NULL && group == default_group)
	//{
		finalize ();
	//	db = NULL;
	//}
}
*/

const bool LIB::machine::device::memory::finalize (void)
{
	try
	{
	//if (db != NULL && group == default_group)
	//{
		delete container;
	//	db = NULL;
	//}
		
		return true;
	}
	catch (...)
	{
		return false;
	}
}

template <typename archive>
void LIB::machine::device::memory::save (archive & arch, const unsigned int & version) const
{
}

template <typename archive>
void LIB::machine::device::memory::load (archive & arch, const unsigned int & version)
{
}

/*const bool LIB::machine::device::memory::query (LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> & result, const std::string & qry, const LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> & arguments)
{
	return container -> database ().query (result, qry, arguments);
}*/

const std::string & LIB::machine::device::memory::database_name (void) const
{
	return container -> database_name ();
}

LIB::container::database::sql::sqlite & LIB::machine::device::memory::database (void)
{
	// It should always be safe to dereference,
	// because the constructors should normally ensure that an object is present.
	return container -> database ();
}

//const LIB::machine::device::memory::relation LIB::machine::device::memory::relate (const LIB::machine::device::memory::memory & other) const
//{
//	relation rel/* = relation::self*/;
//	
//	return rel;
//}
/*
const bool LIB::machine::device::memory::operator == (const LIB::machine::device::memory & other) const
{
	//typeid ();
	if (container == other.container)	// Is this everything which is needed?
		return true;
	
	return false;
}
*/
/*
const bool LIB::machine::device::memory::operator != (const LIB::machine::device::memory & other) const
{
	return ! (operator == (other));
}
*/
/*
const bool LIB::machine::device::memory::operator == (const LIB::machine::device::memory::value & other) const
{
	return false;
}

const bool LIB::machine::device::memory::operator != (const LIB::machine::device::memory::value & other) const
{
	return ! operator == (other);
}
*/
/*
const LIB::machine::device::memory & LIB::machine::device::memory::operator = (const LIB::machine::device::memory & other)
{
	// Do not do anything.
	
	return * this;
}
*/
//const LIB::machine::device::memory & LIB::machine::device::memory::operator = (const LIB::machine::device::memory::value & val)
//{
//	if (clear ())
//	{
//		LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
//		
//		arguments [1] = group;
//		arguments [2] = 0;
//		arguments [3] = previous_name;
//		arguments [4] = 0;
//		arguments [5] = val;
//		
//		container -> database ().query ("INSERT OR REPLACE INTO \"Entities\" (\"Group\", \"Name: Type\", \"Name\", \"Content: Type\", \"Content\") VALUES (?, ?, ?, ?, ?)", arguments);
//	}
//	
//	return * this;
//}

/*
const LIB::mathematics::numbers::natural LIB::machine::device::memory::size (void) const
{
	return 0;
}

const LIB::mathematics::numbers::natural LIB::machine::device::memory::size_group (const LIB::machine::device::memory::key & group) const
{
	return 0;
}

const bool LIB::machine::device::memory::clear (void)
{
	return false;
}

const bool LIB::machine::device::memory::clear_group (const LIB::machine::device::memory::key & group)
{
	return false;
}

const bool LIB::machine::device::memory::empty (void) const
{
	return ! (size () > 0);
}

const bool LIB::machine::device::memory::empty_group (const LIB::machine::device::memory::key & group)
{
	return ! (size_group (group) > 0);
}

const bool LIB::machine::device::memory::full (void) const
{
	return false;
}

const bool LIB::machine::device::memory::exists (const LIB::machine::device::memory::key & name, const LIB::machine::device::memory::key & group) const
{
	LIB::mathematics::numbers::natural count = 0;
	
	if (container -> exists (name, group))
		return true;
	else if (cluster.nodes ().empty ())
		return false;
	
	LIB::communication::message message;
	
	if (!cluster.broadcast (message))
	{
		return false;
	}
	
	
	
	return count > 0;
}
*/

//const bool LIB::machine::device::memory::exists (const LIB::machine::device::memory::key & name) const
//{
//	return exist (name);
//}
/*
const LIB::machine::device::memory LIB::machine::device::memory::operator + (const LIB::machine::device::memory::value & val) const
{}
*/
/*
const LIB::machine::device::memory LIB::machine::device::memory::operator + (const LIB::machine::device::memory & other) const
{
	memory aggregate (* this/*, use the default_database_name * /);
	
	// Add "other" to "this".
	
	return aggregate;
}
*/
/*
const LIB::machine::device::memory & LIB::machine::device::memory::operator += (const LIB::machine::device::memory::value & val)
{}
*/
/*
const LIB::machine::device::memory & LIB::machine::device::memory::operator += (const LIB::machine::device::memory & other)
{
	return * this;
}

const bool LIB::machine::device::memory::add (const LIB::machine::device::memory::key & k, const LIB::machine::device::memory::value & val)
{
	key used_group;
	
	return add (used_group, k, val);
}

const bool LIB::machine::device::memory::add (LIB::machine::device::memory::key & used_group, const LIB::machine::device::memory::key & k, const LIB::machine::device::memory::value & v)
{
	used_group = sequence_group_next_available ();
	
	return _set (used_group, k, v);
}

const bool LIB::machine::device::memory::add (const LIB::machine::device::memory & other)
{
	return false;
}

const bool LIB::machine::device::memory::append (const LIB::machine::device::memory::key & k, const LIB::machine::device::memory::value & v)
{
	key used_group;
	
	return append (used_group, k, v);
}

const bool LIB::machine::device::memory::append (LIB::machine::device::memory::key & used_group, const LIB::machine::device::memory::key & k, const LIB::machine::device::memory::value & v)
{
	used_group = sequence_group_next ();
	
	return _set (used_group, k, v);
}
*/
/*
const bool LIB::machine::device::memory::_set (const LIB::machine::device::memory::key & used_group, const LIB::machine::device::memory::key & k, const LIB::machine::device::memory::value & val)
{
	if (! container -> database ().query ("BEGIN"))
		return false;
	
	// To be completed.
	/*
	used_group = sequence_group_next ();
	
	if (! set_group (used_group, val))
		return false;
	
	memory mem ();
	
	if (! mem.set (val))
		return false;
	
	return true;
	* /
	
	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	//LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	//used_group = sequence_group_next ();
	
	arguments [1] = used_group;
	
	//std::cout << "\tsequence_next () == " << sequence_group_next () << std::endl;
	//std::cout << "\tused_group == " << used_group << std::endl;
	//std::cout << "\targuments [1] == " << arguments [1] << std::endl;
	//std::cout << "\targuments [1].to_string () == " << arguments [1].to_string () << std::endl;
	//std::cout << "\targuments [1].to_string ().c_str () == " << arguments [1].to_string ().c_str () << std::endl;
	//std::cout << "\targuments [1].to_string ().size () == " << arguments [1].to_string ().size () << std::endl;
	arguments [2] = 0;
	arguments [3] = k;
	arguments [4] = 0;
	arguments [5] = val;
	
	if (! container -> database ().query ("\
		INSERT OR IGNORE INTO \"Entities\"\n\
		(\"Group\", \"Name: Type\", \"Name\", \"Content: Type\", \"Content\")\n\
		VALUES\n\
		(?, ?, ?, ?, ?)\
		", arguments))
	{
		container -> database ().query ("ROLLBACK");
		
		return false;
	}
	//else
	//{
	//	return true;
	//}
	
	return container -> database ().query ("COMMIT");
}

const bool LIB::machine::device::memory::append (const LIB::machine::device::memory & other)
{}

const bool LIB::machine::device::memory::push (const LIB::machine::device::memory::key & k, const LIB::machine::device::memory::value & val)
{
	key used_group;
	
	return push (used_group, k, val);
}

const bool LIB::machine::device::memory::push (LIB::machine::device::memory::key & used_group, const LIB::machine::device::memory::key & k, const LIB::machine::device::memory::value & v)
{
	return append (used_group, k, v);
}
*/
const bool LIB::machine::device::memory::pop (void)
{
	if (! container -> database ().query ("BEGIN"))
		return false;
	
	//LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	//LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	if (! container -> database ().query ("\
		DELETE FROM \"Entities\"\n\
		WHERE GROUP = (SELECT COALESCE (MAX (\"Group\"), 0) FROM \"Entities\" WHERE TYPEOF (\"Group\") = 'integer')\
		"))
	{
		container -> database ().query ("ROLLBACK");
		
		return false;
	}
	
	return container -> database ().query ("COMMIT");
}

const LIB::mathematics::numbers::integer LIB::machine::device::memory::key_group_integral_min (void) const
{
	/*
	key i = key_group_integral_max ();
	
	for (auto & element: *this)
	{
		if (element.k.is_numeric () && element.k < i)
		{
			i = element.k;
		}
	}
	
	return i;
	*/
	
	//LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	container -> database ().query (result, "\
		SELECT COALESCE (MIN (\"Group\"), 0)\n\
		FROM \"Entities\"\
		WHERE TYPEOF (\"Group\") = 'integer'\
		");
	
//	if (result.empty ())
//	{
//		return 1;
//	}
//	else
//	{
		// There should always be a result, because of the coalesce function.
		return result [1] [1];
//	}
}

const LIB::mathematics::numbers::integer LIB::machine::device::memory::key_group_integral_max (void) const
{
	/*
	key i = 1;
	
	for (auto & element : *this)
	{
		if (element.k.is_numeric () && element.k > i)
		{
			i = element.k;
		}
	}
	
	return i;
	*/
	
	//LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	container -> database ().query (result, "\
		SELECT COALESCE (MAX (\"Group\"), 0)\n\
		FROM \"Entities\"\
		WHERE TYPEOF (\"Group\") = 'integer'\
		");
	
//	if (result.empty ())
//	{
//		return 1;
//	}
//	else
//	{
		// There should always be a result, because of the coalesce function.
		return result [1] [1];
//	}
}

const LIB::mathematics::numbers::integer LIB::machine::device::memory::key_name_integral_min (const LIB::machine::device::memory::key & group) const
{
	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	arguments.append (group);
	
	container -> database ().query
	(
		result,
		"\
			SELECT\n\
				COALESCE (MIN (\"Name\"), 0)\n\
			FROM\n\
				\"Entities\"\n\
			WHERE\n\
				TYPEOF (\"Name\") = 'integer'\n\
				AND \"Group\" = ?\
		",
		arguments
	);
	
	// There should always be a result, because of the coalesce function.
	return result [1] [1];
}

const LIB::mathematics::numbers::integer LIB::machine::device::memory::key_name_integral_max (const LIB::machine::device::memory::key & group) const
{
	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	arguments.append (group);
	
	container -> database ().query
	(
		result,
		"\
			SELECT\n\
				COALESCE (MAX (\"Name\"), 0)\n\
			FROM\n\
				\"Entities\"\n\
			WHERE\n\
				TYPEOF (\"Name\") = 'integer'\n\
				AND \"Group\" = ?\
		",
		arguments
	);
	
	// There should always be a result, because of the coalesce function.
	return result [1] [1];
}

const bool LIB::machine::device::memory::enqueue (const LIB::machine::device::memory::key & k, const LIB::machine::device::memory::value & v)
{
	key used_group;
	
	return enqueue (used_group, k, v);
}

const bool LIB::machine::device::memory::enqueue (LIB::machine::device::memory::key & used_group, const LIB::machine::device::memory::key & k, const LIB::machine::device::memory::value & v)
{
	return append (used_group, k, v);
}

const bool LIB::machine::device::memory::dequeue (void)
{
	if (! container -> database ().query ("BEGIN"))
		return false;
	
	//LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	//LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	if (! container -> database ().query ("\
		DELETE FROM \"Entities\"\n\
		WHERE GROUP = (SELECT COALESCE (MIN (\"Group\"), 0) FROM \"Entities\" WHERE TYPEOF (\"Group\") = 'integer')\
		"))
	{
		container -> database ().query ("ROLLBACK");
		
		return false;
	}
	
	if (container -> database ().effect () > 0 && key_group_integral_min () >= 2)
	{
		if (! container -> database ().query ("\
			UPDATE \"Entities\"\n\
			SET \"Group\" = \"Group\" - 1\n\
			WHERE TYPEOF (\"Group\") = 'integer'\
			"))
		{
			container -> database ().query ("ROLLBACK");
			
			return false;
		}
	}
	
	return container -> database ().query ("COMMIT");
}

const LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> LIB::machine::device::memory::beginning (void) const
{
	//LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	container -> database ().query (result, "\
		SELECT \"Group\", \"Name: Type\", \"Name\", \"Content: Type\", \"Content\"\n\
		FROM \"Entities\"\n\
		WHERE \"Group\" = (SELECT COALESCE (MIN (\"Group\"), 0) FROM \"Entities\" WHERE TYPEOF (\"Group\") = 'integer')\
		");
	
	return result [1];
}

const LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> LIB::machine::device::memory::ending (void) const
{
	//LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	container -> database ().query (result, "\
		SELECT \"Group\", \"Name: Type\", \"Name\", \"Content: Type\", \"Content\"\n\
		FROM \"Entities\"\n\
		WHERE \"Group\" = (SELECT COALESCE (MAX (\"Group\"), 0) FROM \"Entities\" WHERE TYPEOF (\"Group\") = 'integer')\
		");
	
	return result [1];
}

/*
const bool LIB::machine::device::memory::push (const LIB::machine::device::memory::value & val)
{}

const bool LIB::machine::device::memory::push (const LIB::machine::device::memory::value & val, LIB::machine::device::memory::key & used_key)
{}

const bool LIB::machine::device::memory::pop (void)
{}
*/
//const bool LIB::machine::device::memory::integral_key (void) const
//{}

const LIB::mathematics::numbers::natural LIB::machine::device::memory::sequence_group_next_available (void) const
{
	/*
	for (key i = 1; i <= size (); ++ i)
	{
		if (! exists (i))
		{
			return i;
		}
	}
	*/
	
	//LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	container -> database ().query (result, "\
		SELECT DISTINCT\n\
			-- \"T1\".\"ID\" AS \"Original\", \"T1\".\"ID\" + 1 AS \"Next\", TYPEOF (\"T1\".\"ID\") AS \"Type\"\n\
			\"T1\".\"ID\" + 1 AS \"ID\"\n\
		FROM\n\
				(\n\
					SELECT DISTINCT\n\
						0 AS \"ID\"\n\
					\n\
					UNION\n\
					\n\
					SELECT DISTINCT\n\
						\"T4\".\"Group\" AS \"ID\"\n\
					FROM\n\
						\"Entities\" AS \"T4\"\n\
					WHERE\n\
						\"T4\".\"Group\" IS NOT NULL\n\
						AND\n\
						TYPEOF (\"T4\".\"Group\") = 'integer'\n\
					\n\
					ORDER BY\n\
						\"ID\" ASC\n\
				) AS \"T1\"\n\
			LEFT OUTER JOIN\n\
				(\n\
					SELECT DISTINCT\n\
						0 AS \"ID\"\n\
					\n\
					UNION\n\
					\n\
					SELECT DISTINCT\n\
						\"T4\".\"Group\" AS \"ID\"\n\
					FROM\n\
						\"Entities\" AS \"T4\"\n\
					WHERE\n\
						\"T4\".\"Group\" IS NOT NULL\n\
						AND\n\
						TYPEOF (\"T4\".\"Group\") = 'integer'\n\
					\n\
					ORDER BY\n\
						\"ID\" ASC\n\
				) AS \"T2\"\n\
					ON \"T1\".\"ID\" = \"T2\".\"ID\" - 1\n\
		WHERE\n\
			\"T2\".\"ID\" IS NULL\n\
			AND\n\
			\"T1\".\"ID\" + 1 >= 1\n\
		ORDER BY \"T1\".\"ID\" ASC\n\
		\n\
		LIMIT 1\
	");
	
	return result [1] [1];
	//return 1;
}

const LIB::mathematics::numbers::natural LIB::machine::device::memory::sequence_group_next (void) const
{
	return key_group_integral_max () + 1;
}

/*
const LIB::mathematics::numbers::natural LIB::machine::device::memory::sequence_name_next_available (const LIB::machine::device::memory::key & group) const
{
	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	arguments.append (group);
	arguments.append (group);
	
	_memory -> database ().query
	(
		result,
		"\
			SELECT DISTINCT\n\
				-- \"T1\".\"ID\" AS \"Original\", \"T1\".\"ID\" + 1 AS \"Next\", TYPEOF (\"T1\".\"ID\") AS \"Type\"\n\
				\"T1\".\"ID\" + 1 AS \"ID\"\n\
			FROM\n\
					(\n\
						SELECT DISTINCT\n\
							0 AS \"ID\"\n\
						\n\
						UNION\n\
						\n\
						SELECT DISTINCT\n\
							\"T4\".\"Name\" AS \"ID\"\n\
						FROM\n\
							\"Entities\" AS \"T4\"\n\
						WHERE\n\
							\"T4\".\"Name\" IS NOT NULL\n\
							AND\n\
							TYPEOF (\"T4\".\"Name\") = 'integer'\n\
							AND\n\
							\"T4\".\"Group\" = ?\n\
						\n\
						ORDER BY\n\
							\"ID\" ASC\n\
					) AS \"T1\"\n\
				LEFT OUTER JOIN\n\
					(\n\
						SELECT DISTINCT\n\
							0 AS \"ID\"\n\
						\n\
						UNION\n\
						\n\
						SELECT DISTINCT\n\
							\"T4\".\"Name\" AS \"ID\"\n\
						FROM\n\
							\"Entities\" AS \"T4\"\n\
						WHERE\n\
							\"T4\".\"Name\" IS NOT NULL\n\
							AND\n\
							TYPEOF (\"T4\".\"Name\") = 'integer'\n\
							AND\n\
							\"T4\".\"Group\" = ?\n\
						\n\
						ORDER BY\n\
							\"ID\" ASC\n\
					) AS \"T2\"\n\
						ON \"T1\".\"ID\" = \"T2\".\"ID\" - 1\n\
			WHERE\n\
				\"T2\".\"ID\" IS NULL\n\
				AND\n\
				\"T1\".\"ID\" + 1 >= 1\n\
			ORDER BY \"T1\".\"ID\" ASC\n\
			\n\
			LIMIT 1\
		",
		arguments
	);
	
	return result [1] [1];
}
*/

/*
const LIB::mathematics::numbers::natural LIB::machine::device::memory::sequence_name_next (void) const
{
	return key_name_integral_max () + 1;
}
*/

/*
const LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> LIB::machine::device::memory::list (void) const
{
	//LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	//LIB::container::NAME_A <LIB::machine::device::memory, LIB::machine::device::memory::key> entities;
	
	//arguments [1] = group;
	//container -> database ().query (result, "SELECT \"Name\", \"Content\" FROM \"Entities\" WHERE \"Group\" = ?", arguments);
	container -> database ().query (result, "SELECT \"Group\", \"Name: Type\", \"Name\", \"Content: Type\", \"Content\" FROM \"Entities\"");
	
//	for (LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V>::container & row : result)
//	{
//		//for (LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>::container & column : row.v)
//		//{
//		//	// This loop should last for only one (1) iteration.
//		//}
//		{
//			LIB::machine::device::memory mem (db, row.v [2], group, row.v [1]);
//			
//			entities [row.v [1]] = mem;
//		}
//	}
//	
//	return entities;
	return result;
}
*/

/*
const bool LIB::machine::device::memory::refresh_list (void)
{
	//_list = list ();
	
	return false;
}
*/

/*
const LIB::container::memory::iterator LIB::machine::device::memory::begin (void) const
{
	//return _list.begin ();
	
	LIB::container::memory::iterator iter;
	//iter.iter = iter.list.begin ();
	// iter.iter = _list.begin ();
	
	//iter.reference = (* (iter.iter)) -> v;
	//iter.reference = * (iter.iter);
	// iter.reference = & ((iter.iter) -> v);
	
	//std::cout << **(iter.reference) << std::endl;
	
	//iter.parent = this;
	return iter;
}
*/

/*
const LIB::container::memory::iterator LIB::machine::device::memory::end (void) const
{
	//return _list.end ();
	
	LIB::container::memory::iterator iter;
	//iter.iter = iter.list.end ();
	// iter.iter = _list.end ();
	
	//iter.reference = (* (iter.iter)) -> v;
	//iter.reference = * (iter.iter);
	// iter.reference = & ((iter.iter) -> v);
	
	//std::cout << **(iter.reference) << std::endl;
	
	//iter.parent = this;
	return iter;
}
*/

/*
const std::string LIB::machine::device::memory::serialize (void) const
{
	return LIB::serialize <LIB::machine::device::memory> (* this);
}

const bool LIB::machine::device::memory::deserialize (const std::string & serial)
{
	return LIB::deserialize <LIB::machine::device::memory> (serial, * this);
}
*/

/*operator const std::string (void) const
{
	return serialize ();
}

const LIB::machine::device::memory & operator = (const std::string & serial)
{
	deserialize (serial);
	return *this;
}*/

//LIB::machine::device::memory::operator const value (void) const
//{
//	return get ();
//}

//LIB::machine::device::memory LIB::machine::device::memory::operator [] (const key & name)
//{
//	if (! exists (name))
//	{
//		set_group (name);
//	}
//	
//	return get (name);
//}

/*const LIB::machine::device::memory & LIB::machine::device::memory::operator [] (const key & name) const
{
	return *this;
}*/

//const LIB::machine::device::memory::value LIB::machine::device::memory::get (void) const
//{
//	// Set "Reference" to "false" and "Content/Content" to ""
//	// if the name which is being
//	
//	//content_clear_group ();
//	
//	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
//	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
//	
//	arguments [1] = previous_group;
//	arguments [2] = previous_name;
//	
//	if (container -> database ().query (result, "\
//			SELECT \"Content\"\n\
//			FROM \"Entities\"\n\
//			WHERE \"Group\" = ? AND \"Name\" = ?;\
//			", arguments))
//	{
//		if (! result.empty ())
//		{
//			return result [1] [1];
//		}
//		//if (result.empty ())
//		//{
//		//	return "";
//		//}
//		//else
//		//{
//		//	return result [1] [1];
//		//}
//	}
//	//else
//	//{
//	//	return "";
//	//}
//	
//	return "";
//	
//	//return mem;
//}
//
//const LIB::machine::device::memory LIB::machine::device::memory::get (const LIB::machine::device::memory::key & nm) const
//{
//	//content_clear_literal (nm/* the new, inexistent, (sub-)name*/);
//	
//	key grp;
//	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
//	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
//	/*
//	
//	arguments [1] = group;
//	arguments [2] = name;
//	
//	if (container -> database ().query (result, "SELECT \"Name\"\n\
//			FROM \"Entities\"\n\
//			WHERE \"Group\" = (SELECT \"Content\" FROM \"Entities\" WHERE \"Group\" = ? AND \"Name\" = ?);", arguments))
//	{
//		if (result.empty ())
//		{
//			return "";
//		}
//		else
//		{
//			return result [1] [1];
//		}
//	}
//	else
//	{
//		return "";
//	}
//	*/
//	
//	//grp = sequence_group_next_available ();
//	
//	//if (grp <= 0)
//	//	return *this;
//	
//	arguments [1] = group;
//	arguments [2] = nm;
//	//arguments [3] = nm;
//	
//	//container -> database ().query (NULL, "BEGIN;\n\
//			--DELETE FROM \"Entities\"\n\
//			--WHERE \"Group\" = ? AND \"Name\" = ?;\n\
//			INSERT OR REPLACE INTO \"Entities\"\n\
//			(\"Group\", \"Name\", \"Reference\", \"Content\")\n\
//			VALUES (?, ?, ?, ?), (?, ?, ?, ?);\n\
//			COMMIT;", arguments);
//	//container -> database ().query (NULL, "BEGIN;\n\
//			UPDATE \"Entities\"\n\
//			SET \"Reference\" = ?, \"Content\" = NULL\n\
//			WHERE \"Group\" = ? AND \"Name\" = ?;\n\
//			COMMIT;", arguments);
//	
//	grp = "";
//	
//	if (container -> database ().query (result, "\
//			SELECT \"Content\"\n\
//			FROM \"Entities\"\n\
//			WHERE \"Group\" = ? AND \"Name\" = ? AND \"Content: Type\" != 0;\
//			", arguments))
//	{
//		if (! result.empty ())
//		{
//			grp = result [1] [1];
//		}
//		//else
//		//{
//		//	grp = result [1] [1];
//		//}
//	}
//	//else
//	//{
//	//	grp = "";
//	//}
//	
//	memory mem (db, grp, group, nm);
//	//return memory (db, group, name);
//	return mem;
//	//return result;
//}

//const bool LIB::machine::device::memory::set/*_literal*/ (const LIB::machine::device::memory::value & val)
//{
//	if (! clear ())
//	{
//		return false;
//	}
//	
//	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
//	
//	//arguments [1] = 0;
//	arguments [1] = val;
//	arguments [2] = previous_group;
//	arguments [3] = previous_name;
//	
//	return container -> database ().query (NULL, "\
//			BEGIN;\n\
//			UPDATE \"Entities\"\n\
//			SET \"Content: Type\" = 0, \"Content\" = ?\n\
//			WHERE \"Group\" = ? AND \"Name\" = ?;\n\
//			COMMIT;\
//			", arguments);
//}

/*
const bool LIB::machine::device::memory::set (const LIB::machine::device::memory::key & name, const LIB::container::NAME_A <LIB::container::NAME_V, LIB::machine::device::memory::value> & values, const LIB::machine::device::memory::key & group)
{
	//if (! values.exists ("Group") || ! values.exists ("Name"))
	//{
	//	return false;
	//}
	
	//LIB::container::NAME_A <LIB::container::NAME_V, value> columns;
	
	//LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	
	LIB::container::NAME_A <> cols;
	
	std::string column_names = "\"Group\", \"Name\"", column_placeholders = "?, ?";
	
	arguments.append (group);
	arguments.append (name);
	
	//cols.append ("Group");
	cols.append ("Name: Type");
	//cols.append ("Name");
	cols.append ("Content: Type");
	cols.append ("Content");
	
	//LIB::container::NAME_V val;
	
	for (const LIB::container::NAME_A <>::package & column_name : cols)
	{
		column_names += ", \"" + column_name.v.to_string () + '\"';
		column_placeholders += ", ?";
		
		if (values.exists (column_name.v))
		{
			arguments.append (values [column_name.v]);
		}
		else
		//{
			if (column_name.v == "Name: Type" || column_name.v == "Content: Type")
			{
				arguments.append (0);
			}
			else// if (column_name == "Content")
			{
				arguments.append (default_value);
			}
		//}
	}
	
	//// Remove the trailing ", ".
	//column_names.substr (0, column_names.size () - 2);
	//column_placeholders.substr (0, column_placeholders.size () - 2);
	
	
	//arguments.append (group);
	//arguments.append (name);
	
	std::cout <<
			"\
			INSERT OR REPLACE INTO \"Entities\"\n\
			" + column_names + "\n\
			VALUES\n\
			(" + column_placeholders + ")\
			"
			<< std::endl;
	
	std::cout << "Arguments:" << std::endl;
	for (const auto & arg : arguments)
	{
		std::cout << '[' << arg.k << ']' << " => " << '[' << arg.v << ']' << std::endl;
	}
	std::cout << "Arguments." << std::endl;
	
	return container -> database ().query ("\
			INSERT OR REPLACE INTO \"Entities\"\n\
			(" + column_names + ")\n\
			VALUES\n\
			(" + column_placeholders + ")\
			", arguments);
//			\"Group\", \"Name: Type\", \"Name\", \"Content: Type\", \"Content\"\n
//			WHERE \"Group\" = ? AND \"Name\" = ?;
}
const bool LIB::machine::device::memory::set (const LIB::machine::device::memory::key & name, const LIB::machine::device::memory::key & group)
{
	const LIB::container::NAME_A <LIB::container::NAME_V, value> values;
	
	return set (name, values, group);
}

const bool LIB::machine::device::memory::set (const LIB::machine::device::memory & other)
{
	operator = (other);
	
	return true;
}
*/

//const bool LIB::machine::device::memory::set_group (const LIB::machine::device::memory::key & name)
//{
//	key used_group;
//	return set_group (name, used_group);
//}
//
//const bool LIB::machine::device::memory::set_group (const LIB::machine::device::memory::key & name, const LIB::machine::device::memory::key & used_group)
//{
//	if (! clear ())
//	{
//		return false;
//	}
//	
//	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
//	
//	//key grp = sequence_group_next_available ();
//	used_group =  sequence_group_next_available ();
//	
//	arguments [1] = used_group;
//	arguments [2] = name;
//	arguments [3] = 1;
//	//arguments [3] = previous_group;
//	
//	if (! container -> database ().query (NULL, "BEGIN", NULL))
//	{
//		container -> database ().query (NULL, "ROLLBACK", NULL);
//		return false;
//	}
//	
//	if (!
//		container -> database ().query (NULL, "\
//			INSERT OR IGNORE INTO \"Entities\"\n\
//			(\"Group\", \"Name\", \"Content: Type\", \"Content\")\n\
//			VALUES (?, ?, ?, NULL)\
//			", arguments)
//	)
//	{
//		container -> database ().query (NULL, "ROLLBACK", NULL);
//		return false;
//	}
//	
//	arguments [1] = 1;
//	arguments [2] = used_group;
//	arguments [3] = previous_group;
//	arguments [4] = previous_name;
//	
//	if (!
//		container -> database ().query (NULL, "\
//			UPDATE \"Entities\"\n\
//			SET \"Content: Type\" = ?, \"Content\" = ?\n\
//			WHERE \"Group\" = ? AND \"Name\" = ?\
//			", arguments)
//	)
//	{
//		container -> database ().query (NULL, "ROLLBACK", NULL);
//		return false;
//	}
//	
//	return container -> database ().query (NULL, "COMMIT", NULL);
//}
//
//const bool LIB::machine::device::memory::set_group (void)
//{
//	if (! clear ())
//	{
//		return false;
//	}
//	
//	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
//	
//	arguments [1] = 1;
//	arguments [2] = previous_group;
//	arguments [3] = previous_name;
//	
//	return container -> database ().query (NULL, "\
//			BEGIN;\n\
//			UPDATE \"Entities\"\n\
//			SET \"Content: Type\" = ?, \"Content\" = NULL\n\
//			WHERE \"Group\" = ? AND \"Name\" = ?;\n\
//			COMMIT;\
//			", arguments);
//}

/*
const LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> LIB::machine::device::memory::get (const LIB::machine::device::memory::key & name, const LIB::machine::device::memory::key & group) const
{
	// This is the default, backup variable:
	const LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> columns;
	
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	
	arguments [1] = group;
	arguments [2] = name;
	
	//	SELECT \"Group\", \"Name: Type\", \"Name\", \"Content: Type\", \"Content\"\n\
	//
	container -> database ().query (result, "\
		SELECT \"Name: Type\", \"Content: Type\", \"Content\"\n\
		FROM \"Entities\"\n\
		WHERE \"Group\" = ? AND \"Name\" = ?\
		", arguments);
	
	if (result.empty ())
	{
		// Return the default, backup variable.
		return columns;
	}
	else
	{
		// There should always be one row present because of the (unique) index, if there is anything present.
		// Return the first (and only) row.
		// 
		// Use the fact that "LIB::machine::device::memory::value == LIB::container::NAME_V", for now.
		return result [1];
	}
}

const bool LIB::machine::device::memory::is_name_literal (const LIB::machine::device::memory::key & name, const LIB::machine::device::memory::key & group) const
{
	//key grp;
	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	//grp = sequence_group_next_available ();
	
	//if (grp <= 0)
	//	return false;
	
	arguments [1] = group;
	arguments [2] = name;
	
	if (container -> database ().query (result, "\
			SELECT \"Name: Type\"\n\
			FROM \"Entities\"\n\
			WHERE \"Group\" = ? AND \"Name\" = ?\
			", arguments));
	
	return result [1] [1] == 0;
}
*/

/*
const bool LIB::machine::device::memory::is_name_group (const LIB::machine::device::memory::key & name, const LIB::machine::device::memory::key & group) const
{
	return ! is_name_literal (name, group);
}
*/

/*
const bool LIB::machine::device::memory::is_content_literal (const LIB::machine::device::memory::key & name, const LIB::machine::device::memory::key & group) const
{
	//key grp;
	LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V> arguments;
	LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V> result;
	
	//grp = sequence_group_next_available ();
	
	//if (grp <= 0)
	//	return false;
	
	arguments [1] = group;
	arguments [2] = name;
	
	if (container -> database ().query (result, "\
			SELECT \"Content: Type\"\n\
			FROM \"Entities\"\n\
			WHERE \"Group\" = ? AND \"Name\" = ?\
			", arguments));
	
	return result [1] [1] == 0;
}
*/

/*
const bool LIB::machine::device::memory::is_value_group (const LIB::machine::device::memory::key & name, const LIB::machine::device::memory::key & group) const
{
	return ! is_content_literal (name, group);
}
*/
/*
const bool content_clear_literal (const key & name)
{
	return false;
}

const bool content_clear_group (const key & name)
{
	return false;
}
*/
