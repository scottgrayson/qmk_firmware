#pragma once

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PLANCK_SOUND)
// #define STARTUP_SONG SONG(NO_SOUND)

#    define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }
#endif

// https://docs.qmk.fm/#/tap_hold

#undef RETRO_TAPPING
#undef TAPPING_TERM
#define TAPPING_TERM 200
#undef PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
