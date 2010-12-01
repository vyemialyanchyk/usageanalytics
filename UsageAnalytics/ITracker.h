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

class IFocusPoint;

class ITracker
{
public:
	virtual ~ITracker() {};
	// Track the focusPoint in the application. <br/>
	// @param focusPoint
	//            Focus point of the application like application load,
	//            application module load, user actions, error events etc.
	virtual void trackFocusPoint( IFocusPoint* focusPoint ) = 0;
};