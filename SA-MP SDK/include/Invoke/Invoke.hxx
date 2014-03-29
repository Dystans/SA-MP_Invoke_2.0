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

namespace INVOKE {
	struct Native {
		const char * name;
		const char * data;
	};
#define NATIVE static const Native

	static const char * const names[] = {
		// a_http:
		"HTTP",

		// a_npc:
		"print",
		"printf",
		"format",
		"SetTimer",
		"KillTimer",
		"GetTickCount",
		"asin",
		"acos",
		"atan",
		"atan2",
		"SendChat",
		"SendCommand",
		"GetPlayerState",
		"GetPlayerPos",
		"GetPlayerVehicleID",
		"GetPlayerArmedWeapon",
		"GetPlayerHealth",
		"GetPlayerArmour",
		"GetPlayerSpecialAction",
		"IsPlayerStreamedIn",
		"IsVehicleStreamedIn",
		"GetPlayerKeys",
		"GetPlayerFacingAngle",
		"GetMyPos",
		"SetMyPos",
		"GetMyFacingAngle",
		"SetMyFacingAngle",
		"GetDistanceFromMeToPoint",
		"IsPlayerInRangeOfPoint",
		"GetPlayerName",
		"IsPlayerConnected",
		"StartRecordingPlayback",
		"StopRecordingPlayback",
		"PauseRecordingPlayback",
		"ResumeRecordingPlayback",

		// a_objects:
		"CreateObject",
		"AttachObjectToVehicle",
		"AttachObjectToObject",
		"AttachObjectToPlayer",
		"SetObjectPos",
		"GetObjectPos",
		"SetObjectRot",
		"GetObjectRot",
		"IsValidObject",
		"DestroyObject",
		"MoveObject",
		"StopObject",
		"IsObjectMoving",
		"EditObject",
		"EditPlayerObject",
		"SelectObject",
		"CancelEdit",
		"CreatePlayerObject",
		"AttachPlayerObjectToVehicle",
		"SetPlayerObjectPos",
		"GetPlayerObjectPos",
		"SetPlayerObjectRot",
		"GetPlayerObjectRot",
		"IsValidPlayerObject",
		"DestroyPlayerObject",
		"MovePlayerObject",
		"StopPlayerObject",
		"IsPlayerObjectMoving",
		"AttachPlayerObjectToPlayer",
		"SetObjectMaterial",
		"SetPlayerObjectMaterial",
		"SetObjectMaterialText",
		"SetPlayerObjectMaterialText",

		// a_players:
		"SetSpawnInfo",
		"SpawnPlayer",
		"SetPlayerPos",
		"SetPlayerPosFindZ",
		"GetPlayerPos",
		"SetPlayerFacingAngle",
		"GetPlayerFacingAngle",
		"IsPlayerInRangeOfPoint",
		"GetPlayerDistanceFromPoint",
		"IsPlayerStreamedIn",
		"SetPlayerInterior",
		"GetPlayerInterior",
		"SetPlayerHealth",
		"GetPlayerHealth",
		"SetPlayerArmour",
		"GetPlayerArmour",
		"SetPlayerAmmo",
		"GetPlayerAmmo",
		"GetPlayerWeaponState",
		"GetPlayerTargetPlayer",
		"SetPlayerTeam",
		"GetPlayerTeam",
		"SetPlayerScore",
		"GetPlayerScore",
		"GetPlayerDrunkLevel",
		"SetPlayerDrunkLevel",
		"SetPlayerColor",
		"GetPlayerColor",
		"SetPlayerSkin",
		"GetPlayerSkin",
		"GivePlayerWeapon",
		"ResetPlayerWeapons",
		"SetPlayerArmedWeapon",
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
		"SetPlayerTime",
		"GetPlayerTime",
		"TogglePlayerClock",
		"SetPlayerWeather",
		"ForceClassSelection",
		"SetPlayerWantedLevel",
		"GetPlayerWantedLevel",
		"SetPlayerFightingStyle",
		"GetPlayerFightingStyle",
		"SetPlayerVelocity",
		"GetPlayerVelocity",
		"PlayCrimeReportForPlayer",
		"PlayAudioStreamForPlayer",
		"StopAudioStreamForPlayer",
		"SetPlayerShopName",
		"SetPlayerSkillLevel",
		"GetPlayerSurfingVehicleID",
		"GetPlayerSurfingObjectID",
		"RemoveBuildingForPlayer",
		"GetPlayerLastShotVectors",
		"SetPlayerAttachedObject",
		"RemovePlayerAttachedObject",
		"IsPlayerAttachedObjectSlotUsed",
		"EditAttachedObject",
		"PlayerText:CreatePlayerTextDraw",
		"PlayerTextDrawDestroy",
		"PlayerTextDrawLetterSize",
		"PlayerTextDrawTextSize",
		"PlayerTextDrawAlignment",
		"PlayerTextDrawColor",
		"PlayerTextDrawUseBox",
		"PlayerTextDrawBoxColor",
		"PlayerTextDrawSetShadow",
		"PlayerTextDrawSetOutline",
		"PlayerTextDrawBackgroundColor",
		"PlayerTextDrawFont",
		"PlayerTextDrawSetProportional",
		"PlayerTextDrawSetSelectable",
		"PlayerTextDrawShow",
		"PlayerTextDrawHide",
		"PlayerTextDrawSetString",
		"PlayerTextDrawSetPreviewModel",
		"PlayerTextDrawSetPreviewRot",
		"PlayerTextDrawSetPreviewVehCol",
		"SetPVarInt",
		"GetPVarInt",
		"SetPVarString",
		"GetPVarString",
		"SetPVarFloat",
		"GetPVarFloat",
		"DeletePVar",
		"GetPVarsUpperIndex",
		"GetPVarNameAtIndex",
		"GetPVarType",
		"SetPlayerChatBubble",
		"PutPlayerInVehicle",
		"GetPlayerVehicleID",
		"GetPlayerVehicleSeat",
		"RemovePlayerFromVehicle",
		"TogglePlayerControllable",
		"PlayerPlaySound",
		"ApplyAnimation",
		"ClearAnimations",
		"GetPlayerAnimationIndex",
		"GetAnimationName",
		"GetPlayerSpecialAction",
		"SetPlayerSpecialAction",
		"SetPlayerCheckpoint",
		"DisablePlayerCheckpoint",
		"SetPlayerRaceCheckpoint",
		"DisablePlayerRaceCheckpoint",
		"SetPlayerWorldBounds",
		"SetPlayerMarkerForPlayer",
		"ShowPlayerNameTagForPlayer",
		"SetPlayerMapIcon",
		"RemovePlayerMapIcon",
		"AllowPlayerTeleport",
		"SetPlayerCameraPos",
		"SetPlayerCameraLookAt",
		"SetCameraBehindPlayer",
		"GetPlayerCameraPos",
		"GetPlayerCameraFrontVector",
		"GetPlayerCameraMode",
		"GetPlayerCameraAspectRatio",
		"GetPlayerCameraZoom",
		"AttachCameraToObject",
		"AttachCameraToPlayerObject",
		"InterpolateCameraPos",
		"InterpolateCameraLookAt",
		"IsPlayerConnected",
		"IsPlayerInVehicle",
		"IsPlayerInAnyVehicle",
		"IsPlayerInCheckpoint",
		"IsPlayerInRaceCheckpoint",
		"SetPlayerVirtualWorld",
		"GetPlayerVirtualWorld",
		"EnableStuntBonusForPlayer",
		"EnableStuntBonusForAll",
		"TogglePlayerSpectating",
		"PlayerSpectatePlayer",
		"PlayerSpectateVehicle",
		"StartRecordingPlayerData",
		"StopRecordingPlayerData",
		"SelectTextDraw",
		"CancelSelectTextDraw",

		// a_samp:
		"SendClientMessage",
		"SendClientMessageToAll",
		"SendPlayerMessageToPlayer",
		"SendPlayerMessageToAll",
		"SendDeathMessage",
		"GameTextForAll",
		"GameTextForPlayer",
		"GetTickCount",
		"GetMaxPlayers",
		"CallRemoteFunction",
		"CallLocalFunction",
		"VectorSize",
		"SetGameModeText",
		"SetTeamCount",
		"AddPlayerClass",
		"AddPlayerClassEx",
		"AddStaticVehicle",
		"AddStaticVehicleEx",
		"AddStaticPickup",
		"CreatePickup",
		"DestroyPickup",
		"ShowNameTags",
		"ShowPlayerMarkers",
		"GameModeExit",
		"SetWorldTime",
		"GetWeaponName",
		"EnableTirePopping",
		"EnableVehicleFriendlyFire",
		"AllowInteriorWeapons",
		"SetWeather",
		"SetGravity",
		"AllowAdminTeleport",
		"SetDeathDropAmount",
		"CreateExplosion",
		"EnableZoneNames",
		"UsePlayerPedAnims",
		"DisableInteriorEnterExits",
		"SetNameTagDrawDistance",
		"DisableNameTagLOS",
		"LimitGlobalChatRadius",
		"LimitPlayerMarkerRadius",
		"ConnectNPC",
		"IsPlayerNPC",
		"IsPlayerAdmin",
		"Kick",
		"Ban",
		"BanEx",
		"SendRconCommand",
		"GetServerVarAsString",
		"GetServerVarAsInt",
		"GetServerVarAsBool",
		"GetPlayerNetworkStats",
		"GetNetworkStats",
		"GetPlayerVersion",
		"GetServerTickRate",
		"NetStats_GetConnectedTime",
		"NetStats_MessagesReceived",
		"NetStats_BytesReceived",
		"NetStats_MessagesSent",
		"NetStats_BytesSent",
		"NetStats_MessagesRecvPerSecond",
		"NetStats_PacketLossPercent",
		"NetStats_ConnectionStatus",
		"NetStats_GetIpPort",
		"CreateMenu",
		"DestroyMenu",
		"AddMenuItem",
		"SetMenuColumnHeader",
		"ShowMenuForPlayer",
		"HideMenuForPlayer",
		"IsValidMenu",
		"DisableMenu",
		"DisableMenuRow",
		"GetPlayerMenu",
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
		"TextDrawSetSelectable",
		"TextDrawShowForPlayer",
		"TextDrawHideForPlayer",
		"TextDrawShowForAll",
		"TextDrawHideForAll",
		"TextDrawSetString",
		"TextDrawSetPreviewModel",
		"TextDrawSetPreviewRot",
		"TextDrawSetPreviewVehCol",
		"GangZoneCreate",
		"GangZoneDestroy",
		"GangZoneShowForPlayer",
		"GangZoneShowForAll",
		"GangZoneHideForPlayer",
		"GangZoneHideForAll",
		"GangZoneFlashForPlayer",
		"GangZoneFlashForAll",
		"GangZoneStopFlashForPlayer",
		"GangZoneStopFlashForAll",
		"Text3D:Create3DTextLabel",
		"Delete3DTextLabel",
		"Attach3DTextLabelToPlayer",
		"Attach3DTextLabelToVehicle",
		"Update3DTextLabelText",
		"PlayerText3D:CreatePlayer3DTextLabel",
		"DeletePlayer3DTextLabel",
		"UpdatePlayer3DTextLabelText",
		"ShowPlayerDialog",

		// a_sampdb:
		"db_open",
		"db_close",
		"db_query",
		"db_free_result",
		"db_num_rows",
		"db_next_row",
		"db_num_fields",
		"db_field_name",
		"db_get_field",
		"db_get_field_assoc",

		// a_vehicles:
		"CreateVehicle",
		"DestroyVehicle",
		"IsVehicleStreamedIn",
		"GetVehiclePos",
		"SetVehiclePos",
		"GetVehicleZAngle",
		"GetVehicleRotationQuat",
		"GetVehicleDistanceFromPoint",
		"SetVehicleZAngle",
		"SetVehicleParamsForPlayer",
		"ManualVehicleEngineAndLights",
		"SetVehicleParamsEx",
		"GetVehicleParamsEx",
		"SetVehicleToRespawn",
		"LinkVehicleToInterior",
		"AddVehicleComponent",
		"RemoveVehicleComponent",
		"ChangeVehicleColor",
		"ChangeVehiclePaintjob",
		"SetVehicleHealth",
		"GetVehicleHealth",
		"AttachTrailerToVehicle",
		"DetachTrailerFromVehicle",
		"IsTrailerAttachedToVehicle",
		"GetVehicleTrailer",
		"SetVehicleNumberPlate",
		"GetVehicleModel",
		"GetVehicleComponentInSlot",
		"GetVehicleComponentType",
		"RepairVehicle",
		"GetVehicleVelocity",
		"SetVehicleVelocity",
		"SetVehicleAngularVelocity",
		"GetVehicleDamageStatus",
		"UpdateVehicleDamageStatus",
		"GetVehicleModelInfo",
		"SetVehicleVirtualWorld",
		"GetVehicleVirtualWorld",
	};

	// a_http:
	// HTTP(index, type, url[], data[], callback[]);
	NATIVE HTTP = {"HTTP", "iisss"};

	// a_npc:
	NATIVE print = {"print", "s"};
	NATIVE SetTimer = {"SetTimer", "sii"};
	NATIVE KillTimer = {"KillTimer", "i"};
	NATIVE GetTickCount = {"GetTickCount", ""};
	NATIVE asin = {"asin", "f"};
	NATIVE acos = {"acos", "f"};
	NATIVE atan = {"atan", "f"};
	NATIVE atan2 = {"atan2", "ff"};
	NATIVE SendChat = {"SendChat", "s"};
	NATIVE SendCommand = {"SendCommand", "s"};
	NATIVE GetPlayerState = {"GetPlayerState", "d"};
	NATIVE GetPlayerPos = {"GetPlayerPos", "dvvv"};
	NATIVE GetPlayerVehicleID = {"GetPlayerVehicleID", "d"};
	NATIVE GetPlayerArmedWeapon = {"GetPlayerArmedWeapon", "d"};
	NATIVE GetPlayerHealth = {"GetPlayerHealth", "d"};
	NATIVE GetPlayerArmour = {"GetPlayerArmour", "d"};
	NATIVE GetPlayerSpecialAction = {"GetPlayerSpecialAction", "d"};
	NATIVE IsPlayerStreamedIn = {"IsPlayerStreamedIn", "d"};
	NATIVE IsVehicleStreamedIn = {"IsVehicleStreamedIn", "d"};
	NATIVE GetPlayerKeys = {"GetPlayerKeys", "dvvv"};
	NATIVE GetPlayerFacingAngle = {"GetPlayerFacingAngle", "dv"};
	NATIVE GetMyPos = {"GetMyPos", "vvv"};
	NATIVE SetMyPos = {"SetMyPos", "fff"};
	NATIVE GetMyFacingAngle = {"GetMyFacingAngle", "v"};
	NATIVE SetMyFacingAngle = {"SetMyFacingAngle", "f"};
	NATIVE GetDistanceFromMeToPoint = {"GetDistanceFromMeToPoint", "vvvv"};
	NATIVE IsPlayerInRangeOfPoint = {"IsPlayerInRangeOfPoint", "dffff"};
	NATIVE GetPlayerName = {"GetPlayerName", "dpd"};
	NATIVE IsPlayerConnected = {"IsPlayerConnected", "d"};
	NATIVE StartRecordingPlayback = {"StartRecordingPlayback", "ds"};
	NATIVE StopRecordingPlayback = {"StopRecordingPlayback", ""};
	NATIVE PauseRecordingPlayback = {"PauseRecordingPlayback", ""};
	NATIVE ResumeRecordingPlayback = {"ResumeRecordingPlayback", ""};

	// a_objects:
	NATIVE CreateObject = {"CreateObject", "dfffffff"};
	NATIVE AttachObjectToVehicle = {"AttachObjectToVehicle", "ddffffff"};
	NATIVE AttachObjectToObject = {"AttachObjectToObject", "ddffffffd"};
	NATIVE AttachObjectToPlayer = {"AttachObjectToPlayer", "ddffffff"};
	NATIVE SetObjectPos = {"SetObjectPos", "dfff"};
	NATIVE GetObjectPos = {"GetObjectPos", "dvvv"};
	NATIVE SetObjectRot = {"SetObjectRot", "dfff"};
	NATIVE GetObjectRot = {"GetObjectRot", "dvvv"};
	NATIVE IsValidObject = {"IsValidObject", "d"};
	NATIVE DestroyObject = {"DestroyObject", "d"};
	NATIVE MoveObject = {"MoveObject", "dfffffff"};
	NATIVE StopObject = {"StopObject", "d"};
	NATIVE IsObjectMoving = {"IsObjectMoving", "d"};
	NATIVE EditObject = {"EditObject", "dd"};
	NATIVE EditPlayerObject = {"EditPlayerObject", "dd"};
	NATIVE SelectObject = {"SelectObject", "d"};
	NATIVE CancelEdit = {"CancelEdit", "d"};
	NATIVE CreatePlayerObject = {"CreatePlayerObject", "ddfffffff"};
	NATIVE AttachPlayerObjectToVehicle = {"AttachPlayerObjectToVehicle", "dddffffff"};
	NATIVE SetPlayerObjectPos = {"SetPlayerObjectPos", "ddfff"};
	NATIVE GetPlayerObjectPos = {"GetPlayerObjectPos", "ddvvv"};
	NATIVE SetPlayerObjectRot = {"SetPlayerObjectRot", "ddfff"};
	NATIVE GetPlayerObjectRot = {"GetPlayerObjectRot", "ddvvv"};
	NATIVE IsValidPlayerObject = {"IsValidPlayerObject", "dd"};
	NATIVE DestroyPlayerObject = {"DestroyPlayerObject", "dd"};
	NATIVE MovePlayerObject = {"MovePlayerObject", "ddfffffff"};
	NATIVE StopPlayerObject = {"StopPlayerObject", "dd"};
	NATIVE IsPlayerObjectMoving = {"IsPlayerObjectMoving", "dd"};
	NATIVE AttachPlayerObjectToPlayer = {"AttachPlayerObjectToPlayer", "dddffffff"};
	NATIVE SetObjectMaterial = {"SetObjectMaterial", "dddssd"};
	NATIVE SetPlayerObjectMaterial = {"SetPlayerObjectMaterial", "ddddssd"};
	NATIVE SetObjectMaterialText = {"SetObjectMaterialText", "dsddsddddd"};
	NATIVE SetPlayerObjectMaterialText = {"SetPlayerObjectMaterialText", "ddsddsddddd"};

	// a_players:

	// a_samp:
	NATIVE SendClientMessage =					{ "SendClientMessage","iis" };
	NATIVE SendClientMessageToAll =			{ "SendClientMessageToAll","is" };
	NATIVE SendDeathMessage =					{ "SendDeathMessage","iii" };
	NATIVE GameTextForAll =					{ "GameTextForAll","sii" };
	NATIVE GameTextForPlayer =					{ "GameTextForPlayer",	"isii" };
	NATIVE GetTickCount =						{ "GetTickCount","" };
	NATIVE GetMaxPlayers =						{ "GetMaxPlayers",	"" };
	NATIVE SetGameModeText =					{  "SetGameModeText","s" };
	NATIVE SetTeamCount =						{  "SetTeamCount", "i" };
	NATIVE AddPlayerClass =					{ "AddPlayerClass","iffffiiiiii" };
	NATIVE AddPlayerClassEx =					{ "AddPlayerClassEx","iiffffiiiiii" };
	NATIVE AddStaticVehicle =					{ "AddStaticVehicle","iffffii" };
	NATIVE AddStaticVehicleEx =				{ "AddStaticVehicleEx","iffffiii" };
	NATIVE AddStaticPickup =					{ "AddStaticPickup","iifff" };
	NATIVE ShowNameTags =						{ "ShowNameTags","i" };
	NATIVE ShowPlayerMarkers =					{ "ShowPlayerMarkers",	"i" };
	NATIVE GameModeExit =						{ "GameModeExit","" };
	NATIVE SetWorldTime =						{"SetWorldTime","i" };
	NATIVE GetWeaponName =						{ "GetWeaponName",	"ivi" };
	NATIVE EnableTirePopping =					{ "EnableTirePopping","i" };
	NATIVE AllowInteriorWeapons =				{ "AllowInteriorWeapons","i" };
	NATIVE SetWeather =						{ "SetWeather","i" };
	NATIVE SetGravity =						{ "SetGravity","f" };
	NATIVE AllowAdminTeleport =				{  "AllowAdminTeleport","i" };
	NATIVE SetDeathDropAmount =				{ "SetDeathDropAmount","i" };
	NATIVE CreateExplosion =					{ "CreateExplosion","fffif" };
	NATIVE EnableZoneNames =					{ "EnableZoneNames","i" };
	NATIVE IsPlayerAdmin =						{ "IsPlayerAdmin",	"i" };
	NATIVE Kick =								{ "Kick","i" };
	NATIVE Ban =								{ "Ban",	"i" };
	NATIVE SendRconCommand =					{ "SendRconCommand",	"s" };
	NATIVE ShowPlayerDialog =					{ "ShowPlayerDialog",	"dddssss"};

	// a_players.inc
	NATIVE SetSpawnInfo =						{ "SetSpawnInfo","iiiffffiiiiii" };
	NATIVE SpawnPlayer =						{ "SpawnPlayer","i" };
	NATIVE SetPlayerPos =						{ "SetPlayerPos","ifff" };
	NATIVE GetPlayerPos =						{ "GetPlayerPos","ivvv" };
	NATIVE SetPlayerFacingAngle =				{ "SetPlayerFacingAngle","if" };
	NATIVE GetPlayerFacingAngle =				{ "GetPlayerFacingAngle","iv" };
	NATIVE SetPlayerInterior =					{ "SetPlayerInterior",	"ii" };
	NATIVE GetPlayerInterior =					{ "GetPlayerInterior",	"i" };
	NATIVE SetPlayerHealth =					{ "SetPlayerHealth",						"if" };
	NATIVE GetPlayerHealth =					{ "GetPlayerHealth",						"iv" };
	NATIVE SetPlayerArmour =					{ "SetPlayerArmour",						"if" };
	NATIVE GetPlayerArmour =					{ "GetPlayerArmour",						"iv" };
	NATIVE SetPlayerAmmo =						{ "SetPlayerAmmo",						"iii" };
	NATIVE GetPlayerAmmo =						{ "GetPlayerAmmo",						"i" };
	NATIVE SetPlayerTeam =						{ "SetPlayerTeam",						"ii" };
	NATIVE GetPlayerTeam =						{ "GetPlayerTeam",						"i" };
	NATIVE SetPlayerScore =					{  "SetPlayerScore",						"ii" };
	NATIVE GetPlayerScore =					{  "GetPlayerScore",						"i" };
	NATIVE SetPlayerColor =					{  "SetPlayerColor",						"ii" };
	NATIVE GetPlayerColor =					{  "GetPlayerColor",						"i" };
	NATIVE SetPlayerSkin =						{  "SetPlayerSkin",						"ii" };
	NATIVE GivePlayerWeapon =					{  "GivePlayerWeapon",					"iii" };
	NATIVE ResetPlayerWeapons =				{ "ResetPlayerWeapons",					"i" };
	NATIVE GetPlayerWeaponData =				{  "GetPlayerWeaponData",					"iiiviv " };
	NATIVE GivePlayerMoney =					{  "GivePlayerMoney",						"ii" };
	NATIVE ResetPlayerMoney =					{  "ResetPlayerMoney",					"i" };
	NATIVE SetPlayerName =						{  "SetPlayerName",						"is" };
	NATIVE GetPlayerMoney =					{  "GetPlayerMoney",						"i" };
	NATIVE GetPlayerState =					{  "GetPlayerState",						"i" };
	NATIVE GetPlayerIp =						{  "GetPlayerIp",							"ipi" };
	NATIVE GetPlayerPing =						{  "GetPlayerPing",						"i" };
	NATIVE GetPlayerWeapon =					{  "GetPlayerWeapon",						"i" };
	NATIVE GetPlayerKeys =						{  "GetPlayerKeys",						"ivvv" };
	NATIVE GetPlayerName =						{  "GetPlayerName",						"ipi" };
	NATIVE PutPlayerInVehicle =				{  "PutPlayerInVehicle",					"iii" };
	NATIVE GetPlayerVehicleID =				{  "GetPlayerVehicleID",					"i" };
	NATIVE RemovePlayerFromVehicle =			{  "RemovePlayerFromVehicle",				"i" };
	NATIVE TogglePlayerControllable =			{  "TogglePlayerControllable",			"ii" };
	NATIVE PlayerPlaySound =					{  "PlayerPlaySound",						"iifff" };
	NATIVE SetPlayerCheckpoint =				{  "SetPlayerCheckpoint",					"iffff" };
	NATIVE DisablePlayerCheckpoint =			{  "DisablePlayerCheckpoint",				"i" };
	NATIVE SetPlayerRaceCheckpoint =			{  "SetPlayerRaceCheckpoint",				"iifffffff" };
	NATIVE DisablePlayerRaceCheckpoint =		{  "DisablePlayerRaceCheckpoint",			"i" };
	NATIVE SetPlayerWorldBounds =				{  "SetPlayerWorldBounds",				"iffff" };
	NATIVE SetPlayerMarkerForPlayer =			{  "SetPlayerMarkerForPlayer",			"iii" };
	NATIVE ShowPlayerNameTagForPlayer =		{  "ShowPlayerNameTagForPlayer",			"iii" };
	NATIVE SetPlayerMapIcon =					{  "SetPlayerMapIcon",					"iifffii" };
	NATIVE RemovePlayerMapIcon =				{  "RemovePlayerMapIcon",					"ii" };
	NATIVE SetPlayerCameraPos =				{  "SetPlayerCameraPos",					"ifff" };
	NATIVE SetPlayerCameraLookAt =				{  "SetPlayerCameraLookAt",				"ifff" };
	NATIVE SetCameraBehindPlayer =				{  "SetCameraBehindPlayer",				"i" };
	NATIVE AllowPlayerTeleport =				{  "AllowPlayerTeleport",					"ii" };
	NATIVE IsPlayerConnected =					{  "IsPlayerConnected"					"i" };
	NATIVE IsPlayerInVehicle =					{  "IsPlayerInVehicle",					"ii" };
	NATIVE IsPlayerInAnyVehicle =				{  "IsPlayerInAnyVehicle",				"i" };
	NATIVE IsPlayerInCheckpoint =				{  "IsPlayerInCheckpoint",				"i" };
	NATIVE IsPlayerInRaceCheckpoint =			{  "IsPlayerInRaceCheckpoint",			"i" };
	NATIVE SetPlayerTime =						{  "SetPlayerTime",						"iii" };
	NATIVE TogglePlayerClock =					{  "TogglePlayerClock",					"ii" };
	NATIVE SetPlayerWeather =					{  "SetPlayerWeather",					"ii" };
	NATIVE GetPlayerTime =						{  "GetPlayerTime",						"ivv" };
	NATIVE SetPlayerVirtualWorld =				{  "SetPlayerVirtualWorld",				"ii" };
	NATIVE GetPlayerVirtualWorld =				{  "GetPlayerVirtualWorld",				"i" };

	// a_vehicle.inc
	NATIVE CreateVehicle =						{  "CreateVehicle",						"iffffiii" };
	NATIVE DestroyVehicle =					{  "DestroyVehicle",						"i" };
	NATIVE GetVehiclePos =						{  "GetVehiclePos",						"ivvv" };
	NATIVE SetVehiclePos =						{  "SetVehiclePos",						"ifff" };
	NATIVE GetVehicleZAngle =					{  "GetVehicleZAngle",					"iv" };
	NATIVE SetVehicleZAngle =					{  "SetVehicleZAngle",					"if" };
	NATIVE SetVehicleParamsForPlayer =			{  "SetVehicleParamsForPlayer",			"iiii" };
	NATIVE SetVehicleToRespawn =				{  "SetVehicleToRespawn",					"i" };
	NATIVE LinkVehicleToInterior =				{ "LinkVehicleToInterior",				"ii" };
	NATIVE AddVehicleComponent =				{  "AddVehicleComponent",					"ii" };
	NATIVE ChangeVehicleColor =				{ "ChangeVehicleColor",					"iii" };
	NATIVE ChangeVehiclePaintjob =				{  "ChangeVehiclePaintjob",				"ii" };
	NATIVE SetVehicleHealth =					{  "SetVehicleHealth",					"if" };
	NATIVE GetVehicleHealth =					{  "GetVehicleHealth",					"iv" };
	NATIVE AttachTrailerToVehicle =			{  "AttachTrailerToVehicle",				"ii" };
	NATIVE DetachTrailerFromVehicle =			{  "DetachTrailerFromVehicle",			"i" };
	NATIVE IsTrailerAttachedToVehicle =		{  "IsTrailerAttachedToVehicle",			"i" };
	NATIVE GetVehicleModel =					{  "GetVehicleModel",					"d"};
	NATIVE SetVehicleNumberPlate =				{  "SetVehicleNumberPlate",				"is" };
	NATIVE SetVehicleVirtualWorld =			{  "SetVehicleVirtualWorld",				"ii" };
	NATIVE GetVehicleVirtualWorld =			{  "GetVehicleVirtualWorld",				"i" };
	NATIVE ApplyAnimation =					{ "ApplyAnimation",						"issfiiiii" };

	// a_objects.inc
	NATIVE CreateObject =						{ "CreateObject",						"ifffffff" };
	NATIVE SetObjectPos =						{  "SetObjectPos",						"ifff" };
	NATIVE GetObjectPos =						{  "GetObjectPos",						"ivvv" };
	NATIVE SetObjectRot =						{  "SetObjectRot",						"ifff" };
	NATIVE GetObjectRot =						{  "GetObjectRot",						"ivvv" };
	NATIVE IsValidObject =						{  "IsValidObject",						"i" };
	NATIVE DestroyObject =						{  "DestroyObject",						"i" };
	NATIVE MoveObject =						{  "MoveObject",							"iffff" };
	NATIVE StopObject =						{  "StopObject ",							"i" };
	NATIVE CreatePlayerObject =				{  "CreatePlayerObject",					"iiffffff" };
	NATIVE SetPlayerObjectPos =				{  "SetPlayerObjectPos",					"iifff" };
	NATIVE GetPlayerObjectPos =				{  "GetPlayerObjectPos",					"iivvv" };
	NATIVE GetPlayerObjectRot =				{  "GetPlayerObjectRot",					"iivvv" };
	NATIVE SetPlayerObjectRot =				{  "SetPlayerObjectRot",					"iifff" };
	NATIVE IsValidPlayerObject =				{  "IsValidPlayerObject",					"ii" };
	NATIVE DestroyPlayerObject =				{  "DestroyPlayerObject",					"ii" };
	NATIVE MovePlayerObject =					{  "MovePlayerObject",					"iiffff" };
	NATIVE StopPlayerObject =					{  "StopPlayerObject",					"ii" };

	// Menu's
	NATIVE CreateMenu =						{  "CreateMenu",							"siffff" };
	NATIVE DestroyMenu =						{  "DestroyMenu",							"i" };
	NATIVE AddMenuItem =						{  "AddMenuItem",							"iis" };
	NATIVE SetMenuColumnHeader =				{  "SetMenuColumnHeader",					"iis" };
	NATIVE ShowMenuForPlayer =					{  "ShowMenuForPlayer",					"ii" };
	NATIVE HideMenuForPlayer =					{  "HideMenuForPlayer",					"ii" };
	NATIVE IsValidMenu =						{  "IsValidMenu",							"i" };
	NATIVE DisableMenu =						{  "DisableMenu",							"i" };
	NATIVE DisableMenuRow =					{  "DisableMenuRow",						"ii" };

	// Textdraw
	NATIVE TextDrawCreate =					{ "TextDrawCreate",						"ffs" };
	NATIVE TextDrawDestroy =					{  "TextDrawDestroy",						"i" };
	NATIVE TextDrawLetterSize =				{ "TextDrawLetterSize",					"iff" };
	NATIVE TextDrawTextSize =					{  "TextDrawTextSize",					"iff" };
	NATIVE TextDrawAlignment =					{  "TextDrawAlignment",					"ii" };
	NATIVE TextDrawColor =						{  "TextDrawColor",						"ii" };
	NATIVE TextDrawUseBox =					{  "TextDrawUseBox",						"ii" };
	NATIVE TextDrawBoxColor =					{  "TextDrawBoxColor",					"ii" };
	NATIVE TextDrawSetShadow =					{  "TextDrawSetShadow",					"ii" };
	NATIVE TextDrawSetOutline =				{  "TextDrawSetOutline",					"ii" };
	NATIVE TextDrawBackgroundColor =			{  "TextDrawBackgroundColor",				"ii" };
	NATIVE TextDrawFont =						{ "TextDrawFont",						"ii" };
	NATIVE TextDrawSetProportional =			{  "TextDrawSetProportional",				"ii" };
	NATIVE TextDrawShowForPlayer =				{  "TextDrawShowForPlayer",				"ii" };
	NATIVE TextDrawHideForPlayer =				{  "TextDrawHideForPlayer",				"ii" };
	NATIVE TextDrawShowForAll =				{ "TextDrawShowForAll",					"i" };
	NATIVE TextDrawHideForAll =				{ "TextDrawHideForAll",					"i" };

};
#define PAWN INVOKE

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

typedef int(* amx_Function_t) (AMX * amx, long int * params);
extern Invoke * Invoke_Call;

#define callNative Call_Native
#define gInvoke Invoke_Call