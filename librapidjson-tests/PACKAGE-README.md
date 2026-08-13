# librapidjson-tests - Tests for the RapidJSON C++ library

This is a `build2` package for the [RapidJSON](https://github.com/Tencent/rapidjson)
upstream unit tests and performance tests. It is pulled in automatically when
testing `librapidjson` (`tests: librapidjson-tests == $`).

The JSON-licensed `bin/jsonchecker/` corpus and `jsoncheckertest.cpp` are
omitted.


## Usage

To start using `librapidjson-tests` in your project, add the following build-time
`depends` value to your `manifest`, adjusting the version constraint as
appropriate:

```
depends: * librapidjson-tests ^1.1.0
```

Consumers of `librapidjson` do not normally depend on this package directly.
The `tests:` field on `librapidjson` is enough.

Then import the executable in your `buildfile`:

```
import unittest = librapidjson-tests%exe{unittest}
import perftest = librapidjson-tests%exe{perftest}
```


## Importable targets

This package provides the following importable targets:

```
exe{unittest}
exe{perftest}
```

`exe{unittest}` is the upstream gtest unit test executable. `exe{perftest}`
is the upstream gtest performance suite.


## Configuration variables

This package has no configuration variables.
