# cuemslogger

Part of the **CUEMS** ecosystem — see the [`cuems-RELATIONS`](https://github.com/stagesoft/cuems-RELATIONS) repo for the system index, architecture diagram, and protocol/port map.

## Role

C++ syslog wrapper class (`cuemslogger_class`) for the CUEMS system. Added as a **git submodule** and compiled with its parent — vendored inside the C++ players (`cuems-dmxplayer`, `cuems-audioplayer`, …). Emits to syslog with a per-process ident like `Cuems:d<uuid>` (facility LOCAL0).

**Practical note:** CuemsLogger lines (e.g. MTC events) go to the syslog **ident slug**, whereas a player's plain `stdout` (e.g. dmxplayer `set channels` / `holding`) lands in the spawning node-engine's "Subprocess output" journal — grep the right stream for the right signal. See the dmxplayer CLAUDE.md diagnostics note.

**Operate on the top-level checkout, never the nested submodule copies** inside the players (a commit there would also dirty the parent's submodule pointer).
