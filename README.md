# DeadlockFixes
Deadlock: Planetary Conquest crashes on newer versions of Windows because it uses the dead api WinG and also due to some issues with the WAIL32 
dll that came with the game.

This MSS32.dll came with Warcraft 3. The included WAIL32.dll is a dll that gets calls from Deadlock and forwards them on to the MSS32.dll, which doesn't
cause freezing issues like the original WAIL32.dll does.

The WING32.dll also receives calls from the game and forwards them to functions in Windows' GDI32.dll.

Putting these 3 files in the Deadlock folder should correct the freezing and crashing problems.
