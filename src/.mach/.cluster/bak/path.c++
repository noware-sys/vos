#include "member.h++"

const bool LIB::cluster::paths::default_journal_maximum_limit = true;
const LIB::mathematics::numbers::natural LIB::cluster::paths::default_journal_maximum = 20;

LIB::cluster::paths::paths (void)
{
	journal_limit_maximum = default_journal_limit_maximum;
	journal_maximum = defaul_journal_maximum;
	
	if (db.connect (":memory:"))
	{
		/*
			PRAGMA foreign_keys = true;
			
			CREATE TABLE IF NOT EXISTS `Latencies`
			(
				`Endpoint` none NOT NULL
				,
				`Value` none NULL
				,
				`Time` none NOT NULL
			)
			;
			
			CREATE VIEW IF NOT EXISTS "Paths" AS
				SELECT
					`Endpoint`,
					AVG (`Value`)
						AS 'Value'
				FROM
					`Latencies`
					
					GROUP BY
						`Endpoint`
			;
		*/
		db.query ("PRAGMA foreign_keys = true");
		
		db.query ("CREATE TABLE `Latencies`\
			(\
				`Endpoint` none NOT NULL\
				,\
				`Value` none NOT NULL\
				,\
				`Time` none NOT NULL\
			)");
		
		db.query ("CREATE VIEW IF NOT EXISTS `Paths` AS\
			SELECT\
				`Endpoint`,\
				AVG (`Value`)\
					AS 'Value'\
			FROM\
				`Latencies`\
				\
				GROUP BY\
					`Endpoint`");
	}
}
/*
LIB::cluster::paths::paths (const LIB::cluster::paths & other)
{
	//operator = (other);
}
*/
LIB::cluster::paths::~ paths (void)
{}

template <typename archive>
void LIB::cluster::paths::serialize (archive & arch, const unsigned int & version)
{
	//arch & db;
}
/*
template <typename archive>
void LIB::cluster::paths::save (archive & arch, const unsigned int & version) const
{}

template <typename archive>
void LIB::cluster::paths::load (archive & arch, const unsigned int & version)
{}
*/
const LIB::cluster::paths & LIB::cluster::paths::operator = (const LIB::cluster::paths & other)
{
	return *this;
}

const bool LIB::cluster::paths::operator == (const LIB::cluster::paths & other) const
{
	return this == & other || db == other.db;
}

const LIB::mathematics::numbers::natural LIB::cluster::paths::size (const std::string & endpoint) const
{
	LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	
	arguments.append (endpoint);
	
	if (! db.query (result, "SELECT COUNT (*) FROM `Latencies` WHERE `Endpoint` = ?", arguments))
		return 0;
	
	return result [1/*First row.*/] [1/*First column.*/];
}

const bool LIB::cluster::paths::reduce (const std::string & endpoint)
{
	//LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	
	arguments.append (endpoint);
	arguments.append (endpoint);
	
	return db.query (/*result, */"DELETE FROM `Latencies` WHERE `Endpoint` = ? AND `Time` = (SELECT MIN (`Time`) FROM `Latencies` WHERE `Endpoint` = ?)", arguments);
}

const bool LIB::cluster::paths::add (const std::string & endpoint, const LIB::mathematics::numbers::natural & latency)
{
	if (size (endpoint) >= journal_maximum)
		reduce (endpoint);
	
	//LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
	LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	
	arguments.append (endpoint);
	arguments.append (latency);
	
	return db.query (/*result, */"INSERT INTO `Latencies` (`Endpoint`, `Latency`, `Time`) VALUES (?, ?, strftime ('%Y/%m/%d %H:%M:%S', 'now'))", arguments);
}

const std::string optimal (void) const
{
	LIB::containers::NAME_A <LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V>, LIB::containers::NAME_V> result;
	//LIB::containers::NAME_A <LIB::containers::NAME_V, LIB::containers::NAME_V> arguments;
	
	//arguments.append (endpoint);
	
	if (! db.query (result, "SELECT `Endpoint` FROM `Latencies` WHERE `Value` = (SELECT MIN (`VALUE`) FROM `Latencies` WHERE `Value` IS NOT NULL) LIMIT 1"/*, arguments*/))
		return "";
	
	return result [1/*First row.*/] [1/*First column.*/];
}
