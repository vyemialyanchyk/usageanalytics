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
#include "IApplicationPreferences.h"
#include "AbstractApplicationEnvironment.h"
#include "ApplicationUserAgent.h"
#include "IUsageReportPreferenceConstants.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

AbstractApplicationEnvironment::AbstractApplicationEnvironment( 
	const String& accountName, const String& hostName, IApplicationPreferences* pPreferences ) :
		AbstractGoogleAnalyticsParameters( accountName, hostName, IGoogleAnalyticsParameters::VALUE_NO_REFERRAL ),
		IApplicationEnvironment(),
		m_pPreferences(pPreferences)
{
	srand( (unsigned)time( 0 ) );
	m_pApplicationUserAgent = new CApplicationUserAgent();
	initScreenSettings();
	initVisits();
}

AbstractApplicationEnvironment::AbstractApplicationEnvironment(
	const String& accountName, const String& hostName, const String& referral,
	IApplicationPreferences* pPreferences ) : 
		AbstractGoogleAnalyticsParameters( accountName, hostName, referral ),
		IApplicationEnvironment(),
		m_pPreferences(pPreferences)
{
	srand( (unsigned)time( 0 ) );
	m_pApplicationUserAgent = new CApplicationUserAgent();
	initScreenSettings();
	initVisits();
}

AbstractApplicationEnvironment::~AbstractApplicationEnvironment()
{
	if( m_pApplicationUserAgent )
	{
		delete m_pApplicationUserAgent;
		m_pApplicationUserAgent = 0;
	}
}

void AbstractApplicationEnvironment::initScreenSettings()
{
	RECT screen_rect;
	HWND hWnd = ::GetDesktopWindow();
	::GetWindowRect( hWnd, &screen_rect ); 
	HDC hDC = ::GetWindowDC( ::GetDesktopWindow() );
	//unsigned int nWidth = screen_rect.right - screen_rect.left;
	//unsigned int nHeight = screen_rect.bottom - screen_rect.top;
	unsigned int nWidth = ::GetDeviceCaps( hDC, HORZRES ); //horizontal resolution
	unsigned int nHeight = ::GetDeviceCaps( hDC, VERTRES ); //vertical resolution
	unsigned int n = ::GetDeviceCaps( hDC, BITSPIXEL ) * ::GetDeviceCaps( hDC, PLANES );
	m_screenColorDepth = UIntToString_( n ) + SCREENCOLORDEPTH_POSTFIX;
	::ReleaseDC( hWnd, hDC );
	m_screenResolution = UIntToString_( nWidth ) + SCREERESOLUTION_DELIMITER + UIntToString_( nHeight );
}

void AbstractApplicationEnvironment::initVisits()
{
	clock_t nTime = clock();
	String currentTime = UIntToString_( nTime );
	m_currentVisit = currentTime;
	m_firstVisit = m_pPreferences->get( IUsageReportPreferenceConstants::FIRST_VISIT, _T("") );
	if( m_firstVisit.length() == 0 )
	{
		m_firstVisit = currentTime;
		m_pPreferences->put( IUsageReportPreferenceConstants::FIRST_VISIT, m_firstVisit );
	}
	m_lastVisit = m_pPreferences->get( IUsageReportPreferenceConstants::LAST_VISIT, currentTime );
	m_visitCount = m_pPreferences->getULong( IUsageReportPreferenceConstants::VISIT_COUNT, 1 );
}

String AbstractApplicationEnvironment::getBrowserLanguage()
{
	return m_pApplicationUserAgent->getBrowserLanguage();
}

String AbstractApplicationEnvironment::getScreenResolution()
{
	return m_screenResolution;
}

String AbstractApplicationEnvironment::getScreenColorDepth()
{
	return m_screenColorDepth;
}

String AbstractApplicationEnvironment::getUserAgent()
{
	return m_pApplicationUserAgent->toString();
}

String AbstractApplicationEnvironment::getUserId()
{
	String userId = m_pPreferences->get( IUsageReportPreferenceConstants::APPLICATION_INSTANCE_ID, _T("") );
	if( userId.length() == 0 )
	{
		userId = createIdentifier();
		m_pPreferences->put( IUsageReportPreferenceConstants::APPLICATION_INSTANCE_ID, userId );
		//UsageReportPreferencesUtils.checkedSavePreferences(
		//	m_pPreferences, JBossToolsUsageActivator.getDefault(),
		//	GoogleAnalyticsEclipseMessages.EclipseEnvironment_Error_SavePreferences);
		m_pPreferences->fileSave();
	}
	return userId;
}

String AbstractApplicationEnvironment::createIdentifier()
{
	String builder;
	String randStr = UIntToString_( rand() );
	builder += randStr;
	clock_t nTime = clock();
	String currentTime = UIntToString_( nTime );
	builder += currentTime;
	return builder;
}

String AbstractApplicationEnvironment::getCurrentVisit()
{
	return m_currentVisit;
}

String AbstractApplicationEnvironment::getFirstVisit()
{
	return m_firstVisit;
}

String AbstractApplicationEnvironment::getLastVisit()
{
	return m_lastVisit;
}

unsigned long AbstractApplicationEnvironment::getVisitCount()
{
	return m_visitCount;
}

void AbstractApplicationEnvironment::visit()
{
	m_lastVisit = m_currentVisit;
	m_pPreferences->put( IUsageReportPreferenceConstants::LAST_VISIT, m_lastVisit );
	clock_t nTime = clock();
	String currentTime = UIntToString_( nTime );
	m_currentVisit = currentTime;
	m_visitCount++;
	m_pPreferences->put( IUsageReportPreferenceConstants::VISIT_COUNT, m_visitCount );
	//UsageReportPreferencesUtils.checkedSavePreferences(m_pPreferences, JBossToolsUsageActivator.getDefault(),
	//	GoogleAnalyticsEclipseMessages.EclipseEnvironment_Error_SavePreferences);
	m_pPreferences->fileSave();
}

String AbstractApplicationEnvironment::getFlashVersion()
{
	// some additional info instead of google analytics flash version
	//return getJavaVersion();
	return _T("0");
}

IApplicationUserAgent* AbstractApplicationEnvironment::getApplicationUserAgent()
{
	return m_pApplicationUserAgent;
}

String AbstractApplicationEnvironment::getUserDefined()
{
	//return getLinuxDistroNameAndVersion();
	return _T("0");
}
