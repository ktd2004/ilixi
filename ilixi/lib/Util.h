/*
 Copyright 2010-2012 Tarik Sekmen.

 All Rights Reserved.

 Written by Tarik Sekmen <tarik@ilixi.org>.

 This file is part of ilixi.

 ilixi is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 ilixi is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public License
 along with ilixi.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ILIXI_UTIL_H_
#define ILIXI_UTIL_H_

#include <string>

namespace ilixi
{

/*!
 * An algorithm produced by Professor Daniel J. Bernstein.
 */
unsigned int
createHash(const std::string& str);

/*!
 * Creates a Version 4 UUID.
 *
 * @param uuid 36 characters long.
 */
std::string
createUUID();

} /* namespace ilixi */
#endif /* ILIXI_UTIL_H_ */
