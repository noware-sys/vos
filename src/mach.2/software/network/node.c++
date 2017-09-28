#include "node.h++"

LIB::node::node (void)
{
	_state = status::unavailable;
}

LIB::node::state (void) const
{
	return _state;
}
