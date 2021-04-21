# DeadlockFixes
Deadlock: Planetary Conquest crashes when the user's screen resolution width is > 1280 due to an array overflow error in the game and will also crash due to a bug in the WAIL32 version that came with the game.

Using the WING32.dll file will cause Deadlock to run at a maximum width of 1280, which will prevent the array overflow error that causes the crash to occur when zooming into a territory.

The MSS32.dll came with Warcraft 3. The included WAIL32.dll is a dll that gets calls from Deadlock and forwards them on to the MSS32.dll, which doesn't cause freezing issues like the original WAIL32.dll does.

Putting these 3 files in the Deadlock folder should correct the freezing and crashing problems.

NOTE: FOR WINDOWS XP, USE THE DLLS IN THE WINDOWSXP FOLDER ALONG WITH THE MSS32.DLL. I did not include a version of WING32.dll for XP due to not being able to use the required Detours library.

The compiled DLLs have only been tested on Windows XP 32-bit and Windows 10 64-bit. If they do not work on another version, the source code has been included.
