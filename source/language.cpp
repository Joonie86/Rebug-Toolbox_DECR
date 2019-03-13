/*
# Portions of code and idea for localization by:
# (c) 2006 Eugene Plotnikov <e-plotnikov@operamail.com>
# SMS Media Player for PS2 / PS2DEV Open Source Project
# Used: SMS_Locale.h, SMS_Locale.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "language.h"

static unsigned char s_pDebugMode	[]	= "Debug Mode";
static unsigned char s_pQuit0		[]	= "Quit to XMB\xE2\x84\xA2";
static unsigned char s_pQuit1		[]	= "Quit to XMB\xE2\x84\xA2 screen?";
static unsigned char s_pRestart0	[]	= "Restart " STR_MM_NAME "?";

static unsigned char s_pWarnFTP		[]	= "There are active FTP connections!\n\nAre you sure you want to continue and abort FTP transfers?";

static unsigned char s_pWarnSNES	[]	= "To play SNES games you must install the latest version of SNEX9x for the PS3\xE2\x84\xA2";
static unsigned char s_pWarnGEN		[]	= "To play Genesis+ GX games you must install the latest version of GENESIS Emulator for the PS3\xE2\x84\xA2";
static unsigned char s_pWarnFCEU	[]	= "To play NES/FCE Ultra games you must install the latest version of FCEU Emulator for the PS3\xE2\x84\xA2";
static unsigned char s_pWarnVBA		[]	= "To play GameBoy/Advanced games you must install the latest version of VBA Emulator for the PS3\xE2\x84\xA2";
static unsigned char s_pWarnFBA		[]	= "To play FBA games you must install the latest version of FB Alpha/Next for the PS3\xE2\x84\xA2";

static unsigned char s_pCopy0		[]	= "Copying %d files (%1.3f GB), please wait...";
static unsigned char s_pCopy1		[]	= "Copying %d files, please wait...";
static unsigned char s_pCopy2		[]	= "Creating links for %d files (%1.3f GB), please wait...";
static unsigned char s_pCopy3		[]	= "Installing Game Files to HDD cache, please wait...";
static unsigned char s_pCopy4		[]	= "Copying over %d+ files (%1.3f+ GB), please wait...";
static unsigned char s_pCopy5		[]	= "Copying, please wait!";
static unsigned char s_pCopy6		[]	= "Copying file, please wait...";

static unsigned char s_pCopy7		[]	= "Do you want to create a shadow copy of the selected folder?\n\nSource: [%s]\n\nDestination: [/dev_hdd0/G/<special_pkg_id>";
static unsigned char s_pCopy8		[]	= "Do you want to create a shadow copy of the selected folder?\n\nSource: [%s]\n\nDestination: [%s/%s]";
static unsigned char s_pCopy9		[]	= "Do you want to copy the selected folders?\n\nSource: [%s]\n\nDestination: [%s]";
static unsigned char s_pCopy10		[]	= "Do you want to enable BD-ROM GAME DISC mirror on external USB?\n\nSource: [%s]\n\nDestination: [Emulated BD-ROM on USB device]";
static unsigned char s_pCopy11		[]	= "Do you want to copy the selected file?\n\nSource: [%s]\n\nDestination: [%s/%s]";
static unsigned char s_pCopy12		[]	= "Do you want to copy selected %i files?\n\nSource: [%s]\n\nDestination: [%s]";

static unsigned char s_pNetCopy0	[]	= "Copying network folder (%i files in %i folders) from [%s], please wait!";
static unsigned char s_pNetCopy1	[]	= "Copying file to network host [%s], please wait!";
static unsigned char s_pNetCopy2	[]	= "Copying network file from [%s], please wait!";
static unsigned char s_pNetCopy3	[]	= "Copying local folder (%i files in %i folders) to network host [%s], please wait!";
static unsigned char s_pNetCopy4	[]	= "Transferred %.0f/%.0f MB. Remaining: %i:%2.2i min";

static unsigned char s_pMove0		[]	= "Do you want to move the selected folders?\n\nSource: [%s]\n\nDestination: [%s]";
static unsigned char s_pMove1		[]	= "Do you want to move the selected file?\n\nSource: [%s]\n\nDestination: [%s/%s]";
static unsigned char s_pMove2		[]	= "Do you want to move selected %i files?\n\nSource: [%s]\n\nDestination: [%s]";
static unsigned char s_pMove3		[]	= "Moving, please wait!";
static unsigned char s_pMove4		[]	= "Moving file, please wait...";

static unsigned char s_pWarnINET	[]	= "Internet connection is not available or an error has occurred!";
static unsigned char s_pErrSRV0		[]	= "Error occurred while contacting the server!\n\nPlease try again later.";
static unsigned char s_pErrUPD0		[]	= "Error occurred while downloading the update!\n\nPlease try again later.";
static unsigned char s_pErrUPD1		[]	= "Error occurred while contacting the update server!\n\nPlease try again later.";

static unsigned char s_pErrMNT		[]	= "Error occurred while parsing device mount table!";
static unsigned char s_pErrMVGAME	[]	= "Error occurred while moving game to new location!";

static unsigned char s_pErrMVAV		[]	= "Error (%08X) occurred while setting active AVCHD folder.\n\nCannot rename [%s] to [%s]";

static unsigned char s_pDownUpdate	[]	= "Downloading update data, please wait!";
static unsigned char s_pDownCover	[]	= "Downloading cover, please wait!";
static unsigned char s_pDownFile	[]	= "Downloading file, please wait!";
static unsigned char s_pDownTheme	[]	= "Downloading theme, please wait!";

static unsigned char s_pDownMSG0	[]	= "\nDownloaded %.1f of %.2f MB. Remaining: %imin %2.2isec (/\\ to cancel)\nSave path: %s";
static unsigned char s_pDownMSG1	[]	= "Downloaded %.2f of %.2f KB. Remaining: %i:%2.2i min\n\nPress /\\ to cancel download";
static unsigned char s_pDownMSG2	[]	= "Downloaded %.0f of %.0f KB. Remaining: %i:%2.2i min";

static unsigned char s_pParamVer	[]	= "Game requires PS3 firmware version %.2f.\n\nDo you want to change PARAM.SFO version to %.2f?";

static unsigned char s_pLastPlay	[]	= "Setting data for last played game, please wait...";
static unsigned char s_pSetAccess	[]	= "Setting access permissions, please wait...";
static unsigned char s_pSetAccess1	[]	= "Setting access permissions, please wait!\n\nThis operation will be performed only once.";

static unsigned char s_pPreProcess	[]	= "Pre-processing required for this title.\n\nDo you want to install required data to internal HDD?";

static unsigned char s_pNoSpace0	[]	= "Not enough space to complete cache operation! (Available: %.2fMB)\n\nAdditional %.2fMB of free space required!";
static unsigned char s_pNoSpace1	[]	= "Not enough space on destination drive! (Available: %.2fMB)\n\nAdditional %.2fMB of free space required!";

static unsigned char s_pErrNoMemWeb	[]	= "Not enough memory to launch web browser!\n\nPlease restart " STR_MM_NAME " and try again.";
static unsigned char s_pErrNoMem	[]	= "Please restart " STR_MM_NAME " from PS3 XMB\xE2\x84\xA2";

//multiMAN Update
static unsigned char s_pPleaseWait	[]	= "Please wait...";
static unsigned char s_pWhatsNew	[]	= "What's new in " STR_MM_NAME " %s:\n\n%s";
static unsigned char s_pNewVer		[]	= "New version found: %s\n\nYour current version: %s\n\nDo you want to download the update?";
static unsigned char s_pNewVerDL	[]	= "Download completed successfully!\n\nInstall the update from [* Install Package Files] XMB\xE2\x84\xA2 tab.\n\nUpdate file saved as: %s\n\n%s?";
static unsigned char s_pNewVerNN	[]	= "You already have the latest version: %s\n\n            There is no need to update.";
static unsigned char s_pNewVerUSB	[]	= "Please attach USB storage device to save update data and try again!";

//Game Update
static unsigned char s_pGameUpdate1	[]	= "%s\n\nVersion: %s (%i update)\nUpdate size: %.2fMB\n\nDownload update now?";
static unsigned char s_pGameUpdate2	[]	= "%s\n\nVersions: %s - %s (%i updates)\nTotal update size: %.2fMB\n\nDownload updates now?";
static unsigned char s_pGameUpdate3	[]	= "%s\n\nYou already have version %.2f installed.\n\nDo you want to download newer updates only?";
static unsigned char s_pGameUpdate5	[]	= "Download completed successfully!\n\nUpdate files saved in: %s\n\n%s?";
static unsigned char s_pGameUpdate6	[]	= "You already have the latest version of the game.";
static unsigned char s_pGameUpdate7	[]	= "Cannot find update information for this title!";

//Selection menus captions
static unsigned char s_pSelTheme	[]	= "Select Theme";
static unsigned char s_pSelLang		[]	= "Select Language";
static unsigned char s_pDelGameC	[]	= "Delete Game Cache";

//File Manager top
static unsigned char s_pFMGames		[]	= "Games";
static unsigned char s_pFMUpdate	[]	= "Update";
static unsigned char s_pFMAbout		[]	= "About";
static unsigned char s_pFMHelp		[]	= "Help";
static unsigned char s_pFMThemes	[]	= "Themes";

//File Manager Command menu
static unsigned char s_pCMMulDir	[]	= "Multiple folders";
static unsigned char s_pCMMulFile	[]	= "Multiple files";

static unsigned char s_pCMCopy		[]	= "Copy";
static unsigned char s_pCMMove		[]	= "Move";
static unsigned char s_pCMRename	[]	= "Rename";
static unsigned char s_pCMDelete	[]	= "Delete";
static unsigned char s_pCMShortcut	[]	= "Create Shortcut";
static unsigned char s_pCMShadow	[]	= "Shadow for PKG game";
static unsigned char s_pCMBDMirror	[]	= "Activate BD-Mirror";
static unsigned char s_pCMNetHost	[]	= "Refresh Net Host";
static unsigned char s_pCMHexView	[]	= "Open in HEX Viewer";
static unsigned char s_pCMProps		[]	= "Properties";
static unsigned char s_pCMNewDir	[]	= "Create New Folder";

static unsigned char s_pApplyTheme	[]	= "Applying \x22%s\x22 theme, please wait...";

// system menu
static unsigned char s_pMMUpdate	[]	= "Update";
static unsigned char s_pMMUpdateL1	[]	= "Check for available program updates.";
static unsigned char s_pMMUpdateL2	[]	= "" STR_MM_NAME " is being updated constantly, so make sure";
static unsigned char s_pMMUpdateL3	[]	= "to check for new versions regularly.";
static unsigned char s_pMMUpdateL4	[]	= "Internet connection required.";

static unsigned char s_pMMRefresh	[]	= "Refresh List";
static unsigned char s_pMMRefreshL1	[]	= "Re-scan internal and external hard disk drives.";
static unsigned char s_pMMRefreshL2	[]	= "Force " STR_MM_NAME " to refresh and re-detect content";
static unsigned char s_pMMRefreshL3	[]	= "(games, video, other). Use this option if you";
static unsigned char s_pMMRefreshL4	[]	= "transfer content via FTP. Shortcut is SELECT+L3.";

static unsigned char s_pMMFileMan	[]	= "mmOS";
static unsigned char s_pMMFileManL1	[]	= "Switch to mmOS mode. Shortcut is SELECT+START.";
static unsigned char s_pMMFileManL2	[]	= "Use file manager to manage your files and folders, to copy,";
static unsigned char s_pMMFileManL3	[]	= "move or rename them, to view images and play music and video.";
static unsigned char s_pMMFileManL4	[]	= "SHOWTIME may be required to play some content.";

static unsigned char s_pMMShowtimeST	[]	= "Launch Showtime";
static unsigned char s_pMMShowtimeSTL1	[]	= "Quit " STR_MM_NAME " and launch Showtime Player.";
static unsigned char s_pMMShowtimeSTL2	[]	= "Showtime Media Player is a feature rich";
static unsigned char s_pMMShowtimeSTL3	[]	= "application, which allows you to play";
static unsigned char s_pMMShowtimeSTL4	[]	= "various video, audio and graphic formats.";

static unsigned char s_pMMNTFS		[]	= "PFS / NTFS driver";
static unsigned char s_pMMNTFSL1	[]	= "Switch between FAT32 and NTFS drivers.";
static unsigned char s_pMMNTFSL2	[]	= "To use this option you must connect external USB HDD,";
static unsigned char s_pMMNTFSL3	[]	= "formatted with FAT32 or NTFS file system.";
static unsigned char s_pMMNTFSL4	[]	= "Proper USB.CFG required. Shortcut is START+TRIANGLE.";

static unsigned char s_pMMShowtimeLK	[]	= "Link VIDEO to Showtime";
static unsigned char s_pMMShowtimeLKL1	[]	= "Create links of your XMB\xE2\x84\xA2 video files to";
static unsigned char s_pMMShowtimeLKL2	[]	= "a special folder for Showtime Media Player";
static unsigned char s_pMMShowtimeLKL3	[]	= "to find them. When linking completes, " STR_MM_NAME "";
static unsigned char s_pMMShowtimeLKL4	[]	= "will show a pop-up message.";

static unsigned char s_pMMScrShot	[]	= "Screenshot";
static unsigned char s_pMMScrShotL1	[]	= "Take a screenshot of your game list.";
static unsigned char s_pMMScrShotL2	[]	= "Current screen will be saved as RGB raw file to /dev_hdd0";
static unsigned char s_pMMScrShotL3	[]	= "or in the root folder of connected USB device.";
static unsigned char s_pMMScrShotL4	[]	= "Shortcut is START+R2.";

static unsigned char s_pMMScrSave	[]	= "Screensaver";
static unsigned char s_pMMScrSaveL1	[]	= "Turn on " STR_MM_NAME "'s screensaver.";
static unsigned char s_pMMScrSaveL2	[]	= "A screen with falling 'stars' will appear on";
static unsigned char s_pMMScrSaveL3	[]	= "your display. Press a button to quit";
static unsigned char s_pMMScrSaveL4	[]	= "the screensaver mode.";

static unsigned char s_pMMRestart	[]	= "Restart";
static unsigned char s_pMMRestartL1	[]	= "Restart " STR_MM_NAME ". Shortcut is START+SELECT.";
static unsigned char s_pMMRestartL2	[]	= "You can remotely restart " STR_MM_NAME " by connecting to your";
static unsigned char s_pMMRestartL3	[]	= "PLAYSTATION\xC2\xAE\x33 system via telnet to port 8080";
static unsigned char s_pMMRestartL4	[]	= "and type 'restart'.";

static unsigned char s_pMMSetup		[]	= "" STR_MM_NAME " Setup";
static unsigned char s_pMMSetupL1	[]	= "Switch to XMMB Settings column.";
static unsigned char s_pMMSetupL2	[]	= "You can edit all " STR_MM_NAME " options in XMMB mode.";
static unsigned char s_pMMSetupL3	[]	= "If you select this option, the current display";
static unsigned char s_pMMSetupL4	[]	= "mode will be changed.";

static unsigned char s_pMMQuit		[]	= "Quit";
static unsigned char s_pMMQuitL1	[]	= "Quit " STR_MM_NAME " and return to XMB\xE2\x84\xA2 home screen.";
static unsigned char s_pMMQuitL2	[]	= "You can remotely quit " STR_MM_NAME " by connecting to your";
static unsigned char s_pMMQuitL3	[]	= "PLAYSTATION\xC2\xAE\x33 system via telnet to port 8080";
static unsigned char s_pMMQuitL4	[]	= "and type 'quit'.";

static unsigned char s_pMMHelp		[]	= "Help";
static unsigned char s_pMMHelpL1	[]	= "Start the HELP application.";
static unsigned char s_pMMHelpL2	[]	= "This option will execute external";
static unsigned char s_pMMHelpL3	[]	= "help.MME application and quit " STR_MM_NAME ".";
static unsigned char s_pMMHelpL4	[]	= "Avoid using it during FTP transfers.";

static unsigned char s_pButNavigate	[]	= "Navigate";
static unsigned char s_pButSelect	[]	= "Select";
static unsigned char s_pButBack		[]	= "Back";
static unsigned char s_pButCancel	[]	= "Cancel";
static unsigned char s_pButApply	[]	= "Apply";
static unsigned char s_pButConfirm	[]	= "Confirm";
static unsigned char s_pButGenre	[]	= "Genre";
static unsigned char s_pButDownload	[]	= "Download";
static unsigned char s_pButLoad		[]	= "Load";
static unsigned char s_pButPrev		[]	= "Prev Title";
static unsigned char s_pButNext		[]	= "Next Title";
static unsigned char s_pButLast		[]	= "Last Title";
static unsigned char s_pButFirst	[]	= "First Title";

static unsigned char s_pSelGenre	[]	= "Select Genre";
static unsigned char s_pButDownTheme[]	= "Download Theme";

// Game settings menu
static unsigned char s_pGMCopy		[]	= "Copy";
static unsigned char s_pGMCopyL1	[]	= "Create a backup copy of \x22%s\x22.";
static unsigned char s_pGMCopyL2	[]	= "To protect your PLAYSTATION\xC2\xAE\x33 Blu-ray\xE2\x84\xA2 game disc,";
static unsigned char s_pGMCopyL3	[]	= "transfer its contents to internal or external hard disk drive.";

static unsigned char s_pGMDelete	[]	= "Delete";
static unsigned char s_pGMDeleteL1	[]	= "Permanently delete game files.";
static unsigned char s_pGMDeleteL2	[]	= "If you are running low on disk space, delete the game from your";
static unsigned char s_pGMDeleteL3	[]	= "hard disk drive. Use this option with caution!";

static unsigned char s_pGMRename	[]	= "Rename";
static unsigned char s_pGMRenameL1	[]	= "Pick a name of your choice for the game.";
static unsigned char s_pGMRenameL2	[]	= "You can use the on-screen keyboard or external USB keyboard";
static unsigned char s_pGMRenameL3	[]	= "for input. Use (TM), (R) and (C) to enter \xE2\x84\xA2, \xC2\xAE and \xC2\xA9 symbols.";

static unsigned char s_pGMUpdate	[]	= "Update";
static unsigned char s_pGMUpdateL1	[]	= "Check for game updates.";
static unsigned char s_pGMUpdateL2	[]	= "This feature allows you to download all available updates";
static unsigned char s_pGMUpdateL3	[]	= "or only the latest. Internet connection required.";

static unsigned char s_pGMTest		[]	= "Test";
static unsigned char s_pGMTestL1	[]	= "Verify all files and folders of the game.";
static unsigned char s_pGMTestL2	[]	= "Testing will report various data as Total Size, Number of files,";
static unsigned char s_pGMTestL3	[]	= "Big files (over 4GB) and if game contains split (.666##) files.";

static unsigned char s_pGMPerm		[]	= "Permissions";
static unsigned char s_pGMPermL1	[]	= "Re-apply file and folder access permissions.";
static unsigned char s_pGMPermL2	[]	= "On rare occasions it may be required to perform resetting of";
static unsigned char s_pGMPermL3	[]	= "ownership and execution flags of game contents.";

static unsigned char s_pPOPGS		[]	= ": Game Settings";
static unsigned char s_pPOPChangeS	[]	= ": Change Setting";
static unsigned char s_pPOPSysInfo	[]	= ": View System Information";
static unsigned char s_pPOPLang		[]	= ": Change Display Language";
static unsigned char s_pPOPCache	[]	= ": Clear Cached Files";
static unsigned char s_pPOPPhoto	[]	= ": View Photo";
static unsigned char s_pPOPMusic	[]	= ": Play Music";
static unsigned char s_pPOPST		[]	= ": Launch Showtime";
static unsigned char s_pPOPVideo	[]	= ": Play Video";
static unsigned char s_pPOPRefGames	[]	= ": Refresh List";
static unsigned char s_pPOPRefRoms	[]	= ": Refresh ROMs";
static unsigned char s_pPOPRom		[]	= ": Load Game ROM";

static unsigned char s_pPOPGrpGenre	[]	= ": Group Titles by Genre";
static unsigned char s_pPOPGrpEmu	[]	= ": Group ROMs by Emulator";
static unsigned char s_pPOPGrpName	[]	= ": Group Titles by Name";
static unsigned char s_pPOPSwitch	[]	= ": Switch Display";

static unsigned char s_pPOP1of1		[]	= "%s: %i of %i";
static unsigned char s_pPOPPlaying	[]	= "Playing";
static unsigned char s_pPOPPaused	[]	= "Paused";
static unsigned char s_pPOPVol		[]	= "[Volume: %i]";

// Alpha group "Other"
static unsigned char s_pOther		[]	= "Other";

// Genres
static unsigned char s_pGENOther	[]	= "Other";
static unsigned char s_pGENAct		[]	= "Action";
static unsigned char s_pGENAdv		[]	= "Adventure";
static unsigned char s_pGENFam		[]	= "Family";
static unsigned char s_pGENFight	[]	= "Fighting";
static unsigned char s_pGENParty	[]	= "Party";
static unsigned char s_pGENPlat		[]	= "Platform";
static unsigned char s_pGENPuzz		[]	= "Puzzle";
static unsigned char s_pGENRole		[]	= "Role Playing";
static unsigned char s_pGENRace		[]	= "Racing";
static unsigned char s_pGENShoot	[]	= "Shooter";
static unsigned char s_pGENSim		[]	= "Sim";
static unsigned char s_pGENSport	[]	= "Sports";
static unsigned char s_pGENStrat	[]	= "Strategy";
static unsigned char s_pGENTriv		[]	= "Trivia";
static unsigned char s_pGEN3D		[]	= "3D Support";

// Retro Groups
static unsigned char s_pRETRO		[]	= "Retro";
static unsigned char s_pRETSNES		[]	= "SNES";
static unsigned char s_pRETFCEU		[]	= "FCEU";
static unsigned char s_pRETVBA		[]	= "VBA";
static unsigned char s_pRETGEN		[]	= "GEN+";
static unsigned char s_pRETFBA		[]	= "FBANext";

// XMMB Column names ("Empty", "...", ... Retro, ...)
static unsigned char s_pXCS			[]	= "Settings";	// 2
static unsigned char s_pXCP			[]	= "Photo";		// 3
static unsigned char s_pXCM			[]	= "Music";		// 4
static unsigned char s_pXCV			[]	= "Video";		// 5
static unsigned char s_pXCG			[]	= "Game";		// 6
static unsigned char s_pXCF			[]	= "Favorites";	// 7
static unsigned char s_pXCW			[]	= "Web";		// 9

static unsigned char s_pPS2			[]	= STR_MM_NAME " will now exit to XMB\xE2\x84\xA2 and you can start the game from the [PLAYSTATION\xC2\xAE\x32 Format Game] icon.";
static unsigned char s_pPKG			[]	= "Do you want to exit to XMB\xE2\x84\xA2 to install selected package from [* Install package files] menu?";

static unsigned char s_pNoSplit1	[]	= "You cannot launch games with split big files!\n\nTransfer the game to internal HDD and try again\nor use XMMB mode to launch the title.";
static unsigned char s_pNoSplit2	[]	= "You cannot launch games with split big files!\n\nTransfer the game to internal HDD and try again\nor use [Hermes] option for BD-Emulator type in SETTINGS XMMB column\nand restart your PS3\xE2\x84\xA2 system.";
static unsigned char s_pNoSplit3	[]	= "You cannot launch games with split big files!\n\nTransfer the game to internal HDD and try again\nor enable [Verify USB Games] option in SETTINGS XMMB column\nand restart your PS3\xE2\x84\xA2 system.";

static unsigned char s_pVerifying	[]	= "Verifying data, please wait...";
static unsigned char s_pCanceled	[]	= "Operation failed or canceled.";

static unsigned char s_pNotSupported[]	= "Your current configuration doesn't support this function!";
static unsigned char s_pNotSupported2[]	= "Your current configuration doesn't support this function!\n\n                     (unable to create file cache)";

static unsigned char s_pPS3DISC		[]	= "Please insert an original PLAYSTATION\xC2\xAE\x33 game disc before proceeding!";

static unsigned char s_pThmInstall	[]	= "Do you want to exit to XMB\xE2\x84\xA2 to install \x22%s\x22 theme from [* Install package files] menu?";
static unsigned char s_pToDBoot		[]	= "Do you want to start the game without exiting to XMB?\n\nWarning: Some games do not support such launch mode!";

static unsigned char s_pDLST		[]	= "Showtime for " STR_MM_NAME " application is missing!\n\nDo you want to download it now?";

static unsigned char s_pStartBD1	[]	= STR_MM_NAME " will now exit to XMB\xE2\x84\xA2 and you can start the game from the /app_home icon.";
static unsigned char s_pStartBD2	[]	= STR_MM_NAME " will now exit to XMB\xE2\x84\xA2 and you can start the game from the Blu-ray\xE2\x84\xA2 Game Disc icon.";

static unsigned char s_pOverwrite	[]	= "Destination already contains folder with the same name!\n\nContinue and overwrite?\n\n[%s]";

static unsigned char s_pIncomplete	[]	= "WARNING:\n\nYour installation of " STR_MM_NAME " is incomplete!\nPlease install BASE or FULL version or you may experience graphics display problems!";

static unsigned char s_pErrBDEMU1	[]	= STR_MM_NAME " cannot enable selected BD-ROM emulator type. Functionality may be restricted!\n\nError: BDEMU.BIN incorrect version";
static unsigned char s_pErrBDEMU2	[]	= STR_MM_NAME " cannot enable BD-ROM emulator. Functionality may be restricted!\n\nError: BDEMU.BIN missing";
static unsigned char s_pErrBDEMU3	[]	= STR_MM_NAME " cannot enable BD-ROM emulator. Functionality may be restricted!\n\nError: Unsupported system firmware";

static unsigned char s_pCritical	[]	= "CRITICAL ERROR:\n\n" STR_MM_NAME " cannot access or create default backup folder!\nGame backup functions may not work properly.\n\nPlease use different payload if necessary!";

static unsigned char s_pDelFile		[]	= "Do you want to delete the selected file?\n\n[%s]";
static unsigned char s_pDelFiles	[]	= "Do you want to delete the selected %i files?";
static unsigned char s_pDelDir		[]	= "Do you want to delete the selected folder and its contents?\n\n[%s]";
static unsigned char s_pDelDirs		[]	= "Do you want to delete the selected %i folders and their contents?";

static unsigned char s_pDelFromHDD	[]	= "Do you want to delete title from internal HDD?";
static unsigned char s_pDelFromUSB	[]	= "Do you want to delete title from external USB00%c?";
static unsigned char s_pDelFromCache[]	= "There is cached data for this title. Do you want to clear it?";

static unsigned char s_pCpHdd2Usb	[]	= "Do you want to copy game from internal HDD to external USB00%c?";
static unsigned char s_pCpUsb2Hdd	[]	= "Do you want to copy game from external USB00%c to internal HDD?\n\nSource: /dev_usb00%i/%s/%s\nDestination: %s/%s";
static unsigned char s_pCpPfs2Hdd	[]	= "Do you want to copy game from external USB disk to internal HDD?\n\nSource: %s\nDestination: %s/%s";
static unsigned char s_pCpUsb2Usb	[]	= "Do you want to copy game from external USB00%c to external USB00%c?\n\nSource: /dev_usb00%i/%s/%s\nDestination: /dev_usb00%i/%s/%s";
static unsigned char s_pOverwriteNo	[]	= "Destination already contains folder with the same name!\n\nPlease use FILE MANAGER [SELECT+START] to rename or remove:\n\n[%s]";

static unsigned char s_pDelPartHDD	[]	= "%s\n\nDelete partial copy from internal HDD?";
static unsigned char s_pDelPartUSB	[]	= "%s\n\nDelete partial copy from USB00%c?";

static unsigned char s_pDelCacheDone[]	= "Game Cache Data cleared!";

static unsigned char s_pCpBD2Hdd	[]	= "Do you want to copy game from BD-ROM to internal HDD?";
static unsigned char s_pCpBD2Usb	[]	= "Do you want to copy game from BD-ROM to external USB00%c?";

static unsigned char s_pPinGame		[]	= "Game parental level: %i - Enter access PIN code:";
static unsigned char s_pPinErr		[]	= "Entered PIN code is incorrect!";
static unsigned char s_pPinEnter	[]	= "Enter access PIN code:";
static unsigned char s_pPinNew		[]	= "Enter NEW access PIN code:";
static unsigned char s_pPinErr2		[]	= "Entered PIN code is not accepted!\n\nPlease use four character alphanumeric PIN!";

static unsigned char s_pBd2AVCHD	[]	= "::: %s :::\n\nDo you want to convert the Blu-ray\xE2\x84\xA2 disc structure to AVCHD\xE2\x84\xA2 format?\n\nNote: The action may improve playback compatibility!";
static unsigned char s_pBd2AVCHD2	[]	= "Converting Blu-ray\xE2\x84\xA2 structure to AVCHD\xE2\x84\xA2, please wait...";
static unsigned char s_pActAVCHD	[]	= "Activate currently selected AVCHD\xE2\x84\xA2 video folder?\n\n::: %s :::\n\nNote: You can start video playback from XMB\xE2\x84\xA2 [Video] tab";
static unsigned char s_pActAVCHD2	[]	= "Activating AVCHD\xE2\x84\xA2 structure, please wait...";
static unsigned char s_pBd2AVCHD3	[]	= "::: %s :::\n\n%s: %s\n\nDo you want to convert the Blu-ray\xE2\x84\xA2 disc structure to AVCHD\xE2\x84\xA2 format?\n\nNote: The action may improve playback compatibility!";
static unsigned char s_pActBDMV		[]	= "Activate currently selected Blu-ray\xE2\x84\xA2 (BDMV) video folder?\n\n::: %s :::\n\n[%s: %s]\n\nNote: You can start video playback from XMB\xE2\x84\xA2 [Video] tab";

static unsigned char s_pAttUSB		[]	= "Please attach USB, SDHC or MemoryStick\xE2\x84\xA2 storage device to activate AVCHD\xE2\x84\xA2 HDD playback!";
static unsigned char s_pAttPFS		[]	= "Please attach USB storage device before you proceed!\n\nIs the disk connected to your PLAYSTATION\xC2\xAE\x33 system?";

static unsigned char s_pCacheFile	[]	= "Caching file to internal temporary folder...";
static unsigned char s_pHddErr		[]	= "This title cannot be loaded from internal HDD.\n\nTransfer to external USB HDD or change title options.";
static unsigned char s_pUsbErr		[]	= "This title cannot be loaded from external USB HDD.\n\nTransfer to internal HDD or change title options.";

static unsigned char s_pTitleLocked	[]	= "Options cannot be changed or title is locked!";
static unsigned char s_pTitleRO		[]	= "Options cannot be changed for this title!";

static unsigned char s_pRenameTo	[]	= "Rename [%s] to:";
static unsigned char s_pCreateNew	[]	= "CREATE NEW FOLDER - Enter name for the new folder:";

static unsigned char s_pXCUP		[]	= "Update";
static unsigned char s_pXCUP1		[]	= "Check for " STR_MM_NAME " updates";
static unsigned char s_pXCFM		[]	= "File Manager / mmOS";
static unsigned char s_pXCFM0		[]	= "File Manager / mmOS (Disabled)";
static unsigned char s_pXCFM1		[]	= "Manage files and folders";
static unsigned char s_pXCRF		[]	= "Refresh";
static unsigned char s_pXCRF1		[]	= "Scan all connected devices for supported content";
static unsigned char s_pXCRF2		[]	= "Scan all connected devices and refresh game list";
static unsigned char s_pXCRF3		[]	= "Scan all emulator folders for newly added game ROMs";
static unsigned char s_pXCPF		[]	= "PFS Driver";
static unsigned char s_pXCPF1		[]	= "Toggle between FAT32 and NTFS driver";
static unsigned char s_pXCSS		[]	= "Screensaver";
static unsigned char s_pXCSS1		[]	= "Turn on screensaver mode";
static unsigned char s_pXCTH		[]	= "Themes";
static unsigned char s_pXCTH1		[]	= "Change " STR_MM_NAME " appearance";
static unsigned char s_pXCHL		[]	= "Help";
static unsigned char s_pXCHL1		[]	= "Start helpMMe application";
static unsigned char s_pXCRS		[]	= "Restart";
static unsigned char s_pXCRS1		[]	= "Close and restart " STR_MM_NAME "";
static unsigned char s_pXCQT		[]	= "Quit";
static unsigned char s_pXCQT1		[]	= "Quit " STR_MM_NAME " and return to XMB\xE2\x84\xA2 screen";

static unsigned char s_pXC5LK		[]	= "Link Video Library to Showtime";
static unsigned char s_pXC5LK1		[]	= "Make XMB\xE2\x84\xA2 video files available to Showtime";
static unsigned char s_pXC5ST		[]	= "Start Showtime Media Center";
static unsigned char s_pXC5ST1		[]	= "Launch Showtime to play movies and listen to music";

static unsigned char s_pXC2SS		[]	= "System Information";
static unsigned char s_pXC2SS1		[]	= "Displays information about your PS3\xE2\x84\xA2 system.";
static unsigned char s_pXC2IL		[]	= "Interface Language";
static unsigned char s_pXC2IL1		[]	= "Changes " STR_MM_NAME " interface language.";
static unsigned char s_pXC2GC		[]	= "Clear Game Cache Data";
static unsigned char s_pXC2GC1		[]	= "Removes cache files for selected title.";

static unsigned char s_pXC2YES		[]	= "Yes";
static unsigned char s_pXC2NO		[]	= "No";
static unsigned char s_pXC2AUTO		[]	= "Auto";
static unsigned char s_pXC2ENABLE	[]	= "Enable";
static unsigned char s_pXC2DISABLE	[]	= "Disable";
static unsigned char s_pXC2NONE		[]	= "None";

static unsigned char s_pXC2UNAV		[]	= "(Unavailable)";
static unsigned char s_pXC2STD		[]	= "Standard";

static unsigned char s_pXC2MIN		[]	= "min";
static unsigned char s_pXC2SEC		[]	= "sec";
static unsigned char s_pXC2LEVEL	[]	= "Level";

static unsigned char s_pXC2_339	[]	= "Download Game Covers";
static unsigned char s_pXC2_340	[]	= "Adjusts whether to download missing game covers.";

static unsigned char s_pXC2_341	[]	= "FTP Service";
static unsigned char s_pXC2_342	[]	= "Sets FTP startup mode.";

static unsigned char s_pXC2_343	[]	= "XMMB Sparks";
static unsigned char s_pXC2_344	[]	= "Changes display setting for sparks overlay in XMMB display mode.";

static unsigned char s_pXC2_345	[]	= "XMMB Game Poster";
static unsigned char s_pXC2_346	[]	= "Changes display setting for game poster images in XMMB mode.";

static unsigned char s_pXC2_347	[]	= "XMMB Game Cover";
static unsigned char s_pXC2_348	[]	= "Changes display setting for game cover images in XMMB display mode.";

static unsigned char s_pXC2_349	[]	= "XMMB Game Icon Swap";
static unsigned char s_pXC2_350	[]	= "Switches display of icon and cover in Game column.";

static unsigned char s_pXC2_351	[]	= "XMMB Info Pop-up";
static unsigned char s_pXC2_352	[]	= "Changes display setting for information pop-up boxes.";

static unsigned char s_pXC2_353	[]	= "Parental Control PIN Code";
static unsigned char s_pXC2_354	[]	= "Sets the parental control level PIN code.";

static unsigned char s_pXC2_355	[]	= "Parental Control Level";
static unsigned char s_pXC2_356	[]	= "Sets the parental control level for rated titles.";

static unsigned char s_pXC2_357	[]	= "Function Control";
static unsigned char s_pXC2_358	[]	= "Adjusts which functions will be enabled or disabled.";
static unsigned char s_pXC2_359	[]	= "Enable Copy and Delete";
static unsigned char s_pXC2_360	[]	= "Disable Delete";
static unsigned char s_pXC2_361	[]	= "Disable Copy";
static unsigned char s_pXC2_362	[]	= "Disable Copy and Delete";

static unsigned char s_pXC2_363	[]	= "mmOS Access";
static unsigned char s_pXC2_364	[]	= "Sets whether to restrict access to mmOS.";

static unsigned char s_pXC2_365	[]	= "Verify USB Games";
static unsigned char s_pXC2_366	[]	= "Sets whether to check titles on USB for compatibility.";

static unsigned char s_pXC2_367	[]	= "Scan for Homebrew Applications";
static unsigned char s_pXC2_368	[]	= "Sets whether to scan for applications with RELOAD.SELF boot file.";

static unsigned char s_pXC2_369	[]	= "Scan for AVCHD\xE2\x84\xA2 and Blu-ray\xE2\x84\xA2";
static unsigned char s_pXC2_370	[]	= "Sets whether to scan USB devices for AVCHD\xE2\x84\xA2 and Blu-ray\xE2\x84\xA2 content.";

static unsigned char s_pXC2_371	[]	= "Expand Contents of AVCHD\xE2\x84\xA2";
static unsigned char s_pXC2_372	[]	= "Sets whether to show one entry per title or all AVCHD\xE2\x84\xA2 playlists.";

static unsigned char s_pXC2_373	[]	= "Hide BD-ROM Disc from Game List";
static unsigned char s_pXC2_374	[]	= "Sets appearance of BD-ROM disc entry in the game list.";

static unsigned char s_pXC2_375	[]	= "Content Filter";
static unsigned char s_pXC2_376	[]	= "Changes default content filter (key shortcut SELECT+R1).";

static unsigned char s_pXC2_377	[]	= "Clean Activity Logs";
static unsigned char s_pXC2_378	[]	= "Adjusts whether to remove push list and boot history.";

static unsigned char s_pXC2_379	[]	= "Date Format";
static unsigned char s_pXC2_380	[]	= "Sets the order of display for year, month and day.";

static unsigned char s_pXC2_381	[]	= "Time Format";
static unsigned char s_pXC2_382	[]	= "Sets the time display to either a 12-hour or 24-hour clock.";
static unsigned char s_pXC2_383	[]	= "12-Hour Clock";
static unsigned char s_pXC2_384	[]	= "24-Hour Clock";

static unsigned char s_pXC2_385	[]	= "Button Assignment";
static unsigned char s_pXC2_386	[]	= "Sets which buttons are used for Accept/Enter and Cancel/Back.";
static unsigned char s_pXC2_387	[]	= "Circle is [Accept]";
static unsigned char s_pXC2_388	[]	= "Cross is [Accept]";

static unsigned char s_pXC2_389	[]	= "Default Display Mode";
static unsigned char s_pXC2_390	[]	= "Sets default startup display mode. Switch modes with L1/R1.";
static unsigned char s_pXC2_391	[]	= "Board (5x4x5)";
static unsigned char s_pXC2_392	[]	= "Game List (4x2)";
static unsigned char s_pXC2_393	[]	= "Game List (poster)";
static unsigned char s_pXC2_394	[]	= "XBDM (XBOX\xE2\x84\xA2 dash clone)"; //"Game list (user background)"
static unsigned char s_pXC2_395	[]	= "Slide Cover Flow";
static unsigned char s_pXC2_396	[]	= "mmOS";
static unsigned char s_pXC2_397	[]	= "TMB (Top media bar)";
static unsigned char s_pXC2_398	[]	= "Game List (8x4)";
static unsigned char s_pXC2_399	[]	= "XMMB (XMB\xE2\x84\xA2 clone)";

static unsigned char s_pXC2_400	[]	= "Display Mode Lock";
static unsigned char s_pXC2_401	[]	= "Locks " STR_MM_NAME " to pre-selected display mode.";

static unsigned char s_pXC2_402	[]	= "Font Preference";
static unsigned char s_pXC2_403	[]	= "Sets default font (key shortcut R3).";

static unsigned char s_pXC2_404	[]	= "Theme Audio";
static unsigned char s_pXC2_405	[]	= "Sets whether to play theme music in the background.";

static unsigned char s_pXC2_406	[]	= "TV Overscan";
static unsigned char s_pXC2_407	[]	= "Sets TV overscan zone in percents (key shortcut SELECT+L2/R2).";

static unsigned char s_pXC2_408	[]	= "Title Name Appearance";
static unsigned char s_pXC2_409	[]	= "Changes size and appearance of title names and paths.";
static unsigned char s_pXC2_410	[]	= "Large size title";
static unsigned char s_pXC2_411	[]	= "Title and path";
static unsigned char s_pXC2_412	[]	= "Medium size title";

static unsigned char s_pXC2_413	[]	= "Title Details";
static unsigned char s_pXC2_414	[]	= "Adjusts level of displayed details for selected display modes.";
static unsigned char s_pXC2_415	[]	= "Title Only";
static unsigned char s_pXC2_416	[]	= "Title and ID";
static unsigned char s_pXC2_417	[]	= "Full";

static unsigned char s_pXC2_418	[]	= "Animation";
static unsigned char s_pXC2_419	[]	= "Adjusts animation options for some display modes.";
static unsigned char s_pXC2_420	[]	= "Disable background slide";
static unsigned char s_pXC2_421	[]	= "Disable icon animation";

static unsigned char s_pXC2_422	[]	= "Poster Overlay";
static unsigned char s_pXC2_423	[]	= "Sets whether to show poster in [Game list (poster)] display mode.";

static unsigned char s_pXC2_424	[]	= "Poster and Cover Alteration";
static unsigned char s_pXC2_425	[]	= "Sets whether to grayscale game poster and cover when required.";

static unsigned char s_pXC2_426	[]	= "Progress Bar";
static unsigned char s_pXC2_427	[]	= "Sets whether to show progress bar during copy operations.";

static unsigned char s_pXC2_428	[]	= "Inactivity Timeout";
static unsigned char s_pXC2_429	[]	= "Dim and hide title names after specified amount of time.";

static unsigned char s_pXC2_430	[]	= "Screensaver";
static unsigned char s_pXC2_431	[]	= "Turn on screensaver after specified amount of time.";

static unsigned char s_pXC2_432	[]	= "Motion Sensor";
static unsigned char s_pXC2_433	[]	= "Sets whether to use sensor information from SIXAXIS\xE2\x84\xA2 controller.";

static unsigned char s_pXC2_434	[]	= "Mouse Sensitivity (X)";
static unsigned char s_pXC2_435	[]	= "Sets analogue sticks horizontal sensitivity (dead zone).";

static unsigned char s_pXC2_436	[]	= "Mouse Sensitivity (Y)";
static unsigned char s_pXC2_437	[]	= "Sets analogue sticks vertical sensitivity (dead zone).";

static unsigned char s_pXC2_438	[]	= "Key Repeat Delay";
static unsigned char s_pXC2_439	[]	= "Sets initial delay before key repeat.";
static unsigned char s_pXC2_440	[]	= "Very Short";
static unsigned char s_pXC2_441	[]	= "Short";
static unsigned char s_pXC2_442	[]	= "Normal";
static unsigned char s_pXC2_443	[]	= "Long";
static unsigned char s_pXC2_444	[]	= "Very Long";

static unsigned char s_pXC2_445	[]	= "Key Repeat Speed";
static unsigned char s_pXC2_446	[]	= "Sets key repeat speed.";
static unsigned char s_pXC2_447	[]	= "Very Fast";
static unsigned char s_pXC2_448	[]	= "Fast";
static unsigned char s_pXC2_449	[]	= "Normal";
static unsigned char s_pXC2_450	[]	= "Slow";
static unsigned char s_pXC2_451	[]	= "Slower";

static unsigned char s_pXC2_452	[]	= "Cache Partition";
static unsigned char s_pXC2_453	[]	= "Enable or disable 2GB temporary partition (/dev_hdd1).";

static unsigned char s_pXC2_454	[]	= "BD-ROM Emulator";
static unsigned char s_pXC2_455	[]	= "Changes emulator type. System restart required to apply changes.";

static unsigned char s_pXC9_456	[]	= "Download PS3\xE2\x84\xA2 Demos and Utilities";
static unsigned char s_pXC9_457	[]	= "Browse PSX Store Website for rich content for your PLAYSTATION\xC2\xAE\x33 system";

static unsigned char s_pXC9_458	[]	= "Download Themes";
static unsigned char s_pXC9_459	[]	= "Check for new downloadable themes";

static unsigned char s_pXC9_460	[]	= "Visit " STR_MM_NAME " Forum";
static unsigned char s_pXC9_461	[]	= "Browse forum thread for " STR_MM_NAME " discussions";

static unsigned char s_pXC9_462	[]	= "View Online User Guide";
static unsigned char s_pXC9_463	[]	= "Browse to official website for beginner's guide to " STR_MM_NAME;

static unsigned char s_pXC9_464	[]	= "Support " STR_MM_NAME " Development";
static unsigned char s_pXC9_465	[]	= "Find how to contribute to " STR_MM_NAME " development";

static unsigned char s_pCopy13	[]	= "Installed %.0f/%.0f MB. Remaining: %i:%2.2i min";
static unsigned char s_pCopy14	[]	= "Files linked: %i. Elapsed time: %i:%2.2i min";
static unsigned char s_pCopy15	[]	= "Files linked: %i/%i. Remaining: %i:%2.2i min";
static unsigned char s_pCopy16	[]	= "Copied %.0f MB (%i/%i). Elapsed: %i:%2.2i min";
static unsigned char s_pCopy17	[]	= "Copied %.0f/%.0f MB (%i/%i) Remaining: %i:%2.2i min";
static unsigned char s_pCopy18	[]	= "Copied %.0f/%.0f MB. Remaining: %i:%2.2i min";
static unsigned char s_pCopy19	[]	= "Copied %.0fMB. Elapsed time: %i:%2.2i min";

static unsigned char s_pGMDISC	[]	= "Game disc";
static unsigned char s_pGMINT	[]	= "Internal";
static unsigned char s_pGMEXT	[]	= "External";

static unsigned char s_pGMDB	[]	= "Direct boot";
static unsigned char s_pGMBDM	[]	= "BD mirror";
static unsigned char s_pGMEXTGD	[]	= "Ext Game Data";
static unsigned char s_pGMFAV	[]	= "Favorite";
static unsigned char s_pGMUSBP	[]	= "USB patch";

static unsigned char s_pSIVER	[]	= "Version";
static unsigned char s_pSIIP	[]	= "IP Address";
static unsigned char s_pSINA	[]	= "Not Available";
static unsigned char s_pSIHDD	[]	= "Free HDD space: %.2f GB";
static unsigned char s_pSIMEM	[]	= "Free Memory: %.0f KB";

static unsigned char s_pLGLOAD	[]	= "Load";
static unsigned char s_pLGEXIT	[]	= "Exit";
static unsigned char s_pLGNEXT	[]	= "Next Mode";
static unsigned char s_pLGPREV	[]	= "Prev Mode";
static unsigned char s_pLGGS	[]	= "Game Settings";
static unsigned char s_pLGSS	[]	= "System Menu";

static unsigned char s_SIDESW	[]	= "Set as Wallpaper";
static unsigned char s_SIDERW	[]	= "Restore Wallpaper";

static unsigned char s_pXC2_494	[]	= "Write Access to /dev_flash";
static unsigned char s_pXC2_495	[]	= "Mount /dev_flash as /dev_blind with write permissions.";

static unsigned char s_SIDE_ADV	[]	= "Advanced Settings";
static unsigned char s_SIDE_STD	[]	= "Standard Settings";

static unsigned char s_SIDE_PAUSE[]	= "Pause Music";
static unsigned char s_SIDE_STOP[]	= "Stop Music";

static unsigned char s_SIDE_INFO[]	= "Information";
static unsigned char s_SIDE_BROW[]	= "Browse";

static unsigned char s_BR_NOV[]		= "There are no titles";
static unsigned char s_BR_NOP[]		= "There are no images";
static unsigned char s_BR_NOM[]		= "There are no tracks";
static unsigned char s_BR_NOE[]		= "There are no PSX/PS2/ROM images";

static unsigned char s_BR_HDD[]		= "PS3™ Internal HDD";
static unsigned char s_BR_USB[]		= "USB Device (Port %03i)";

static unsigned char s_pXC2_508	[]	= "Default";
static unsigned char s_pXC2_509	[]	= "Side Menu Color";
static unsigned char s_pXC2_510	[]	= "Changes the background color of the side menu.";
static unsigned char s_pXC2_511	[]	= "Color";

static unsigned char s_pXC2_512	[]	= "Rain Drops";
static unsigned char s_pXC2_513	[]	= "Options";

static unsigned char s_pXC2_514	[]	= "Background Appearance";
static unsigned char s_pXC2_515	[]	= "Changes background type for XMMB and Coverflow modes.";
static unsigned char s_pXC2_516	[]	= "Image";
static unsigned char s_pXC2_517	[]	= "Video";

static unsigned char s_pXC1_RSPS3	[]	= "Restart System";
static unsigned char s_pXC1_RSPS32	[]	= "Close " STR_MM_NAME " and restart your PLAYSTATION\xC2\xAE\x33 System";
static unsigned char s_pXC1_SHUT	[]	= "Turn Off System";
static unsigned char s_pXC1_SHUT2	[]	= "Shutdown your PLAYSTATION\xC2\xAE\x33 System";

static unsigned char s_pXC2_522	[]	= "System Auto-Off";
static unsigned char s_pXC2_523	[]	= "Sets whether to enable or disable the automatic turn-off feature.";

static unsigned char s_pXC2_524	[]	= "Expand Contents of XMMB media columns";
static unsigned char s_pXC2_525	[]	= "Sets whether to scan and show content in music, photo, video and retro columns.";

static unsigned char s_pISO		[]	= "Create ISO";
static unsigned char s_pISO1	[]	= "Creating ISO image, please wait...";
static unsigned char s_pISO2	[]	= "Speed: %4.2f MB/s, Remaining: %02i:%02i min";
static unsigned char s_pISO3	[]	= "ISO Image saved as:\n\n%s\n\nProcessed %.0f MB in %i:%02i min (%.2f MB/s)";
static unsigned char s_pISO4	[]	= "Error occurred while accessing data!\n\nSectors read: %lu\nTotal sectors: %lu";
static unsigned char s_pISO5	[]	= "ERROR: ISO Image cannot be created!";

static unsigned char s_pXC2_532	[]	= "PSX Display Mode (PAL)";
static unsigned char s_pXC2_533	[]	= "Sets default video output mode for PAL region titles.";

static unsigned char s_pXC2_534	[]	= "PSX Display Mode (NTSC)";
static unsigned char s_pXC2_535	[]	= "Sets default video output mode for NTSC region titles.";

static unsigned char s_pSFD		[]	= "Start Game from Disc (PSX/PS3)";
static unsigned char s_pNotAllow[]	= "This operation is not allowed.";
static unsigned char s_pEnableDA[]	= "Enable Direct Disc Access";

static unsigned char s_pUMDDISC[]	= "PSP\xE2\x84\xA2 UMD Disc";

static unsigned char s_pRegionBD[]	= "Blu-ray\xE2\x84\xA2 Movie Disc Region";
static unsigned char s_pRegionBD1[]	= "Sets preferred region for Blu-ray\xE2\x84\xA2 movie titles.";

static unsigned char s_pRegionDVD[]	= "DVD Video Disc Region";
static unsigned char s_pRegionDVD1[]= "Sets preferred region for DVD movie titles.";

static unsigned char s_pPROMETH	[]	= "The selected PSP\xE2\x84\xA2 ISO is not supported!\n\nERROR: ISO is in Prometheus format!";
static unsigned char s_pPSPLAUN	[]	= "PSP\xE2\x84\xA2 Launcher application is not installed!\n\nPlease quit to XMB\xE2\x84\xA2 and install the latest version of \x22PSP\xE2\x84\xA2 Launcher\x22.";

static unsigned char s_pPS2USB	[]	= "PS2\xE2\x84\xA2 ISO format is not supported from external USB drives.\n\nDo you want to transfer the file to internal HDD?";
static unsigned char s_pENCRYPT	[]	= "WARNING:\n\nThe disc you are going to copy may be encrypted. Before using the ISO image, transfer it to your PC\nand decrypt it with DVDFab or AnyDVDHD software.";
static unsigned char s_pERRCUE	[]	= "ERROR:\n\nCannot find corresponding BIN file to mount the image!\n\nPlease make sure that both CUE and BIN files share the same name\nor if FILE directive in CUE points to a valid BIN file.";

static unsigned char s_pEJECT	[]	= "Eject Disc";
static unsigned char s_pINSERT	[]	= "Insert Disc";

static unsigned char s_pISONAMES[]	= "Detect Game Title in ISO Images";
static unsigned char s_pISONAMES1[]	= "Sets whether to display ISO filename or detect the game title.";

#ifdef COBRA_MODE
	static unsigned char s_USBFW	[]	= "Check for new USB dongle firmware version";

	static unsigned char s_pLEDS	[]	= "Set Dongle LEDs";
	static unsigned char s_pLEDS1	[]	= "Changes dongle led light or turns leds off.";
	static unsigned char s_pLEDS2	[]	= "Blue";
	static unsigned char s_pLEDS3	[]	= "Green";

	static unsigned char s_pNOTPS3	[]	= "WARNING:\n\nThe selected disc image is not a compliant PS3 ISO,\nbut you may still be able to access it in other applications.";
	static unsigned char s_pNEWMM	[]	= "WARNING:\n\nBefore updating to CobraUSB firmware %s\nmake sure that you have downloaded the LATEST version of " STR_MM_NAME " to a USB stick.\nAfter dongle update is complete, please re-install " STR_MM_NAME "!";
#else
	static unsigned char s_USBFW	[]	= "-";

	static unsigned char s_pLEDS	[]	= "-";
	static unsigned char s_pLEDS1	[]	= "-";
	static unsigned char s_pLEDS2	[]	= "-";
	static unsigned char s_pLEDS3	[]	= "-";

	static unsigned char s_pNOTPS3	[]	= "-";
	static unsigned char s_pNEWMM	[]	= "-";

#endif

static unsigned char s_pXC2_STFONT	[]	= "Showtime Font Preference";
static unsigned char s_pXC2_STFONT1	[]	= "Sets default GUI and subtitle font for Showtime Media Player.";

static unsigned char s_pISO_EXTR	[]	= "Extract ISO";
static unsigned char s_pPSPLAUN2	[]	= "PSP\xE2\x84\xA2 Launcher application must be updated!\n\nPlease quit to XMB\xE2\x84\xA2 and install the latest version of \x22PSP\xE2\x84\xA2 Launcher\x22.";

static unsigned char s_pSPOOF		[]	= "System Firmware Version";
static unsigned char s_pSPOOF1		[]	= "Enables or disables spoofing of PS3\xE2\x84\xA2 System Firmware Version. Reboot required.";

static unsigned char s_pREBOOT0		[]	= "Press OK to reboot your PS3\xE2\x84\xA2 System";
static unsigned char s_pREBOOT1		[]	= "Rebooting";
static unsigned char s_pCOBRA		[]	= "To use this feature you must attach the Cobra USB to your PS3\xE2\x84\xA2 System";

static unsigned char s_pNETHOST		[]	= "Network Servers";
static unsigned char s_pNETHOST1	[]	= "Sets connection information for remote network servers.";

static unsigned char s_pRESETINI	[]	= "Reset Options to Default";

static unsigned char s_pXC2_572		[]	= "Top Media Bar Color";
static unsigned char s_pXC2_573		[]	= "Changes the background color of the TMB menu.";

static unsigned char s_pXC2_574		[]	= "Swap Sticks In mmOS";
static unsigned char s_pXC2_575		[]	= "Change actions of Left and Right Sticks in mmOS.";

static unsigned char s_pCMCut		[]	= "Cut";
static unsigned char s_pCMPaste		[]	= "Paste";
static unsigned char s_pCMPasteISO	[]	= "Paste as ISO";
static unsigned char s_pCMPasteLNK	[]	= "Paste as Link";
static unsigned char s_pShowDesktop	[]	= "Show Desktop";
static unsigned char s_pResetDesktop[]	= "Reset Desktop";

static unsigned char s_pP3TTHM		[]	= "PS3\xE2\x84\xA2 theme \x22%s\x22 copied to system XMB\xE2\x84\xA2 themes (/dev_hdd0/theme) successfully.";
static unsigned char s_p3DPlay		[]	= "Selected video will be played in 3D or Anaglyph format, depending on your TV set capabilities.\n\nUse [START/SELECT/UP/DOWN/LEFT/RIGHT] to control playback,\n[L1/R1/L2/R2] to adjust anaglyph bias,\n[L3/R3] to switch SBS/TB or [CIRCLE/TRIANGLE] to exit.";

static unsigned char s_pOpenTarget	[]	= "Open Location";
static unsigned char s_pCMUnzip		[]	= "Unzip Here";

static unsigned char s_pInstallZip	[]	=  "INSTALLABLE PACKAGE:\n\nDo you want to Install/Extract the selected archive in the following folder?\n\n%s";

static unsigned char s_pShowTemp	[]	=  "Show Temperature Data";
static unsigned char s_pShowTemp1	[]	=  "Displays CELL CPU/RSX GPU Temperatures in Clock Area";

static MMString s_MMStringDef[] = {
 { sizeof ( s_pDebugMode  ) - 1, s_pDebugMode	}, //0
 { sizeof ( s_pQuit0	  ) - 1, s_pQuit0		}, //1
 { sizeof ( s_pQuit1	  ) - 1, s_pQuit1		},
 { sizeof ( s_pRestart0	  ) - 1, s_pRestart0	},
 { sizeof ( s_pWarnFTP	  ) - 1, s_pWarnFTP		},
 { sizeof ( s_pWarnSNES	  ) - 1, s_pWarnSNES	},
 { sizeof ( s_pWarnGEN	  ) - 1, s_pWarnGEN		},
 { sizeof ( s_pWarnFCEU	  ) - 1, s_pWarnFCEU	},
 { sizeof ( s_pWarnVBA	  ) - 1, s_pWarnVBA		},
 { sizeof ( s_pWarnFBA	  ) - 1, s_pWarnFBA		}, //9

 { sizeof ( s_pCopy0	  ) - 1, s_pCopy0		}, //10
 { sizeof ( s_pCopy1	  ) - 1, s_pCopy1		},
 { sizeof ( s_pCopy2	  ) - 1, s_pCopy2		},
 { sizeof ( s_pCopy3	  ) - 1, s_pCopy3		},
 { sizeof ( s_pCopy4	  ) - 1, s_pCopy4		},
 { sizeof ( s_pCopy5	  ) - 1, s_pCopy5		},
 { sizeof ( s_pCopy6	  ) - 1, s_pCopy6		},
 { sizeof ( s_pCopy7	  ) - 1, s_pCopy7		},
 { sizeof ( s_pCopy8	  ) - 1, s_pCopy8		},
 { sizeof ( s_pCopy9	  ) - 1, s_pCopy9		},
 { sizeof ( s_pCopy10	  ) - 1, s_pCopy10		},
 { sizeof ( s_pCopy11	  ) - 1, s_pCopy11		},
 { sizeof ( s_pCopy12	  ) - 1, s_pCopy12		}, //22

 { sizeof ( s_pNetCopy0	  ) - 1, s_pNetCopy0	}, //23
 { sizeof ( s_pNetCopy1	  ) - 1, s_pNetCopy1	},
 { sizeof ( s_pNetCopy2	  ) - 1, s_pNetCopy2	},
 { sizeof ( s_pNetCopy3	  ) - 1, s_pNetCopy3	},
 { sizeof ( s_pNetCopy4	  ) - 1, s_pNetCopy4	}, //27

 { sizeof ( s_pMove0	  ) - 1, s_pMove0		}, //28
 { sizeof ( s_pMove1	  ) - 1, s_pMove1		},
 { sizeof ( s_pMove2	  ) - 1, s_pMove2		},
 { sizeof ( s_pMove3	  ) - 1, s_pMove3		},
 { sizeof ( s_pMove4	  ) - 1, s_pMove4		}, //32

 { sizeof ( s_pWarnINET	  ) - 1, s_pWarnINET	}, //33
 { sizeof ( s_pErrSRV0	  ) - 1, s_pErrSRV0		},
 { sizeof ( s_pErrUPD0	  ) - 1, s_pErrUPD0		},
 { sizeof ( s_pErrUPD1	  ) - 1, s_pErrUPD1		}, //36

 { sizeof ( s_pErrMNT	  ) - 1, s_pErrMNT		}, //37
 { sizeof ( s_pErrMVGAME  ) - 1, s_pErrMVGAME	},
 { sizeof ( s_pErrMVAV	  ) - 1, s_pErrMVAV		},

 { sizeof ( s_pDownUpdate ) - 1, s_pDownUpdate		}, //40
 { sizeof ( s_pDownCover  ) - 1, s_pDownCover		},
 { sizeof ( s_pDownFile	  ) - 1, s_pDownFile		},
 { sizeof ( s_pDownTheme  ) - 1, s_pDownTheme		},

 { sizeof ( s_pDownMSG0	  ) - 1, s_pDownMSG0		}, //44
 { sizeof ( s_pDownMSG1	  ) - 1, s_pDownMSG1		},
 { sizeof ( s_pDownMSG2	  ) - 1, s_pDownMSG2		},

 { sizeof ( s_pParamVer	  ) - 1, s_pParamVer		}, //47
 { sizeof ( s_pLastPlay	  ) - 1, s_pLastPlay		},
 { sizeof ( s_pSetAccess  ) - 1, s_pSetAccess		},
 { sizeof ( s_pSetAccess1 ) - 1, s_pSetAccess1		},

 { sizeof ( s_pPreProcess ) - 1, s_pPreProcess		}, //51

 { sizeof ( s_pNoSpace0	  ) - 1, s_pNoSpace0		}, //52
 { sizeof ( s_pNoSpace0	  ) - 1, s_pNoSpace1		},

 { sizeof ( s_pErrNoMemWeb	) - 1, s_pErrNoMemWeb	}, //54
 { sizeof ( s_pErrNoMem		) - 1, s_pErrNoMem		},

 { sizeof ( s_pPleaseWait	) - 1, s_pPleaseWait	},
 { sizeof ( s_pWhatsNew		) - 1, s_pWhatsNew		},
 { sizeof ( s_pNewVer		) - 1, s_pNewVer		},
 { sizeof ( s_pNewVerDL		) - 1, s_pNewVerDL		},
 { sizeof ( s_pNewVerNN		) - 1, s_pNewVerNN		}, //60
 { sizeof ( s_pNewVerUSB	) - 1, s_pNewVerUSB		},

 { sizeof ( s_pGameUpdate1	) - 1, s_pGameUpdate1	}, //62
 { sizeof ( s_pGameUpdate2	) - 1, s_pGameUpdate2	},
 { sizeof ( s_pGameUpdate3	) - 1, s_pGameUpdate3	},
 { sizeof ( s_pGameUpdate5	) - 1, s_pGameUpdate5	},
 { sizeof ( s_pGameUpdate6	) - 1, s_pGameUpdate6	},
 { sizeof ( s_pGameUpdate7	) - 1, s_pGameUpdate7	}, //67

 { sizeof ( s_pSelTheme	    ) - 1, s_pSelTheme		},
 { sizeof ( s_pSelLang  	) - 1, s_pSelLang		},
 { sizeof ( s_pDelGameC		) - 1, s_pDelGameC		}, //70

 { sizeof ( s_pFMGames		) - 1, s_pFMGames		},
 { sizeof ( s_pFMUpdate		) - 1, s_pFMUpdate		},
 { sizeof ( s_pFMAbout		) - 1, s_pFMAbout		},
 { sizeof ( s_pFMHelp		) - 1, s_pFMHelp		},
 { sizeof ( s_pFMThemes		) - 1, s_pFMThemes		}, //75

 { sizeof ( s_pCMMulDir		) - 1, s_pCMMulDir		}, //76
 { sizeof ( s_pCMMulFile	) - 1, s_pCMMulFile		},

 { sizeof ( s_pCMCopy		) - 1, s_pCMCopy		}, //78
 { sizeof ( s_pCMMove		) - 1, s_pCMMove		},
 { sizeof ( s_pCMRename		) - 1, s_pCMRename		},
 { sizeof ( s_pCMDelete		) - 1, s_pCMDelete		},
 { sizeof ( s_pCMShortcut	) - 1, s_pCMShortcut	},
 { sizeof ( s_pCMShadow		) - 1, s_pCMShadow		},
 { sizeof ( s_pCMBDMirror	) - 1, s_pCMBDMirror	},
 { sizeof ( s_pCMNetHost	) - 1, s_pCMNetHost		},
 { sizeof ( s_pCMHexView	) - 1, s_pCMHexView		},
 { sizeof ( s_pCMProps		) - 1, s_pCMProps		},
 { sizeof ( s_pCMNewDir		) - 1, s_pCMNewDir		}, //88

 { sizeof ( s_pApplyTheme	) - 1, s_pApplyTheme	}, //89

 { sizeof ( s_pMMUpdate		) - 1, s_pMMUpdate		}, //90
 { sizeof ( s_pMMUpdateL1	) - 1, s_pMMUpdateL1	},
 { sizeof ( s_pMMUpdateL2	) - 1, s_pMMUpdateL2	},
 { sizeof ( s_pMMUpdateL3	) - 1, s_pMMUpdateL3	},
 { sizeof ( s_pMMUpdateL4	) - 1, s_pMMUpdateL4	},

 { sizeof ( s_pMMRefresh	) - 1, s_pMMRefresh		}, //95
 { sizeof ( s_pMMRefreshL1	) - 1, s_pMMRefreshL1	},
 { sizeof ( s_pMMRefreshL2	) - 1, s_pMMRefreshL2	},
 { sizeof ( s_pMMRefreshL3	) - 1, s_pMMRefreshL3	},
 { sizeof ( s_pMMRefreshL4	) - 1, s_pMMRefreshL4	},

 { sizeof ( s_pMMFileMan	) - 1, s_pMMFileMan		}, //100
 { sizeof ( s_pMMFileManL1	) - 1, s_pMMFileManL1	},
 { sizeof ( s_pMMFileManL2	) - 1, s_pMMFileManL2	},
 { sizeof ( s_pMMFileManL3	) - 1, s_pMMFileManL3	},
 { sizeof ( s_pMMFileManL4	) - 1, s_pMMFileManL4	},

 { sizeof ( s_pMMShowtimeST		) - 1, s_pMMShowtimeST		}, //105
 { sizeof ( s_pMMShowtimeSTL1	) - 1, s_pMMShowtimeSTL1	},
 { sizeof ( s_pMMShowtimeSTL2	) - 1, s_pMMShowtimeSTL2	},
 { sizeof ( s_pMMShowtimeSTL3	) - 1, s_pMMShowtimeSTL3	},
 { sizeof ( s_pMMShowtimeSTL4	) - 1, s_pMMShowtimeSTL4	},

 { sizeof ( s_pMMNTFS			) - 1, s_pMMNTFS			}, //110
 { sizeof ( s_pMMNTFSL1			) - 1, s_pMMNTFSL1			},
 { sizeof ( s_pMMNTFSL2			) - 1, s_pMMNTFSL2			},
 { sizeof ( s_pMMNTFSL3			) - 1, s_pMMNTFSL3			},
 { sizeof ( s_pMMNTFSL4			) - 1, s_pMMNTFSL4			},

 { sizeof ( s_pMMShowtimeLK		) - 1, s_pMMShowtimeLK		}, //115
 { sizeof ( s_pMMShowtimeLKL1	) - 1, s_pMMShowtimeLKL1	},
 { sizeof ( s_pMMShowtimeLKL2	) - 1, s_pMMShowtimeLKL2	},
 { sizeof ( s_pMMShowtimeLKL3	) - 1, s_pMMShowtimeLKL3	},
 { sizeof ( s_pMMShowtimeLKL4	) - 1, s_pMMShowtimeLKL4	},

 { sizeof ( s_pMMScrShot	) - 1, s_pMMScrShot		}, //120
 { sizeof ( s_pMMScrShotL1	) - 1, s_pMMScrShotL1	},
 { sizeof ( s_pMMScrShotL2	) - 1, s_pMMScrShotL2	},
 { sizeof ( s_pMMScrShotL3	) - 1, s_pMMScrShotL3	},
 { sizeof ( s_pMMScrShotL4	) - 1, s_pMMScrShotL4	},

 { sizeof ( s_pMMScrSave	) - 1, s_pMMScrSave		}, //125
 { sizeof ( s_pMMScrSaveL1	) - 1, s_pMMScrSaveL1	},
 { sizeof ( s_pMMScrSaveL2	) - 1, s_pMMScrSaveL2	},
 { sizeof ( s_pMMScrSaveL3	) - 1, s_pMMScrSaveL3	},
 { sizeof ( s_pMMScrSaveL4	) - 1, s_pMMScrSaveL4	},

 { sizeof ( s_pMMRestart	) - 1, s_pMMRestart		}, //130
 { sizeof ( s_pMMRestartL1	) - 1, s_pMMRestartL1	},
 { sizeof ( s_pMMRestartL2	) - 1, s_pMMRestartL2	},
 { sizeof ( s_pMMRestartL3	) - 1, s_pMMRestartL3	},
 { sizeof ( s_pMMRestartL4	) - 1, s_pMMRestartL4	},

 { sizeof ( s_pMMSetup		) - 1, s_pMMSetup		}, //135
 { sizeof ( s_pMMSetupL1	) - 1, s_pMMSetupL1		},
 { sizeof ( s_pMMSetupL2	) - 1, s_pMMSetupL2		},
 { sizeof ( s_pMMSetupL3	) - 1, s_pMMSetupL3		},
 { sizeof ( s_pMMSetupL4	) - 1, s_pMMSetupL4		},

 { sizeof ( s_pMMQuit		) - 1, s_pMMQuit		}, //140
 { sizeof ( s_pMMQuitL1		) - 1, s_pMMQuitL1		},
 { sizeof ( s_pMMQuitL2		) - 1, s_pMMQuitL2		},
 { sizeof ( s_pMMQuitL3		) - 1, s_pMMQuitL3		},
 { sizeof ( s_pMMQuitL4		) - 1, s_pMMQuitL4		},

 { sizeof ( s_pMMHelp		) - 1, s_pMMHelp		}, //145
 { sizeof ( s_pMMHelpL1		) - 1, s_pMMHelpL1		},
 { sizeof ( s_pMMHelpL2		) - 1, s_pMMHelpL2		},
 { sizeof ( s_pMMHelpL3		) - 1, s_pMMHelpL3		},
 { sizeof ( s_pMMHelpL4		) - 1, s_pMMHelpL4		},

 { sizeof ( s_pButNavigate	) - 1, s_pButNavigate	}, //150
 { sizeof ( s_pButSelect	) - 1, s_pButSelect		},
 { sizeof ( s_pButBack		) - 1, s_pButBack		},
 { sizeof ( s_pButCancel	) - 1, s_pButCancel		},
 { sizeof ( s_pButApply		) - 1, s_pButApply		},
 { sizeof ( s_pButConfirm	) - 1, s_pButConfirm	},
 { sizeof ( s_pButGenre		) - 1, s_pButGenre		},
 { sizeof ( s_pButDownload	) - 1, s_pButDownload	},
 { sizeof ( s_pButLoad		) - 1, s_pButLoad		},
 { sizeof ( s_pButPrev		) - 1, s_pButPrev		},
 { sizeof ( s_pButNext		) - 1, s_pButNext		}, //160
 { sizeof ( s_pButLast		) - 1, s_pButLast		},
 { sizeof ( s_pButFirst		) - 1, s_pButFirst		},

 { sizeof ( s_pSelGenre		) - 1, s_pSelGenre		}, //163
 { sizeof ( s_pButDownTheme	) - 1, s_pButDownTheme	},

 { sizeof ( s_pGMCopy		) - 1, s_pGMCopy		}, //165
 { sizeof ( s_pGMCopyL1		) - 1, s_pGMCopyL1		},
 { sizeof ( s_pGMCopyL2		) - 1, s_pGMCopyL2		},
 { sizeof ( s_pGMCopyL3		) - 1, s_pGMCopyL3		},

 { sizeof ( s_pGMDelete		) - 1, s_pGMDelete		}, //169
 { sizeof ( s_pGMDeleteL1	) - 1, s_pGMDeleteL1	},
 { sizeof ( s_pGMDeleteL2	) - 1, s_pGMDeleteL2	},
 { sizeof ( s_pGMDeleteL3	) - 1, s_pGMDeleteL3	},

 { sizeof ( s_pGMRename		) - 1, s_pGMRename		}, //173
 { sizeof ( s_pGMRenameL1	) - 1, s_pGMRenameL1	},
 { sizeof ( s_pGMRenameL2	) - 1, s_pGMRenameL2	},
 { sizeof ( s_pGMRenameL3	) - 1, s_pGMRenameL3	},

 { sizeof ( s_pGMUpdate		) - 1, s_pGMUpdate		}, //177
 { sizeof ( s_pGMUpdateL1	) - 1, s_pGMUpdateL1	},
 { sizeof ( s_pGMUpdateL2	) - 1, s_pGMUpdateL2	},
 { sizeof ( s_pGMUpdateL3	) - 1, s_pGMUpdateL3	},

 { sizeof ( s_pGMTest		) - 1, s_pGMTest		}, //181
 { sizeof ( s_pGMTestL1		) - 1, s_pGMTestL1		},
 { sizeof ( s_pGMTestL2		) - 1, s_pGMTestL2		},
 { sizeof ( s_pGMTestL3		) - 1, s_pGMTestL3		},

 { sizeof ( s_pGMPerm		) - 1, s_pGMPerm		}, //185
 { sizeof ( s_pGMPermL1		) - 1, s_pGMPermL1		},
 { sizeof ( s_pGMPermL2		) - 1, s_pGMPermL2		},
 { sizeof ( s_pGMPermL3		) - 1, s_pGMPermL3		}, //188

 { sizeof ( s_pPOPGS		) - 1, s_pPOPGS			}, //189
 { sizeof ( s_pPOPChangeS	) - 1, s_pPOPChangeS	},
 { sizeof ( s_pPOPSysInfo	) - 1, s_pPOPSysInfo	},
 { sizeof ( s_pPOPLang		) - 1, s_pPOPLang		},
 { sizeof ( s_pPOPCache		) - 1, s_pPOPCache		},
 { sizeof ( s_pPOPPhoto		) - 1, s_pPOPPhoto		},
 { sizeof ( s_pPOPMusic		) - 1, s_pPOPMusic		},
 { sizeof ( s_pPOPST		) - 1, s_pPOPST			},
 { sizeof ( s_pPOPVideo		) - 1, s_pPOPVideo		},
 { sizeof ( s_pPOPRefGames	) - 1, s_pPOPRefGames	},
 { sizeof ( s_pPOPRefRoms	) - 1, s_pPOPRefRoms	},
 { sizeof ( s_pPOPRom		) - 1, s_pPOPRom		}, //200

 { sizeof ( s_pPOPGrpGenre	) - 1, s_pPOPGrpGenre	}, //201
 { sizeof ( s_pPOPGrpEmu	) - 1, s_pPOPGrpEmu		},
 { sizeof ( s_pPOPGrpName	) - 1, s_pPOPGrpName	},
 { sizeof ( s_pPOPSwitch	) - 1, s_pPOPSwitch		},

 { sizeof ( s_pPOP1of1		) - 1, s_pPOP1of1		}, //205
 { sizeof ( s_pPOPPlaying	) - 1, s_pPOPPlaying	},
 { sizeof ( s_pPOPPaused	) - 1, s_pPOPPaused		},
 { sizeof ( s_pPOPVol		) - 1, s_pPOPVol		}, //208

 { sizeof ( s_pOther		) - 1, s_pOther			}, //209

 { sizeof ( s_pGENOther		) - 1, s_pGENOther		}, //210
 { sizeof ( s_pGENAct		) - 1, s_pGENAct		},
 { sizeof ( s_pGENAdv		) - 1, s_pGENAdv		},
 { sizeof ( s_pGENFam		) - 1, s_pGENFam		},
 { sizeof ( s_pGENFight		) - 1, s_pGENFight		},
 { sizeof ( s_pGENParty		) - 1, s_pGENParty		},
 { sizeof ( s_pGENPlat		) - 1, s_pGENPlat		},
 { sizeof ( s_pGENPuzz		) - 1, s_pGENPuzz		},
 { sizeof ( s_pGENRole		) - 1, s_pGENRole		},
 { sizeof ( s_pGENRace		) - 1, s_pGENRace		},
 { sizeof ( s_pGENShoot		) - 1, s_pGENShoot		}, //220
 { sizeof ( s_pGENSim		) - 1, s_pGENSim		},
 { sizeof ( s_pGENSport		) - 1, s_pGENSport		},
 { sizeof ( s_pGENStrat		) - 1, s_pGENStrat		},
 { sizeof ( s_pGENTriv		) - 1, s_pGENTriv		},
 { sizeof ( s_pGEN3D		) - 1, s_pGEN3D			}, //225

 { sizeof ( s_pRETRO		) - 1, s_pRETRO			}, //226
 { sizeof ( s_pRETSNES		) - 1, s_pRETSNES		},
 { sizeof ( s_pRETFCEU		) - 1, s_pRETFCEU		},
 { sizeof ( s_pRETVBA		) - 1, s_pRETVBA		},
 { sizeof ( s_pRETGEN		) - 1, s_pRETGEN		},
 { sizeof ( s_pRETFBA		) - 1, s_pRETFBA		}, //231

 { sizeof ( s_pXCS			) - 1, s_pXCS			}, //232
 { sizeof ( s_pXCP			) - 1, s_pXCP			},
 { sizeof ( s_pXCM			) - 1, s_pXCM			},
 { sizeof ( s_pXCV			) - 1, s_pXCV			},
 { sizeof ( s_pXCG			) - 1, s_pXCG			},
 { sizeof ( s_pXCF			) - 1, s_pXCF			},
 { sizeof ( s_pXCW			) - 1, s_pXCW			}, //238

 { sizeof ( s_pPS2			) - 1, s_pPS2			}, //239
 { sizeof ( s_pPKG			) - 1, s_pPKG			},
 { sizeof ( s_pNoSplit1		) - 1, s_pNoSplit1		},
 { sizeof ( s_pNoSplit2		) - 1, s_pNoSplit2		},
 { sizeof ( s_pNoSplit3		) - 1, s_pNoSplit3		},
 { sizeof ( s_pVerifying	) - 1, s_pVerifying		}, //244
 { sizeof ( s_pCanceled		) - 1, s_pCanceled		},
 { sizeof ( s_pNotSupported	) - 1, s_pNotSupported	},
 { sizeof ( s_pNotSupported2) - 1, s_pNotSupported2	},
 { sizeof ( s_pPS3DISC		) - 1, s_pPS3DISC		},
 { sizeof ( s_pThmInstall	) - 1, s_pThmInstall	},
 { sizeof ( s_pToDBoot		) - 1, s_pToDBoot		},

 { sizeof ( s_pDLST			) - 1, s_pDLST			}, //251
 { sizeof ( s_pStartBD1		) - 1, s_pStartBD1		},
 { sizeof ( s_pStartBD2		) - 1, s_pStartBD2		},
 { sizeof ( s_pOverwrite	) - 1, s_pOverwrite		},

 { sizeof ( s_pIncomplete	) - 1, s_pIncomplete	}, //255
 { sizeof ( s_pErrBDEMU1	) - 1, s_pErrBDEMU1		},
 { sizeof ( s_pErrBDEMU2	) - 1, s_pErrBDEMU2		},
 { sizeof ( s_pErrBDEMU3	) - 1, s_pErrBDEMU3		},

 { sizeof ( s_pCritical		) - 1, s_pCritical		}, //259

 { sizeof ( s_pDelFile		) - 1, s_pDelFile		}, //260
 { sizeof ( s_pDelFiles		) - 1, s_pDelFiles		},
 { sizeof ( s_pDelDir		) - 1, s_pDelDir		},
 { sizeof ( s_pDelDirs		) - 1, s_pDelDirs		},

 { sizeof ( s_pDelFromHDD	) - 1, s_pDelFromHDD	},
 { sizeof ( s_pDelFromUSB	) - 1, s_pDelFromUSB	},
 { sizeof ( s_pDelFromCache	) - 1, s_pDelFromCache	},

 { sizeof ( s_pCpHdd2Usb	) - 1, s_pCpHdd2Usb		}, //267
 { sizeof ( s_pCpUsb2Hdd	) - 1, s_pCpUsb2Hdd		},
 { sizeof ( s_pCpPfs2Hdd	) - 1, s_pCpPfs2Hdd		},
 { sizeof ( s_pCpUsb2Usb	) - 1, s_pCpUsb2Usb		},

 { sizeof ( s_pOverwriteNo	) - 1, s_pOverwriteNo	}, //271
 { sizeof ( s_pDelPartHDD	) - 1, s_pDelPartHDD	},
 { sizeof ( s_pDelPartUSB	) - 1, s_pDelPartUSB	},
 { sizeof ( s_pDelCacheDone	) - 1, s_pDelCacheDone	},

 { sizeof ( s_pCpBD2Hdd		) - 1, s_pCpBD2Hdd		}, //275
 { sizeof ( s_pCpBD2Usb		) - 1, s_pCpBD2Usb		},

 { sizeof ( s_pPinGame		) - 1, s_pPinGame		}, //277
 { sizeof ( s_pPinErr		) - 1, s_pPinErr		},
 { sizeof ( s_pPinEnter		) - 1, s_pPinEnter		},
 { sizeof ( s_pPinNew		) - 1, s_pPinNew		},
 { sizeof ( s_pPinErr2		) - 1, s_pPinErr2		}, //281

 { sizeof ( s_pBd2AVCHD		) - 1, s_pBd2AVCHD		}, //282
 { sizeof ( s_pBd2AVCHD2	) - 1, s_pBd2AVCHD2		},
 { sizeof ( s_pActAVCHD		) - 1, s_pActAVCHD		},
 { sizeof ( s_pActAVCHD2	) - 1, s_pActAVCHD2		}, //285
 { sizeof ( s_pBd2AVCHD3	) - 1, s_pBd2AVCHD3		},
 { sizeof ( s_pActBDMV		) - 1, s_pActBDMV		},
 { sizeof ( s_pAttUSB		) - 1, s_pAttUSB		},
 { sizeof ( s_pAttPFS		) - 1, s_pAttPFS		},
 { sizeof ( s_pCacheFile	) - 1, s_pCacheFile		}, //290
 { sizeof ( s_pHddErr		) - 1, s_pHddErr		},
 { sizeof ( s_pUsbErr		) - 1, s_pUsbErr		},
 { sizeof ( s_pTitleLocked	) - 1, s_pTitleLocked	},
 { sizeof ( s_pTitleRO		) - 1, s_pTitleRO		}, //294

 { sizeof ( s_pRenameTo		) - 1, s_pRenameTo		},
 { sizeof ( s_pCreateNew	) - 1, s_pCreateNew		},

 { sizeof ( s_pXCUP			) - 1, s_pXCUP			}, //297
 { sizeof ( s_pXCUP1		) - 1, s_pXCUP1			},
 { sizeof ( s_pXCFM			) - 1, s_pXCFM			},
 { sizeof ( s_pXCFM0		) - 1, s_pXCFM0			}, //300
 { sizeof ( s_pXCFM1		) - 1, s_pXCFM1			},
 { sizeof ( s_pXCRF			) - 1, s_pXCRF			},
 { sizeof ( s_pXCRF1		) - 1, s_pXCRF1			},
 { sizeof ( s_pXCRF2		) - 1, s_pXCRF2			},
 { sizeof ( s_pXCRF3		) - 1, s_pXCRF3			},
 { sizeof ( s_pXCPF			) - 1, s_pXCPF			}, //306
 { sizeof ( s_pXCPF1		) - 1, s_pXCPF1			},
 { sizeof ( s_pXCSS			) - 1, s_pXCSS			},
 { sizeof ( s_pXCSS1		) - 1, s_pXCSS1			},
 { sizeof ( s_pXCTH			) - 1, s_pXCTH			},
 { sizeof ( s_pXCTH1		) - 1, s_pXCTH1			},
 { sizeof ( s_pXCHL			) - 1, s_pXCHL			}, //312
 { sizeof ( s_pXCHL1		) - 1, s_pXCHL1			},
 { sizeof ( s_pXCRS			) - 1, s_pXCRS			},
 { sizeof ( s_pXCRS1		) - 1, s_pXCRS1			},
 { sizeof ( s_pXCQT			) - 1, s_pXCQT			},
 { sizeof ( s_pXCQT1		) - 1, s_pXCQT1			}, //317

 { sizeof ( s_pXC5LK		) - 1, s_pXC5LK			},
 { sizeof ( s_pXC5LK1		) - 1, s_pXC5LK1		},
 { sizeof ( s_pXC5ST		) - 1, s_pXC5ST			},
 { sizeof ( s_pXC5ST1		) - 1, s_pXC5ST1		}, //321

 { sizeof ( s_pXC2SS		) - 1, s_pXC2SS			},
 { sizeof ( s_pXC2SS1		) - 1, s_pXC2SS1		},
 { sizeof ( s_pXC2IL		) - 1, s_pXC2IL			},
 { sizeof ( s_pXC2IL1		) - 1, s_pXC2IL1		},
 { sizeof ( s_pXC2GC		) - 1, s_pXC2GC			},
 { sizeof ( s_pXC2GC1		) - 1, s_pXC2GC1		}, //327

 { sizeof ( s_pXC2YES		) - 1, s_pXC2YES		},
 { sizeof ( s_pXC2NO		) - 1, s_pXC2NO			},
 { sizeof ( s_pXC2AUTO		) - 1, s_pXC2AUTO		}, //330
 { sizeof ( s_pXC2ENABLE	) - 1, s_pXC2ENABLE		},
 { sizeof ( s_pXC2DISABLE	) - 1, s_pXC2DISABLE	},
 { sizeof ( s_pXC2NONE		) - 1, s_pXC2NONE		},
 { sizeof ( s_pXC2UNAV		) - 1, s_pXC2UNAV		},
 { sizeof ( s_pXC2STD		) - 1, s_pXC2STD		},
 { sizeof ( s_pXC2MIN		) - 1, s_pXC2MIN		}, //336
 { sizeof ( s_pXC2SEC		) - 1, s_pXC2SEC		},
 { sizeof ( s_pXC2LEVEL		) - 1, s_pXC2LEVEL		}, //338

  { sizeof ( s_pXC2_339		) - 1, s_pXC2_339		},
  { sizeof ( s_pXC2_340		) - 1, s_pXC2_340		},
  { sizeof ( s_pXC2_341		) - 1, s_pXC2_341		},
  { sizeof ( s_pXC2_342		) - 1, s_pXC2_342		},
  { sizeof ( s_pXC2_343		) - 1, s_pXC2_343		},
  { sizeof ( s_pXC2_344		) - 1, s_pXC2_344		},
  { sizeof ( s_pXC2_345		) - 1, s_pXC2_345		},
  { sizeof ( s_pXC2_346		) - 1, s_pXC2_346		},
  { sizeof ( s_pXC2_347		) - 1, s_pXC2_347		},
  { sizeof ( s_pXC2_348		) - 1, s_pXC2_348		},
  { sizeof ( s_pXC2_349		) - 1, s_pXC2_349		},
  { sizeof ( s_pXC2_350		) - 1, s_pXC2_350		},
  { sizeof ( s_pXC2_351		) - 1, s_pXC2_351		},
  { sizeof ( s_pXC2_352		) - 1, s_pXC2_352		},
  { sizeof ( s_pXC2_353		) - 1, s_pXC2_353		},
  { sizeof ( s_pXC2_354		) - 1, s_pXC2_354		},
  { sizeof ( s_pXC2_355		) - 1, s_pXC2_355		},
  { sizeof ( s_pXC2_356		) - 1, s_pXC2_356		},
  { sizeof ( s_pXC2_357		) - 1, s_pXC2_357		},
  { sizeof ( s_pXC2_358		) - 1, s_pXC2_358		},
  { sizeof ( s_pXC2_359		) - 1, s_pXC2_359		},
  { sizeof ( s_pXC2_360		) - 1, s_pXC2_360		},
  { sizeof ( s_pXC2_361		) - 1, s_pXC2_361		},
  { sizeof ( s_pXC2_362		) - 1, s_pXC2_362		},
  { sizeof ( s_pXC2_363		) - 1, s_pXC2_363		},
  { sizeof ( s_pXC2_364		) - 1, s_pXC2_364		},
  { sizeof ( s_pXC2_365		) - 1, s_pXC2_365		},
  { sizeof ( s_pXC2_366		) - 1, s_pXC2_366		},
  { sizeof ( s_pXC2_367		) - 1, s_pXC2_367		},
  { sizeof ( s_pXC2_368		) - 1, s_pXC2_368		},
  { sizeof ( s_pXC2_369		) - 1, s_pXC2_369		},
  { sizeof ( s_pXC2_370		) - 1, s_pXC2_370		},
  { sizeof ( s_pXC2_371		) - 1, s_pXC2_371		},
  { sizeof ( s_pXC2_372		) - 1, s_pXC2_372		},
  { sizeof ( s_pXC2_373		) - 1, s_pXC2_373		},
  { sizeof ( s_pXC2_374		) - 1, s_pXC2_374		},
  { sizeof ( s_pXC2_375		) - 1, s_pXC2_375		},
  { sizeof ( s_pXC2_376		) - 1, s_pXC2_376		},
  { sizeof ( s_pXC2_377		) - 1, s_pXC2_377		},
  { sizeof ( s_pXC2_378		) - 1, s_pXC2_378		},
  { sizeof ( s_pXC2_379		) - 1, s_pXC2_379		},
  { sizeof ( s_pXC2_380		) - 1, s_pXC2_380		},
  { sizeof ( s_pXC2_381		) - 1, s_pXC2_381		},
  { sizeof ( s_pXC2_382		) - 1, s_pXC2_382		},
  { sizeof ( s_pXC2_383		) - 1, s_pXC2_383		},
  { sizeof ( s_pXC2_384		) - 1, s_pXC2_384		},
  { sizeof ( s_pXC2_385		) - 1, s_pXC2_385		},
  { sizeof ( s_pXC2_386		) - 1, s_pXC2_386		},
  { sizeof ( s_pXC2_387		) - 1, s_pXC2_387		},
  { sizeof ( s_pXC2_388		) - 1, s_pXC2_388		},
  { sizeof ( s_pXC2_389		) - 1, s_pXC2_389		},
  { sizeof ( s_pXC2_390		) - 1, s_pXC2_390		},
  { sizeof ( s_pXC2_391		) - 1, s_pXC2_391		},
  { sizeof ( s_pXC2_392		) - 1, s_pXC2_392		},
  { sizeof ( s_pXC2_393		) - 1, s_pXC2_393		},
  { sizeof ( s_pXC2_394		) - 1, s_pXC2_394		},
  { sizeof ( s_pXC2_395		) - 1, s_pXC2_395		},
  { sizeof ( s_pXC2_396		) - 1, s_pXC2_396		},
  { sizeof ( s_pXC2_397		) - 1, s_pXC2_397		},
  { sizeof ( s_pXC2_398		) - 1, s_pXC2_398		},
  { sizeof ( s_pXC2_399		) - 1, s_pXC2_399		},
  { sizeof ( s_pXC2_400		) - 1, s_pXC2_400		},
  { sizeof ( s_pXC2_401		) - 1, s_pXC2_401		},
  { sizeof ( s_pXC2_402		) - 1, s_pXC2_402		},
  { sizeof ( s_pXC2_403		) - 1, s_pXC2_403		},
  { sizeof ( s_pXC2_404		) - 1, s_pXC2_404		},
  { sizeof ( s_pXC2_405		) - 1, s_pXC2_405		},
  { sizeof ( s_pXC2_406		) - 1, s_pXC2_406		},
  { sizeof ( s_pXC2_407		) - 1, s_pXC2_407		},
  { sizeof ( s_pXC2_408		) - 1, s_pXC2_408		},
  { sizeof ( s_pXC2_409		) - 1, s_pXC2_409		},
  { sizeof ( s_pXC2_410		) - 1, s_pXC2_410		},
  { sizeof ( s_pXC2_411		) - 1, s_pXC2_411		},
  { sizeof ( s_pXC2_412		) - 1, s_pXC2_412		},
  { sizeof ( s_pXC2_413		) - 1, s_pXC2_413		},
  { sizeof ( s_pXC2_414		) - 1, s_pXC2_414		},
  { sizeof ( s_pXC2_415		) - 1, s_pXC2_415		},
  { sizeof ( s_pXC2_416		) - 1, s_pXC2_416		},
  { sizeof ( s_pXC2_417		) - 1, s_pXC2_417		},
  { sizeof ( s_pXC2_418		) - 1, s_pXC2_418		},
  { sizeof ( s_pXC2_419		) - 1, s_pXC2_419		},
  { sizeof ( s_pXC2_420		) - 1, s_pXC2_420		},
  { sizeof ( s_pXC2_421		) - 1, s_pXC2_421		},
  { sizeof ( s_pXC2_422		) - 1, s_pXC2_422		},
  { sizeof ( s_pXC2_423		) - 1, s_pXC2_423		},
  { sizeof ( s_pXC2_424		) - 1, s_pXC2_424		},
  { sizeof ( s_pXC2_425		) - 1, s_pXC2_425		},
  { sizeof ( s_pXC2_426		) - 1, s_pXC2_426		},
  { sizeof ( s_pXC2_427		) - 1, s_pXC2_427		},
  { sizeof ( s_pXC2_428		) - 1, s_pXC2_428		},
  { sizeof ( s_pXC2_429		) - 1, s_pXC2_429		},
  { sizeof ( s_pXC2_430		) - 1, s_pXC2_430		},
  { sizeof ( s_pXC2_431		) - 1, s_pXC2_431		},
  { sizeof ( s_pXC2_432		) - 1, s_pXC2_432		},
  { sizeof ( s_pXC2_433		) - 1, s_pXC2_433		},
  { sizeof ( s_pXC2_434		) - 1, s_pXC2_434		},
  { sizeof ( s_pXC2_435		) - 1, s_pXC2_435		},
  { sizeof ( s_pXC2_436		) - 1, s_pXC2_436		},
  { sizeof ( s_pXC2_437		) - 1, s_pXC2_437		},
  { sizeof ( s_pXC2_438		) - 1, s_pXC2_438		},
  { sizeof ( s_pXC2_439		) - 1, s_pXC2_439		},
  { sizeof ( s_pXC2_440		) - 1, s_pXC2_440		},
  { sizeof ( s_pXC2_441		) - 1, s_pXC2_441		},
  { sizeof ( s_pXC2_442		) - 1, s_pXC2_442		},
  { sizeof ( s_pXC2_443		) - 1, s_pXC2_443		},
  { sizeof ( s_pXC2_444		) - 1, s_pXC2_444		},
  { sizeof ( s_pXC2_445		) - 1, s_pXC2_445		},
  { sizeof ( s_pXC2_446		) - 1, s_pXC2_446		},
  { sizeof ( s_pXC2_447		) - 1, s_pXC2_447		},
  { sizeof ( s_pXC2_448		) - 1, s_pXC2_448		},
  { sizeof ( s_pXC2_449		) - 1, s_pXC2_449		},
  { sizeof ( s_pXC2_450		) - 1, s_pXC2_450		},
  { sizeof ( s_pXC2_451		) - 1, s_pXC2_451		},
  { sizeof ( s_pXC2_452		) - 1, s_pXC2_452		},
  { sizeof ( s_pXC2_453		) - 1, s_pXC2_453		},
  { sizeof ( s_pXC2_454		) - 1, s_pXC2_454		},
  { sizeof ( s_pXC2_455		) - 1, s_pXC2_455		},

  { sizeof ( s_pXC9_456		) - 1, s_pXC9_456		},
  { sizeof ( s_pXC9_457		) - 1, s_pXC9_457		},
  { sizeof ( s_pXC9_458		) - 1, s_pXC9_458		},
  { sizeof ( s_pXC9_459		) - 1, s_pXC9_459		},
  { sizeof ( s_pXC9_460		) - 1, s_pXC9_460		},
  { sizeof ( s_pXC9_461		) - 1, s_pXC9_461		},
  { sizeof ( s_pXC9_462		) - 1, s_pXC9_462		},
  { sizeof ( s_pXC9_463		) - 1, s_pXC9_463		},
  { sizeof ( s_pXC9_464		) - 1, s_pXC9_464		},
  { sizeof ( s_pXC9_465		) - 1, s_pXC9_465		},

  { sizeof ( s_pCopy13		) - 1, s_pCopy13		}, //466
  { sizeof ( s_pCopy14		) - 1, s_pCopy14		},
  { sizeof ( s_pCopy15		) - 1, s_pCopy15		},
  { sizeof ( s_pCopy16		) - 1, s_pCopy16		},
  { sizeof ( s_pCopy17		) - 1, s_pCopy17		}, //470
  { sizeof ( s_pCopy18		) - 1, s_pCopy18		},
  { sizeof ( s_pCopy19		) - 1, s_pCopy19		},

// Game Settings screen
  { sizeof ( s_pGMDISC		) - 1, s_pGMDISC		}, //473
  { sizeof ( s_pGMINT		) - 1, s_pGMINT			},
  { sizeof ( s_pGMEXT		) - 1, s_pGMEXT			},

  { sizeof ( s_pGMDB		) - 1, s_pGMDB			},
  { sizeof ( s_pGMBDM		) - 1, s_pGMBDM			},
  { sizeof ( s_pGMEXTGD		) - 1, s_pGMEXTGD		},
  { sizeof ( s_pGMFAV		) - 1, s_pGMFAV			},
  { sizeof ( s_pGMUSBP		) - 1, s_pGMUSBP		}, //480

  { sizeof ( s_pSIVER		) - 1, s_pSIVER			}, //481
  { sizeof ( s_pSIIP		) - 1, s_pSIIP			},
  { sizeof ( s_pSINA		) - 1, s_pSINA			},
  { sizeof ( s_pSIHDD		) - 1, s_pSIHDD			},
  { sizeof ( s_pSIMEM		) - 1, s_pSIMEM			},

  { sizeof ( s_pLGLOAD		) - 1, s_pLGLOAD		}, //486
  { sizeof ( s_pLGEXIT		) - 1, s_pLGEXIT		},
  { sizeof ( s_pLGNEXT		) - 1, s_pLGNEXT		},
  { sizeof ( s_pLGPREV		) - 1, s_pLGPREV		},
  { sizeof ( s_pLGGS		) - 1, s_pLGGS			},
  { sizeof ( s_pLGSS		) - 1, s_pLGSS			}, //491

  { sizeof ( s_SIDESW		) - 1, s_SIDESW			}, //492
  { sizeof ( s_SIDERW		) - 1, s_SIDERW			}, //493

  { sizeof ( s_pXC2_494		) - 1, s_pXC2_494		},
  { sizeof ( s_pXC2_495		) - 1, s_pXC2_495		},

  { sizeof ( s_SIDE_ADV		) - 1, s_SIDE_ADV		}, //496
  { sizeof ( s_SIDE_STD		) - 1, s_SIDE_STD		},

  { sizeof ( s_SIDE_PAUSE	) - 1, s_SIDE_PAUSE		}, //498
  { sizeof ( s_SIDE_STOP	) - 1, s_SIDE_STOP		},
  { sizeof ( s_SIDE_PAUSE	) - 1, s_SIDE_INFO		}, //500
  { sizeof ( s_SIDE_STOP	) - 1, s_SIDE_BROW		},

  { sizeof ( s_BR_NOV		) - 1, s_BR_NOV			}, //502
  { sizeof ( s_BR_NOP		) - 1, s_BR_NOP			},
  { sizeof ( s_BR_NOM		) - 1, s_BR_NOM			},
  { sizeof ( s_BR_NOE		) - 1, s_BR_NOE			},

  { sizeof ( s_BR_HDD		) - 1, s_BR_HDD			},
  { sizeof ( s_BR_USB		) - 1, s_BR_USB			}, //507

  { sizeof ( s_pXC2_508		) - 1, s_pXC2_508		},
  { sizeof ( s_pXC2_509		) - 1, s_pXC2_509		},
  { sizeof ( s_pXC2_510		) - 1, s_pXC2_510		},
  { sizeof ( s_pXC2_511		) - 1, s_pXC2_511		}, //511

  { sizeof ( s_pXC2_512		) - 1, s_pXC2_512		},
  { sizeof ( s_pXC2_513		) - 1, s_pXC2_513		},

  { sizeof ( s_pXC2_514		) - 1, s_pXC2_514		}, //514
  { sizeof ( s_pXC2_515		) - 1, s_pXC2_515		},
  { sizeof ( s_pXC2_516		) - 1, s_pXC2_516		},
  { sizeof ( s_pXC2_517		) - 1, s_pXC2_517		}, //517

  { sizeof ( s_pXC1_RSPS3	) - 1, s_pXC1_RSPS3		},
  { sizeof ( s_pXC1_RSPS32	) - 1, s_pXC1_RSPS32	},
  { sizeof ( s_pXC1_SHUT	) - 1, s_pXC1_SHUT		},
  { sizeof ( s_pXC1_SHUT2	) - 1, s_pXC1_SHUT2		}, //521

  { sizeof ( s_pXC2_522		) - 1, s_pXC2_522		},
  { sizeof ( s_pXC2_523		) - 1, s_pXC2_523		}, //523

  { sizeof ( s_pXC2_525		) - 1, s_pXC2_524		},
  { sizeof ( s_pXC2_525		) - 1, s_pXC2_525		},

  { sizeof ( s_pISO			) - 1, s_pISO			},  //526
  { sizeof ( s_pISO1		) - 1, s_pISO1			},
  { sizeof ( s_pISO2		) - 1, s_pISO2			},
  { sizeof ( s_pISO3		) - 1, s_pISO3			},
  { sizeof ( s_pISO4		) - 1, s_pISO4			},
  { sizeof ( s_pISO5		) - 1, s_pISO5			},

  { sizeof ( s_pXC2_532		) - 1, s_pXC2_532		},
  { sizeof ( s_pXC2_533		) - 1, s_pXC2_533		},
  { sizeof ( s_pXC2_534		) - 1, s_pXC2_534		},
  { sizeof ( s_pXC2_535		) - 1, s_pXC2_535		},

  { sizeof ( s_pSFD			) - 1, s_pSFD			}, //536
  { sizeof ( s_pNotAllow	) - 1, s_pNotAllow		},
  { sizeof ( s_pEnableDA	) - 1, s_pEnableDA		}, //538

  { sizeof ( s_pUMDDISC		) - 1, s_pUMDDISC		}, //539
  { sizeof ( s_pRegionBD	) - 1, s_pRegionBD		},
  { sizeof ( s_pRegionBD1	) - 1, s_pRegionBD1		},
  { sizeof ( s_pRegionDVD	) - 1, s_pRegionDVD		},
  { sizeof ( s_pRegionDVD1	) - 1, s_pRegionDVD1	},
  { sizeof ( s_pPROMETH		) - 1, s_pPROMETH		},
  { sizeof ( s_pPSPLAUN		) - 1, s_pPSPLAUN		},
  { sizeof ( s_pPS2USB		) - 1, s_pPS2USB		}, //546
  { sizeof ( s_pENCRYPT		) - 1, s_pENCRYPT		},
  { sizeof ( s_pERRCUE		) - 1, s_pERRCUE		},
  { sizeof ( s_pEJECT		) - 1, s_pEJECT			},
  { sizeof ( s_pINSERT		) - 1, s_pINSERT		},
  { sizeof ( s_USBFW		) - 1, s_USBFW			}, //551
  { sizeof ( s_pLEDS		) - 1, s_pLEDS			},
  { sizeof ( s_pLEDS1		) - 1, s_pLEDS1			}, //553
  { sizeof ( s_pLEDS2		) - 1, s_pLEDS2			},
  { sizeof ( s_pLEDS3		) - 1, s_pLEDS3			}, //555
  { sizeof ( s_pISONAMES	) - 1, s_pISONAMES		},
  { sizeof ( s_pISONAMES1	) - 1, s_pISONAMES1		}, //557
  { sizeof ( s_pNOTPS3		) - 1, s_pNOTPS3		},
  { sizeof ( s_pNEWMM		) - 1, s_pNEWMM			},
  { sizeof ( s_pXC2_STFONT	) - 1, s_pXC2_STFONT	},
  { sizeof ( s_pXC2_STFONT1 ) - 1, s_pXC2_STFONT1	},

  { sizeof ( s_pISO_EXTR	) - 1, s_pISO_EXTR		}, //562
  { sizeof ( s_pPSPLAUN2	) - 1, s_pPSPLAUN2		}, //563

  { sizeof ( s_pSPOOF		) - 1, s_pSPOOF			}, //564
  { sizeof ( s_pSPOOF1		) - 1, s_pSPOOF1		}, //565

  { sizeof ( s_pREBOOT0		) - 1, s_pREBOOT0		}, //566
  { sizeof ( s_pREBOOT1		) - 1, s_pREBOOT1		}, //567

  { sizeof ( s_pCOBRA		) - 1, s_pCOBRA			}, //568

  { sizeof ( s_pNETHOST		) - 1, s_pNETHOST		}, //569
  { sizeof ( s_pNETHOST1	) - 1, s_pNETHOST1		}, //570
  { sizeof ( s_pRESETINI	) - 1, s_pRESETINI		}, //571

  { sizeof ( s_pXC2_572		) - 1, s_pXC2_572		},
  { sizeof ( s_pXC2_573		) - 1, s_pXC2_573		},

  { sizeof ( s_pXC2_574		) - 1, s_pXC2_574		},
  { sizeof ( s_pXC2_575		) - 1, s_pXC2_575		}, //575

 { sizeof ( s_pCMCut		) - 1, s_pCMCut			},
 { sizeof ( s_pCMPaste		) - 1, s_pCMPaste		}, //577
 { sizeof ( s_pCMPasteISO	) - 1, s_pCMPasteISO	}, //578
 { sizeof ( s_pCMPasteLNK	) - 1, s_pCMPasteLNK	}, //579
 { sizeof ( s_pShowDesktop	) - 1, s_pShowDesktop	}, //580
 { sizeof ( s_pResetDesktop	) - 1, s_pResetDesktop	}, //581
 { sizeof ( s_pP3TTHM		) - 1, s_pP3TTHM		}, //582
 { sizeof ( s_p3DPlay		) - 1, s_p3DPlay		}, //583
 { sizeof ( s_pOpenTarget	) - 1, s_pOpenTarget	}, //584
 { sizeof ( s_pCMUnzip		) - 1, s_pCMUnzip		}, //585
 { sizeof ( s_pInstallZip	) - 1, s_pInstallZip	}, //586
 { sizeof ( s_pShowTemp		) - 1, s_pShowTemp		}, //587
 { sizeof ( s_pShowTemp1	) - 1, s_pShowTemp1		}, //588

};


static MMString s_MMStringUDF[ sizeof ( s_MMStringDef ) / sizeof ( s_MMStringDef[ 0 ] ) ]; //UDF - user defined file with texts
       MMString g_MMString   [ sizeof ( s_MMStringDef ) / sizeof ( s_MMStringDef[ 0 ] ) ]; //holds default GUI texts


int MM_LocaleInit ( char *lang_file )
{
	long lSize=0;
	unsigned int   lIdx = 0;
	FILE *lFD = fopen(lang_file, "rb");

	if ( lFD != NULL )
	{
		fseek ( lFD, 0, SEEK_END );
		lSize = ftell(lFD);

		if ( lSize > 0 )
		{
			unsigned char* lpEnd;
			unsigned char* lpPtr;
			unsigned char* lpBuff = lpPtr = ( unsigned char* )malloc ( lSize + 1 );

			lpEnd = lpBuff + lSize;

			fseek( lFD, 3, SEEK_SET);
			fread( (unsigned char*) lpBuff, lSize, 1, lFD);
			for(int m=0; m<lSize; m++) {
				if(lpBuff[m]=='\n') lpBuff[m]=' ';
				if(lpBuff[m]=='|') lpBuff[m]='\n';
				}

			while ( 1 )
			{
				while ( lpPtr != lpEnd && *lpPtr != '\r' ) ++lpPtr;

				*lpPtr = '\x00';
				s_MMStringUDF[ lIdx ].m_pStr = lpBuff;
				s_MMStringUDF[ lIdx ].m_Len  = lpPtr - lpBuff;

				if (  !s_MMStringUDF[ lIdx++ ].m_Len ||
				lpPtr++ == lpEnd               ||
				lIdx    == sizeof ( s_MMStringUDF ) / sizeof ( s_MMStringUDF[ 0 ] )
				) break;

				if ( *lpPtr  == '\r'  ) ++lpPtr;

				lpBuff = lpPtr;
			}
		}
		fclose ( lFD );
	}
	return lIdx;
}


void MM_LocaleSet ( bool mm_language ) {

 MMString* lpStr;

	if (  mm_language )
		lpStr = s_MMStringUDF;	//user defined translation file
	else
		lpStr = s_MMStringDef;	//default English

	memcpy (  g_MMString, lpStr, sizeof ( g_MMString )  );
}
