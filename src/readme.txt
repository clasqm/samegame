Qt implementation of SameGame

    SameGame is a puzzle game for Linux and Windows. The rules of the game are as follows:

        1. You may remove pieces provided at least two are adjacent either horizontally or vertically.
        2. Let n = number of removed pieces. Then score += (n-1)².
        3. If you remove all pieces, your score will be doubled.
        4. The game ends when you have removed all pieces or there are no removable pieces.

AUTHORS

    Jari Karppinen <jari.p.karppinen at, gmail.com>

COPYING

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

INSTALL

    To build the sources, you need CMake (3.16 or later) and the Qt5 development
    files (Qt5 Core, Gui and Widgets). First check out the source:

        git clone https://github.com/clasqm/samegame.git

    Then build using CMake:

        1. cmake -S . -B build
        2. cmake --build build
        3. cmake --install build          (as root, or set CMAKE_INSTALL_PREFIX)

URL

    The project is hosted at Sourceforge, visit:

        http://samegame.sourceforge.net/
