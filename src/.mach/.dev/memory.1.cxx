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

