#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include "processor.hpp"

// Platform.

LIB::cluster::processor::instruction::instruction (void)
{
	inputs [0] = inputs [1] = 0;
}

LIB::cluster::processor::platform::platform (void)
{
	run (false);
}

void LIB::cluster::processor::platform::run (const bool value)
{
	{
        boost::unique_lock <boost::mutex> lock (running_mutex);
		running = value;
    }

    running_condition_variable.notify_all ();
}

void LIB::cluster::processor::platform::pause (void)
{
	boost::unique_lock <boost::mutex> lock (running_mutex);

	while (!running)
	{
		running_condition_variable.wait (lock);
	}
}

// Processor.

LIB::cluster::processor::processor (void)
{
	// Create the threads.

	//boost::thread * thread = new boost::thread (boost::bind (LIB::cluster::processor::initialize, this));

	//threads [thread -> get_id ()].thread = thread;
	//threads [boost::this_thread::get_id ()].queue
	//threads.enqueue ();
	mathematics::numbers::natural n = 1;

	//for (mathematics::numbers::natural i = 0; i < n; ++ i)
	//{
	//	threads [i].thread = new boost::thread (boost::bind (LIB::cluster::processor::_do, this));
	//}
}

LIB::cluster::processor::~processor (void)
{

}

//bool LIB::cluster::processor::enqueue (const LIB::cluster::processor::instruction _instruction)
//{
//	/*
//		Assign the instruction to a random processor;
//		this means to add it to the random processor's instruction queue.
//	*/
//
//	boost::thread::id id = boost::this_thread::get_id ();	// Select a random processor from the avaiable ones.
//	LIB::cluster::processor::platform * platform = & threads [id];	// Prevent searching through the array again; this may increase performance.
//
//	if (platform -> queue.enqueue (_instruction))
//	{
//		platform -> run (true);
//
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}

// Each processor would be executing this for the duration of the this object, when there are instructions to be run.
//void LIB::cluster::processor::run (void)
//{
//	/*
//		This is the concept:
//
//		While there are instructions to be performed, perform them;
//		otherwise, wait (preferably, without consuming any resources) for any instruction to come.
//	*/
//
//	boost::thread::id id = boost::this_thread::get_id ();	// Select a random processor from the avaiable ones.
//	LIB::cluster::processor::platform * platform = & threads [id];	// Prevent searching through the array again; this may increase performance.
//
//	while (! platform -> queue.empty ())
//	{
//		_do (platform -> queue.current ());
//
//		platform -> queue.dequeue ();
//	}
//}

LIB::mathematics::numbers::real LIB::cluster::processor::_do (const LIB::cluster::processor::instruction _instruction) const
{
	switch (_instruction._operation)
	{
		case LIB::cluster::processor::operation::add:
			return _instruction.inputs [0] + _instruction.inputs [1];
		case LIB::cluster::processor::operation::substract:
			return _instruction.inputs [0] - _instruction.inputs [1];
		case LIB::cluster::processor::operation::multiply:
			return _instruction.inputs [0] * _instruction.inputs [1];
		case LIB::cluster::processor::operation::divide:
			return _instruction.inputs [0] / _instruction.inputs [1];
		default:
			return LIB::mathematics::numbers::default;
	}
}

//LIB::mathematics::numbers::real LIB::cluster::processor::Do (const LIB::cluster::processor::instruction _instruction) const
//{
//	switch (_instruction._operation)
//	{
//		case LIB::cluster::processor::operation::add:
//			return _instruction.inputs [0] + _instruction.inputs [1];
//		case LIB::cluster::processor::operation::substract:
//			return _instruction.inputs [0] - _instruction.inputs [1];
//		case LIB::cluster::processor::operation::multiply:
//			return _instruction.inputs [0] * _instruction.inputs [1];
//		case LIB::cluster::processor::operation::divide:
//			return _instruction.inputs [0] / _instruction.inputs [1];
//		default:
//			return LIB::mathematics::numbers::default;
//	}
//}
