module hackerranki.feb14_board_cutting;


import std.stdio;

void main() {
    ulong lines = 0;
    double sumLength = 0;
    foreach (line; stdin.byLine()) {
        ++lines;
        sumLength += line.length; 
    }
    writeln("Average line length: ",
        lines ? sumLength / lines : 0);
}


