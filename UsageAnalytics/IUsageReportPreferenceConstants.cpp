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
#include "IUsageReportPreferenceConstants.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

boolean IUsageReportPreferenceConstants::USAGEREPORT_ENABLED_DEFAULTVALUE = false;

String IUsageReportPreferenceConstants::USAGEREPORT_ENABLED_ID = _T("allow_usage_report_preference");

String IUsageReportPreferenceConstants::ASK_USER_USAGEREPORT_ID = _T("ask_user_for_usage_report_preference");

String IUsageReportPreferenceConstants::APPLICATION_INSTANCE_ID = _T("application_instance_id");

String IUsageReportPreferenceConstants::FIRST_VISIT = _T("first_visit");

String IUsageReportPreferenceConstants::LAST_VISIT = _T("last_visit");

String IUsageReportPreferenceConstants::VISIT_COUNT = _T("visit_count");

bool IUsageReportPreferenceConstants::ASK_USER_USAGEREPORT_DEFAULTVALUE = true;
