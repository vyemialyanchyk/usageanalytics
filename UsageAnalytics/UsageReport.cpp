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
#include "IStopKaEnvironment.h"
#include "UsageReport.h"
#include "UsageActivator.h"
#include "SuffixFocusPoint.h"
#include "GoogleAnalyticsUrlStrategy.h"
#include "Tracker.h"
#include "IApplicationEnvironment.h"
#include "IGoogleAnalyticsParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

UsageReport::UsageReport()
{
	m_pStopKaEnvironment = CUsageActivator::getInstance().getStopKaEnvironment();
	m_pApplicationEnvironment = CUsageActivator::getInstance().getApplicationEnvironment();
	m_pGoogleAnalyticsParameters = CUsageActivator::getInstance().getGoogleAnalyticsParameters();
	m_pFocusPoint = new SuffixFocusPoint( _T("StopKa"), m_pStopKaEnvironment->getStopKaVersion() );
	IFocusPoint* pFocusPoint = 0;
	pFocusPoint = m_pFocusPoint->setChild( new FocusPoint( _T("usageanalytics") ) );
	pFocusPoint = pFocusPoint->setChild( new FocusPoint( _T("test") ) );
	pFocusPoint = pFocusPoint->setChild( new FocusPoint( _T("startup") ) );
}

UsageReport::~UsageReport()
{
	delete m_pFocusPoint;
	m_pFocusPoint = 0;
}

void UsageReport::doReport()
{
	IURLBuildingStrategy* pUrlBuildingStrategy = new GoogleAnalyticsUrlStrategy( m_pGoogleAnalyticsParameters );
	ITracker* pTracker = new Tracker( pUrlBuildingStrategy, m_pGoogleAnalyticsParameters->getUserAgent() );
	pTracker->trackFocusPoint( m_pFocusPoint );
	delete pTracker;
	delete pUrlBuildingStrategy;
}
