#pragma once

#include <cln/nr.hxx>
//#include <bitset>
#include <string>
//#include <sstream>
#include ".x86_64/.incl.hxx"
#include "../dev.hxx"
#include "../../usr/store.hxx"
#include "../../usr/queue.hxx"
#include <gdabah/distorm/distorm.h>
#include <gdabah/distorm/mnemonics.h>

namespace noware
{
	namespace vos
	{
		namespace srv
		{
			namespace cpu
			{
				// processor cpu
				// thread task job
				class x86_64
					: virtual public dev
					//: virtual public cluster::node
					, virtual public usr::store <char unsigned/* val_t*/, uint64_t/* key_t*/, int unsigned/* grp_t*/>
					, virtual public usr::queue <std::string/* val_t*/>
				{
					public:
						// operator operation
						/*
						enum class dev
						{
							none,
							cpu,
							store,
							cli
						};
						*/
						/*
						enum class opr
						{
							none,
							
							// For controlling the flow of the execution:
							//and,	// and intersection
							//or, // or union
							get,				// attainment obtainment get read load
							set,				// assignment settlement set write store move
							//exist,			// presence existence exist
							remove,					// removal resettal rm remove reset unset
							///*
							
							add,				// addition
							substr,			// substraction
							multi,			// multiplication
							div,				// division
							
							exp,				// exponentiation
							modulo,			// remainder of division
							modulus,		// absolute value
							complement,	// complement compl
							
							cat					// concatenation cat
							//* /
							
							//set,
							
							// Control of the flow
							//eql,
							//grtr,
							//grtr_eql,
							//lowr,
							//lowr_eql,
							
							//output,		// output set echo cout
							//go//,			// go[[ ]to] skip jump hop
							
							//tx,
							//exe
						};
						*/
						
						//#include ".cpu/x86_64.hxx"
						//#include ".cpu/instr.mov.hxx"
						//#include ".cpu/instr.x86_64.hxx"
						
						typedef /*cln::nr*/int unsigned store_grp_t;
						typedef uint64_t store_key_t;
						typedef char unsigned store_val_t;
						typedef std::string queue_val_t;
						
						#include ".x86_64/.hxx"
						
						x86_64 (void);
						virtual ~x86_64 (void);
						
						static std::string const grp_dft;
						
						virtual bool const start (void);
						virtual bool const stop (void);
						virtual bool const running (void) const;
						
						// In seconds
						// notification_delay_dft noten_delay_dft
						static int short unsigned const noten_delay_dft;
						
						// in nr of instructions
						static cln::nr const insn_cache_dft;
						
						//virtual const bool join (void);
						
						cln::nr const insn_cache (void) const;
						bool const insn_cache (cln::nr const &);
						
						// Queue
					public:
					//protected:
						// dequeue beginning first head top pop next fetch operate
					//	virtual bool const next (queue_val_t &) const;
					//	virtual bool const next_dequeue (queue_val_t &);
					//	virtual bool const dequeue (void);
						//const instruction dequeue (void);
					public:
						virtual cln::nr const size (void) const;
						virtual bool const empty (void) const;
						virtual bool const full (void) const;
						
					//	virtual bool const enqueue (queue_val_t const &);
						////const bool enqueue (const operation &/* operator*/, const noware::var &/* operand1*/, const noware::var &/* operand2*/ = "");	// Accurate.
						//virtual const bool enqueue (const std::string &/* operand1 (source)*/, const opr &/* operation*/ = opr::none, const std::string &/* operand2 (key)*/ = "", const std::string &/* operand3/thread_id (group)*/ = "");	// Convenient.
						
						//const bool enqueue (const cpu::dev &, const opr &, const std::map <std::string, std::string> &/* arg*/, const std::string &/* thread_id*/);
						//const bool enqueue (const std::string &, const std::string &, const std::map <std::string, std::string> &/* arg*/, const std::string &/* thread_id*/);
						
						// do perform execute apply evaluate
						//const bool apply (const instruction &);
						
						// Store
					public:
					//	virtual bool const exist (store_key_t const &/* key*/) const;
					//	virtual bool const exist (store_grp_t const &/* group*/, store_key_t const &/* key*/) const;
						
						virtual bool const clear (void);
					//	virtual bool const clear (store_grp_t const &/* group*/);
						
					//	virtual bool const del (store_grp_t const &/* group*/, store_key_t const &/* key*/);
					//	virtual bool const del (store_key_t const &/* key*/);
						
					//	virtual val_t const/* value*/ get (grp_t const &/* group*/, key_t const &/* key*/) const;
						//virtual const std::string/* value*/ get (const std::string &/* key*/) const;
						////virtual const std::pair <std::string/* value*/, bool/* reference*/> get (const std::string &/* group*/, const std::string &/* key*/) const;
						////virtual const std::pair <std::string/* value*/, bool/* reference*/> get (const std::string &/* key*/) const;
						
					//	virtual bool const/* success*/ set (store_grp_t const &/* group*/, store_key_t const &/* key*/, store_val_t const &/* content/value*/);
					//	virtual bool const/* success*/ set (store_key_t const &/* key*/, store_val_t const &/* content/value*/);
						//virtual const bool/* success*/ set (const std::string &/* group*/, const std::string &/* key*/, const std::string &/* content/value*/, const bool &/* reference*/ = false);
						//virtual const bool/* success*/ set (const std::string &/* key*/, const std::string &/* content/value*/, const bool &/* reference*/ = false);
						
						
						// /Command Prompt/Terminal/Console/CLI/CUI/TTY/ functionality
						// set
						virtual bool const cout (char unsigned const &/* value*/);
						// get
						virtual bool const cin (std::string &/* value*/, char const &/* delimiter*/ = '\n');
						
						// evaluate instruction
						//#include ".cpu/val.x86_64.hxx"
						//virtual bool const val (x86_64::instr const &/* instruction*/);
					private:
						//#include ".cpu/val.x86_64.hxx"
						//#include ".cpu/exe-x86_64.hxx"
						//#include ".cpu/exe-bbj.hxx"
					//	virtual unsigned int const fetch (unsigned int const &/* address*/) const;
					//	virtual unsigned int const decode (unsigned int /*instr */const &/* instruction*/);
						//virtual bool const exe (unsigned int /*instr */const &/* instruction*/);
					//	virtual bool const exe (insn const &/* instruction*/, std::string &/* thread.insn_ptr*/, std::string const &/* thread.id*/);
						
						virtual bool const exe (bool &/* OUT: end*/, _DInst const &/* IN: instruction*//*, uint64_t &*//* IN/OUT: thread's relevant current insn_ptr value*/, thread &/* IN/OUT: thread*/);
						
						virtual const bool/* success*/ respond (zmq::msg &/* response*/, const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/);
						virtual const bool/* success*/ search_remote (zmq::msg const &/* result*/, const zmq::msg &/* message/expression*/, const cln::nr &/* total, expected resonses count*/, const cln::nr &/* current count of peers who responded (so far)*/, const std::string &/* src*/, const net::cast &/* src_cast*/);// const
						//virtual const bool/* success*/ search_local (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/);// const
						virtual bool const/* success*/ aggregate_remote (zmq::msg &/* overall/final result. passed during each iteration*/, zmq::msg const &/* current response message/expression*/, cln::nr const &/* total, expected resonses count*/, cln::nr const &/* current count of peers who responded (so far)*/, std::string const &/* src*/, net::cast const &/* src_cast*/);
					private:
						// /Process/Find/Search for/ the next instruction on-the-fly.
						// Do not store an instruction queue.
						//std::queue <instruction> queue;
						
						// nr of instructions ("time share") of the same thread
						// which are being spent executing before moving on to another thread:
						// 
						// how many instructions, of the same thread, to locally execute,
						// before resuming usage of the networked queue again
						// 
						// valid range: [1 - !fin[ | val is an int
						// 
						//cln::nr reenqueue_delay;
						cln::nr _insn_cache;
					private:
						//bool _running;
						bool _insn_avail;
						
						// 'EXEcutioN' thread
						// For running "void exe (void)".
						boost::thread * _exen;
						
						// main execution loop
						void cycle (void);
						
						boost::condition_variable _condition_instr_enqueued;
						boost::mutex _mutex;
						void notify (const unsigned int &/* seconds to delay between notifications*/);
						boost::thread * _notification;
						//// redundancy group
						//std::string grp;
					//private:
						// program counter
						//unsigned int pc;
						
						//mar;
						//mdr;
						
						// instruction register
						//unsigned int ir;
						
						//cu;
						//alu;
						//fpu;
				};
			}
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
*/
