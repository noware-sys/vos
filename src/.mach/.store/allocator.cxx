const noware::var noware::mach::storage::allocator::group_default = "allocator";

noware::mach::storage::allocator::allocator (void)
{
	//data.initialize ();
	data.initialize ("data.db");
	
	node.join (noware::mach::storage::allocator::group_default);
	node.join (noware::mach::storage::group_default);
	//node.join ("storage.sqlite.persistent");
}

noware::mach::storage::allocator::~allocator (void)
{
	//node.leave ("storage.sqlite.persistent");
	node.leave (noware::mach::storage::group_default);
	node.leave (noware::mach::storage::allocator::group_default);
	
	//data.finalize ();
}

/*
const bool noware::mach::storage::sqlite::finalize (void)
{
	if (!data.finalize ())
		return false;
	
	return true;
}

const bool noware::mach::storage::sqlite::initialize (void)
{
	if (!data.connect ("data.db"))
		return false;
	
	if (!data.query (query_sql_initial))
		return false;
	
	return true;
}
*/

const bool noware::mach::storage::allocator::respond (const noware::tree <> & message, const zyre_event_t * event)
{
	std::cout << "noware::mach::storage::sqlite::respond()::called" << std::endl;
	
	noware::tree <> response;
	bool result;
	
	result = false;
	
	if (message ["type"] == "response")
	{
		std::cout << "noware::mach::storage::sqlite::respond()::if::message[type]==" << message ["type"] << "::in scope" << std::endl;
		
		//if (message ["subject"] == "presence")
		//{
			std::cout << "noware::mach::storage::sqlite::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			//std::cout << "noware::mach::storage::receive()::else::msg[subject]==" << msg ["subject"] << "::sleeping" << std::endl;
			//zclock_sleep (1500);
			
			// Redirect the message to the function which asked for it.
			//unicast_local (zmsg_popstr (zmq_msg));
			result = unicast_local (message);
			std::cout << "noware::mach::storage::sqlite::respond()::unicast_local (message)==" << (result ? "Success" : "Failure") << std::endl;
		//}
	}
	else	// if (message ["type"] == "request")
	{
		std::cout << "noware::mach::storage::sqlite::respond()::if::message[type]==" << message ["type"] << "::else::in scope" << std::endl;
		
		if (message ["subject"] == "group.minimum")
		{
			std::cout << "noware::mach::storage::sqlite::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			response ["key"] = message ["key"];
			response ["value"] = data.exist (message ["group"], message ["key"]);
		}
		else if (message ["subject"] == "group.maximum")
		{
			std::cout << "noware::mach::storage::sqlite::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			//response ["key"] = message ["key"];
			response ["value"] = data.magnitude ();
		}
		else if (message ["subject"] == "group.next")
		{
			std::cout << "noware::mach::storage::sqlite::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			response ["key"] = message ["key"];
			response ["value.present"] = data.exist (message ["group"], message ["key"]);
			if (response ["value.present"].get_value ())
				response ["value"] = data.get (message ["group"], message ["key"]);
		}
		else if (message ["subject"] == "group.available")
		{
			std::cout << "noware::mach::storage::sqlite::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			response ["key"] = message ["key"];
			response ["presence"] = data.exist (message ["group"], message ["key"]);
			if (response ["presence"].get_value ())
				response ["success"] = data.set (message ["group"], message ["key"], message ["value"]);
			else
				response ["success"] = false;
		}
		else if (message ["subject"] == "key.minimum")
		{
			std::cout << "noware::mach::storage::sqlite::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			response ["key"] = message ["key"];
			//response ["meta"] = data.exist (message ["key"]);
			//if (response ["meta"])
			response ["success"] = data.remove (message ["group"], message ["key"]);
		}
		else if (message ["subject"] == "key.maximum")
		{
			std::cout << "noware::mach::storage::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			//response ["key"] = message ["key"];
			//response ["meta"] = data.exist (message ["key"]);
			//if (response ["meta"])
			response ["success"] = data.reset ();
		}
		else if (message ["subject"] == "key.next")
		{
			std::cout << "noware::mach::storage::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			//response ["key"] = message ["key"];
			//response ["meta"] = data.exist (message ["key"]);
			//if (response ["meta"])
			response ["success"] = data.reset ();
		}
		else if (message ["subject"] == "key.available")
		{
			std::cout << "noware::mach::storage::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			//response ["key"] = message ["key"];
			//response ["meta"] = data.exist (message ["key"]);
			//if (response ["meta"])
			response ["success"] = data.reset ();
		}
		else
		{
			return false;
		}
		
		//// Send back the answer.
		//result = node.unicast (response, zyre_event_peer_uuid (event));
		std::cout << "noware::mach::storage::sqlite::respond()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
		//return result;
	}
	
	return result;
}

const bool noware::mach::storage::allocator::search (noware::var & result, const noware::tree <> & message)
{
	std::cout << "noware::mach::storage::sqlite::search()::called" << std::endl;
	
	if (message ["subject"] == "presence")
	{
		result = message ["value"];
		
		return !result;
	}
	else if (message ["subject"] == "magnitude")
	{
		if (result.type () != noware::var::container::type::numeric)
			result = 0;
		
		//result += data.size ();
		result += message ["value"];
		
		return true;
	}
	else if (message ["subject"] == "attainment")
	{
		if (!(message ["value.present"].get_value ()))
		{
			return true;
		}
		
		result = message ["value"];
		
		return false;
	}
	else if (message ["subject"] == "settlement")
	{
		result = message ["success"];
		
		return !result;
	}
	else if (message ["subject"] == "removal")
	{
		result = message ["success"];
		//result = result && message ["success"];
		
		//if (!result)
		//{
			//result = true;
		//	return true;
		//}
		
		return result;
	}
	else if (message ["subject"] == "resettal")
	{
		result = message ["success"];
		//result = result && message ["success"];
		
		return result;
	}
	
	return false;
}

const bool noware::mach::storage::allocator::search_local (noware::var & result, const noware::tree <> & message)
{
	return false;
}

const noware::var noware::mach::storage::allocator::aggregate (const noware::var & result, const noware::var & response, const noware::tree <> & expression)
{
	if (expression ["subject"] == "magnitude")
	{
		return result + response;
	}
	
	return response;
}

const noware::nr noware::mach::storage::allocator::group_min (void)
{
}

const noware::nr noware::mach::storage::allocator::group_max (void)
{
}

const noware::nr noware::mach::storage::allocator::group_next (void)
{
	return group_max () + 1;
}

const noware::nr noware::mach::storage::allocator::group_avail (void)
{
	noware::tree <> expression;
	noware::nr group;
	
	group = 0;
	//expression ["key"] = "";
	
	do
	{
		++ group;
		
		expression ["subject"] = "existence.group";
		expression ["group"] = group;
	}
	while (evaluate (expression, noware::mach::storage::group_default));
	
	return group;
}

const noware::nr noware::mach::storage::allocator::key_min (const std::string & group)
{
}

const noware::nr noware::mach::storage::allocator::key_max (const std::string & group)
{
}

const noware::nr noware::mach::storage::allocator::key_next (const std::string & group)
{
	return key_max (group) + 1;
}

const noware::nr noware::mach::storage::allocator::key_avail (const std::string & group)
{
	noware::tree <> expression;
	noware::nr key;
	
	expression ["group"] = group;
	key = 0;
	
	do
	{
		++ key;
		
		expression ["subject"] = "existence";
		expression ["key"] = key;
	}
	while (evaluate (expression, noware::mach::storage::group_default));
	
	return key;
}
