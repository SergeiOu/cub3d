# Handover notes for the team

Everything one of us needs to know about the other's work before the
evaluation. Read this once, then read the code it points to: either of us can
be asked about any file.

## Where the project stands

All mandatory features are implemented and tested. No bonus was attempted.

| Area | Written by |
| --- | --- |
| Parsing, validation, init (`src/parsing/`, `src/initialization/`) | mfassad |
| Window, events, textures, camera, raycaster, movement, rendering | sounania, with Claude Code (AI assistant) |
| Makefile, `cub3d.h` | started by mfassad, extended by sounania |

The README states which parts AI helped with. Keep it accurate if anything
changes.

## What changed in the parsing files

The parsing logic and structure are unchanged. Six files got small edits to
make it tolerate harmless formatting that public testers use. Review them with
`git log -p -- <file>`.

| File | Change | Why |
| --- | --- | --- |
| `src/parsing/identify_line.c` | New `skip_indent`; `NO/SO/WE/EA/F/C` are recognised after leading spaces | `   WE   path` was rejected |
| `src/parsing/parse_texture.c` | Path start skips the indent; trailing spaces after the path are trimmed | `NO path   ` looked for a file named with spaces |
| `src/parsing/parse_color.c` | `parse_rgb` skips the indent before the identifier | `   F 1,2,3` was rejected |
| `src/parsing/parse_file_utils.c` | `handle_map` accepts empty lines once the map has started | Trailing blank line after the map was rejected |
| `src/parsing/parse_file.c` | New `map_has_no_gap`: an empty line inside the map is still an error | Keeps blank-line-in-map invalid |
| `src/parsing/store_map.c` | Trailing empty lines are not stored; width counts only real rows | Same trailing-line case |
| `src/main.c` | Split into `check_args`, `init_game`, `main` (Norm: 25 lines) | Norm |

Still rejected: a duplicate or missing element, an unknown line, a bad colour,
a non-`.xpm` or unopenable texture, a gap inside the map, text after the map,
no player, several players, and any open walkable cell.

## The map-closure rule (decide and be consistent)

`validate_map` rejects the map if **any** `0` or player cell has a space or
the outside as an up/down/left/right neighbour, even if the player cannot
reach it. This is deliberate. Some public testers flood-fill from the player
and accept an unreachable open pocket; we do not. If an evaluator disagrees,
the answer is that the subject says the map must be closed.

## The project layout

Everything is at the repository root. An old copy under `cub3d/` was removed.
`minilibx-linux/` is the school's library: never edit it, never run
norminette on it.

## How to check everything quickly

```sh
make                                   # builds; a second make must do nothing
./cub3D maps/valid/valid_map.cub       # walk around; ESC quits
for f in maps/invalid/*.cub; do ./cub3D $f >/dev/null 2>&1; echo -n "$? "; done; echo   # all 1
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./cub3D maps/valid/valid_map.cub   # ESC to quit
norminette src includes get_next_line libft
```

Under valgrind the game runs about 30 times slower (about 3 fps). That is
normal. Quit with ESC so everything is freed.

Test maps: `maps/valid/` (12, including `spawn_north/south/east/west.cub`) and
`maps/invalid/` (25). The public testers we ran are linked in the next
section.

## Test results on the final code

- Own maps: 12 of 12 valid open a window; 25 of 25 invalid exit 1 with
  `Error` and a message. All 25 invalid maps run clean under valgrind.
- [humblEgo/cub3D_map_tester](https://github.com/humblEgo/cub3D_map_tester):
  57 of 57 invalid rejected, valid control accepted.
- [mcombeau/cub3D](https://github.com/mcombeau/cub3D) maps: 44 of 47. The
  three differences are about enclosed pockets of spaces and one unreadable
  file (rejected when run as an ordinary user).
- 600 random key events: no crash, clean exit on ESC.
- No forbidden functions, no global variables, norminette clean.

## Things each of us should be able to explain

**Parsing (mfassad's part):** why the file is read twice; how a line is
classified; what `handle_line` does in the config part versus the map part;
how `validate_map` finds the player and checks closure; why a missing texture
and a non-XPM texture are both handled.

**Everything else (sounania's part):** one ray from `camera_x` to wall
height; the DDA loop; why the distance is perpendicular; how the texture
column is chosen; how rotation and collision work; what is freed on exit and
in which order.

## Before the evaluation

- [ ] Both of us have read `src/parsing/` and `src/raycast/`, `src/render/`.
- [ ] A fresh `git clone` of the 42 repo builds and runs on a school machine.
- [ ] The README matches the subject and its AI disclosure is accurate.
- [ ] Nobody edits `minilibx-linux/`.
