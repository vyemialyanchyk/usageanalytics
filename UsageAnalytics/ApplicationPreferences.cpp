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
#include "ApplicationPreferences.h"
#include "StdioFileEx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

ApplicationPreferences::ApplicationPreferences()
{
}

ApplicationPreferences::~ApplicationPreferences()
{
}

ApplicationPreferences& ApplicationPreferences::getInstance()
{
	static ApplicationPreferences _ApplicationPreferences;
	return _ApplicationPreferences;
}

void ApplicationPreferences::cleanUp()
{
	m_mapPropVal.clear();
}

bool ApplicationPreferences::setFilePath( const String& strFilePath )
{
	if( 0 == CompareLowStrings_( m_strFilePath, strFilePath ) )
	{
		return false;
	}
	m_strFilePath = strFilePath;
	cleanUp();
	return true;
}

void ApplicationPreferences::put( const String& name, const String& val )
{
	std::map<String, String>::iterator itEnd = m_mapPropVal.end();
	std::map<String, String>::iterator it = m_mapPropVal.find( name.c_str() );
	if( it == itEnd )
	{
		m_mapPropVal.insert( std::pair<String, String>( name, val ) );
	}
	else
	{
		it->second = val.c_str();
	}
}

void ApplicationPreferences::put( const String& name, const unsigned long& val )
{
	put( name, UIntToString_( val ) );
}

String ApplicationPreferences::get( const String& name, const String& defaultVal )
{
	std::map<String, String>::iterator it = m_mapPropVal.find( name );
	if( it == m_mapPropVal.end() )
	{
		return defaultVal;
	}
	return it->second;
}

String ApplicationPreferences::get( const String& name )
{
	return get( name, _T("") );
}

unsigned long ApplicationPreferences::getULong( const String& name, const unsigned long& defaultVal )
{
	const String strRes( get( name, UIntToString_( defaultVal ) ) );
	return StrToUInt_( strRes );
}

void saveStringParam( CStdioFileEx& file, const String& name, const String& val )
{
	file.WriteString( ( name + _T("=") + val + sNEWLINE ).c_str() );
}

bool ApplicationPreferences::fileSave()
{
	CStdioFileEx file;
	if( !file.Open( m_strFilePath.c_str(), CFile::modeCreate | CFile::modeWrite | 
		CFile::typeText | CStdioFileEx::modeWriteUnicode ) )
	{
		return false;
	}
	std::map<String, String>::iterator it = m_mapPropVal.begin();
	std::map<String, String>::iterator itEnd = m_mapPropVal.end();
	for( ; it != itEnd; ++it )
	{
		saveStringParam( file, it->first, it->second );
	}
	return true;
}

bool ApplicationPreferences::fileLoad()
{
	cleanUp();
	CStdioFileEx file;
	if( !file.Open( m_strFilePath.c_str(), CFile::modeRead | CFile::typeText ) )
	{
		return false;
	}
	String str;
	CString strTmp;
	while( file.ReadString( strTmp ) )
	{
		strTmp = strTmp.Trim();
		if( strTmp.GetLength() == 0 )
		{
			continue;
		}
		str = LPCTSTR( strTmp );
		const CharType delimiters[] = _T("=");
		String::size_type start = 0;
		String strToken0 = GetToken_( str, start, delimiters );
		String strToken1 = GetToken_( str, start, delimiters );
		Trim_( strToken0 );
		Trim_( strToken1 );
		put( strToken0, strToken1 );
	}
	return true;
}
