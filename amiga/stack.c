/* A Shell gives 4 KB of stack; libnix's startup sets this much up instead.
 * The AmiCradle Team. GPL 3 or later, like Ballerburg. */
unsigned long __stack = 256 * 1024;
static const char version[] __attribute__((used)) = "$VER: Ballerburg 1.2.2 Amiga (06.11.2026)";
