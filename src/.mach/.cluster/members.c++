#include "members.h++"

//static const unsigned short int LIB::cluster::members::default_udp_port;
//static const unsigned short int LIB::cluster::members::default_tcp_port;
const /*unsigned short int*/LIB::mathematics::numbers::natural LIB::cluster::members::default_udp_port = 6;
const /*unsigned short int*/LIB::mathematics::numbers::natural LIB::cluster::members::default_tcp_port = 7;
const LIB::mathematics::numbers::natural LIB::cluster::members::default_timeout = 10;
//#include "member.c++"
/*
template <typename archive>
void LIB::cluster::members::serialize (archive & arch, const unsigned int & version)
{
	//arch & id_local;
	//arch & keepalive;
	//arch & _members;
}
*/
LIB::cluster::members::members (void)
{
	//timeout = 10;
	id_local = id_generate ();
	
	timeout = default_timeout;
	
	//mpi._connections [1].addrs.listen ["port"] = default_udp_port;
	mpi._connections [1].multicast.reliable ["port"] = default_tcp_port;
	mpi._connections [1].multicast.unreliable ["port"] = default_udp_port;
	
	mpi._connections [1].reception.reliable ["port"] = default_tcp_port;
	mpi._connections [1].reception.unreliable ["port"] = default_udp_port;
	mpi._connections [1].transmission.reliable ["port"] = default_tcp_port;
	mpi._connections [1].transmission.unreliable ["port"] = default_udp_port;
	
	//_members [id_local].addresses = LIB::network::ip::addresses ();
	
	mpi.receive_async (boost::bind (boost::mem_fn (& LIB::::cluster::members::receive), this, _1, _2));
	mpi.listen_async (boost::bind (boost::mem_fn (& LIB::::cluster::members::receive), this, _1, _2));
	
	distribution = new boost::thread (boost::bind (& LIB::cluster::members::distribute, this));
}

LIB::cluster::members::~members (void)
{
	delete distribution;
	
	mpi.receive_async_stop (boost::bind (boost::mem_fn (& LIB::::cluster::members::receive), this, _1, _2));
	mpi.listen_async_stop (boost::bind (boost::mem_fn (& LIB::::cluster::members::receive), this, _1, _2));
	
	
	// Tell all other machines that this machine is leaving the group.
	LIB::communication::message _message;
	
	_message = LIB::network::_mpi::prepare (_message);
	
	_message.content ["meta"] ["origin"] ["subject"] = "presence";
	_message.content ["meta"] ["origin"] ["function"] = "declaration";
	_message.content ["meta"] ["origin"] ["value"] = false;
	
	broadcast (_message);
}

const LIB::mathematics::numbers::natural LIB::cluster::members::size (void) const
{
	return _members.size ();
}

const bool LIB::cluster::members::empty (void) const
{
	return ! (size () > 0);
}

const LIB::mathematics::numbers::natural LIB::cluster::members::id_generate (void) const
{
	return LIB::tools::random ();
}

const LIB::containers::NAME_A <LIB::cluster::member, LIB::mathemathics::numbers::natural> & LIB::cluster::members::list (void) const
{
	return _members;
}

void LIB::cluster::members::distribute (void)
{
	LIB::communication::message _message;
	//std::string _message_serial;
	
	////_message.content ["addresses"] = network::ip::addresses ();
	//_message.content ["id"] = id_local;
	
	_message = LIB::network::_mpi::prepare (_message);
	
	_message.content ["meta"] ["origin"] /*["action"]*/["subject"] = "presence";
	_message.content ["meta"] ["origin"] ["function"] = "declaration";
	_message.content ["meta"] ["origin"] ["value"] = true;
	//_message.content ["endpoint"] ["port"] ["tcp"] = static_cast <LIB::network::ip::mpi> (mpi -> connections ()).;
	//_message.content ["endpoint"] ["udp"] = mpi -> addrs.listen;
	//_message.content ["endpoint"] ["tcp"] = mpi -> addrs.receive;
	
	//_message.content ["id"] = * _local;
	//_message.content ["id:next"] = nodes.sequence_next ();
	//_message.content ["machines"] = nodes;
	
	//LIB::NAME_V * __id = & (_message.content ["id"]);
	
	// _message_serial = _message;
	
	//_message.content.clear ();
	
	//io.reset ();
	
	while (true)
	{
		//if (/*_local != NULL && */(* __id) != (* _local))
		//{
			//(* __id) = (* _local);
			//_members [id_local].addresses = LIB::network::ip::addresses ();
			
	//		_message.content ["content"] ["id"]/* ["local"]*/ ["source"/*source origin*/] = id_local;
	//		_message.content ["content"] ["id"] ["last"/*previous intermediate last source*/] = id_local;
			//_message.content ["content"] ["id"] ["target"] = id_local;
			//_message.content ["content"] ["id"] ["next"] = _members.sequence_next ();
		//	_message.content ["content"] ["machines"] = _members;
			//_message.content ["content"] ["endpoint"] ["udp"] = mpi.addrs.listen;
			//_message.content ["content"] ["endpoint"] ["tcp"] = mpi.addrs.receive;
			_message.content ["meta"] ["origin"]/* ["time"]*/ ["keepalive"] = _members [id_local].keepalive;
			_message.content ["meta"] ["origin"] ["networks"] = _members [id_local].networks = LIB::network::ip::networks ();
			_message.content ["meta"] ["origin"] ["addresses"] = _members [id_local].addresses = LIB::network::ip::addresses ();
			
			//_message_serial = _message;
		//}
		
		//mpi.broadcast (_message, false);
		broadcast (_message);
		
		//timer.expires_from_now (boost::posix_time::milliseconds (keepalive));
		
		//io.run ();
		boost::this_thread::sleep (boost::posix_time::seconds (_members [id_local].keepalive));
	}
	
	//distribution = NULL;
}

void LIB::cluster::members::receive (LIB::containers::NTT <> remote_endpoint, const LIB::communication::message & _message)
{
	/*
	LIB::containers::NAME_A <LIB::cluster::member, LIB::mathemathics::numbers::natural> __members;
	
	if (_message.content ["content"].exists ("machines") && __members.deserialize (_message.content ["content"] ["machines"]))
	{
		for (auto & _member : __members)
		{
			_members [_member.k] = _member.v;
			
			if (_members [_member.k].thread_timeout != NULL)
			{
				// Cancel the current thread, so that it will not remove the member.
				delete _members [_member.k].thread_timeout;
			}
			
			_members [_member.k].thread_timeout = new boost::thread (boost::bind (& LIB::cluster::member::function_timeout, & (_members [_member.k]), _members, _member.k, _members [_member.k].keepalive + timeout));
		}
		
		
		//boost::this_thread::sleep (boost::posix_time::seconds (timeout));
	}
	*/
	
	/*
	// Self message.
	if (remote_endpoint.is_group () && remote_endpoint.exists ("address") && _members [id_local].addresses.exists_value (remote_endpoint ["address"]))
	{
		// Do not process.
		return;
	}
	*/
	
	if (_message.content.exists ("meta"))
	{
		if (_message.content ["meta"].exists ("origin"))
		{
			if (/*_message.content ["meta"].exists ("origin") && */_message.content ["meta"] ["origin"].exists ("id"))
			{
				if (_message.content ["meta"] ["origin"].exists ("subject") && _message.content ["meta"] ["origin"].exists ("function"))
				{
					if (_message.content ["meta"] ["origin"] ["subject"] == "presence" && _message.content ["meta"] ["origin"] ["function"] == "declaration" && _message.content ["meta"] ["origin"].exists ("value"))
					{
						//if (_message.content.exists ("content"))
						//{
							//if (/*_message.content ["meta"].exists ("origin") && */_message.content ["meta"] ["origin"].exists ("id"))
							//{
								if (_message.content ["meta"] ["origin"] ["value"])
								{
									if (_members [_message.content ["content"] ["origin"] ["id"]].thread_timeout != NULL)
									{
										// Cancel the current thread, so that it will not remove the member.
										delete _members [_message.content ["content"] ["origin"] ["id"]].thread_timeout;
									}
									
									_members [_message.content ["content"] ["origin"] ["id"]].thread_timeout = new boost::thread (boost::bind (& LIB::cluster::member::function_timeout/*, & (_members [_message.content ["content"] ["id"] ["origin"]])*/, _members, _message.content ["content"] ["origin"] ["id"], _members [_message.content ["content"] ["origin"] ["id"]].keepalive + timeout));
								}
								else
								{
									/*
									if (_members [_message.content ["content"] ["id"] ["origin"]].thread_timeout != NULL)
									{
										// Cancel the current thread, so that it will not remove the member.
										delete _members [_message.content ["content"] ["id"] ["origin"]].thread_timeout;
										_members [_message.content ["content"] ["id"] ["origin"]].thread_timeout = NULL;
									}
									*/
									
									
									_members.unset (_message.content ["content"] ["origin"] ["id"]);
									
									//// TODO: Pass the message to everyone else who is not connected (did not receive).
									//broadcast (_message, remote_endpoint);
								}
							//}
						//}
					}
				}
				
				broadcast (_message, remote_endpoint);
			}
		}
	}
}

const bool LIB::cluster::members::broadcast (const LIB::communication::message & _message) const
{
	const LIB::containers::NTT <> remote_endpoint;
	
	return broadcast (_message, remote_endpoint);
}

const bool LIB::cluster::members::broadcast (LIB::communication::message _message, const LIB::containers::NTT <> & remote_endpoint) const
{
	//std::string received_network;
	
	LIB::mathematics::numbers::natural id_previous;
	//LIB::containers::NAME_A <std::string, LIB::mathematics::numbers::natural> networks_previous;
	//LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural>, std::string> addresses_origin;
	bool id_previous_existed = false;
	// bool networks_previous_existed = false;
	//bool addresses_origin_existed = false;
	
	
	
	if (/*! _message.content ["meta"].exists ("origin") || */_message.content ["meta"] ["previous"].exists ("id"))
	{
		id_previous = _message.content ["meta"] ["previous"] ["id"];
		id_previous_existed = true;
	}
	
	//if (/*! _message.content ["meta"].exists ("origin") || */_message.content ["meta"] ["previous"].exists ("networks"))
	//{
	//	//networks_previous = _message.content ["meta"] ["previous"] ["networks"];
	//	networks_previous_existed = true;
	//}
	
	//if (/*! _message.content ["meta"].exists ("origin") || */_message.content ["meta"] ["origin"].exists ("addresses"))
	//{
	//	addresses_origin = _message.content ["meta"] ["origin"] ["addresses"];
	//	addresses_origin_existed = true;
	//}
	
	
	
	//_message.content ["meta"] ["redistribution"]/* ["re"]*/ = true;
	_message.content ["meta"] ["previous"] ["id"] = id_local;
	_message.content ["meta"] ["previous"] ["networks"] = _members [id_local].networks;
	
	if (/*! _message.content ["meta"].exists ("origin") || */! _message.content ["meta"] ["origin"].exists ("id"))
		_message.content ["meta"] ["origin"] ["id"] = _message.content ["meta"] ["previous"] ["id"];
	
	if (/*! _message.content ["meta"].exists ("origin") || */! _message.content ["meta"] ["origin"].exists ("networks"))
		_message.content ["meta"] ["origin"] ["networks"] = _message.content ["meta"] ["previous"] ["networks"];
	
	if (/*! _message.content ["meta"].exists ("origin") || */! _message.content ["meta"] ["origin"].exists ("addresses"))
		_message.content ["meta"] ["origin"] ["addresses"] = _members [id_local].addresses;
	
	
	
	// If any *_previous_existed == false, then that should (normally) mean that this machine is the origin.
	
	if (id_previous_existed)
	// There was a previous node which transmitted.
	{
		LIB::containers::NTT <> addresses;
		LIB::containers::NAME_A <std::string, LIB::mathematics::numbers::natural> networks;
		
		networks
			=																		// Value
				// The networks which this machine is connected to.
				//_message.content ["meta"] ["previous"] ["networks"]
				//networks_previous
				_members [id_local].networks
		;
		//}
		
		if (/*addresses_origin_existed && */remote_endpoint.is_group () && remote_endpoint.exists ("address"))
		{
			networks
				-=
					// Network which the message was received on.
					network_received (/*addresses_origin*/_message.content ["meta"] ["origin"] ["addresses"], remote_endpoint ["address"])
			;
		}

		// If this machine is a neighbour of the original transmitter.
		if (/*networks_previous_existed && *//*id_previous_existed && */_message.content ["meta"] ["origin"] ["id"] == id_previous)
		{
			//// If we are here, then that means that this machine is a neighbour of the original transmitter.

			networks
				-=
					// The networks which the source (original transmitter) is connected to.
					//original_networks
					_message.content ["meta"] ["origin"] ["networks"] - networks_disconnected (id_previous)
			;
		}
		
		
		addresses ["addresses"] = networks;
		
		return mpi.broadcast (_message, addresses, false);
	}
	else
	//if (networks.empty ())
	{
		// This machine is the original transmitter.
		
		return mpi.broadcast (_message, false);
	}
	/*else
	{
		LIB::containers::NTT <> addresses;
		
		addresses ["addresses"] = networks;
		
		
		return mpi.broadcast (_message, addresses, false);
	}*/
}

const std::string LIB::cluster::members::networks_received (const LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural>, std::string> & addresses, const std::string & address)
{
	for (const LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural>, std::string>::container & devices : addresses)
	{
		for (const LIB::containers::NAME_A <LIB::containers::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural>::container & version : devices.v)
		{
			if (version.v.exists ("address") && version.v ["address"] == address && version.v.exists ("network"))
			{
				return version.v ["network"];
			}
		}
	}
	
	return "";
}

const LIB::containers::NAME_A <std::string, LIB::mathematics::numbers::natural> LIB::cluster::members::networks_disconnected (const LIB::mathematics::numbers::natural & member) const
{
	LIB::containers::NAME_A <std::string, LIB::mathematics::numbers::natural> networks;
	bool network_found;
	
	for (const LIB::containers::NAME_A <std::string, LIB::mathematics::numbers::natural>::container & network_local : _members [id_local].networks)
	{
		for (const LIB::containers::NAME_A <std::string, LIB::mathematics::numbers::natural>::container & network_remote : _members [member].networks)
		{
			if (network_local.v == network_remote.v)
			{
				network_found = false;
				for (const LIB::containers::NAME_A <LIB::containers::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural>::container & path_remote : _members [member].paths)
				{
					if (path_remote.v.exists ("network") && path_remote.v ["network"] == network_local.v)
					{
						network_found = true;
						
						break;
					}
				}
				
				if (!/*we are interested if the network is disconnected*/ network_found)
					networks += network_local.v;
			}
		}
	}
	
	return networks;
}
