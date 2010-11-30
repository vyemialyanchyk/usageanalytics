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

#include "IStopKaEnvironment.h"
#include "AbstractApplicationEnvironment.h"

class IApplicationPreferences;

class StopKaEnvironment : public AbstractApplicationEnvironment, public IStopKaEnvironment
{
public:
	static CharType STOPKA_COMPONENTS_DELIMITER;

public:
	StopKaEnvironment( const String& accountName, const String& hostName, IApplicationPreferences* pPreferences );
	virtual ~StopKaEnvironment();

public:
	String getKeyword();

	String bundleGroupsToKeywordString( const std::vector<String>& vecComponentNames );

	String getStopKaVersion();
};
