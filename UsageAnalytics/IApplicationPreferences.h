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

class IApplicationPreferences
{
public:
	virtual ~IApplicationPreferences() {};
	//
	virtual void put( const String& name, const String& val ) = 0;
	//
	virtual void put( const String& name, const unsigned long& val ) = 0;
	//
	virtual String get( const String& name, const String& defaultVal ) = 0;
	//
	virtual String get( const String& name ) = 0;
	//
	virtual unsigned long getULong( const String& name, const unsigned long& defaultVal ) = 0;
	//
	virtual bool fileSave() = 0;
	//
	virtual bool fileLoad() = 0;
};
