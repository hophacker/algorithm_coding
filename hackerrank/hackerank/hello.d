import std.stdio;

class Widget { }

void main() {
    // Automatically managed.
    auto w = new Widget;
    // Code is executed in any case upon scope exit.
    scope(exit) { writeln("Exiting main."); }
    // File is closed deterministically at scope's end.
    foreach (line; File("text.txt").byLine()) {
        writeln(line);
    }
    writeln();
}
