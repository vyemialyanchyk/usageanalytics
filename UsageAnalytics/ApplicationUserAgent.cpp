/////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2010 Vitali Yemialyanchyk
//
// Distributed under license by Vitali Yemialyanchyk. All rights reserved.
// This program is made available under the terms of the
// MIT License, which accompanies this distribution,
// and is available at http://www.opensource.org/licenses/mit-license.php
//
// Contributor:
//   Vitali Yemialyanchyk - initial API and implementation
//     developer of http://www.stopka.us -> StopKa file manager & desktop search tool
/////////////////////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "ApplicationUserAgent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CharType CApplicationUserAgent::BROWSER_LOCALE_DELIMITER = '-';
CharType CApplicationUserAgent::JAVA_LOCALE_DELIMITER = '_';
String CApplicationUserAgent::USERAGENT_WIN = _T("%s//%s (Windows; U; Windows NT %s; %s)");
CharType CApplicationUserAgent::VERSION_DELIMITER = '.';
String CApplicationUserAgent::PROP_OS_VERSION = _T("os.version");

CApplicationUserAgent::CApplicationUserAgent()
{
}

CApplicationUserAgent::~CApplicationUserAgent()
{
}

String CApplicationUserAgent::createBrowserLanguage()
{
	String nl = getNL();
	if( nl.length() == 0 )
	{
		nl = _T("zz-ZZ");
	}
	size_t nPlace = nl.find( JAVA_LOCALE_DELIMITER, 0 );
	if( nPlace != String::npos )
	{
		nl.replace( nPlace, 1, &BROWSER_LOCALE_DELIMITER );
	}
	return nl;
}

String CApplicationUserAgent::getNL()
{
	CharType strLocaleName[ LOCALE_NAME_MAX_LENGTH ] = {0};
	int i = 0;
	if( i = ::GetUserDefaultLocaleName( strLocaleName, LOCALE_NAME_MAX_LENGTH ) )
	{
		return strLocaleName;
	}
	// return undef locale by default
	return _T("zz-ZZ");
}

String CApplicationUserAgent::getBrowserLanguage()
{
	if( m_browserLanguage.length() == 0 )
	{
		m_browserLanguage = createBrowserLanguage();
	}
	return m_browserLanguage;
}

String CApplicationUserAgent::toString()
{
	const String productId = getApplicationName();
	const String productVersion = getApplicationVersion();
	// Google API for android: this.userAgent = String.format(
	// "GoogleAnalytics/%s (Linux; U; Android %s; %s-%s; %s; Build/%s)" ,
	// new Object[] { "1.0" , Build.VERSION.RELEASE ,
	// (localLocale.getLanguage() != null) ?
	// localLocale.getLanguage().toLowerCase() : "en" ,
	// (localLocale.getCountry() != null) ?
	// localLocale.getCountry().toLowerCase() : "" , Build.MODEL, Build.ID
	// });
	const String userAgentPattern = getUserAgentPattern( getOS() );
	const String osVersion = getOSVersion();
	const String browserLanguage = getBrowserLanguage();
	const size_t n = 1024 + userAgentPattern.length() + productId.length() +
		productVersion.length() + osVersion.length() + browserLanguage.length();
	String res;
	res.reserve( n );
	res.resize( n );
	const int i = _stprintf_s( const_cast<CharType*>( res.c_str() ), n, userAgentPattern.c_str(), 
		productId.c_str(), productVersion.c_str(), osVersion.c_str(), browserLanguage.c_str() );
	res.resize( i );
	return res;
}

String CApplicationUserAgent::getOS()
{
	return _T("Windows");
}

String CApplicationUserAgent::getOSVersion()
{
	OSVERSIONINFO osvi;
	ZeroMemory( &osvi, sizeof(OSVERSIONINFO) );
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	::GetVersionEx( &osvi );
	const size_t n = 1024;
	String res;
	res.reserve( n );
	res.resize( n );
	const int i = _stprintf_s( const_cast<CharType*>( res.c_str() ), n, _T("%d.%d (%d)"), 
		osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber );
	res.resize( i );
	return res;
}

String CApplicationUserAgent::getUserAgentPattern( const String& os )
{
	String userAgentPattern( _T("") );
	if( 0 == CompareLowStrings_( os, _T("Windows") ) )
	{
		return USERAGENT_WIN;
	}
	return userAgentPattern;
}

String CApplicationUserAgent::getApplicationName()
{
	return _T("StopKa");
}

String CApplicationUserAgent::getApplicationVersion()
{
	// TODO: get application version from one place
	return _T("1.5");
}
