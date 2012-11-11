/* Generated by re2c 0.13.5 on Sat Nov 10 23:11:03 2012 */
// 1 "scanner.re"

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"

#include "scanner.h"

#define KKCTYPE char
#define KKCURSOR (s->start)
#define KKLIMIT (s->end)
#define KKMARKER q

int phvolt_get_token(phvolt_scanner_state *s, phvolt_scanner_token *token) {

	char next, *q = KKCURSOR, *start = KKCURSOR;
	int status = PHVOLT_SCANNER_RETCODE_IMPOSSIBLE;

	while (PHVOLT_SCANNER_RETCODE_IMPOSSIBLE == status) {

		if (s->mode == PHVOLT_MODE_RAW || s->mode == PHVOLT_MODE_COMMENT) {

			if (*KKCURSOR == '\n') {
				s->active_line++;
			}

			next = *(KKCURSOR+1);
			if (*KKCURSOR == '\0' || (*KKCURSOR == '{' && (next == '%' || next == '{' || next == '#'))) {

				if (next != '#') {

					s->mode = PHVOLT_MODE_CODE;

					if (s->raw_buffer_cursor > 0) {
						token->opcode = PHVOLT_T_RAW_FRAGMENT;
						token->value = emalloc(sizeof(char) * s->raw_buffer_cursor+1);
						memcpy(token->value, s->raw_buffer, s->raw_buffer_cursor);
						token->value[s->raw_buffer_cursor] = 0;
						token->len = s->raw_buffer_cursor;
						s->raw_buffer_cursor = 0;
						q = KKCURSOR;
					} else {
						token->opcode = PHVOLT_T_IGNORE;
					}

				} else {

					while ((next = *(++KKCURSOR))) {
						if (next == '#' && *(KKCURSOR+1) == '}') {
							KKCURSOR+=2;
							token->opcode = PHVOLT_T_IGNORE;
							return 0;
						} else {
							if (next == '\n') {
								s->active_line++;
							}
						}
					}

					return PHVOLT_SCANNER_RETCODE_EOF;

				}

				return 0;

			} else {

				if (s->raw_buffer_cursor == s->raw_buffer_size) {
					s->raw_buffer_size += PHVOLT_RAW_BUFFER_SIZE;
					s->raw_buffer = erealloc(s->raw_buffer, s->raw_buffer_size);
				}

				memcpy(s->raw_buffer+s->raw_buffer_cursor, KKCURSOR, 1);
				s->raw_buffer_cursor++;

				++KKCURSOR;
			}

		} else {

		
// 105 "scanner.c"
		{
			KKCTYPE kkch;
			unsigned int kkaccept = 0;

			kkch = *KKCURSOR;
			switch (kkch) {
			case 0x00:	goto kk61;
			case '\t':
			case '\r':
			case ' ':	goto kk57;
			case '\n':	goto kk59;
			case '!':	goto kk51;
			case '"':	goto kk20;
			case '%':	goto kk17;
			case '\'':	goto kk21;
			case '(':	goto kk37;
			case ')':	goto kk39;
			case '*':	goto kk27;
			case '+':	goto kk23;
			case ',':	goto kk35;
			case '-':	goto kk25;
			case '.':	goto kk33;
			case '/':	goto kk29;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto kk2;
			case ':':	goto kk55;
			case '<':	goto kk45;
			case '=':	goto kk47;
			case '>':	goto kk49;
			case 'A':
			case 'a':	goto kk11;
			case 'B':
			case 'b':	goto kk13;
			case 'C':
			case 'G':
			case 'H':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'P':
			case 'Q':
			case 'R':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case 'c':
			case 'g':
			case 'h':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'p':
			case 'q':
			case 'r':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto kk22;
			case 'D':
			case 'd':	goto kk14;
			case 'E':
			case 'e':	goto kk6;
			case 'F':
			case 'f':	goto kk7;
			case 'I':
			case 'i':	goto kk4;
			case 'N':
			case 'n':	goto kk9;
			case 'O':
			case 'o':	goto kk12;
			case 'S':
			case 's':	goto kk8;
			case 'T':
			case 't':	goto kk10;
			case '[':	goto kk41;
			case ']':	goto kk43;
			case '{':	goto kk15;
			case '|':	goto kk53;
			case '}':	goto kk19;
			case '~':	goto kk31;
			default:	goto kk63;
			}
kk2:
			kkaccept = 0;
			kkch = *(KKMARKER = ++KKCURSOR);
			goto kk180;
kk3:
// 106 "scanner.re"
			{
			token->opcode = PHVOLT_T_INTEGER;
			token->value = estrndup(start, KKCURSOR - start);
			token->len = KKCURSOR - start;
			q = KKCURSOR;
			return 0;
		}
// 216 "scanner.c"
kk4:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case 'F':
			case 'f':	goto kk166;
			case 'N':
			case 'n':	goto kk168;
			case 'S':
			case 's':	goto kk170;
			default:	goto kk83;
			}
kk5:
// 259 "scanner.re"
			{
			token->opcode = PHVOLT_T_IDENTIFIER;
			token->value = estrndup(start, KKCURSOR - start);
			token->len = KKCURSOR - start;
			q = KKCURSOR;
			return 0;
		}
// 237 "scanner.c"
kk6:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'L':
			case 'l':	goto kk140;
			case 'N':
			case 'n':	goto kk141;
			case 'X':
			case 'x':	goto kk142;
			default:	goto kk83;
			}
kk7:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'A':
			case 'a':	goto kk132;
			case 'O':
			case 'o':	goto kk133;
			default:	goto kk83;
			}
kk8:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'E':
			case 'e':	goto kk129;
			default:	goto kk83;
			}
kk9:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'O':
			case 'o':	goto kk122;
			case 'U':
			case 'u':	goto kk123;
			default:	goto kk83;
			}
kk10:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'R':
			case 'r':	goto kk118;
			default:	goto kk83;
			}
kk11:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'N':
			case 'n':	goto kk115;
			default:	goto kk83;
			}
kk12:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'R':
			case 'r':	goto kk113;
			default:	goto kk83;
			}
kk13:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'L':
			case 'l':	goto kk108;
			default:	goto kk83;
			}
kk14:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'E':
			case 'e':	goto kk101;
			default:	goto kk83;
			}
kk15:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '%':	goto kk99;
			case '{':	goto kk97;
			default:	goto kk16;
			}
kk16:
// 413 "scanner.re"
			{
			status = PHVOLT_SCANNER_RETCODE_ERR;
			break;
		}
// 322 "scanner.c"
kk17:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '}':	goto kk95;
			default:	goto kk18;
			}
kk18:
// 287 "scanner.re"
			{
			token->opcode = PHVOLT_T_MOD;
			return 0;
		}
// 335 "scanner.c"
kk19:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case '}':	goto kk93;
			default:	goto kk16;
			}
kk20:
			kkaccept = 1;
			kkch = *(KKMARKER = ++KKCURSOR);
			if (kkch <= 0x00) goto kk16;
			goto kk91;
kk21:
			kkaccept = 1;
			kkch = *(KKMARKER = ++KKCURSOR);
			if (kkch <= 0x00) goto kk16;
			goto kk85;
kk22:
			kkch = *++KKCURSOR;
			goto kk83;
kk23:
			++KKCURSOR;
// 267 "scanner.re"
			{
			token->opcode = PHVOLT_T_ADD;
			return 0;
		}
// 362 "scanner.c"
kk25:
			++KKCURSOR;
// 272 "scanner.re"
			{
			token->opcode = PHVOLT_T_SUB;
			return 0;
		}
// 370 "scanner.c"
kk27:
			++KKCURSOR;
// 277 "scanner.re"
			{
			token->opcode = PHVOLT_T_MUL;
			return 0;
		}
// 378 "scanner.c"
kk29:
			++KKCURSOR;
// 282 "scanner.re"
			{
			token->opcode = PHVOLT_T_DIV;
			return 0;
		}
// 386 "scanner.c"
kk31:
			++KKCURSOR;
// 292 "scanner.re"
			{
			token->opcode = PHVOLT_T_CONCAT;
			return 0;
		}
// 394 "scanner.c"
kk33:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '.':	goto kk80;
			default:	goto kk34;
			}
kk34:
// 302 "scanner.re"
			{
			token->opcode = PHVOLT_T_DOT;
			return 0;
		}
// 407 "scanner.c"
kk35:
			++KKCURSOR;
// 307 "scanner.re"
			{
			token->opcode = PHVOLT_T_COMMA;
			return 0;
		}
// 415 "scanner.c"
kk37:
			++KKCURSOR;
// 312 "scanner.re"
			{
			token->opcode = PHVOLT_T_BRACKET_OPEN;
			return 0;
		}
// 423 "scanner.c"
kk39:
			++KKCURSOR;
// 317 "scanner.re"
			{
			token->opcode = PHVOLT_T_BRACKET_CLOSE;
			return 0;
		}
// 431 "scanner.c"
kk41:
			++KKCURSOR;
// 322 "scanner.re"
			{
			token->opcode = PHVOLT_T_SBRACKET_OPEN;
			return 0;
		}
// 439 "scanner.c"
kk43:
			++KKCURSOR;
// 327 "scanner.re"
			{
			token->opcode = PHVOLT_T_SBRACKET_CLOSE;
			return 0;
		}
// 447 "scanner.c"
kk45:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '=':	goto kk78;
			case '>':	goto kk76;
			default:	goto kk46;
			}
kk46:
// 377 "scanner.re"
			{
			token->opcode = PHVOLT_T_LESS;
			return 0;
		}
// 461 "scanner.c"
kk47:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '=':	goto kk72;
			default:	goto kk48;
			}
kk48:
// 337 "scanner.re"
			{
			token->opcode = PHVOLT_T_ASSIGN;
			return 0;
		}
// 474 "scanner.c"
kk49:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '=':	goto kk70;
			default:	goto kk50;
			}
kk50:
// 382 "scanner.re"
			{
			token->opcode = PHVOLT_T_GREATER;
			return 0;
		}
// 487 "scanner.c"
kk51:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '=':	goto kk66;
			default:	goto kk52;
			}
kk52:
// 372 "scanner.re"
			{
			token->opcode = PHVOLT_T_NOT;
			return 0;
		}
// 500 "scanner.c"
kk53:
			++KKCURSOR;
// 387 "scanner.re"
			{
			token->opcode = PHVOLT_T_PIPE;
			return 0;
		}
// 508 "scanner.c"
kk55:
			++KKCURSOR;
// 392 "scanner.re"
			{
			token->opcode = PHVOLT_T_DOUBLECOLON;
			return 0;
		}
// 516 "scanner.c"
kk57:
			++KKCURSOR;
			kkch = *KKCURSOR;
			goto kk65;
kk58:
// 397 "scanner.re"
			{
			token->opcode = PHVOLT_T_IGNORE;
			return 0;
		}
// 527 "scanner.c"
kk59:
			++KKCURSOR;
// 402 "scanner.re"
			{
			s->active_line++;
			token->opcode = PHVOLT_T_IGNORE;
			return 0;
		}
// 536 "scanner.c"
kk61:
			++KKCURSOR;
// 408 "scanner.re"
			{
			status = PHVOLT_SCANNER_RETCODE_EOF;
			break;
		}
// 544 "scanner.c"
kk63:
			kkch = *++KKCURSOR;
			goto kk16;
kk64:
			++KKCURSOR;
			kkch = *KKCURSOR;
kk65:
			switch (kkch) {
			case '\t':
			case '\r':
			case ' ':	goto kk64;
			default:	goto kk58;
			}
kk66:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '=':	goto kk68;
			default:	goto kk67;
			}
kk67:
// 352 "scanner.re"
			{
			token->opcode = PHVOLT_T_NOTEQUALS;
			return 0;
		}
// 570 "scanner.c"
kk68:
			++KKCURSOR;
// 367 "scanner.re"
			{
			token->opcode = PHVOLT_T_NOTIDENTICAL;
			return 0;
		}
// 578 "scanner.c"
kk70:
			++KKCURSOR;
// 342 "scanner.re"
			{
			token->opcode = PHVOLT_T_GREATEREQUAL;
			return 0;
		}
// 586 "scanner.c"
kk72:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '=':	goto kk74;
			default:	goto kk73;
			}
kk73:
// 347 "scanner.re"
			{
			token->opcode = PHVOLT_T_EQUALS;
			return 0;
		}
// 599 "scanner.c"
kk74:
			++KKCURSOR;
// 362 "scanner.re"
			{
			token->opcode = PHVOLT_T_IDENTICAL;
			return 0;
		}
// 607 "scanner.c"
kk76:
			++KKCURSOR;
// 357 "scanner.re"
			{
			token->opcode = PHVOLT_T_NOTEQUALS;
			return 0;
		}
// 615 "scanner.c"
kk78:
			++KKCURSOR;
// 332 "scanner.re"
			{
			token->opcode = PHVOLT_T_LESSEQUAL;
			return 0;
		}
// 623 "scanner.c"
kk80:
			++KKCURSOR;
// 297 "scanner.re"
			{
			token->opcode = PHVOLT_T_RANGE;
			return 0;
		}
// 631 "scanner.c"
kk82:
			++KKCURSOR;
			kkch = *KKCURSOR;
kk83:
			switch (kkch) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto kk82;
			default:	goto kk5;
			}
kk84:
			++KKCURSOR;
			kkch = *KKCURSOR;
kk85:
			switch (kkch) {
			case 0x00:	goto kk86;
			case '\'':	goto kk88;
			case '\\':	goto kk87;
			default:	goto kk84;
			}
kk86:
			KKCURSOR = KKMARKER;
			switch (kkaccept) {
			case 0: 	goto kk3;
			case 1: 	goto kk16;
			}
kk87:
			++KKCURSOR;
			kkch = *KKCURSOR;
			switch (kkch) {
			case '\n':	goto kk86;
			default:	goto kk84;
			}
kk88:
			++KKCURSOR;
// 250 "scanner.re"
			{
			token->opcode = PHVOLT_T_STRING;
			token->value = estrndup(q, KKCURSOR - q - 1);
			token->len = KKCURSOR - q - 1;
			q = KKCURSOR;
			return 0;
		}
// 736 "scanner.c"
kk90:
			++KKCURSOR;
			kkch = *KKCURSOR;
kk91:
			switch (kkch) {
			case 0x00:	goto kk86;
			case '"':	goto kk88;
			case '\\':	goto kk92;
			default:	goto kk90;
			}
kk92:
			++KKCURSOR;
			kkch = *KKCURSOR;
			switch (kkch) {
			case '\n':	goto kk86;
			default:	goto kk90;
			}
kk93:
			++KKCURSOR;
// 243 "scanner.re"
			{
			s->mode = PHVOLT_MODE_RAW;
			token->opcode = PHVOLT_T_CLOSE_EDELIMITER;
			return 0;
		}
// 762 "scanner.c"
kk95:
			++KKCURSOR;
// 231 "scanner.re"
			{
			s->mode = PHVOLT_MODE_RAW;
			token->opcode = PHVOLT_T_CLOSE_DELIMITER;
			return 0;
		}
// 771 "scanner.c"
kk97:
			++KKCURSOR;
// 237 "scanner.re"
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_OPEN_EDELIMITER;
			return 0;
		}
// 780 "scanner.c"
kk99:
			++KKCURSOR;
// 226 "scanner.re"
			{
			token->opcode = PHVOLT_T_OPEN_DELIMITER;
			return 0;
		}
// 788 "scanner.c"
kk101:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'F':
			case 'f':	goto kk102;
			default:	goto kk83;
			}
kk102:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'I':
			case 'i':	goto kk103;
			default:	goto kk83;
			}
kk103:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'N':
			case 'n':	goto kk104;
			default:	goto kk83;
			}
kk104:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'E':
			case 'e':	goto kk105;
			default:	goto kk83;
			}
kk105:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'D':
			case 'd':	goto kk106;
			default:	goto kk83;
			}
kk106:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto kk82;
			default:	goto kk107;
			}
kk107:
// 214 "scanner.re"
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_DEFINED;
			return 0;
		}
// 900 "scanner.c"
kk108:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'O':
			case 'o':	goto kk109;
			default:	goto kk83;
			}
kk109:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'C':
			case 'c':	goto kk110;
			default:	goto kk83;
			}
kk110:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'K':
			case 'k':	goto kk111;
			default:	goto kk83;
			}
kk111:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto kk82;
			default:	goto kk112;
			}
kk112:
// 185 "scanner.re"
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_BLOCK;
			return 0;
		}
// 998 "scanner.c"
kk113:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto kk82;
			default:	goto kk114;
			}
kk114:
// 180 "scanner.re"
			{
			token->opcode = PHVOLT_T_OR;
			return 0;
		}
// 1074 "scanner.c"
kk115:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'D':
			case 'd':	goto kk116;
			default:	goto kk83;
			}
kk116:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto kk82;
			default:	goto kk117;
			}
kk117:
// 175 "scanner.re"
			{
			token->opcode = PHVOLT_T_AND;
			return 0;
		}
// 1157 "scanner.c"
kk118:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'U':
			case 'u':	goto kk119;
			default:	goto kk83;
			}
kk119:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'E':
			case 'e':	goto kk120;
			default:	goto kk83;
			}
kk120:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto kk82;
			default:	goto kk121;
			}
kk121:
// 170 "scanner.re"
			{
			token->opcode = PHVOLT_T_TRUE;
			return 0;
		}
// 1247 "scanner.c"
kk122:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'T':
			case 't':	goto kk127;
			default:	goto kk83;
			}
kk123:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'L':
			case 'l':	goto kk124;
			default:	goto kk83;
			}
kk124:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'L':
			case 'l':	goto kk125;
			default:	goto kk83;
			}
kk125:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto kk82;
			default:	goto kk126;
			}
kk126:
// 160 "scanner.re"
			{
			token->opcode = PHVOLT_T_NULL;
			return 0;
		}
// 1344 "scanner.c"
kk127:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto kk82;
			default:	goto kk128;
			}
kk128:
// 208 "scanner.re"
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_NOT;
			return 0;
		}
// 1421 "scanner.c"
kk129:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'T':
			case 't':	goto kk130;
			default:	goto kk83;
			}
kk130:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto kk82;
			default:	goto kk131;
			}
kk131:
// 155 "scanner.re"
			{
			token->opcode = PHVOLT_T_SET;
			return 0;
		}
// 1504 "scanner.c"
kk132:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'L':
			case 'l':	goto kk136;
			default:	goto kk83;
			}
kk133:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'R':
			case 'r':	goto kk134;
			default:	goto kk83;
			}
kk134:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto kk82;
			default:	goto kk135;
			}
kk135:
// 139 "scanner.re"
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_FOR;
			return 0;
		}
// 1595 "scanner.c"
kk136:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'S':
			case 's':	goto kk137;
			default:	goto kk83;
			}
kk137:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'E':
			case 'e':	goto kk138;
			default:	goto kk83;
			}
kk138:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto kk82;
			default:	goto kk139;
			}
kk139:
// 165 "scanner.re"
			{
			token->opcode = PHVOLT_T_FALSE;
			return 0;
		}
// 1685 "scanner.c"
kk140:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'S':
			case 's':	goto kk163;
			default:	goto kk83;
			}
kk141:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'D':
			case 'd':	goto kk149;
			default:	goto kk83;
			}
kk142:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'T':
			case 't':	goto kk143;
			default:	goto kk83;
			}
kk143:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'E':
			case 'e':	goto kk144;
			default:	goto kk83;
			}
kk144:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'N':
			case 'n':	goto kk145;
			default:	goto kk83;
			}
kk145:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'D':
			case 'd':	goto kk146;
			default:	goto kk83;
			}
kk146:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'S':
			case 's':	goto kk147;
			default:	goto kk83;
			}
kk147:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto kk82;
			default:	goto kk148;
			}
kk148:
// 196 "scanner.re"
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_EXTENDS;
			return 0;
		}
// 1811 "scanner.c"
kk149:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'B':
			case 'b':	goto kk150;
			case 'F':
			case 'f':	goto kk151;
			case 'I':
			case 'i':	goto kk152;
			default:	goto kk83;
			}
kk150:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'L':
			case 'l':	goto kk158;
			default:	goto kk83;
			}
kk151:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'O':
			case 'o':	goto kk155;
			default:	goto kk83;
			}
kk152:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'F':
			case 'f':	goto kk153;
			default:	goto kk83;
			}
kk153:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto kk82;
			default:	goto kk154;
			}
kk154:
// 134 "scanner.re"
			{
			token->opcode = PHVOLT_T_ENDIF;
			return 0;
		}
// 1919 "scanner.c"
kk155:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'R':
			case 'r':	goto kk156;
			default:	goto kk83;
			}
kk156:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto kk82;
			default:	goto kk157;
			}
kk157:
// 145 "scanner.re"
			{
			token->opcode = PHVOLT_T_ENDFOR;
			return 0;
		}
// 2002 "scanner.c"
kk158:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'O':
			case 'o':	goto kk159;
			default:	goto kk83;
			}
kk159:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'C':
			case 'c':	goto kk160;
			default:	goto kk83;
			}
kk160:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'K':
			case 'k':	goto kk161;
			default:	goto kk83;
			}
kk161:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto kk82;
			default:	goto kk162;
			}
kk162:
// 191 "scanner.re"
			{
			token->opcode = PHVOLT_T_ENDBLOCK;
			return 0;
		}
// 2099 "scanner.c"
kk163:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'E':
			case 'e':	goto kk164;
			default:	goto kk83;
			}
kk164:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto kk82;
			default:	goto kk165;
			}
kk165:
// 129 "scanner.re"
			{
			token->opcode = PHVOLT_T_ELSE;
			return 0;
		}
// 2182 "scanner.c"
kk166:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto kk82;
			default:	goto kk167;
			}
kk167:
// 123 "scanner.re"
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_IF;
			return 0;
		}
// 2259 "scanner.c"
kk168:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto kk82;
			case 'C':
			case 'c':	goto kk172;
			default:	goto kk169;
			}
kk169:
// 150 "scanner.re"
			{
			token->opcode = PHVOLT_T_IN;
			return 0;
		}
// 2335 "scanner.c"
kk170:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto kk82;
			default:	goto kk171;
			}
kk171:
// 202 "scanner.re"
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_IS;
			return 0;
		}
// 2412 "scanner.c"
kk172:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'L':
			case 'l':	goto kk173;
			default:	goto kk83;
			}
kk173:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'U':
			case 'u':	goto kk174;
			default:	goto kk83;
			}
kk174:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'D':
			case 'd':	goto kk175;
			default:	goto kk83;
			}
kk175:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case 'E':
			case 'e':	goto kk176;
			default:	goto kk83;
			}
kk176:
			++KKCURSOR;
			switch ((kkch = *KKCURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '\\':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto kk82;
			default:	goto kk177;
			}
kk177:
// 220 "scanner.re"
			{
			s->statement_position++;
			token->opcode = PHVOLT_T_INCLUDE;
			return 0;
		}
// 2517 "scanner.c"
kk178:
			kkch = *++KKCURSOR;
			switch (kkch) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto kk181;
			default:	goto kk86;
			}
kk179:
			kkaccept = 0;
			KKMARKER = ++KKCURSOR;
			kkch = *KKCURSOR;
kk180:
			switch (kkch) {
			case '.':	goto kk178;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto kk179;
			default:	goto kk3;
			}
kk181:
			++KKCURSOR;
			kkch = *KKCURSOR;
			switch (kkch) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto kk181;
			default:	goto kk183;
			}
kk183:
// 115 "scanner.re"
			{
			token->opcode = PHVOLT_T_DOUBLE;
			token->value = estrndup(start, KKCURSOR - start);
			token->len = KKCURSOR - start;
			q = KKCURSOR;
			return 0;
		}
// 2577 "scanner.c"
		}
// 418 "scanner.re"


		}
	}

	return status;
}
