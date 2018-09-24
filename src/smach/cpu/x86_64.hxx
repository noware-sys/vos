#pragma once

#include <cln/nr.hxx>
#include ".x86_64/.incl.hxx"
#include "dev.hxx"

namespace noware
{
	namespace smach
	{
		namespace cpu
		{
			// processor cpu
			// thread task job
			class x86_64
				: virtual public dev
				//: virtual public cluster::node
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
					
					#include ".x86_64/.hxx"
					
					x86_64 (void);
					virtual ~x86_64 (void);
					
					static std::string const grp_dft;
					
					virtual const bool stop (void);
					virtual const bool running (void) const;
					virtual const bool start (void);
					
					// In seconds
					// notification_delay_dft noten_delay_dft
					static unsigned short int const noten_delay_dft;
					
					// in nr of instructions
					static cln::nr const reenqueue_delay_dft;
					
					//virtual const bool join (void);
					
					cln::nr const reenqueue_delay_get (void) const;
					bool const reenqueue_delay_set (cln::nr const &);
					
					// Queue
				public:
				//protected:
					// dequeue beginning first head top pop next fetch operate
					virtual std::string const next_dequeue (void);
					virtual std::string const next (void) const;
					virtual const bool dequeue (void);
					//const instruction dequeue (void);
				public:
					virtual const cln::nr size (void) const;
					virtual const bool empty (void) const;
					virtual const bool full (void) const;
					
					virtual const bool enqueue (std::string const &);
					////const bool enqueue (const operation &/* operator*/, const noware::var &/* operand1*/, const noware::var &/* operand2*/ = "");	// Accurate.
					//virtual const bool enqueue (const std::string &/* operand1 (source)*/, const opr &/* operation*/ = opr::none, const std::string &/* operand2 (key)*/ = "", const std::string &/* operand3/thread_id (group)*/ = "");	// Convenient.
					
					//const bool enqueue (const cpu::dev &, const opr &, const std::map <std::string, std::string> &/* arg*/, const std::string &/* thread_id*/);
					//const bool enqueue (const std::string &, const std::string &, const std::map <std::string, std::string> &/* arg*/, const std::string &/* thread_id*/);
					
					// do perform execute apply evaluate
					//const bool apply (const instruction &);
					
					// Store
				public:
					virtual const bool exist (const std::string &/* key*/) const;
					virtual const bool exist (const std::string &/* group*/, const std::string &/* key*/) const;
					
					virtual const bool clear (void);
					virtual const bool clear (const std::string &/* group*/);
					
					virtual const bool remove (const std::string &/* group*/, const std::string &/* key*/);
					virtual const bool remove (const std::string &/* key*/);
					
					virtual const std::string/* value*/ get (const std::string &/* group*/, const std::string &/* key*/) const;
					virtual const std::string/* value*/ get (const std::string &/* key*/) const;
					//virtual const std::pair <std::string/* value*/, bool/* reference*/> get (const std::string &/* group*/, const std::string &/* key*/) const;
					//virtual const std::pair <std::string/* value*/, bool/* reference*/> get (const std::string &/* key*/) const;
					
					virtual const bool/* success*/ set (const std::string &/* group*/, const std::string &/* key*/, const std::string &/* content/value*/);
					virtual const bool/* success*/ set (const std::string &/* key*/, const std::string &/* content/value*/);
					//virtual const bool/* success*/ set (const std::string &/* group*/, const std::string &/* key*/, const std::string &/* content/value*/, const bool &/* reference*/ = false);
					//virtual const bool/* success*/ set (const std::string &/* key*/, const std::string &/* content/value*/, const bool &/* reference*/ = false);
					
					
					// /Command Prompt/Terminal/Console/CLI/CUI/TTY/ functionality
					// set
					virtual bool const cout (std::string const &/* value*/);
					// get
					virtual bool const cin (std::string &/* value*/, char const &/* delimiter*/ = '\n');
					
					// evaluate instruction
					//#include ".cpu/val.x86_64.hxx"
					//virtual bool const val (x86_64::instr const &/* instruction*/);
				protected:
					//#include ".cpu/val.x86_64.hxx"
					//#include ".cpu/exe-x86_64.hxx"
					//#include ".cpu/exe-bbj.hxx"
					virtual unsigned int const fetch (unsigned int const &/* address*/) const;
					virtual unsigned int const decode (unsigned int /*instr */const &/* instruction*/);
					//virtual bool const exe (unsigned int /*instr */const &/* instruction*/);
					virtual bool const exe (insn const &/* instruction*/, thread const &);
					
					virtual const bool/* success*/ respond (zmq::msg &/* response*/, const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/);
					virtual const bool/* success*/ search (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/, const cln::nr &/* total, expected resonses count*/, const cln::nr &/* current count of peers who responded (so far)*/, const std::string &/* src*/, const net::cast &/* src_cast*/);// const
					//virtual const bool/* success*/ search_local (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/);// const
					//virtual const zmq::msg/* result*/ aggregate (const zmq::msg &/* result*/, const cln::nr &/* responses_count*//* number of peers who answered*/, const zmq::msg &/* response*/, const zmq::msg &/* expression*/);
				protected:
					// /Process/Find/Search for/ the next instruction on-the-fly.
					// Do not store an instruction queue.
					//std::queue <instruction> queue;
					
					// how many instructions to locally execute, before enqueing into the
					// networked queue, the result of the last executed instruction.
					// valid range: [1 - !fin[ | val is an int
					cln::nr reenqueue_delay;
				protected:
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
