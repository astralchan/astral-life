# Astral Life

WIP game

## Build

```
git clone https://github.com/astralchan/astral-life.git
cd astral-life
```

### Unix

On mac, install [brew](https://brew.sh) and run:

```
brew bundle
```

On linux, install the devel packages for the dependencies.

Then, run:

```
./build.sh
```

Optionally specify `--release` (default) or `--debug`.

#### vcpkg

To test vcpkg builds on unix, specify `--vcpkg`.

### Windows

Install [VS BuildTools](https://visualstudio.microsoft.com/downloads/)
and [vcpkg](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started).

Open the VS Developer Command Prompt and `cd` to the repository.

```
.\build.bat
```

Optionally specify `--release` (default) or `--debug`.

## Run

### Unix

```
./build/astral-life
```

### Windows

#### Release (default)

```
.\build\Release\astral-life.exe
```

#### Debug

```
.\build\Debug\astral-life.exe
```

## License

![gplv3-or-later](./.img/gplv3-or-later.png)

SPDX-License-Identifier: `GPL-3.0-or-later`  
Copyright (C) 2025-2025 astral

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see
<[https://www.gnu.org/licenses/](https://www.gnu.org/licenses/)>.

For more details, see [COPYING](./COPYING).

### Contact

Discord: [Astral Life](https://discord.gg/H5fyxRuW5r)
