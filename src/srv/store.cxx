#pragma once

#include "store.hxx"
//#include <cstring>
#include <string>
#include <cln/nr.cxx>
#include <noware/var.cxx>
#include <noware/contnr/array.cxx>
#include "dev.cxx"
//#include "store.op.cxx"
#include "../msg/subj.hxx"

//#include ".store/.incl.cxx"

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
std::string const noware::vos::srv::store <val_t, key_t, grp_t>::grp_dft = "noware::vos::srv::store";

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::srv::store <val_t, key_t, grp_t>::write_dft = true;
//bool const noware::vos::srv::store::cache_dft = true;
//unsigned short int const noware::vos::srv::store::copy_dft = 1;

//#include ".store/.cxx"

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
noware::vos::srv::store <val_t, key_t, grp_t>::store (void)
{
////	node.initialize ();
////	node.start ();
//	assert (node.join (/*noware::vos::srv::store::*/grp_dft));
	////assert (node.join (/*store::*/grp_dft));
//	assert (node.join ("noware::vos::srv::store::nonfull")); // Temporary: dynamically find when needed.
////	node.reception_set (boost::bind (boost::mem_fn (&noware::vos::srv::store::receive), this, _1));
	////node.reception_set (boost::mem_fn (&noware::vos::srv::store::receive));
	////node.reception_set (&noware::vos::srv::store::receive);
	
	write = write_dft; // Temporary: TODO: dynamically find this.
//	cache = cache_dft;
//	copy = copy_dft;
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
noware::vos::srv::store <val_t, key_t, grp_t>::~store (void)
{
//	node.reception_unset ();
	// node.leave (/*noware::vos::srv::store::*/grp_dft);
//	node.stop ();
//	node.finalize ();
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::srv::store <val_t, key_t, grp_t>::start (void)
{
	if (!dev::start ())
		return false;
	
	if (!_node.join (grp_dft))
		return false;
	
	if (!_node.join (grp_dft + std::string ("::nonfull"))) // TODO: dynamically find when needed.
		return false;
	
	return true;
}

//const noware::var noware::vos::srv::store::evaluate (const noware::var & expression)
//{
//	return "";
//}
//

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::srv::store <val_t, key_t, grp_t>::respond (zmq::msg & re/* response/reply*/, zmq::msg const & req/* request*/, zyre_event_t const * const/* event*/, std::string const &/* event_type*/, std::string const &/* src*/, net::cast const &/* src_cast*/)
{
	std::cerr << "noware::vos::srv::store::respond()::scope::in" << std::endl;
	
	//zmq::msg msg;
	//zmsg_t * zmsg;
	//zmsg_t * zmsg_response;
	//zframe_t * zframe_response;
	//std::string event_type;
	
	//zmsg = zyre_event_msg (event);
	//msg = zyre_event_msg (event);
	//msg = zmsg;
	//event_type = zyre_event_type (event);
	//assert (event);
	//assert (zmsg);
	
	////noware::tree <std::string, std::string> response;
	//std::map <std::string, std::string> response;
	////noware::tree <std::string, std::string> message;
	
	//std::map <std::string, std::string> message;
	//noware::var result_tmp;
	//bool result;
	
//	zframe_t * frm;
	//noware::nr ndx;
	
	//data.clear ();
	//frm = zmsg_first (msg_rx);
//	frm = zmsg_first (zmsg);
	//ndx = 1;
	//while (frm != nullptr)
	//{
		// This makes a copy of the frame.
		//data [ndx] = *frm;
		
		//zframe_destroy (&f);
		
	//	frm = zmsg_next (&other);
	//	++ndx;
	//}
	
	//return other;
	
	//////if (!message.deserialize (msg_rx))
	//if (!noware::deserialize <std::map <std::string, std::string>> (message, std::string (msg_req)))
	////if (!noware::deserialize <std::map <std::string, std::string>> (message, std::string ((char *) zframe_data (frm), zframe_size (frm))))
	//	return false;
	
	//result = false;
	
	////std::cerr << "noware::vos::srv::store::respond()::if::message[subject]==[" << message ["subject"] << ']' << std::endl;
	//std::cerr << "noware::vos::srv::store::respond()::if::message[msg::meta]==[" << req [msg::meta] << ']' << std::endl;
	
	//std::cerr << "noware::vos::srv::store::respond()::if::message[type]==" << message ["type"] << "::else::in scope" << std::endl;
	
	//msg subj = *(req [0/*subj*/].data.data <msg> ());
	msg::subj * msg_req_subj;
	
	
	std::cerr << "noware::vos::srv::store::respond()::req.dump():" << std::endl;
	req.dump ();
	
	try
	{
		msg_req_subj = req.data.at (0/*subj*/).data.data <msg::subj> ();
		
		//msg msg_re_dir = msg::re;
		re.data [0/*msg::subj*/] = req.data.at (0);;
		
		//if (message ["subject"] == "existence")
		if (*msg_req_subj == msg::subj::exist)
		//if (req [msg::subj] == msg::exist)
		{
			std::cerr << "noware::vos::srv::store::respond()::exist::scope::in" << std::endl;
			
			//bool ok;
			bool result;
			grp_t grp;
			key_t key;
			
			//re = req;
			//re [0/*msg::subj*/] = req [0];
			//re [0/*msg::subj*/].data.data () = req [0];
			//re [1/*msg::dir*/] = zmq::message_t (&msg_re_dir, sizeof msg_re_dir);
			//response ["subject"] = message ["subject"];
			//response ["group"] = message ["group"];
			//response ["key"] = message ["key"];
			
			grp = *(req.data.at (1/*msg::grp*/).data.data <grp_t> ());
			key = *(req.data.at (2/*msg::grp*/).data.data <key_t> ());
			
			//if (!data.exist (message ["group"]))
			//	response ["value"] = false;
			//else
// 			try
// 			{
// 				std::cerr << "noware::vos::srv::store::respond()::exist::true" << std::endl;
// 				
// 				grp_t grp = *(req.data.at (1/*msg::grp*/).data.data <grp_t> ());
// 				key_t key = *(req.data.at (2/*msg::grp*/).data.data <key_t> ());
// 				//val_t val = *(req.data.at (3/*msg::grp*/).data.data <val_t> ());
// 				
// 				//data.at (*(req.data.at (1/*msg::grp*/).data.data <grp_t> ())).at (*(req.data.at (2/*msg::key*/).data.data <key_t> ()));
// 				data.at (grp).at (key).data.data <key_t> ()));
// 				////data.at (req [msg::grp]).at (req [msg::key]);
// 				//*(re [msg::exist].data.data <bool> ()) = true;
// 				//re [msg::exist] = true;
// 				result = true;
// 			}
// 			catch (...)
// 			{
// 				std::cerr << "noware::vos::srv::store::respond()::exist::false" << std::endl;
// 				
// 				//re [msg::exist] = false;
// 				result = false;
// 			}
			
			result = data.count (grp) > 0 && data.at (grp).count (key) > 0;
			
			//ok = true;
			
			//re [0/*result (msg::ok/success)*/] = zmq::message_t (&ok, sizeof ok);
			re.data [1/*1*//*result (msg::exist)*/] = zmq::message_t (&result, sizeof result);
			//msg_response = response ["value"];
			//return true;
		}
		/*
		else if (message ["subject"] == "existence.group")
		{
			std::cerr << "noware::vos::srv::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			response ["type"] = "response";
			response ["subject"] = message ["subject"];
			response ["group"] = message ["group"];
			//response ["key"] = message ["key"];
			//if (!data.exist (message ["group"]))
			//	response ["value"] = false;
			//else
				response ["value"] = data.exist (message ["group"]);
		}
		*/
		//else if (req [msg::subj] == msg::get)
		else if (*msg_req_subj == msg::subj::get)
		{
			std::cerr << "noware::vos::srv::store::respond()::get::scope::in" << std::endl;
			
			//re [0/*msg::subj*/] = req [0];
			//re [msg::dir] = msg::re;
			//re [msg::subj] = req [msg::subj];
			//re [msg::grp] = req [msg::grp];
			//re [msg::key] = req [msg::key];
			
			//bool succ;
			////bool exist;
			grp_t grp;
			key_t key;
			val_t val;
			
			try
			{
				std::cerr << "noware::vos::srv::store::respond()::get::try" << std::endl;
				
				grp = *(req.data.at (1/*msg::grp*/).data.data <grp_t> ());
				key = *(req.data.at (2/*msg::grp*/).data.data <key_t> ());
				
				//std::pair <std::string, bool> value = data.at (message ["group"]).at (message ["key"]);
				//re [msg::val] = data.at (req [msg::grp]).at (req [msg::key]);
			//	val = &data.at (*(req.data.at (1/*msg::grp*/).data.data <grp_t> ())).at (*(req.data.at (2/*msg::key*/).data.data <key_t> ()));
				val = data.at (grp).at (key);
				//response ["value"] = value.first;
				//response ["value.reference"] = value.second ? "1" : "0";
				
				std::cerr << "noware::vos::srv::store::respond()::get::exist::true" << std::endl;
				
				//exist = true;
				re.data [1/*1*//*2*//*value*/] = zmq::message_t (&val, sizeof val);
			}
			catch (...)
			{
				std::cerr << "noware::vos::srv::store::respond()::get::exist::false" << std::endl;
				
				//exist = false;
			}
			
			//succ = true;
			
			//re [0/*result (msg::ok/success)*/] = zmq::message_t (&succ, sizeof succ);
			////re [1/*result (msg::exist)*/] = zmq::message_t (&exist, sizeof exist);
			
			//std::cerr << "noware::vos::srv::store::respond()::message[subject]==" << message ["subject"] << "::response[value.exist]==" << response ["value.exist"] << std::endl;
			//if (bool (re [msg::exist]))
			//	std::cerr << "noware::vos::srv::store::respond()::message[subject]==" << message ["subject"] << "::response[value]==" << response ["value"] << std::endl;
		}
		//else if (re [msg::meta] == msg::set)
		else if (*msg_req_subj == msg::subj::set)
		{
			std::cerr << "noware::vos::srv::store::respond()::set::scope::in" << std::endl;
			
			//re [msg::dir] = msg::re;
			//re [msg::subj] = req [msg::subj];
			//re [msg::grp] = req [msg::grp];
			//re [msg::key] = req [msg::key];
			//response ["existence"] = data.exist (message ["group"]) && data.get (message ["group"]).exist (message ["key"]);
			
			bool succ;
			
			if (!write || full ())
			{
				std::cerr << "noware::vos::srv::store::respond()::!write||full()" << std::endl;
				
				succ = false;
				
				//re [msg::ok] = false;
				//return false;
			}
			else
			{
				std::cerr << "noware::vos::srv::store::respond()::write" << std::endl;
				
				grp_t grp;
				key_t key;
				val_t val;
				
				grp = *(req.data.at (1/*msg::grp*/).data.data <grp_t> ());
				key = *(req.data.at (2/*msg::grp*/).data.data <key_t> ());
				val = *(req.data.at (3/*msg::grp*/).data.data <val_t> ());
			//	grp_t * grp = req.data.at (1/*msg::grp*/).data.data <grp_t> ();
			//	key_t * key = req.data.at (2/*msg::grp*/).data.data <key_t> ();
			//	val_t * val = req.data.at (3/*msg::grp*/).data.data <val_t> ();
				
				std::cerr << "noware::vos::srv::store::respond()::write::grp[1]==";
				std::cerr << '[' << *(req.data.at (1).data.data <grp_t> ()) << ']' << std::endl;
				
				std::cerr << "noware::vos::srv::store::respond()::write::key[2]==";
				std::cerr << '[' << *(req.data.at (2).data.data <key_t> ()) << ']' << std::endl;
				
				std::cerr << "noware::vos::srv::store::respond()::write::val[3]==";
				std::cerr << '[' << *(req.data.at (3).data.data <val_t> ()) << ']' << std::endl;
				
				//response ["type"] = "response";
				//response ["subject"] = message ["subject"];
				//response ["group"] = message ["group"];
				//response ["key"] = message ["key"];
				////response ["existence"] = data.exist (message ["group"]) && data.get (message ["group"]).exist (message ["key"]);
				
				//data [req [msg::grp]] [req [msg:key]] = req [msg::val];
			//	data
			//		 [(*(req.data.at (1/*msg::grp*/).data.data <grp_t> ()))]
			//		 [(*(req.data.at (2/*msg::key*/).data.data <key_t> ()))]
			//		= (*(req.data.at (3/*msg::key*/).data.data <val_t> ()));
				data [grp] [key] = val;
				//data [message ["group"]] [message ["key"]] = std::pair <std::string, bool> (message ["value"], message ["reference"] == "1" ? true : false);
				
				std::cerr << "noware::vos::srv::store::respond()::write::succ=[true]" << std::endl;
				succ = true;
				
				/*
				std::cerr << "noware::vos::srv::store::respond()::if::message[subject]==" << message ["subject"] << "::try..." << std::endl;
				try
				{
					std::cerr << "noware::vos::srv::store::respond()::if::message[subject]==" << message ["subject"] << "::try::in scope" << std::endl;
					if (data.at (message ["group"]).at (message ["key"]) == message ["value"])
					{
						std::cerr << "noware::vos::srv::store::respond()::if::message[subject]==" << message ["subject"] << "::try::if" << std::endl;
						response ["value"] = "1";
					}
					else
					{
						std::cerr << "noware::vos::srv::store::respond()::if::message[subject]==" << message ["subject"] << "::try::if::else" << std::endl;
						response ["value"] = "0";
					}
				}
				catch (...)
				{
					std::cerr << "noware::vos::srv::store::respond()::if::message[subject]==" << message ["subject"] << "::try::catch" << std::endl;
					response ["value"] = "0";
				}
				
				//response ["value"] = "1";
				
				std::cerr << "noware::vos::srv::store::respond()::if::message[subject]==" << message ["subject"] << "::response[value]==[" << response ["value"] << ']' << std::endl;
				//return response ["value"] == "1";
				*/
				
				if (full ())
				{
					std::cerr << "noware::vos::srv::store::respond()::write::node.leave(" << grp_dft + std::string ("::nonfull") << ')' << std::endl;
					
					assert (_node.leave (grp_dft + std::string ("::nonfull")));
				}
				
				std::cerr << "noware::vos::srv::store::respond()::write::node.join(" << grp_dft + std::string ("::nonempty") << ')' << std::endl;
					
				assert (_node.join (grp_dft + std::string ("::nonempty")));
				
				//re [msg::ok] = true;
			}
			
			std::cerr << "noware::vos::srv::store::respond()::write::re.data[1]=succ[" << succ << ']' << std::endl;
			
			re.data [1/*result (msg::ok/success)*/] = zmq::message_t (&succ, sizeof succ);
			//msg_response = response ["value"];
			//return true;
		}
		//else if (req [msg::subj] == msg::del)
		else if (*msg_req_subj == msg::subj::del)
		{
			std::cerr << "noware::vos::srv::store::respond()::del::scope::in" << std::endl;
			/*
			std::cerr << "noware::vos::srv::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			std::cerr << "noware::vos::srv::store::respond()::message[group]==" << message ["group"] << "" << std::endl;
			std::cerr << "noware::vos::srv::store::respond()::message[key]==" << message ["key"] << "" << std::endl;
			*/
			
			bool succ;
			grp_t grp;
			key_t key;
			
			grp = *(req.data.at (1/*msg::grp*/).data.data <grp_t> ());
			key = *(req.data.at (2/*msg::key*/).data.data <key_t> ());
			
			//try
			//{
				//re [msg::dir] = msg::re;
				//re [msg::subj] = req [msg::subj];
				//re [msg::grp] = req [msg::grp];
				//re [msg::key] = req [msg::key];
				
				if (data.count (grp) <= 0 || data.at (grp).count (key) <= 0)
				{
					std::cerr << "noware::vos::srv::store::respond()::del::if::1" << std::endl;
					
					// grp+key already absent
					succ = true;
					
					//re [msg::ok] = true;
					//return true;
				}
				else if (!write)
				{
					std::cerr << "noware::vos::srv::store::respond()::del::if::2" << std::endl;
					
					// may not modify local container
					succ = false;
					
					//re [msg::ok] = false;
					//return false;
				}
				else
				{
					std::cerr << "noware::vos::srv::store::respond()::del::if::3" << std::endl;
					
					//response ["type"] = "response";
					//response ["subject"] = message ["subject"];
					//response ["group"] = message ["group"];
					//response ["key"] = message ["key"];
					////response ["meta"] = data.exist (message ["key"]);
					
					try
					{
						data.at (grp).erase (key);
						
						//re [msg::ok] = true;
						succ = true;
						
						if (data.at (grp).empty ())
							data.erase (grp);
					}
					catch (...)
					{
						// The group does not exist (idempotency).
						succ = true;
						
						//re [msg::ok] = true;
					}
				}
			/*
			}
			catch (...)
			{
				// ...branch not really needed
				
				ok = false;
			}
			*/
			
			//msg_response = response ["value"];
			re.data [1/*result (msg::ok/success)*/] = zmq::message_t (&succ, sizeof succ);
			//return true;
		}
		//else if (req [msg::subj] == msg::size)
		else if (*msg_req_subj == msg::subj::size)
		{
			std::cerr << "noware::vos::srv::store::respond()::size" << std::endl;
			
			//std::cerr << "noware::vos::srv::store::respond()::if::message[subject]==" << message ["subject"] << "::in scope" << std::endl;
			
			//re [msg::dir] = msg::re;
			//re [msg::subj] = req [msg::subj];
			//response ["key"] = message ["key"];
			
			//bool ok;
			int unsigned count;
			
			if (req.data.count (1) > 0)
			{
				std::cerr << "noware::vos::srv::store::respond()::size::group[ed]" << std::endl;
				
				grp_t grp;
				
				grp = *(req.data.at (1/*msg::grp*/).data.data <grp_t> ());
				
				if (data.count (grp) > 0)
				{
					std::cerr << "noware::vos::srv::store::respond()::size::group::exist::true" << std::endl;
					
					//re [msg::val] = data [req [msg::grp]].size ();
					count = data.at (grp).size ();
				}
				else
				{
					std::cerr << "noware::vos::srv::store::respond()::size::group::exist::false" << std::endl;
					
					//re [msg::val] = 0;
					count = 0;
				}
			}
			else
			{
				std::cerr << "noware::vos::srv::store::respond()::size::not group[ed]" << std::endl;
				
				//response ["value"] = data.size ();
				//std::cerr << "noware::vos::srv::store::respond()::data.size ()==[" << data.size () << ']' << std::endl;
				
				count = 0;
				for (std::pair <grp_t, std::map <key_t, val_t>> const & group : data)
				{
					count += group.second.size ();
				}
				
				std::cerr << "noware::vos::srv::store::respond()::size::count==[" << count << ']' << std::endl;
				//std::cerr << "noware::vos::srv::store::respond()::response[value]==[" << response ["value"] << ']' << std::endl;
			}
			
			//ok = true;
			
			re.data [1/*msg::val*/] = zmq::message_t (&count, sizeof count);
			//response ["value"] = "12321";
			//re [0/*result (msg::ok/success)*/] = zmq::message_t (&ok, sizeof ok);
			
			//msg_response = response ["value"];
			//return true;
		}
		//else if (req [msg::subj] == msg::avail)
		else if (*msg_req_subj == msg::subj::avail)
		{
			std::cerr << "noware::vos::srv::store::respond()::avail" << std::endl;
			
			//bool succ;
			int unsigned count;
			
			count = 0;
			//succ = true;
			
			//re [msg::dir] = msg::re;
			//re [msg::subj] = req [msg::subj];
			//re [msg::val] = 0;
			
			re.data [1/*msg::val*/] = zmq::message_t (&count, sizeof count);
			//response ["value"] = "12321";
			//re [0/*result (msg::ok/success)*/] = zmq::message_t (&succ, sizeof succ);
			
			//msg_response = response ["value"];
			//return true;
		}
		//else if (req [msg::subj] == msg::used)
		else if (*msg_req_subj == msg::subj::used)
		{
			std::cerr << "noware::vos::srv::store::respond()::used" << std::endl;
			
			//bool succ;
			int unsigned count;
			
			count = 0;
			//succ = true;
			
			//re [msg::dir] = msg::re;
			//re [msg::subj] = req [msg::subj];
			//re [msg::val] = 0;
			
			re.data [1/*msg::val*/] = zmq::message_t (&count, sizeof count);
			//response ["value"] = "12321";
			//re [0/*result (msg::ok/success)*/] = zmq::message_t (&succ, sizeof succ);
			
			//msg_response = response ["value"];
			//return true;
		}
		//else if (req [msg::subj] == msg::capac)
		else if (*msg_req_subj == msg::subj::capac)
		{
			std::cerr << "noware::vos::srv::store::respond()::capac" << std::endl;
			
			//bool succ;
			int unsigned count;
			
			//re [msg::dir] = msg::re;
			//re [msg::subj] = req [msg::subj];
			//re [msg::val] = 0;
			
			count = 0;
			//succ = true;
			
			re.data [1/*msg::val*/] = zmq::message_t (&count, sizeof count);
			//response ["value"] = "12321";
			//re [0/*result (msg::ok/success)*/] = zmq::message_t (&succ, sizeof succ);
			
			//msg_response = response ["value"];
			//return true;
		}
		//else if (req [msg::subj] == msg::empty)
		else if (*msg_req_subj == msg::subj::empty)
		{
			std::cerr << "noware::vos::srv::store::respond()::empty" << std::endl;
			
			//bool succ;
			bool empty;
			
			//re [msg::dir] = msg::re;
			//re [msg::subj] = req [msg::subj];
			
			/*
			if (data.empty ())
				re [msg::val] = true;
			else
				re [msg::val] = false;
			*/
			
			empty = data.empty ();
			//succ = true;
			
			//re [msg::val] = data.empty ();
			re.data [1/*msg::val*/] = zmq::message_t (&empty, sizeof empty);
			//response ["value"] = "12321";
			//re [0/*result (msg::ok/success)*/] = zmq::message_t (&succ, sizeof succ);
			
			//msg_response = response ["value"];
			//return true;
		}
		//else if (req [msg::subj] == msg::full)
		else if (*msg_req_subj == msg::subj::full)
		{
			std::cerr << "noware::vos::srv::store::respond()::full" << std::endl;
			
			//bool ok;
			bool full;
			
			//re [msg::dir] = msg::re;
			//re [msg::subj] = req [msg::subj];
			
			full = false;
			//ok = true;
			
			//re [msg::val] = false;
			re.data [1/*msg::val*/] = zmq::message_t (&full, sizeof full);
			//response ["value"] = "12321";
			//re [0/*result (msg::ok/success)*/] = zmq::message_t (&ok, sizeof ok);
			
			//msg_response = response ["value"];
			//return true;
		}
		//else if (req [msg::subj] == msg::clear)
		else if (*msg_req_subj == msg::subj::clear)
		{
			std::cerr << "noware::vos::srv::store::respond()::clear" << std::endl;
			
			bool succ;
			
			//re [msg::subj] = req [msg::subj];
			//re [msg::dir] = msg::re;
			
			if (!write)
			{
				// may not modify local container
				
				//re [msg::ok] = false;
				succ = false;
				//return false;
			}
			else
			{
				if (req.data.count (1) > 0/* && data.count (message.at ("group")) > 0*/)
				{
					//grp = req [1/*msg::grp*/].data.data <grp_t> ();
					grp_t grp;
					
					grp = *(req.data.at (1/*msg::grp*/).data.data <grp_t> ());
					
					data.erase (grp);
					
					if (empty ())
						assert (_node.leave (grp_dft + std::string ("::nonempty")));
				}
				else
				{
					//response ["key"] = message ["key"];
					//response ["meta"] = data.exist (message ["key"]);
					//if (response ["meta"])
					data.clear ();
					assert (_node.leave (grp_dft + std::string ("::nonempty")));
				}
				
				assert (_node.join (grp_dft + std::string ("::nonfull")));
				
				//response ["subject"] = message ["subject"];
				//response ["type"] = "response";
				
				//re [msg::ok] = true;
				succ = true;
			}
			
			//msg_response = response ["value"];
			re.data [1/*result (msg::ok/success)*/] = zmq::message_t (&succ, sizeof succ);
			//return true;
		}
		else
		{
			std::cerr << "noware::vos::srv::store::respond()::else" << std::endl;
			
			return false;
		}
	}
	catch (...)
	{
		std::cerr << "noware::vos::srv::store::respond()::caught" << std::endl;
		return false;
	}
	
	// Send back the answer.
	/*
	//result = node.unicast (zmq::msg (response.serialize ()), zyre_event_peer_uuid (event));
	std::string response_serial;
	if (!noware::serialize <std::map <std::string, std::string>> (response_serial, response))
		return false;
	//result = node.unicast (zmq::msg (response_serial), zyre_event_peer_uuid (event));
	
	msg_response = response_serial;
	*/
	
	//result = true;
	
	//zmsg_response = zmsg_new ();
	//zframe_response = zframe_new (response_serial.data (), response_serial.size ());
	//zmsg_append (zmsg_response, &zframe_response);
	
	//result = node.unicast (zmsg_response, zyre_event_peer_uuid (event));
//	std::cerr << "noware::vos::srv::store::respond()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
	
	//return result;
	return true;
}

/*
template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::srv::store <val_t, key_t, grp_t>::exist (const key_t & key) const
{
	return exist ("", key);
}
*/

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::srv::store <val_t, key_t, grp_t>::exist (grp_t const & grp, key_t const & key) const
{
	val_t const * val;
	return get (grp, key, val);
}

/*
template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const/*success* / noware::vos::srv::store <val_t, key_t, grp_t>::get (const key_t & key, val_t const * & val) const
//const std::pair <std::string/*value* /, bool/*reference* /> noware::vos::srv::store::get (const std::string & key) const
{
	return get ("", key, val);
}
*/

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const/*success*/ noware::vos::srv::store <val_t, key_t, grp_t>::get (grp_t const & grp, key_t const & key, val_t const * & val) const
//const std::pair <std::string/*value*/, bool/*reference*/> noware::vos::srv::store::get (const std::string & group, const std::string & key) const
{
	try
	{
		val = &(data.at (grp).at (key));
		return true;
	}
	catch (...)
	{
		return false;
	}
	
	// to satisfy the compiler
	return false;
}

/*
template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::srv::store <val_t, key_t, grp_t>::set (key_t const & key, val_t const & val)
//const bool noware::vos::srv::store::set (const std::string & key, const std::string & value, const bool & reference)
{
	return set ("", key, val);
	//return set ("", key, value, reference);
}
*/

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::srv::store <val_t, key_t, grp_t>::set (grp_t const & grp, key_t const & key, val_t const & val)
//const bool noware::vos::srv::store::set (const std::string & group, const std::string & key, const std::string & value, const bool & reference)
{
	data [grp] [key] = val;
	return true;
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
cln::nr const noware::vos::srv::store <val_t, key_t, grp_t>::capac (void) const
{
	return 0;
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
cln::nr const noware::vos::srv::store <val_t, key_t, grp_t>::used (void) const
{
	return sizeof data;
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
cln::nr const noware::vos::srv::store <val_t, key_t, grp_t>::avail (void) const
{
	return 0;
	//return INFINITY;
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
cln::nr const noware::vos::srv::store <val_t, key_t, grp_t>::size (void) const
{
	cln::nr count;
	
	count = 0;
	for (std::pair <grp_t, std::map <key_t, val_t>> const & grp : data)
		count += grp.second.size ();
	
	return count;
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
cln::nr const noware::vos::srv::store <val_t, key_t, grp_t>::size (grp_t const & grp) const
{
	try
	{
		return data.at (grp).size ();
	}
	catch (...)
	{
		// there is no such group
		return 0;
	}
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::srv::store <val_t, key_t, grp_t>::empty (void) const
{
	//return size () <= 0;
	return data.empty ();
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::srv::store <val_t, key_t, grp_t>::full (void) const
{
	return false;
}

/*
bool const rename (std::string const & old_k, std::string const & new_k);
{
	
	return true;
}
*/

/*
template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::srv::store <val_t, key_t, grp_t>::remove (key_t const & key)
{
	return remove ("", key);
}
*/

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::srv::store <val_t, key_t, grp_t>::del (grp_t const & grp, key_t const & key)
{
	try
	{
		data.at (grp).erase (key);
	}
	catch (...)
	{
		// no such group
		// no such key, either
		return true;
	}
	
	// do not keep an empty group container
	if (data.at (grp).empty ())
		data.erase (grp);
	
	return true;
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::srv::store <val_t, key_t, grp_t>::clear (void)
{
	data.clear ();
	//_size = 0;
	return true;
}

template
<
	typename val_t,
	typename key_t,
	typename grp_t
>
bool const noware::vos::srv::store <val_t, key_t, grp_t>::clear (grp_t const & grp)
{
	data.erase (grp);
	return true;
}

/*
std::string & noware::vos::srv::store::operator [] (std::string const & key)
{
	std::string const * val;
	
	if (get ("", key, val))
		return *val;
	
	// TODO: handle case when set/get fails
	set ("", key, "");
	get ("", key, val);
	return *val;
}
*/

/*
template <typename value>
virtual const iterator <value> noware::vos::srv::store::begin (void) const
{
}

template <typename value>
virtual const iterator <value> noware::vos::srv::store::end (void) const
{
}

template <typename value>
virtual const iterator <value> noware::vos::srv::store::operator ++ (void)
{
}

template <typename value>
virtual const iterator <value> noware::vos::srv::store::operator -- (void)
{
}

template <typename value>
virtual const bool noware::vos::srv::store::operator == (const iterator <value> & other) const
{
}

template <typename value>
virtual const value noware::vos::srv::store::operator * (void) const
{
}
*/

/*
// For range-based for looping:

virtual const misc::iterator <std::tuple <std::string, std::string, std::string>> begin (void) const;
//virtual const store begin (void) const
{
	misc::iterator <std::tuple <std::string, std::string, std::string>> iterator;
	
	return iterator;
}

virtual const misc::iterator <std::tuple <std::string, std::string, std::string>> end (void) const;
//virtual const store end (void) const
{}

virtual const std::tuple <std::string, std::string, std::string> operator * (void) const
{}

virtual const bool operator == (const misc::iterator <std::tuple <std::string, std::string, std::string>> & other) const;
//virtual const bool operator == (const store & other) const
{}

virtual const misc::iterator <std::tuple <std::string, std::string, std::string>> operator ++ (void);
//virtual const store operator ++ (void)
{
	std::cerr << "noware::vos::srv::dev::multicast()::called" << std::endl;
	//if (!message.is_group ())
	//	return "";
	
	std::string request_token;
	zmq::msg msg_resp;
	//noware::nr responses_count;
	
	request_token = noware::random::string (token_size_dft);
	std::cerr << "noware::vos::srv::dev::multicast()::request_token==[" << request_token << ']' << std::endl;
	
	msg_req.prepend (zmq::msg::frame (dev::grp_dft + std::string ("::response::desired")));
	msg_req.prepend (zmq::msg::frame (request_token));
	
	if (!node.multicast (msg_req, group))
	{
		std::cerr << "noware::vos::srv::dev::multicast()::node.multicast()::failure" << std::endl;
		return msg_resp;
	}
	
	std::cerr << "noware::vos::srv::dev::multicast()::node.multicast()::success" << std::endl;
	
	iteration = receive_local (request_token, node.peers_size (group), responses_count, group, net::cast::multi);
	
	//return *this;
}

virtual const misc::iterator <std::tuple <std::string, std::string, std::string>> operator -- (void);
//virtual const store operator -- (void)
{}
*/
