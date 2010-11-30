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

class IUsageReportPreferenceConstants
{
public:
	virtual ~IUsageReportPreferenceConstants() {};
	// The value that determines if usage shall be reported if there's no user set setting.
	static boolean USAGEREPORT_ENABLED_DEFAULTVALUE;
	// The identifier to be used to identify the value that determines if usage shall be reported.
	static String USAGEREPORT_ENABLED_ID;
	// The identifier to be used for the value that determines if the user shall be asked for reporting.
	static String ASK_USER_USAGEREPORT_ID;
	// The identifier to be used for the value that determines this application instance.
	static String APPLICATION_INSTANCE_ID;

	static String FIRST_VISIT;

	static String LAST_VISIT;

	static String VISIT_COUNT;

	static bool ASK_USER_USAGEREPORT_DEFAULTVALUE;
};
