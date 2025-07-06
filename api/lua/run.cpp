extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include <iostream>

int main() {
    lua_State* L = luaL_newstate(); // neue Lua-VM
    if (L == nullptr) {
        std::cerr << "Fehler: Lua konnte nicht initialisiert werden." << std::endl;
        return 1;
    }

    luaL_openlibs(L); // Standardbibliotheken laden

    const char* lua_code = "print('Hallo von Lua!')";

    if (luaL_dostring(L, lua_code) != LUA_OK) {
        std::cerr << "Lua-Fehler: " << lua_tostring(L, -1) << std::endl;
        lua_close(L);
        return 1;
    }

    lua_close(L); // VM freigeben
    return 0;
}
