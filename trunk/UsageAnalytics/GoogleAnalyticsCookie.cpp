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
#include "IGoogleAnalyticsParameters.h"
#include "GoogleAnalyticsCookie.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

GoogleAnalyticsCookie::GoogleAnalyticsCookie( const String& identifier, const String& val, 
	const std::vector<CharType>& delimiters ) :
	m_identifier(identifier), m_value(val)
{
	m_delimiters = delimiters;
}

GoogleAnalyticsCookie::GoogleAnalyticsCookie( const String& identifier, const String& val ) :
	m_identifier(identifier), m_value(val)
{
}

GoogleAnalyticsCookie::GoogleAnalyticsCookie( const String& identifier, const String& val, 
	CharType a1 ) : m_identifier(identifier), m_value(val)
{
	m_delimiters.push_back( a1 );
}

GoogleAnalyticsCookie::GoogleAnalyticsCookie( const String& identifier, const String& val, 
	CharType a1, CharType a2 ) :  m_identifier(identifier), m_value(val)
{
	m_delimiters.push_back( a1 );
	m_delimiters.push_back( a2 );
}

GoogleAnalyticsCookie::GoogleAnalyticsCookie( const String& identifier, const String& val, 
	CharType a1, CharType a2, CharType a3 ) :  m_identifier(identifier), m_value(val)
{
	m_delimiters.push_back( a1 );
	m_delimiters.push_back( a2 );
	m_delimiters.push_back( a3 );
}

GoogleAnalyticsCookie::~GoogleAnalyticsCookie()
{
}
