
How to write tests
---
- If it's a new feature X.
  1. create a directory for feature X.
  2. cd into directory.
  3. Create a Makefile and include Makefile.mk from the parent directory.
  4. Create a rule called `run` with a dependency called `link`.(ie run: link)
  5. Define your tests cases inside the rule `run`.
  6. Call this Makefile from the parent directory in the rule `tests`
- If it's an already created feature.
  1. Just read the Makefiles, either way should read them.

## NOTE
The file Makefile.mk is the base Makefile used to compile all tests files.
It's meant to be included into Makefiles inside feature directories. See
load/Makefile for a better picture

