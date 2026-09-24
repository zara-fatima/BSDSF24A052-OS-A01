## Feature 2 — Multi-file Build

**1. $(TARGET): $(OBJECTS) rule:**
This rule links all the .o object files directly together to create the final
executable. It differs from a library-based rule because it doesn't use -L or -l
flags — it just lists every object file that needs to be linked. A library-based
rule instead links against a pre-built .a or .so file using -lmyutils, so you
don't need to recompile all source files every time, only the parts that changed.

**2. What is a git tag, and annotated vs simple tag:**
A git tag marks a specific commit as an important point in history, usually a
release version. It's useful because it lets you go back to or reference that
exact version later. An annotated tag stores extra metadata (author, date,
message) and is a full object in git's database, while a simple/lightweight tag
is just a name pointing directly at a commit with no extra info.

**3. Purpose of a GitHub Release and attaching binaries:**
A Release packages a specific tagged version of the project in a user-friendly
way on GitHub, with release notes describing what changed. Attaching binaries
(like the compiled client executable) lets users download a ready-to-run
program without needing to have the source code, a compiler, or build tools
themselves.
