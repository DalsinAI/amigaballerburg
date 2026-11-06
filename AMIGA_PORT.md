Ballerburg 1.2.2 for AmigaOS 3.x
================================

Ballerburg (Eckhard Kruse's 1987 Atari ST game, brought to SDL by Thomas
Huth, https://framagit.org/baller/ballerburg), the castle artillery duel: two kings
on either side of a mountain fire cannons at each other's castle, buy
powder, cannonballs and new cannons with their taxes, and build their
walls again, until one king is hit or gives up. Two players, one against
the computer, or two computer players. For AmigaOS 3.x on a 68040 or 68060
with an FPU and an RTG screen, on OpenGPU's SDL 2.

Base: ballerburg_1.2.2.orig.tar.gz from Debian (sha256
8e001efa44b70a9a51041a6ce39a2b01d9d3135d2ec54ca54196fc34f164914e).
Debian's two patches only point the data and the translations at
/usr/share, so they are left out. Branch team2/ballerburg-amiga.

Status: plays in the lab (Instance-45 on GFOpenUp 0.8.19, 6 November
2026): round 1 with both castles, the cannon dialog (angle and powder) and
a shot fired, the settings (Escape) with player 2 made the computer, its
shot and round 2, then Exit program with its question back to the Shell.
The lab is muted, so the tune and the sound were not heard there.


What you need
-------------

- A 68040 or 68060 with an FPU, AmigaOS 3.x, an RTG card (or the
  AmigaChrome lab).
- GFOpenUp 0.8.18 or later (LIBS:OpenGPU/SDL2.module). Everything else is
  in the program.


How to play
-----------

Open the Ballerburg icon, or run Ballerburg from a Shell. It opens a
640x480 window. Click your own cannon to aim and fire it, and the other
parts of your castle to buy or build; Done ends your turn. Escape opens
the settings: names, human or computer for each side, the computer's
strategy and strength, the number of rounds, new game and Exit program.
manual.html (and the German anleitung.html) in the drawer has all the
rules. The castles and the tune are in the drawer's data/.


Building
--------

    make -f amiga/Makefile.amigaos dist

with GFOpenAmigaGCC 16.2.0-open4 and the OpenGPU kit (see the Makefile's
head). The drawer is dist/Ballerburg (and dist/Ballerburg.info).


What was changed
----------------

- src/paths.c: on AmigaOS the data directory is PROGDIR:data, where
  baller.dat and baller.mus are (upstream works it out from the
  program's place and ../share/ballerburg).
- amiga/Makefile.amigaos builds src/CMakeLists.txt's sources for SDL 2
  (WITH_SDL2, as CMake does when it finds SDL 2), with amiga/config.h for
  CMake's; no gettext, so the game is in English. amiga/stack.c: 256 KB of
  stack.


Licences
--------

Ballerburg: GPL 3 or later (COPYING.txt). The Amiga files (amiga/): GPL 3
or later, the AmiCradle Team; the icon is Debian's ballerburg.xpm (GPL 2 or
later).
