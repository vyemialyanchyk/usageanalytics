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
#include "AbstractApplicationEnvironment.h"
#include "StopKaEnvironment.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CharType StopKaEnvironment::STOPKA_COMPONENTS_DELIMITER = '-';

StopKaEnvironment::StopKaEnvironment( const String& accountName, 
	const String& hostName, IApplicationPreferences* pPreferences ) :
		AbstractApplicationEnvironment( accountName, hostName, pPreferences ), IStopKaEnvironment()
{
}

StopKaEnvironment::~StopKaEnvironment()
{
}

String StopKaEnvironment::getKeyword()
{
	// here is a set of all plugins which application use
	std::vector<String> vecComponentNames;
	vecComponentNames.push_back( _T("StopKa.exe") );
	//vecComponentNames.push_back( _T("7z") );
	return bundleGroupsToKeywordString( vecComponentNames );
}

String StopKaEnvironment::bundleGroupsToKeywordString( const std::vector<String>& vecComponentNames )
{
	CharType delimiter = STOPKA_COMPONENTS_DELIMITER;
	String builder;
	for( size_t i = 0; i < vecComponentNames.size(); i++  )
	{
		builder += vecComponentNames[ i ] + delimiter;
	}
	return builder;
}

String StopKaEnvironment::getStopKaVersion()
{
	// TODO: get version number from one place
	return _T("1.5");
}
