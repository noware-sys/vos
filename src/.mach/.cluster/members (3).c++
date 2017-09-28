#include "members.h++"

const static unsigned short int LIB::cluster::members::default_udp_port;
const static unsigned short int LIB::cluster::members::default_tcp_port;

template <typename archive>
void LIB::cluster::members::serialize (archive & arch, const unsigned int & version)
{
	//arch & local;
	//arch & keepalive;
	//arch & _members;
}

LIB::cluster::members::members (void)
{
	timeout = 10;
	local = generate_id ();
	
	mpi._connections [1].addrs.listen ["port"] = default_udp_port;
	mpi._connections [1].addrs.broadcast ["port"] = default_udp_port;
	
	mpi._connections [1].addrs.reception ["port"] = default_tcp_port;
	mpi._connections [1].addrs.transmission ["port"] = default_tcp_port;
	
	//__members [local].addresses = LIB::network::ip::addresses ();
	
	distribution = new boost::thread (boost::bind (& LIB::cluster::members::distribute, this));
}

LIB::cluster::members::~members (void)
{
	delete distribution;
}

const LIB::mathematics::numbers::natural LIB::cluster::members::size (void) const
{
	return __members.size ();
}

const bool LIB::cluster::members::empty (void) const
{
	return size () <= 0;
}

const LIB::mathematics::numbers::natural LIB::cluster::members::generate_id (void) const
{
	return 1;
}

const LIB::NAME_A <LIB::cluster::member, LIB::mathemathics::numbers::natural> & LIB::cluster::members::list (void) const
{
	return __members;
}

void LIB::cluster::members::distribute (void)
{
	LIB::communication::message _message;
	//std::string _message_serial;
	
	////_message.content ["addresses"] = network::ip::addresses ();
	//_message.content ["id"] = local;
	
	/*_message = */prepare (_message);
	
	_message.content ["meta"] /*["action"]*/["subject"] = "presence";
	_message.content ["meta"] ["function"] = "declaration";
	_message.content ["meta"] ["value"] = true;
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
			//_members [local].addresses = LIB::network::ip::addresses ();
			
			_message.content ["content"] ["id"] ["local"] = local;
			//_message.content ["content"] ["id"] ["next"] = _members.sequence_next ();
			_message.content ["content"] ["machines"] = __members;
			//_message.content ["content"] ["endpoint"] ["udp"] = mpi.addrs.listen;
			//_message.content ["content"] ["endpoint"] ["tcp"] = mpi.addrs.receive;
			//_message.content ["content"] ["time"] ["keepalive"] = _members [local].keepalive;
			
			//_message_serial = _message;
		//}
		
		mpi.broadcast (_message);
		
		//timer.expires_from_now (boost::posix_time::milliseconds (keepalive));
		
		//io.run ();
		boost::this_thread::sleep (boost::posix_time::seconds (__members [local].keepalive));
	}
	
	//distribution = NULL;
}

void LIB::cluster::members::manage (LIB::entity <> remote_endpoint, const LIB::communication::message & _message)
{
	LIB::NAME_A <LIB::cluster::member, LIB::mathemathics::numbers::natural> _members;
	
	if (_message.content ["content"].exists ("machines") && _members.deserialize (_message.content ["content"] ["machines"]))
	{
		for (auto & _member : _members)
		{
			__members [_member.k] = _member.v;
			
			if (__members [_member.k].thread_timeout != NULL)
			{
				// Cancel the current thread, so that it will not remove the 
				delete __members [_member.k].thread_timeout;
			}
			
			__members [_member.k].thread_timeout = new boost::thread (boost::bind (& LIB::cluster::member::function_timeout, & (__members [_member.k]), __members, _member.k, __members [_member.k].keepalive + timeout));
		}
		
		
		//boost::this_thread::sleep (boost::posix_time::seconds (timeout));
	}
}

const bool LIB::cluster::members::broadcast (const LIB::communication::message & _message) const
{
	return false;
}
