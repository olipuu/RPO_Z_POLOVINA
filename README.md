# TestSystem

Simple console testing system in C++ with categories and multiple-choice questions.

## What Is Included

- `TestSystem/TestSystem/TestSystem.vcxproj` - Visual Studio C++ project
- `TestSystem/TestSystem/categories.txt` - preloaded categories and questions
- release package with `TestSystem.exe` and `categories.txt`

## Run Ready-Made EXE

1. Open the latest release on GitHub.
2. Download the release archive.
3. Extract the archive to any folder.
4. Make sure `TestSystem.exe` and `categories.txt` stay in the same folder.
5. Run `TestSystem.exe`.

## Build In Visual Studio

1. Open `TestSystem/TestSystem.slnx` in Visual Studio.
2. Select `Release` and `x64`.
3. Build the project.
4. After the build, run the generated `TestSystem.exe`.

The build copies `categories.txt` to the output folder automatically.

## Preloaded Categories

- Animals
- Colors
- School

Each category contains 5 easy questions in English.

## Notes

- The program stores categories in `categories.txt`.
- Every question has 4 answer options.
- Correct answers are stored as zero-based indexes in the file format.
