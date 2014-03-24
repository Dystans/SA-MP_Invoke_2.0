/*
    SA-MP 0.3z Invoke v1.0
    Copyright (c) 2014, Linux_Shines
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
          notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
          notice, this list of conditions and the following disclaimer in the
          documentation and/or other materials provided with the distribution.
        * Neither the name of the Linux_Shines nor the
          names of its contributors may be used to endorse or promote products
          derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL LINUX_SHINES BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#include <bitset>
#include <list>
#include <map>
#include <stdarg.h>

#include "..\SDK\plugin.h"

#define PAWN INVOKE

namespace INVOKE {
	struct Native {
		const char * name;
		const char * data;
	};

	static const char * const names[] = {
		"SendClientMessage",
		"SendClientMessageToAll",
		"SendDeathMessage",
		"GameTextForAll",
		"GameTextForPlayer",
		"GetTickCount",
		"GetMaxPlayers",
		"SetGameModeText",
		"SetTeamCount",
		"AddPlayerClass",
		"AddPlayerClassEx",
		"AddStaticVehicle",
		"AddStaticVehicleEx",
		"AddStaticPickup",
		"ShowNameTags",
		"ShowPlayerMarkers",
		"GameModeExit",
		"SetWorldTime",
		"GetWeaponName",
		"EnableTirePopping",
		"AllowInteriorWeapons",
		"SetWeather",
		"SetGravity",
		"AllowAdminTeleport",
		"SetDeathDropAmount",
		"CreateExplosion",
		"EnableZoneNames",
		"IsPlayerAdmin",
		"Kick",
		"Ban",
		"SendRconCommand",
		"ShowPlayerDialog",

		//a_players.inc
		"SetSpawnInfo",
		"SpawnPlayer",
		"SetPlayerPos",
		"GetPlayerPos",
		"SetPlayerFacingAngle",
		"GetPlayerFacingAngle",
		"SetPlayerInterior",
		"GetPlayerInterior",
		"SetPlayerHealth",
		"GetPlayerHealth",
		"SetPlayerArmour",
		"GetPlayerArmour",
		"SetPlayerAmmo",
		"GetPlayerAmmo",
		"SetPlayerTeam",
		"GetPlayerTeam",
		"SetPlayerScore",
		"GetPlayerScore",
		"SetPlayerColor",
		"GetPlayerColor",
		"SetPlayerSkin",
		"GivePlayerWeapon",
		"ResetPlayerWeapons",
		"GetPlayerWeaponData",
		"GivePlayerMoney",
		"ResetPlayerMoney",
		"SetPlayerName",
		"GetPlayerMoney",
		"GetPlayerState",
		"GetPlayerIp",
		"GetPlayerPing",
		"GetPlayerWeapon",
		"GetPlayerKeys",
		"GetPlayerName",
		"PutPlayerInVehicle",
		"GetPlayerVehicleID",
		"RemovePlayerFromVehicle",
		"TogglePlayerControllable",
		"PlayerPlaySound",
		"SetPlayerCheckpoint",
		"DisablePlayerCheckpoint",
		"SetPlayerRaceCheckpoint",
		"DisablePlayerRaceCheckpoint",
		"SetPlayerWorldBounds",
		"SetPlayerMarkerForPlayer",
		"ShowPlayerNameTagForPlayer",
		"SetPlayerMapIcon",
		"RemovePlayerMapIcon",
		"SetPlayerCameraPos",
		"SetPlayerCameraLookAt",
		"SetCameraBehindPlayer",
		"AllowPlayerTeleport",
		"IsPlayerConnected",
		"IsPlayerInVehicle",
		"IsPlayerInAnyVehicle",
		"IsPlayerInCheckpoint",
		"IsPlayerInRaceCheckpoint",
		"SetPlayerTime",
		"TogglePlayerClock",
		"SetPlayerWeather",
		"GetPlayerTime",
		"SetPlayerVirtualWorld",
		"GetPlayerVirtualWorld",

		//a_vehicle.inc
		"CreateVehicle",
		"DestroyVehicle",
		"GetVehiclePos",
		"SetVehiclePos",
		"GetVehicleZAngle",
		"SetVehicleZAngle",
		"SetVehicleParamsForPlayer",
		"SetVehicleToRespawn",
		"LinkVehicleToInterior",
		"AddVehicleComponent",
		"ChangeVehicleColor",
		"ChangeVehiclePaintjob",
		"SetVehicleHealth",
		"GetVehicleHealth",
		"AttachTrailerToVehicle",
		"DetachTrailerFromVehicle",
		"IsTrailerAttachedToVehicle",
		"SetVehicleNumberPlate",
		"GetVehicleModel",
		"SetVehicleVirtualWorld",
		"GetVehicleVirtualWorld",
		"ApplyAnimation",

		//a_objects.inc
		"CreateObject",
		"SetObjectPos",
		"GetObjectPos",
		"SetObjectRot",
		"GetObjectRot",
		"IsValidObject",
		"DestroyObject",
		"MoveObject",
		"StopObject",
		"CreatePlayerObject",
		"SetPlayerObjectPos",
		"GetPlayerObjectPos",
		"GetPlayerObjectRot",
		"SetPlayerObjectRot",
		"IsValidPlayerObject",
		"DestroyPlayerObject",
		"MovePlayerObject",
		"StopPlayerObject",

		//Menu's
		"CreateMenu",
		"DestroyMenu",
		"AddMenuItem",
		"SetMenuColumnHeader",
		"ShowMenuForPlayer",
		"HideMenuForPlayer",
		"IsValidMenu",
		"DisableMenu",
		"DisableMenuRow",

		//Textdraw
		"TextDrawCreate",
		"TextDrawDestroy",
		"TextDrawLetterSize",
		"TextDrawTextSize",
		"TextDrawAlignment",
		"TextDrawColor",
		"TextDrawUseBox",
		"TextDrawBoxColor",
		"TextDrawSetShadow",
		"TextDrawSetOutline",
		"TextDrawBackgroundColor",
		"TextDrawFont",
		"TextDrawSetProportional",
		"TextDrawShowForPlayer",
		"TextDrawHideForPlayer",
		"TextDrawShowForAll",
		"TextDrawHideForAll",
	};

	static const Native SendClientMessage =					{ "SendClientMessage","iis" };
	static const Native SendClientMessageToAll =			{ "SendClientMessageToAll","is" };
	static const Native SendDeathMessage =					{ "SendDeathMessage","iii" };
	static const Native GameTextForAll =					{ "GameTextForAll","sii" };
	static const Native GameTextForPlayer =					{ "GameTextForPlayer",	"isii" };
	static const Native GetTickCount =						{ "GetTickCount","" };
	static const Native GetMaxPlayers =						{ "GetMaxPlayers",	"" };
	static const Native SetGameModeText =					{  "SetGameModeText","s" };
	static const Native SetTeamCount =						{  "SetTeamCount", "i" };
	static const Native AddPlayerClass =					{ "AddPlayerClass","iffffiiiiii" };
	static const Native AddPlayerClassEx =					{ "AddPlayerClassEx","iiffffiiiiii" };
	static const Native AddStaticVehicle =					{ "AddStaticVehicle","iffffii" };
	static const Native AddStaticVehicleEx =				{ "AddStaticVehicleEx","iffffiii" };
	static const Native AddStaticPickup =					{ "AddStaticPickup","iifff" };
	static const Native ShowNameTags =						{ "ShowNameTags","i" };
	static const Native ShowPlayerMarkers =					{ "ShowPlayerMarkers",	"i" };
	static const Native GameModeExit =						{ "GameModeExit","" };
	static const Native SetWorldTime =						{"SetWorldTime","i" };
	static const Native GetWeaponName =						{ "GetWeaponName",	"ivi" };
	static const Native EnableTirePopping =					{ "EnableTirePopping","i" };
	static const Native AllowInteriorWeapons =				{ "AllowInteriorWeapons","i" };
	static const Native SetWeather =						{ "SetWeather","i" };
	static const Native SetGravity =						{ "SetGravity","f" };
	static const Native AllowAdminTeleport =				{  "AllowAdminTeleport","i" };
	static const Native SetDeathDropAmount =				{ "SetDeathDropAmount","i" };
	static const Native CreateExplosion =					{ "CreateExplosion","fffif" };
	static const Native EnableZoneNames =					{ "EnableZoneNames","i" };
	static const Native IsPlayerAdmin =						{ "IsPlayerAdmin",	"i" };
	static const Native Kick =								{ "Kick","i" };
	static const Native Ban =								{ "Ban",	"i" };
	static const Native SendRconCommand =					{ "SendRconCommand",	"s" };
	static const Native ShowPlayerDialog =					{ "ShowPlayerDialog",	"dddssss"};

	// a_players.inc
	static const Native SetSpawnInfo =						{ "SetSpawnInfo","iiiffffiiiiii" };
	static const Native SpawnPlayer =						{ "SpawnPlayer","i" };
	static const Native SetPlayerPos =						{ "SetPlayerPos","ifff" };
	static const Native GetPlayerPos =						{ "GetPlayerPos","ivvv" };
	static const Native SetPlayerFacingAngle =				{ "SetPlayerFacingAngle","if" };
	static const Native GetPlayerFacingAngle =				{ "GetPlayerFacingAngle","iv" };
	static const Native SetPlayerInterior =					{ "SetPlayerInterior",	"ii" };
	static const Native GetPlayerInterior =					{ "GetPlayerInterior",	"i" };
	static const Native SetPlayerHealth =					{ "SetPlayerHealth",						"if" };
	static const Native GetPlayerHealth =					{ "GetPlayerHealth",						"iv" };
	static const Native SetPlayerArmour =					{ "SetPlayerArmour",						"if" };
	static const Native GetPlayerArmour =					{ "GetPlayerArmour",						"iv" };
	static const Native SetPlayerAmmo =						{ "SetPlayerAmmo",						"iii" };
	static const Native GetPlayerAmmo =						{ "GetPlayerAmmo",						"i" };
	static const Native SetPlayerTeam =						{ "SetPlayerTeam",						"ii" };
	static const Native GetPlayerTeam =						{ "GetPlayerTeam",						"i" };
	static const Native SetPlayerScore =					{  "SetPlayerScore",						"ii" };
	static const Native GetPlayerScore =					{  "GetPlayerScore",						"i" };
	static const Native SetPlayerColor =					{  "SetPlayerColor",						"ii" };
	static const Native GetPlayerColor =					{  "GetPlayerColor",						"i" };
	static const Native SetPlayerSkin =						{  "SetPlayerSkin",						"ii" };
	static const Native GivePlayerWeapon =					{  "GivePlayerWeapon",					"iii" };
	static const Native ResetPlayerWeapons =				{ "ResetPlayerWeapons",					"i" };
	static const Native GetPlayerWeaponData =				{  "GetPlayerWeaponData",					"iiiviv " };
	static const Native GivePlayerMoney =					{  "GivePlayerMoney",						"ii" };
	static const Native ResetPlayerMoney =					{  "ResetPlayerMoney",					"i" };
	static const Native SetPlayerName =						{  "SetPlayerName",						"is" };
	static const Native GetPlayerMoney =					{  "GetPlayerMoney",						"i" };
	static const Native GetPlayerState =					{  "GetPlayerState",						"i" };
	static const Native GetPlayerIp =						{  "GetPlayerIp",							"ipi" };
	static const Native GetPlayerPing =						{  "GetPlayerPing",						"i" };
	static const Native GetPlayerWeapon =					{  "GetPlayerWeapon",						"i" };
	static const Native GetPlayerKeys =						{  "GetPlayerKeys",						"ivvv" };
	static const Native GetPlayerName =						{  "GetPlayerName",						"ipi" };
	static const Native PutPlayerInVehicle =				{  "PutPlayerInVehicle",					"iii" };
	static const Native GetPlayerVehicleID =				{  "GetPlayerVehicleID",					"i" };
	static const Native RemovePlayerFromVehicle =			{  "RemovePlayerFromVehicle",				"i" };
	static const Native TogglePlayerControllable =			{  "TogglePlayerControllable",			"ii" };
	static const Native PlayerPlaySound =					{  "PlayerPlaySound",						"iifff" };
	static const Native SetPlayerCheckpoint =				{  "SetPlayerCheckpoint",					"iffff" };
	static const Native DisablePlayerCheckpoint =			{  "DisablePlayerCheckpoint",				"i" };
	static const Native SetPlayerRaceCheckpoint =			{  "SetPlayerRaceCheckpoint",				"iifffffff" };
	static const Native DisablePlayerRaceCheckpoint =		{  "DisablePlayerRaceCheckpoint",			"i" };
	static const Native SetPlayerWorldBounds =				{  "SetPlayerWorldBounds",				"iffff" };
	static const Native SetPlayerMarkerForPlayer =			{  "SetPlayerMarkerForPlayer",			"iii" };
	static const Native ShowPlayerNameTagForPlayer =		{  "ShowPlayerNameTagForPlayer",			"iii" };
	static const Native SetPlayerMapIcon =					{  "SetPlayerMapIcon",					"iifffii" };
	static const Native RemovePlayerMapIcon =				{  "RemovePlayerMapIcon",					"ii" };
	static const Native SetPlayerCameraPos =				{  "SetPlayerCameraPos",					"ifff" };
	static const Native SetPlayerCameraLookAt =				{  "SetPlayerCameraLookAt",				"ifff" };
	static const Native SetCameraBehindPlayer =				{  "SetCameraBehindPlayer",				"i" };
	static const Native AllowPlayerTeleport =				{  "AllowPlayerTeleport",					"ii" };
	static const Native IsPlayerConnected =					{  "IsPlayerConnected"					"i" };
	static const Native IsPlayerInVehicle =					{  "IsPlayerInVehicle",					"ii" };
	static const Native IsPlayerInAnyVehicle =				{  "IsPlayerInAnyVehicle",				"i" };
	static const Native IsPlayerInCheckpoint =				{  "IsPlayerInCheckpoint",				"i" };
	static const Native IsPlayerInRaceCheckpoint =			{  "IsPlayerInRaceCheckpoint",			"i" };
	static const Native SetPlayerTime =						{  "SetPlayerTime",						"iii" };
	static const Native TogglePlayerClock =					{  "TogglePlayerClock",					"ii" };
	static const Native SetPlayerWeather =					{  "SetPlayerWeather",					"ii" };
	static const Native GetPlayerTime =						{  "GetPlayerTime",						"ivv" };
	static const Native SetPlayerVirtualWorld =				{  "SetPlayerVirtualWorld",				"ii" };
	static const Native GetPlayerVirtualWorld =				{  "GetPlayerVirtualWorld",				"i" };

	// a_vehicle.inc
	static const Native CreateVehicle =						{  "CreateVehicle",						"iffffiii" };
	static const Native DestroyVehicle =					{  "DestroyVehicle",						"i" };
	static const Native GetVehiclePos =						{  "GetVehiclePos",						"ivvv" };
	static const Native SetVehiclePos =						{  "SetVehiclePos",						"ifff" };
	static const Native GetVehicleZAngle =					{  "GetVehicleZAngle",					"iv" };
	static const Native SetVehicleZAngle =					{  "SetVehicleZAngle",					"if" };
	static const Native SetVehicleParamsForPlayer =			{  "SetVehicleParamsForPlayer",			"iiii" };
	static const Native SetVehicleToRespawn =				{  "SetVehicleToRespawn",					"i" };
	static const Native LinkVehicleToInterior =				{ "LinkVehicleToInterior",				"ii" };
	static const Native AddVehicleComponent =				{  "AddVehicleComponent",					"ii" };
	static const Native ChangeVehicleColor =				{ "ChangeVehicleColor",					"iii" };
	static const Native ChangeVehiclePaintjob =				{  "ChangeVehiclePaintjob",				"ii" };
	static const Native SetVehicleHealth =					{  "SetVehicleHealth",					"if" };
	static const Native GetVehicleHealth =					{  "GetVehicleHealth",					"iv" };
	static const Native AttachTrailerToVehicle =			{  "AttachTrailerToVehicle",				"ii" };
	static const Native DetachTrailerFromVehicle =			{  "DetachTrailerFromVehicle",			"i" };
	static const Native IsTrailerAttachedToVehicle =		{  "IsTrailerAttachedToVehicle",			"i" };
	static const Native GetVehicleModel =					{  "GetVehicleModel",					"d"};
	static const Native SetVehicleNumberPlate =				{  "SetVehicleNumberPlate",				"is" };
	static const Native SetVehicleVirtualWorld =			{  "SetVehicleVirtualWorld",				"ii" };
	static const Native GetVehicleVirtualWorld =			{  "GetVehicleVirtualWorld",				"i" };
	static const Native ApplyAnimation =					{ "ApplyAnimation",						"issfiiiii" };

	// a_objects.inc
	static const Native CreateObject =						{ "CreateObject",						"ifffffff" };
	static const Native SetObjectPos =						{  "SetObjectPos",						"ifff" };
	static const Native GetObjectPos =						{  "GetObjectPos",						"ivvv" };
	static const Native SetObjectRot =						{  "SetObjectRot",						"ifff" };
	static const Native GetObjectRot =						{  "GetObjectRot",						"ivvv" };
	static const Native IsValidObject =						{  "IsValidObject",						"i" };
	static const Native DestroyObject =						{  "DestroyObject",						"i" };
	static const Native MoveObject =						{  "MoveObject",							"iffff" };
	static const Native StopObject =						{  "StopObject ",							"i" };
	static const Native CreatePlayerObject =				{  "CreatePlayerObject",					"iiffffff" };
	static const Native SetPlayerObjectPos =				{  "SetPlayerObjectPos",					"iifff" };
	static const Native GetPlayerObjectPos =				{  "GetPlayerObjectPos",					"iivvv" };
	static const Native GetPlayerObjectRot =				{  "GetPlayerObjectRot",					"iivvv" };
	static const Native SetPlayerObjectRot =				{  "SetPlayerObjectRot",					"iifff" };
	static const Native IsValidPlayerObject =				{  "IsValidPlayerObject",					"ii" };
	static const Native DestroyPlayerObject =				{  "DestroyPlayerObject",					"ii" };
	static const Native MovePlayerObject =					{  "MovePlayerObject",					"iiffff" };
	static const Native StopPlayerObject =					{  "StopPlayerObject",					"ii" };

	// Menu's
	static const Native CreateMenu =						{  "CreateMenu",							"siffff" };
	static const Native DestroyMenu =						{  "DestroyMenu",							"i" };
	static const Native AddMenuItem =						{  "AddMenuItem",							"iis" };
	static const Native SetMenuColumnHeader =				{  "SetMenuColumnHeader",					"iis" };
	static const Native ShowMenuForPlayer =					{  "ShowMenuForPlayer",					"ii" };
	static const Native HideMenuForPlayer =					{  "HideMenuForPlayer",					"ii" };
	static const Native IsValidMenu =						{  "IsValidMenu",							"i" };
	static const Native DisableMenu =						{  "DisableMenu",							"i" };
	static const Native DisableMenuRow =					{  "DisableMenuRow",						"ii" };

	// Textdraw
	static const Native TextDrawCreate =					{ "TextDrawCreate",						"ffs" };
	static const Native TextDrawDestroy =					{  "TextDrawDestroy",						"i" };
	static const Native TextDrawLetterSize =				{ "TextDrawLetterSize",					"iff" };
	static const Native TextDrawTextSize =					{  "TextDrawTextSize",					"iff" };
	static const Native TextDrawAlignment =					{  "TextDrawAlignment",					"ii" };
	static const Native TextDrawColor =						{  "TextDrawColor",						"ii" };
	static const Native TextDrawUseBox =					{  "TextDrawUseBox",						"ii" };
	static const Native TextDrawBoxColor =					{  "TextDrawBoxColor",					"ii" };
	static const Native TextDrawSetShadow =					{  "TextDrawSetShadow",					"ii" };
	static const Native TextDrawSetOutline =				{  "TextDrawSetOutline",					"ii" };
	static const Native TextDrawBackgroundColor =			{  "TextDrawBackgroundColor",				"ii" };
	static const Native TextDrawFont =						{ "TextDrawFont",						"ii" };
	static const Native TextDrawSetProportional =			{  "TextDrawSetProportional",				"ii" };
	static const Native TextDrawShowForPlayer =				{  "TextDrawShowForPlayer",				"ii" };
	static const Native TextDrawHideForPlayer =				{  "TextDrawHideForPlayer",				"ii" };
	static const Native TextDrawShowForAll =				{ "TextDrawShowForAll",					"i" };
	static const Native TextDrawHideForAll =				{ "TextDrawHideForAll",					"i" };

};

class Invoke {
    public:
        Invoke() {
            gotAddresses = false;
        }
        int Call_Native(const INVOKE::Native * native, ...);
        int getAddresses();
        int amx_idx;
        std::list<AMX *> amx_list;
    
    private:
        bool gotAddresses;
        std::map<std::string, unsigned int> amx_map;
};

typedef int(* amx_Function_t) (AMX * amx, cell * params);
extern Invoke * g_Invoke;