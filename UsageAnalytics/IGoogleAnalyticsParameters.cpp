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

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CharType IGoogleAnalyticsParameters::AMPERSAND = '&';
CharType IGoogleAnalyticsParameters::EQUALS_SIGN = '=';
CharType IGoogleAnalyticsParameters::URL_PARAM_DELIMITER = '?';
CharType IGoogleAnalyticsParameters::PLUS_SIGN = '+';
CharType IGoogleAnalyticsParameters::DOT = '.';
CharType IGoogleAnalyticsParameters::SEMICOLON = ';';
CharType IGoogleAnalyticsParameters::PIPE = '|';

String IGoogleAnalyticsParameters::PARAM_HID = _T("utmhid");
String IGoogleAnalyticsParameters::PARAM_PAGE_REQUEST = _T("utmp");
String IGoogleAnalyticsParameters::PARAM_ACCOUNT_NAME = _T("utmac");
String IGoogleAnalyticsParameters::PARAM_HOST_NAME = _T("utmhn");
String IGoogleAnalyticsParameters::PARAM_COOKIES = _T("utmcc");
String IGoogleAnalyticsParameters::PARAM_COOKIES_UNIQUE_VISITOR_ID = _T("__utma");
String IGoogleAnalyticsParameters::PARAM_COOKIES_SESSION = _T("__utmb");
String IGoogleAnalyticsParameters::PARAM_COOKIES_BROWSERSESSION = _T("__utmc");
String IGoogleAnalyticsParameters::PARAM_COOKIES_REFERRAL_TYPE = _T("__utmz");
String IGoogleAnalyticsParameters::PARAM_COOKIES_UTMCSR = _T("utmcsr");
String IGoogleAnalyticsParameters::PARAM_COOKIES_UTMCCN = _T("utmccn");
String IGoogleAnalyticsParameters::PARAM_COOKIES_UTMCMD = _T("utmcmd");
String IGoogleAnalyticsParameters::PARAM_COOKIES_KEYWORD = _T("utmctr");
String IGoogleAnalyticsParameters::PARAM_COOKIES_USERDEFINED = _T("__utmv");

String IGoogleAnalyticsParameters::PARAM_REFERRAL = _T("utmr");
String IGoogleAnalyticsParameters::PARAM_TRACKING_CODE_VERSION = _T("utmwv");
String IGoogleAnalyticsParameters::PARAM_UNIQUE_TRACKING_NUMBER = _T("utmn");
String IGoogleAnalyticsParameters::PARAM_LANGUAGE_ENCODING = _T("utmcs");
String IGoogleAnalyticsParameters::PARAM_SCREEN_RESOLUTION = _T("utmsr");
String IGoogleAnalyticsParameters::PARAM_SCREEN_COLOR_DEPTH = _T("utmsc");
String IGoogleAnalyticsParameters::PARAM_PRODUCT_NAME = _T("utmipn");
String IGoogleAnalyticsParameters::PARAM_PRODUCT_CODE = _T("utmipc");
String IGoogleAnalyticsParameters::PARAM_FLASH_VERSION = _T("utmfl");
String IGoogleAnalyticsParameters::PARAM_BROWSER_LANGUAGE = _T("utmul");
String IGoogleAnalyticsParameters::PARAM_REPEAT_CAMPAIGN_VISIT = _T("utmcr");
String IGoogleAnalyticsParameters::PARAM_PAGE_TITLE = _T("utmdt");
String IGoogleAnalyticsParameters::PARAM_GAQ = _T("gaq");
String IGoogleAnalyticsParameters::PARAM_AD_CONTENT = _T("utm_content");

String IGoogleAnalyticsParameters::VALUE_TRACKING_CODE_VERSION = _T("4.7.2");
String IGoogleAnalyticsParameters::VALUE_NO_REFERRAL = _T("0");
String IGoogleAnalyticsParameters::VALUE_ENCODING_UTF8 = _T("UTF-8");

String IGoogleAnalyticsParameters::SCREERESOLUTION_DELIMITER = _T("x");
String IGoogleAnalyticsParameters::SCREENCOLORDEPTH_POSTFIX = _T("-bit");

IGoogleAnalyticsParameters::IGoogleAnalyticsParameters()
{
}

IGoogleAnalyticsParameters::~IGoogleAnalyticsParameters()
{
}
