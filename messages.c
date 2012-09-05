/*
 * sin título.c
 * 
 * Copyright 2012 Miguel Angel Reynoso <miguel@vacteria.org>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include "messages.h"
#include "main.h"

void msg_help(void)
{
	printf(_(
		"Vacteria Package Manager Copyright 2012\n"
		"\n"
		"Usage : \n"
		" %s [arguments] [parameters]\n"
		"\n"
		"Arguments :\n"
		" -m, --mkpkg     Compress given directory in a vpm package\n"
		" -v, --verbose   Show much possible informative messages\n"
		" -s, --silent    Only show fatal errors\n"
		" -h, --help      Show this help and exit\n"
	),progname);
}
