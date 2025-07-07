local moo = require("moo")
local os = require("os")

-- Testskript zur Überprüfung der Funktionalität des moo-Moduls
local function test_moo()
    local math = moo.moo()

    -- Absolutwert testen
    local abs_value = math.abs(-42.0)
    print("Absolutwert von -42.0: " .. abs_value)

    -- Ganzzahlige Division testen
    local idiv_result = math.idiv(10, 3)
    print("Ganzzahlige Division von 10 durch 3: " .. idiv_result)

    -- Abrunden testen
    local floor_result = math.floor(10.323)
    print("Abrunden von 10.323: " .. floor_result)

    -- Aufrunden testen
    local ceil_result = math.ceil(10.43)
    print("Aufrunden von 10.43: " .. ceil_result)

    -- GGT testen
    local gcd_result = math.gcd(48, 18)
    print("GGT von 48 und 18: " .. gcd_result)

    -- KGV testen
    local lcm_result = math.lcm(4, 6)
    print("KGV von 4 und 6: " .. lcm_result)

    print(math.permutation(5, 3))

    local n = 3
    local ptr = math.factable(n)
    if not ptr then
        print("Fehler: NULL-Zeiger von permutation zurückgegeben.")
    else
        local fakultaet = {}
        for i = 0, n do
            fakultaet[i + 1] = ptr[i]
        end
        print(n .. "! Tabelle =", table.concat(fakultaet, ", "))
    end

    -- Permutationen generieren testen
    local ptr_perm = math.genPerm(n)
    if not ptr_perm then
        print("Fehler: NULL-Zeiger von genPerm zurückgegeben.")
    else
        for _, k in ipairs(ptr_perm) do
            print(k)
        end
    end

    print(math.min(10, 3))
    print(math.max(10, 3))

    print(math.combination(10, 5))
    print(math.permutation(10, 5))
end

if ... == nil then
    test_moo()
end