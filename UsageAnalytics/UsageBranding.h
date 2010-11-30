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

#include "IUsageBranding.h"

class UsageBranding : public IUsageBranding
{
public:
	UsageBranding();
	virtual ~UsageBranding();

public:
	String getGoogleAnalyticsAccount()
	{
		return _T("UA-12968016-1");
	}

	String getGoogleAnalyticsReportingHost()
	{
		return _T("www.stopka.us");
	}
};
