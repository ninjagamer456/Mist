#pragma once
#include <Windows.h>
#include "retcheck.h"
#include "Bridge.h"
#include "Addresses.h"

#define Declare(address, returnValue, callingConvention, ...) (returnValue(callingConvention*)(__VA_ARGS__))(retcheckBypass(x(address)))
#define r_lua_tostring(rL,i)	r_lua_tolstring(rL, (i), NULL) //
#define r_lua_pop(rL,n)		r_lua_settop(rL, -(n)-1) //
#define r_lua_getglobal(rL,s)	r_lua_getfield(rL, LUA_GLOBALSINDEX, (s))
#define r_lua_newtable(rL) r_lua_createtable(rL, 0, 0)
#define x(x) (x - 0x400000 + (DWORD)GetModuleHandleA(0))

int GDM;


typedef DWORD(getdatamodel2_CCV* gdm2)();
gdm2 getdatamodel2 = (gdm2)(x(Adresses::getdatamodel2_addr));

typedef DWORD(__thiscall* getdatamodel)(DWORD, DWORD);
getdatamodel r_getdatamodel = (getdatamodel)(x(Adresses::getdatamodel_addr));

typedef int(lual_error_CCV* ee)(int e, const char* n, ...);
static ee r_luaL_error = (ee)x(Adresses::lual_error_addr);

typedef void(lua_getfield_CCV* rgetfield)(DWORD rL, int idx, const char* k);
rgetfield r_lua_getfield = (rgetfield)retcheckBypass(x(Adresses::lua_getfield_addr));

typedef int(lua_pushboolean_CCV* rboolean)(unsigned int, int);
rboolean r_lua_pushboolean = (rboolean)(retcheckBypass(x(Adresses::lua_pushboolean_addr)));

typedef char* (lua_tolstring_CCV* rtolstring)(DWORD rL, int idx, size_t* size);
rtolstring r_lua_tolstring = (rtolstring)(retcheckBypass(x(Adresses::lua_tolstring_addr))); 

typedef bool(lua_toboolean_CCV* toboolean)(DWORD rL, bool idx);
toboolean r_lua_toboolean = (toboolean)(x(Adresses::lua_toboolean_addr));

typedef void(lua_pushvalue_CCV* pushvalue)(DWORD rL, DWORD idx);
pushvalue r_lua_pushvalue = (pushvalue)(retcheckBypass(x(Adresses::lua_pushvalue_addr)));

typedef double(lua_pushnumber_CCV* pushnumber)(DWORD rL, double idx);
pushnumber r_lua_pushnumber = (pushnumber)(retcheckBypass(x(Adresses::lua_pushnumber_addr)));

typedef void(lua_pushstring_CCV* rpushstring)(DWORD rL, const char*);
rpushstring r_lua_pushstring = (rpushstring)(retcheckBypass(x(Adresses::lua_pushstring_addr))); 

typedef int(lua_pcall_CCV* rLua_pcall)(DWORD lst, int nargs, int nresults, int errfunc);
rLua_pcall r_lua_pcall = (rLua_pcall)retcheckBypass(x(Adresses::lua_pcall_addr));

typedef DWORD(lua_next_CCV* next2)(DWORD rL, int idx);
next2 r_lua_next = (next2)(retcheckBypass(x(Adresses::lua_next_addr)));

typedef double(lua_tonumber_CCV* rtonumber)(DWORD, int, int);
rtonumber r_lua_tonumber = (rtonumber)(x(Adresses::lua_tonumber_addr));

typedef void(lua_pushcclosure_CCV* rpushcclosure)(DWORD rL, int fn, int non, int a1, int xd);
rpushcclosure r_lua_pushcclosure = (rpushcclosure)(retcheckBypass(x(Adresses::lua_pushcclosure_addr)));

typedef void(lua_createtable_CCV* rcreatetable)(DWORD rL, int num, int fix);
rcreatetable r_lua_createtable = (rcreatetable)(retcheckBypass(x(Adresses::lua_createtable_addr)));

typedef DWORD(lua_newthread_CCV* rnewthread)(DWORD);
rnewthread r_lua_newthread = (rnewthread)retcheckBypass(x(Adresses::lua_newthread_addr));

typedef void* (lua_newuserdata_CCV* rnewuserdata)(DWORD, size_t, int);
rnewuserdata r_lua_newuserdata = (rnewuserdata)(retcheckBypass(x(Adresses::lua_newuserdata_addr)));

typedef void(lua_rawgeti_CCV* rrawgeti)(DWORD, DWORD, DWORD);
rrawgeti r_lua_rawgeti = (rrawgeti)retcheckBypass(x(Adresses::lua_rawgeti_addr));

typedef void(lua_rawseti_CCV* rrawgeti)(DWORD, DWORD, DWORD);
rrawgeti r_lua_rawseti = (rrawgeti)retcheckBypass(x(Adresses::lua_rawseti_addr));

typedef void* (lua_getmetatable_CCV* rgetmetatable)(DWORD rL, int idx);
rgetmetatable r_lua_getmetatable = (rgetmetatable)(retcheckBypass(x(Adresses::lua_getmetatable_addr)));

typedef int (lua_setmetatable_CCV* rsetmetatable)(DWORD rL, int idx);
rsetmetatable r_lua_setmetatable = (rsetmetatable)(retcheckBypass(x(Adresses::lua_setmetatable_addr)));

typedef int(lua_touserdata_CCV* rtouserdata)(DWORD, int);
rtouserdata r_lua_touserdata = (rtouserdata)(retcheckBypass(x(Adresses::lua_touserdata_addr)));

typedef void(fireclickdetector_CCV* fireclick)(DWORD, float, DWORD);
fireclick FireClick = (fireclick)x(Adresses::fireclickdetector_addr);

typedef DWORD(lua_type_CCV* rtype)(DWORD, int);
rtype r_lua_type = (rtype)(x(Adresses::lua_type_addr));

typedef void* (lua_settable_CCV* rsettable)(DWORD rL, int);
rsettable r_lua_settable = (rsettable)(retcheckBypass(x(Adresses::lua_settable_addr)));

typedef DWORD(__cdecl* rref)(DWORD, DWORD);
rref r_luaL_ref = (rref)(retcheckBypass(x(Adresses::lual_ref)));

int r_lua_gettop(int rL)
{
	return *(DWORD*)(rL + Adresses::ls_top) - *(DWORD*)(rL + Adresses::ls_base) >> 4;
}

typedef void(lua_settop_CCV* rsettop)(DWORD rL, int idx);
rsettop r_lua_settop = (rsettop)(retcheckBypass(x(Adresses::lua_settop_addr))); 

typedef void(lua_pushnil_CCV* pushnil)(DWORD);
pushnil r_lua_pushnil = (pushnil)(retcheckBypass(x(Adresses::lua_pushnil_addr)));

typedef void(lua_pushlightuserdata_CCV* rpushlight)(DWORD, void*);
rpushlight r_lua_pushlightuserdata = (rpushlight)(retcheckBypass(x(Adresses::lua_pushlightuserdata_addr)));

typedef bool(flog_getvalue_CCV* FLog)(const std::string& name, std::string& value, bool alsoCheckUnknown);
FLog GetValue = reinterpret_cast<FLog>(x(Adresses::flog_getvalue_addr));

typedef bool(flog_setvalue_CCV* SLog)(const std::string& name, const std::string& value, int Type, bool loadedFromServer);
SLog SetValue = reinterpret_cast<SLog>(x(Adresses::flog_setvalue_addr));

typedef uint32_t(index2adr_CCV* T_index2adr)(uint32_t, uint32_t);
T_index2adr r_index2adr;