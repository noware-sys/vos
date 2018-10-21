#pragma once

#include "dev.hxx"
#include <cln/nr.hxx>
#include <noware/var.hxx>
#include <queue>

namespace noware
{
	namespace vos
	{
		namespace srv
		{
			template <typename val_t = var>
			class queue
				: virtual public dev
				//: virtual public cluster::node
			{
				public:
					queue (void);
					virtual ~queue (void);
					
					virtual bool const start (void);
					
					static std::string const grp_dft;
					
					// dequeue beginning first head top pop next current present fetch operate
					virtual bool const next (val_t &) const;
					// get the next element and dequeue
					virtual bool const next_dequeue (val_t &);
					virtual bool const dequeue (void);
					virtual bool const enqueue (val_t const &/* element*/);
					virtual cln::nr const size (void) const;
					virtual bool const empty (void) const;
					//virtual bool const empty_local (void) const;
					virtual bool const full (void) const;
					//virtual bool const full_local (void) const;
					virtual bool const clear (void);
					
				protected:
					//virtual bool const/* success*/ respond (zmq::msg &/* response*/, zmq::msg const &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/);
					virtual bool const/* success*/ respond (zmq::msg &/* response*/, zmq::msg const &/* rx'd*/, zyre_event_t const * const/* (zyre) event*/, std::string const &/* event_type*/, std::string const &/* src*/, net::cast const &/* src_cast*/);
					virtual bool const/* success*/ respond_post (zmq::msg const &/* response (read-only)*/, zmq::msg const &/* rx'd*/, zyre_event_t const * const/* (zyre) event*/, std::string const &/* event_type*/, std::string const &/* src*/, net::cast const &/* src_cast*/, bool const &/* result*/);
				//	virtual bool const/* success*/ search (zmq::msg &/* result*/, zmq::msg const &/* message/expression*/, noware::nr const &/* total, expected resonses count*/, noware::nr const &/* current count of peers who responded (so far)*/, std::string const &/* src*/, net::cast const &/* src_cast*/);// const
				//	virtual bool const/* success*/ search_local (zmq::msg &/* result*/, zmq::msg const &/* message/expression*/, std::string const &/* src*/, net::cast const &/* src_cast*/);// const
				//	virtual zmq::msg const/* result*/ aggregate (zmq::msg const &/* result*/, zmq::msg const &/* response*/, zmq::msg const &/* expression*/, noware::nr const &/* responses_count*//* number of peers who answered*/, std::string const &/* src*/, net::cast const &/* src_cast*/);
					
				//protected:
				public:
					std::queue <val_t> queue;
			};
		}
	}
}

/*
	{
		(ins(req()));
		(ins(req()));
		(ins(req()));
	}
*/

/*
	activity
	{
		process (exp (ins));
		process (exp (ins));
		process (exp (ins));
	}
*/

/*
	activity
	{
		process (operation (instruction ...) ...);
		process (operation (instruction ...) ...);
		process (operation (instruction ...) ...);
	}
*/

/*
	main activity
	# parallel
	{
		sub activity / action ...
		# parallel
		{
			process
			# serial
			{
				operation ...
				# parallel or serial
				{
					instruction; ...
				}
			}
		}
	}
*/

/*
	
	{
		# parallel
		{
			process
			{
				# serial
				{
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
					
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
					
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
				};
			};
			
			process
			{
				# serial
				{
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
					
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
					
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
				};
			};
			
			process
			{
				# serial
				{
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
					
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
					
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
				};
			};
		};
	};
*/
