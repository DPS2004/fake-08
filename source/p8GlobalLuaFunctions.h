#pragma once

#include <string>


//from PicoLove api.lua

const char * p8GlobalLuaFunctions = R"#(
-- The functions below are normally attached to the program code, but are here for simplicity
---------------------------------
--Table Helpers
---------------------------------
function all(a)
	if a==nil or #a==0 then
		return function() end
	end
	local i, li=1
	return function()
		if (a[i]==li) then i=i+1 end
		while(a[i]==nil and i<=#a) do i=i+1 end
		li=a[i]
		return a[i]
	end
end

function foreach(a, f)
	for v in all(a) do
		f(v)
	end
end

function count(a)
	local count=0
	for i=1, #a do
		if a[i]~=nil then count=count+1 end
	end
	return count
end

function add(a, v)
	if a==nil then return end
	a[#a+1]=v
end

function del(a, dv)
	if a==nil then return end
	for i=1, #a do
		if a[i]==dv then
			table.remove(a, i)
			return
		end
	end
end

//from zepto 8 bios.p8
function deli(c,i)
    if c != nil then
        -- delete at i if specified, otherwise at the end
        i=i and mid(1,i\1,#c) or #c
        local v=c[i]
        for j=i,#c-1 do c[j]=c[j+1] end
        return v
    end
end

---------------------------------
--Coroutines
---------------------------------
yield = coroutine.yield
cocreate = coroutine.create
coresume = coroutine.resume
costatus = coroutine.status

---------------------------------
--Debug
---------------------------------
trace = debug.traceback

sub = string.sub
pack = table.pack
unpack = table.unpack

--Button emoji variables
⬅️ = 0
➡️ = 1
⬆️ = 2
⬇️ = 3
🅾️ = 4
❎ = 5

function menuitem()
--noop placeholder for now
end

)#";


