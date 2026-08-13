# rapidjson - JSON parser/generator C++ library

This is a `build2` package repository for [RapidJSON](https://github.com/Tencent/rapidjson),
a fast JSON parser and generator for C++ with both SAX and DOM style APIs.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`rapidjson` in your `build2`-based project, then instead see the accompanying
`PACKAGE-README.md` files:

* [`librapidjson/PACKAGE-README.md`](librapidjson/PACKAGE-README.md)
* [`librapidjson-tests/PACKAGE-README.md`](librapidjson-tests/PACKAGE-README.md)

The development setup for `rapidjson` uses the standard `bdep`-based workflow.
For example:

```
git clone --recurse-submodules .../rapidjson.git
cd rapidjson

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```
