/*
#include <string>

#include "../../../../name.h++"
#include "../../../../mathematics.h++"
#include "../../../../container/database/sqlite.h++"
*/
/*
namespace lib
{
	namespace machine
	{
		namespace resource
		{
			namespace processor
			{
*/				class program
				{
					public:
						#include ".program/index.h++"
						
						//program (void);
						//program (const std::string &/* file name/code?*/);
						//program (const processor::instructions &, const bool &/* parallel*/ = false);
						//virtual ~ program (void);
						
						//virtual const bool enqueue (const std::string &/* file/code?*/);
						//virtual const bool enqueue (const processor::instructions &, const bool &/* parallel*/ = false);
						//virtual const processor::instructions dequeue (const mathematics::numbers::natural & = 1);
						virtual const LIB::mathematics::numbers::natural size (void) const;
						
					protected:
						//LIB::container::entity_2 queue;
						
					public:
						#include ".program/postinnerindex.h++"
				};
/*			}
		}
	}
}
*/

#include ".program/postindex.h++"

