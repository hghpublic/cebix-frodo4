// translate_key.cpp

#include <SDL2/SDL.h>

#include <map>
#include <string>

// https://wiki.libsdl.org/SDL2/SDL_ScancodeAndKeycode
// https://wiki.libsdl.org/SDL2/SDLKeycodeLookup
// https://www.c64-wiki.de/wiki/Tastatur

static const std::map<SDL_Scancode, std::string> scancodeToString = {
    {SDL_SCANCODE_A, "SDL_SCANCODE_A"},
    {SDL_SCANCODE_B, "SDL_SCANCODE_B"},
    {SDL_SCANCODE_C, "SDL_SCANCODE_C"},
    {SDL_SCANCODE_D, "SDL_SCANCODE_D"},
    {SDL_SCANCODE_E, "SDL_SCANCODE_E"},
    {SDL_SCANCODE_F, "SDL_SCANCODE_F"},
    {SDL_SCANCODE_G, "SDL_SCANCODE_G"},
    {SDL_SCANCODE_H, "SDL_SCANCODE_H"},
    {SDL_SCANCODE_I, "SDL_SCANCODE_I"},
    {SDL_SCANCODE_J, "SDL_SCANCODE_J"},
    {SDL_SCANCODE_K, "SDL_SCANCODE_K"},
    {SDL_SCANCODE_L, "SDL_SCANCODE_L"},
    {SDL_SCANCODE_M, "SDL_SCANCODE_M"},
    {SDL_SCANCODE_N, "SDL_SCANCODE_N"},
    {SDL_SCANCODE_O, "SDL_SCANCODE_O"},
    {SDL_SCANCODE_P, "SDL_SCANCODE_P"},
    {SDL_SCANCODE_Q, "SDL_SCANCODE_Q"},
    {SDL_SCANCODE_R, "SDL_SCANCODE_R"},
    {SDL_SCANCODE_S, "SDL_SCANCODE_S"},
    {SDL_SCANCODE_T, "SDL_SCANCODE_T"},
    {SDL_SCANCODE_U, "SDL_SCANCODE_U"},
    {SDL_SCANCODE_V, "SDL_SCANCODE_V"},
    {SDL_SCANCODE_W, "SDL_SCANCODE_W"},
    {SDL_SCANCODE_X, "SDL_SCANCODE_X"},
    {SDL_SCANCODE_Y, "SDL_SCANCODE_Y"},
    {SDL_SCANCODE_Z, "SDL_SCANCODE_Z"},
    {SDL_SCANCODE_0, "SDL_SCANCODE_0"},
    {SDL_SCANCODE_1, "SDL_SCANCODE_1"},
    {SDL_SCANCODE_2, "SDL_SCANCODE_2"},
    {SDL_SCANCODE_3, "SDL_SCANCODE_3"},
    {SDL_SCANCODE_4, "SDL_SCANCODE_4"},
    {SDL_SCANCODE_5, "SDL_SCANCODE_5"},
    {SDL_SCANCODE_6, "SDL_SCANCODE_6"},
    {SDL_SCANCODE_7, "SDL_SCANCODE_7"},
    {SDL_SCANCODE_8, "SDL_SCANCODE_8"},
    {SDL_SCANCODE_9, "SDL_SCANCODE_9"},
    {SDL_SCANCODE_SPACE, "SDL_SCANCODE_SPACE"},
    {SDL_SCANCODE_GRAVE, "SDL_SCANCODE_GRAVE"},
    {SDL_SCANCODE_BACKSLASH, "SDL_SCANCODE_BACKSLASH"},
    {SDL_SCANCODE_COMMA, "SDL_SCANCODE_COMMA"},
    {SDL_SCANCODE_PERIOD, "SDL_SCANCODE_PERIOD"},
    {SDL_SCANCODE_MINUS, "SDL_SCANCODE_MINUS"},
    {SDL_SCANCODE_EQUALS, "SDL_SCANCODE_EQUALS"},
    {SDL_SCANCODE_LEFTBRACKET, "SDL_SCANCODE_LEFTBRACKET"},
    {SDL_SCANCODE_RIGHTBRACKET, "SDL_SCANCODE_RIGHTBRACKET"},
    {SDL_SCANCODE_SEMICOLON, "SDL_SCANCODE_SEMICOLON"},
    {SDL_SCANCODE_APOSTROPHE, "SDL_SCANCODE_APOSTROPHE"},
    {SDL_SCANCODE_SLASH, "SDL_SCANCODE_SLASH"},
    {SDL_SCANCODE_ESCAPE, "SDL_SCANCODE_ESCAPE"},
    {SDL_SCANCODE_RETURN, "SDL_SCANCODE_RETURN"},
    {SDL_SCANCODE_DELETE, "SDL_SCANCODE_DELETE"},
    {SDL_SCANCODE_INSERT, "SDL_SCANCODE_INSERT"},
    {SDL_SCANCODE_HOME, "SDL_SCANCODE_HOME"},
    {SDL_SCANCODE_END, "SDL_SCANCODE_END"},
    {SDL_SCANCODE_PAGEUP, "SDL_SCANCODE_PAGEUP"},
    {SDL_SCANCODE_PAGEDOWN, "SDL_SCANCODE_PAGEDOWN"},
    {SDL_SCANCODE_RCTRL, "SDL_SCANCODE_RCTRL"},
    {SDL_SCANCODE_LSHIFT, "SDL_SCANCODE_LSHIFT"},
    {SDL_SCANCODE_RSHIFT, "SDL_SCANCODE_RSHIFT"},
    {SDL_SCANCODE_LALT, "SDL_SCANCODE_LALT"},
    {SDL_SCANCODE_RALT, "SDL_SCANCODE_RALT"},
    {SDL_SCANCODE_UP, "SDL_SCANCODE_UP"},
    {SDL_SCANCODE_DOWN, "SDL_SCANCODE_DOWN"},
    {SDL_SCANCODE_LEFT, "SDL_SCANCODE_LEFT"},
    {SDL_SCANCODE_RIGHT, "SDL_SCANCODE_RIGHT"},
    {SDL_SCANCODE_F1, "SDL_SCANCODE_F1"},
    {SDL_SCANCODE_F2, "SDL_SCANCODE_F2"},
    {SDL_SCANCODE_F3, "SDL_SCANCODE_F3"},
    {SDL_SCANCODE_F4, "SDL_SCANCODE_F4"},
    {SDL_SCANCODE_F5, "SDL_SCANCODE_F5"},
    {SDL_SCANCODE_F6, "SDL_SCANCODE_F6"},
    {SDL_SCANCODE_F7, "SDL_SCANCODE_F7"},
    {SDL_SCANCODE_F8, "SDL_SCANCODE_F8"}

};

#define MATRIX(a,b) (((a) << 3) | (b))

static void translate_key(SDL_Keycode key, bool key_up, uint8_t *key_matrix, uint8_t *rev_matrix, uint8_t *joystick)
{
	int c64_key = -1;
	switch (key) {
		case SDLK_a: c64_key = MATRIX(1,2); break;
		case SDLK_b: c64_key = MATRIX(3,4); break;
		case SDLK_c: c64_key = MATRIX(2,4); break;
		case SDLK_d: c64_key = MATRIX(2,2); break;
		case SDLK_e: c64_key = MATRIX(1,6); break;
		case SDLK_f: c64_key = MATRIX(2,5); break;
		case SDLK_g: c64_key = MATRIX(3,2); break;
		case SDLK_h: c64_key = MATRIX(3,5); break;
		case SDLK_i: c64_key = MATRIX(4,1); break;
		case SDLK_j: c64_key = MATRIX(4,2); break;
		case SDLK_k: c64_key = MATRIX(4,5); break;
		case SDLK_l: c64_key = MATRIX(5,2); break;
		case SDLK_m: c64_key = MATRIX(4,4); break;
		case SDLK_n: c64_key = MATRIX(4,7); break;
		case SDLK_o: c64_key = MATRIX(4,6); break;
		case SDLK_p: c64_key = MATRIX(5,1); break;
		case SDLK_q: c64_key = MATRIX(7,6); break;
		case SDLK_r: c64_key = MATRIX(2,1); break;
		case SDLK_s: c64_key = MATRIX(1,5); break;
		case SDLK_t: c64_key = MATRIX(2,6); break;
		case SDLK_u: c64_key = MATRIX(3,6); break;
		case SDLK_v: c64_key = MATRIX(3,7); break;
		case SDLK_w: c64_key = MATRIX(1,1); break;
		case SDLK_x: c64_key = MATRIX(2,7); break;
		case SDLK_y: c64_key = MATRIX(3,1); break;
		case SDLK_z: c64_key = MATRIX(1,4); break;

		case SDLK_0: c64_key = MATRIX(4,3); break;
		case SDLK_1: c64_key = MATRIX(7,0); break;
		case SDLK_2: c64_key = MATRIX(7,3); break;
		case SDLK_3: c64_key = MATRIX(1,0); break;
		case SDLK_4: c64_key = MATRIX(1,3); break;
		case SDLK_5: c64_key = MATRIX(2,0); break;
		case SDLK_6: c64_key = MATRIX(2,3); break;
		case SDLK_7: c64_key = MATRIX(3,0); break;
		case SDLK_8: c64_key = MATRIX(3,3); break;
		case SDLK_9: c64_key = MATRIX(4,0); break;

		case SDLK_SPACE: c64_key = MATRIX(7,4); break;
		case SDLK_BACKQUOTE: c64_key = MATRIX(7,1); break;		// ←
		case SDLK_BACKSLASH: c64_key = MATRIX(6,6); break;		// ↑
		case SDLK_COMMA: c64_key = MATRIX(5,7); break;
		case SDLK_PERIOD: c64_key = MATRIX(5,4); break;
		case SDLK_MINUS: c64_key = MATRIX(5,0); break;			// +
		case SDLK_EQUALS: c64_key = MATRIX(5,3); break;			// -
		case SDLK_LEFTBRACKET: c64_key = MATRIX(5,6); break;	// @
		case SDLK_RIGHTBRACKET: c64_key = MATRIX(6,1); break;	// *
		case SDLK_SEMICOLON: c64_key = MATRIX(5,5); break;		// :
		case SDLK_QUOTE: c64_key = MATRIX(6,2); break;		    // ;
		case SDLK_SLASH: c64_key = MATRIX(6,7); break;
		case SDLK_ESCAPE: c64_key = MATRIX(7,7); break;			// RUN/STOP
		case SDLK_RETURN: c64_key = MATRIX(0,1); break;
		case SDLK_BACKSPACE:
		case SDLK_DELETE: c64_key = MATRIX(0,0); break;			// INS/DEL
		case SDLK_INSERT: c64_key = MATRIX(0,0) | 0x80; break;
		case SDLK_HOME: c64_key = MATRIX(6,3); break;			// CLR/HOME
		case SDLK_END: c64_key = MATRIX(6,0); break;			// £
		case SDLK_PAGEUP: c64_key = MATRIX(6,6); break;			// ↑
		case SDLK_PAGEDOWN: c64_key = MATRIX(6,5); break;		// =
		case SDLK_LCTRL:
		case SDLK_TAB:
		case SDLK_RCTRL: c64_key = MATRIX(7,2); break;
		case SDLK_LSHIFT: c64_key = MATRIX(1,7); break;
		case SDLK_RSHIFT: c64_key = MATRIX(6,4); break;
		case SDLK_LALT: c64_key = MATRIX(7,5); break;			// C=
		case SDLK_RALT: c64_key = MATRIX(7,5); break;			// C=

		case SDL_SCANCODE_UP: c64_key = MATRIX(0,7)| 0x80; break;
		case SDL_SCANCODE_DOWN: c64_key = MATRIX(0,7); break;
		case SDL_SCANCODE_LEFT: c64_key = MATRIX(0,2) | 0x80; break;
		case SDL_SCANCODE_RIGHT: c64_key = MATRIX(0,2); break;

		case SDLK_F1: c64_key = MATRIX(0,4); break;
		case SDLK_F2: c64_key = MATRIX(0,4) | 0x80; break;
		case SDLK_F3: c64_key = MATRIX(0,5); break;
		case SDLK_F4: c64_key = MATRIX(0,5) | 0x80; break;
		case SDLK_F5: c64_key = MATRIX(0,6); break;
		case SDLK_F6: c64_key = MATRIX(0,6) | 0x80; break;
		case SDLK_F7: c64_key = MATRIX(0,3); break;
		case SDLK_F8: c64_key = MATRIX(0,3) | 0x80; break;

		case SDLK_KP_0:
		case SDLK_KP_5: c64_key = 0x10 | 0x40; break;
		case SDLK_KP_1: c64_key = 0x06 | 0x40; break;
		case SDLK_KP_2: c64_key = 0x02 | 0x40; break;
		case SDLK_KP_3: c64_key = 0x0a | 0x40; break;
		case SDLK_KP_4: c64_key = 0x04 | 0x40; break;
		case SDLK_KP_6: c64_key = 0x08 | 0x40; break;
		case SDLK_KP_7: c64_key = 0x05 | 0x40; break;
		case SDLK_KP_8: c64_key = 0x01 | 0x40; break;
		case SDLK_KP_9: c64_key = 0x09 | 0x40; break;

		default: break;
	}

	if (c64_key < 0)
		return;

	// Handle joystick emulation
	if (c64_key & 0x40) {
		c64_key &= 0x1f;
		if (key_up) {
			*joystick |= c64_key;
		} else {
			*joystick &= ~c64_key;
		}
		return;
	}

	// Handle other keys
	bool shifted = c64_key & 0x80;
	int c64_byte = (c64_key >> 3) & 7;
	int c64_bit = c64_key & 7;
	if (key_up) {
		if (shifted) {
			key_matrix[6] |= 0x10;
			rev_matrix[4] |= 0x40;
		}
		key_matrix[c64_byte] |= (1 << c64_bit);
		rev_matrix[c64_bit] |= (1 << c64_byte);
	} else {
		if (shifted) {
			key_matrix[6] &= 0xef;
			rev_matrix[4] &= 0xbf;
		}
		key_matrix[c64_byte] &= ~(1 << c64_bit);
		rev_matrix[c64_bit] &= ~(1 << c64_byte);
	}
}
