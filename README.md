# Dat2Root
Convert an ASCII file to a ROOT histogram.

The script includes the instructions on how to run it in ROOT/GRSISort.

It has many commented lines to walk you through the script.

It also includes several (optional) formatting commands with which you should familiarize yourself.

The goal of this script is to convert MTSort spectra to ROOT, and also to start getting familiar with ROOT scripts/macros.

To use Dat2Root, you should first save your MTSort spectrum in ASCII format (for example: input.dat).

In Dat2Root.C, you should edit the input and output file names. Whenever you edit a script, you should close ROOT/GRSISort to run it again.

To run Dat2Root, you type in the command line:

grsisort -l Dat2Root.C

or:

grsisort -l

.x Dat2Root.C

Also, the above 'grsisort' can be replaced with 'root' - and it should work just fine!

After Dat2Root has created the output file, you close GRSISort by typing in the command line:

.q

To open the output file (for example: output.root), you type in the command line:

grsisort -l output.root

.ls    (to see the list of everything that is in your ROOT file)

myhist->Draw()    (to draw the TH1 histogram that you just created) 

And you are ready to examine your histogram and fit peaks in GRSISort!
