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
public:
	UsageReport();
	virtual ~UsageReport();

	void report()
	{
		doReport();
	}

private:
	// Reports the usage of the current StopKa installation.
	void doReport();
};