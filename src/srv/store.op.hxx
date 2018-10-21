// free-function operators which are useful only/mostly for store

#include "msg.hxx"
#include <zmq/msg.hxx>

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
operator grp_t zmq::msg::frame _frame ();
