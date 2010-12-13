#include "parser.h"

#include <stdio.h>
#include <stdlib.h>

#include <vector>

using namespace std;

#define INI_PROG 0x0000
#define MAX_LABELS 2048

Parser::Parser (Memoria *memory, char* input)
{
	posAtual = INI_PROG;

	entrada = fopen (input, "r");
	if (!entrada)
	{
		printf ("Nao foi possivel carregar o arquivo de entrada.\n");
	}

	mem = memory;

	nop["add"] = 2;
	nop["sub"] = 2;
	nop["mov"] = 2;
	nop["cmp"] = 2;
	nop["and"] = 2;
	nop["or"] = 2;
	nop["not"] = 1;
	nop["clr"] = 1;
	nop["neg"] = 1;
	nop["sh"] = 2;
	nop["br"] = 2;
	nop["jmp"] = 1;
	nop["halt"] = 0;
	nop["brz"] = 1;
	nop["brn"] = 1;
	nop["bre"] = 1;
	nop["brl"] = 1;
	nop["brg"] = 1;
	nop["brc"] = 1;

	codigo[command("add", "#const", "r0")] = 1;
	codigo[command("add", "#const", "r1")] = 2;
	codigo[command("add", "#const", "r2")] = 3;
	codigo[command("add", "#const", "r3")] = 4;
	codigo[command("add", "#const", "r4")] = 5;
	codigo[command("add", "#const", "(r0)")] = 6;
	codigo[command("add", "#const", "(r1)")] = 7;
	codigo[command("add", "#const", "(r2)")] = 8;
	codigo[command("add", "#const", "(r3)")] = 9;
	codigo[command("add", "#const", "(r4)")] = 10;
	codigo[command("add", "r0", "r0")] = 11;
	codigo[command("add", "r0", "r1")] = 12;
	codigo[command("add", "r0", "r2")] = 13;
	codigo[command("add", "r0", "r3")] = 14;
	codigo[command("add", "r0", "r4")] = 15;
	codigo[command("add", "r1", "r0")] = 16;
	codigo[command("add", "r1", "r1")] = 17;
	codigo[command("add", "r1", "r2")] = 18;
	codigo[command("add", "r1", "r3")] = 19;
	codigo[command("add", "r1", "r4")] = 20;
	codigo[command("add", "r2", "r0")] = 21;
	codigo[command("add", "r2", "r1")] = 22;
	codigo[command("add", "r2", "r2")] = 23;
	codigo[command("add", "r2", "r3")] = 24;
	codigo[command("add", "r2", "r4")] = 25;
	codigo[command("add", "r3", "r0")] = 26;
	codigo[command("add", "r3", "r1")] = 27;
	codigo[command("add", "r3", "r2")] = 28;
	codigo[command("add", "r3", "r3")] = 29;
	codigo[command("add", "r3", "r4")] = 30;
	codigo[command("add", "r4", "r0")] = 31;
	codigo[command("add", "r4", "r1")] = 32;
	codigo[command("add", "r4", "r2")] = 33;
	codigo[command("add", "r4", "r3")] = 34;
	codigo[command("add", "r4", "r4")] = 35;
	codigo[command("add", "r0", "(r0)")] = 36;
	codigo[command("add", "r0", "(r1)")] = 37;
	codigo[command("add", "r0", "(r2)")] = 38;
	codigo[command("add", "r0", "(r3)")] = 39;
	codigo[command("add", "r0", "(r4)")] = 40;
	codigo[command("add", "r1", "(r0)")] = 41;
	codigo[command("add", "r1", "(r1)")] = 42;
	codigo[command("add", "r1", "(r2)")] = 43;
	codigo[command("add", "r1", "(r3)")] = 44;
	codigo[command("add", "r1", "(r4)")] = 45;
	codigo[command("add", "r2", "(r0)")] = 46;
	codigo[command("add", "r2", "(r1)")] = 47;
	codigo[command("add", "r2", "(r2)")] = 48;
	codigo[command("add", "r2", "(r3)")] = 49;
	codigo[command("add", "r2", "(r4)")] = 50;
	codigo[command("add", "r3", "(r0)")] = 51;
	codigo[command("add", "r3", "(r1)")] = 52;
	codigo[command("add", "r3", "(r2)")] = 53;
	codigo[command("add", "r3", "(r3)")] = 54;
	codigo[command("add", "r3", "(r4)")] = 55;
	codigo[command("add", "r4", "(r0)")] = 56;
	codigo[command("add", "r4", "(r1)")] = 57;
	codigo[command("add", "r4", "(r2)")] = 58;
	codigo[command("add", "r4", "(r3)")] = 59;
	codigo[command("add", "r4", "(r4)")] = 60;
	codigo[command("add", "(r0)", "r0")] = 61;
	codigo[command("add", "(r0)", "r1")] = 62;
	codigo[command("add", "(r0)", "r2")] = 63;
	codigo[command("add", "(r0)", "r3")] = 64;
	codigo[command("add", "(r0)", "r4")] = 65;
	codigo[command("add", "(r1)", "r0")] = 66;
	codigo[command("add", "(r1)", "r1")] = 67;
	codigo[command("add", "(r1)", "r2")] = 68;
	codigo[command("add", "(r1)", "r3")] = 69;
	codigo[command("add", "(r1)", "r4")] = 70;
	codigo[command("add", "(r2)", "r0")] = 71;
	codigo[command("add", "(r2)", "r1")] = 72;
	codigo[command("add", "(r2)", "r2")] = 73;
	codigo[command("add", "(r2)", "r3")] = 74;
	codigo[command("add", "(r2)", "r4")] = 75;
	codigo[command("add", "(r3)", "r0")] = 76;
	codigo[command("add", "(r3)", "r1")] = 77;
	codigo[command("add", "(r3)", "r2")] = 78;
	codigo[command("add", "(r3)", "r3")] = 79;
	codigo[command("add", "(r3)", "r4")] = 80;
	codigo[command("add", "(r4)", "r0")] = 81;
	codigo[command("add", "(r4)", "r1")] = 82;
	codigo[command("add", "(r4)", "r2")] = 83;
	codigo[command("add", "(r4)", "r3")] = 84;
	codigo[command("add", "(r4)", "r4")] = 85;
	codigo[command("add", "(r0)", "(r0)")] = 86;
	codigo[command("add", "(r0)", "(r1)")] = 87;
	codigo[command("add", "(r0)", "(r2)")] = 88;
	codigo[command("add", "(r0)", "(r3)")] = 89;
	codigo[command("add", "(r0)", "(r4)")] = 90;
	codigo[command("add", "(r1)", "(r0)")] = 91;
	codigo[command("add", "(r1)", "(r1)")] = 92;
	codigo[command("add", "(r1)", "(r2)")] = 93;
	codigo[command("add", "(r1)", "(r3)")] = 94;
	codigo[command("add", "(r1)", "(r4)")] = 95;
	codigo[command("add", "(r2)", "(r0)")] = 96;
	codigo[command("add", "(r2)", "(r1)")] = 97;
	codigo[command("add", "(r2)", "(r2)")] = 98;
	codigo[command("add", "(r2)", "(r3)")] = 99;
	codigo[command("add", "(r2)", "(r4)")] = 100;
	codigo[command("add", "(r3)", "(r0)")] = 101;
	codigo[command("add", "(r3)", "(r1)")] = 102;
	codigo[command("add", "(r3)", "(r2)")] = 103;
	codigo[command("add", "(r3)", "(r3)")] = 104;
	codigo[command("add", "(r3)", "(r4)")] = 105;
	codigo[command("add", "(r4)", "(r0)")] = 106;
	codigo[command("add", "(r4)", "(r1)")] = 107;
	codigo[command("add", "(r4)", "(r2)")] = 108;
	codigo[command("add", "(r4)", "(r3)")] = 109;
	codigo[command("add", "(r4)", "(r4)")] = 110;
	codigo[command("sub", "#const", "r0")] = 111;
	codigo[command("sub", "#const", "r1")] = 112;
	codigo[command("sub", "#const", "r2")] = 113;
	codigo[command("sub", "#const", "r3")] = 114;
	codigo[command("sub", "#const", "r4")] = 115;
	codigo[command("sub", "#const", "(r0)")] = 116;
	codigo[command("sub", "#const", "(r1)")] = 117;
	codigo[command("sub", "#const", "(r2)")] = 118;
	codigo[command("sub", "#const", "(r3)")] = 119;
	codigo[command("sub", "#const", "(r4)")] = 120;
	codigo[command("sub", "r0", "r0")] = 121;
	codigo[command("sub", "r0", "r1")] = 122;
	codigo[command("sub", "r0", "r2")] = 123;
	codigo[command("sub", "r0", "r3")] = 124;
	codigo[command("sub", "r0", "r4")] = 125;
	codigo[command("sub", "r1", "r0")] = 126;
	codigo[command("sub", "r1", "r1")] = 127;
	codigo[command("sub", "r1", "r2")] = 128;
	codigo[command("sub", "r1", "r3")] = 129;
	codigo[command("sub", "r1", "r4")] = 130;
	codigo[command("sub", "r2", "r0")] = 131;
	codigo[command("sub", "r2", "r1")] = 132;
	codigo[command("sub", "r2", "r2")] = 133;
	codigo[command("sub", "r2", "r3")] = 134;
	codigo[command("sub", "r2", "r4")] = 135;
	codigo[command("sub", "r3", "r0")] = 136;
	codigo[command("sub", "r3", "r1")] = 137;
	codigo[command("sub", "r3", "r2")] = 138;
	codigo[command("sub", "r3", "r3")] = 139;
	codigo[command("sub", "r3", "r4")] = 140;
	codigo[command("sub", "r4", "r0")] = 141;
	codigo[command("sub", "r4", "r1")] = 142;
	codigo[command("sub", "r4", "r2")] = 143;
	codigo[command("sub", "r4", "r3")] = 144;
	codigo[command("sub", "r4", "r4")] = 145;
	codigo[command("sub", "r0", "(r0)")] = 146;
	codigo[command("sub", "r0", "(r1)")] = 147;
	codigo[command("sub", "r0", "(r2)")] = 148;
	codigo[command("sub", "r0", "(r3)")] = 149;
	codigo[command("sub", "r0", "(r4)")] = 150;
	codigo[command("sub", "r1", "(r0)")] = 151;
	codigo[command("sub", "r1", "(r1)")] = 152;
	codigo[command("sub", "r1", "(r2)")] = 153;
	codigo[command("sub", "r1", "(r3)")] = 154;
	codigo[command("sub", "r1", "(r4)")] = 155;
	codigo[command("sub", "r2", "(r0)")] = 156;
	codigo[command("sub", "r2", "(r1)")] = 157;
	codigo[command("sub", "r2", "(r2)")] = 158;
	codigo[command("sub", "r2", "(r3)")] = 159;
	codigo[command("sub", "r2", "(r4)")] = 160;
	codigo[command("sub", "r3", "(r0)")] = 161;
	codigo[command("sub", "r3", "(r1)")] = 162;
	codigo[command("sub", "r3", "(r2)")] = 163;
	codigo[command("sub", "r3", "(r3)")] = 164;
	codigo[command("sub", "r3", "(r4)")] = 165;
	codigo[command("sub", "r4", "(r0)")] = 166;
	codigo[command("sub", "r4", "(r1)")] = 167;
	codigo[command("sub", "r4", "(r2)")] = 168;
	codigo[command("sub", "r4", "(r3)")] = 169;
	codigo[command("sub", "r4", "(r4)")] = 170;
	codigo[command("sub", "(r0)", "r0")] = 171;
	codigo[command("sub", "(r0)", "r1")] = 172;
	codigo[command("sub", "(r0)", "r2")] = 173;
	codigo[command("sub", "(r0)", "r3")] = 174;
	codigo[command("sub", "(r0)", "r4")] = 175;
	codigo[command("sub", "(r1)", "r0")] = 176;
	codigo[command("sub", "(r1)", "r1")] = 177;
	codigo[command("sub", "(r1)", "r2")] = 178;
	codigo[command("sub", "(r1)", "r3")] = 179;
	codigo[command("sub", "(r1)", "r4")] = 180;
	codigo[command("sub", "(r2)", "r0")] = 181;
	codigo[command("sub", "(r2)", "r1")] = 182;
	codigo[command("sub", "(r2)", "r2")] = 183;
	codigo[command("sub", "(r2)", "r3")] = 184;
	codigo[command("sub", "(r2)", "r4")] = 185;
	codigo[command("sub", "(r3)", "r0")] = 186;
	codigo[command("sub", "(r3)", "r1")] = 187;
	codigo[command("sub", "(r3)", "r2")] = 188;
	codigo[command("sub", "(r3)", "r3")] = 189;
	codigo[command("sub", "(r3)", "r4")] = 190;
	codigo[command("sub", "(r4)", "r0")] = 191;
	codigo[command("sub", "(r4)", "r1")] = 192;
	codigo[command("sub", "(r4)", "r2")] = 193;
	codigo[command("sub", "(r4)", "r3")] = 194;
	codigo[command("sub", "(r4)", "r4")] = 195;
	codigo[command("sub", "(r0)", "(r0)")] = 196;
	codigo[command("sub", "(r0)", "(r1)")] = 197;
	codigo[command("sub", "(r0)", "(r2)")] = 198;
	codigo[command("sub", "(r0)", "(r3)")] = 199;
	codigo[command("sub", "(r0)", "(r4)")] = 200;
	codigo[command("sub", "(r1)", "(r0)")] = 201;
	codigo[command("sub", "(r1)", "(r1)")] = 202;
	codigo[command("sub", "(r1)", "(r2)")] = 203;
	codigo[command("sub", "(r1)", "(r3)")] = 204;
	codigo[command("sub", "(r1)", "(r4)")] = 205;
	codigo[command("sub", "(r2)", "(r0)")] = 206;
	codigo[command("sub", "(r2)", "(r1)")] = 207;
	codigo[command("sub", "(r2)", "(r2)")] = 208;
	codigo[command("sub", "(r2)", "(r3)")] = 209;
	codigo[command("sub", "(r2)", "(r4)")] = 210;
	codigo[command("sub", "(r3)", "(r0)")] = 211;
	codigo[command("sub", "(r3)", "(r1)")] = 212;
	codigo[command("sub", "(r3)", "(r2)")] = 213;
	codigo[command("sub", "(r3)", "(r3)")] = 214;
	codigo[command("sub", "(r3)", "(r4)")] = 215;
	codigo[command("sub", "(r4)", "(r0)")] = 216;
	codigo[command("sub", "(r4)", "(r1)")] = 217;
	codigo[command("sub", "(r4)", "(r2)")] = 218;
	codigo[command("sub", "(r4)", "(r3)")] = 219;
	codigo[command("sub", "(r4)", "(r4)")] = 220;
	codigo[command("mov", "#const", "r0")] = 221;
	codigo[command("mov", "#const", "r1")] = 222;
	codigo[command("mov", "#const", "r2")] = 223;
	codigo[command("mov", "#const", "r3")] = 224;
	codigo[command("mov", "#const", "r4")] = 225;
	codigo[command("mov", "#const", "(r0)")] = 226;
	codigo[command("mov", "#const", "(r1)")] = 227;
	codigo[command("mov", "#const", "(r2)")] = 228;
	codigo[command("mov", "#const", "(r3)")] = 229;
	codigo[command("mov", "#const", "(r4)")] = 230;
	codigo[command("mov", "r0", "r0")] = 231;
	codigo[command("mov", "r0", "r1")] = 232;
	codigo[command("mov", "r0", "r2")] = 233;
	codigo[command("mov", "r0", "r3")] = 234;
	codigo[command("mov", "r0", "r4")] = 235;
	codigo[command("mov", "r1", "r0")] = 236;
	codigo[command("mov", "r1", "r1")] = 237;
	codigo[command("mov", "r1", "r2")] = 238;
	codigo[command("mov", "r1", "r3")] = 239;
	codigo[command("mov", "r1", "r4")] = 240;
	codigo[command("mov", "r2", "r0")] = 241;
	codigo[command("mov", "r2", "r1")] = 242;
	codigo[command("mov", "r2", "r2")] = 243;
	codigo[command("mov", "r2", "r3")] = 244;
	codigo[command("mov", "r2", "r4")] = 245;
	codigo[command("mov", "r3", "r0")] = 246;
	codigo[command("mov", "r3", "r1")] = 247;
	codigo[command("mov", "r3", "r2")] = 248;
	codigo[command("mov", "r3", "r3")] = 249;
	codigo[command("mov", "r3", "r4")] = 250;
	codigo[command("mov", "r4", "r0")] = 251;
	codigo[command("mov", "r4", "r1")] = 252;
	codigo[command("mov", "r4", "r2")] = 253;
	codigo[command("mov", "r4", "r3")] = 254;
	codigo[command("mov", "r4", "r4")] = 255;
	codigo[command("mov", "r0", "(r0)")] = 256;
	codigo[command("mov", "r0", "(r1)")] = 257;
	codigo[command("mov", "r0", "(r2)")] = 258;
	codigo[command("mov", "r0", "(r3)")] = 259;
	codigo[command("mov", "r0", "(r4)")] = 260;
	codigo[command("mov", "r1", "(r0)")] = 261;
	codigo[command("mov", "r1", "(r1)")] = 262;
	codigo[command("mov", "r1", "(r2)")] = 263;
	codigo[command("mov", "r1", "(r3)")] = 264;
	codigo[command("mov", "r1", "(r4)")] = 265;
	codigo[command("mov", "r2", "(r0)")] = 266;
	codigo[command("mov", "r2", "(r1)")] = 267;
	codigo[command("mov", "r2", "(r2)")] = 268;
	codigo[command("mov", "r2", "(r3)")] = 269;
	codigo[command("mov", "r2", "(r4)")] = 270;
	codigo[command("mov", "r3", "(r0)")] = 271;
	codigo[command("mov", "r3", "(r1)")] = 272;
	codigo[command("mov", "r3", "(r2)")] = 273;
	codigo[command("mov", "r3", "(r3)")] = 274;
	codigo[command("mov", "r3", "(r4)")] = 275;
	codigo[command("mov", "r4", "(r0)")] = 276;
	codigo[command("mov", "r4", "(r1)")] = 277;
	codigo[command("mov", "r4", "(r2)")] = 278;
	codigo[command("mov", "r4", "(r3)")] = 279;
	codigo[command("mov", "r4", "(r4)")] = 280;
	codigo[command("mov", "(r0)", "r0")] = 281;
	codigo[command("mov", "(r0)", "r1")] = 282;
	codigo[command("mov", "(r0)", "r2")] = 283;
	codigo[command("mov", "(r0)", "r3")] = 284;
	codigo[command("mov", "(r0)", "r4")] = 285;
	codigo[command("mov", "(r1)", "r0")] = 286;
	codigo[command("mov", "(r1)", "r1")] = 287;
	codigo[command("mov", "(r1)", "r2")] = 288;
	codigo[command("mov", "(r1)", "r3")] = 289;
	codigo[command("mov", "(r1)", "r4")] = 290;
	codigo[command("mov", "(r2)", "r0")] = 291;
	codigo[command("mov", "(r2)", "r1")] = 292;
	codigo[command("mov", "(r2)", "r2")] = 293;
	codigo[command("mov", "(r2)", "r3")] = 294;
	codigo[command("mov", "(r2)", "r4")] = 295;
	codigo[command("mov", "(r3)", "r0")] = 296;
	codigo[command("mov", "(r3)", "r1")] = 297;
	codigo[command("mov", "(r3)", "r2")] = 298;
	codigo[command("mov", "(r3)", "r3")] = 299;
	codigo[command("mov", "(r3)", "r4")] = 300;
	codigo[command("mov", "(r4)", "r0")] = 301;
	codigo[command("mov", "(r4)", "r1")] = 302;
	codigo[command("mov", "(r4)", "r2")] = 303;
	codigo[command("mov", "(r4)", "r3")] = 304;
	codigo[command("mov", "(r4)", "r4")] = 305;
	codigo[command("mov", "(r0)", "(r0)")] = 306;
	codigo[command("mov", "(r0)", "(r1)")] = 307;
	codigo[command("mov", "(r0)", "(r2)")] = 308;
	codigo[command("mov", "(r0)", "(r3)")] = 309;
	codigo[command("mov", "(r0)", "(r4)")] = 310;
	codigo[command("mov", "(r1)", "(r0)")] = 311;
	codigo[command("mov", "(r1)", "(r1)")] = 312;
	codigo[command("mov", "(r1)", "(r2)")] = 313;
	codigo[command("mov", "(r1)", "(r3)")] = 314;
	codigo[command("mov", "(r1)", "(r4)")] = 315;
	codigo[command("mov", "(r2)", "(r0)")] = 316;
	codigo[command("mov", "(r2)", "(r1)")] = 317;
	codigo[command("mov", "(r2)", "(r2)")] = 318;
	codigo[command("mov", "(r2)", "(r3)")] = 319;
	codigo[command("mov", "(r2)", "(r4)")] = 320;
	codigo[command("mov", "(r3)", "(r0)")] = 321;
	codigo[command("mov", "(r3)", "(r1)")] = 322;
	codigo[command("mov", "(r3)", "(r2)")] = 323;
	codigo[command("mov", "(r3)", "(r3)")] = 324;
	codigo[command("mov", "(r3)", "(r4)")] = 325;
	codigo[command("mov", "(r4)", "(r0)")] = 326;
	codigo[command("mov", "(r4)", "(r1)")] = 327;
	codigo[command("mov", "(r4)", "(r2)")] = 328;
	codigo[command("mov", "(r4)", "(r3)")] = 329;
	codigo[command("mov", "(r4)", "(r4)")] = 330;
	codigo[command("cmp", "#const", "r0")] = 331;
	codigo[command("cmp", "#const", "r1")] = 332;
	codigo[command("cmp", "#const", "r2")] = 333;
	codigo[command("cmp", "#const", "r3")] = 334;
	codigo[command("cmp", "#const", "r4")] = 335;
	codigo[command("cmp", "#const", "(r0)")] = 336;
	codigo[command("cmp", "#const", "(r1)")] = 337;
	codigo[command("cmp", "#const", "(r2)")] = 338;
	codigo[command("cmp", "#const", "(r3)")] = 339;
	codigo[command("cmp", "#const", "(r4)")] = 340;
	codigo[command("cmp", "r0", "r0")] = 341;
	codigo[command("cmp", "r0", "r1")] = 342;
	codigo[command("cmp", "r0", "r2")] = 343;
	codigo[command("cmp", "r0", "r3")] = 344;
	codigo[command("cmp", "r0", "r4")] = 345;
	codigo[command("cmp", "r1", "r0")] = 346;
	codigo[command("cmp", "r1", "r1")] = 347;
	codigo[command("cmp", "r1", "r2")] = 348;
	codigo[command("cmp", "r1", "r3")] = 349;
	codigo[command("cmp", "r1", "r4")] = 350;
	codigo[command("cmp", "r2", "r0")] = 351;
	codigo[command("cmp", "r2", "r1")] = 352;
	codigo[command("cmp", "r2", "r2")] = 353;
	codigo[command("cmp", "r2", "r3")] = 354;
	codigo[command("cmp", "r2", "r4")] = 355;
	codigo[command("cmp", "r3", "r0")] = 356;
	codigo[command("cmp", "r3", "r1")] = 357;
	codigo[command("cmp", "r3", "r2")] = 358;
	codigo[command("cmp", "r3", "r3")] = 359;
	codigo[command("cmp", "r3", "r4")] = 360;
	codigo[command("cmp", "r4", "r0")] = 361;
	codigo[command("cmp", "r4", "r1")] = 362;
	codigo[command("cmp", "r4", "r2")] = 363;
	codigo[command("cmp", "r4", "r3")] = 364;
	codigo[command("cmp", "r4", "r4")] = 365;
	codigo[command("cmp", "r0", "(r0)")] = 366;
	codigo[command("cmp", "r0", "(r1)")] = 367;
	codigo[command("cmp", "r0", "(r2)")] = 368;
	codigo[command("cmp", "r0", "(r3)")] = 369;
	codigo[command("cmp", "r0", "(r4)")] = 370;
	codigo[command("cmp", "r1", "(r0)")] = 371;
	codigo[command("cmp", "r1", "(r1)")] = 372;
	codigo[command("cmp", "r1", "(r2)")] = 373;
	codigo[command("cmp", "r1", "(r3)")] = 374;
	codigo[command("cmp", "r1", "(r4)")] = 375;
	codigo[command("cmp", "r2", "(r0)")] = 376;
	codigo[command("cmp", "r2", "(r1)")] = 377;
	codigo[command("cmp", "r2", "(r2)")] = 378;
	codigo[command("cmp", "r2", "(r3)")] = 379;
	codigo[command("cmp", "r2", "(r4)")] = 380;
	codigo[command("cmp", "r3", "(r0)")] = 381;
	codigo[command("cmp", "r3", "(r1)")] = 382;
	codigo[command("cmp", "r3", "(r2)")] = 383;
	codigo[command("cmp", "r3", "(r3)")] = 384;
	codigo[command("cmp", "r3", "(r4)")] = 385;
	codigo[command("cmp", "r4", "(r0)")] = 386;
	codigo[command("cmp", "r4", "(r1)")] = 387;
	codigo[command("cmp", "r4", "(r2)")] = 388;
	codigo[command("cmp", "r4", "(r3)")] = 389;
	codigo[command("cmp", "r4", "(r4)")] = 390;
	codigo[command("cmp", "(r0)", "r0")] = 391;
	codigo[command("cmp", "(r0)", "r1")] = 392;
	codigo[command("cmp", "(r0)", "r2")] = 393;
	codigo[command("cmp", "(r0)", "r3")] = 394;
	codigo[command("cmp", "(r0)", "r4")] = 395;
	codigo[command("cmp", "(r1)", "r0")] = 396;
	codigo[command("cmp", "(r1)", "r1")] = 397;
	codigo[command("cmp", "(r1)", "r2")] = 398;
	codigo[command("cmp", "(r1)", "r3")] = 399;
	codigo[command("cmp", "(r1)", "r4")] = 400;
	codigo[command("cmp", "(r2)", "r0")] = 401;
	codigo[command("cmp", "(r2)", "r1")] = 402;
	codigo[command("cmp", "(r2)", "r2")] = 403;
	codigo[command("cmp", "(r2)", "r3")] = 404;
	codigo[command("cmp", "(r2)", "r4")] = 405;
	codigo[command("cmp", "(r3)", "r0")] = 406;
	codigo[command("cmp", "(r3)", "r1")] = 407;
	codigo[command("cmp", "(r3)", "r2")] = 408;
	codigo[command("cmp", "(r3)", "r3")] = 409;
	codigo[command("cmp", "(r3)", "r4")] = 410;
	codigo[command("cmp", "(r4)", "r0")] = 411;
	codigo[command("cmp", "(r4)", "r1")] = 412;
	codigo[command("cmp", "(r4)", "r2")] = 413;
	codigo[command("cmp", "(r4)", "r3")] = 414;
	codigo[command("cmp", "(r4)", "r4")] = 415;
	codigo[command("cmp", "(r0)", "(r0)")] = 416;
	codigo[command("cmp", "(r0)", "(r1)")] = 417;
	codigo[command("cmp", "(r0)", "(r2)")] = 418;
	codigo[command("cmp", "(r0)", "(r3)")] = 419;
	codigo[command("cmp", "(r0)", "(r4)")] = 420;
	codigo[command("cmp", "(r1)", "(r0)")] = 421;
	codigo[command("cmp", "(r1)", "(r1)")] = 422;
	codigo[command("cmp", "(r1)", "(r2)")] = 423;
	codigo[command("cmp", "(r1)", "(r3)")] = 424;
	codigo[command("cmp", "(r1)", "(r4)")] = 425;
	codigo[command("cmp", "(r2)", "(r0)")] = 426;
	codigo[command("cmp", "(r2)", "(r1)")] = 427;
	codigo[command("cmp", "(r2)", "(r2)")] = 428;
	codigo[command("cmp", "(r2)", "(r3)")] = 429;
	codigo[command("cmp", "(r2)", "(r4)")] = 430;
	codigo[command("cmp", "(r3)", "(r0)")] = 431;
	codigo[command("cmp", "(r3)", "(r1)")] = 432;
	codigo[command("cmp", "(r3)", "(r2)")] = 433;
	codigo[command("cmp", "(r3)", "(r3)")] = 434;
	codigo[command("cmp", "(r3)", "(r4)")] = 435;
	codigo[command("cmp", "(r4)", "(r0)")] = 436;
	codigo[command("cmp", "(r4)", "(r1)")] = 437;
	codigo[command("cmp", "(r4)", "(r2)")] = 438;
	codigo[command("cmp", "(r4)", "(r3)")] = 439;
	codigo[command("cmp", "(r4)", "(r4)")] = 440;
	codigo[command("and", "#const", "r0")] = 441;
	codigo[command("and", "#const", "r1")] = 442;
	codigo[command("and", "#const", "r2")] = 443;
	codigo[command("and", "#const", "r3")] = 444;
	codigo[command("and", "#const", "r4")] = 445;
	codigo[command("and", "#const", "(r0)")] = 446;
	codigo[command("and", "#const", "(r1)")] = 447;
	codigo[command("and", "#const", "(r2)")] = 448;
	codigo[command("and", "#const", "(r3)")] = 449;
	codigo[command("and", "#const", "(r4)")] = 450;
	codigo[command("and", "r0", "r0")] = 451;
	codigo[command("and", "r0", "r1")] = 452;
	codigo[command("and", "r0", "r2")] = 453;
	codigo[command("and", "r0", "r3")] = 454;
	codigo[command("and", "r0", "r4")] = 455;
	codigo[command("and", "r1", "r0")] = 456;
	codigo[command("and", "r1", "r1")] = 457;
	codigo[command("and", "r1", "r2")] = 458;
	codigo[command("and", "r1", "r3")] = 459;
	codigo[command("and", "r1", "r4")] = 460;
	codigo[command("and", "r2", "r0")] = 461;
	codigo[command("and", "r2", "r1")] = 462;
	codigo[command("and", "r2", "r2")] = 463;
	codigo[command("and", "r2", "r3")] = 464;
	codigo[command("and", "r2", "r4")] = 465;
	codigo[command("and", "r3", "r0")] = 466;
	codigo[command("and", "r3", "r1")] = 467;
	codigo[command("and", "r3", "r2")] = 468;
	codigo[command("and", "r3", "r3")] = 469;
	codigo[command("and", "r3", "r4")] = 470;
	codigo[command("and", "r4", "r0")] = 471;
	codigo[command("and", "r4", "r1")] = 472;
	codigo[command("and", "r4", "r2")] = 473;
	codigo[command("and", "r4", "r3")] = 474;
	codigo[command("and", "r4", "r4")] = 475;
	codigo[command("and", "r0", "(r0)")] = 476;
	codigo[command("and", "r0", "(r1)")] = 477;
	codigo[command("and", "r0", "(r2)")] = 478;
	codigo[command("and", "r0", "(r3)")] = 479;
	codigo[command("and", "r0", "(r4)")] = 480;
	codigo[command("and", "r1", "(r0)")] = 481;
	codigo[command("and", "r1", "(r1)")] = 482;
	codigo[command("and", "r1", "(r2)")] = 483;
	codigo[command("and", "r1", "(r3)")] = 484;
	codigo[command("and", "r1", "(r4)")] = 485;
	codigo[command("and", "r2", "(r0)")] = 486;
	codigo[command("and", "r2", "(r1)")] = 487;
	codigo[command("and", "r2", "(r2)")] = 488;
	codigo[command("and", "r2", "(r3)")] = 489;
	codigo[command("and", "r2", "(r4)")] = 490;
	codigo[command("and", "r3", "(r0)")] = 491;
	codigo[command("and", "r3", "(r1)")] = 492;
	codigo[command("and", "r3", "(r2)")] = 493;
	codigo[command("and", "r3", "(r3)")] = 494;
	codigo[command("and", "r3", "(r4)")] = 495;
	codigo[command("and", "r4", "(r0)")] = 496;
	codigo[command("and", "r4", "(r1)")] = 497;
	codigo[command("and", "r4", "(r2)")] = 498;
	codigo[command("and", "r4", "(r3)")] = 499;
	codigo[command("and", "r4", "(r4)")] = 500;
	codigo[command("and", "(r0)", "r0")] = 501;
	codigo[command("and", "(r0)", "r1")] = 502;
	codigo[command("and", "(r0)", "r2")] = 503;
	codigo[command("and", "(r0)", "r3")] = 504;
	codigo[command("and", "(r0)", "r4")] = 505;
	codigo[command("and", "(r1)", "r0")] = 506;
	codigo[command("and", "(r1)", "r1")] = 507;
	codigo[command("and", "(r1)", "r2")] = 508;
	codigo[command("and", "(r1)", "r3")] = 509;
	codigo[command("and", "(r1)", "r4")] = 510;
	codigo[command("and", "(r2)", "r0")] = 511;
	codigo[command("and", "(r2)", "r1")] = 512;
	codigo[command("and", "(r2)", "r2")] = 513;
	codigo[command("and", "(r2)", "r3")] = 514;
	codigo[command("and", "(r2)", "r4")] = 515;
	codigo[command("and", "(r3)", "r0")] = 516;
	codigo[command("and", "(r3)", "r1")] = 517;
	codigo[command("and", "(r3)", "r2")] = 518;
	codigo[command("and", "(r3)", "r3")] = 519;
	codigo[command("and", "(r3)", "r4")] = 520;
	codigo[command("and", "(r4)", "r0")] = 521;
	codigo[command("and", "(r4)", "r1")] = 522;
	codigo[command("and", "(r4)", "r2")] = 523;
	codigo[command("and", "(r4)", "r3")] = 524;
	codigo[command("and", "(r4)", "r4")] = 525;
	codigo[command("and", "(r0)", "(r0)")] = 526;
	codigo[command("and", "(r0)", "(r1)")] = 527;
	codigo[command("and", "(r0)", "(r2)")] = 528;
	codigo[command("and", "(r0)", "(r3)")] = 529;
	codigo[command("and", "(r0)", "(r4)")] = 530;
	codigo[command("and", "(r1)", "(r0)")] = 531;
	codigo[command("and", "(r1)", "(r1)")] = 532;
	codigo[command("and", "(r1)", "(r2)")] = 533;
	codigo[command("and", "(r1)", "(r3)")] = 534;
	codigo[command("and", "(r1)", "(r4)")] = 535;
	codigo[command("and", "(r2)", "(r0)")] = 536;
	codigo[command("and", "(r2)", "(r1)")] = 537;
	codigo[command("and", "(r2)", "(r2)")] = 538;
	codigo[command("and", "(r2)", "(r3)")] = 539;
	codigo[command("and", "(r2)", "(r4)")] = 540;
	codigo[command("and", "(r3)", "(r0)")] = 541;
	codigo[command("and", "(r3)", "(r1)")] = 542;
	codigo[command("and", "(r3)", "(r2)")] = 543;
	codigo[command("and", "(r3)", "(r3)")] = 544;
	codigo[command("and", "(r3)", "(r4)")] = 545;
	codigo[command("and", "(r4)", "(r0)")] = 546;
	codigo[command("and", "(r4)", "(r1)")] = 547;
	codigo[command("and", "(r4)", "(r2)")] = 548;
	codigo[command("and", "(r4)", "(r3)")] = 549;
	codigo[command("and", "(r4)", "(r4)")] = 550;
	codigo[command("or", "#const", "r0")] = 551;
	codigo[command("or", "#const", "r1")] = 552;
	codigo[command("or", "#const", "r2")] = 553;
	codigo[command("or", "#const", "r3")] = 554;
	codigo[command("or", "#const", "r4")] = 555;
	codigo[command("or", "#const", "(r0)")] = 556;
	codigo[command("or", "#const", "(r1)")] = 557;
	codigo[command("or", "#const", "(r2)")] = 558;
	codigo[command("or", "#const", "(r3)")] = 559;
	codigo[command("or", "#const", "(r4)")] = 560;
	codigo[command("or", "r0", "r0")] = 561;
	codigo[command("or", "r0", "r1")] = 562;
	codigo[command("or", "r0", "r2")] = 563;
	codigo[command("or", "r0", "r3")] = 564;
	codigo[command("or", "r0", "r4")] = 565;
	codigo[command("or", "r1", "r0")] = 566;
	codigo[command("or", "r1", "r1")] = 567;
	codigo[command("or", "r1", "r2")] = 568;
	codigo[command("or", "r1", "r3")] = 569;
	codigo[command("or", "r1", "r4")] = 570;
	codigo[command("or", "r2", "r0")] = 571;
	codigo[command("or", "r2", "r1")] = 572;
	codigo[command("or", "r2", "r2")] = 573;
	codigo[command("or", "r2", "r3")] = 574;
	codigo[command("or", "r2", "r4")] = 575;
	codigo[command("or", "r3", "r0")] = 576;
	codigo[command("or", "r3", "r1")] = 577;
	codigo[command("or", "r3", "r2")] = 578;
	codigo[command("or", "r3", "r3")] = 579;
	codigo[command("or", "r3", "r4")] = 580;
	codigo[command("or", "r4", "r0")] = 581;
	codigo[command("or", "r4", "r1")] = 582;
	codigo[command("or", "r4", "r2")] = 583;
	codigo[command("or", "r4", "r3")] = 584;
	codigo[command("or", "r4", "r4")] = 585;
	codigo[command("or", "r0", "(r0)")] = 586;
	codigo[command("or", "r0", "(r1)")] = 587;
	codigo[command("or", "r0", "(r2)")] = 588;
	codigo[command("or", "r0", "(r3)")] = 589;
	codigo[command("or", "r0", "(r4)")] = 590;
	codigo[command("or", "r1", "(r0)")] = 591;
	codigo[command("or", "r1", "(r1)")] = 592;
	codigo[command("or", "r1", "(r2)")] = 593;
	codigo[command("or", "r1", "(r3)")] = 594;
	codigo[command("or", "r1", "(r4)")] = 595;
	codigo[command("or", "r2", "(r0)")] = 596;
	codigo[command("or", "r2", "(r1)")] = 597;
	codigo[command("or", "r2", "(r2)")] = 598;
	codigo[command("or", "r2", "(r3)")] = 599;
	codigo[command("or", "r2", "(r4)")] = 600;
	codigo[command("or", "r3", "(r0)")] = 601;
	codigo[command("or", "r3", "(r1)")] = 602;
	codigo[command("or", "r3", "(r2)")] = 603;
	codigo[command("or", "r3", "(r3)")] = 604;
	codigo[command("or", "r3", "(r4)")] = 605;
	codigo[command("or", "r4", "(r0)")] = 606;
	codigo[command("or", "r4", "(r1)")] = 607;
	codigo[command("or", "r4", "(r2)")] = 608;
	codigo[command("or", "r4", "(r3)")] = 609;
	codigo[command("or", "r4", "(r4)")] = 610;
	codigo[command("or", "(r0)", "r0")] = 611;
	codigo[command("or", "(r0)", "r1")] = 612;
	codigo[command("or", "(r0)", "r2")] = 613;
	codigo[command("or", "(r0)", "r3")] = 614;
	codigo[command("or", "(r0)", "r4")] = 615;
	codigo[command("or", "(r1)", "r0")] = 616;
	codigo[command("or", "(r1)", "r1")] = 617;
	codigo[command("or", "(r1)", "r2")] = 618;
	codigo[command("or", "(r1)", "r3")] = 619;
	codigo[command("or", "(r1)", "r4")] = 620;
	codigo[command("or", "(r2)", "r0")] = 621;
	codigo[command("or", "(r2)", "r1")] = 622;
	codigo[command("or", "(r2)", "r2")] = 623;
	codigo[command("or", "(r2)", "r3")] = 624;
	codigo[command("or", "(r2)", "r4")] = 625;
	codigo[command("or", "(r3)", "r0")] = 626;
	codigo[command("or", "(r3)", "r1")] = 627;
	codigo[command("or", "(r3)", "r2")] = 628;
	codigo[command("or", "(r3)", "r3")] = 629;
	codigo[command("or", "(r3)", "r4")] = 630;
	codigo[command("or", "(r4)", "r0")] = 631;
	codigo[command("or", "(r4)", "r1")] = 632;
	codigo[command("or", "(r4)", "r2")] = 633;
	codigo[command("or", "(r4)", "r3")] = 634;
	codigo[command("or", "(r4)", "r4")] = 635;
	codigo[command("or", "(r0)", "(r0)")] = 636;
	codigo[command("or", "(r0)", "(r1)")] = 637;
	codigo[command("or", "(r0)", "(r2)")] = 638;
	codigo[command("or", "(r0)", "(r3)")] = 639;
	codigo[command("or", "(r0)", "(r4)")] = 640;
	codigo[command("or", "(r1)", "(r0)")] = 641;
	codigo[command("or", "(r1)", "(r1)")] = 642;
	codigo[command("or", "(r1)", "(r2)")] = 643;
	codigo[command("or", "(r1)", "(r3)")] = 644;
	codigo[command("or", "(r1)", "(r4)")] = 645;
	codigo[command("or", "(r2)", "(r0)")] = 646;
	codigo[command("or", "(r2)", "(r1)")] = 647;
	codigo[command("or", "(r2)", "(r2)")] = 648;
	codigo[command("or", "(r2)", "(r3)")] = 649;
	codigo[command("or", "(r2)", "(r4)")] = 650;
	codigo[command("or", "(r3)", "(r0)")] = 651;
	codigo[command("or", "(r3)", "(r1)")] = 652;
	codigo[command("or", "(r3)", "(r2)")] = 653;
	codigo[command("or", "(r3)", "(r3)")] = 654;
	codigo[command("or", "(r3)", "(r4)")] = 655;
	codigo[command("or", "(r4)", "(r0)")] = 656;
	codigo[command("or", "(r4)", "(r1)")] = 657;
	codigo[command("or", "(r4)", "(r2)")] = 658;
	codigo[command("or", "(r4)", "(r3)")] = 659;
	codigo[command("or", "(r4)", "(r4)")] = 660;
	codigo[command("not", "r0")] = 661;
	codigo[command("not", "r1")] = 662;
	codigo[command("not", "r2")] = 663;
	codigo[command("not", "r3")] = 664;
	codigo[command("not", "r4")] = 665;
	codigo[command("not", "(r0)")] = 666;
	codigo[command("not", "(r1)")] = 667;
	codigo[command("not", "(r2)")] = 668;
	codigo[command("not", "(r3)")] = 669;
	codigo[command("not", "(r4)")] = 670;
	codigo[command("clr", "r0")] = 671;
	codigo[command("clr", "r1")] = 672;
	codigo[command("clr", "r2")] = 673;
	codigo[command("clr", "r3")] = 674;
	codigo[command("clr", "r4")] = 675;
	codigo[command("clr", "(r0)")] = 676;
	codigo[command("clr", "(r1)")] = 677;
	codigo[command("clr", "(r2)")] = 678;
	codigo[command("clr", "(r3)")] = 679;
	codigo[command("clr", "(r4)")] = 680;
	codigo[command("neg", "r0")] = 681;
	codigo[command("neg", "r1")] = 682;
	codigo[command("neg", "r2")] = 683;
	codigo[command("neg", "r3")] = 684;
	codigo[command("neg", "r4")] = 685;
	codigo[command("neg", "(r0)")] = 686;
	codigo[command("neg", "(r1)")] = 687;
	codigo[command("neg", "(r2)")] = 688;
	codigo[command("neg", "(r3)")] = 689;
	codigo[command("neg", "(r4)")] = 690;
	codigo[command("sh", "l", "r0")] = 691;
	codigo[command("sh", "l", "r1")] = 692;
	codigo[command("sh", "l", "r2")] = 693;
	codigo[command("sh", "l", "r3")] = 694;
	codigo[command("sh", "l", "r4")] = 695;
	codigo[command("sh", "l", "(r0)")] = 696;
	codigo[command("sh", "l", "(r1)")] = 697;
	codigo[command("sh", "l", "(r2)")] = 698;
	codigo[command("sh", "l", "(r3)")] = 699;
	codigo[command("sh", "l", "(r4)")] = 700;
	codigo[command("sh", "r", "r0")] = 701;
	codigo[command("sh", "r", "r1")] = 702;
	codigo[command("sh", "r", "r2")] = 703;
	codigo[command("sh", "r", "r3")] = 704;
	codigo[command("sh", "r", "r4")] = 705;
	codigo[command("sh", "r", "(r0)")] = 706;
	codigo[command("sh", "r", "(r1)")] = 707;
	codigo[command("sh", "r", "(r2)")] = 708;
	codigo[command("sh", "r", "(r3)")] = 709;
	codigo[command("sh", "r", "(r4)")] = 710;
	codigo[command("br", "z", "#label")] = 711;
	codigo[command("br", "n", "#label")] = 712;
	codigo[command("br", "e", "#label")] = 713;
	codigo[command("br", "l", "#label")] = 714;
	codigo[command("br", "g", "#label")] = 715;
	codigo[command("br", "c", "#label")] = 716;
	codigo[command("brz", "#label")] = 711;
	codigo[command("brn", "#label")] = 712;
	codigo[command("bre", "#label")] = 713;
	codigo[command("brl", "#label")] = 714;
	codigo[command("brg", "#label")] = 715;
	codigo[command("brc", "#label")] = 716;
	codigo[command("jmp", "#label")] = 717;
	codigo[command("halt")] = 718;
}

// Carrega os comandos do assembly na memória.
void Parser::parse (void)
{
	// Vão receber as strings na entrada. São muito grandes porque eu sou neurótico.
	char comando[2048];
	char fonte[1024], destino[1024];

	// Vão ser usadas para acessar os maps, fazer comparações entre outros. Substituem os char pointers.
	string cmm, src, dst;

	// Ajudarão com as labels.
	map<string,int> label_to_come;
	vector<int> pos[MAX_LABELS];

	fscanf (entrada, " %s", comando);
	while (!feof(entrada))
	{
		// Testa se o que foi lido é o começo de um comentário. Se for ignora tudo até o fim da linha.
		if (comando[0] == '#')
		{
			while (getc(entrada) != '\n' && !feof(entrada));
			fscanf (entrada, " %s", comando);
			continue;
		}

		// Testa se o que foi lido é uma label. Se for coloca a label no map e tenta ler um comando.
		if (comando[strlen(comando)-1] == ':')
		{
			comando[strlen(comando)-1] = '\0';

			if (label.find(comando) != label.end())
			{
				for (int i = 0; i < (int) pos[label_to_come[comando]].size(); i++)
				{
					mem->acesso(true, pos[label_to_come[comando]][i], posAtual);
				}
			}

			label[comando] = posAtual;

			fscanf (entrada, " %s", comando);
			continue;
		}

		cmm = comando;
		for (int i = 0; i < (int) cmm.size(); i++) cmm[i] = tolower(cmm[i]);

		// O if mais externo testa quantos operandos são esperados para a operação.
		if (nop[cmm] == 2)
		{
			bool has_const = false;		// Vai dizer se há um operando constante que deve ser colocado na memória.
			int operando_constante;		// Vai guardar o valor do operando constante a ser colocado na memória. 

			fscanf (entrada, " %s", fonte);
			if (fonte[strlen(fonte) - 1] == ',')
			{
				fonte[strlen(fonte) - 1] = '\0';
				fscanf (entrada, " %s", destino);
			}
			else
			{
				int i;

				for (i = 0; fonte[i] != ','; i++);
				fonte[i] = '\0';
				sscanf (fonte + i + 1, " %s", destino);
			}

			src = fonte;
			dst = destino;

			// Testa se a fonte é uma constante. Se for seta o bool has_const e transforma src em #const para poder identificar a instrução.
			if (src[0] >= '0' && src[0] <= '9')
			{
				// Operando constante em hexadecimal ou em decimal.
				if (src.find("0x") != string::npos)
				{
					sscanf (src.c_str(), "%x", &operando_constante);
				}
				else
				{
					sscanf (src.c_str(), "%d", &operando_constante);
				}
				
				src = "#const";

				has_const = true;
			}
			
			// No caso da operação br é certo que há uma label como operando destino. Trata isso.
			if (cmm == "br")
			{
				operando_constante = label[dst];
				
				dst = "#label";

				has_const = true;
			}
			
			for (int i = 0; i < (int) src.size(); i++) src[i] = tolower(src[i]);	// Converte o operando fonte para lower case.
			for (int i = 0; i < (int) dst.size(); i++) dst[i] = tolower(dst[i]);	// Converte o operando destino para lower case.
			mem->acesso(1, posAtual, codigo[command(cmm, src, dst)]);	// Joga para a memória o código da operação.

			// Se houver operando constante coloca na memória.
			if (has_const)
			{
				posAtual++;
				mem->acesso(1, posAtual, operando_constante);
			}
		}
		else if (nop[cmm] == 1)
		{
			bool has_const = false;		// Vai dizer se há um operando constante que deve ser colocado na memória.
			int operando_constante;		// Vai guardar o valor do operando constante a ser colocado na memória. 

			fscanf (entrada, " %s", fonte);
			
			src = fonte;

			// Trata labels no operando fonte.
			if (cmm == "jmp" || cmm == "brz" || cmm == "brn" || cmm == "bre" || cmm == "brl" || cmm == "brg" || cmm == "brc")
			{
				if (label.find(src) == label.end() || (label.find(src) != label.end() && label[src] == -1))
				{
					label_to_come[src] = label_to_come.size();
					label[src] = -1;
					pos[label_to_come[src]].push_back(posAtual + 1);
				}

				operando_constante = label[src];
				
				src = "#label";

				has_const = true;
			}
			
			// Testa se a fonte é uma constante. Se for seta o bool has_const e transforma src em #const para poder identificar a instrução.
			if (src[0] >= '0' && src[0] <= '9')
			{
				// Operando constante em hexadecimal ou em decimal.
				if (src.find("0x") != string::npos)
				{
					sscanf (src.c_str(), "%x", &operando_constante);
				}
				else
				{
					sscanf (src.c_str(), "%d", &operando_constante);
				}
				
				src = "#const";

				has_const = true;
			}
			
			for (int i = 0; i < (int) src.size(); i++) src[i] = tolower(src[i]);	// Converte o operando fonte para lower case.
			mem->acesso(1, posAtual, codigo[command(cmm, src)]);	// Joga para a memória o código da operação.

			// Se houver operando constante coloca na memória.
			if (has_const)
			{
				posAtual++;
				mem->acesso(true, posAtual, operando_constante);
			}
		}
		else
		{
			mem->acesso(true, posAtual, codigo[command(cmm)]);	// Joga para a memória o código da operação.
		}

		posAtual++;
		while (getc(entrada) != '\n' && !feof(entrada));	// Lê o que restar até o fim da linha.

		fscanf (entrada, " %s", comando);
	}
}
