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

class IFocusPoint;
class IStopKaEnvironment;
class IApplicationEnvironment;
class IGoogleAnalyticsParameters;
class IApplicationPreferences;

class UsageReport
{
protected:
	//
	IFocusPoint* m_pFocusPoint;
	//
	IStopKaEnvironment* m_pStopKaEnvironment;
	//
	IApplicationEnvironment* m_pApplicationEnvironment;
	//
	IGoogleAnalyticsParameters* m_pGoogleAnalyticsParameters;
	//
	IApplicationPreferences* m_pAppPrefs;
public:
	UsageReport();
	UsageReport( IApplicationPreferences* pAppPrefs );
	virtual ~UsageReport();

	void report()
	{
		doReport();
	}

private:
	// Reports the usage of the current StopKa installation.
	void doReport();
};