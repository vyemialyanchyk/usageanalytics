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

#include "AbstractGoogleAnalyticsParameters.h"
#include "IApplicationEnvironment.h"

class IApplicationUserAgent;
class IApplicationPreferences;

class AbstractApplicationEnvironment : public AbstractGoogleAnalyticsParameters, public IApplicationEnvironment
{
public:
	AbstractApplicationEnvironment( const String& accountName, const String& hostName, 
		const String& referral, IApplicationPreferences* pPreferences );
	AbstractApplicationEnvironment( const String& accountName, const String& hostName, 
		IApplicationPreferences* pPreferences );
	virtual ~AbstractApplicationEnvironment();

protected:
	String m_screenResolution;
	String m_screenColorDepth;
	IApplicationPreferences* m_pPreferences;
	String m_firstVisit;
	String m_lastVisit;
	String m_currentVisit;
	unsigned long m_visitCount;
	IApplicationUserAgent* m_pApplicationUserAgent;

public:
	void initScreenSettings();

	void initVisits();

	String getBrowserLanguage();

	String getScreenResolution();

	String getScreenColorDepth();

	String getUserAgent();

	String getUserId();

	// Creates an unique identifier.
	// @return the identifier
	String createIdentifier();

	virtual String getKeyword() = 0;

	String getCurrentVisit();

	String getFirstVisit();

	String getLastVisit();

	unsigned long getVisitCount();

	void visit();

	String getFlashVersion();

	IApplicationUserAgent* getApplicationUserAgent();

	String getUserDefined();
};
