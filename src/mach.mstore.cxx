#pragma once

//#include <thread>

// #include <assert.h>

//#include <boost/function.hpp>
////#include <boost/function_equal.hpp>
//#include <boost/bind.hpp>

#include <boost/thread.hpp>

// #include <omp.h>

#include "mach.hxx"

//#include "array.txx"
// #include "var.cxx"
// #include <zmq/msg.cxx>
//#include "nr.cxx"
//#include "container/list/sqlite.cxx"
//#include ".mach/.incl.cxx"
//#include ".mach/.cxx"
#include "mmach/store.cxx"
//#include "mach/store.cxx"
//#include "mach/store.cxx"

noware::mach::mach (void)
{
	/*
	thread * t;
	
	t = new thread ();
	
	trd [t -> group ()] = t;
	*/
	
	
	//cpu.activate ();
	
	
	unsigned int n;
	
	mmach::store * s;
	//queue * q;
	//cpu * p;	// processor
	
	
	//n = boost::thread::hardware_concurrency ();
	n = 1;
	
	#pragma omp parallel
	{
		#pragma omp for
		for (unsigned int ndx = 1; ndx <= n; ++ndx)
		{
			
			#pragma omp critical
			{
				s = &_mstore [ndx];
				
				assert (s -> init ());
				assert (s -> enable ());
				assert (s -> start ());
				//assert (s -> running ());
			}
			
			/*
			#pragma omp critical
			{
				q = &_queue [ndx];
				
				assert (q -> init ());
				assert (q -> enable ());
				assert (q -> start ());
				assert (q -> running ());
			}
			*/
			/*
			#pragma omp critical
			{
				p = &_cpu [ndx];
				
				assert (p -> init ());
				assert (p -> enable ());
				assert (p -> start ());
				assert (p -> running ());
				assert (p -> node.join (noware::mach::cpu::grp_dft));
			}
			*/
		}
	}
	
	
	/*
	assert (s1.init ());
	assert (s1.enable ());
	assert (s1.start ());
	assert (s1.running ());
	
	assert (s2.init ());
	assert (s2.enable ());
	assert (s2.start ());
	assert (s2.running ());
	
	
	assert (q1.init ());
	assert (q1.enable ());
	assert (q1.start ());
	assert (q1.running ());
	
	assert (q2.init ());
	assert (q2.enable ());
	assert (q2.start ());
	assert (q2.running ());
	
	
	assert (p1.init ());
	assert (p1.enable ());
	assert (p1.start ());
	assert (p1.running ());
	assert (p1.node.join (noware::mach::cpu::grp_dft));
	
	assert (p2.init ());
	assert (p2.enable ());
	assert (p2.start ());
	assert (p2.running ());
	assert (p2.node.join (noware::mach::cpu::grp_dft));
	*/
	
	/*
	assert (_cpu [2].init ());
	assert (_cpu [2].enable ());
	assert (_cpu [2].start ());
	assert (_cpu [2].running ());
	assert (_cpu [2].node.join (noware::mach::cpu::grp_dft));
	*/
	
}

noware::mach::~mach (void)
{
	//delete
}
