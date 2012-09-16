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

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclude rarely-used stuff from Windows headers
#endif

#include <afx.h>
#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC support for Internet Explorer 4 Common Controls
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <iostream>

#include <limits>
#include <string>
#include <vector>
#include <map>

#include <atlhttp.h>

#ifdef _UNICODE
typedef std::wstring       String;
#else
typedef std::string        String;
#endif

// StringW - строки unicode
typedef std::wstring       StringW;
// StringA - строки обычные
typedef std::string        StringA;

typedef String::value_type CharType;
typedef StringA::value_type CharTypeA;
typedef StringW::value_type CharTypeW;

inline String UIntToString_( unsigned int nNum )
{
	CharType pstr[ 30 ];
	_stprintf_s( pstr, 30, _T("%u"), nNum );
	return String( pstr );
}

#ifdef max
#undef max
#endif

inline unsigned int StrToUInt_( const String& str )
{
	unsigned int nRet = std::numeric_limits<unsigned int>::max();
	if( !_stscanf_s( str.c_str(), _T("%d"), &nRet ) ) nRet = std::numeric_limits<unsigned int>::max();
	return nRet;
}

inline int CompareStrings_( const String& str1, const String& str2 )
{
	return _tcscoll( str1.c_str(), str2.c_str() );
	//return _tcscmp( str1.c_str(), str2.c_str() );
}

inline int CompareLowStrings_( const String& str1, const String& str2 )
{
	return _tcsicoll( str1.c_str(), str2.c_str() );
	//return _tcsicmp( str1.c_str(), str2.c_str() );
}

inline String GetToken_( const String& strLine, String::size_type& start, const CharType delimiters[] )
{
	if( start >= strLine.length() )
	{
		return _T("");
	}
	String::size_type index1, index2;
	index1 = strLine.find_first_not_of( delimiters, start );
	if( String::npos == index1 )
	{
		start = strLine.length();
		return _T("");
	}
	index2 = strLine.find_first_of( delimiters, index1 );
	if( String::npos == index2 )
	{
		index2 = strLine.length();
		start = index2;
	}
	else
	{
		start = index2 + 1;
	}
	return strLine.substr( index1, index2 - index1 );
}

inline void Trim_( String& strLine )
{
	const CharType delimiters[] = _T("\n\t\r\f\v ");
	String::size_type indexFirst = strLine.find_first_not_of( delimiters );
	String::size_type indexLast = strLine.find_last_not_of( delimiters );
	if( indexFirst == String::npos )
	{
		indexFirst = 0;
	}
	if( indexLast == String::npos )
	{
		indexLast = strLine.length();
	}
	else
	{
		indexLast++;
	}
	strLine = strLine.substr( indexFirst, indexLast );
}
