/*
PQntuples Returns the number of tuples (instances) in the query result.
PQnfields Returns the number of fields (attributes) in each tuple of the query result.
PQfname Returns the field (attribute) name associated with the given field index. Field indices start at 0.
PQgetvalue Returns a single field (attribute) value of one tuple of a PGresult. Tuple and field indices start at 0.
PQprint Prints out all the tuples and, optionally, the attribute names to the specified output stream.
PQclear Frees the storage associated with the PGresult. Every query result should be freed via PQclear when it is no longer needed.
*/
#pragma once

#include "stdafx.h"
#include "libpq-fe.h"

class Database{
private:
	const std::string connInfo;//������
	PGconn* conn;
	void closeConn();
	bool connDB();
public:
	Database():conn(NULL),connInfo("port = '5432' dbname = 'osm' user = 'postgres' password = 'wyjcool' "){connDB();}
	~Database(){closeConn();}
	PGresult* execQuery(std::string SQL);
	bool execUpdate(std::string SQL);
};