
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      SuperDir/Functions.h

#pragma once

// ===== SuperDir ===========================================================
class IFileInfo;

// Functions
// //////////////////////////////////////////////////////////////////////////

extern IFileInfo** FindFiles(const char* aFolder);

extern void DisplayInformation (IFileInfo** aFiles);
extern void ReleaseMemory      (IFileInfo** aFiles);
extern void RetrieveInformation(IFileInfo** aFiles);
