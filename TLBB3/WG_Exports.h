#pragma once

#ifndef WG_HOOK
#define WG_HOOK extern "C" __declspec(dllimport)
#endif


WG_HOOK BOOL WINAPI InstallHook(DWORD dwID);
WG_HOOK BOOL WINAPI UnInstallHook();