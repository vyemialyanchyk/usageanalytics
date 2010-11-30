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

#include "IGoogleAnalyticsParameters.h"

class AbstractGoogleAnalyticsParameters : public IGoogleAnalyticsParameters
{
protected:
	String m_accountName;
	String m_hostName;
	String m_referral;
	String m_userDefined;

public:
	AbstractGoogleAnalyticsParameters( const String& accountName, const String& hostName, 
		const String& referral );

	AbstractGoogleAnalyticsParameters( const String& accountName, const String& hostName, 
		const String& referral, const String& userDefined );

	virtual ~AbstractGoogleAnalyticsParameters();

	String getReferral()
	{
		return m_referral;
	}

	String getAccountName()
	{
		return m_accountName;
	}

	String getHostname()
	{
		return m_hostName;
	}

	String getUserDefined()
	{
		return m_userDefined;
	}
};
