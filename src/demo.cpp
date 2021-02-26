#include <fst/fstlib.h>
#include <iostream>
#include "global.h"
#include "demo.h"

using namespace std;
using namespace fst;

void demo(string filename)
{
  // A vector FST is a general mutable FST
  StdVectorFst fst;

  // A symbol table
  SymbolTable *syms = new SymbolTable();
  syms->AddSymbol("A", 100);
  syms->AddSymbol("B", 101);

  // Adds state 0 to the initially empty FST and make it the start state.
  int start = fst.AddState(); // 1st state will be state 0 (returned by AddState)
  fst.SetStart(start); // arg is state ID

  // Adds two arcs exiting state 0.
  // Arc constructor args: ilabel, olabel, weight, dest state ID.
  fst.AddArc(0, StdArc(100, 100, 1, 1)); // 1st arg is src state ID
  // fst.AddArc(0, StdArc(2, 2, 1.5, 1));

  // Adds state 1 and its arc.
  fst.AddState();
  fst.AddArc(1, StdArc(101, 101, 1, 2));

  // Adds state 2 and set its final weight.
  fst.AddState();
  fst.SetFinal(2); // 1st arg is state ID, 2nd arg weight

  // assign symbols to fst
  fst.SetInputSymbols(syms);
  fst.SetOutputSymbols(syms);

  // Writes the result FST to a file.
  string path = workspaceDirectory() + "/" + filename;
  cout << "Writing: " + path + "\n";
  fst.Write(path);
}
