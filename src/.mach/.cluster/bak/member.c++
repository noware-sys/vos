#include "member.h++"

const LIB::mathematics::numbers::natural LIB::cluster::member::default_keepalive = 20;

LIB::cluster::member::member (void)
{
	//available = false;
	keepalive = default_keepalive;
	thread_timeout = NULL;
}

LIB::cluster::member::member (const LIB::cluster::member & other)
{
	operator = (other);
}

LIB::cluster::member::~member (void)
{
	if (thread_timeout != NULL)
	{
		delete thread_timeout;
		thread_timeout = NULL;
	}
}

template <typename archive>
void LIB::cluster::member::serialize (archive & arch, const unsigned int & version)
{
}

/*
const LIB::mathematics::numbers::natural & LIB::cluster::member::id (void) const
{
	return _id;
}

const LIB::mathematics::numbers::natural LIB::cluster::member::generate_id (void) const
{
	return 1;
}
*/

const LIB::cluster::member & LIB::cluster::member::operator = (const LIB::cluster::member & other)
{
	keepalive = other.keepalive;
	
	return *this;
}

const bool LIB::cluster::member::operator == (const LIB::cluster::member & other) const
{
	return this == & other || keepalive == other.keepalive;
}

void function_timeout (LIB::NAME_A <LIB::cluster::member, LIB::mathemathics::numbers::natural> & _members, const LIB::mathemathics::numbers::natural & key, const LIB::mathemathics::numbers::natural & timeout) const
{
	boost::this_thread::sleep (boost::posix_time::seconds (timeout));
	
	_members.unset (key);
}
