/**
 * This file has a different license to the rest of the uGFX system.
 * You can copy, modify and distribute this file as you see fit.
 * You do not need to publish your source modifications to this file.
 * The only thing you are not permitted to do is to relicense it
 * under a different license.
 */

/**
 * Copy this file into your project directory and rename it as gfxconf.h
 * Edit your copy to turn on the uGFX features you want to use.
 *
 * Please use spaces instead of tabs in this file.
 */

#ifndef _GFXCONF_H
#define _GFXCONF_H

/* The operating system to use. One of these must be defined - preferably in your Makefile */
//#define GFX_USE_OS_CHIBIOS				TRUE
//#define GFX_USE_OS_WIN32					TRUE
//#define GFX_USE_OS_LINUX					TRUE
//#define GFX_USE_OS_OSX					TRUE

///////////////////////////////////////////////////////////////////////////
// GDISP                                                                 //
///////////////////////////////////////////////////////////////////////////
#define GFX_USE_GDISP						TRUE

#define GDISP_NEED_CIRCLE					TRUE
#define GDISP_NEED_TEXT						TRUE
#define GDISP_INCLUDE_FONT_DEJAVUSANS20_AA	TRUE

#endif /* _GFXCONF_H */
