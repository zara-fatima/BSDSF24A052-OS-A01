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
## Feature 3 — Static Library

**1. Makefile differences between Part 2 and Part 3:**
In Part 2, the Makefile linked all .o files directly into the executable using
$(TARGET): $(OBJECTS). In Part 3, the Makefile first bundles mystrfunctions.o
and myfilefunctions.o into a static library (libmyutils.a) using the ar
command, and then links main.o against that library using the -L (library
path) and -l (link library name) flags, instead of listing every object file
directly.

**2. Purpose of ar, and why ranlib is used after it:**
The ar command creates and manages archive files — it bundles multiple .o
object files into a single .a static library file. ranlib is used after ar to
generate/update an index of the symbols in the archive, which lets the linker
quickly find which object file defines which function. Modern versions of ar
with the 's' flag (ar rcs) create this index automatically, so a separate
ranlib call isn't strictly necessary in that case.

**3. Are mystrlen's symbols present in nm/readelf output on client_static?**
Yes. Running readelf -s on bin/client_static shows mystrlen as a defined FUNC
symbol inside the executable itself. This confirms that static linking copies
the actual machine code of the library functions directly into the final
executable at link time, rather than just referencing an external file. This
is why the static executable is self-contained but larger in size.

## Feature 4 — Dynamic Library

**1. What is Position-Independent Code (-fPIC), and why is it required for shared libraries:**
Position-Independent Code is machine code that can run correctly no matter
where in memory it is loaded, because it doesn't use hardcoded/absolute memory
addresses — it uses relative addressing instead. This is essential for shared
libraries because a single copy of a .so file in memory can be shared by many
different running programs at the same time, and each program may load the
library at a different memory address. Without -fPIC, the code would only
work correctly if it was always loaded at one fixed address, which isn't
possible when multiple programs share it.

**2. Difference in file size between static and dynamic clients, and why:**
client_static is self-contained: at link time, the actual compiled machine
code from libmyutils.a is copied directly into the executable, making it
larger but able to run standalone. client_dynamic only stores a reference to
libmyutils.so; the actual function code is not copied in, it is loaded from
the separate .so file at runtime by the OS loader. This is why the dynamic
executable is smaller — the difference becomes much more significant with
larger libraries, since many programs can share a single loaded copy of the
library in memory instead of each having its own copy.

**3. What is LD_LIBRARY_PATH, and why was it necessary:**
LD_LIBRARY_PATH is an environment variable that tells the dynamic loader
(ld.so) additional directories to search when looking for shared libraries at
runtime. It was necessary because libmyutils.so lives in a custom project
folder (lib/), not in one of the operating system's standard library search
paths (like /usr/lib). Without it, running client_dynamic failed with
"cannot open shared object file" because the loader didn't know where to find
the library. This shows that the dynamic loader is responsible for locating
and loading shared libraries at program startup, separately from the
compiler/linker's job at build time.
