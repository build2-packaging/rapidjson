# librapidjson - JSON parser/generator C++ library

This is a `build2` package for the [RapidJSON](https://github.com/Tencent/rapidjson)
C++ library. It provides a fast, self-contained, header-only JSON parser and
generator with both SAX and DOM style APIs.

It supports UTF-8/16/32, optional SSE2/SSE4.2 and NEON acceleration, and does
not depend on STL by default.

This package tracks upstream commit `24b5e7a` (2025-02-05). Upstream still
reports `RAPIDJSON_VERSION_STRING` as `1.1.0`. The `upstream-version` manifest
field records the commit date.


## Usage

To start using `librapidjson` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: librapidjson ^1.1.0
```

Then import the library in your `buildfile`:

```
import libs = librapidjson%lib{rapidjson}
```


## Importable targets

This package provides the following importable targets:

```
lib{rapidjson}
```

This is a binless (header-only) library. Public headers are included as
`<rapidjson/document.h>` and similar. Upstream examples live in the `examples/`
subproject of this package and are built and run by `b test`. They are not
installed.


## Configuration variables

This package provides the following configuration variables:

```
[bool]   config.librapidjson.stdstring  ?= false
[bool]   config.librapidjson.membersmap ?= false
[bool]   config.librapidjson.sse2       ?= false
[bool]   config.librapidjson.sse42      ?= false
[bool]   config.librapidjson.neon       ?= false
[string] config.librapidjson.namespace  ?= [null]
```

These map to the corresponding RapidJSON preprocessor macros and are exported
to consumers:

- `stdstring` sets `RAPIDJSON_HAS_STDSTRING=1` (`std::string` helpers).
- `membersmap` sets `RAPIDJSON_USE_MEMBERSMAP=1` (object members in a
  `std::multimap`).
- `sse2`, `sse42`, and `neon` set `RAPIDJSON_SSE2`, `RAPIDJSON_SSE42`, and
  `RAPIDJSON_NEON`. SSE4.2 takes precedence over SSE2. Neon cannot be combined
  with SSE.
- `namespace` sets `RAPIDJSON_NAMESPACE` to a single identifier. Nested
  namespaces still require `RAPIDJSON_NAMESPACE_BEGIN` / `_END` in the
  consumer.

Enable a feature when configuring the dependent, for example
`config.librapidjson.stdstring=true`.
