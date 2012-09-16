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
#include "UsageActivator.h"
#include "IApplicationEnvironment.h"
#include "IUsageBranding.h"
#include "IStopKaEnvironment.h"
#include "UsageBranding.h"
#include "StopKaEnvironment.h"
#include "ApplicationPreferences.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CUsageActivator::CUsageActivator() : m_pApplicationEnvironment(0), m_pBranding(0)
{
}

CUsageActivator::~CUsageActivator()
{
	if( m_pApplicationEnvironment )
	{
		delete m_pApplicationEnvironment;
		m_pApplicationEnvironment = 0;
	}
	if( m_pBranding )
	{
		delete m_pBranding;
		m_pBranding = 0;
	}
}

IStopKaEnvironment* CUsageActivator::getStopKaEnvironment( IApplicationPreferences* pAppPrefs )
{
	if( m_pApplicationEnvironment == 0 )
	{
		if( pAppPrefs == 0 )
		{
			ApplicationPreferences& ap = ApplicationPreferences::getInstance();
			ap.setFilePath( _T("ap.txt") );
			ap.fileLoad();
			pAppPrefs = &( ap );
		}
		IUsageBranding* pBranding = getUsageBranding();
		m_pApplicationEnvironment = new StopKaEnvironment(
			pBranding->getGoogleAnalyticsAccount(), pBranding->getGoogleAnalyticsReportingHost(), pAppPrefs );
	}
	return dynamic_cast<IStopKaEnvironment*>( m_pApplicationEnvironment );
}

IApplicationEnvironment* CUsageActivator::getApplicationEnvironment( IApplicationPreferences* pAppPrefs )
{
	getStopKaEnvironment( pAppPrefs );
	return m_pApplicationEnvironment;
}

IGoogleAnalyticsParameters* CUsageActivator::getGoogleAnalyticsParameters( IApplicationPreferences* pAppPrefs )
{
	getStopKaEnvironment( pAppPrefs );
	return dynamic_cast<IGoogleAnalyticsParameters*>( m_pApplicationEnvironment );
}

IUsageBranding* CUsageActivator::getUsageBranding()
{
	if( 0 == m_pBranding )
	{
		m_pBranding = new UsageBranding();
	}
	return m_pBranding;
}
