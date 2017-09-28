#include <iostream>
#include "memory.h++"
//#include "../../network/ip.h++"
//#include <boost/mem_fn.hpp>
//#include <boost/ref.hpp>

// Memory: Iterator:

//const std::string LIB::containers::memory::default_database_name;
/*
LIB::cluster::entity::iterator::iterator (void)
{
	//set = false;
}
*/
/*
LIB::cluster::entity::iterator::iterator (const memory & other)
{
	operator = (other);
}

LIB::cluster::entity::iterator::~iterator (void)
{
}

const LIB::cluster::entity::iterator & LIB::cluster::entity::iterator::operator = (const iterator & other)
{
	return *this;
}
*/
/*
const bool LIB::cluster::entity::iterator::operator == (const LIB::cluster::entity::iterator & other) const
{
	return iter == other.iter;
}

const bool LIB::cluster::entity::iterator::operator != (const LIB::cluster::entity::iterator & other) const
{
	return ! (operator == (other));
}

const LIB::cluster::entity::iterator & LIB::cluster::entity::iterator::operator ++ (void)
{
	++ iter;
	
	return * this;
}

const LIB::cluster::entity::iterator & LIB::cluster::entity::iterator::operator -- (void)
{
	-- iter;
	
	return * this;
}

const LIB::containers::NAME_A <LIB::cluster::entity *, LIB::containers::memory::key>::package & LIB::cluster::entity::iterator::operator * (void) const
{
	//return * (iter -> v);
	return * iter;
}
*/
// Memory:
//const bool LIB::cluster::entity::default_tolerant = LIB::cluster::entity::default_tolerant;
/*
const LIB::containers::memory::key LIB::cluster::entity::default_group = "";
const LIB::containers::memory::key LIB::cluster::entity::default_name = "";
const LIB::containers::memory::value LIB::cluster::entity::default_value = "";
*/
//const LIB::containers::memory::key LIB::cluster::entity::default_name = "";
//const LIB::containers::memory::value LIB::cluster::entity::backup;
LIB::containers::NAME_A <LIB::mathematics::numbers::natural, LIB::machine::resources::memory *> LIB::cluster::entity::instances;

const bool LIB::cluster::entity::initialize (const LIB::cluster::entity * other, const LIB::containers::memory::key & _name, const LIB::containers::memory::key & _group)
{
	if (other == NULL)
	{
		_memory = new LIB::machine::resources::memory ();
		tolerant = LIB::containers::entity_2::default_tolerant;
		
		//++ instances [_memory];
		instances [_memory] = 0;
		
		if (! _memory -> exists (LIB::containers::entity_2::default_name, LIB::containers::memory::default_group))
		{
			if (! _memory -> set (LIB::containers::entity_2::default_name, LIB::containers::memory::default_value, LIB::containers::memory::default_group))
			{
				return false;
			}
		}
	}
	else
	{
		try
		{
			_memory = other -> _memory;
			tolerant = other -> tolerant;
		}
		catch (...)
		{
			return false;
		}
	}
	
	std::cout << instances [_memory] << std::endl;
	++ instances [_memory];
	std::cout << instances [_memory] << std::endl;
	
	group = _group;
	name = _name;
	
	return true;
}
/*
const bool LIB::cluster::entity::initialize (const std::string & database)
{
	return initialize (NULL, default_name, memory::default_group, database);
}
*/
/*
LIB::cluster::entity::entity (const LIB::cluster::entity * other, const LIB::containers::memory::key & _name, const LIB::containers::memory::key & _group)
{
	initialize (other, _name, _group);
}
*/
/*
LIB::cluster::entity::entity_2 (const std::string & database)
{
	initialize (NULL,.default_name, memory::default_group, database);
}
*/
/*
LIB::cluster::entity::entity (const LIB::cluster::entity & other)
{
	std::cout << instances [_memory] << std::endl;
	++ instances [other._memory];
	std::cout << instances [_memory] << std::endl;
	
	_memory = other._memory;
	tolerant = other.tolerant;
	group = other.group;
	name = other.name;
}

const bool LIB::cluster::entity::finalize (void)
{
	std::cout << instances [_memory] << std::endl;
	-- instances [_memory];
	std::cout << instances [_memory] << std::endl;
	
	if (instances [_memory] < 1)
	{
		delete _memory;
		instances.unset (_memory);
	}
}

LIB::cluster::entity::~entity (void)
{
	finalize ();
}
*/
const LIB::mathematics::numbers::integer LIB::cluster::entity::key_integral_min (void) const
{
	if (is_content_literal ())
	{
		return 0;
	}
	
	//const LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> row = _memory -> get (name, group);
	
	return _memory -> key_name_integral_min (_memory -> get (name, group) [3]);
}

const LIB::mathematics::numbers::integer LIB::cluster::entity::key_integral_max (void) const
{
	if (is_content_literal ())
	{
		return 0;
	}
	
	return _memory -> key_name_integral_max (_memory -> get (name, group) [3]);
}

const LIB::containers::memory::key LIB::cluster::entity::sequence_next_available (void) const
{
	if (is_content_literal ())
		return 0;
	
	return _memory -> sequence_name_next_available (_memory -> get (name, group) [3]);
}
/*
const LIB::containers::memory::key LIB::cluster::entity::sequence_next (void) const
{
	return key_integral_max () + 1;
}
*/
const bool LIB::cluster::entity::set (const LIB::containers::memory::value & val)
{
	clear ();
	
	LIB::containers::NAME_A <LIB::containers::NAME_V, value> values;
	
	values ["Name: Type"] = 0;
	values ["Content: Type"] = 0;
	values ["Content"] = val;
	
	return _memory -> set (name, values, group);
}

const LIB::containers::memory::value LIB::cluster::entity::get (void) const
{
	return _memory -> get (name, group) [3];
}
/*
LIB::cluster::entity::operator const LIB::containers::memory::value/* &* / (void) const
{
	return get ();
}
*/
/*
std::ostream & operator << (std::ostream & stream, const LIB::cluster::entity & ntt)
{
	stream << ntt.get ();
	
	return stream;
}
*/
/*
std::ostream & LIB::cluster::entity::operator << (std::ostream & stream) const
{
	stream << get ();
	
	return stream;
}
*/
LIB::cluster::entity LIB::cluster::entity::get (const LIB::containers::memory::key & _name)
{
	if (! tolerant && is_content_literal ())
		return *this;
	
	if (_memory -> is_content_literal (name, group))
	{
		LIB::containers::NAME_A <LIB::containers::NAME_V, value> values;
		
		//values ["Name: Type"] = 0;
		values ["Content: Type"] = 1;
		//values ["Content"] = default_value;
		values ["Content"] = _memory -> sequence_group_next_available ();
		
		if (! _memory -> set (_name, values, group))
			return *this;
	}
	
	const key _group =  _memory -> get (name, group) [3];
	
	LIB::containers::NAME_A <LIB::containers::NAME_V, value> values;
	
	values ["Name: Type"] = 0;
	values ["Content: Type"] = 0;
	values ["Content"] = default_value;
	//values ["Content"] = _memory -> sequence_group_next_available ();
	
	if (! _memory -> set (_name, values, _group))
		return *this;
	
	// Finally, return the representation of the new entity.
	return entity (this, _name, _group, _memory -> database_name ());
	
}

const LIB::cluster::entity & LIB::cluster::entity::operator = (const LIB::cluster::entity & other)
{
	finalize ();
	
	initialize (& other, other.name, other.group, other._memory -> database_name ());
	
	return * this;
}

const LIB::containers::memory::value & LIB::cluster::entity::operator = (const LIB::containers::memory::value & val)
{
	set (val);
	
	return val;
}

LIB::cluster::entity LIB::cluster::entity::operator [] (const LIB::containers::memory::key & _name)
{
	//clear_literal ();
	
	return get (_name);
}

const bool LIB::cluster::entity::unset (const LIB::containers::memory::key & _name)
{
	if (is_content_literal ())
		return false;
	
	return _memory -> unset (_name, _memory -> get (name, group) [3]);
}

const bool LIB::cluster::entity::rename (const LIB::containers::memory::key & name_current, const LIB::containers::memory::key & name_new)
{
	if (is_content_literal () || ! exists (name_current) || exists (name_new))
		return false;
	
	LIB::containers::NAME_A <LIB::containers::NAME_V, value> values;
	
	values ["Name"] = name_new;
	//values ["Content: Type"] = 0;
	//values ["Content"] = default_value;
	//values ["Content"] = _memory -> sequence_group_next_available ();
	
	return _memory -> set (name_current, values, _memory -> get (name, group) [3]);
}

/*
const bool LIB::cluster::entity::clear_literal (void)
{
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	//LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
	
	arguments.append (group);
	arguments.append (default_name);
	
	return
		_memory -> database ().query
		(
			"\
				DELETE FROM\n\
					\"Entities\"\n\
				WHERE\n\
					\"Group\" = ?\n\
					AND\n\
					\"Name\" = ?\
			",
			arguments
		)
	;
}
*/
/*
const bool LIB::cluster::entity::clear_group (void)
{
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	//LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
	
	arguments.append (group);
	//arguments.append (name);
	
	return
		_memory -> database ().query
		(
			"\
				DELETE FROM\n\
					\"Entities\"\n\
				WHERE\n\
					\"Group\" = ?\n\
					--AND\n\
					--\"Name\" != ?\
			",
			arguments
		)
	;
}
*/

const LIB::mathematics::numbers::natural LIB::cluster::entity::size (void) const
{
	if (is_content_literal ())
		return 1;
	
	return _memory -> size_group (_memory -> get (name, group) [3]);
}

const bool LIB::cluster::entity::clear (void)
{
	return _memory -> clear_group (_memory -> get (name, group) [3]);
}

//const bool LIB::cluster::entity::empty (void) const
//{
//	return ! (size () > 0);
//}

const bool LIB::cluster::entity::full (void) const
{
	return _memory -> full ();
}

const bool LIB::cluster::entity::exists (const LIB::containers::memory::key & _name) const
{
	if (is_content_literal ())
		return false;
	
	return _memory -> exists (_name, _memory -> get (name, group) [3]);
}

//const bool LIB::cluster::entity::add (const LIB::containers::memory::value & val)
//{
//	LIB::containers::memory::key name;
//	
//	return add (val, name);
//}

//const bool LIB::cluster::entity::add (const LIB::containers::memory::value & val, LIB::containers::memory::key & _name)
//{
//	return add_internal (val, _name, sequence_next_available ());
//}

const bool LIB::cluster::entity::_add (const LIB::containers::memory::value & val, LIB::containers::memory::key & _name, const LIB::containers::memory::key & sequence_next_value)
{
	LIB::containers::NAME_A <LIB::containers::NAME_V, value> values;
	
	_name = sequence_next_value;
	
	if (_memory -> is_content_literal (name, group))
	{
		//values ["Name"] = sequence_next_value;
		values ["Content"] = sequence_next_value;
		values ["Content: Type"] = 1;
		
		// Make it a reference.
		if (! _memory -> set (_name, values, group))
			return false;
	}
	
	values ["Name: Type"] = 0;
	//values ["Name"] = _name;
	values ["Content: Type"] = 0;
	values ["Content"] = val;
	
	// Add the new entry.
	return _memory -> set (_name, values, _memory -> get (name, group) [3]);
}
/*
const bool LIB::cluster::entity::append (const LIB::containers::memory::value & val)
{
	LIB::containers::memory::key _name;
	
	return append (val, _name);
}

const bool LIB::cluster::entity::append (const LIB::containers::memory::value & val, LIB::containers::memory::key & _name)
{
	return add_internal (val, _name, sequence_next ());
}

const bool LIB::cluster::entity::enqueue (const LIB::containers::memory::value & val)
{
	LIB::containers::memory::key _name;
	
	return enqueue (val, _name);
}

const bool LIB::cluster::entity::enqueue (const LIB::containers::memory::value & val, LIB::containers::memory::key & _name)
{
	return append (val, _name);
}
*/
const bool LIB::cluster::entity::dequeue (void)
{
	if
	(
		! _memory -> database ().query
		(
			"BEGIN"
		)
	)
		return false;
	
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	
	arguments.append (group);
	arguments.append (name);
	arguments.append (group);
	arguments.append (name);
	
	// Remove the first entry.
	if
	(
		! _memory -> database ().query
		(
			"\
				DELETE\n\
				FROM\n\
					\"Entities\"\n\
				WHERE\n\
					\"Group\" =\n\
					(\n\
						SELECT\n\
							\"Content\"\n\
						FROM\n\
							\"Entities\"\n\
						WHERE\n\
							\"Group\" = ?\n\
							AND\n\
							\"Name\" = ?\n\
					)\n\
					AND\n\
					\"Name\" =\n\
					(\n\
						SELECT COALESCE (MIN (\"Name\"), 0)\n\
						FROM \"Entities\"\
						WHERE TYPEOF (\"Name\") = 'integer'\n\
						AND \"Group\" =\n\
						(\n\
							SELECT\n\
								\"Content\"\n\
							FROM\n\
								\"Entities\"\n\
							WHERE\n\
								\"Group\" = ?\n\
								AND\n\
								\"Name\" = ?\n\
						)\n\
					)\
			",
			arguments
		)
	)
		return false;
	
	arguments.unset (3);
	arguments.unset (4);
	
	// Shift the next entries by one, towards the beginning.
	if
	(
		! _memory -> database ().query
		(
			"\
				UPDATE\n\
					\"Entities\"\n\
				SET\n\
					\"Name\" = \"Name\" - 1\n\
				WHERE\n\
					\"Group\" =\n\
					(\n\
						SELECT\n\
							\"Content\"\n\
						FROM\n\
							\"Entities\"\n\
						WHERE\n\
							\"Group\" = ?\n\
							AND\n\
							\"Name\" = ?\n\
					)\n\
					AND\n\
					TYPEOF (\"Name\") = 'integer'\n\
					AND\n\
					\"Name\" > 0\
			",
			arguments
		)
	)
	{
		_memory -> database ().query ("ROLLBACK");
		
		return false;
	}
	
	return
		_memory -> database ().query
		(
			"COMMIT"
		)
	;
}
/*
const bool LIB::cluster::entity::push (const LIB::containers::memory::value & val)
{
	LIB::containers::memory::key _name;
	
	return push (val, _name);
}

const bool LIB::cluster::entity::push (const LIB::containers::memory::value & val, LIB::containers::memory::key & _name)
{
	return append (val, _name);
}
*/
const bool LIB::cluster::entity::pop (void)
{
	if
	(
		! _memory -> database ().query
		(
			"BEGIN"
		)
	)
		return false;
	
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	
	arguments.append (group);
	arguments.append (name);
	arguments.append (group);
	arguments.append (name);
	
	// Remove the last entry.
	if
	(
		! _memory -> database ().query
		(
			"\
				DELETE\n\
				FROM\n\
					\"Entities\"\n\
				WHERE\n\
					\"Group\" =\n\
					(\n\
						SELECT\n\
							\"Content\"\n\
						FROM\n\
							\"Entities\"\n\
						WHERE\n\
							\"Group\" = ?\n\
							AND\n\
							\"Name\" = ?\n\
					)\n\
					AND\n\
					\"Name\" =\n\
					(\n\
						SELECT\n\
							COALESCE (MAX (\"Name\"), 0)\n\
						FROM\n\
							\"Entities\"\
						WHERE\n\
							TYPEOF (\"Name\") = 'integer'\n\
							AND \"Group\" =\n\
							(\n\
								SELECT\n\
									\"Content\"\n\
								FROM\n\
									\"Entities\"\n\
								WHERE\n\
									\"Group\" = ?\n\
									AND\n\
									\"Name\" = ?\n\
							)\n\
					)\
			",
			arguments
		)
	)
		return false;
	
	return
		_memory -> database ().query
		(
			"COMMIT"
		)
	;
}
/*
const bool LIB::cluster::entity::refresh_list (void)
{
	for (const LIB::containers::NAME_A <LIB::cluster::entity *, LIB::containers::memory::key>::package & element : _list)
	{
		delete element.v;
	}
	_list.clear ();
	
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
	
	if (is_content_literal ())
	{
		arguments.append (group);
		
		if
		(
			! _memory -> database ().query
			(
				result,
				"\
					SELECT\n\
						\"Group\",\n\
						\"Name\"\n\
					FROM\n\
						\"Entities\"\n\
					WHERE\n\
						\"Group\" = ?\
				",
				arguments
			)
		)
			return false;
	}
	else
	{
		arguments.append (group);
		arguments.append (name);
		
		if
		(
			! _memory -> database ().query
			(
				result,
				"\
					SELECT\n\
						\"Group\",\n\
						\"Name\"\n\
					FROM\n\
						\"Entities\"\n\
					WHERE\n\
						\"Group\" =\n\
						(\n\
							SELECT\n\
								\"Content\"\n\
							FROM\n\
								\"Entities\"\n\
							WHERE\n\
								\"Group\" = ?\n\
								AND\n\
								\"Name\" = ?\n\
						)\
				",
				arguments
			)
		)
			return false;
	}
	
	for (const LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V>::package & row : result)
	{
		//for (const LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>::package & column : row.v)
		//{
			//_list.append (entity_2 (this, row.v [2], row.v [1], _memory -> database_name ()));
			_list [row.v [2]] = new entity_2 (this, row.v [2], row.v [1], _memory -> database_name ());
		//}
	}
	
	return true;
}

const LIB::containers::NAME_A <LIB::cluster::entity *, LIB::containers::memory::key> & LIB::cluster::entity::list (void) const
{
	return _list;
}

const LIB::cluster::entity::iterator LIB::cluster::entity::begin (void)
{
	iterator iter;
	//entity_2 ntt (this, _name, _group, _memory -> database_name ());
	iter.iter = _list.begin ();
	
	return iter;
}

const LIB::cluster::entity::iterator LIB::cluster::entity::end (void)
{
	iterator iter;
	//entity_2 ntt (this, _name, _group, _memory -> database_name ());
	iter.iter = _list.end ();
	
	return iter;
}
*/
const LIB::cluster::entity LIB::cluster::entity::beginning (void) const
{
	//entity_2 ntt (this, _name, _group, _memory -> database_name ());
	return *this;
}

const LIB::cluster::entity LIB::cluster::entity::ending (void) const
{
	//entity_2 ntt (this, _name, _group, _memory -> database_name ());
	return *this;
}
/*
const LIB::containers::entity::relation LIB::cluster::entity::relate (const LIB::cluster::entity & other) const
{
	return relation::other;
}
*/
const bool LIB::cluster::entity::is_content_literal (void) const
{
	return _memory -> get (name, group) [2] == 0;
}

const std::string LIB::cluster::entity::serialize (void) const
{
	return LIB::serialize <LIB::cluster::entity> (* this);
}

const bool LIB::cluster::entity::deserialize (const std::string & serial)
{
	return LIB::deserialize <LIB::cluster::entity> (serial, * this);
}

template <typename archive>
void LIB::cluster::entity::save (archive & arch, const unsigned int & version) const
{
}

template <typename archive>
void LIB::cluster::entity::load (archive & arch, const unsigned int & version)
{
}
