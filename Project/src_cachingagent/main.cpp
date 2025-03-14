#include "DataCacherManager.h"
#include "Common.h"
#include "ExceptionLogger.h"
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char **argv)
{
	std::string ConfigPath="../CachedData";
	mkdir ( ConfigPath.c_str(), S_IRWXU | S_IRWXG | S_IRWXO );
	std::string configFilePath = "../CachedData/Telemetry";
	mkdir ( configFilePath.c_str(), S_IRWXU | S_IRWXG | S_IRWXO );
	chmod( configFilePath.c_str(), S_IRWXU | S_IRWXG | S_IRWXO );
	
	configFilePath = "../CachedData/Alert";
	mkdir ( configFilePath.c_str(), S_IRWXU | S_IRWXG | S_IRWXO );
	chmod( configFilePath.c_str(), S_IRWXU | S_IRWXG | S_IRWXO );
	
	ConfigPath="/root/DataBackup";
	mkdir ( ConfigPath.c_str(), S_IRWXU | S_IRWXG | S_IRWXO );
	configFilePath = "/root/DataBackup/Telemetry";
	mkdir ( configFilePath.c_str(), S_IRWXU | S_IRWXG | S_IRWXO );
	chmod( configFilePath.c_str(), S_IRWXU | S_IRWXG | S_IRWXO );
	
	std::string file_creation = "touch " + configFilePath + "/fmgnmt.txt";
	system(file_creation.c_str());
	
	configFilePath = "/root/DataBackup/Alert";
	mkdir ( configFilePath.c_str(), S_IRWXU | S_IRWXG | S_IRWXO );
	chmod( configFilePath.c_str(), S_IRWXU | S_IRWXG | S_IRWXO );
	
	file_creation = "touch " + configFilePath + "/fmgnmt.txt";
	system(file_creation.c_str());
	
	ExceptionLogger *exceptionLoggerObj = exceptionLoggerObj->GetInstance();
	
	if( exceptionLoggerObj )
	{
		exceptionLoggerObj->Init( CACHING_AGENT_LOG_FILE, "CachingAgent" );
	}
	
	DataCacherManager *dataCacherObj = new DataCacherManager( argv[1], argv[2] );
	
	if( dataCacherObj )
	{
		exceptionLoggerObj->LogInfo("CacherAgent :: Main  Message : DataCacherManager object create successfully");
	}
	else
	{
		exceptionLoggerObj->LogError("CacherAgent :: Main  Message : DataCacherManager object creation failed.");
	}
		
	while(1)
	{
		sleep(1);
	}
	
	if( dataCacherObj )
	{
		delete dataCacherObj;
	}
	
	if( exceptionLoggerObj )
	{
		delete exceptionLoggerObj;
	}

	return 0;
}
