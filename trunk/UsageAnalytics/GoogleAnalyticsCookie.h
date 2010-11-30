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

class GoogleAnalyticsCookie
{
protected:
	String m_value;
	String m_identifier;
	std::vector<CharType> m_delimiters;
public:
	GoogleAnalyticsCookie( const String& identifier, const String& val, const std::vector<CharType>& delimiters );
	GoogleAnalyticsCookie( const String& identifier, const String& val );
	GoogleAnalyticsCookie( const String& identifier, const String& val, CharType a1 );
	GoogleAnalyticsCookie( const String& identifier, const String& val, CharType a1, CharType a2 );
	GoogleAnalyticsCookie( const String& identifier, const String& val, CharType a1, CharType a2, CharType a3 );
	virtual ~GoogleAnalyticsCookie();
	// Appends the identifier and the value of this cookie to the given
	// <code>StringBuilder</code>. If no value is present <code>null</code>,
	// nothing is appended.
	// @param builder
	//            the builder
	void appendTo( String& builder )
	{
		if( m_identifier.length() > 0 && m_value.length() > 0 )
		{
			builder += m_identifier;
			builder += IGoogleAnalyticsParameters::EQUALS_SIGN;
			builder += m_value;
			for( size_t i = 0; i < m_delimiters.size(); i++ )
			{
				builder += m_delimiters[ i ];
			}
		}
	}
};
