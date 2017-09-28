#include ".cluster/index.c++"
#include "cluster.h++"

//static const unsigned short int LIB::machine::cluster::default_udp_port;
//static const unsigned short int LIB::machine::cluster::default_tcp_port;
const unsigned short int/*LIB::mathematics::numbers::natural*/ LIB::machine::cluster::default_udp_port = 6;
const unsigned short int/*LIB::mathematics::numbers::natural*/ LIB::machine::cluster::default_tcp_port = 7;
const /*unsigned short int*/LIB::mathematics::numbers::natural LIB::machine::cluster::default_timeout = 10;
//#include "member.c++"
/*
template <typename archive>
void LIB::machine::cluster::serialize (archive & arch, const unsigned int & version)
{
	//arch & local;
	//arch & keepalive;
	//arch & _nodes;
}
*/
LIB::machine::cluster::cluster (void)
{
	//running = true;
	//timeout = 10;
	handler = LIB::container::null;
	
	local = id_generate ();
	
	timeout = default_timeout;
	
	/*
	//mpi._connections [1].addrs.listen ["port"] = default_udp_port;
	mpi._connections [1].multicast.reliable ["port"] = default_tcp_port;
	mpi._connections [1].multicast.unreliable ["port"] = default_udp_port;
	
	mpi._connections [1].reception.reliable ["port"] = default_tcp_port;
	mpi._connections [1].reception.unreliable ["port"] = default_udp_port;
	mpi._connections [1].transmission.reliable ["port"] = default_tcp_port;
	mpi._connections [1].transmission.unreliable ["port"] = default_udp_port;
	
	//_nodes [local].addresses = LIB::network::ip::addresses ();
	*/
	
	// Set ports.
	mpi.connections () ["ip"] -> multicast.reliable ["port"] = default_tcp_port;
	mpi.connections () ["ip"] -> multicast.unreliable ["port"] = default_udp_port;
	
	mpi.connections () ["ip"] -> reception.reliable ["port"] = default_tcp_port;
	mpi.connections () ["ip"] -> reception.unreliable ["port"] = default_udp_port;
	
	mpi.connections () ["ip"] -> transmission.reliable ["port"] = default_tcp_port;
	mpi.connections () ["ip"] -> transmission.unreliable ["port"] = default_udp_port;
	
	
	mpi.receive_async (boost::bind (boost::mem_fn (&LIB::machine::cluster::receive), this, _1, _2));
	//mpi.receive_async (boost::bind (& LIB::machine::cluster::receive, this, _1, _2));
	//mpi.receive_async (boost::mem_fn (& LIB::machine::cluster::receive), this, _1, _2);
	
	mpi.listen_async (boost::bind (boost::mem_fn (&LIB::machine::cluster::receive), this, _1, _2));
	//mpi.listen_async (boost::bind (& LIB::machine::cluster::receive, this, _1, _2));
	//mpi.listen_async (boost::mem_fn (& LIB::machine::cluster::receive), this, _1, _2);
	
	//distribution = new boost::thread (boost::bind (& LIB::machine::cluster::distribute, this));
//	distribution = new boost::thread (& LIB::machine::cluster::distribute, this);
	distribution = new boost::thread (boost::bind (boost::mem_fn (&LIB::machine::cluster::distribute), this));
}

LIB::machine::cluster::~cluster (void)
{
	// running = false;
	//distribution -> interrupt ();
	//if (distribution -> joinable ())
	// 	distribution -> join ();
	delete distribution;
	
	//mpi.receive_async_stop (boost::bind (boost::mem_fn (& LIB::machine::cluster::receive), this, _1, _2));
	mpi.receive_async_stop ();
	//mpi.listen_async_stop (boost::bind (boost::mem_fn (& LIB::machine::cluster::receive), this, _1, _2));
	mpi.listen_async_stop ();
	
	
	// Tell all other machines that this machine is leaving the group.
	LIB::communication::message _message;
	
//	_message = LIB::network::_mpi::prepare (_message);
	
	_message.content ["meta"] ["origin"] ["subject"] = "presence";
	_message.content ["meta"] ["origin"] ["function"] = "declaration";
	_message.content ["meta"] ["origin"] ["value"] = false;
	
	broadcast (_message);
}

/*
const LIB::mathematics::numbers::natural LIB::machine::cluster::size (void) const
{
	return _nodes.size ();
}

const bool LIB::machine::cluster::empty (void) const
{
	return ! (size () > 0);
}
*/

const LIB::mathematics::numbers::natural LIB::machine::cluster::id_generate (void) const
{
	return LIB::tool::random ();
}

const LIB::container::NAME_A <LIB::network::node/*LIB::machine::cluster::member*/, LIB::mathematics::numbers::natural> & LIB::machine::cluster::nodes (void) const
{
	return _nodes;
}

void LIB::machine::cluster::distribute (void)
{
	LIB::communication::message _message;
	//std::string _message_serial;
	
	////_message.content ["address"] = network::ip::addresses ();
	//_message.content ["id"] = local;
	
//	_message = LIB::network::_mpi::prepare (_message);
	
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
			//_nodes [local].addresses = LIB::network::ip::addresses ();
			
	//		_message.content ["content"] ["id"]/* ["local"]*/ ["source"/*source origin*/] = local;
	//		_message.content ["content"] ["id"] ["last"/*previous intermediate last source*/] = local;
			//_message.content ["content"] ["id"] ["target"] = local;
			//_message.content ["content"] ["id"] ["next"] = _nodes.sequence_next ();
		//	_message.content ["content"] ["machines"] = _nodes;
			//_message.content ["content"] ["endpoint"] ["udp"] = mpi.addrs.listen;
			//_message.content ["content"] ["endpoint"] ["tcp"] = mpi.addrs.receive;
			
			_message.content ["meta"] ["origin"]/* ["time"]*/ ["id"] = local;
			//_message.content ["meta"] ["origin"]/* ["time"]*/ ["keepalive"] = LIB::container::NAME_V (_nodes [local].keepalive);
			//std::cout << _nodes [local].keepalive << std::endl;
			//std::cout << _message.content ["meta"] ["origin"] ["keepalive"] << std::endl;
			_message.content ["meta"] ["origin"]/* ["time"]*/ ["keepalive"] = _nodes [local].keepalive;
			
			
			//LIB::container::NAME_A <> nets = _nodes [local].networks = LIB::network::ip::networks ();
			_nodes [local].networks = LIB::network::ip::networks ();
			for (const LIB::container::NAME_A <std::string, LIB::mathematics::numbers::natural>::container & network : _nodes [local].networks)
				_message.content ["meta"] ["origin"] ["network"] [network.k] = LIB::container::NAME_V (network.v);
			
			//std::cout << _message.content ["meta"] ["origin"] ["keepalive"] << std::endl;
			
			//_message.content ["meta"] ["origin"] ["network"] = _nodes [local].networks = LIB::network::ip::networks ();
			// _message.content ["meta"] ["origin"] ["network"] = LIB::container::NAME_V (nets.serialize ());
		//	_message.content ["meta"] ["origin"] ["network"] = *(dynamic_cast <LIB::container::NTT <> *> (const_cast <LIB::container::NAME_A <std::string, LIB::mathematics::numbers::natural> *> (& (_nodes [local].networks = LIB::network::ip::networks ()))));
			//_message.content ["meta"] ["origin"] ["address"] = _nodes [local].addresses = LIB::network::ip::addresses ();
			
			// Addresses.
			//_message.content ["meta"] ["origin"] ["address"] = (LIB::container::NAME_V) (_nodes [local].addresses = LIB::network::ip::addresses ()).serialize ();
			_nodes [local].addresses = LIB::network::ip::addresses ();
			
		//	_message.content ["meta"] ["origin"] ["address"] = *(dynamic_cast <LIB::container::NTT <> *> (& (_nodes [local].addresses = LIB::network::ip::addresses ())));
			
			for (const LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_A <std::string, std::string>, noware::mathematics::numbers::natural>, std::string>::container & address : _nodes [local].addresses)
			{
				for (const LIB::container::NAME_A <LIB::container::NAME_A <std::string, std::string>, noware::mathematics::numbers::natural>::container & version : address.v)
				{
					for (const LIB::container::NAME_A <std::string, std::string>::container & attribute : version.v)
					{
						//std::cout << "\t\t" << '[' << address.k << ']' << ' ' << '[' << version.k << ']' << ' ' << '[' << attribute.k << ']' << "\t" << '[' << attribute.v << ']' << std::endl;
						_message.content ["meta"] ["origin"] ["address"] [address.k] [version.k] [attribute.k] = LIB::container::NAME_V (attribute.v);
					}
				}
			}
			
			//std::cout << _message.content ["meta"] ["origin"] ["keepalive"] << std::endl;
			//_message_serial = _message;
		//}
		
		//std::cout << "Sending 0::  Subject: [" << _message.content ["meta"] ["origin"] ["subject"] << ']'<< std::endl;
		//std::cout << "Sending 0:: Function: [" << _message.content ["meta"] ["origin"] ["function"] << ']'<< std::endl;
		//std::cout << "Sending 0::    Value: [" << _message.content ["meta"] ["origin"] ["value"] << ']'<< std::endl;
		
		//mpi.broadcast (_message, false);
		broadcast (_message);
		
		//std::cout << _message.content ["meta"] ["origin"] ["keepalive"] << std::endl;
		//timer.expires_from_now (boost::posix_time::milliseconds (keepalive));
		
		//io.run ();
		boost::this_thread::sleep (boost::posix_time::seconds (_nodes [local].keepalive));
	}
	
	//distribution = NULL;
}

//void LIB::machine::cluster::receive (LIB::container::NTT <> remote_endpoint, const LIB::communication::message & _message)
void LIB::machine::cluster::receive (LIB::container::NTT <> remote_endpoint, const std::string & serial)
{
	LIB::communication::message _message;
	
	/*
	LIB::container::NAME_A <LIB::cluster::member, LIB::mathematics::numbers::natural> __nodes;
	
	if (_message.content ["content"].exists ("machines") && __nodes.deserialize (_message.content ["content"] ["machines"]))
	{
		for (auto & _member : __nodes)
		{
			_nodes [_member.k] = _member.v;
			
			if (_nodes [_member.k].thread_timeout != NULL)
			{
				// Cancel the current thread, so that it will not remove the member.
				delete _nodes [_member.k].thread_timeout;
			}
			
			_nodes [_member.k].thread_timeout = new boost::thread (boost::bind (& LIB::cluster::member::function_timeout, & (_nodes [_member.k]), _nodes, _member.k, _nodes [_member.k].keepalive + timeout));
		}
		
		
		//boost::this_thread::sleep (boost::posix_time::seconds (timeout));
	}
	*/
	
	/*
	// Self message.
	if (remote_endpoint.is_group () && remote_endpoint.exists ("address") && _nodes [local].addresses.exists_value (remote_endpoint ["address"]))
	{
		// Do not process.
		return;
	}
	*/
	
	std::cout << "SERIAL[" << serial << ']' << std::endl;
	if (_message.deserialize (serial))
	{
		std::cout << "Deserialization Succeeded" << std::endl;
		
		if (_message.content.exists ("meta"))
		{
			std::cout << "meta" << std::endl;
			
			if (_message.content ["meta"].exists ("origin"))
			{
				std::cout << "[meta].origin" << std::endl;
				
				if (/*_message.content ["meta"].exists ("origin") && */_message.content ["meta"] ["origin"].exists ("id"))
				{
					std::cout << "[meta] [origin].id" << std::endl;
					
					std::cout << "    Local ID: [" << local << ']'<< std::endl;
					std::cout << " Received ID: [" << _message.content ["meta"] ["origin"] ["id"] << ']'<< std::endl;
					std::cout << " Previous ID: [" << _message.content ["meta"] ["previous"] ["id"] << ']'<< std::endl;
					
					std::cout << "  Subject: [" << _message.content ["meta"] ["origin"] ["subject"] << ']'<< std::endl;
					std::cout << " Function: [" << _message.content ["meta"] ["origin"] ["function"] << ']'<< std::endl;
					std::cout << "    Value: [" << _message.content ["meta"] ["origin"] ["value"] << ']'<< std::endl;
					
					//_message.content ["meta"] ["origin"] ["id"] = local + 1000;
					std::cout << " Received ID (again): [" << _message.content ["meta"] ["origin"] ["id"] << ']'<< std::endl;
					if (_message.content ["meta"] ["origin"] ["id"] != local)
					{
						//// Customization should be done here?
						std::cout << "[meta] [origin] [id] != local" << std::endl;
						
						if (_message.content ["meta"] ["origin"].exists ("subject") && _message.content ["meta"] ["origin"].exists ("function"))
						{
							std::cout << "[meta] [origin] [id].subject && .function" << std::endl;
							
							if (_message.content ["meta"] ["origin"] ["subject"] == "presence" && _message.content ["meta"] ["origin"] ["function"] == "declaration" && _message.content ["meta"] ["origin"].exists ("value"))
							{
								std::cout << "[meta] [origin] [subject] == presence && [meta] [origin] [function] == declaration && [meta] [origin].value" << std::endl;
								
								//if (_message.content.exists ("content"))
								//{
									//if (/*_message.content ["meta"].exists ("origin") && */_message.content ["meta"] ["origin"].exists ("id"))
									//{
										if ((LIB::container::NAME_V) (_message.content ["meta"] ["origin"] ["value"]))
										{
											if (_nodes [(LIB::container::NAME_V) _message.content ["meta"] ["origin"] ["id"]].thread_timeout != NULL)
											{
												// Cancel the current thread, so that it will not remove the member.
												delete _nodes [(LIB::container::NAME_V) _message.content ["meta"] ["origin"] ["id"]].thread_timeout;
											}
											
											
											// Set the node's attributes.
											
											// Keepalive.
											_nodes [(LIB::container::NAME_V) _message.content ["meta"] ["origin"] ["id"]].keepalive = _message.content ["meta"] ["origin"] ["keepalive"].get_value ();
											
											// Addresses.
											//for (const LIB::container::NTT <>::container::grp & address : _message.content ["meta"] ["origin"] ["address"])
											for (
													LIB::container::NTT <>::iterator it_address_current = _message.content ["meta"] ["origin"] ["address"].begin (),
														it_address_end = _message.content ["meta"] ["origin"] ["address"].end ();
													it_address_current != it_address_end;
													++ it_address_current
												)
											{
												//for (const LIB::container::NTT <>::container::grp & version : *(address.v))
												for (
														LIB::container::NTT <>::iterator it_version_current = (*it_address_current).begin (),
															it_version_end = (*it_address_current).end ();
														it_version_current != it_version_end;
														++ it_version_current
													)
												{
													//for (const LIB::container::NTT <>::container::grp & attribute : *(version.v))
													for (
															LIB::container::NTT <>::iterator it_attribute_current = (*it_version_current).begin (),
																it_attribute_end = (*it_version_current).end ();
															it_attribute_current != it_attribute_end;
															++ it_attribute_current
														)
													{
														_nodes [(LIB::container::NAME_V) _message.content ["meta"] ["origin"] ["id"]].addresses [it_address_current.k ()] [it_version_current.k ()] [it_attribute_current.k ()] = (*it_attribute_current).get_value ().to_string ();
													}
												}
											}
											
											// Networks.
											//for (const LIB::container::NTT <> & network : _message.content ["meta"] ["origin"] ["network"])
											for (
													LIB::container::NTT <>::iterator it_current = _message.content ["meta"] ["origin"] ["network"].begin (),
														it_end = _message.content ["meta"] ["origin"] ["network"].end ();
													it_current != it_end;
													++ it_current
												)
												_nodes [(LIB::container::NAME_V) _message.content ["meta"] ["origin"] ["id"]].networks [it_current.k ()] = (*it_current).get_value ().to_string ();
											
											
											std::cout << "Setting node thread." << std::endl;
											
											//_nodes [(LIB::container::NAME_V) _message.content ["content"] ["origin"] ["id"]].thread_timeout = new boost::thread (boost::bind (& LIB::network::node::function_timeout/*, & (_nodes [_message.content ["content"] ["id"] ["origin"]])*/, _nodes, (LIB::container::NAME_V) _message.content ["content"] ["origin"] ["id"], _nodes [(LIB::container::NAME_V) _message.content ["content"] ["origin"] ["id"]].keepalive + timeout));
											_nodes [(LIB::container::NAME_V) _message.content ["meta"] ["origin"] ["id"]].thread_timeout = new boost::thread (boost::bind (boost::mem_fn (& LIB::network::node::function_timeout), & (_nodes [(LIB::container::NAME_V) _message.content ["meta"] ["origin"] ["id"]]), _nodes, LIB::mathematics::numbers::natural (LIB::container::NAME_V (_message.content ["meta"] ["origin"] ["id"]).to_string ().c_str ()), _nodes [(LIB::container::NAME_V) _message.content ["meta"] ["origin"] ["id"]].keepalive + timeout));
										}
										else
										{
											/*
											if (_nodes [_message.content ["content"] ["id"] ["origin"]].thread_timeout != NULL)
											{
												// Cancel the current thread, so that it will not remove the member.
												delete _nodes [_message.content ["content"] ["id"] ["origin"]].thread_timeout;
												_nodes [_message.content ["content"] ["id"] ["origin"]].thread_timeout = NULL;
											}
											*/
											
											
											std::cout << "Unsetting node thread." << std::endl;
											
											// Done within node::~node().
											/*if (_nodes [(LIB::container::NAME_V) _message.content ["meta"] ["origin"] ["id"]].thread_timeout != NULL)
											{
												// Cancel the current thread, so that it will not remove the member.
												delete _nodes [(LIB::container::NAME_V) _message.content ["meta"] ["origin"] ["id"]].thread_timeout;
											}*/
											_nodes.unset ((LIB::container::NAME_V) _message.content ["meta"] ["origin"] ["id"]);
											
											//// TODO: Pass the message to everyone else who is not connected (did not receive).
											//broadcast (_message, remote_endpoint);
										}
									//}
								//}
							}
							else
							{
								std::cout << "[meta] [origin] [subject] != presence || [meta] [origin] [function] != declaration || ![meta] [origin].value" << std::endl;
							}
						}
						else
						{
							std::cout << "![meta] [origin] [id].subject || !.function" << std::endl;
						}
						
						broadcast (_message, remote_endpoint);
						
						if (handler != LIB::container::null)
							(*handler) (_message, remote_endpoint);
					}
					else
					{
						std::cout << "[meta] [origin] [id] == local" << std::endl;
					}
					
					//broadcast (_message, remote_endpoint);
				}
				else
				{
					std::cout << "![meta] [origin].id" << std::endl;
				}
			}
			else
			{
				std::cout << "![meta].origin" << std::endl;
			}
		}
		else
		{
			std::cout << "!meta" << std::endl;
		}
	}
	else
	{
		std::cout << "Deserialization Failed" << std::endl;
	}
	
	//if (handler != LIB::container::null)
	//	(*handler) (remote_endpoint, serial);
}

//const bool receive_async (const boost::function <void (const LIB::container::NTT <> &/* remote_endpoint*/, const std::string &/* message*/)> & _handler)
const bool receive_async (const boost::function <void (const LIB::communication::message &/* message*/, const LIB::container::NTT <> &/* remote_endpoint*/)> & _handler)
{
	handler = &_handler;
	
	return true;
}

const bool receive_async_stop (void)
{
	if (handler == LIB::container::null)
		return true;
	
	handler = LIB::container::null;
	
	return true;
}

//const bool LIB::machine::cluster::broadcast (const LIB::communication::message & _message) const
const bool LIB::machine::cluster::broadcast (LIB::communication::message _message) const
{
	const LIB::container::NTT <> remote_endpoint;
	//LIB::container::NTT <> remote_endpoint;
	
	if (_message.content.exists ("meta"))
	{
		std::cout << "Exists::meta:" << true << std::endl;
		
		if (_message.content ["meta"].exists ("origin"))
		{
			std::cout << "Exists::meta.origin:" << true << std::endl;
			
			if (_message.content ["meta"] ["origin"].exists ("subject"))
			{
				std::cout << "Exists::meta.origin.subject:" << true << std::endl;
			}
		}
	}
	std::cout << "Sending 1::  Subject: [" << _message.content ["meta"] ["origin"] ["subject"] << ']'<< std::endl;
	std::cout << "Sending 1:: Function: [" << _message.content ["meta"] ["origin"] ["function"] << ']'<< std::endl;
	std::cout << "Sending 1::    Value: [" << _message.content ["meta"] ["origin"] ["value"] << ']'<< std::endl;
	
	return broadcast (_message, remote_endpoint);
}

const bool LIB::machine::cluster::broadcast (LIB::communication::message _message, const LIB::container::NTT <> & remote_endpoint) const
//const bool LIB::machine::cluster::broadcast (LIB::communication::message _message, LIB::container::NTT <> remote_endpoint) const
{
	//std::string received_network;
	
	LIB::mathematics::numbers::natural id_previous;
	//LIB::container::NAME_A <std::string, LIB::mathematics::numbers::natural> networks_previous;
	//LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural>, std::string> addresses_origin;
	bool id_previous_existed = false;
	// bool networks_previous_existed = false;
	//bool addresses_origin_existed = false;
	
	
	if (/*! _message.content ["meta"].exists ("origin") || */_message.content ["meta"] ["previous"].exists ("id"))
	{
		id_previous = LIB::mathematics::numbers::natural (std::string (LIB::container::NAME_V (_message.content ["meta"] ["previous"] ["id"])).c_str ());
		id_previous_existed = true;
	}
	
	std::cout << " Sending::   Local ID: [" << local << ']'<< std::endl;
	//std::cout << " Sending::PRE::  Origin ID: [" << _message.content ["meta"] ["origin"] ["id"] << ']'<< std::endl;
	//std::cout << " Sending::PRE::Previous ID: [" << _message.content ["meta"] ["previous"] ["id"] << ']'<< std::endl;
	
	//if (/*! _message.content ["meta"].exists ("origin") || */_message.content ["meta"] ["previous"].exists ("network"))
	//{
	//	//networks_previous = _message.content ["meta"] ["previous"] ["network"];
	//	networks_previous_existed = true;
	//}
	
	//if (/*! _message.content ["meta"].exists ("origin") || */_message.content ["meta"] ["origin"].exists ("address"))
	//{
	//	addresses_origin = _message.content ["meta"] ["origin"] ["address"];
	//	addresses_origin_existed = true;
	//}
	
	
	
	//_message.content ["meta"] ["redistribution"]/* ["re"]*/ = true;
	_message.content ["meta"] ["previous"] ["id"] = local;
	//_message.content ["meta"] ["previous"] ["network"] = LIB::container::NAME_V (_nodes [local].networks);
	for (const LIB::container::NAME_A <std::string, LIB::mathematics::numbers::natural>::container & network : _nodes [local].networks)
		_message.content ["meta"] ["previous"] ["network"] [network.k] = LIB::container::NAME_V (network.v);
	
	if (/*! _message.content ["meta"].exists ("origin") || */! _message.content ["meta"] ["origin"].exists ("id"))
		_message.content ["meta"] ["origin"] ["id"] = _message.content ["meta"] ["previous"] ["id"];
	
	if (/*! _message.content ["meta"].exists ("origin") || */! _message.content ["meta"] ["origin"].exists ("network"))
		_message.content ["meta"] ["origin"] ["network"] = _message.content ["meta"] ["previous"] ["network"];
	
	if (/*! _message.content ["meta"].exists ("origin") || */! _message.content ["meta"] ["origin"].exists ("address"))
		//_message.content ["meta"] ["origin"] ["address"] = (LIB::container::NAME_V) _nodes [local].addresses.serialize ();
		for (const noware::container::array <noware::container::array <noware::container::array <std::string, std::string>, noware::mathematics::numbers::natural>, std::string>::container & address : _nodes [local].addresses)
		{
			for (const noware::container::array <noware::container::array <std::string, std::string>, noware::mathematics::numbers::natural>::container & version : address.v)
			{
				for (const noware::container::array <std::string, std::string>::container & attribute : version.v)
				{
					//std::cout << "\t\t" << '[' << address.k << ']' << ' ' << '[' << version.k << ']' << ' ' << '[' << attribute.k << ']' << "\t" << '[' << attribute.v << ']' << std::endl;
					_message.content ["meta"] ["origin"] ["address"] [address.k] [version.k] [attribute.k] = LIB::container::NAME_V (attribute.v);
				}
			}
		}
	
	
	std::cout << " Sending::POST::  Origin ID: [" << _message.content ["meta"] ["origin"] ["id"] << ']'<< std::endl;
	std::cout << " Sending::POST::Previous ID: [" << _message.content ["meta"] ["previous"] ["id"] << ']'<< std::endl;
	
	std::cout << "Sending::  Subject: [" << _message.content ["meta"] ["origin"] ["subject"] << ']'<< std::endl;
	std::cout << "Sending:: Function: [" << _message.content ["meta"] ["origin"] ["function"] << ']'<< std::endl;
	std::cout << "Sending::    Value: [" << _message.content ["meta"] ["origin"] ["value"] << ']'<< std::endl;
	
	// If any *_previous_existed == false, then that should (normally) mean that this machine is the origin.
	
	if (id_previous_existed)
	// There was a previous node which transmitted.
	{
		LIB::container::NTT <> addresses;
		//LIB::container::NAME_A <std::string, LIB::mathematics::numbers::natural> networks;	// Try to use this one!
		LIB::container::NAME_A <> networks;														// Temporary work-around.
		
		networks
			=																		// Value
				// The networks which this machine is connected to.
				//_message.content ["meta"] ["previous"] ["network"]
				//networks_previous
				_nodes [local].networks
		;
		//}
		
		if (/*addresses_origin_existed && */remote_endpoint.is_group () && remote_endpoint.exists ("address"))
		{
			networks
				-=
					// Network which the message was received on.
					network_received (LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural>, std::string> (/*addresses_origin*/_message.content ["meta"] ["origin"] ["address"].serialize ()), remote_endpoint ["address"].serialize ())
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
					//LIB::container::NAME_A <> (_message.content ["meta"] ["origin"] ["network"]) - networks_disconnected (id_previous)
					LIB::container::NAME_A <> (_message.content ["meta"] ["origin"] ["network"]) - LIB::container::NAME_A <> (networks_disconnected (id_previous))
					//LIB::container::NAME_A <> (_message.content ["meta"] ["origin"] ["network"]) - *(dynamic_cast <LIB::container::NAME_A <> *> (const_cast <LIB::container::NAME_A <std::string, LIB::mathematics::numbers::natural> *> (& networks_disconnected (id_previous))))
			;
		}
		
		
		addresses ["addresses"] = LIB::container::NAME_V (networks.serialize ());
		//addresses ["network"] = networks;
		
		std::cout << "::Networks:" << std::endl;
		for (const LIB::container::NAME_A <>::container & network : networks)
			std::cout << "\t" << '[' << network.k << ']' << ' ' << '[' << network.v << ']' << std::endl;
		
		std::cout << "Broadcast :: Proxy" << std::endl;
		
		//return mpi.broadcast (_message, addresses, false);
		if (mpi.broadcast (_message, addresses, false))
		{
			std::cout << "Broadcast :: Success" << std::endl;
			return true;
		}
		else
		{
			std::cout << "Broadcast :: Failure" << std::endl;
			return false;
		}
	}
	else
	//if (networks.empty ())	// ?
	// This machine is the original transmitter.
	{
		std::cout << "Broadcast :: Origin" << std::endl;
		//LIB::container::NTT <> addr;
		//addr ["address"]
		
		std::cout << "SERIAL(DEPARTING)[" << _message.serialize () << ']';
		//return mpi.broadcast (_message, false);
		if (mpi.broadcast (_message, false))
		{
			std::cout << "Broadcast :: Success" << std::endl;
			return true;
		}
		else
		{
			std::cout << "Broadcast :: Failure" << std::endl;
			return false;
		}
	}
	/*else
	{
		LIB::container::NTT <> addresses;
		
		addresses ["addresses"] = networks;
		
		
		return mpi.broadcast (_message, addresses, false);
	}*/
}

const std::string LIB::machine::cluster::network_received (const LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural>, std::string> & addresses, const std::string & address)
{
	for (const LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural>, std::string>::container & devices : addresses)
	{
		for (const LIB::container::NAME_A <LIB::container::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural>::container & version : devices.v)
		{
			if (version.v.exists ("address") && version.v ["address"] == address && version.v.exists ("network"))
			{
				return version.v ["network"];
			}
		}
	}
	
	return "";
}

const LIB::container::NAME_A <std::string, LIB::mathematics::numbers::natural> LIB::machine::cluster::networks_disconnected (const LIB::mathematics::numbers::natural & member) const
{
	LIB::container::NAME_A <std::string, LIB::mathematics::numbers::natural> networks;
	bool network_found;
	
	for (const LIB::container::NAME_A <std::string, LIB::mathematics::numbers::natural>::container & network_local : _nodes [local].networks)
	{
		for (const LIB::container::NAME_A <std::string, LIB::mathematics::numbers::natural>::container & network_remote : _nodes [member].networks)
		{
			if (network_local.v == network_remote.v)
			{
				network_found = false;
				
				//for (const LIB::container::NAME_A <LIB::container::NAME_A <std::string, std::string>, LIB::mathematics::numbers::natural>::container & path_remote : _nodes [member].paths.all ())
				for (const LIB::container::NAME_A <LIB::container::NAME_A <LIB::container::NAME_V, LIB::container::NAME_V>, LIB::container::NAME_V>::container & path_remote : _nodes [member].paths.all ())
				{
					//if (path_remote.v.exists ("network") && path_remote.v ["network"] == network_local.v)
					if (/*path_remote.v.exists (1) && */path_remote.v [1] == network_local.v)
					{
						network_found = true;
						
						break;
					}
				}
				
				if ( ! /* we are interested if the network is not connected */ network_found)
					networks += network_local.v;
			}
		}
	}
	
	return networks;
}
