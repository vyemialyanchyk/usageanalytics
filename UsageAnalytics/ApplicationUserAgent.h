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

#include "IApplicationUserAgent.h"

class CApplicationUserAgent : public IApplicationUserAgent
{
public:
	CApplicationUserAgent();
	virtual ~CApplicationUserAgent();

public:
	static CharType BROWSER_LOCALE_DELIMITER;

	static CharType JAVA_LOCALE_DELIMITER;

	static String USERAGENT_WIN;

	static CharType VERSION_DELIMITER;

	static String PROP_OS_VERSION;

protected:
	String m_browserLanguage;

public:
	String createBrowserLanguage();

	String getNL();

	String getBrowserLanguage();

	String toString();

	String getOS();

	String getOSVersion();

	String getUserAgentPattern( const String& os );

	String getApplicationName();

	String getApplicationVersion();
};
