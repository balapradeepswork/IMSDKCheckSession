/*****************************************************************************

INTEL CORPORATION PROPRIETARY INFORMATION
This software is supplied under the terms of a license agreement or
nondisclosure agreement with Intel Corporation and may not be copied
or disclosed except in accordance with the terms of that agreement.
Copyright(c) 2005-2014 Intel Corporation. All Rights Reserved.

*****************************************************************************/

#include "mfxvideo++.h"
#include <iostream>

int main(int argc, char** argv)
{
	mfxStatus sts = MFX_ERR_NONE;
	

	// Initialize Intel Media SDK session
	// - MFX_IMPL_AUTO_ANY selects HW acceleration if available (on any adapter)
	// - Version 1.0 is selected for greatest backwards compatibility.
	// OS specific notes
	// - On Windows both SW and HW libraries may present
	// - On Linux HW library only is available
	// If more recent API features are needed, change the version accordingly
	mfxIMPL impl = MFX_IMPL_AUTO_ANY;
	mfxVersion ver = { { 3, 1 } };
	MFXVideoSession session;
	// Initialize Intel Media SDK Session
	sts = session.Init(impl, &ver);
	

	// Query selected implementation and version
	sts = session.QueryIMPL(&impl);
	

	sts = session.QueryVersion(&ver);
	
	if (sts == MFX_ERR_NONE) {
		printf("\n\nImplementation: %s \t\t API version: %d.%d\n",
			(impl == MFX_IMPL_SOFTWARE) ? "SOFTWARE" : "HARDWARE",
			ver.Major, ver.Minor);
	}
	else
		printf("\nIntel Media SDK is unsupported");

	session.Close();
	std::cout << "Press a key";
	char a;
	std::cin >> a;

	return 0;
}
