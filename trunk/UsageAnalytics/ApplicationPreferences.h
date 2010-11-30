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

#include "IApplicationPreferences.h"

class ApplicationPreferences : public IApplicationPreferences
{
protected:
	String m_strFilePath;
	//
	std::map<String, String> m_mapPropVal;
public:
	ApplicationPreferences();
	virtual ~ApplicationPreferences();
	//
	static ApplicationPreferences& getInstance();
public:
	//
	void cleanUp();
	//
	bool setFilePath( const String& strFilePath );
	//
	void put( const String& name, const String& val );
	//
	void put( const String& name, const unsigned long& val );
	//
	String get( const String& name, const String& defaultVal );
	//
	String get( const String& name );
	//
	unsigned long getULong( const String& name, const unsigned long& defaultVal );
	//
	bool fileSave();
	//
	bool fileLoad();
};
