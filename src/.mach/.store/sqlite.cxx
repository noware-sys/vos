const noware::var noware::machine::storage::sqlite::group_default = "storage.sqlite";

noware::machine::storage::sqlite::sqlite (void)
{
	//data.initialize ();
	data.initialize ("data.db");
	
	node.join (noware::machine::storage::sqlite::group_default);
	//node.join (noware::machine::storage::group_default);
	//node.join ("storage.sqlite.persistent");
}

noware::machine::storage::sqlite::~sqlite (void)
{
	//node.leave (noware::machine::storage::group_default);
	node.leave (noware::machine::storage::sqlite::group_default);
	//node.leave ("storage.sqlite.persistent");
	
	//data.finalize ();
}

/*
const bool noware::machine::storage::sqlite::finalize (void)
{
	if (!data.finalize ())
		return false;
	
	return true;
}

const bool noware::machine::storage::sqlite::initialize (void)
{
	if (!data.connect ("data.db"))
		return false;
	
	if (!data.query (query_sql_initial))
		return false;
	
	return true;
}
*/

const bool noware::machine::storage::sqlite::respond (const noware::tree <> & message, const zyre_event_t * event)
{
	std::cout << "noware::machine::storage::sqlite::respond()::called" << std::endl;
	
	noware::tree <> response;
	bool result;
	
	result = false;
	
	if (message ["type"] == "response")
	{
		std::cout << "noware::machine::storage::sqlite::respond()::if::message[type]==" << message ["type"] << "::in scope" << std::endl;
		
		//if (message ["subject"] == "existence")
		//{
			std::cout << "noware::machine::storage::sqlite::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			//std::cout << "noware::machine::storage::receive()::else::msg[subject]==" << msg ["subject"] << "::sleeping" << std::endl;
			//zclock_sleep (1500);
			
			// Redirect the message to the function which asked for it.
			//unicast_local (zmsg_popstr (zmq_msg));
			result = unicast_local (message);
			std::cout << "noware::machine::storage::sqlite::respond()::unicast_local (message)==" << (result ? "Success" : "Failure") << std::endl;
		//}
	}
	else	// if (message ["type"] == "request")
	{
		std::cout << "noware::machine::storage::sqlite::respond()::if::message[type]==" << message ["type"] << "::else::in scope" << std::endl;
		
		if (message ["subject"] == "existence")
		{
			std::cout << "noware::machine::storage::sqlite::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			response ["key"] = message ["key"];
			response ["value"] = data.exist (message ["group"], message ["key"]);
		}
		else if (message ["subject"] == "magnitude")
		{
			std::cout << "noware::machine::storage::sqlite::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			//response ["key"] = message ["key"];
			response ["value"] = data.size ();
		}
		else if (message ["subject"] == "obtainment")
		{
			std::cout << "noware::machine::storage::sqlite::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			response ["key"] = message ["key"];
			response ["value.exist"] = data.exist (message ["group"], message ["key"]);
			if (response ["value.exist"].get_value ())
				response ["value"] = data.get (message ["group"], message ["key"]);
		}
		else if (message ["subject"] == "settlement")
		{
			std::cout << "noware::machine::storage::sqlite::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			response ["key"] = message ["key"];
			response ["existence"] = data.exist (message ["group"], message ["key"]);
			if (response ["existence"].get_value ())
				response ["value"] = data.set (message ["group"], message ["key"], message ["value"]);
			else
				response ["value"] = false;
		}
		else if (message ["subject"] == "removal")
		{
			std::cout << "noware::machine::storage::sqlite::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			response ["key"] = message ["key"];
			//response ["meta"] = data.exist (message ["key"]);
			//if (response ["meta"])
			response ["value"] = data.remove (message ["group"], message ["key"]);
		}
		else if (message ["subject"] == "clearance")
		{
			std::cout << "noware::machine::storage::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			//response ["key"] = message ["key"];
			//response ["meta"] = data.exist (message ["key"]);
			//if (response ["meta"])
			response ["value"] = data.clear ();
		}
		else
		{
			return false;
		}
		
		// Send back the answer.
		result = node.unicast (response, zyre_event_peer_uuid (event));
		std::cout << "noware::machine::storage::sqlite::respond()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
		//return result;
	}
	
	return result;
}

const bool noware::machine::storage::sqlite::search (noware::var & result, const noware::tree <> & message)
{
	std::cout << "noware::machine::storage::sqlite::search()::called" << std::endl;
	
	if (message ["subject"] == "existence")
	{
		result = message ["value"];
		
		return result;
	}
	else if (message ["subject"] == "magnitude")
	{
		if (result.type () != noware::var::container::type::numeric)
			result = 0;
		
		//result += data.size ();
		result += message ["value"];
		
		return true;
	}
	else if (message ["subject"] == "obtainment")
	{
		if (!(message ["value.exist"].get_value ()))
		{
			return true;
		}
		
		result = message ["value"];
		
		return false;
	}
	else if (message ["subject"] == "settlement")
	{
		result = message ["value"];
		
		return result;
	}
	else if (message ["subject"] == "removal")
	{
		result = message ["value"];
		//result = result && message ["value"];
		
		//if (!result)
		//{
			//result = true;
		//	return true;
		//}
		
		return result;
	}
	else if (message ["subject"] == "clearance")
	{
		result = message ["value"];
		//result = result && message ["value"];
		
		return result;
	}
	
	return false;
}

const bool noware::machine::storage::sqlite::search_local (noware::var & result, const noware::tree <> & message)
{
	std::cout << "noware::machine::storage::sqlite::search_local()::called" << std::endl;
	
	std::cout << "noware::machine::storage::sqlite::search_local()::message[subject]==[" << message ["subject"] << ']' << std::endl;
	
	
	//bool result;
	bool r;
	
	if (message ["subject"] == "existence")
	{
		std::cout << "noware::machine::storage::sqlite::search_local()::message[group]==[" << message ["group"] << ']' << std::endl;
		std::cout << "noware::machine::storage::sqlite::search_local()::message[key]==[" << message ["key"] << ']' << std::endl;
		
		result = r = data.exist (message ["group"], message ["key"]);
		
		std::cout << "noware::machine::storage::sqlite::search_local()::r==[" << r << ']' << std::endl;
		std::cout << "noware::machine::storage::sqlite::search_local()::result==[" << result << ']' << std::endl;
		
		//return true;
		return result;
	}
	else if (message ["subject"] == "magnitude")
	{
		if (result.type () != noware::var::container::type::numeric)
			result = 0;
		
		result += data.size ();
		
		return false;
	}
	else if (message ["subject"] == "obtainment")
	{
		std::cout << "noware::machine::storage::sqlite::search_local()::message[group]==[" << message ["group"] << ']' << std::endl;
		std::cout << "noware::machine::storage::sqlite::search_local()::message[key]==[" << message ["key"] << ']' << std::endl;
		
		if (!data.exist (message ["group"], message ["key"]))
		{
			return false;
		}
		
		result = data.get (message ["group"], message ["key"]);
		
		return true;
	}
	else if (message ["subject"] == "settlement")
	{
		std::cout << "noware::machine::storage::sqlite::search_local()::message[group]==[" << message ["group"] << ']' << std::endl;
		std::cout << "noware::machine::storage::sqlite::search_local()::message[key]==[" << message ["key"] << ']' << std::endl;
		std::cout << "noware::machine::storage::sqlite::search_local()::message[value]==[" << message ["value"] << ']' << std::endl;
		
		if (data.exist (message ["group"], message ["key"]))
		{
			result = data.set (message ["group"], message ["key"], message ["value"]);
			
			return true;
		}
		else if (!exist (message ["group"], message ["key"]))
		{
			result = data.set (message ["group"], message ["key"], message ["value"]);
			
			return true;
		}
		else
		{
			result = false;
			
			return false;
		}
	}
	else if (message ["subject"] == "removal")
	{
		std::cout << "noware::machine::storage::sqlite::search_local()::message[subject]==[" << message ["subject"] << ']' << "::pre" << std::endl;
		
		//if (data.exist (message ["group"], message ["key"]))
		//{
		//	std::cout << "noware::machine::storage::sqlite::search_local()::message[subject]==[" << message ["subject"] << ']' << "::data.exists(" << message ["key"] << ")==true" << std::endl;
			
			result = data.remove (message ["group"], message ["key"]);
			
			//return !result;
			return result;
			//return true;
		//}
		
		std::cout << "noware::machine::storage::sqlite::search_local()::message[subject]==[" << message ["subject"] << ']' << "::post" << std::endl;
		
		//return false;
	}
	else if (message ["subject"] == "clearance")
	{
		//if (!result)
		//	result = true;
		
		//result = result || data.clear ();
		result = data.clear ();
		
		return !result;
	}
	
	return false;
}

const noware::var noware::machine::storage::sqlite::aggregate (const noware::var & result, noware::nr::natural & responses_count, const noware::var & response, const noware::tree <> & expression)
{
	if (expression ["subject"] == "magnitude")
	{
		return result + response;
	}
	else if (expression ["subject"] == "removal")
	{
		if (responses_count > noware::nr::natural (0))
			return result && response;
		else
			return result;
	}
	
	return response;
}

const noware::nr noware::machine::storage::sqlite::size (void) const
{
	noware::tree <> expression;
	
	expression ["subject"] = "magnitude";
	
	return evaluate (expression, noware::machine::storage::sqlite::group_default);
}

const bool noware::machine::storage::sqlite::exist (const noware::var & group, const noware::var & key) const
{
	noware::tree <> expression;
	
	expression ["subject"] = "existence";
	expression ["group"] = group;
	expression ["key"] = key;
	
	return evaluate (expression, noware::machine::storage::sqlite::group_default);
}

const bool noware::machine::storage::sqlite::exist (const noware::var & key) const
{
	return exist (noware::array::sqlite::group_default, key);
}

const noware::var noware::machine::storage::sqlite::get (const noware::var & group, const noware::var & key) const
{
	noware::tree <> expression;
	
	expression ["subject"] = "obtainment";
	expression ["group"] = group;
	expression ["key"] = key;
	
	return evaluate (expression, noware::machine::storage::sqlite::group_default);
}

const noware::var noware::machine::storage::sqlite::get (const noware::var & key) const
{
	return get (noware::array::sqlite::group_default, key);
}

const bool noware::machine::storage::sqlite::remove (const noware::var & group, const noware::var & key)
{
	noware::tree <> expression;
	
	expression ["subject"] = "removal";
	expression ["group"] = group;
	expression ["key"] = key;
	
	return evaluate (expression, noware::machine::storage::sqlite::group_default);
}

const bool noware::machine::storage::sqlite::remove (const noware::var & key)
{
	return remove (noware::array::sqlite::group_default, key);
}

const bool noware::machine::storage::sqlite::set (const noware::var & group, const noware::var & key, const noware::var & value)
{
	noware::tree <> expression;
	
	expression ["subject"] = "settlement";
	expression ["group"] = group;
	expression ["key"] = key;
	expression ["value"] = value;
	
	return evaluate (expression, noware::machine::storage::sqlite::group_default);
}

const bool noware::machine::storage::sqlite::set (const noware::var & key, const noware::var & value)
{
	return set (noware::array::sqlite::group_default, key, value);
}

const bool noware::machine::storage::sqlite::clear (void)
{
	noware::tree <> expression;
	
	expression ["subject"] = "clearance";
	
	return evaluate (expression, noware::machine::storage::sqlite::group_default);
}
