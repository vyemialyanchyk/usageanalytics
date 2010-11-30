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
#include "AbstractGoogleAnalyticsParameters.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

AbstractGoogleAnalyticsParameters::AbstractGoogleAnalyticsParameters( 
	const String& accountName, const String& hostName, const String& referral ) :
	IGoogleAnalyticsParameters(),
	m_accountName(accountName), m_hostName(hostName), m_referral(referral), m_userDefined(_T(""))
{
}

AbstractGoogleAnalyticsParameters::AbstractGoogleAnalyticsParameters( 
	const String& accountName, const String& hostName, const String& referral, const String& userDefined ) :
	IGoogleAnalyticsParameters(),
	m_accountName(accountName), m_hostName(hostName), m_referral(referral), m_userDefined(userDefined)
{
}

AbstractGoogleAnalyticsParameters::~AbstractGoogleAnalyticsParameters()
{
}
