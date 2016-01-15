# UsageAnalytics
The project includes a sources of library that provide capability to anonymously reports information back to the library user.
The library was developed using C++ as a basic language. The main intention of the library is a use in the desktop applications. 
StopKa file manager & desktop search tool (http://www.stopka.us) is an example application which is track it's usage using the library.

The library use example:
```C++
UINT UsageReportExec( LPVOID pParam )
{
#ifdef _USAGEANALYTICS
	UsageReport usageReport( &( UsageAnalyticsAppPreferences::getInstance() ) );
	usageReport.report();
#endif
	return 0;
}
```
