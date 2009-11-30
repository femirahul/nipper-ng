/***************************************************************************
 *   Nipper - The network infrastructure parser                            *
 *   Copyright (C) 2006 - 2008 by Ian Ventura-Whiting                      *
 *   fizz@titania.co.uk                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or     *
 *   (at your option) any later version. However, there are a number of    *
 *   exceptions listed below.                                              *
 *                                                                         *
 *   EXCEPTIONS TO THE GPL License:                                        *
 *      1. This code cannot be used as part of a commercial product. If a  *
 *         commercial license is required, contact fizz@titania.co.uk for  *
 *         licensing information.                                          *
 *      2. Any code that integrates Nipper MUST display the copyright      *
 *         information below with the programs own copyright information.  *
 *                                                                         *
 *         "Nipper Copyright (C) 2006 - 2008 by Ian Ventura-Whiting"       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.  *
 *                                                                         *
 ***************************************************************************/


// Process Domain Name
void processNameServer(char *line, struct nipperConfig *nipper)
{
	// Variables
	struct host *dnsPointer = 0;
	struct ciscoCommand command;

	// Debug
	if (nipper->debugMode == true)
	{
		printf("Name Server Line: %s\n", line);
	}

	// Create DNS Server struct
	if (nipper->ios->dns == 0)
	{
		// create struct
		nipper->ios->dns = malloc(sizeof(struct host));
		dnsPointer = nipper->ios->dns;
	}
	else
	{
		dnsPointer = nipper->ios->dns;
		while (dnsPointer->next != 0)
			dnsPointer = dnsPointer->next;
		// create struct
		dnsPointer->next = malloc(sizeof(struct host));
		dnsPointer = dnsPointer->next;
	}

	// Init
	command = splitLine(line);
	memset(dnsPointer, 0, sizeof(struct host));

	// Copy DNS server
	strncpy(dnsPointer->server, command.part[2], sizeof(dnsPointer->server) - 1);
}

