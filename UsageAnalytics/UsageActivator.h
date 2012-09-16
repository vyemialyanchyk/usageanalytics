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

class IApplicationEnvironment;
class IUsageBranding;
class IStopKaEnvironment;
class IGoogleAnalyticsParameters;
class IApplicationPreferences;

class CUsageActivator
{
protected:
	IApplicationEnvironment* m_pApplicationEnvironment;
	//
	IUsageBranding* m_pBranding;
	//
	CUsageActivator();
	virtual ~CUsageActivator();
public:
	static CUsageActivator& getInstance()
	{
		static CUsageActivator _UsageActivator;
		return _UsageActivator;
	}
	//
	IStopKaEnvironment* getStopKaEnvironment( IApplicationPreferences* pAppPrefs = 0 );
	//
	IApplicationEnvironment* getApplicationEnvironment( IApplicationPreferences* pAppPrefs = 0 );
	//
	IGoogleAnalyticsParameters* getGoogleAnalyticsParameters( IApplicationPreferences* pAppPrefs = 0 );
	//
	IUsageBranding* getUsageBranding();
};
