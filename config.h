static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
static const unsigned int alpha = 0xF2;     /* Amount of opacity. 0xff is opaque (0xE6 - 90%, 0xF2 - 95%)             */
static int horizpadbar = -16;                 /* horizontal padding */
static int vertpadbar = 1;                  /* vertical padding */
static int draw_input = 1;                  /* -noi option; if 0, the input will not be drawn by default */
static int centered = 1;                    /* -c option; centers dmenu on screen */
static int min_width = 500;                    /* minimum width when centered */
static const float menu_height_ratio = 2.0f;  /* This is the ratio used in the original calculation */
/* -fn option overrides fonts[0]; default X11 font or font set */
static char *fonts[] = {
	"JetBrainsMonoNL Nerd Font:size=12"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */

/* default colors used if xrdb is not loaded */
static char normbgcolor[]           = "#282828";
static char normfgcolor[]           = "#ebdbb2";

static char selfgcolor[]            = "#d65d0e";
static char selbordercolor[]        = "#d65d0e";
static char selbgcolor[]            = "#d65d0e";

static char hlfgcolor[]       = "#fabd2f";
static char hlbgcolor[]       = "#d65d0e";

static char outfgcolor[]      = "#d65d0e";
static char outbgcolor[]      = "#d65d0e";

static char *colors[SchemeLast][2] = {
	/* fg            bg */
	[SchemeNorm]          = { normfgcolor, normbgcolor },
	[SchemeSel]           = { selfgcolor,  selbgcolor },
	[SchemeNormHighlight] = { hlfgcolor,    normbgcolor },
	[SchemeSelHighlight]  = { hlfgcolor,    hlbgcolor },
	[SchemeOut]           = { outfgcolor,   outbgcolor },
	[SchemeCursor]        = { "#222222", "#bbbbbb"},
	[SchemeOutHighlight]  = { hlfgcolor,    outbgcolor },
	[SchemeBorder]        = { selbordercolor, NULL },
};

static const unsigned int alphas[SchemeLast][2] = {
	[SchemeNorm] = { OPAQUE, alpha },
	[SchemeSel] = { OPAQUE, alpha },
	[SchemeOut] = { OPAQUE, alpha },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/*
 * -vi option; if nonzero, vi mode is always enabled and can be
 * accessed with the global_esc keysym + mod mask
 */
static unsigned int vi_mode = 1;
static unsigned int start_mode = 0;			/* mode to use when -vi is passed. 0 = insert mode, 1 = normal mode */
static Key global_esc = { XK_n, Mod1Mask };	/* escape key when vi mode is not enabled explicitly */
static Key quit_keys[] = {
	/* keysym	modifier */
	{ XK_q,		0 }
};

/* Size of the window border */
static unsigned int border_width = 1;
