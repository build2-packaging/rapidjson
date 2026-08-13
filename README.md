# rapidjson - build2 packages

This is a `build2` package repository for [RapidJSON](https://github.com/Tencent/rapidjson),
a fast JSON parser and generator for C++ with both SAX and DOM style APIs.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`librapidjson` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](librapidjson/PACKAGE-README.md) file.

Packages in this repository:

- `librapidjson` -- header-only library
- `librapidjson-tests` -- upstream unit tests (depends on `gtest`)

Upstream is imported as a `git` submodule in `upstream/`, currently pinned to
commit `24b5e7a` (2025-02-05). The same commit is what vcpkg ships as
`2025-02-26`. To move to a newer snapshot:

```
cd upstream
git fetch
git checkout <commit>
cd ..
git add upstream
git commit -m "Update upstream submodule to <commit>"
```

The development setup for this repository uses the standard `bdep`-based
workflow. For example:

```
git clone --recurse-submodules .../rapidjson.git
cd rapidjson

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```
